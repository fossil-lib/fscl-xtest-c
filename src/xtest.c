/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xtest.h"
#include <stdio.h>
#include <stdlib.h>

int TRIL_XTEST_FLAG_RESULT = 0;
int TRIL_XTEST_FLAG_ERROR = 0;
int TRIL_XTEST_FLAG_SKIP = 0;
int TRIL_XTEST_FLAG_OUTPUT = 0;

/*
  overview:
  > As the name suggests, UTestRunner is a tool
  > that is used to run or execute tests and track
  > results. The runner has a setup and teardown
  > function built-in and are set to nullptr by
  > default, the structure also has a range of
  > score values for pass/fail and more.
  >
  args:
  -> _pass: pass test score value
  -> _fail: fail test score value
  -> _skip: skip test score value
  -> _error: error test score value
  -> _total: total test score run
  -> _setup: Test case setup function
  -> _teardown: Test case teardown function
*/
struct UTestRunner
{
    // pass/fail counters
    int _pass;
    int _fail;
    int _skip;
    int _total;

    // setup/teardown functions
    void (*_setup)();
    void (*_teardown)();

}; // end struct

/*
  overview:
  >
  > This will create a test runner when the tester is
  > ready to begin a set of test cases. Test
  >

  usage:
  >
  > tril_xtest_create_runner(NULL, NULL);
  > tril_xtest_create_runner(setup, taerdown); // or set them later
  >
  > ... before tril_xtest_end_runner() ...
  >
  args:
  -> setup: The setup function being set
  -> teardown: The teardown function being set
*/
UTestRunner *tril_xtest_create_runner(void (*setup)(), void (*teardown)())
{
    UTestRunner *runner = malloc(sizeof(UTestRunner));
    if (!runner)
    {
        return NULL;
    } // end if

    //
    // score values
    runner->_total = 0;
    runner->_pass = 0;
    runner->_fail = 0;
    runner->_skip = 0;

    runner->_setup = setup;
    runner->_teardown = teardown;

    return runner;
} // end of func

/*
  overview:
  >
  > This will erase a test runner when the tester is
  > ready to clear the object out of memeory. Test
  > results are output to the console after we ensure
  > the tester can get a summery of all the test.
  >
  > If the runner is null then we return zero assuming
  > its a dry run or you forgot to allocate a test runner
  > with the 'tril_xtest_create_runner()'.
  >

  usage:
  >
  > ... after tril_xtest_create_runner() ...
  >
  > tril_xtest_end_runner(runner); // loops 7 times
  >
  args:
  -> runner: The runner for the test cases
*/
int tril_xtest_end_runner(UTestRunner *runner)
{
    if (runner == NULL)
    {
        return 0;
    } // end if

    puts("--- --- --- --- --- --- --- --- --- --- --- :");
    puts(": ---  :[Trilobite XTest - Dashboard]:  --- :");
    puts("--- --- --- --- --- --- --- --- --- --- --- :");
    printf(" -> Total : (%.2d)\n", runner->_total);
    puts("--- --- --- --- --- --- --- --- --- --- --- :");
    printf(" --> Pass : (%.2d)\n", runner->_pass);
    printf(" --> Fail : (%.2d)\n", runner->_fail);
    printf(" --> Skip : (%.2d)\n", runner->_skip);
    puts("--- --- --- --- --- --- --- --- --- --- --- :");
    puts("--- --- --- --- --- --- --- --- --- --- --- :");

    int result = runner->_fail;
    if (runner)
    {
        free(runner);
    } // end if

    return result;
} // end of func

/*
  overview:
  >
  > Basic flag control function that will allow the
  > tester to skip test cases. If the value is not
  > a known value then we defualt to zero.
  >

  usage:
  >
  > tril_xtest_flag_skip(1); // were skipping
  > tril_xtest_flag_skip(0); // were not skipping
  > tril_xtest_flag_skip(42); // we get zero anyway
  >
  args:
  -> runner: The runner for the test cases
*/
void tril_xtest_flag_skip(int flag)
{
    if (flag == 1)
    {
        TRIL_XTEST_FLAG_SKIP = flag;
    } // end if
    else
    {
        TRIL_XTEST_FLAG_SKIP = 0;
    } // end else

} // end of func

/*
  overview:
  >
  > Basic flag control function that will allow the
  > tester to turn of the output. If the value is not
  > a known value then we defualt to zero.
  >

  usage:
  >
  > tril_xtest_flag_output(1); // were skipping
  > tril_xtest_flag_output(0); // were not skipping
  > tril_xtest_flag_output(42); // we get zero anyway
  >
  args:
  -> runner: The runner for the test cases
*/
void tril_xtest_flag_output(int flag)
{
    if (flag == 1)
    {
        TRIL_XTEST_FLAG_OUTPUT = flag;
    } // end if
    else
    {
        TRIL_XTEST_FLAG_OUTPUT = 0;
    } // end else

} // end of func

/*
  overview:
  >
  > This will set a setup function for a set of cases until
  > a new setup function is used or stopped with the null
  > value.
  >

  usage:
  >
  > ... some function named setup ...
  >
  > tril_xtest_setup(runner, setup);
  >
  args:
  -> runner: The runner for the test cases
  -> func: The setup function being set
*/
void tril_xtest_setup(UTestRunner *runner, void (*func)())
{
    if (!func)
    {
        return;
    } // end if

    if (runner)
    {
        runner->_setup = func;
    } // end if

} // end of func

/*
  overview:
  >
  > This will set a teardown function for a set of cases until
  > a new teardown function is used or stopped with the null
  > value.
  >

  usage:
  >
  > ... some function named teardown ...
  >
  > tril_xtest_teardown(runner, teardown);
  >
  args:
  -> runner: The runner for the test cases
  -> func: The teardown function being set
*/
void tril_xtest_teardown(UTestRunner *runner, void (*func)())
{
    if (!func)
    {
        return;
    } // end if

    if (runner)
    {
        runner->_teardown = func;
    } // end if

} // end of func

/*
  overview:
  >
  > Adds test cases into a test runner. If the test
  > is null then we will ignore and return out of the
  > function else resume with the process of testing
  > the current test case.
  >

  usage:
  >
  > tril_xtest_run(runner, test_myCoffeeCup);
  >
  args:
  -> runner: The runner for the test cases
  -> test: The current unit case that is yet to be tested
*/
void tril_xtest_run(UTestRunner *runner, void (*test)())
{
    if (!test)
    {
        return;
    } // end if

    if (TRIL_XTEST_FLAG_OUTPUT != 1)
    {
        printf("Begin test case: %.2i\n", runner->_total + 1);
    } // end if

    //
    // setup some extra stuff before test, we then
    // run the current case in question and when
    // were done we teardown the extra stuff.
    if (runner || TRIL_XTEST_FLAG_SKIP != 1)
    {
        if (runner->_setup != NULL)
        {
            runner->_setup();
        } // end if

        test();

        if (runner->_teardown != NULL)
        {
            runner->_teardown();
        } // end if

    } // end if

    //
    // keep a score of test results add a pass if we
    // passed the logic test else we add a fail.
    if (TRIL_XTEST_FLAG_SKIP == 1)
    {
        runner->_skip++;
    }
    else if (TRIL_XTEST_FLAG_RESULT == 1)
    {
        runner->_fail++;
    }
    else
    {
        runner->_pass++;
        TRIL_XTEST_FLAG_RESULT = 0;
    } // end switch

    //
    // end of test output control
    if (TRIL_XTEST_FLAG_OUTPUT != 1)
    {
        puts("done...\n");
    } // end if

    runner->_total++;
} // end of func
