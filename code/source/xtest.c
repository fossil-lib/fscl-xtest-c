/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#define _POSIX_C_SOURCE 200809L // allows use of other time functions
#include "fossil/xtest.h"
#include <stdarg.h>
#include <string.h>
#include <time.h>

typedef struct {
    bool cutback;
    bool verbose;
    bool dry_run;
    bool only_test;
    bool only_fish;
    bool only_mark;
    bool repeat;
    uint8_t iter_repeat;
} xparser;

// Global xparser variable
xparser xcli;

// Static control panel for assert/expect and marks
static uint8_t XEXPECT_PASS_SCAN = true;
static uint8_t XASSERT_PASS_SCAN = true;
static uint8_t XIGNORE_TEST_CASE = false;
static uint8_t XERRORS_TEST_CASE = false;
static uint8_t MAX_REPEATS = 100;
static uint8_t MIN_REPEATS = 1;

//
// local types
//
typedef char *xstring;
static struct timespec start_time;

// =================================================================
// XEngine utility functions
// =================================================================
static uint16_t xengine_get_passed_count(xengine *runner) {
    return runner->stats.passed_count;
}

static uint16_t xengine_get_failed_count(xengine *runner) {
    return runner->stats.failed_count;
}

static uint16_t xengine_get_skipped_count(xengine *runner) {
    return runner->stats.ignored_count;
}

static uint16_t xengine_get_errors_count(xengine *runner) {
    return runner->stats.error_count;
}

static uint16_t xengine_get_mark_count(xengine *runner) {
    return runner->stats.mark_count;
}

static uint16_t xengine_get_fish_count(xengine *runner) {
    return runner->stats.fish_count;
}

static uint16_t xengine_get_test_count(xengine *runner) {
    return runner->stats.test_count;
}

static uint16_t xengine_get_total_count(xengine *runner) {
    return runner->stats.total_count;
}

// ==============================================================================
// Xtest internal console stream logic
// ==============================================================================

// Error Output Function
static void xtest_console_err(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// Color Output Function
static void xtest_console_out(const char *color_name, const char *format, ...) {
    va_list args;
    va_start(args, format);

    if (strcmp(color_name, "reset") == 0) {
        printf("\033[0m");
    } else if (strcmp(color_name, "black") == 0) {
        printf("\033[0;30m");
    } else if (strcmp(color_name, "gray") == 0) {
        printf("\033[1;30m");
    } else if (strcmp(color_name, "white") == 0) {
        printf("\033[1;37m");
    } else if (strcmp(color_name, "red") == 0) {
        printf("\033[0;31m");
    } else if (strcmp(color_name, "green") == 0) {
        printf("\033[0;32m");
    } else if (strcmp(color_name, "yellow") == 0) {
        printf("\033[0;33m");
    } else if (strcmp(color_name, "blue") == 0) {
        printf("\033[0;34m");
    } else if (strcmp(color_name, "magenta") == 0) {
        printf("\033[0;35m");
    } else if (strcmp(color_name, "cyan") == 0) {
        printf("\033[0;36m");
    } else {
        // Default to classic output if an unsupported color is specified
        vprintf(format, args);
        va_end(args);
        return;
    }

    vprintf(format, args);
    printf("\033[0m"); // Reset color
    va_end(args);
}

static xstring xtest_console_name(const char *input) {
    if (input == NULL) {
        // Handle NULL input gracefully
        xtest_console_err("Error: Input string is NULL\n");
        return NULL;
    }

    // Get the length of the input string
    size_t length = strlen(input);

    // Allocate memory for the new string (including space for null terminator)
    char *result = (char*)malloc((length + 1) * sizeof(char));

    if (result == NULL) {
        // Memory allocation failed
        xtest_console_err("Error: Memory allocation failed\n");
        return NULL;
    }

    // Iterate through each character in the input string
    for (size_t i = 0; i < length; i++) {
        // Replace underscores with spaces
        result[i] = (input[i] == '_') ? ' ' : input[i];
    }

    // Add null terminator to the end of the new string
    result[length] = '\0';

    return result;
}

// Formats and displays information about the start/end of a test case.
static void xtest_output_start(xtest *test_case, xengine* engine) {
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("blue", "[Running Test Case] ...\n");
        xtest_console_out("cyan", "TITLE: - %s\n", xtest_console_name(test_case->name));
        xtest_console_out("cyan", "INDEX: - %.2i\n", engine->stats.total_count + 1);
        xtest_console_out("cyan", "CLASS: - %s\n", (test_case->config.is_fish)? "Fish AI" : (test_case->config.is_mark)? "Benchmark" : "Test Case");
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("blue", "> name: - %s\n", xtest_console_name(test_case->name));
        xtest_console_out("blue", "> type: - %s\n", (test_case->config.is_fish)? "fish" : (test_case->config.is_mark)? "mark" : "test");
    }
} // end of func

static void xtest_output_end(xtest *test_case, xengine* engine) {
    if (xcli.verbose && !xcli.cutback) {
        int minutes = (int)(test_case->timer.elapsed / (60 * 1000));
        int seconds = (int)((test_case->timer.elapsed - minutes * 60 * 1000) / 1000);
        int millis = (int)(test_case->timer.elapsed - minutes * 60 * 1000 - seconds * 1000);
        xtest_console_out("cyan", "TIME  : - %d minutes, %d seconds, and %d milliseconds\n", minutes, seconds, millis);
        xtest_console_out("cyan", "SKIP  : - %s\n", test_case->config.ignored ? "yes" : "no");
        xtest_console_out("blue", "[Current Case Done] ...\n");
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("blue", "ignore: %s\n", test_case->config.ignored ? "yes" : "no");
    }
} // end of func

// Output for XUnit Test Case Report.
static void xtest_output_report(xengine *runner) {
    runner->timer.end = clock();
    // Calculate elapsed time and store it in the test case
    runner->timer.elapsed = ((double)(runner->timer.end - runner->timer.start)  / CLOCKS_PER_SEC) * 1000.0;
    int minutes = (int)(runner->timer.elapsed / (60 * 1000));
    int seconds = (int)((runner->timer.elapsed - minutes * 60 * 1000) / 1000);
    int millis = (int)(runner->timer.elapsed - minutes * 60 * 1000 - seconds * 1000);

    xtest_console_out("blue", "[ ===== Xtest report system ===== ] %d minutes, %d seconds, and %d milliseconds\n", minutes, seconds, millis);
    xtest_console_out("white",     "===================================\n");
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("magenta", "PASSED    : - %.2i\n",     xengine_get_passed_count(runner));
        xtest_console_out("magenta", "FAILED    : - %.2i\n",     xengine_get_failed_count(runner));
        xtest_console_out("magenta", "SKIPPED   : - %.2i\n",     xengine_get_skipped_count(runner));
        xtest_console_out("magenta", "ERRORS    : - %.2i\n",     xengine_get_errors_count(runner));
        xtest_console_out("magenta", "TOTAL MARK: - %.2i\n",     xengine_get_mark_count(runner));
        xtest_console_out("magenta", "TOTAL FISH: - %.2i\n",     xengine_get_fish_count(runner));
        xtest_console_out("magenta", "TOTAL TEST: - %.2i\n",     xengine_get_test_count(runner));
        xtest_console_out("yellow",  "ALL TEST CASES: - %.2i\n", xengine_get_total_count(runner));
    } else if (!xcli.verbose && !xcli.cutback) {
        xtest_console_out("magenta", "pass: %.2i, fail: %.2i\n", xengine_get_passed_count(runner), xengine_get_failed_count(runner));
    } else if (!xcli.verbose && xcli.cutback) {
        xtest_console_out("magenta", "result: %s\n", xengine_get_failed_count(runner)? "fail" : "pass");
    }
    xtest_console_out("white",     "===================================\n\n");
} // end of func

// ==============================================================================
// Xtest internal argument parser logic
// ==============================================================================

// Prints usage instructions, including custom options, for a command-line program.
static void xparser_print_usage(void) {
    xtest_console_out("green",  "USAGE: Xcli [options]\n");
    xtest_console_out("green", "Options:\n");
    xtest_console_out("gray", "  -h, --help    Display this help message\n");
    xtest_console_out("gray", "  -v, --version Display program version\n");
    xtest_console_out("gray", "  --only-test   Run only test cases\n");
    xtest_console_out("gray", "  --only-fish   Run only AI training cases\n");
    xtest_console_out("gray", "  --only-mark   Run only benchmark cases\n");
    xtest_console_out("gray", "  --cutback     Enable cutback mode\n");
    xtest_console_out("gray", "  --verbose     Enable verbose mode\n");
    xtest_console_out("gray", "  --repeat N    Repeat the test N times (requires a numeric argument)\n");
} // end of func

// Function to check if a specific option is present
static bool xparser_has_option(int argc, char *argv[], const char *option) {
    for (int32_t i = 1; i < argc; i++) {
        if (strcmp(argv[i], option) == 0) {
            return true;
        }
    }
    return false;
}

// Original xparser_parse_args function
static void xparser_parse_args(int argc, char *argv[]) {
    xcli.cutback = false;
    xcli.verbose = false;
    xcli.dry_run = false;
    xcli.repeat  = false;
    xcli.only_test = false;
    xcli.only_mark = false;

    for (int32_t i = 1; i < argc; i++) {
        if (xparser_has_option(argc, argv, "--dry-run")) {
            xcli.dry_run = true;
        } else if (xparser_has_option(argc, argv, "--cutback")) {
            xcli.cutback = true;
            xcli.verbose = false;
        } else if (xparser_has_option(argc, argv, "--verbose")) {
            xcli.verbose = true;
            xcli.cutback = false;
        } else if (xparser_has_option(argc, argv, "--only-test")) {
            xcli.only_test = true;
            xcli.only_fish = false;
            xcli.only_mark = false;
        } else if (xparser_has_option(argc, argv, "--only-fish")) {
            xcli.only_fish = true;
            xcli.only_mark = false;
            xcli.only_test = false;
        } else if (xparser_has_option(argc, argv, "--only-mark")) {
            xcli.only_mark = true;
            xcli.only_fish = false;
            xcli.only_test = false;
        } else if (xparser_has_option(argc, argv, "--version") || xparser_has_option(argc, argv, "-v")) {
            xtest_console_out("green", "1.1.1\n");
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--help") || xparser_has_option(argc, argv, "-h")) {
            xparser_print_usage();
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--repeat")) {
            xcli.repeat = true;
            if (++i < argc) {
                int iter_repeat = atoi(argv[i]);
                if (iter_repeat >= MIN_REPEATS && iter_repeat <= MAX_REPEATS) {
                    xcli.iter_repeat = iter_repeat;
                } else {
                    xtest_console_err("Error: --repeat value must be between 1 and 100.\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                xtest_console_err("Error: --repeat option requires a numeric argument.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
} // end of func

// ==============================================================================
// Xtest create and erase
// ==============================================================================

// Initializes an xengine and processes command-line arguments.
xengine xtest_create(int argc, char **argv) {
    xengine runner;
    xparser_parse_args(argc, argv);

    runner.stats = (xstats){0, 0, 0, 0, 0, 0, 0, 0};
    runner.timer = (xtime){0, 0, 0};

    if (xcli.dry_run) { // Check if it's a dry run
        xtest_console_out("blue", "Simulating config step...\n");
    }
    runner.timer.start = clock();
    return runner;
} // end of func

// Finalizes the execution of a Trilobite XUnit runner and displays test results.
int xtest_erase(xengine *runner) {
    if (xcli.dry_run) {
        xtest_console_out("blue", "Simulating test results...\n");
    } else {
        xtest_output_report(runner);
    }
    return runner->stats.failed_count;
} // end of func

// ==============================================================================
// Xtest basic utility functions
// ==============================================================================

// Updates the statistics
static void xtest_update_scoreboard(xengine* engine, xtest* test_case) {
    // Check if the test should be ignored
    if (test_case->config.ignored) {
        engine->stats.ignored_count++;
        return;
    }
    if (XERRORS_TEST_CASE) {
        engine->stats.error_count++;
        return;
    }

    // Update the appropriate count based on your logic
    if (!test_case->config.is_mark && !test_case->config.is_fish) {
        engine->stats.test_count++;
    } else if (test_case->config.is_fish && !test_case->config.is_mark) {
        engine->stats.fish_count++;
    } else if (test_case->config.is_mark && !test_case->config.is_fish) {
        engine->stats.mark_count++;
    }

    // Update main score values
    if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN) {
        engine->stats.failed_count++;
    } else {
        engine->stats.passed_count++;
    }
    engine->stats.total_count++;
} // end of func

// Core steps to run a test case
static void xtest_run(xtest* test_case, xfixture* fixture) {
    test_case->timer.start = clock();

    for (uint8_t iter = 0; iter < xcli.iter_repeat; iter++) {
        if (fixture && fixture->setup) {
            fixture->setup();
        }

        test_case->test_function();

        if (fixture && fixture->teardown) {
            fixture->teardown();
        }
    }

    test_case->timer.end = clock(); // Calculate elapsed time and store it in the test case
    test_case->timer.elapsed = ((double)(test_case->timer.end - test_case->timer.start)  / CLOCKS_PER_SEC) * 1000.0;
} // end of func

// Common functionality for running a test case.
static void xtest_run_test(xengine* engine, xtest* test_case, xfixture* fixture) {
    xtest_output_start(test_case, engine);

    if (!xcli.dry_run && !XIGNORE_TEST_CASE) {
        xtest_run(test_case, fixture);

    } else if (!xcli.dry_run && XIGNORE_TEST_CASE) {
        test_case->config.ignored = XIGNORE_TEST_CASE;
        XIGNORE_TEST_CASE = false;

    } else if (xcli.dry_run) {
        xtest_console_out("blue", "Simulating test case...\n");
        return;
    }

    xtest_update_scoreboard(engine, test_case);
    xtest_output_end(test_case, engine);
} // end of func

// ==============================================================================
// Xtest essential test runner functions
// ==============================================================================

void xtest_run_as_test(xengine* engine, xtest* test_case) {
    test_case->config.ignored = false;
    xtest_run_test(engine, test_case, NULL);
} // end of func

void xtest_run_as_fixture(xengine* engine, xtest* test_case, xfixture* fixture) {
    test_case->config.ignored = false;
    xtest_run_test(engine, test_case, fixture);
} // end of func

// ==============================================================================
// Xmark functions for benchmarks
// ==============================================================================

void xmark_start_benchmark() {
    clock_gettime(CLOCK_MONOTONIC, &start_time);
}

uint64_t xmark_stop_benchmark() {
    struct timespec end_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    return (end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec);
}

void xmark_assert_seconds(uint64_t elapsed_time_ns, double max_seconds) {
    if (!XASSERT_PASS_SCAN) {
        return;
    }
    double elapsed_seconds = elapsed_time_ns / 1e9;
    if (elapsed_seconds > max_seconds) {
        XASSERT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("blue", "[XMARK ISSUE]\n");
            xtest_console_out("red", "Elapsed time (%f min)\n", elapsed_seconds);
            xtest_console_out("red", "Exceeds limit (%f min)\n", max_seconds);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "Benchmark failed: elapsed time (%f min) exceeds limit (%f min)\n", elapsed_seconds, max_seconds);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("green", "[P]");
        }
    }
}

void xmark_assert_minutes(uint64_t elapsed_time_ns, double max_minutes) {
    if (!XASSERT_PASS_SCAN) {
        return;
    }
    double elapsed_minutes = elapsed_time_ns / 60e9;
    if (elapsed_minutes > max_minutes) {
         XASSERT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("blue", "[XMARK ISSUE]\n");
            xtest_console_out("red", "Elapsed time (%f min)\n", elapsed_minutes);
            xtest_console_out("red", "Exceeds limit (%f min)\n", max_minutes);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "Benchmark failed: elapsed time (%f min) exceeds limit (%f min)\n", elapsed_minutes, max_minutes);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("green", "[P]");
        }
    }
}

void xmark_expect_seconds(uint64_t elapsed_time_ns, double max_seconds) {
    double elapsed_seconds = elapsed_time_ns / 1e9;
    XEXPECT_PASS_SCAN = true;

    if (elapsed_seconds > max_seconds) {
        XEXPECT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("blue", "[XMARK ISSUE]\n");
            xtest_console_out("red", "Elapsed time (%f min)\n", elapsed_seconds);
            xtest_console_out("red", "Exceeds limit (%f min)\n", max_seconds);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "Benchmark failed: elapsed time (%f min) exceeds limit (%f min)\n", elapsed_seconds, max_seconds);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("green", "[P]");
        }
    }
}

void xmark_expect_minutes(uint64_t elapsed_time_ns, double max_minutes) {
    double elapsed_minutes = elapsed_time_ns / 60e9;
    XEXPECT_PASS_SCAN = true;

    if (elapsed_minutes > max_minutes) {
        XEXPECT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("blue", "[XMARK ISSUE]\n");
            xtest_console_out("red", "Elapsed time (%f min)\n", elapsed_minutes);
            xtest_console_out("red", "Exceeds limit (%f min)\n", max_minutes);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "Benchmark failed: elapsed time (%f min) exceeds limit (%f min)\n", elapsed_minutes, max_minutes);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("green", "[P]");
        }
    }
}

// ==============================================================================
// Xtest functions for asserts
// ==============================================================================

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xignore(const char* reason, const char* file, int line, const char* func) {
    XIGNORE_TEST_CASE = true;
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("yellow", "[SKIP CASE]\n");
        xtest_console_out("yellow", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
        xtest_console_out("yellow", "message: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("yellow", "message: %s\n line: %.4i\n func: %s\n", reason, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xtest_console_out("yellow", "[S]");
    }
} // end of func

// Marks a test case as error with a specified reason and prints it to stderr.
void xerrors(const char* reason, const char* file, int line, const char* func) {
    XERRORS_TEST_CASE = true;
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("red", "[ERROR CASE]\n");
        xtest_console_out("red", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
        xtest_console_out("red", "message: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("red", "message: %s\n line: %.4i\n func: %s\n", reason, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xtest_console_out("red", "[E]");
    }
} // end of func


// Custom assertion function with optional message.
void xassert(bool expression, const char *message, const char* file, int line, const char* func) {
    if (!XASSERT_PASS_SCAN) {
        return;
    }
    if (!expression) {
         XASSERT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("blue", "[ASSERT ISSUE]\n");
            xtest_console_out("red", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
            xtest_console_out("red", "message: %s\n", message);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "message: %s\n line: %.4i\n func: %s\n", message, line, func);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("green", "[P]");
        }
    }
} // end of func

// Custom expectation function with optional message.
void xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {
        XEXPECT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("blue", "[EXPECT ISSUE]\n");
            xtest_console_out("red", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
            xtest_console_out("red", "message: %s\n", message);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "message: %s\n line: %.4i\n func: %s\n", message, line, func);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("green", "[P]");
        }
    }
} // end of func
