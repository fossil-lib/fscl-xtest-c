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
const char *XTEST_VERSION = "0.4.0";

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

/**
 * @brief Output for XUnit Test Case Assert.
 *
 * Outputs information related to an assertion in a test case, including the assertion status (PASS/FAIL)
 * and an optional error message.
 *
 * @param expression  The result of the assertion (true for pass, false for fail).
 * @param message     An optional message associated with the assertion.
 */
static void xtest_output_xassert(bool expression, const char *message, const char* file, int line, const char* func) {
    const char* color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char* color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";
    const char* color_red = XTEST_FLAG_COLORED ? ANSI_COLOR_RED : "";
    const char* color_green = XTEST_FLAG_COLORED ? ANSI_COLOR_GREEN : "";

    if (!expression && (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK)) {
        printf("%s", color_start);
        if (XTEST_FLAG_VERBOSE) {
            printf("[Asserted case failed]" ANSI_COLOR_RESET "\n%sline: %.4i\nfile: %s\nfunc: %s\n", color_red, line, file, func);
            printf("%smessage: %s\nresult: %s\n", color_red, message, expression ? "PASS" : "FAIL");
        } else if (XTEST_FLAG_CUTBACK) {
            printf("%s", (XASSERT_PASS_SCAN ? color_green "[O]" : color_red "[X]") ANSI_COLOR_RESET);
        }
        printf("%s", color_reset);
    }
} // end of func

/**
 * @brief Output for XUnit Test Case Expect.
 *
 * Outputs information related to an expectation in a test case, including the expectation status (PASS/FAIL)
 * and an optional error message.
 *
 * @param expression  The result of the expectation (true for pass, false for fail).
 * @param message     An optional message associated with the expectation.
 */
static void xtest_output_xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    const char* color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char* color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";
    const char* color_red = XTEST_FLAG_COLORED ? ANSI_COLOR_RED : "";
    const char* color_green = XTEST_FLAG_COLORED ? ANSI_COLOR_GREEN : "";

    if (!expression && (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK)) {
        printf("%s", color_start);
        if (XTEST_FLAG_VERBOSE) {
            printf("[Expect assert failed]" ANSI_COLOR_RESET "\n%sline: %.4i\nfile: %s\nfunc: %s\n", color_red, line, file, func);
            printf("%smessage: %s\nresult: %s\n", color_red, message, expression ? "PASS" : "FAIL");
        } else if (XTEST_FLAG_CUTBACK) {
            printf("%s", (XEXPECT_PASS_SCAN ? color_green "[O]" : color_red "[X]") ANSI_COLOR_RESET);
        }
        printf("%s", color_reset);
    }
} // end of func

/**
 * @brief Output for XUnit Test Case Ignored.
 *
 * Outputs information indicating that a test case has been ignored along with an optional reason.
 *
 * @param reason  The reason for ignoring the test case.
 */
static void xtest_output_xignore(const char* reason, const char* file, int line, const char* func) {
    const char* color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char* color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";
    const char* color_yellow = XTEST_FLAG_COLORED ? ANSI_COLOR_YELLOW : "";

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

/**
 * @brief Formats and displays information about the start of a test case.
 *
 * This function formats and displays information about the start of a test case,
 * including its description, type (benchmark or unit test), and the total number of test cases.
 *
 * @param test_case The test case for which the information is displayed.
 * @param stats     The statistics containing the total count of test cases.
 */
static void xtest_output_xunittest_format_start(XTestCase* test_case, XTestStats *stats) {
    const char* color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char* color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";

    if (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK) {
        printf("%s", color_start);
        if (XTEST_FLAG_VERBOSE) {
            puts("[Running XUnit Test]" ANSI_COLOR_RESET);
            printf("name  : %s\nnumber: %.4i\ntype: %s\n",
                test_case->name, stats->total_count + 1, !test_case->is_benchmark ? "Unit test" : "Benchmark");
        } else if (XTEST_FLAG_CUTBACK) {
            printf("name: %s, type: %s\n", test_case->name, !test_case->is_benchmark ? "unit" : "mark");
        }
        printf("%s", color_reset);
    }
} // end of func

/**
 * @brief Formats and displays information about the end of a test case.
 *
 * This function formats and displays information about the end of a test case,
 * including its description, type (benchmark or unit test), and the elapsed time.
 *
 * @param test_case The test case for which the information is displayed.
 */
static void xtest_output_xunittest_format_end(XTestCase* test_case) {
    const char* color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char* color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";

    if (XTEST_FLAG_VERBOSE || XTEST_FLAG_CUTBACK) {
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

/**
 * @brief Output for XUnit Test Case Report.
 *
 * Outputs a summary report of test results, including the number of tests passed, failed, ignored, and the total count.
 *
 * @param runner  Pointer to the XUnitRunner structure containing test statistics.
 */
static void xtest_output_xunittest_report(XUnitRunner *runner) {
    const char* color_start = XTEST_FLAG_COLORED ? ANSI_COLOR_BLUE : "";
    const char* color_reset = XTEST_FLAG_COLORED ? ANSI_COLOR_RESET : "";

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

/**
 * @brief Prints usage instructions, including custom options, for a command-line program.
 *
 * This function prints usage instructions for a command-line program, including custom options.
 * It displays the program name and lists available options along with their short and long names
 * and descriptions.
 *
 * @param program_name  Name of the command-line program.
 * @param options       Array of XTestCliOption structures representing available options.
 * @param num_options   Number of elements in the options array.
 *
 * @return              None.
 */
void xtest_cli_print_usage(const char* program_name, const XTestCliOption* options, unsigned int num_options) {
    puts("########################################");
    printf("Usage: %s [options]\n", program_name);
    puts("Options:");

    for (unsigned int i = 0; i < num_options; ++i) {
        printf("  %s %s\t%s\n", options[i].option_long_name, options[i].option_short_name, options[i].description);
    } // end for
    puts("########################################");
} // end of func

/**
 * @brief Parses command-line arguments and sets flags based on specified options.
 *
 * This function parses command-line arguments and sets flags based on the specified options.
 * It iterates through the command-line arguments and compares them with the short and long
 * names of the provided options to set corresponding flags.
 *
 * @param options       Array of XTestCliOption structures representing available options.
 * @param num_options   Number of elements in the options array.
 * @param argc          Number of command-line arguments.
 * @param argv          Array of command-line argument strings.
 *
 * @return              0 if the parsing is successful.
 */
int xtest_cli_parse_args(XTestCliOption* options, unsigned int num_options, int argc, char** argv) {
    int repeatCount = -1; // Default value in case "--repeat" is not provided

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--repeat") == 0 && i + 1 < argc) {
            // Attempt to convert the next argument to an integer
            char* endPtr; // To check for conversion errors
            repeatCount = strtol(argv[i + 1], &endPtr, 10);

            if (*endPtr != '\0') {
                fprintf(stderr, "Error: Invalid number after --repeat\n");
                return 1; // Exit with an error code
            }

            i++; // Skip the next argument since we've already processed it
        } else {
            // Check for other command-line options and set corresponding flags
            for (size_t j = 0; j < num_options; ++j) {
                if (strcmp(argv[i], options[j].option_short_name) == 0) {
                    *(options[j].flag) = 1;
                    break;
                } else if (strcmp(argv[i], options[j].option_long_name) == 0) {
                    *(options[j].flag) = 1;
                    break;
                }
            }
        }
    }

    // Now you have the repeatCount value and can use it as needed
    if (repeatCount != -1) {
        printf("Repeat count: %d\n", repeatCount);
    } else {
        printf("Repeat count not provided. Using default value or -1 if not specified.\n");
    }
    XTEST_ITER_REAPET = repeatCount;

    return 0;
} // end of func



/**
 * @brief Initializes an XUnitRunner and processes command-line arguments.
 *
 * This function initializes an XUnitRunner, processes command-line arguments to handle custom options,
 * and displays version information or usage instructions if requested.
 *
 * @param argc  Number of command-line arguments.
 * @param argv  Array of command-line argument strings.
 *
 * @return      An initialized XUnitRunner structure.
 */
XUnitRunner xtest_start(int argc, char **argv) {
    XUnitRunner runner;
    unsigned int num_options = sizeof(options) / sizeof(options[0]);
    xtest_cli_parse_args(options, num_options, argc, (char**)argv);

    if (XTEST_FLAG_VERSION) {
        puts(XTEST_VERSION);
        exit(EXIT_SUCCESS);
    } else if (XTEST_FLAG_HELP) {
        xtest_cli_print_usage("Xrunner", options, num_options);
        exit(EXIT_SUCCESS);
    } // end if, else if

    if (XTEST_FLAG_REPEAT) {
        if (strcmp(options->option_long_name, "--repeat") == 0 && num_options + 1 < argc) {
        // Attempt to convert the next argument to an integer
            char* end_ptr; // To check for conversion errors
            XTEST_ITER_REAPET = strtol(argv[num_options + 1], &end_ptr, 10);

            if (*end_ptr != '\0') {
                fprintf(stderr, "Error: Invalid number after --repeat\n");
                exit(1); // Exit with an error code
            } // end if
        } // end if
    } // end if

    runner.stats = (XTestStats){0, 0, 0, 0};
    return runner;
} // end of func

/**
 * @brief Finalizes the execution of a Trilobite XUnit runner and displays test results.
 *
 * This function prints the test results, including the number of tests passed, failed, ignored,
 * and the total count. It also returns the count of failed tests.
 *
 * @param runner    Pointer to the Trilobite XUnit runner containing test statistics.
 *
 * @return          The count of failed tests.
 */
int xtest_end(XUnitRunner *runner) {
    xtest_output_xunittest_report(runner);
    return runner->stats.failed_count;
} // end of func

/**
 * @brief Runs a unit test case and updates test statistics.
 *
 * This function executes a unit test case, records the execution time, and updates the
 * test statistics based on the test result.
 *
 * @param test_case   Pointer to the unit test case to be executed.
 * @param stats       Pointer to the structure containing test statistics.
 *
 * @return            None.
 */
void xtest_run_test_unit(XTestCase* test_case, XTestStats* stats)  {
    xtest_output_xunittest_format_start(test_case, stats);

    // Execute the test function
    if (!XIGNORE_TEST_CASE) {
        clock_t start_time = clock(); // Record start time
        for (int iter = 0; iter < XTEST_ITER_REAPET; iter++) {
            test_case->test_function();
        } // end for

        clock_t end_time = clock(); // Record end time

        // Calculate elapsed time and store it in the test_case
        test_case->elapsed_time = end_time - start_time;

        // Determine whether the test passed or failed based on your logic
        bool test_passed = true; // Assume the test passes by default

        // Check whether expectation scanning is enabled
        if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN) {
            // If any expectations fail, consider the test as failed
            test_passed = false;
        } // end if

        // Update the appropriate count based on the test result
        if (test_passed) {
            stats->passed_count++;
        } else {
            stats->failed_count++;
        } // end if else
    } else {
        // Update the ignored count
        stats->ignored_count++;
        XIGNORE_TEST_CASE = false;
    } // end if else
    test_case->ignored = XIGNORE_TEST_CASE;
    xtest_output_xunittest_format_end(test_case);

    // Update the total count
    stats->total_count++;
} // end of func

/**
 * @brief Runs a test case within a test fixture and updates test statistics.
 *
 * This function executes a test case within a given test fixture, records the execution time,
 * and updates the test statistics based on the test result.
 *
 * @param test_case   Pointer to the test case to be executed.
 * @param fixture     Pointer to the test fixture containing setup and teardown functions.
 * @param stats       Pointer to the structure containing test statistics.
 *
 * @return            None.
 */
void xtest_run_test_fixture(XTestCase* test_case, XTestFixture* fixture, XTestStats* stats)  {
    xtest_output_xunittest_format_start(test_case, stats);

    // Execute the test function within the fixture
    if (!XIGNORE_TEST_CASE) {
        clock_t start_time = clock(); // Record start time

        for (int iter = 0; iter < XTEST_ITER_REAPET; iter++) {
            if (fixture->setup) {
                fixture->setup();
            } // end if

            test_case->test_function();
   
            if (fixture->teardown) {
                fixture->teardown();
            } // end if

        } // end for

        clock_t end_time = clock(); // Record end time

        // Calculate elapsed time and store it in the test_case
        test_case->elapsed_time = end_time - start_time;

        // Determine whether the test passed or failed based on your logic
        bool test_passed = true; // Assume the test passes by default

        // Check whether expectation scanning is enabled
        if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN) {
            // If any expectations fail, consider the test as failed
            test_passed = false;
        } // end if

        // Update the appropriate count based on the test result
        if (test_passed) {
            stats->passed_count++;
        } else {
            stats->failed_count++;
        } // end if else
    } else {
        // Update the ignored count
        stats->ignored_count++;
        XIGNORE_TEST_CASE = false;
    } // end if else
    test_case->ignored = XIGNORE_TEST_CASE;
    xtest_output_xunittest_format_end(test_case);

    // Update the total count
    stats->total_count++;
} // end of func

/**
 * @brief Marks a test case as ignored with a specified reason and prints it to stderr.
 *
 * This function is used to indicate that a test case should be ignored and provides a reason
 * for the omission. It prints the specified reason to the standard error stream (stderr).
 *
 * @param reason  The reason for ignoring the test case.
 */
void xignore(const char* reason, const char* file, int line, const char* func) {
    XIGNORE_TEST_CASE = true;
    xtest_output_xignore(reason, file, line, func);
} // end of func

/**
 * @brief Custom assertion function with optional message.
 *
 * This function allows custom assertions and displays a message if the assertion fails.
 * It also provides an option to disable further assertion scanning after the first failure.
 *
 * @param expression  The expression to be asserted (should evaluate to true for success).
 * @param message     An optional message to be displayed when the assertion fails.
 *
 * @return            None.
 */
void xassert(bool expression, const char *message, const char* file, int line, const char* func) {
    if (!XASSERT_PASS_SCAN) {
        return;
    } else if (!expression) {
        XASSERT_PASS_SCAN = false;
    } // end if, else if
    xtest_output_xassert(expression, message, file, line, func);
} // end of func

/**
 * @brief Custom expectation function with optional message.
 *
 * This function allows custom expectations and displays a message if the expectation fails.
 * It also provides an option to disable further expectation scanning after the first failure.
 *
 * @param expression  The expression to be expected (should evaluate to true for success).
 * @param message     An optional message to be displayed when the expectation fails.
 *
 * @return            None.
 */
void xexpect(bool expression, const char *message, const char* file, int line, const char* func) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {
        XEXPECT_PASS_SCAN = false;
    } // end if
    xtest_output_xexpect(expression, message, file, line, func);
} // end of func
