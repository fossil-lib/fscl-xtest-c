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

    xmockup_test_group(&runner);
    xbenchs_test_group(&runner);
    unit_test_c_group( &runner);
    xignore_test_group(&runner);
    xexpect_test_group(&runner);
    xassert_test_group(&runner);
    xmockup_hardware_group(&runner);

    return xtest_end(&runner);
} // end of function main
