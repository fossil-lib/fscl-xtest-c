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

/*
  overview:
  > Should output the a greeting message
  > to the user.
  >
  args:
  -> ...: N/A
*/
UTestRunner *tril_xtest_create_runner(void)
{
    UTestRunner *runner = malloc(sizeof(UTestRunner));
    if (!runner)
    {
        return NULL;
    } // end if

    //
    // score values
    runner->_total = 0;
    runner->_error = 0;
    runner->_skip = 0;
    runner->_pass = 0;
    runner->_fail = 0;

    runner->_setup = NULL;
    runner->_teardown = NULL;

    return runner;
} // end of func


int tril_xtest_end_runner(UTestRunner *runner)
{
    puts("XTest results:");
    printf("Total: %.2i\n", runner->_total);
    printf("Pass: %.2i\n", runner->_pass);
    printf("Fail: %.2i\n", runner->_fail);
    printf("Error: %.2i\n", runner->_error);
    printf("Skip: %.2i\n", runner->_skip);

    int result = runner->_fail;
    if (runner)
    {
        free(runner);
    } // end if

    return result;
} // end of func

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


void tril_xtest_run(UTestRunner *runner, void (*test)())
{
    if (!test)
    {
        return;
    } // end if

    //
    // setup some extra stuff before test, we then
    // run the current case in question and when
    // were done we teardown the extra stuff.
    if (runner)
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
    switch (TRIL_XTEST_FLAG_RESULT)
    {
    case 3:
        runner->_skip++;
        break;
    case 2:
        runner->_error++;
        break;
    case 1:
        runner->_fail++;
        break;    
    default:
        runner->_pass++;
        TRIL_XTEST_FLAG_RESULT = 0;
        break;
    } // end switch

    runner->_total++;
} // end of func

