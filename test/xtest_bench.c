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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // assert functions

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
XTEST_MARK(comput_bubble_sort_small_dataset) {
    // Example data
    int data[] = {5, 2, 8, 12, 3};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_MARK(comput_bubble_sort_large_dataset) {
    // Example data
    int data[] = {100, 75, 43, 28, 56, 89, 34, 12};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_MARK(comput_bubble_sort_medium_dataset) {
    // Example data
    int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_MARK(comput_bubble_sort_empty_dataset) {
    // Edge case: Empty dataset
    int data[] = {};
    size_t size = 0;

    bubble_sort(data, size);

    // Nothing to assert for an empty dataset
} // end benchmark

XTEST_MARK(comput_bubble_sort_sorted_dataset) {
    // Edge case: Already sorted dataset
    int data[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);

    // Add assertions to check if data is sorted in ascending order
    for (size_t i = 0; i < size - 1; i++) {
        TEST_ASSERT_MSG(data[i] <= data[i + 1], "Data is not sorted");
    }
} // end benchmark

XTEST_MARK(comput_bubble_sort_reverse_sorted_dataset) {
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
XTEST_DEFINE_POOL(xbenchs_test_group) {
    XTEST_RUN_UNIT(comput_bubble_sort_small_dataset);
    XTEST_RUN_UNIT(comput_bubble_sort_medium_dataset);
    XTEST_RUN_UNIT(comput_bubble_sort_large_dataset);
    XTEST_RUN_UNIT(comput_bubble_sort_empty_dataset);
    XTEST_RUN_UNIT(comput_bubble_sort_sorted_dataset);
    XTEST_RUN_UNIT(comput_bubble_sort_reverse_sorted_dataset);
} // end of group
