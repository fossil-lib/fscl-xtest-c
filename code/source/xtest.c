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
#include "fossil/xtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ANSI escape code macros for text color
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

// Output for XUnit Test Case Assert/Expect.
static void xtest_output_xassert(bool expression, const char *message, const char *file, int line, const char *func) {
    puts(ANSI_COLOR_BLUE);
    if (xcli.verbose && !xcli.verbose) {
        printf("[assert]\n line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
        printf(ANSI_COLOR_RED "message: %s\nresult: %s\n", message, expression ? "PASS" : "FAIL");
    } else if (xcli.cutback && !xcli.verbose) {
        printf("%s[O]", (expression ? ANSI_COLOR_GREEN : ANSI_COLOR_RED));
    } else if (!xcli.cutback && !xcli.verbose) {
        printf(ANSI_COLOR_RED "message: %s\nresult: %s\n", message, expression ? "PASS" : "FAIL");
    }
    puts(ANSI_COLOR_RESET);
} // end of func

// Output for XUnit Test Case Assert/Expect.
static void xtest_output_expect(bool expression, const char *message, const char *file, int line, const char *func) {
    puts(ANSI_COLOR_BLUE);
    if (xcli.verbose && !xcli.verbose) {
        printf("[expect]\n line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
        printf(ANSI_COLOR_RED "message: %s\nresult: %s\n", message, expression ? "PASS" : "FAIL");
    } else if (xcli.cutback && !xcli.verbose) {
        printf("%s[O]", (expression ? ANSI_COLOR_GREEN : ANSI_COLOR_RED));
    } else if (!xcli.cutback && !xcli.verbose) {
        printf(ANSI_COLOR_RED "message: %s\nresult: %s\n", message, expression ? "PASS" : "FAIL");
    }
    puts(ANSI_COLOR_RESET);
} // end of func

// Output for XUnit Test Case Error.
static void xtest_output_xerror(const char *reason, const char *file, int line, const char *func) {
    puts(ANSI_COLOR_BLUE);
    if (xcli.verbose && !xcli.cutback) {
        puts("[ assumtion error ]" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "line: %.4i\nfile: %s\nfunc: %s\n" ANSI_COLOR_RESET, line, file, func);
        printf(ANSI_COLOR_YELLOW "message: %s\n" ANSI_COLOR_RESET, reason);
    } else if (xcli.cutback && !xcli.verbose) {
        printf("%s", XERRORS_TEST_CASE ? ANSI_COLOR_YELLOW "[I]" : ANSI_COLOR_RED "[X]");
    } else if (!xcli.cutback && !xcli.verbose) {
        printf(ANSI_COLOR_YELLOW "message: %s\n" ANSI_COLOR_RESET, reason);
    }
    puts(ANSI_COLOR_RESET);
} // end of func

// Output for XUnit Test Case Ignored.
static void xtest_output_xignore(const char *reason, const char *file, int line, const char *func) {
    puts(ANSI_COLOR_BLUE);
    if (xcli.verbose && !xcli.cutback) {
        puts("[ assumtion skipped ]" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "line: %.4i\nfile: %s\nfunc: %s\n" ANSI_COLOR_RESET, line, file, func);
        printf(ANSI_COLOR_YELLOW "message: %s\n" ANSI_COLOR_RESET, reason);
    } else if (xcli.cutback && !xcli.verbose) {
        printf("%s", XIGNORE_TEST_CASE ? ANSI_COLOR_YELLOW "[I]" : ANSI_COLOR_RED "[X]");
    } else if (!xcli.cutback && !xcli.verbose) {
        printf(ANSI_COLOR_YELLOW "message: %s\n" ANSI_COLOR_RESET, reason);
    }
    puts(ANSI_COLOR_RESET);
} // end of func

// Formats and displays information about the start/end of a test case.
static void xtest_output_xunittest_format(bool is_start, xtest *test_case, xstats *stats) {
    if (is_start) {
        if (xcli.verbose && !xcli.cutback) {
            puts(ANSI_COLOR_BLUE "[Running Test Case]" ANSI_COLOR_RESET);
            printf("name  : %s\nnumber: %.4i\ntype: %s\n", test_case->name, stats->total_count + 1, (test_case->is_fish)? "Fish" : (test_case->is_mark)? "Mark" : "Test");
        } else if (xcli.cutback && !xcli.verbose) {
            printf("name: %s, type: %s\n", test_case->name, (test_case->is_fish)? "fish" : (test_case->is_mark)? "mark" : "test");
        } else {
            printf("name  : %s\nnumber: %.4i\ntype: %s\n", test_case->name, stats->total_count + 1, (test_case->is_fish)? "Fish" : (test_case->is_mark)? "Mark" : "Test");
        }
    } else if (!is_start) {
        printf("time: %.6lu \n", test_case->elapsed_time);
        if (xcli.verbose && !xcli.cutback) {
            printf("ignore: %s\n", test_case->ignored ? "yes" : "no");
            puts(ANSI_COLOR_BLUE "[Current unit done]" ANSI_COLOR_RESET);
        } else if (xcli.cutback && !xcli.verbose) {
            printf("\n");
        } else {
            printf("ignore: %s\n", test_case->ignored ? "yes" : "no");
        }
    }
} // end of func

// Output for XUnit Test Case Report.
static void xtest_output_xunittest_report(xengine *runner) {
    puts(ANSI_COLOR_BLUE "[ ===== Xtest report system ===== ]" ANSI_COLOR_RESET);
    if (!xcli.verbose && xcli.cutback) {
        printf("result: %s\n", runner->stats.failed_count? "fail" : "pass");
    } else if (xcli.verbose && !xcli.cutback) {
        printf(ANSI_COLOR_BLUE "pass : " ANSI_COLOR_YELLOW " %.2i\n" ANSI_COLOR_RESET, runner->stats.passed_count);
        printf(ANSI_COLOR_BLUE "fail : " ANSI_COLOR_YELLOW " %.2i\n" ANSI_COLOR_RESET, runner->stats.failed_count);
        printf(ANSI_COLOR_BLUE "skip : " ANSI_COLOR_YELLOW " %.2i\n" ANSI_COLOR_RESET, runner->stats.ignored_count);
        printf(ANSI_COLOR_BLUE "error: " ANSI_COLOR_YELLOW " %.2i\n" ANSI_COLOR_RESET, runner->stats.error_count);
        printf(ANSI_COLOR_BLUE "total: " ANSI_COLOR_YELLOW " %.2i\n" ANSI_COLOR_RESET, runner->stats.total_count);
    } else {
        printf(ANSI_COLOR_BLUE "pass: %.2i, fail: %.2i\n" ANSI_COLOR_RESET,
            runner->stats.passed_count, runner->stats.failed_count);
    }
} // end of func

static void xparser_init(void) {
    // Initialize members individually
    xcli.cutback = false;
    xcli.verbose = false;
    xcli.dry_run = false;
    xcli.repeat  = false;
    xcli.only_test = false;
    xcli.only_mark = false;
} // end of func

// Prints usage instructions, including custom options, for a command-line program.
static void xparser_print_usage(void) {
    puts("Usage: Xcli [options]");
    puts("Options:");
    puts("  --help        Display this help message");
    puts("  --version     Display program version");
    puts("  --only-test   Run only test cases");
    puts("  --only-fish   Run only AI training cases");
    puts("  --only-mark   Run only benchmark cases");
    puts("  --cutback     Enable cutback mode");
    puts("  --verbose     Enable verbose mode");
    puts("  --repeat N    Repeat the test N times (requires a numeric argument)");
} // end of func

// Function to check if a specific option is present
bool xparser_has_option(int argc, char *argv[], const char *option) {
    for (int32_t i = 1; i < argc; i++) {
        if (strcmp(argv[i], option) == 0) {
            return true;
        }
    }
    return false;
}

// Original xparser_parse_args function
static void xparser_parse_args(int argc, char *argv[]) {
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
        } else if (xparser_has_option(argc, argv, "--version")) {
            puts("1.0.0");
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--help")) {
            xparser_print_usage();
            exit(EXIT_SUCCESS);
        } else if (xparser_has_option(argc, argv, "--repeat")) {
            xcli.repeat = true;
            if (++i < argc) {
                int iter_repeat = atoi(argv[i]);
                if (iter_repeat >= MIN_REPEATS && iter_repeat <= MAX_REPEATS) {
                    xcli.iter_repeat = iter_repeat;
                } else {
                    fprintf(stderr, "Error: --repeat value must be between 1 and 100.\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                fprintf(stderr, "Error: --repeat option requires a numeric argument.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
} // end of func

// Initializes an xengine and processes command-line arguments.
xengine xtest_start(int argc, char **argv) {
    xengine runner;
    xparser_init();
    xparser_parse_args(argc, argv);

    runner.stats = (xstats){0, 0, 0, 0, 0};

    if (xcli.dry_run) { // Check if it's a dry run
        printf("Simulating a test run to ensure Xcli can run...\n");
        exit(xtest_end(&runner)); // Exit the program
    }

    return runner;
} // end of func

// Finalizes the execution of a Trilobite XUnit runner and displays test results.
int xtest_end(xengine *runner) {
    if (!xcli.dry_run) {
        xtest_output_xunittest_report(runner);
    }
    return runner->stats.failed_count;
} // end of func

// Common functionality for running a test case and updating test statistics.
void xtest_run_test(xtest* test_case, xstats* stats, xfixture* fixture) {
    xtest_output_xunittest_format(true, test_case, stats);

    // Check if the test should be ignored
    if (XIGNORE_TEST_CASE || (xcli.only_test && test_case->is_mark) || (xcli.only_mark && !test_case->is_mark) || (xcli.only_fish && !test_case->is_mark)) {
        // Skip the test if it doesn't match the desired type
        stats->ignored_count++;
        XIGNORE_TEST_CASE = false;
        test_case->ignored = true;
        return;
    }
    if (XERRORS_TEST_CASE) {
        stats->error_count++;
        return;
    }

    // Record start time
    clock_t start_time = clock();

    // Run tests sequentially
    for (uint8_t iter = 0; iter < xcli.iter_repeat; iter++) {
        // Execute setup function if provided
        if (fixture && fixture->setup) {
            fixture->setup();
        }

        // Run the actual test function
        test_case->test_function();

        // Execute teardown function if provided
        if (fixture && fixture->teardown) {
            fixture->teardown();
        }
    }

    // Record end time
    clock_t end_time = clock();

    // Calculate elapsed time and store it in the test case
    test_case->elapsed_time = end_time - start_time;

    // Update the appropriate count based on your logic
    if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN) {
        // If any expectations fail, consider the test as failed
        stats->failed_count++;
    } else {
        stats->passed_count++;
    }
    stats->total_count++;

    // Output test format information
    xtest_output_xunittest_format(false, test_case, stats);
} // end of func

// Runs a test case and updates test statistics.
void xtest_run_test_unit(xtest* test_case, xstats* stats) {
    // Initialize the test as not ignored
    test_case->ignored = false;

    // Run the test
    xtest_run_test(test_case, stats, NULL);
} // end of func

// Runs a test case within a test fixture and updates test statistics.
void xtest_run_test_fixture(xtest* test_case, xfixture* fixture, xstats* stats) {
    // Initialize the test as not ignored
    test_case->ignored = false;

    // Run the test with the specified fixture
    xtest_run_test(test_case, stats, fixture);
}  // end of func

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xignore(const char* reason, const char* file, int line, const char* func) {
    XIGNORE_TEST_CASE = true;
    xtest_output_xignore(reason, file, line, func);
} // end of func

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xerrors(const char* reason, const char* file, int line, const char* func) {
    XERRORS_TEST_CASE = true;
    xtest_output_xerror(reason, file, line, func);
} // end of func


// Custom assertion function with optional message.
void xassert(bool expression, const char *message, const char* file, int line, const char* func) {
    if (!XASSERT_PASS_SCAN) {
        return;
    } else if (!expression) {
        XASSERT_PASS_SCAN = false;
    }
    xtest_output_xassert(expression, message, file, line, func);
} // end of func

// Custom expectation function with optional message.
void xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {
        XEXPECT_PASS_SCAN = false;
    }
    xtest_output_expect(expression, message, file, line, func);
} // end of func
