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
#include <trilobite/xtest.h>
#include <trilobite/xmock.h>


//
// XMOCK-FUNCS:
//

// Example mocked functions
XMOCK_FUNC(int, get_value) {
    return 42;
} // end mock

XMOCK_FUNC(float, calculate_average, int x, int y) {
    return (float)(x + y) / 2;
} // end mock

// Define the mocked 'min' and 'max' functions
XMOCK_FUNC(int, min_int, int a, int b) {
    return (a < b) ? a : b;
} // end mock

XMOCK_FUNC(int, max_int, int a, int b) {
    return (a > b) ? a : b;
} // end mock

//
// XUNIT-TEST:
//
XTEST_CASE(xmock_func_get_value) {
    int result = xmock_get_value();
    XASSERT_INT_EQUAL(42, result);
} // end case

XTEST_CASE(xmock_func_calculate_average) {
    float result = xmock_calculate_average(10, 20);
    XASSERT_FLOAT_WITHIN(0.01f, 15.0f, result);
} // end case

XTEST_CASE(xmock_func_get_value_negative) {
    int result = xmock_get_value();
    XASSERT_INT_NOT_EQUAL(0, result);
} // end case

XTEST_CASE(xmock_func_calculate_average_large_numbers) {
    float result = xmock_calculate_average(1000, 2000);
    XASSERT_FLOAT_WITHIN(0.01f, 1500.0f, result);
} // end case

XTEST_CASE(xmock_func_min_int) {
    int result = xmock_min_int(5, 10);
    XASSERT_INT_EQUAL(5, result); // Expected minimum is 5

    result = xmock_min_int(10, 5);
    XASSERT_INT_EQUAL(5, result); // Expected minimum is 5
} // end case

XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_max_int) {
    int result = xmock_max_int(5, 10);
    XASSERT_INT_EQUAL(10, result); // Expected maximum is 10

    result = xmock_max_int(10, 5);
    XASSERT_INT_EQUAL(10, result); // Expected maximum is 10
} // end case

//
// XUNIT-GROUP:
//
void group_mock_test(XUnitRunner *runner) {
    XTEST_RUN_UNIT(xmock_func_calculate_average,               runner);
    XTEST_RUN_UNIT(xmock_func_calculate_average_large_numbers, runner);
    XTEST_RUN_UNIT(xmock_func_get_value,                       runner);
    XTEST_RUN_UNIT(xmock_func_get_value_negative,              runner);
    XTEST_RUN_UNIT(xmock_func_min_int,                         runner);
    XTEST_RUN_UNIT(xmock_func_max_int,                         runner);
} // end of group

//
// XUNIT-RUNNER:
//
int main(int argc, char **argv) {
    XUnitRunner runner = XTEST_RUNNER_START(argc, argv);

    group_mock_test(&runner);

    return XTEST_RUNNER_END(runner);
} // end of func
