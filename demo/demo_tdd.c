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
    XASSERT_INT_EQUAL(x, 42);                // Should pass
    XASSERT_INT_EQUAL(y, 20);                // Should pass
    XASSERT_INT_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT_LESS(y, x);                 // Should pass
    XASSERT_INT_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int8) {
    int8_t x = 42;
    int8_t y = 20;

    // Test cases
    XASSERT_INT8_EQUAL(x, 42);                // Should pass
    XASSERT_INT8_EQUAL(y, 20);                // Should pass
    XASSERT_INT8_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT8_LESS(y, x);                 // Should pass
    XASSERT_INT8_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT8_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int16) {
    int16_t x = 42;
    int16_t y = 20;

    // Test cases
    XASSERT_INT16_EQUAL(x, 42);                // Should pass
    XASSERT_INT16_EQUAL(y, 20);                // Should pass
    XASSERT_INT16_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT16_LESS(y, x);                 // Should pass
    XASSERT_INT16_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT16_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int32) {
    int32_t x = 42;
    int32_t y = 20;

    // Test cases
    XASSERT_INT32_EQUAL(x, 42);                // Should pass
    XASSERT_INT32_EQUAL(y, 20);                // Should pass
    XASSERT_INT32_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT32_LESS(y, x);                 // Should pass
    XASSERT_INT32_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT32_GREATER(x, y);              // Should pass
} // end case

XTEST_CASE(xassert_run_of_int64) {
    int64_t x = 42;
    int64_t y = 20;

    // Test cases
    XASSERT_INT64_EQUAL(x, 42);                // Should pass
    XASSERT_INT64_EQUAL(y, 20);                // Should pass
    XASSERT_INT64_NOT_EQUAL(x, y);            // Should pass
    XASSERT_INT64_LESS(y, x);                 // Should pass
    XASSERT_INT64_LESS_EQUAL(y, x);           // Should pass
    XASSERT_INT64_GREATER(x, y);              // Should pass
} // end case

//
// XUNIT-GROUP:
//
void group_tdd_test(XUnitRunner *runner) {
    XTEST_RUN_UNIT(xassert_run_of_int,   runner);
    XTEST_RUN_UNIT(xassert_run_of_int8,  runner);
    XTEST_RUN_UNIT(xassert_run_of_int16, runner);
    XTEST_RUN_UNIT(xassert_run_of_int32, runner);
    XTEST_RUN_UNIT(xassert_run_of_int64, runner);
} // end of group

//
// XUNIT-RUNNER:
//
int main(int argc, char **argv) {
    XUnitRunner runner = XTEST_RUNNER_START(argc, argv);

    group_tdd_test(&runner);

    return XTEST_RUNNER_END(runner);
} // end of func
