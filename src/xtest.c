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
const char *XTEST_VERSION = "0.3.0";

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
static bool XTEST_FLAG_ONLY_TESTS = false;
static bool XTEST_FLAG_ONLY_BENCH = false;

// XUnit options for the tester to switch on-off
XTestCliOption options[] = {
     { "--verbose",    "-V", "Show more information to standard output", &XTEST_FLAG_VERBOSE },
     { "--version",    "-v", "Get the version of this test framework", &XTEST_FLAG_VERSION },
     { "--color"  ,    "-c", "Enable color text output", &XTEST_FLAG_COLORED },
     { "--help",       "-h", "Print this message you see before you're eyes", &XTEST_FLAG_HELP },
     { "--only-tests", "-t", "Only run unit test cases", &XTEST_FLAG_ONLY_TESTS },
     { "--only-bench", "-b", "Only run benchmark cases", &XTEST_FLAG_ONLY_BENCH }
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
static void xtest_output_xassert(bool expression, const char *message) {
    if (XTEST_FLAG_COLORED) {
        printf("%s[ASSERT] XUnit Test Case Assert%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
        printf("%s[MESSAGE] :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, message);
        printf("%s[RESULT]  :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, expression? "PASS" : "FAIL");
    } else {
        printf("[ASSERT] XUnit Test Case Assert\n");
        printf("[MESSAGE] : %s\n", message);
        printf("[RESULT]  : %s\n", expression? "PASS" : "FAIL");
    } // end if else
    puts("####################################-");
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
        printf("%s[EXPECT] XUnit Test Case Expect%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
        printf("%s[MESSAGE] :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, message);
        printf("%s[RESULT]  :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, expression? "PASS" : "FAIL");
    } else {
        printf("[EXPECT] XUnit Test Case Expect\n");
        printf("[MESSAGE] : %s\n", message);
        printf("[RESULT]  : %s\n", expression? "PASS" : "FAIL");
    } // end if else
    puts("####################################-");
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
        printf("%s[ERROR] XUnit Test Case Error%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
        printf("%s[MESSAGE] :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, message);
        printf("%s[RESULT]  :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, expression? "PASS" : "FAIL");
    } else {
        printf("[ERROR] XUnit Test Case Error\n");
        printf("[MESSAGE] : %s\n", message);
        printf("[RESULT]  : %s\n", expression? "PASS" : "FAIL");
    } // end if else
    puts("####################################-");
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
        printf("%s[IGNORE] XUnit Test Case Ignored%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
        printf("%s[MESSAGE] :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, reason);
    } else {
        printf("%s[IGNORE] XUnit Test Case Ignored%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
        printf("%s[MESSAGE] :%s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, reason);
    } // end if else
    puts("####################################-");
} // end of func

/**
 * @brief Output for XUnit Test Case Format.
 *
 * Outputs the format for a specific test case, including its name and elapsed time (if available).
 *
 * @param test_case  Pointer to the test case for which the format is displayed.
 */
static void xtest_output_xunittest_format(const XTestCase* test_case) {
    if (XTEST_FLAG_COLORED) {
        printf("%s[TEST CASE] %s%s\n", ANSI_COLOR_BLUE, test_case->name, ANSI_COLOR_RESET);
        printf("%s[TIME] : %s%s\n", ANSI_COLOR_BLUE, test_case->elapsed_time, ANSI_COLOR_RESET);
    } else {
        printf("[TEST CASE] %s\n", test_case->name);
        printf("[TIME] : %s\n", test_case->elapsed_time);
    } // end if else
    puts("#####################################");
} // end of func

/**
 * @brief Output for XUnit Test Case Report.
 *
 * Outputs a summary report of test results, including the number of tests passed, failed, ignored, and the total count.
 *
 * @param runner  Pointer to the XUnitRunner structure containing test statistics.
 */
static void xtest_output_xunittest_report(XUnitRunner *runner) {
    if (XTEST_FLAG_COLORED) {
        printf("%s[TRILOBITE XUNIT RUNNER] results of the test%s", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
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
void xtest_cli_print_usage(const char* program_name, const XTestCliOption* options, size_t num_options) {
    printf("Usage: %s [options]\n", program_name);
    printf("Options:\n");

    for (size_t i = 0; i < num_options; ++i) {
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
int xtest_cli_parse_args(XTestCliOption* options, size_t num_options, int argc, char** argv) {
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
    size_t num_options = sizeof(options) / sizeof(options[0]);
    xtest_cli_parse_args(options, num_options, argc, (char**)argv);

    if (XTEST_FLAG_VERSION) {
        puts(XTEST_VERSION);
        exit(EXIT_SUCCESS);
    } else if (XTEST_FLAG_HELP) {
        xtest_cli_print_usage("Xrunner", options, 6);
        exit(EXIT_SUCCESS);
    } // end if, else if
   
    runner.stats = (XTestStats){0, 0, 0, 0, 0, 0};
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
        printf(" \n");
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
void xtest_run_unit_unit(const XTestCase* test_case, XTestStats* stats)  {
    // Check to see if we can skip
    test_case->ignored = XIGNORE_TEST_CASE;

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
        if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN || !XERRORS_PASS_SCAN) {
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
    } // end if else

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_format(test_case);
    } // end if

    // Update the total count
    stats->total_count++;
    XIGNORE_TEST_CASE = false;
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
void xtest_run_unit_fixture(const XTestCase* test_case, const XTestFixture* fixture, XTestStats* stats)  {
    // Check to see if we can skip
    test_case->ignored = XIGNORE_TEST_CASE;

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
        if (!XEXPECT_PASS_SCAN || !XASSERT_PASS_SCAN || !XERRORS_PASS_SCAN) {
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
    } // end if else

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xunittest_format(test_case);
    } // end if

    // Update the total count
    stats->total_count++;
    XIGNORE_TEST_CASE = false;
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
        putchar('?');
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
        putchar('X');
        return;
    } else if (!expression) {
        XASSERT_PASS_SCAN = false;
    } // end if, else if

    if (XTEST_FLAG_VERBOSE) {
        xtest_output_xassert(expression, message);
    } else {
        printf("%s", (XEXPECT_PASS_SCAN)? "O" : "X");
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
        printf("%s", (XEXPECT_PASS_SCAN)? "O" : "X");
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
        printf("%s", (XERRORS_PASS_SCAN)? "O" : "X");
    }
} // end of func
