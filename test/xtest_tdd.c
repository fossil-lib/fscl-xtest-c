/*  ----------------------------------------------------------------------------
    File: demo.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xtest.h>
#include <trilobite/xassert.h>

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
