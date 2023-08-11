/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
XTEST(custom_assert_check)
{
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT(true);
} // end of case

XTEST(custom_assert_random)
{
    TRIL_XASSERT((2 + 2) == 4);
    TRIL_XASSERT("true value" != NULL);
    TRIL_XASSERT(true);
} // end of case

XTEST(assert_check_pointers)
{
    TRIL_XASSERT_ITS_NULL(NULL);
    TRIL_XASSERT_NOT_NULL("Some kind of value");
} // end of case

XTEST(assert_check_boolean)
{
    TRIL_XASSERT_ITS_TRUE(true);
    TRIL_XASSERT_ITS_FALSE(false);
    TRIL_XASSERT_ITS_TRUE(!false);
    TRIL_XASSERT_ITS_FALSE(!true);
} // end of case

XTEST(assert_check_int)
{
    int first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_INT_ITS_EQUAL(first, third);
    TRIL_XASSERT_INT_NOT_EQUAL(first, second);

    TRIL_XASSERT_INT_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_INT_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_INT_GREATER_THAN(first, second);
    TRIL_XASSERT_INT_LESSER_THAN(second, third);
    TRIL_XASSERT_INT_WITHIN_RANGE(first, second, third);
} // end of case

XTEST(assert_check_int8)
{
    int8_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_INT8_ITS_EQUAL(first, third);
    TRIL_XASSERT_INT8_NOT_EQUAL(first, second);

    TRIL_XASSERT_INT8_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_INT8_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_INT8_GREATER_THAN(first, second);
    TRIL_XASSERT_INT8_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_int16)
{
    int16_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_INT16_ITS_EQUAL(first, third);
    TRIL_XASSERT_INT16_NOT_EQUAL(first, second);

    TRIL_XASSERT_INT16_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_INT16_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_INT16_GREATER_THAN(first, second);
    TRIL_XASSERT_INT16_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_int32)
{
    int32_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_INT32_ITS_EQUAL(first, third);
    TRIL_XASSERT_INT32_NOT_EQUAL(first, second);

    TRIL_XASSERT_INT32_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_INT32_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_INT32_GREATER_THAN(first, second);
    TRIL_XASSERT_INT32_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_int64)
{
    int64_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_INT64_ITS_EQUAL(first, third);
    TRIL_XASSERT_INT64_NOT_EQUAL(first, second);

    TRIL_XASSERT_INT64_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_INT64_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_INT64_GREATER_THAN(first, second);
    TRIL_XASSERT_INT64_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint)
{
    unsigned int first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_UINT_ITS_EQUAL(first, third);
    TRIL_XASSERT_UINT_NOT_EQUAL(first, second);

    TRIL_XASSERT_UINT_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_UINT_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_UINT_GREATER_THAN(first, second);
    TRIL_XASSERT_UINT_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint8)
{
    uint8_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_UINT8_ITS_EQUAL(first, third);
    TRIL_XASSERT_UINT8_NOT_EQUAL(first, second);

    TRIL_XASSERT_UINT8_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_UINT8_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_UINT8_GREATER_THAN(first, second);
    TRIL_XASSERT_UINT8_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint16)
{
    uint16_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_UINT16_ITS_EQUAL(first, third);
    TRIL_XASSERT_UINT16_NOT_EQUAL(first, second);

    TRIL_XASSERT_UINT16_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_UINT16_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_UINT16_GREATER_THAN(first, second);
    TRIL_XASSERT_UINT16_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint32)
{
    uint32_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_UINT32_ITS_EQUAL(first, third);
    TRIL_XASSERT_UINT32_NOT_EQUAL(first, second);

    TRIL_XASSERT_UINT32_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_UINT32_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_UINT32_GREATER_THAN(first, second);
    TRIL_XASSERT_UINT32_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint64)
{
    uint64_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_UINT64_ITS_EQUAL(first, third);
    TRIL_XASSERT_UINT64_NOT_EQUAL(first, second);

    TRIL_XASSERT_UINT64_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_UINT64_LESSER_OR_EQUAL(second, first);
    TRIL_XASSERT_UINT64_GREATER_THAN(first, second);
    TRIL_XASSERT_UINT64_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_hex)
{
    unsigned int first = 0x1A3B, second = 0x1A2B, third = 0x1A3B;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_HEX_ITS_EQUAL(first, third);
    TRIL_XASSERT_HEX_NOT_EQUAL(first, second);
} // end of case

XTEST(assert_check_oct)
{
    unsigned int first = 0754, second = 0434, third = 0754;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_HEX_ITS_EQUAL(first, third);
    TRIL_XASSERT_HEX_NOT_EQUAL(first, second);
} // end of case

XTEST(assert_check_bin)
{
    unsigned int first = 0b110010, second = 0b101011, third = 0b110010;
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_HEX_ITS_EQUAL(first, third);
    TRIL_XASSERT_HEX_NOT_EQUAL(first, second);
} // end of case

XTEST(assert_check_str)
{
    char *one = "Something", *two = "Whatever", *three = "Something";
    //
    // checking to see if we can call this at all
    //
    TRIL_XASSERT_STR_ITS_EQUAL(one, three);
    TRIL_XASSERT_STR_NOT_EQUAL(one, two);

    TRIL_XASSERT_STR_GREATER_THAN(one, two);
    TRIL_XASSERT_STR_LESSER_THAN(two, three);
} // end of case

XTEST(assert_check_str_len)
{
    char *word = "Coffee Ice Cream";

    TRIL_XASSERT_STR_ITS_EQUAL_LEN(word, 18);
    TRIL_XASSERT_STR_NOT_EQUAL_LEN(word, 42);
} // end of case

XTEST(assert_check_char)
{
    char this = 'A', that = 'B', other = 'A';

    TRIL_XASSERT_CHAR_ITS_EQUAL(this, other);
    TRIL_XASSERT_CHAR_NOT_EQUAL(this, that);
} // end of case

XTEST(assert_check_float)
{
    float first = 20.00, second = 10.00, third = 20.00;

    TRIL_XASSERT_FLOAT_ITS_EQUAL(first, third);
    TRIL_XASSERT_FLOAT_NOT_EQUAL(first, second);
    TRIL_XASSERT_FLOAT_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_FLOAT_GREATER_THAN(first, second);
    TRIL_XASSERT_FLOAT_LESSER_OR_EQUAL(second, third);
    TRIL_XASSERT_FLOAT_LESSER_THAN(second, third);
    TRIL_XASSERT_FLOAT_WITHIN_RANGE(first, second, third);
} // end of case

XTEST(assert_check_double)
{
    double first = 20.00, second = 10.00, third = 20.00;

    TRIL_XASSERT_DOUBLE_ITS_EQUAL(first, third);
    TRIL_XASSERT_DOUBLE_NOT_EQUAL(first, second);
    TRIL_XASSERT_DOUBLE_GREATER_OR_EQUAL(first, second);
    TRIL_XASSERT_DOUBLE_GREATER_THAN(first, second);
    TRIL_XASSERT_DOUBLE_LESSER_OR_EQUAL(second, third);
    TRIL_XASSERT_DOUBLE_LESSER_THAN(second, third);
    TRIL_XASSERT_DOUBLE_WITHIN_RANGE(first, second, third);
} // end of case

//
// XTEST FIXTURE
//
void xtest_fixture_basic_cases(XTestRunner *runner)
{
    //
    // setup and teardown methods get set here
    // before any of the listed test cases are
    // run.
    tril_xtest_setup(runner, setup);
    tril_xtest_teardown(runner, teardown);

    //
    // list of test cases for the current test fixture
    //
    tril_xtest_run(runner, xtest_custom_assert_check);
    tril_xtest_run(runner, xtest_custom_assert_random);
    tril_xtest_run(runner, xtest_assert_check_pointers);
    tril_xtest_run(runner, xtest_assert_check_boolean);
    tril_xtest_run(runner, xtest_assert_check_int);
    tril_xtest_run(runner, xtest_assert_check_int8);
    tril_xtest_run(runner, xtest_assert_check_int16);
    tril_xtest_run(runner, xtest_assert_check_int32);
    tril_xtest_run(runner, xtest_assert_check_int64);
    tril_xtest_run(runner, xtest_assert_check_uint);
    tril_xtest_run(runner, xtest_assert_check_uint8);
    tril_xtest_run(runner, xtest_assert_check_uint16);
    tril_xtest_run(runner, xtest_assert_check_uint32);
    tril_xtest_run(runner, xtest_assert_check_uint64);
    tril_xtest_run(runner, xtest_assert_check_hex);
    tril_xtest_run(runner, xtest_assert_check_oct);
    tril_xtest_run(runner, xtest_assert_check_bin);
    tril_xtest_run(runner, xtest_assert_check_str);
    tril_xtest_run(runner, xtest_assert_check_str_len);

} // end of fixture
