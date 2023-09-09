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

// Static array to hold test cases
static bool XEXPECT_PASS_SCAN = true;
static bool XASSERT_PASS_SCAN = true;

static bool XTEST_FLAG_VERBOSE    = false;
static bool XTEST_FLAG_VERSION    = false;
static bool XTEST_FLAG_COLORED    = false;
static bool XTEST_FLAG_HELP       = false;
static bool XTEST_FLAG_ONLY_TESTS = false;
static bool XTEST_FLAG_ONLY_BENCH = false;

CLIOption options[] = {
     { "--verbose",    "-m", "Show more information to standard output", &XTEST_FLAG_VERBOSE },
     { "--version",    "-v", "Get the version of this test framework", &XTEST_FLAG_VERSION },
     { "--color"  ,    "-c", "Enable color text output", &XTEST_FLAG_COLORED },
     { "--help",       "-h", "Print this message you see before you're eyes", &XTEST_FLAG_HELP },
     { "--only-tests", "-t", "Only run unit test cases", &XTEST_FLAG_ONLY_TESTS },
     { "--only-bench", "-b", "Only run benchmark cases", &XTEST_FLAG_ONLY_BENCH }
 }; // end of command-line options

// Function to print usage instructions, including custom options
void xtest_cli_print_usage(const char* program_name, const XTestCliOption* options, size_t num_options) {
    printf("Usage: %s [options]\n", program_name);
    printf("Options:\n");

    for (size_t i = 0; i < num_options; ++i) {
        printf("  %s\t%s\n", options[i].option_name_long, options[i].option_name_short, options[i].description);
    } // end for
    puts("########################################");
} // end of func

// Function to parse command-line arguments and set custom option flags
int xtest_cli_parse_args(XTestCliOption* options, size_t num_options, int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        for (size_t j = 0; j < num_options; ++j) {
            if (strcmp(argv[i], options[j].option_name) == 0) {
                *(options[j].flag) = 1;
                break;
            } // end if
        } // end for
    } // end for
    return 0;
} // end of func

XUnitRunner xtest_start(int argc, char **argv) {
    XUnitRunner runner;
    xtest_cli_parse_args(options, num_options, argc, (char**)argv);
    runner.verbose = XTEST_FLAG_VERBOSE;       // --verbose, -v : Show more information to standard output
    runner.version = XTEST_FLAG_VERSION;       // --version     : Get the version of this test framework
    runner.color = XTEST_FLAG_COLORED;         // --color, -c   : Enable color text output 
    runner.help = XTEST_FLAG_HELP;             // --help, -h    : Print this message you see before you're eyes
    runner.only_tests = XTEST_FLAG_ONLY_TESTS; // --only-tests  : Only run unit test cases
    runner.only_bench = XTEST_FLAG_ONLY_BENCH; // --only-bench  : Only run benchmark cases

    // TODO: process args here
   
    runner.stats = (XTestStats){0, 0, 0, 0, 0, 0};
    return runner;
} // end of func

int xtest_end(XUnitRunner *runner) {
    printf("%s[TRILOBITE XUNIT RUNNER] results of the test%s", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    printf("Tests passed: %d\n", runner->stats.passed_count);
    printf("Tests failed: %d\n", runner->stats.failed_count);
    printf("Tests ignored: %d\n", runner->stats.ignored_count);
    printf("Total count: %d\n", runner->stats.total_count);
    return runner->stats.failed_count;
} // end of func

void xtest_run_unit(const XTestCase* test_case, XTestStats* stats)  {
    // Execute the test function
    if (!test_case->ignored) {
        clock_t start_time = clock(); // Record start time

        // ... Execute the test function
        // Example:
        // test_case->test_function();

        clock_t end_time = clock(); // Record end time

        // Calculate elapsed time and store it in the test_case
        test_case->elapsed_time = end_time - start_time;

        // Determine whether the test passed or failed based on your logic
        bool test_passed = true; // Assume the test passes by default

        // Check whether expectation scanning is enabled
        if (!XEXPECT_PASS_SCAN) {
            // If any expectations fail, consider the test as failed
            test_passed = false;
        } // end if

        // Check whether assertion scanning is enabled
        if (!XASSERT_PASS_SCAN) {
            // If any assertions fail, consider the test as failed
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

    // Update the total count
    stats->total_count++;
} // end of func

void xtest_run_fixture(const XTestCase* test_case, const XTestFixture* fixture, XTestStats* stats)  {
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
        if (!XEXPECT_PASS_SCAN) {
            // If any expectations fail, consider the test as failed
            test_passed = false;
        } // end if

        // Check whether assertion scanning is enabled
        if (!XASSERT_PASS_SCAN) {
            // If any assertions fail, consider the test as failed
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

    // Update the total count
    stats->total_count++;
} // end of func

/**
    @brief Starter for the Xunit test runner which will process commands
    and any other setup steps before starting.

    @param argc The number of command line arguments
    @param argv The array of command line arguments
    @returns An instance of the XUnitRunner struct containing the tag
             to run and the number of tests passed and failed
*/
XUnitRunner xtest_start(int argc, char **argv)
{
    XUnitRunner runner = {
        .passed_count = 0,
        .failed_count = 0,
        .run_tag = "both",
        .setup_function = NULL,
        .teardown_function = NULL};

    if (argc == 1) {
        return runner;
    } // end if

    const char *command = argv[1];
    if (!strcmp(command, "--only-tests")) {
        puts("Only running Xtest cases");
        runner.run_tag = "test";
        return runner;
    }
    else if (!strcmp(command, "--only-bench")) {
        puts("Only running Xbench cases");
        runner.run_tag = "bench";
        return runner;
    }
    else if (!strcmp(command, "--run-both")) {
        puts("Running all written cases");
    }
    else {
        printf(ANSI_COLOR_BLUE "Usage: runner command-line flags, runs both by default\n\n" ANSI_COLOR_RESET);
        puts(ANSI_COLOR_WHITE ": --help       : Prints this helpful message to the console     " ANSI_COLOR_RESET);
        puts(ANSI_COLOR_WHITE ": --only-tests : Skip benchmarks and only run test cases        " ANSI_COLOR_RESET);
        puts(ANSI_COLOR_WHITE ": --only-bench : Skip test cases and only run benchmarks        " ANSI_COLOR_RESET);
        puts(ANSI_COLOR_WHITE ": --run-both   : Run both test cases and benchmarks -> (default)" ANSI_COLOR_RESET);
        exit(EXIT_SUCCESS);
    } // end if, else if, else
    return runner;
} // end of func


/**
    @brief Asserts that the expression is true, and prints a message if it is not.

    @param expression The expression to check.
    @param message The message to print if the expression is false.

    @return void
*/
void xassert(bool expression, const char *message) {
    if (XASSERT_PASS_SCAN == false) {
        return;
    } else if (!expression) {
        printf(" --> %s: %s\n", ANSI_COLOR_RED "Failed" ANSI_COLOR_RESET, message);
        XASSERT_PASS_SCAN = false;
    } else {
        printf(" --> %s:\n", ANSI_COLOR_GREEN "Passed" ANSI_COLOR_RESET);
    } // end if, else if, else
} // end of func

/**
    @brief Expected that the expression is true, and prints a message if it is not.

    @param expression The expression to check.
    @param message The message to print if the expression is false.

    @return void
*/
void xexpect(bool expression, const char *message) {
    XEXPECT_PASS_SCAN = true;

    if (!expression) {
        printf(" --> %s: %s\n", ANSI_COLOR_RED "Failed" ANSI_COLOR_RESET, message);
        XEXPECT_PASS_SCAN = false;
    } // end if
    printf(" --> %s:\n", ANSI_COLOR_GREEN "Passed" ANSI_COLOR_RESET);
} // end of func
