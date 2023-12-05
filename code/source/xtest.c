/*  ----------------------------------------------------------------------------
    File: xtest.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xtest.h"

// ANSI escape code macros for text color
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Extra
const char *XTEST_VERSION = "0.4.2";
const int DEFAULT_REPEAT_VALUE = -1;

// Static control panel for assert/expect and marks
static bool XEXPECT_PASS_SCAN = true;
static bool XASSERT_PASS_SCAN = true;
static bool XIGNORE_TEST_CASE = false;

// Static control panel for command-line arguments
static bool XTEST_FLAG_CUTBACK    = false;
static bool XTEST_FLAG_VERBOSE    = false;
static bool XTEST_FLAG_VERSION    = false;
static bool XTEST_FLAG_COLORED    = false;
static bool XTEST_FLAG_HELP       = false;
static bool XTEST_FLAG_REPEAT     = false;
static int XTEST_ITER_REAPET      = 1;

// XUnit options for the tester to switch on-off
XTestCliOption options[] = {
     { "--cutback",    "-C", "Show less information to standard output", &XTEST_FLAG_CUTBACK },
     { "--verbose",    "-V", "Show more information to standard output", &XTEST_FLAG_VERBOSE },
     { "--version",    "-v", "Get the version of this test framework", &XTEST_FLAG_VERSION },
     { "--color"  ,    "-c", "Enable color text output", &XTEST_FLAG_COLORED },
     { "--help",       "-h", "Print this message you see before you're eyes", &XTEST_FLAG_HELP },
     { "--reapet"  ,   "-r", "Reapet test cases number of times (0-100)", &XTEST_FLAG_REPEAT }
 }; // end of command-line options

// Output for XUnit Test Case Assert/Expect.
static void xtest_output_xassert_expect(bool expression, const char *message, const char *assert_type,
                                        const char *file, int line, const char *func) {
    const char *color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char *color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";
    const char *color_fail = XTEST_FLAG_COLORED ? ANSI_COLOR_RED : "";
    const char *color_pass = XTEST_FLAG_COLORED ? ANSI_COLOR_GREEN : "";

    if (!expression && (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK)) {
        printf("%s", color_start);
        if (XTEST_FLAG_VERBOSE) {
            printf("[%s case failed]" ANSI_COLOR_RESET "\n%sline: %.4i\nfile: %s\nfunc: %s\n", assert_type, color_fail, line, file, func);
            printf("%smessage: %s\nresult: %s\n", color_fail, message, expression ? "PASS" : "FAIL");
        } else if (XTEST_FLAG_CUTBACK) {
            printf("%s[O]", (XEXPECT_PASS_SCAN ? color_pass : color_fail));
        }
        printf("%s", color_reset);
    }
} // end of func

// Output for XUnit Test Case Ignored.
static void xtest_output_xignore(const char *reason, const char *file, int line, const char *func) {
    const char *color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char *color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";
    const char *color_yellow = XTEST_FLAG_COLORED ? ANSI_COLOR_YELLOW : "";

    if (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK) {
        printf("%s", color_start);
        if (XTEST_FLAG_VERBOSE) {
            puts("[Assert had been skipped]" ANSI_COLOR_RESET);
            printf("%sline: %.4i\nfile: %s\nfunc: %s\n", color_yellow, line, file, func);
            printf("%smessage: %s\n", color_yellow, reason);
        } else if (XTEST_FLAG_CUTBACK) {
            printf("%s", XIGNORE_TEST_CASE ? ANSI_COLOR_YELLOW "[I]" : ANSI_COLOR_RED "[X]");
        }
        printf("%s", color_reset);
    }
} // end of func

// Formats and displays information about the start/end of a test case.
static void xtest_output_xunittest_format(bool is_start, XTestCase *test_case, XTestStats *stats) {
    const char *color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char *color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";

    if ((XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK) && is_start) {
        printf("%s", color_start);
        if (XTEST_FLAG_VERBOSE) {
            puts("[Running XUnit Test]" ANSI_COLOR_RESET);
            printf("name  : %s\nnumber: %.4i\ntype: %s\n", test_case->name, stats->total_count + 1, !test_case->is_benchmark ? "Unit test" : "Benchmark");
        } else if (XTEST_FLAG_CUTBACK) {
            printf("name: %s, type: %s\n", test_case->name, !test_case->is_benchmark ? "unit" : "mark");
        }
        printf("%s", color_reset);
    } else if (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK) {
        printf("%stime: %.6lu", color_start, test_case->elapsed_time);
        if (XTEST_FLAG_VERBOSE) {
            printf("ignore: %s\n", test_case->ignored ? "yes" : "no");
            if (XTEST_FLAG_COLORED) {
                puts("[Current unit done]\n\n" ANSI_COLOR_RESET);
            } else {
                puts("[Current unit done]\n\n");
            }
        } else if (XTEST_FLAG_CUTBACK) {
            printf("\n");
        }
        printf("%s", color_reset);
    }
} // end of func

// Output for XUnit Test Case Report.
static void xtest_output_xunittest_report(XUnitRunner *runner) {
    const char *color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char *color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";

    if (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK) {
        printf("%s[XUnit Runner] test results%s", color_start, color_reset);
        if (!XTEST_FLAG_CUTBACK) {
            printf("pass: %.3i, fail: %.3i", runner->stats.passed_count, runner->stats.failed_count);
        } else {
            printf("pass: %.3i, fail: %.3i, skip: %.3i, total: %.3i",
                   runner->stats.passed_count, runner->stats.failed_count,
                   runner->stats.ignored_count, runner->stats.total_count);
        }
        printf("%s\n", color_reset);
    }
} // end of func

// Prints usage instructions, including custom options, for a command-line program.
static void xtest_cli_print_usage(const char* program_name, const XTestCliOption* options, unsigned int num_options) {
    const char* separator = "########################################";

    puts(separator);
    printf("Usage: %s [options]\n", program_name);
    puts("Options:");

    for (unsigned int i = 0; i < num_options; ++i) {
        printf("  %s %s\t%s\n", options[i].option_long_name, options[i].option_short_name, options[i].description);
    }

    puts(separator);
} // end of func

// Parses command-line arguments and sets corresponding flags
int xtest_cli_parse_args(XTestCliOption* options, unsigned int num_options, int argc, char** argv) {
    int repeat = DEFAULT_REPEAT_VALUE;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--repeat") == 0 && i + 1 < argc) {
            char* endPtr;
            repeat = strtol(argv[i + 1], &endPtr, 10);

            if (*endPtr != '\0') {
                fprintf(stderr, "Error: Invalid number after --repeat\n");
                return 1;
            }

            i++;
        } else {
            for (size_t j = 0; j < num_options; ++j) {
                if (strcmp(argv[i], options[j].option_short_name) == 0 ||
                    strcmp(argv[i], options[j].option_long_name) == 0) {
                    *(options[j].flag) = 1;
                    break;
                }
            }
        }
    }

    if (repeat != DEFAULT_REPEAT_VALUE) {
        printf("Repeat count: %d\n", repeat);
    } else {
        printf("Repeat count not provided. Using default value or -1 if not specified.\n");
    }
    XTEST_ITER_REAPET = repeat;

    return 0;
} // end of func

// Initializes an XUnitRunner and processes command-line arguments.
XUnitRunner xtest_start(int argc, char **argv) {
    XUnitRunner runner;
    unsigned int num_options = sizeof(options) / sizeof(options[0]);
    xtest_cli_parse_args(options, num_options, argc, argv);

    if (XTEST_FLAG_VERSION) {
        puts(XTEST_VERSION);
        exit(EXIT_SUCCESS);
    } else if (XTEST_FLAG_HELP) {
        xtest_cli_print_usage("Xcli", options, num_options);
        exit(EXIT_SUCCESS);
    }

    if (XTEST_FLAG_REPEAT) {
        if (num_options + 1 < argc && strcmp(argv[num_options], "--repeat") == 0) {
            char* endPtr;
            XTEST_ITER_REAPET = strtol(argv[num_options + 1], &endPtr, 10);

            if (*endPtr != '\0') {
                fprintf(stderr, "Error: Invalid number after --repeat\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    runner.stats = (XTestStats){0, 0, 0, 0};
    return runner;
} // end of func

// Finalizes the execution of a Trilobite XUnit runner and displays test results.
int xtest_end(XUnitRunner *runner) {
    xtest_output_xunittest_report(runner);
    return runner->stats.failed_count;
} // end of func

// Common functionality for running a test case and updating test statistics.
void xtest_run_test(XTestCase* test_case, XTestStats* stats, XTestFixture* fixture) {
    // Check if the test should be ignored
    if (XIGNORE_TEST_CASE) {
        stats->ignored_count++;
        XIGNORE_TEST_CASE = false;
        test_case->ignored = true;
        return;
    }

    // Record start time
    clock_t start_time = clock();

    // Run tests sequentially
    for (int iter = 0; iter < XTEST_ITER_REAPET; iter++) {
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

    // Output test format information
    xtest_output_xunittest_format(test_case->is_benchmark, test_case, stats);
} // end of func

// Runs a test case and updates test statistics.
void xtest_run_test_unit(XTestCase* test_case, XTestStats* stats) {
    // Initialize the test as not ignored
    test_case->ignored = false;

    // Run the test
    xtest_run_test(test_case, stats, NULL);
} // end of func

// Runs a test case within a test fixture and updates test statistics.
void xtest_run_test_fixture(XTestCase* test_case, XTestFixture* fixture, XTestStats* stats) {
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

// Custom assertion function with optional message.
void xassert(bool expression, const char *message, const char* file, int line, const char* func) {
    if (!XASSERT_PASS_SCAN) {
        return;
    } else if (!expression) {
        XASSERT_PASS_SCAN = false;
    }
    xtest_output_xassert_expect(expression, message, "Assert", file, line, func);
} // end of func

// Custom expectation function with optional message.
void xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {
        XEXPECT_PASS_SCAN = false;
    }
    xtest_output_xassert_expect(expression, message, "Expect", file, line, func);
} // end of func
