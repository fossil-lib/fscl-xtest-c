/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xtest.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// put here for the benchmark test
//
// Should add the values from the vector to
// the summary and return the value of sum.
//
// arg-list:
//  -> ar: the array being passed in
//  -> ar_count: length of the array
//
long aVeryBigSum(int count, long* ar)
{
    long sum = 0L;
    for (int iter = 0; iter < count; iter++)
    {
        sum += *(ar + iter);
    } // end if
    return sum;
} // end of func


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
    const bool trueValue = true, falseValue = false;

    //
    // here we run the asserts
    tril_xtest_assert(trueValue == true, "should assert to true");
    tril_xtest_assert(falseValue == false, "should assert to false");
} // end of test case

static void test_02_assertInts()
{
    //
    // we setup are test data here.
    const int first = 50, second = 20;

    //
    // here we run the asserts
    tril_xtest_assert(first != second, "first and second should assert not equal");
    tril_xtest_assert(first == tril_xmock_stub_integer(50), "first is 50 should assert equal");
} // end of test case

static void test_03_assertStrings()
{
    //
    // we setup are test data here.
    const char *first = "Something", *second = "Something else";

    //
    // here we run the asserts
    tril_xtest_assert(strcmp(first, "Something") == 0, "first word is not equal to second word");
    tril_xtest_assert(!(strcmp(first, second) == 0), "first word is equal to second word");
    tril_xtest_assert(strlen(first) == 9, "first word should be 9 chars in length");
    tril_xtest_assert(strlen(second) != 9, "second word should not be 9 chars in length");
    tril_xtest_assert(strcmp(first, second) < 0, "first word is less than second word");
    tril_xtest_assert(strcmp(second, first) > 0, "second word is more than first word");
} // end of test case

static void test_04_assertPointer()
{
    //
    // we setup are test data here.
    const void *something = "40", *other = NULL;

    //
    // here we run the asserts
    tril_xtest_assert(something != tril_xmock_stub_nullptr(), "should assert to a non null value");
    tril_xtest_assert(other == tril_xmock_stub_nullptr(), "should assert to null value");
} // end of test case

static void test_05_expectBools()
{
    //
    // we setup are test data here.
    const bool trueValue = true, falseValue = false;

    //
    // here we run the asserts
    tril_xtest_expect(trueValue == true, "should assert to true");
    tril_xtest_expect(falseValue == false, "should assert to false");
} // end of test case

static void test_06_expectInts()
{
    //
    // we setup are test data here.
    const int first = 50, second = 20;

    //
    // here we run the asserts
    tril_xtest_expect(first != second, "first and second should assert not equal");
    tril_xtest_expect(first == tril_xmock_stub_integer(50), "first is 50 should assert equal");
} // end of test case

static void test_07_expectStrings()
{
    //
    // we setup are test data here.
    const char *first = "Something", *second = "Something else";

    //
    // here we run the asserts
    tril_xtest_expect(strcmp(first, "Something") == 0, "first word is not equal to second word");
    tril_xtest_expect(!(strcmp(first, second) == 0), "first word is equal to second word");
    tril_xtest_expect(strlen(first) == 9, "first word should be 9 chars in length");
    tril_xtest_expect(strlen(second) != 9, "second word should not be 9 chars in length");
    tril_xtest_expect(strcmp(first, second) < 0, "first word is less than second word");
    tril_xtest_expect(strcmp(second, first) > 0, "second word is more than first word");
} // end of test case

static void test_08_expectPointer()
{
    //
    // we setup are test data here.
    const void *something = "40", *other = NULL;

    //
    // here we run the asserts
    tril_xtest_expect(something != tril_xmock_stub_nullptr(), "should assert to a non null value");
    tril_xtest_expect(other == tril_xmock_stub_nullptr(), "should assert to null value");
} // end of test case


static void test_09_runAssert()
{
    //
    // here we run the asserts
    tril_xtest_assert(true, "this simple assert should run");
} // end of test case


static void test_10_benchmark()
{
    long array[5] = {1000000001, 1000000002, 1000000003, 1000000004, 1000000005};
    //
    // here we run the asserts
    tril_xbench_start();
    aVeryBigSum(5, array);
    tril_xbench_end();
} // end of test case


static void test_11_skipTest()
{
    //
    // here we run the asserts
    tril_xtest_assert(true, "this simple assert should run");
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
    UTestRunner *runner = tril_xtest_create_runner(setup, teardown);

    //
    // list of test cases being ran in this
    // project.
    tril_xtest_run(runner, test_01_assertBools);
    tril_xtest_run(runner, test_02_assertInts);
    tril_xtest_run(runner, test_03_assertStrings);
    tril_xtest_run(runner, test_04_assertPointer);
    tril_xtest_run(runner, test_05_expectBools);
    tril_xtest_run(runner, test_06_expectInts);
    tril_xtest_run(runner, test_07_expectStrings);
    tril_xtest_run(runner, test_08_expectPointer);
    tril_xtest_run(runner, test_09_runAssert);
    tril_xtest_run(runner, test_10_benchmark);
    tril_xtest_flag_skip(1);
    tril_xtest_run(runner, test_11_skipTest);
    tril_xtest_flag_skip(0);

    return tril_xtest_end_runner(runner);
} // end of function main
