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



XTEST_CASE(xexpect_run_of_int) {
    int this = 32, that = 22, other = 32;

    XEXPECT_INT_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_INT_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_INT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_int8) {
    int8_t this = 32, that = 22, other = 32;

    XEXPECT_INT8_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_INT8_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_INT8_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT8_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT8_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT8_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_int16) {
    int16_t this = 32, that = 22, other = 32;

    XEXPECT_INT16_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_INT16_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_INT16_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT16_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT16_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT16_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_int32) {
    int32_t this = 32, that = 22, other = 32;

    XEXPECT_INT32_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_INT32_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_INT32_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT32_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT32_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT32_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_int64) {
    int64_t this = 32, that = 22, other = 32;

    XEXPECT_INT64_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_INT64_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_INT64_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT64_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT64_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT64_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_uint) {
    unsigned int this = 32, that = 22, other = 32;

    XEXPECT_UINT_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_UINT_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_UINT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_uint8) {
    uint8_t this = 32, that = 22, other = 32;

    XEXPECT_UINT8_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_UINT8_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_UINT8_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT8_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT8_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT8_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_uint16) {
    uint16_t this = 32, that = 22, other = 32;

    XEXPECT_UINT16_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_UINT16_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_UINT16_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT16_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT16_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT16_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_uint32) {
    uint32_t this = 32, that = 22, other = 32;

    XEXPECT_UINT32_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_UINT32_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_UINT32_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT32_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT32_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT32_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_uint64) {
    uint64_t this = 32, that = 22, other = 32;

    XEXPECT_UINT64_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_UINT64_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_UINT64_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT64_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT64_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT64_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_hex) {
    unsigned int this = 20, that = 16, other = 20;

    XEXPECT_HEX_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_HEX_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_HEX_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_hex8) {
    unsigned char this = 32, that = 22, other = 32;

    XEXPECT_HEX8_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_HEX8_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_HEX8_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX8_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX8_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX8_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_hex16) {
    unsigned short this = 32, that = 22, other = 32;

    XEXPECT_HEX16_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_HEX16_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_HEX16_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX16_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX16_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX16_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_hex32) {
    unsigned int this = 32, that = 22, other = 32;

    XEXPECT_HEX32_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_HEX32_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_HEX32_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX32_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX32_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX32_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_hex64) {
    unsigned long long this = 32, that = 22, other = 32;

    XEXPECT_HEX64_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_HEX64_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_HEX64_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX64_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX64_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX64_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_bit) {
    unsigned int this = 100000, that = 10110, other = 100000;

    XEXPECT_BIT_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_BIT_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_BIT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_BIT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_BIT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_BIT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_oct) {
    unsigned int this = 40, that = 26, other = 40;

    XEXPECT_INT_EQUAL(this, other,"'x' should be equal to 'y'");
    XEXPECT_INT_GREATER(this, that,"'x' should be greater than 'y'");
    XEXPECT_INT_GREATER_EQUAL(this, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT_LESS_EQUAL(that, this,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT_NOT_EQUAL(this, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_float) {
    float this = 40.00, that = 26.00, other = 40.00;

    XEXPECT_FLOAT_EQUAL(this, other, that,"'x' should be equal to 'y'");
    XEXPECT_FLOAT_GREATER(this, that, "'x' should be greater than 'y'");
    XEXPECT_FLOAT_GREATER_EQUAL(this, that, "'x' should be greater or equal to 'y'");
    XEXPECT_FLOAT_LESS(that, other, "'x' should be lesser than 'y'");
    XEXPECT_FLOAT_LESS_EQUAL(that, this, "'x' should be lesser or equal to 'y'");
    XEXPECT_FLOAT_NOT_EQUAL(this, that, 50.00, "'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_double) {
    double this = 40.00, that = 26.00, other = 40.00;

    XEXPECT_FLOAT_EQUAL(this, other, that,"'x' should be equal to 'y'");
    XEXPECT_FLOAT_GREATER(this, that, "'x' should be greater than 'y'");
    XEXPECT_FLOAT_GREATER_EQUAL(this, that, "'x' should be greater or equal to 'y'");
    XEXPECT_FLOAT_LESS(that, other, "'x' should be lesser than 'y'");
    XEXPECT_FLOAT_LESS_EQUAL(that, this, "'x' should be lesser or equal to 'y'");
    XEXPECT_FLOAT_NOT_EQUAL(this, that, 50.00, "'x' should not be equal to 'y'");
} // end case

XTEST_CASE(xexpect_run_of_string) {
    char *one = "Something", *two = "Whatever", *three = "Something";
    XEXPECT_STRING_EQUAL(one, three, "one and three should have benn equal");
    XEXPECT_STRING_NOT_EQUAL(one, two, "one and two should not be equal");
} // end case

XTEST_CASE(xexpect_run_of_pointer) {
    XEXPECT_NOT_NULL("Coffee Cup", "as a coffee cup should have been a non null value");
    XEXPECT_NULL(NULL, "Why didn't this cup of tea return as null?");
} // end case

XTEST_CASE(xexpect_run_of_boolean) {
    XEXPECT_TRUE(true, "should have returned true from a true value");
    XEXPECT_FALSE(false, "should have returned false from a false value");
} // end case

XTEST_CASE(xbdd_logic_test) {
    GIVEN("a valid statement is passed") {
        // Set up the context
        bool givenExecuted = true;

        WHEN("a statement is true") {
            // Perform the login action
            bool whenExecuted = true;
            
            THEN("we validate everything was worked") {
                // Check the expected outcome
                bool thenExecuted = true;

                XEXPECT_TRUE(givenExecuted, "should have returned true from a true given");
                XEXPECT_TRUE(whenExecuted, "should have returned true from a true when");
                XEXPECT_TRUE(thenExecuted, "should have returned true from a true then");
            }
        }
    }
} // end of case

XTEST_CASE(xbdd_user_account) {
    GIVEN("a user's account with sufficient balance") {
        // Set up the context
        float accountBalance = 500.0;
        float withdrawalAmount = 200.0;

        WHEN("the user requests a withdrawal of $200") {
            // Perform the withdrawal action
            if (accountBalance >= withdrawalAmount) {
                accountBalance -= withdrawalAmount;
            } // end if
            THEN("the withdrawal amount should be deducted from the account balance") {
                // Check the expected outcome

                // Simulate the scenario
                float compareBalance = 500.0;
                XEXPECT_FLOAT_LESS(accountBalance, compareBalance,"Insufficient funds for withdrawal");
            }
        }
    }
} // end of case

XTEST_CASE(xbdd_empty_cart) {
    GIVEN("a user with an empty shopping cart") {
        // Set up the context
        int cartItemCount = 0;

        WHEN("the user adds a product to the cart") {
            // Perform the action of adding a product

            THEN("the cart item count should increase by 1") {
                // Check the expected outcome
                cartItemCount++;

                XEXPECT_INT_EQUAL(cartItemCount, 1,"Darn it we forgot to add eggs in the cart");
            }
        }
    }
} // end of case

XTEST_CASE(xbdd_valid_login) {
    GIVEN("a registered user with valid credentials") {
        // Set up the context
        const char* validUsername = "user123";
        const char* validPassword = "pass456";

        WHEN("the user provides correct username and password") {
            // Perform the action of user login
            const char* inputUsername = "user123";
            const char* inputPassword = "pass456";

            THEN("the login should be successful") {
                // Check the expected outcome
                // Simulate login validation
                XEXPECT_STRING_EQUAL(inputUsername, validUsername, "Invalid username");
                XEXPECT_STRING_EQUAL(inputPassword, validPassword, "Invalid password");
            }
        }

        WHEN("the user provides incorrect password") {
            // Perform the action of user login
            const char* inputUsername = "user123";
            const char* inputPassword = "wrongpass";

            THEN("the login should fail with an error message") {
                // Check the expected outcome
                // Simulate login validation
                XEXPECT_STRING_EQUAL(inputUsername, validUsername, "Valid username but password should fail");
                XEXPECT_STRING_NOT_EQUAL(inputPassword, validPassword, "Invalid password but didn't block");
            }
        }
    }
} // end of case

// Define a test case for Logistic Regression training
XTEST_CASE(xauto_logistic_regression_training) {
    // Mock training data
    int num_samples = 5;
    int labels[] = {0, 0, 1, 1, 1};
    int num_features = 2; // Set the number of features

    double input[] = {
        1.0, 2.0,
        3.0, 4.0,
        5.0, 1.0,
        1.5, 2.0,
        2.5, 3.0
    };

    // Initialize the Logistic Regression model
    LogisticRegressionModel model;
    model.num_features = num_features;

    // Train the model
    train_logistic_regression(&model, input, labels, num_samples, 0.01, 1000);

    // Define assertions specific to Logistic Regression training
    // In this example, you can check if the model's coefficients and intercept match expected values.
    XASSERT(fabs(model.coefficients[0] - 0.61) < 0.01, "Coefficient 1 is not as expected");
    XASSERT(fabs(model.coefficients[1] - 0.88) < 0.01, "Coefficient 2 is not as expected");
    XASSERT(fabs(model.intercept + 3.16) < 0.01, "Intercept is not as expected");
} // end of case

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
    
    xtest_run(&xexpect_run_of_int, runner);
    xtest_run(&xexpect_run_of_int8, runner);
    xtest_run(&xexpect_run_of_int16, runner);
    xtest_run(&xexpect_run_of_int32, runner);
    xtest_run(&xexpect_run_of_int64, runner);
    xtest_run(&xexpect_run_of_uint, runner);
    xtest_run(&xexpect_run_of_uint8, runner);
    xtest_run(&xexpect_run_of_uint16, runner);
    xtest_run(&xexpect_run_of_uint32, runner);
    xtest_run(&xexpect_run_of_uint64, runner);
    xtest_run(&xexpect_run_of_hex, runner);
    xtest_run(&xexpect_run_of_hex8, runner);
    xtest_run(&xexpect_run_of_hex16, runner);
    xtest_run(&xexpect_run_of_hex32, runner);
    xtest_run(&xexpect_run_of_hex64, runner);
    xtest_run(&xexpect_run_of_oct, runner);
    xtest_run(&xexpect_run_of_bit, runner);
    xtest_run(&xexpect_run_of_float, runner);
    xtest_run(&xexpect_run_of_double, runner);
    xtest_run(&xexpect_run_of_string, runner);
    xtest_run(&xexpect_run_of_pointer, runner);
    xtest_run(&xexpect_run_of_boolean, runner);
    
    xtest_run(&xbdd_logic_test, runner);
    xtest_run(&xbdd_user_account, runner);
    xtest_run(&xbdd_empty_cart, runner);
    xtest_run(&xbdd_valid_login, runner);

    xtest_run(&xauto_logistic_regression_training, runner);
} // end of fixture
