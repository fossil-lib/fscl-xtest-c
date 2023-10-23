/*  ----------------------------------------------------------------------------
    File: xtest_stack.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

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
#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts
#include <trilobite/xmock.h>   // adds mocks

XMockStack *stack;

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmock_stack_test_fixture);
XTEST_SETUP(xmock_stack_test_fixture) {
    stack = xmock_stack_create(100);
} // end setup

XTEST_TEARDOWN(xmock_stack_test_fixture) {
    xmock_stack_destroy(stack);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmock_stack_test_fixture, mock_stack_push) {
    xmock_stack_push(stack, 22);
    xmock_stack_push(stack, 23);
    xmock_stack_push(stack, 11);

    XASSERT_INT_EQUAL(xmock_stack_size(stack), 3);
}

XTEST_CASE_FIXTURE(xmock_stack_test_fixture, mock_stack_pop) {
    xmock_stack_push(stack, 22);
    xmock_stack_push(stack, 23);
    xmock_stack_push(stack, 11);

    XASSERT_INT_EQUAL(xmock_stack_size(stack), 3);

    xmock_stack_pop(stack);
    XASSERT_INT_EQUAL(xmock_stack_size(stack), 2);
}

//
// XUNIT-GROUP:
//
void group_mockup_stack(XUnitRunner *runner) {
    XTEST_RUN_FIXTURE(mock_stack_push,      xmock_stack_test_fixture, runner);
    XTEST_RUN_FIXTURE(mock_stack_pop,       xmock_stack_test_fixture, runner);
} // end group
