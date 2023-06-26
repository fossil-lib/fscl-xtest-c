/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xtest.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*
 >
 >  project setup teardown functions if needed
 >
*/
void setup()
{
    // TODO.
} // end of function setUp


void teardown()
{
    // TODO.
} // end of function tearDown


/*
 >
 > list of all the test cases for this project
 >
*/
static void test_01_assertBools()
{
    //
    // we setup are test data here.
    const xmock_blooean trueValue = xmock_true, falseValue = xmock_false;

    //
    // here we run the asserts
    tril_xtest_assert(trueValue == xmock_true, "should assert to true");
    tril_xtest_assert(falseValue == xmock_false, "should assert to false");
} // end of test case

static void test_02_assertInts()
{
    //
    // we setup are test data here.
    const xmock_int16 first = 50, second = 20;

    //
    // here we run the asserts
    tril_xtest_assert(first != second, "first and second should assert not equal");
    tril_xtest_assert(first == tril_xmock_stub_medium_int(), "first is 50 should assert equal");
} // end of test case

static void test_03_assertFloats()
{
    //
    // we setup are test data here.
    const xmock_float left = 22.0f, right = 24.0f;

    //
    // here we run the asserts
    tril_xtest_assert(!(fabs(left - 22.0) <= __FLT_EPSILON__), "assert float should be 22.0");
    tril_xtest_assert(fabs(left - right) <= __FLT_EPSILON__, "assert left and right are not equal");
    tril_xtest_assert(left > right - __FLT_EPSILON__, "assert left is less than right");
    tril_xtest_assert(right < left + __FLT_EPSILON__, "assert left is more than right");
} // end of test case

static void test_04_assertDouble()
{
    //
    // we setup are test data here.
    const xmock_double left = 22.0f, right = 24.0f;

    //
    // here we run the asserts
    tril_xtest_assert(!(fabs(left - 22.0) <= __DBL_EPSILON__), "assert float should be 22.0");
    tril_xtest_assert(fabs(left - right) <= __DBL_EPSILON__, "assert left and right are not equal");
    tril_xtest_assert(left > right - __DBL_EPSILON__, "assert left is less than right");
    tril_xtest_assert(right < left + __DBL_EPSILON__, "assert left is more than right");
} // end of test case

static void test_05_assertStrings()
{
    //
    // we setup are test data here.
    const xmock_string first = "Something", second = "Some other word";

    //
    // here we run the asserts
    tril_xtest_assert(!(strcmp(first, "Something") == 0), "first word is not equal to second word");
    tril_xtest_assert(strcmp(first, second) == 0, "first word is equal to second word");
    tril_xtest_assert(strlen(first) == 9, "first word should be 9 chars in length");
    tril_xtest_assert(strlen(second) != 9, "second word should not be 9 chars in length");
    tril_xtest_assert(strcmp(first, second) < 0, "first word is less than second word");
    tril_xtest_assert(strcmp(second, first) > 0, "second word is more than first word");
} // end of test case

static void test_06_assertPointer()
{
    //
    // we setup are test data here.
    const xmock_ptr something = "40", other = NULL;

    //
    // here we run the asserts
    tril_xtest_assert(something != tril_xmock_stub_nullptr(), "should assert to a non null value");
    tril_xtest_assert(other == tril_xmock_stub_nullptr(), "should assert to null value");
} // end of test case

static void test_07_expectBools()
{
    //
    // we setup are test data here.
    const xmock_blooean trueValue = xmock_true, falseValue = xmock_false;

    //
    // here we run the asserts
    tril_xtest_expect(trueValue == xmock_true, "should assert to true");
    tril_xtest_expect(falseValue == xmock_false, "should assert to false");
} // end of test case

static void test_08_expectInts()
{
    //
    // we setup are test data here.
    const xmock_int16 first = 50, second = 20;

    //
    // here we run the asserts
    tril_xtest_expect(first != second, "first and second should assert not equal");
    tril_xtest_expect(first == tril_xmock_stub_medium_int(), "first is 50 should assert equal");
} // end of test case

static void test_09_expectFloats()
{
    //
    // we setup are test data here.
    const xmock_float left = 22.0f, right = 24.0f;

    //
    // here we run the asserts
    tril_xtest_expect(!(fabs(left - 22.0) <= __FLT_EPSILON__), "assert float should be 22.0");
    tril_xtest_expect(fabs(left - right) <= __FLT_EPSILON__, "assert left and right are not equal");
    tril_xtest_expect(left > right - __FLT_EPSILON__, "assert left is less than right");
    tril_xtest_expect(right < left + __FLT_EPSILON__, "assert left is more than right");
} // end of test case

static void test_10_expectDouble()
{
    //
    // we setup are test data here.
    const xmock_double left = 22.0f, right = 24.0f;

    //
    // here we run the asserts
    tril_xtest_expect(!(fabs(left - 22.0) <= __DBL_EPSILON__), "assert float should be 22.0");
    tril_xtest_expect(fabs(left - right) <= __DBL_EPSILON__, "assert left and right are not equal");
    tril_xtest_expect(left > right - __DBL_EPSILON__, "assert left is less than right");
    tril_xtest_expect(right < left + __DBL_EPSILON__, "assert left is more than right");
} // end of test case

static void test_11_expectStrings()
{
    //
    // we setup are test data here.
    const xmock_string first = "Something", second = "Some other word";

    //
    // here we run the asserts
    tril_xtest_expect(!(strcmp(first, "Something") == 0), "first word is not equal to second word");
    tril_xtest_expect(strcmp(first, second) == 0, "first word is equal to second word");
    tril_xtest_expect(strlen(first) == 9, "first word should be 9 chars in length");
    tril_xtest_expect(strlen(second) != 9, "second word should not be 9 chars in length");
    tril_xtest_expect(strcmp(first, second) < 0, "first word is less than second word");
    tril_xtest_expect(strcmp(second, first) > 0, "second word is more than first word");
} // end of test case

static void test_12_expectPointer()
{
    //
    // we setup are test data here.
    const xmock_ptr something = "40", other = NULL;

    //
    // here we run the asserts
    tril_xtest_expect(something != tril_xmock_stub_nullptr(), "should assert to a non null value");
    tril_xtest_expect(other == tril_xmock_stub_nullptr(), "should assert to null value");
} // end of test case


//
// function added for benchmark test
//
int simpleArraySum(int count, int* ar)
{
    int sum = 0;
    for (int iter = 0; iter < count; iter++)
    {
        sum += ar[iter];
    } // end for
    return sum;
} // end of func


static void test_13_benchArraySum()
{
    //
    // we setup are test data here.
    xmock_int32 array[] = {1, 2, 3, 4, 10, 11};
    xmock_int32 sum = 0;

    //
    // here we run the asserts
    tril_xbench_start();
    sum = simpleArraySum(6, array);
    tril_xbench_end();

    tril_xtest_assert(sum == 31, "assert of array sum should be 31");
} // end of test case



/*
 >
 > here main is used as the test runner
 >
*/
int main(void)
{
    //
    // setup and teardown can be set to nullptr.
    UTestRunner *runner = tril_xtest_create_runner();

    tril_xtest_setup(runner, setup);
    tril_xtest_teardown(runner, teardown);

    //
    // list of test cases being ran in this
    // project.
    tril_xtest_run(runner, test_01_assertBools);
    tril_xtest_run(runner, test_02_assertInts);
    tril_xtest_run(runner, test_03_assertFloats);
    tril_xtest_run(runner, test_04_assertDouble);
    tril_xtest_run(runner, test_05_assertStrings);
    tril_xtest_run(runner, test_06_assertPointer);
    tril_xtest_run(runner, test_07_expectBools);
    tril_xtest_run(runner, test_08_expectInts);
    tril_xtest_run(runner, test_09_expectFloats);
    tril_xtest_run(runner, test_10_expectDouble);
    tril_xtest_run(runner, test_11_expectStrings);
    tril_xtest_run(runner, test_12_expectPointer);
    tril_xtest_run(runner, test_13_benchArraySum);

    return tril_xtest_end_runner(runner);
} // end of function main
