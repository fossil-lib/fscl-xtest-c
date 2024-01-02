/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <fossil/xtest.h>
#include <fossil/xassert.h>

//
// TEST CASES
//
XTEST_CASE(xassert_run_of_int) {
    int x = 42;
    int y = 20;

    // Test cases
    TEST_ASSERT_EQUAL_INT(x, 42);                // Should pass
    TEST_ASSERT_EQUAL_INT(y, 20);                // Should pass
    TEST_ASSERT_NOT_EQUAL_INT(x, y);            // Should pass
    TEST_ASSERT_LESS_INT(y, x);                 // Should pass
    TEST_ASSERT_LESS_EQUAL_INT(y, x);           // Should pass
    TEST_ASSERT_GREATER_INT(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int8) {
    int8_t x = 42;
    int8_t y = 20;

    // Test cases
    TEST_ASSERT_EQUAL_INT8(x, 42);                // Should pass
    TEST_ASSERT_EQUAL_INT8(y, 20);                // Should pass
    TEST_ASSERT_NOT_EQUAL_INT8(x, y);            // Should pass
    TEST_ASSERT_LESS_INT8(y, x);                 // Should pass
    TEST_ASSERT_LESS_EQUAL_INT8(y, x);           // Should pass
    TEST_ASSERT_GREATER_INT8(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int16) {
    int16_t x = 42;
    int16_t y = 20;

    // Test cases
    TEST_ASSERT_EQUAL_INT16(x, 42);                // Should pass
    TEST_ASSERT_EQUAL_INT16(y, 20);                // Should pass
    TEST_ASSERT_NOT_EQUAL_INT16(x, y);            // Should pass
    TEST_ASSERT_LESS_INT16(y, x);                 // Should pass
    TEST_ASSERT_LESS_EQUAL_INT16(y, x);           // Should pass
    TEST_ASSERT_GREATER_INT16(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int32) {
    int32_t x = 42;
    int32_t y = 20;

    // Test cases
    TEST_ASSERT_EQUAL_INT32(x, 42);                // Should pass
    TEST_ASSERT_EQUAL_INT32(y, 20);                // Should pass
    TEST_ASSERT_NOT_EQUAL_INT32(x, y);            // Should pass
    TEST_ASSERT_LESS_INT32(y, x);                 // Should pass
    TEST_ASSERT_LESS_EQUAL_INT32(y, x);           // Should pass
    TEST_ASSERT_GREATER_INT32(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int64) {
    int64_t x = 42;
    int64_t y = 20;

    // Test cases
    TEST_ASSERT_EQUAL_INT64(x, 42);                // Should pass
    TEST_ASSERT_EQUAL_INT64(y, 20);                // Should pass
    TEST_ASSERT_NOT_EQUAL_INT64(x, y);            // Should pass
    TEST_ASSERT_LESS_INT64(y, x);                 // Should pass
    TEST_ASSERT_LESS_EQUAL_INT64(y, x);           // Should pass
    TEST_ASSERT_GREATER_INT64(x, y);              // Should pass
} // end case

//
// XUNIT-GROUP:
//
XTEST_DEFINE_POOL(tdd_test_group) {
    XTEST_RUN_UNIT(xassert_run_of_int);
    XTEST_RUN_UNIT(xassert_run_of_int8);
    XTEST_RUN_UNIT(xassert_run_of_int16);
    XTEST_RUN_UNIT(xassert_run_of_int32);
    XTEST_RUN_UNIT(xassert_run_of_int64);
} // end of group
