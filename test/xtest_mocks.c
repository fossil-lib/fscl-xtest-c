/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

XMOCK_FUNC(float, bar) {
    return XMOCK_FUNC_RETVAL(float, arg * 1.5f);
}

XTEST_CASE(xmock_stub_bar) {
    float result = xmock_bar(3.0f);
    printf("Result: %f\n", result);
    XASSERT_FLOAT_EQUAL(result, 4.6f, 4.3, "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(char *, baz) {
    return XMOCK_FUNC_RETVAL(char *, arg);
}

XTEST_CASE(xmock_stub_baz) {
    char *result = xmock_baz("Hello, world!");
    printf("Result: %s\n", result);
    XASSERT_STRING_EQUAL(result, "Hello, world!", "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(int, foo) {
    return XMOCK_FUNC_RETVAL(int, arg * 2);
}

XTEST_CASE(xmock_stub_foo) {
    int result = xmock_foo(10);
    printf("Result: %d\n", result);
    XASSERT_INT_EQUAL(result, "Hello, world!", "'x' should be equal to 'y'");
} // end of case

XMOCK_FUNC(int, sum_array) {
    int sum = 0;
    for (int i = 0; i < arg[0]; ++i) {
        sum += arg[i + 1];
    } // end for
    return XMOCK_FUNC_RETVAL(int, sum);
}

XTEST_CASE(xmock_stub_car) {
    int args1[] = {3, 1, 2, 3};
    int args2[] = {4, 10, 20, 30, 40};

    int result1 = xmock_sum_array(args1);
    int result2 = xmock_sum_array(args2);

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
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
