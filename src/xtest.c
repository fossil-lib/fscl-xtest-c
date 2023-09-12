/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
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
const char *XTEST_VERSION = "0.3.1";

// Static control panel for assert/expect and marks
static bool XERRORS_PASS_SCAN = true;
static bool XEXPECT_PASS_SCAN = true;
static bool XASSERT_PASS_SCAN = true;
static bool XIGNORE_TEST_CASE = false;

// Static control panel for command-line arguments
static bool XTEST_FLAG_VERBOSE    = false;
static bool XTEST_FLAG_VERSION    = false;
static bool XTEST_FLAG_COLORED    = false;
static bool XTEST_FLAG_HELP       = false;

// XUnit options for the tester to switch on-off
XTestCliOption options[] = {
     { "--verbose",    "-V", "Show more information to standard output", &XTEST_FLAG_VERBOSE },
     { "--version",    "-v", "Get the version of this test framework", &XTEST_FLAG_VERSION },
     { "--color"  ,    "-c", "Enable color text output", &XTEST_FLAG_COLORED },
     { "--help",       "-h", "Print this message you see before you're eyes", &XTEST_FLAG_HELP }
 }; // end of command-line options

// TODO: add —-only-tests, —-only-bench, —-only-ai, —-repeat, —-thread-run
//       test <test_name> bench <bench_name> fixture <name>

// TODO: add C++ compatibility for binding.

/**
 * @brief Output for XUnit Test Case Assert.
 *
 * Outputs information related to an assertion in a test case, including the assertion status (PASS/FAIL)
 * and an optional error message.
 *
 * @param expression  The result of the assertion (true for pass, false for fail).
 * @param message     An optional message associated with the assertion.
 */
static void xtest_output_xassert(bool expression, const char *message) {
    if (XTEST_FLAG_COLORED) {
        puts(ANSI_COLOR_BLUE "[ASSERT] XUnit Test Case Assert" ANSI_COLOR_RESET);
        if (!expression) {
            printf(ANSI_COLOR_RED "[MESSAGE] :" ANSI_COLOR_RESET " %s\n", message);
        } // end if
        printf(ANSI_COLOR_BLUE "[RESULT]  :" ANSI_COLOR_RESET " %s\n", expression? "PASS" : "FAIL");
    } else {
        puts("[ASSERT] XUnit Test Case Assert");
        if (!expression) {
            printf("[MESSAGE] : %s\n", message);
        } // end if
        printf("[RESULT]  : %s\n", expression? "PASS" : "FAIL");
    } // end if else
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
static void xtest_output_xexpect(bool expression, const char *message) {
    if (XTEST_FLAG_COLORED) {
        puts(ANSI_COLOR_BLUE "[EXPECT] XUnit Test Case Expect" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "[MESSAGE] :" ANSI_COLOR_RESET " %s\n", message);
        printf(ANSI_COLOR_BLUE "[RESULT]  :" ANSI_COLOR_RESET " %s\n", expression? "PASS" : "FAIL");
    } else {
        puts("[EXPECT] XUnit Test Case Expect");
        printf("[MESSAGE] : %s\n", message);
        printf("[RESULT]  : %s\n", expression? "PASS" : "FAIL");
    } // end if else
} // end of func

/**
 * @brief Output for XUnit Test Case Error.
 *
 * Outputs information related to an error condition in a test case, including the error status (PASS/FAIL)
 * and an optional error message.
 *
 * @param expression  The result of the error condition (true for pass, false for fail).
 * @param message     An optional message associated with the error.
 */
static void xtest_output_xerrors(bool expression, const char *message) {
    if (XTEST_FLAG_COLORED) {
        puts(ANSI_COLOR_BLUE "[ERROR] XUnit Test Case Error" ANSI_COLOR_RESET);
        if (!expression) {
            printf(ANSI_COLOR_BLUE "[MESSAGE] :" ANSI_COLOR_RESET " %s\n", message);
        } // end if
        printf(ANSI_COLOR_BLUE "[RESULT]  :" ANSI_COLOR_RESET " %s\n", expression? "PASS" : "FAIL");
    } else {
        puts("[ERROR] XUnit Test Case Error");
        printf("[MESSAGE] : %s\n", message);
        printf("[RESULT]  : %s\n", expression? "PASS" : "FAIL");
    } // end if else
} // end of func

/**
 * @brief Output for XUnit Test Case Ignored.
 *
 * Outputs information indicating that a test case has been ignored along with an optional reason.
 *
 * @param reason  The reason for ignoring the test case.
 */
static void xtest_output_xignore(const char* reason) {
    if (XTEST_FLAG_COLORED) {
        printf(ANSI_COLOR_BLUE "[IGNORE] XUnit Test Case Ignored\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "[MESSAGE] : " ANSI_COLOR_RESET " %s\n", reason);
    } else {
        printf(ANSI_COLOR_BLUE "[IGNORE] XUnit Test Case Ignored\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "[MESSAGE] : " ANSI_COLOR_RESET " %s\n", reason);
    } // end if else
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
    puts("\n#####################################");
    if (XTEST_FLAG_COLORED) {
        printf(ANSI_COLOR_BLUE "[START TEST CASE] Description: %s\n" ANSI_COLOR_RESET, test_case->name);
        printf(ANSI_COLOR_BLUE "[NUMBER] : " ANSI_COLOR_RESET " %d\n", stats->total_count + 1);
        printf(ANSI_COLOR_BLUE "[TYPE  ] : " ANSI_COLOR_RESET " %s\n", test_case->is_benchmark? "Benchmark" : "Unit Test");
    } else {
        printf("[START TEST CASE] Description: %s\n", test_case->name);
        printf("[NUMBER] : %d\n", stats->total_count + 1);
        printf("[TYPE  ] : %s\n", test_case->is_benchmark? "Benchmark" : "Unit Test");
    } // end if else
    puts("#####################################\n");
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
    puts("\n#####################################");
    if (XTEST_FLAG_COLORED) {
        printf(ANSI_COLOR_BLUE"[END TEST CASE] Description: %s\n" ANSI_COLOR_RESET, test_case->name);
        printf(ANSI_COLOR_BLUE"[TIME  ] : %lu\n" ANSI_COLOR_RESET, test_case->elapsed_time);
    } else {
        printf("[END TEST CASE] Description: %s\n", test_case->name);
        printf("[TIME  ] : %.6lu\n", test_case->elapsed_time);
    } // end if else
    puts("#####################################\n");
} // end of func

/**
 * @brief Output for XUnit Test Case Report.
 *
 * Outputs a summary report of test results, including the number of tests passed, failed, ignored, and the total count.
 *
 * @param runner  Pointer to the XUnitRunner structure containing test statistics.
 */
static void xtest_output_xunittest_report(XUnitRunner *runner) {
    puts("\n\n#####################################");
    if (XTEST_FLAG_COLORED) {
        puts(ANSI_COLOR_BLUE "[TRILOBITE XUNIT RUNNER] results of the test" ANSI_COLOR_RESET);
        printf("Tests passed: %d\n", runner->stats.passed_count);
        printf("Tests failed: %d\n", runner->stats.failed_count);
        printf("Tests ignored: %d\n", runner->stats.ignored_count);
        printf("Total count: %d\n", runner->stats.total_count);
    } else {
        puts("[TRILOBITE XUNIT RUNNER] results of the test");
        printf("Tests passed: %d\n", runner->stats.passed_count);
        printf("Tests failed: %d\n", runner->stats.failed_count);
        printf("Tests ignored: %d\n", runner->stats.ignored_count);
        printf("Total count: %d\n", runner->stats.total_count);
    } // end if else
    puts("#####################################");
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
    printf("Options:\n");

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
    for (int i = 1; i < argc; ++i) {
        for (size_t j = 0; j < num_options; ++j) {
            if (strcmp(argv[i], options[j].option_short_name) == 0) {
                *(options[j].flag) = 1;
                break;
            } else if (strcmp(argv[i], options[j].option_long_name) == 0) {
                *(options[j].flag) = 1;
                break;
            } // end if, else if
        } // end for
    } // end for
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
    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_report(runner);
    } else {
        puts("\n\n[TRILOBITE XUNIT RUNNER] results of the test");
        printf("::passed: %.2d failed: %.2d ignored: %.2d total: %.2d\n", 
            runner->stats.passed_count, runner->stats.failed_count,
            runner->stats.ignored_count, runner->stats.total_count);
    } // end if else

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
    // Check to see if we can skip
    test_case->ignored = XIGNORE_TEST_CASE;

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_format_start(test_case, stats);
    } // end if

    // Execute the test function
    if (!test_case->ignored) {
        clock_t start_time = clock(); // Record start time

        test_case->test_function();

        clock_t end_time = clock(); // Record end time

        // Calculate elapsed time and store it in the test_case
        test_case->elapsed_time = end_time - start_time;

        // Determine whether the test passed or failed based on your logic
        bool test_passed = true; // Assume the test passes by default

        // Check whether expectation scanning is enabled
        if (!XEXPECT_PASS_SCAN || !XERRORS_PASS_SCAN) {
            // If any expectations fail, consider the test as failed
            test_passed = false;
        } // end if

        if (!XASSERT_PASS_SCAN) {
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

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_format_end(test_case);
    } // end if

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
    // Check to see if we can skip
    test_case->ignored = XIGNORE_TEST_CASE;

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_format_start(test_case, stats);
    } // end if

    // Execute the test function within the fixture
    if (!test_case->ignored) {
        clock_t start_time = clock(); // Record start time

        if (fixture->setup) {
            fixture->setup();
        } // end if
   
        test_case->test_function();
   
        if (fixture->teardown) {
            fixture->teardown();
        } // end if

        clock_t end_time = clock(); // Record end time

        // Calculate elapsed time and store it in the test_case
        test_case->elapsed_time = end_time - start_time;

        // Determine whether the test passed or failed based on your logic
        bool test_passed = true; // Assume the test passes by default

        // Check whether expectation scanning is enabled
        if (!XEXPECT_PASS_SCAN || !XERRORS_PASS_SCAN) {
            // If any expectations fail, consider the test as failed
            test_passed = false;
        } // end if

        if (!XASSERT_PASS_SCAN) {
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

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_format_end(test_case);
    } // end if

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
void xignore(const char* reason) {
    XIGNORE_TEST_CASE = true;

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xignore(reason);
    } else {
        if (XTEST_FLAG_COLORED) {
            printf(ANSI_COLOR_YELLOW "?" ANSI_COLOR_RESET);
        } else {
            putchar('?');
        } // end if else
    } // end if else
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
void xassert(bool expression, const char *message) {
    if (!XASSERT_PASS_SCAN) {
        return;
    } else if (!expression) {
        XASSERT_PASS_SCAN = false;
    } // end if, else if

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xassert(expression, message);
    } else {
        if (XTEST_FLAG_COLORED) {
            printf("%s", (XASSERT_PASS_SCAN)? ANSI_COLOR_GREEN "O" ANSI_COLOR_RESET : ANSI_COLOR_RED "X" ANSI_COLOR_RESET);
        } else {
            printf("%s", (XASSERT_PASS_SCAN)? "O" : "X");
        } // end if else
    } // end if else
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
void xexpect(bool expression, const char *message) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {        
        XEXPECT_PASS_SCAN = false;
    } // end if

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xexpect(expression, message);
    } else {
        if (XTEST_FLAG_COLORED) {
            printf("%s", (XEXPECT_PASS_SCAN)? ANSI_COLOR_GREEN "O" ANSI_COLOR_RESET : ANSI_COLOR_RED "X" ANSI_COLOR_RESET);
        } else {
            printf("%s", (XEXPECT_PASS_SCAN)? "O" : "X");
        } // end if else
    } // end if else
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
void xerrors(bool expression, const char *message) {
    XERRORS_PASS_SCAN = true;

    if (!expression) {
        XERRORS_PASS_SCAN = false;
    } // end if, else if

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xerrors(expression, message);
    } else {
        if (XTEST_FLAG_COLORED) {
            printf("%s", (XERRORS_PASS_SCAN)? ANSI_COLOR_GREEN "O" ANSI_COLOR_RESET : ANSI_COLOR_RED "X" ANSI_COLOR_RESET);
        } else {
            printf("%s", (XERRORS_PASS_SCAN)? "O" : "X");
        } // end if else
    } // end if else
} // end of func
