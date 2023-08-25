/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

// Original functions
int add(int a, int b) {
    return a + b;
} // end of func

double compute(int a, float b, char *str) {
    return a * b + (double)strlen(str);
} // end of func

int multiply(int a, int b) {
    return a * b;
} // end of func


XTEST_CASE(mock_add_func) {
    // Creating a mock function stub for the 'add' function
    XMockStub *addStub = xmock_stub_create((void *(*)(void *))add, (void *)42, sizeof(int));

    // Using the mock function stub
    int result = add(5, 7);
    int mockResult = *(int *)xmock_stub_call(addStub, &result);

    printf("Result of real add function: %d\n", result);
    printf("Result of mock add function: %d\n", mockResult);

    xmock_stub_erase(addStub);
}  // end of case


XTEST_CASE(mock_comput_func) {
    // Creating a mock function stub for the 'compute' function
    XMockStub *computeStub = xmock_stub_create((void *(*)(void *))compute, (void *)99.99, sizeof(double));

    // Using the mock function stub with different argument types
    int a = 5;
    float b = 3.14;
    char str[] = "Hello";
    double result = compute(a, b, str);
    double mockResult = *(double *)xmock_stub_call(computeStub, &result);

    printf("Result of real compute function: %.2f\n", result);
    printf("Result of mock compute function: %.2f\n", mockResult);

    xmock_stub_erase(computeStub);
} // end of case

XTEST_CASE(mock_mult_func) {
    // Creating a mock function stub for the 'multiply' function
    XMockStub *multiplyStub = xmock_stub_create((void *(*)(void *))multiply, (void *)999, sizeof(int));

    // Using the mock function stub with non-matching arguments
    int a = 5;
    int b = 7;
    int result = multiply(a, b);
    int mockResult = *(int *)xmock_stub_call(multiplyStub, &result);

    printf("Result of real multiply function: %d\n", result);
    printf("Result of mock multiply function: %d\n", mockResult); // Will print "0" (fallback)

    xmock_stub_erase(multiplyStub);
} // end of case

//
// XTEST FIXTURE
//
void xtest_fixture_mocking_cases(XUnitRunner *runner)
{
    xtest_run(&mock_add_func, runner);
    xtest_run(&mock_comput_func ,runner);
    xtest_run(&mock_mult_func ,runner);
} // end of fixture
