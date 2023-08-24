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
    TRILXASSERT(true);
} // end of case

XTEST(custom_assert_random)
{
    TRILXASSERT((2 + 2) == 4);
    TRILXASSERT("true value" != NULL);
    TRILXASSERT(true);
} // end of case

XTEST(assert_check_pointers)
{
    TRILXASSERT_ITS_NULL(NULL);
    TRILXASSERT_NOT_NULL("Some kind of value");
} // end of case

XTEST(assert_check_boolean)
{
    TRILXASSERT_ITS_TRUE(true);
    TRILXASSERT_ITS_FALSE(false);
    TRILXASSERT_ITS_TRUE(!false);
    TRILXASSERT_ITS_FALSE(!true);
} // end of case

XTEST(assert_check_int)
{
    int first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_INT_ITS_EQUAL(first, third);
    TRILXASSERT_INT_NOT_EQUAL(first, second);

    TRILXASSERT_INT_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_INT_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_INT_GREATER_THAN(first, second);
    TRILXASSERT_INT_LESSER_THAN(second, third);
    TRILXASSERT_INT_WITHIN_RANGE(first, second, third);
} // end of case

XTEST(assert_check_int8)
{
    int8_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_INT8_ITS_EQUAL(first, third);
    TRILXASSERT_INT8_NOT_EQUAL(first, second);

    TRILXASSERT_INT8_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_INT8_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_INT8_GREATER_THAN(first, second);
    TRILXASSERT_INT8_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_int16)
{
    int16_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_INT16_ITS_EQUAL(first, third);
    TRILXASSERT_INT16_NOT_EQUAL(first, second);

    TRILXASSERT_INT16_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_INT16_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_INT16_GREATER_THAN(first, second);
    TRILXASSERT_INT16_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_int32)
{
    int32_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_INT32_ITS_EQUAL(first, third);
    TRILXASSERT_INT32_NOT_EQUAL(first, second);

    TRILXASSERT_INT32_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_INT32_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_INT32_GREATER_THAN(first, second);
    TRILXASSERT_INT32_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_int64)
{
    int64_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_INT64_ITS_EQUAL(first, third);
    TRILXASSERT_INT64_NOT_EQUAL(first, second);

    TRILXASSERT_INT64_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_INT64_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_INT64_GREATER_THAN(first, second);
    TRILXASSERT_INT64_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint)
{
    unsigned int first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_UINT_ITS_EQUAL(first, third);
    TRILXASSERT_UINT_NOT_EQUAL(first, second);

    TRILXASSERT_UINT_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_UINT_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_UINT_GREATER_THAN(first, second);
    TRILXASSERT_UINT_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint8)
{
    uint8_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_UINT8_ITS_EQUAL(first, third);
    TRILXASSERT_UINT8_NOT_EQUAL(first, second);

    TRILXASSERT_UINT8_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_UINT8_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_UINT8_GREATER_THAN(first, second);
    TRILXASSERT_UINT8_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint16)
{
    uint16_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_UINT16_ITS_EQUAL(first, third);
    TRILXASSERT_UINT16_NOT_EQUAL(first, second);

    TRILXASSERT_UINT16_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_UINT16_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_UINT16_GREATER_THAN(first, second);
    TRILXASSERT_UINT16_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint32)
{
    uint32_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_UINT32_ITS_EQUAL(first, third);
    TRILXASSERT_UINT32_NOT_EQUAL(first, second);

    TRILXASSERT_UINT32_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_UINT32_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_UINT32_GREATER_THAN(first, second);
    TRILXASSERT_UINT32_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_uint64)
{
    uint64_t first = 20, second = 10, third = 20;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_UINT64_ITS_EQUAL(first, third);
    TRILXASSERT_UINT64_NOT_EQUAL(first, second);

    TRILXASSERT_UINT64_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_UINT64_LESSER_OR_EQUAL(second, first);
    TRILXASSERT_UINT64_GREATER_THAN(first, second);
    TRILXASSERT_UINT64_LESSER_THAN(second, third);
} // end of case

XTEST(assert_check_hex)
{
    unsigned int first = 0x1A3B, second = 0x1A2B, third = 0x1A3B;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_HEX_ITS_EQUAL(first, third);
    TRILXASSERT_HEX_NOT_EQUAL(first, second);
} // end of case

XTEST(assert_check_oct)
{
    unsigned int first = 0754, second = 0434, third = 0754;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_HEX_ITS_EQUAL(first, third);
    TRILXASSERT_HEX_NOT_EQUAL(first, second);
} // end of case

XTEST(assert_check_bin)
{
    unsigned int first = 0b110010, second = 0b101011, third = 0b110010;
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_HEX_ITS_EQUAL(first, third);
    TRILXASSERT_HEX_NOT_EQUAL(first, second);
} // end of case

XTEST(assert_check_str)
{
    char *one = "Something", *two = "Whatever", *three = "Something";
    //
    // checking to see if we can call this at all
    //
    TRILXASSERT_STR_ITS_EQUAL(one, three);
    TRILXASSERT_STR_NOT_EQUAL(one, two);

    TRILXASSERT_STR_GREATER_THAN(two, one);
    TRILXASSERT_STR_LESSER_THAN(three, two);
} // end of case

XTEST(assert_check_str_len)
{
    char *word = "Coffee Ice Cream";

    TRILXASSERT_STR_ITS_EQUAL_LEN(word, 16);
    TRILXASSERT_STR_NOT_EQUAL_LEN(word, 42);
} // end of case

XTEST(assert_check_char)
{
    char this = 'A', that = 'B', other = 'A';

    TRILXASSERT_CHAR_ITS_EQUAL(this, other);
    TRILXASSERT_CHAR_NOT_EQUAL(this, that);
} // end of case

XTEST(assert_check_float)
{
    float first = 20.00, second = 10.00, third = 20.00;

    TRILXASSERT_FLOAT_ITS_EQUAL(first, third);
    TRILXASSERT_FLOAT_NOT_EQUAL(first, second);
    TRILXASSERT_FLOAT_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_FLOAT_GREATER_THAN(first, second);
    TRILXASSERT_FLOAT_LESSER_OR_EQUAL(second, third);
    TRILXASSERT_FLOAT_LESSER_THAN(second, third);
    TRILXASSERT_FLOAT_WITHIN_RANGE(first, second, third);
} // end of case

XTEST(assert_check_double)
{
    double first = 20.00, second = 10.00, third = 20.00;

    TRILXASSERT_DOUBLE_ITS_EQUAL(first, third);
    TRILXASSERT_DOUBLE_NOT_EQUAL(first, second);
    TRILXASSERT_DOUBLE_GREATER_OR_EQUAL(first, second);
    TRILXASSERT_DOUBLE_GREATER_THAN(first, second);
    TRILXASSERT_DOUBLE_LESSER_OR_EQUAL(second, third);
    TRILXASSERT_DOUBLE_LESSER_THAN(second, third);
    TRILXASSERT_DOUBLE_WITHIN_RANGE(first, second, third);
} // end of case

//
// XTEST FIXTURE
//
void xfixture_basic_cases(XUnitRunner *runner)
{
    xtest_run(NULL, runner);
} // end of fixture