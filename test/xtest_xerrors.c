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
    XERRORS_EXPECT_THROW(xerrors_throw("Exception", "Test"), "Exception", "Test", "Could not use the function to throw");
    XERRORS_EXPECT_THROW(XERRORS_THROW("Exception", "Test"), "Exception", "Test", "Could not use the macro to throw");
} // end case

XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_throw_with_message) {
    XERRORS_EXPECT_THROW_WITH_MESSAGE(xerrors_throw("Exception", "Test"), "Exception", "Test", "Custom message throw failed from function");
    XERRORS_EXPECT_THROW_WITH_MESSAGE(XERRORS_THROW("Exception", "Test"), "Exception", "Test", "Custom message throw failed from macro");
} // end case

XTEST_CASE_FIXTURE(xerrors_test_fixture, xerrors_custom_error) {
    XERRORS_EXPECT_CUSTOM_ERROR(xerrors_throw("CustomError", "Test"), "CustomError", "Test", "Test custom error with function");
    XERRORS_EXPECT_CUSTOM_ERROR(XERRORS_THROW("CustomError", "Test"), "CustomError", "Test", "Test custom error with macro");
} // end case

//
// LOCAL TEST GROUP
//
void xerrors_test_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xerrors_do_throw,           &xerrors_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xerrors_throw_with_message, &xerrors_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xerrors_custom_error,       &xerrors_test_fixture, &runner->stats);
} // end of group
