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
int main(int argc, char **argv)
{
    //
    // The command-line refreance for the Xtest runner
    //
    // --help,-h    : Output a handy usage message
    // --only-tests : Only run unit test cases
    // --only-bench : Only run benchmark tests
    //
    XUnitRunner runner = xtest_start(argc, argv);

    xfixture_basic_cases(&runner);

    return xtest_end(&runner);
} // end of function main
