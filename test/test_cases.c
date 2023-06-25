/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/package.h"
#include <trilobite/xtest.h>
#include <stdbool.h>
#include <stdlib.h>


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
static void test_01_simpleAssertTrue()
{
    //
    // we setup are test data here.
    const bool trueValue = true, falseValue = false;

    //
    // here we run the asserts
    tril_utest_assert_its_true(trueValue);
    tril_utest_assert_its_false(falseValue);
} // end of test case


static void test_02_simpleAssertNull()
{
    //
    // we setup are test data here.
    void *nullPtr = NULL;
   
    //
    // here we run the asserts
    tril_utest_assert_its_nullptr(nullPtr);
} // end of test case


static void test_03_simpleAssertCompare()
{
    //
    // we setup are test data here.
    int dummy = 3;

    //
    // here we run the asserts
    tril_utest_assert_equal_int(3, dummy);
} // end of test case


static void test_04_simpleAssertCall()
{
    //
    // we setup are test data here.
    const char *dummy = "Salutations and welcome to C";

    //
    // here we run the asserts
    tril_utest_assert_equal_str(dummy, salutations());
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
    UTestRunner *runner = tril_utest_create_runner();

    tril_utest_set_setup(runner, setup);
    tril_utest_set_teardown(runner, teardown);

    //
    // list of test cases being ran in this
    // project.
    tril_utest_run(runner, test_01_simpleAssertTrue);
    tril_utest_run(runner, test_02_simpleAssertNull);
    tril_utest_run(runner, test_03_simpleAssertCompare);
    tril_utest_run(runner, test_04_simpleAssertCall);

    return tril_utest_end(runner);
} // end of function main
