/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"


/*
 >
 > here main is used as the test runner
 >
*/
int main(void)
{
    //
    // setup and teardown can be set to nullptr.
    XTestRunner *runner = tril_xtest_create_runner(NULL, NULL);

    xtest_fixture_basic_cases(runner);

    return tril_xtest_end_runner(runner);
} // end of function main
