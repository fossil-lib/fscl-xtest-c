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
    xmock_float result = xmock_bar(3.0f);
    printf("Result: %f\n", result);
    XASSERT_FLOAT_EQUAL(result, 4.6f, 4.3, "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(xmock_string, baz) {
    return arg;
}

XTEST_CASE(xmock_stub_baz) {
    xmock_string result = xmock_baz("Hello, world!");
    printf("Result: %s\n", result);
    XASSERT_STRING_EQUAL(result, "Hello, world!", "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(xmock_int, foo) {
    return arg * 2;
}

XTEST_CASE(xmock_stub_foo) {
    xmock_int result = xmock_foo(10);
    printf("Result: %d\n", result);
    XASSERT_INT_EQUAL(result, 20, "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(xmock_int, sum_args) {
    xmock_int args[] = {4, 1, 2, 3, 4}; // First element is the count
    return xmock_sum(arg, args);
}

XTEST_CASE(xmock_stub_car) {
    xmock_int result = xmock_sum_args();
    printf("Result: %d\n", result);
    XASSERT_INT_EQUAL(result, 14, "'x' should be equal to 'y'");
} // end of case

//
// XTEST FIXTURE
//
void xtest_fixture_mocking_cases(XUnitRunner *runner)
{
    xtest_run(&xmock_stub_foo, runner);
    xtest_run(&xmock_stub_bar, runner);
    xtest_run(&xmock_stub_baz, runner);
    xtest_run(&xmock_stub_car, runner);
} // end of fixture
