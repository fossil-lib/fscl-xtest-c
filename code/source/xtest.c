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
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

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

// ==============================================================================
// Xtest internal written number logic
// ==============================================================================
typedef struct {
    xstring word;
    int64_t value;
} NumberMapping;

typedef struct {
    xstring operator;
    int32_t priority;
} OperatorMapping;

OperatorMapping operators[] = {
    {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}
};

// Define mappings for units, tens, and powers of ten
NumberMapping units[] = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

NumberMapping teens[] = {
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
    {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}
};

NumberMapping tens[] = {
    {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
    {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

NumberMapping powersOfTen[] = {
    {"thousand", 1000}, {"million", 1000000}, {"billion", 1000000000}, {"trillion", 1000000000000}
};

// ==============================================================================
// Xtest internal console stream logic
// ==============================================================================

// Error Output Function
void xtest_console_err(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

// Color Output Function
void xtest_console_out(const char *color_name, const char *format, ...) {
    va_list args;
    va_start(args, format);

    if (strcmp(color_name, "reset") == 0) {
        printf("\033[0m");
    } else if (strcmp(color_name, "black") == 0) {
        printf("\033[0;30m");
    } else if (strcmp(color_name, "dark_gray") == 0) {
        printf("\033[1;30m");
    } else if (strcmp(color_name, "light_gray") == 0) {
        printf("\033[2;37m");
    } else if (strcmp(color_name, "white") == 0) {
        printf("\033[1;37m");
    } else if (strcmp(color_name, "dark_red") == 0) {
        printf("\033[0;31m");
    } else if (strcmp(color_name, "light_red") == 0) {
        printf("\033[1;31m");
    } else if (strcmp(color_name, "dark_green") == 0) {
        printf("\033[0;32m");
    } else if (strcmp(color_name, "light_green") == 0) {
        printf("\033[1;32m");
    } else if (strcmp(color_name, "dark_yellow") == 0) {
        printf("\033[0;33m");
    } else if (strcmp(color_name, "light_yellow") == 0) {
        printf("\033[1;33m");
    } else if (strcmp(color_name, "dark_blue") == 0) {
        printf("\033[0;34m");
    } else if (strcmp(color_name, "light_blue") == 0) {
        printf("\033[1;34m");
    } else if (strcmp(color_name, "dark_magenta") == 0) {
        printf("\033[0;35m");
    } else if (strcmp(color_name, "light_magenta") == 0) {
        printf("\033[1;35m");
    } else if (strcmp(color_name, "dark_cyan") == 0) {
        printf("\033[0;36m");
    } else if (strcmp(color_name, "light_cyan") == 0) {
        printf("\033[1;36m");
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

xstring xtest_console_numeric(int number) {
    // Implementation of converting numeric values to English words is more complex
    // and may require additional logic based on your specific requirements.
    // This example includes only basic handling for numbers less than 100.
    
    if (number >= 10 && number <= 19) {
        for (size_t i = 0; i < sizeof(teens) / sizeof(teens[0]); ++i) {
            if (number == teens[i].value) {
                return teens[i].word;
            }
        }
    } else if (number % 10 == 0 && number < 100) {
        for (size_t i = 0; i < sizeof(tens) / sizeof(tens[0]); ++i) {
            if (number == tens[i].value) {
                return tens[i].word;
            }
        }
    } else {
        for (size_t i = 0; i < sizeof(units) / sizeof(units[0]); ++i) {
            if (number % 10 == units[i].value) {
                return units[i].word;
            }
        }
    }

    return "unknown";
}

xstring xtest_console_name(const char *input) {
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
static void xtest_output_xtest_start(xtest *test_case, xstats *stats) {
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("dark_blue", "[Running Test Case] ...\n");
        xtest_console_out("light_cyan", "TITLE: - %s\n", xtest_console_name(test_case->name));
        xtest_console_out("light_cyan", "INDEX: - %s\n", xtest_console_numeric(stats->total_count + 1));
        xtest_console_out("light_cyan", "CLASS: - %s\n", (test_case->is_fish)? "Fish AI" : (test_case->is_mark)? "Benchmark" : "Test Case");
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("dark_blue", "> name: - %s\n", xtest_console_name(test_case->name));
        xtest_console_out("dark_blue", "> type: - %s\n", (test_case->is_fish)? "fish" : (test_case->is_mark)? "mark" : "test");
    }
} // end of func

static void xtest_output_xtest_end(xtest *test_case, xstats *stats) {
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("light_cyan", "TIME  : - %.6lu\n", test_case->elapsed_time);
        xtest_console_out("light_cyan", "SKIP  : - %s\n", test_case->ignored ? "yes" : "no");
        xtest_console_out("dark_blue", "[Current Case Done] ...\n");
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("dark_blue", "ignore: %s\n", test_case->ignored ? "yes" : "no");
    }
} // end of func

// Output for XUnit Test Case Report.
static void xtest_output_xunittest_report(xengine *runner) {
    clock_t end_time = clock();
    xtest_console_out("dark_blue", "[ ===== Xtest report system ===== ] time: %i\n", (runner->elapsed_time - end_time));
    xtest_console_out("white",     "===================================\n");
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("light_magenta", "PASSED    : - %s\n",     xtest_console_numeric(runner->stats.passed_count));
        xtest_console_out("light_magenta", "FAILED    : - %s\n",     xtest_console_numeric(runner->stats.failed_count));
        xtest_console_out("light_magenta", "SKIPPED   : - %s\n",     xtest_console_numeric(runner->stats.ignored_count));
        xtest_console_out("light_magenta", "ERRORS    : - %s\n",     xtest_console_numeric(runner->stats.error_count));
        xtest_console_out("light_magenta", "TOTAL MARK: - %s\n",     xtest_console_numeric(runner->stats.mark_count));
        xtest_console_out("light_magenta", "TOTAL FISH: - %s\n",     xtest_console_numeric(runner->stats.fish_count));
        xtest_console_out("light_magenta", "TOTAL TEST: - %s\n",     xtest_console_numeric(runner->stats.total_count - runner->stats.fish_count - runner->stats.mark_count));
        xtest_console_out("light_yellow",  "ALL TEST CASES: - %s\n", xtest_console_numeric(runner->stats.total_count));
    } else if (!xcli.verbose && !xcli.cutback) {
        xtest_console_out("light_magenta", "pass: %.2i, fail: %.2i\n", runner->stats.passed_count, runner->stats.failed_count);
    } else if (!xcli.verbose && xcli.cutback) {
        xtest_console_out("light_magenta", "result: %s\n", runner->stats.failed_count? "fail" : "pass");
    }
    xtest_console_out("white",     "===================================\n\n");
} // end of func

// ==============================================================================
// Xtest internal argument parser logic
// ==============================================================================
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
    xtest_console_out("dark_green",  "USAGE: Xcli [options]\n");
    xtest_console_out("light_green", "Options:\n");
    xtest_console_out("dark_gray",   "  --help        Display this help message\n");
    xtest_console_out("light_gray",  "  --version     Display program version\n");
    xtest_console_out("dark_gray",   "  --only-test   Run only test cases\n");
    xtest_console_out("light_gray",  "  --only-fish   Run only AI training cases\n");
    xtest_console_out("dark_gray",   "  --only-mark   Run only benchmark cases\n");
    xtest_console_out("light_gray",  "  --cutback     Enable cutback mode\n");
    xtest_console_out("dark_gray",   "  --verbose     Enable verbose mode\n");
    xtest_console_out("light_gray",  "  --repeat N    Repeat the test N times (requires a numeric argument)\n");
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
            xtest_console_out_color("dark_green", "1.1.0\n");
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
xengine xtest_start(int argc, char **argv) {
    xengine runner;
    xparser_init();
    xparser_parse_args(argc, argv);

    runner.stats = (xstats){0, 0, 0, 0, 0, 0, 0};
    runner.elapsed_time = clock();

    if (xcli.dry_run) { // Check if it's a dry run
        xtest_console_out("light_blue", "Simulating a test run to ensure Xcli can run...\n");
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

// ==============================================================================
// Xtest basic functions
// ==============================================================================

// Common functionality for running a test case and updating test statistics.
void xtest_run_test(xtest* test_case, xstats* stats, xfixture* fixture) {
    xtest_output_xtest_start(test_case, stats);

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
    if (test_case->is_mark && !test_case->is_fish) {
        stats->mark_count++;
    } else if (test_case->is_fish && !test_case->is_mark) {
        stats->fish_count++;
    }
    if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN) {
        stats->failed_count++;
    } else {
        stats->passed_count++;
    }
    stats->total_count++;

    // Output test format information
    xtest_output_xtest_end(test_case, stats);
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

// ==============================================================================
// Xtest functions for asserts
// ==============================================================================

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xignore(const char* reason, const char* file, int line, const char* func) {
    XIGNORE_TEST_CASE = true;
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("light_yellow", "[SKIP CASE]\n");
        xtest_console_out("dark_yellow", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
        xtest_console_out("dark_yellow", "message: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("light_yellow", "message: %s\n line: %.4i\n func: %s\n", reason, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xtest_console_out("light_yellow", "[S]");
    }
} // end of func

// Marks a test case as ignored with a specified reason and prints it to stderr.
void xerrors(const char* reason, const char* file, int line, const char* func) {
    XERRORS_TEST_CASE = true;
    if (xcli.verbose && !xcli.cutback) {
        xtest_console_out("light_red", "[ERROR CASE]\n");
        xtest_console_out("dark_red", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
        xtest_console_out("dark_red", "message: %s\n", reason);
    } else if (!xcli.cutback && !xcli.verbose) {
        xtest_console_out("dark_red", "message: %s\n line: %.4i\n func: %s\n", reason, line, func);
    } else if (xcli.cutback && !xcli.verbose) {
        xtest_console_out("light_red", "[E]");
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
            xtest_console_out("light_blue", "[ASSERT ISSUE]\n");
            xtest_console_out("dark_red", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
            xtest_console_out("dark_red", "message: %s\n", message);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("dark_red", "message: %s\n line: %.4i\n func: %s\n", message, line, func);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("light_red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("light_green", "[P]");
        }
    }
} // end of func

// Custom expectation function with optional message.
void xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {
        XEXPECT_PASS_SCAN = false;
        if (xcli.verbose && !xcli.cutback) {
            xtest_console_out("light_blue", "[EXPECT ISSUE]\n");
            xtest_console_out("dark_red", "line: %.4i\nfile: %s\nfunc: %s\n", line, file, func);
            xtest_console_out("dark_red", "message: %s\n", message);
        } else if (!xcli.cutback && !xcli.verbose) {
            xtest_console_out("dark_red", "message: %s\n line: %.4i\n func: %s\n", message, line, func);
        } else if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("light_red", "[F]");
        }
    } else {
        if (xcli.cutback && !xcli.verbose) {
            xtest_console_out("light_green", "[P]");
        }
    }
} // end of func
