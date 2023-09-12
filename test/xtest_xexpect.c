/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xtest.h"
#include "trilobite/xexpect.h"

//
// TEST FIXTURE
//
XTEST_FIXTURE(xexpect_test_fixture);

XTEST_SETUP(xexpect_test_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xexpect_test_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_int) {
    int first = 32, that = 22, other = 32;

    XEXPECT_INT_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_INT_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_INT_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_int8) {
    int8_t first = 32, that = 22, other = 32;

    XEXPECT_INT8_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_INT8_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_INT8_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT8_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT8_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT8_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_int16) {
    int16_t first = 32, that = 22, other = 32;

    XEXPECT_INT16_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_INT16_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_INT16_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT16_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT16_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT16_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_int32) {
    int32_t first = 32, that = 22, other = 32;

    XEXPECT_INT32_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_INT32_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_INT32_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT32_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT32_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT32_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_int64) {
    int64_t first = 32, that = 22, other = 32;

    XEXPECT_INT64_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_INT64_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_INT64_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT64_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT64_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT64_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_uint) {
    unsigned int first = 32, that = 22, other = 32;

    XEXPECT_UINT_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_UINT_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_UINT_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_uint8) {
    uint8_t first = 32, that = 22, other = 32;

    XEXPECT_UINT8_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_UINT8_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_UINT8_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT8_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT8_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT8_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_uint16) {
    uint16_t first = 32, that = 22, other = 32;

    XEXPECT_UINT16_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_UINT16_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_UINT16_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT16_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT16_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT16_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_uint32) {
    uint32_t first = 32, that = 22, other = 32;

    XEXPECT_UINT32_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_UINT32_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_UINT32_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT32_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT32_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT32_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_uint64) {
    uint64_t first = 32, that = 22, other = 32;

    XEXPECT_UINT64_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_UINT64_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_UINT64_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_UINT64_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_UINT64_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_UINT64_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_hex) {
    unsigned int first = 20, that = 16, other = 20;

    XEXPECT_HEX_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_HEX_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_HEX_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_hex8) {
    unsigned char first = 32, that = 22, other = 32;

    XEXPECT_HEX8_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_HEX8_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_HEX8_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX8_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX8_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX8_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_hex16) {
    unsigned short first = 32, that = 22, other = 32;

    XEXPECT_HEX16_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_HEX16_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_HEX16_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX16_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX16_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX16_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_hex32) {
    unsigned int first = 32, that = 22, other = 32;

    XEXPECT_HEX32_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_HEX32_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_HEX32_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX32_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX32_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX32_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_hex64) {
    unsigned long long first = 32, that = 22, other = 32;

    XEXPECT_HEX64_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_HEX64_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_HEX64_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_HEX64_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_HEX64_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_HEX64_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_bit) {
    unsigned int first = 100000, that = 10110, other = 100000;

    XEXPECT_BIT_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_BIT_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_BIT_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_BIT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_BIT_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_BIT_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_oct) {
    unsigned int first = 40, that = 26, other = 40;

    XEXPECT_INT_EQUAL(first, other,"'x' should be equal to 'y'");
    XEXPECT_INT_GREATER(first, that,"'x' should be greater than 'y'");
    XEXPECT_INT_GREATER_EQUAL(first, that,"'x' should be greater or equal to 'y'");
    XEXPECT_INT_LESS(that, other,"'x' should be lesser than 'y'");
    XEXPECT_INT_LESS_EQUAL(that, first,"'x' should be lesser or equal to 'y'");
    XEXPECT_INT_NOT_EQUAL(first, that,"'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_float) {
    float first = 40.00, that = 26.00, other = 40.00;

    XEXPECT_FLOAT_EQUAL(first, other, that,"'x' should be equal to 'y'");
    XEXPECT_FLOAT_GREATER(first, that, "'x' should be greater than 'y'");
    XEXPECT_FLOAT_GREATER_EQUAL(first, that, "'x' should be greater or equal to 'y'");
    XEXPECT_FLOAT_LESS(that, other, "'x' should be lesser than 'y'");
    XEXPECT_FLOAT_LESS_EQUAL(that, first, "'x' should be lesser or equal to 'y'");
    XEXPECT_FLOAT_NOT_EQUAL(first, that, 50.00, "'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_double) {
    double first = 40.00, that = 26.00, other = 40.00;

    XEXPECT_FLOAT_EQUAL(first, other, that,"'x' should be equal to 'y'");
    XEXPECT_FLOAT_GREATER(first, that, "'x' should be greater than 'y'");
    XEXPECT_FLOAT_GREATER_EQUAL(first, that, "'x' should be greater or equal to 'y'");
    XEXPECT_FLOAT_LESS(that, other, "'x' should be lesser than 'y'");
    XEXPECT_FLOAT_LESS_EQUAL(that, first, "'x' should be lesser or equal to 'y'");
    XEXPECT_FLOAT_NOT_EQUAL(first, that, 50.00, "'x' should not be equal to 'y'");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_string) {
    char *one = "Something", *two = "Whatever", *three = "Something";
    XEXPECT_STRING_EQUAL(one, three, "one and three should have benn equal");
    XEXPECT_STRING_NOT_EQUAL(one, two, "one and two should not be equal");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_pointer) {
    XEXPECT_NOT_NULL("Coffee Cup", "as a coffee cup should have been a non null value");
    XEXPECT_NULL(NULL, "Why didn't first cup of tea return as null?");
} // end case

XTEST_CASE_FIXTURE(xexpect_test_fixture, xexpect_run_of_boolean) {
    XEXPECT_TRUE(true, "should have returned true from a true value");
    XEXPECT_FALSE(false, "should have returned false from a false value");
} // end case

//
// LOCAL TEST GROUP
//
void xexpect_test_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xexpect_run_of_int,    &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_int8,   &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_int16,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_int32,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_int64,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_uint,   &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_uint8,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_uint16, &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_uint32, &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_uint64, &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_hex,    &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_hex8,   &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_hex16,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_hex32,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_hex64,  &xexpect_test_fixture, &runner->stats);

    xtest_run_test_fixture(&xexpect_run_of_bit,    &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_oct,    &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_float,  &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_double, &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_string, &xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_pointer,&xexpect_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xexpect_run_of_boolean,&xexpect_test_fixture, &runner->stats);
} // end of group
