/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xtest.h"

//
// TEST DATA
//

//
// TEST FIXTURE
//
XTEST_FIXTURE(xignore_test_fixture) {
    //
    void setup_xignore_test_fixture() {
        // empty
    }
    void teardown_xignore_test_fixture() {
        // empty
    }
}

//
// TEST CASES
//


//
// LOCAL TEST GROUP
//
void xignore_test_group(XUnitRunner *runner) {
    //xtest_run_test_fixture(xassert_run_of_int, xassert_test_fixture, &runner->stats);
} // end of group
