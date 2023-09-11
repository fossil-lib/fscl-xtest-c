/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xtest.h"
#include "trilobite/xerrors.h"

//
// TEST FIXTURE
//
XTEST_FIXTURE(xerrors_test_fixture);

XTEST_SETUP(xerrors_test_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xerrors_test_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_do_throw) {
    XERRORS_EXPECT_THROW(xerrors_throw("Exception", "Test"), "Exception", "Test");
    XERRORS_EXPECT_THROW(XERRORS_THROW("Exception", "Test"), "Exception", "Test");
} // end case

XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_no_throw) {
    XERRORS_EXPECT_NO_THROW(printf("No exception\n"));
} // end case

XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_throw_with_message) {
    XERRORS_EXPECT_THROW_WITH_MESSAGE(xerrors_throw("Exception", "Test"), "Exception", "Test", "Custom message");
    XERRORS_EXPECT_THROW_WITH_MESSAGE(XERRORS_THROW("Exception", "Test"), "Exception", "Test", "Custom message");
} // end case

XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_custom_error) {
    XERRORS_EXPECT_CUSTOM_ERROR(xerrors_throw("CustomError", "Test"), "CustomError", "Test");
    XERRORS_EXPECT_CUSTOM_ERROR(XERRORS_THROW("CustomError", "Test"), "CustomError", "Test");
} // end case

//
// LOCAL TEST GROUP
//
void xignore_test_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xerrors_do_throw,           &xerrors_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xerrors_no_throw,           &xerrors_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xerrors_throw_with_message, &xerrors_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xerrors_custom_error,       &xerrors_test_fixture, &runner->stats);
} // end of group
