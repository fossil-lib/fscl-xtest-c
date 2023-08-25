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
    XUnitRunner runner = xtest_start(argc, argv);

    xfixture_basic_cases(&runner);
    xfixture_bench_cases(&runner);

    return xtest_end(&runner);
} // end of function main
