/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include <stdint.h>

//
// XUNIT TEST CASES
//
XTEST_CASE(basic_run_of_int) {
    int this = 32, that = 22, other = 32;

    XASSERT_INT_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_INT_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_INT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_INT_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_INT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_INT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_int8) {
    int8_t this = 32, that = 22, other = 32;

    XASSERT_INT8_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_INT8_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_INT8_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_INT8_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_INT8_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_INT8_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_int16) {
    int16_t this = 32, that = 22, other = 32;

    XASSERT_INT16_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_INT16_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_INT16_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_INT16_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_INT16_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_INT16_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_int32) {
    int32_t this = 32, that = 22, other = 32;

    XASSERT_INT32_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_INT32_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_INT32_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_INT32_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_INT32_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_INT32_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_int64) {
    int64_t this = 32, that = 22, other = 32;

    XASSERT_INT64_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_INT64_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_INT64_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_INT64_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_INT64_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_INT64_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_uint) {
    unsigned int this = 32, that = 22, other = 32;

    XASSERT_UINT_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_UINT_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_UINT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_UINT_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_UINT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_UINT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_uint8) {
    uint8_t this = 32, that = 22, other = 32;

    XASSERT_UINT8_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_UINT8_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_UINT8_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_UINT8_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_UINT8_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_UINT8_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_uint16) {
    uint16_t this = 32, that = 22, other = 32;

    XASSERT_UINT16_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_UINT16_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_UINT16_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_UINT16_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_UINT16_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_UINT16_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_uint32) {
    uint32_t this = 32, that = 22, other = 32;

    XASSERT_UINT32_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_UINT32_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_UINT32_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_UINT32_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_UINT32_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_UINT32_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_uint64) {
    uint64_t this = 32, that = 22, other = 32;

    XASSERT_UINT64_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_UINT64_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_UINT64_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_UINT64_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_UINT64_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_UINT64_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_hex) {
    unsigned int this = 20, that = 16, other = 20;

    XASSERT_HEX_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_HEX_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_HEX_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_HEX_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_HEX_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_HEX_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_hex8) {
    unsigned char this = 32, that = 22, other = 32;

    XASSERT_HEX8_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_HEX8_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_HEX8_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_HEX8_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_HEX8_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_HEX8_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_hex16) {
    unsigned short this = 32, that = 22, other = 32;

    XASSERT_HEX16_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_HEX16_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_HEX16_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_HEX16_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_HEX16_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_HEX16_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_hex32) {
    unsigned int this = 32, that = 22, other = 32;

    XASSERT_HEX32_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_HEX32_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_HEX32_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_HEX32_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_HEX32_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_HEX32_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_hex64) {
    unsigned long long this = 32, that = 22, other = 32;

    XASSERT_HEX64_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_HEX64_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_HEX64_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_HEX64_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_HEX64_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_HEX64_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_bit) {
    unsigned int this = 100000, that = 10110, other = 100000;

    XASSERT_BIT_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_BIT_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_BIT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_BIT_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_BIT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_BIT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_oct) {
    unsigned int this = 40, that = 26, other = 40;

    XASSERT_INT_EQUAL(this, other,"'x' should be equal to 'y'");
    XASSERT_INT_GREATER(this, that,"'x' should be greater than 'y'");
    XASSERT_INT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XASSERT_INT_LESS(that, other,"'x' should be lesser than 'y'");
    XASSERT_INT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XASSERT_INT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_float) {
    float this = 40.00, that = 26.00, other = 40.00;

    XASSERT_FLOAT_EQUAL(this, other, that,"'x' should be equal to 'y'");
    XASSERT_FLOAT_GREATER(this, that, "'x' should be greater than 'y'");
    XASSERT_FLOAT_GREATER_EQUAL(this, that, "'x' should be greater or equal to 'y'");
    XASSERT_FLOAT_LESS(that, other, "'x' should be lesser than 'y'");
    XASSERT_FLOAT_LESS_EQUAL(that, this, "'x' should be lesser or equal to 'y'");
    XASSERT_FLOAT_NOT_EQUAL(this, that, 50.00, "'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_double) {
    double this = 40.00, that = 26.00, other = 40.00;

    XASSERT_FLOAT_EQUAL(this, other, that,"'x' should be equal to 'y'");
    XASSERT_FLOAT_GREATER(this, that, "'x' should be greater than 'y'");
    XASSERT_FLOAT_GREATER_EQUAL(this, that, "'x' should be greater or equal to 'y'");
    XASSERT_FLOAT_LESS(that, other, "'x' should be lesser than 'y'");
    XASSERT_FLOAT_LESS_EQUAL(that, this, "'x' should be lesser or equal to 'y'");
    XASSERT_FLOAT_NOT_EQUAL(this, that, 50.00, "'x' should not be equal to 'y'");
} // end case

XTEST_CASE(basic_run_of_string) {
    char *one = "Something", *two = "Whatever", *three = "Something";
    XASSERT_STRING_EQUAL(one, three, "one and three should have benn equal");
    XASSERT_STRING_NOT_EQUAL(one, two, "one and two should not be equal");
} // end case

XTEST_CASE(basic_run_of_pointer) {
    XASSERT_NOT_NULL("Coffee Cup", "as a coffee cup should have been a non null value");
    XASSERT_NULL(NULL, "Why didn't this cup of tea return as null?");
} // end case

XTEST_CASE(basic_run_of_boolean) {
    XASSERT_TRUE(true, "should have returned true from a true value");
    XASSERT_FALSE(false, "should have returned false from a false value");
} // end case

//
// XTEST FIXTURE
//
void xfixture_basic_cases(XUnitRunner *runner)
{
    xtest_run(&basic_run_of_int, runner);
    xtest_run(&basic_run_of_int8, runner);
    xtest_run(&basic_run_of_int16, runner);
    xtest_run(&basic_run_of_int32, runner);
    xtest_run(&basic_run_of_int64, runner);
    xtest_run(&basic_run_of_uint, runner);
    xtest_run(&basic_run_of_uint8, runner);
    xtest_run(&basic_run_of_uint16, runner);
    xtest_run(&basic_run_of_uint32, runner);
    xtest_run(&basic_run_of_uint64, runner);
    xtest_run(&basic_run_of_hex, runner);
    xtest_run(&basic_run_of_hex8, runner);
    xtest_run(&basic_run_of_hex16, runner);
    xtest_run(&basic_run_of_hex32, runner);
    xtest_run(&basic_run_of_hex64, runner);
    xtest_run(&basic_run_of_oct, runner);
    xtest_run(&basic_run_of_bit, runner);
    xtest_run(&basic_run_of_float, runner);
    xtest_run(&basic_run_of_double, runner);
    xtest_run(&basic_run_of_string, runner);
    xtest_run(&basic_run_of_pointer, runner);
    xtest_run(&basic_run_of_boolean, runner);
} // end of fixture
