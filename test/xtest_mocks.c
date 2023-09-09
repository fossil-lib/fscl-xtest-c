/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

XMOCK_FUNC(xmock_float, bar) {
    return arg * 1.5f;
}

XTEST_CASE(xmock_stub_bar) {
    xmock_float result = xmock_bar(3.0f); // Result: 4.500000
    XASSERT_FLOAT_EQUAL(result, 4.6f, 4.3, "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(xmock_string, baz) {
    return arg;
}

XTEST_CASE(xmock_stub_baz) {
    xmock_string result = xmock_baz("Hello, world!");
    XASSERT_STRING_EQUAL(result, "Hello, world!", "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(xmock_int, foo) {
    return arg * 2;
}

XTEST_CASE(xmock_stub_foo) {
    xmock_int result = xmock_foo(10);
    XASSERT_INT_EQUAL(result, 20, "'x' should be equal to 'y'");
} // end of case

//
// XTEST FIXTURE
//
void xfixture_mocking_cases(XUnitRunner *runner)
{
    xtest_run_test_unit(&xmock_stub_foo, runner->stats);
    xtest_run_test_unit(&xmock_stub_bar, runner->stats);
    xtest_run_test_unit(&xmock_stub_baz, runner->stats);
} // end of fixture
