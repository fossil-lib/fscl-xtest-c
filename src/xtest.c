/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xtest.h"
#include "trilobite/xassert.h"

enum {MAX_TEST_CASES = 100}; // Maximum number of test cases

// Static array to hold test cases
XTestCase test_case[MAX_TEST_CASES];

// ANSI escape code macros for text color
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
    Starter for the Xunit test runner which will process commands
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
        .run_tag = "both"};

    if (argc == 1) {
        return runner;
    } // end if

    const char *command = argv[1];
    if (!strcmp(command, "--only-test")) {
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
    This function checks the result of the XUnitRunner and displays a
    message based on the result.

    @param runner The XUnitRunner object that is being checked
    @returns The number of failed tests that were run
*/
int xtest_end(XUnitRunner *runner)
{
    if (runner->failed_count > 0) {
        puts(ANSI_COLOR_RED "RUNNER: Failed" ANSI_COLOR_RESET);
    } else if (runner->passed_count == 0 && runner->failed_count == 0) {
        puts(ANSI_COLOR_YELLOW "RUNNER: Not sure what to do" ANSI_COLOR_RESET);
    } // end if else if
    else if (runner->passed_count > 0 || runner->failed_count == 0) {
        puts(ANSI_COLOR_GREEN "RUNNER: Passed" ANSI_COLOR_RESET);
    }
    
    printf(ANSI_COLOR_BLUE "SCORE: PASS [%2d] FAIL [%2d]\n\n" ANSI_COLOR_RESET, runner->passed_count, runner->failed_count);
    return runner->failed_count;
} // end of func

/**
    This function runs a test case and prints the results.

    @param test_case: A pointer to a XTestCase object containing
                      the test case to be run.
    @param runner: A pointer to a XUnitRunner object containing
                   the runner configuration.
    @returns void: No value is returned.
*/
void xtest_run(XTestCase *test_case, XUnitRunner *runner) {
    if (strcmp(runner->run_tag, "test") != 0 || strcmp(runner->run_tag, "both") != 0) {
        return;
    } // end if

    printf(ANSI_COLOR_BLUE "Running test: %s\n" ANSI_COLOR_RESET, test_case->name);

    if (test_case->setup_function) {
        test_case->setup_function();
    } // end if

    test_case->test_function();
    printf("%s\n\n", runner->run_tag);

    if (test_case->teardown_function) {
        test_case->teardown_function();
    } // end if

    puts("Assertions:");
    for (size_t i = 0; i < test_case->num_assertions; i++) {
        XAssert assertion = test_case->assertions[i];
        printf("%s: %s\n", assertion.passed ?
            ANSI_COLOR_GREEN "Passed" ANSI_COLOR_RESET :
            ANSI_COLOR_RED   "Failed" ANSI_COLOR_RESET, assertion.message);
        if (assertion.passed) {
            runner->passed_count++;
        } else {
            runner->failed_count++;
        } // end if else
    } // end for
    puts("\n");
} // end of func



/**
  This function xbench_run runs a benchmark and measures its elapsed time.

  @param XBench *benchmark: a pointer to the benchmark to be run
  @param XUnitRunner *runner: a pointer to the unit test runner

  @returns: void - the elapsed time of the benchmark is stored in benchmark->elapsed_time
*/
void xbench_run(XBench *benchmark, XUnitRunner *runner) {
    if (strcmp(runner->run_tag, "bench") != 0 || strcmp(runner->run_tag, "both") != 0)
    {
        return;
    } // end if

    printf(ANSI_COLOR_BLUE "Running benchmark: %s\n" ANSI_COLOR_RESET, benchmark->name);

    if (benchmark->setup_function) {
        benchmark->setup_function();
    } // end if

    clock_t start_time = clock();
    benchmark->benchmark_function();
    clock_t end_time = clock();

    if (benchmark->teardown_function) {
        benchmark->teardown_function();
    } // end if

    benchmark->elapsed_time = end_time - start_time;

    printf("Elapsed time: %f seconds\n\n", (double)benchmark->elapsed_time / CLOCKS_PER_SEC);

    runner->passed_count++;
} // end of func

/**
    Sets the setup and teardown functions for the given test case.

    @param test_case The test case to set the setup and teardown functions for.
    @param setup_func The function to be called before the test is run.
    @param teardown_func The function to be called after the test is complete.

    @returns Nothing.
*/
void xtest_set_setup_teardown(XTestCase *test_case, void (*setup_func)(void), void (*teardown_func)(void)) {
    test_case->setup_function = setup_func;
    test_case->teardown_function = teardown_func;
} // end of func


void xassert(bool expression, const char *message) {
    XAssert new_assertion = { message, expression };
    test_case->assertions[test_case->num_assertions++] = new_assertion;
} // end of func
