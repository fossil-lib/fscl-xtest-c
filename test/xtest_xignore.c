/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xtest.h"

//
// TEST FIXTURE
//
XTEST_FIXTURE(xignore_test_fixture);

XTEST_SETUP(xignore_test_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xignore_test_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xignore_test_fixture, xignore_run_of_string) {
    // empty
    XTEST_IGNORE("Just some reason to skip 1");
} // end case

XTEST_CASE_FIXTURE(xignore_test_fixture, xignore_run_of_pointer) {
    // empty
    XTEST_IGNORE("Just some reason to skip 2");
} // end case

XTEST_CASE_FIXTURE(xignore_test_fixture, xignore_run_of_boolean) {
    // empty
    XTEST_IGNORE("Just some reason to skip 3");
} // end case

// TODO add xignore case for OS ignore case

//
// LOCAL TEST GROUP
//
void xignore_test_group(XUnitRunner *runner) {
    //XTEST_IGNORE("Just some reason to skip 1");
    xtest_run_test_fixture(&xignore_run_of_string,  &xignore_test_fixture, &runner->stats);
    //XTEST_IGNORE("Just some reason to skip 2");
    xtest_run_test_fixture(&xignore_run_of_pointer, &xignore_test_fixture, &runner->stats);
    //XTEST_IGNORE("Just some reason to skip 3");
    xtest_run_test_fixture(&xignore_run_of_boolean, &xignore_test_fixture, &runner->stats);
} // end of group
