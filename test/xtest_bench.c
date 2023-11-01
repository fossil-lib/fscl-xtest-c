/*  ----------------------------------------------------------------------------
    File: xtest_bench.c

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
#include <trilobite/xassert.h> // assert functions

/**
    @brief This is an example function for the benchmark cases

    @param array An array of integers
    @param size The size of the array

    @return Void
*/
void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {

        for (size_t j = 0; j < size - i - 1; ++j) {

            if (*(array + j) > *(array + j + 1)) {
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            } // end if

        } // end for

    } // end for

} // end of func

//
// XUNIT-TEST:
//
XTEST_BENCH(comput_bubble_sort_small_dataset) {
    // Example data
    int data[] = {5, 2, 8, 12, 3};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_BENCH(comput_bubble_sort_large_dataset) {
    // Example data
    int data[] = {100, 75, 43, 28, 56, 89, 34, 12};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_BENCH(comput_bubble_sort_medium_dataset) {
    // Example data
    int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_BENCH(comput_bubble_sort_empty_dataset) {
    // Edge case: Empty dataset
    int data[] = {};
    size_t size = 0;

    bubble_sort(data, size);

    // Nothing to assert for an empty dataset
} // end benchmark

XTEST_BENCH(comput_bubble_sort_sorted_dataset) {
    // Edge case: Already sorted dataset
    int data[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_BENCH(comput_bubble_sort_reverse_sorted_dataset) {
    // Edge case: Reverse sorted dataset
    int data[] = {5, 4, 3, 2, 1};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark


//
// XUNIT-GROUP:
//
void xbenchs_test_group(XUnitRunner *runner) {
    XTEST_RUN_UNIT(comput_bubble_sort_small_dataset, runner);
    XTEST_RUN_UNIT(comput_bubble_sort_medium_dataset, runner);
    XTEST_RUN_UNIT(comput_bubble_sort_large_dataset, runner);
    XTEST_RUN_UNIT(comput_bubble_sort_empty_dataset, runner);
    XTEST_RUN_UNIT(comput_bubble_sort_sorted_dataset, runner);
    XTEST_RUN_UNIT(comput_bubble_sort_reverse_sorted_dataset, runner);
} // end of group
