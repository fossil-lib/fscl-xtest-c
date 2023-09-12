/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

//
// MOCK FUNCTIONS
//
XMOCK_FUNC(xmock_float, bar) {
    return arg * 1.5f;
}

XMOCK_FUNC(xmock_string, baz) {
    return arg;
}

XMOCK_FUNC(xmock_int, foo) {
    return arg * 2;
}

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_test_fixture);

XTEST_SETUP(xmockup_test_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xmockup_test_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_test_fixture, xmock_stub_bar) {
    xmock_float result = xmock_bar(3.0f); // Result: 4.500000
    XASSERT_FLOAT_EQUAL(result, 4.6f, 4.3);
} // end of case

XTEST_CASE_FIXTURE(xmockup_test_fixture, xmock_stub_baz) {
    xmock_string result = xmock_baz("Hello, world!");
    XASSERT_STRING_EQUAL(result, "Hello, world!");
} // end of case



XTEST_CASE_FIXTURE(xmockup_test_fixture, xmock_stub_foo) {
    xmock_int result = xmock_foo(10);
    XASSERT_INT_EQUAL(result, 20);
} // end of case

//
// XTEST FIXTURE
//
void xmockup_test_group(XUnitRunner *runner)
{
    xtest_run_test_fixture(&xmock_stub_foo, &xmockup_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stub_bar, &xmockup_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stub_baz, &xmockup_test_fixture, &runner->stats);
} // end of fixture
