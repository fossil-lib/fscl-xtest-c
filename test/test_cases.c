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
    TRIL_XASSERT(trueValue == true);
    TRIL_XASSERT(falseValue == false);
} // end of test case

static void test_02_assertInts()
{
    //
    // we setup are test data here.
    const int first = 50, second = 20;

    //
    // here we run the asserts
    TRIL_XASSERT(first != second);
    TRIL_XASSERT(first == tril_xmock_stub_integer(50));
} // end of test case

static void test_03_assertStrings()
{
    //
    // we setup are test data here.
    const char *first = "Something", *second = "Something else";

    //
    // here we run the asserts
    TRIL_XASSERT(strcmp(first, "Something") == 0);
    TRIL_XASSERT(!(strcmp(first, second) == 0));
    TRIL_XASSERT(strlen(first) == 9);
    TRIL_XASSERT(strlen(second) != 9);
    TRIL_XASSERT(strcmp(first, second) < 0);
    TRIL_XASSERT(strcmp(second, first) > 0);
} // end of test case

static void test_04_assertPointer()
{
    //
    // we setup are test data here.
    const void *something = "40", *other = NULL;

    //
    // here we run the asserts
    TRIL_XASSERT(something != tril_xmock_stub_nullptr());
    TRIL_XASSERT(other == tril_xmock_stub_nullptr());
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

    return tril_xtest_end_runner(runner);
} // end of function main
