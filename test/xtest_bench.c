/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"

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
// XBENCHMARK CASES
//
XTEST_BENCH(comput_bubble_sort_small_dataset) {
    // Example data
    int data[] = {5, 2, 8, 12, 3};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);
} // end benchmark

XTEST_BENCH(comput_bubble_sort_large_dataset) {
    // Example data
    int data[] = {100, 75, 43, 28, 56, 89, 34, 12};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);
} // end benchmark

XTEST_BENCH(comput_bubble_sort_medium_dataset) {
    // Example data
    int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t size = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, size);
} // end benchmark

//
// XTEST FIXTURE
//
void xfixture_bench_cases(XUnitRunner *runner)
{
    xtest_run_test_unit(&comput_bubble_sort_small_dataset, runner->stats);
    xtest_run_test_unit(&comput_bubble_sort_medium_dataset, runner->stats);
    xtest_run_test_unit(&comput_bubble_sort_large_dataset, runner->stats);

} // end of fixture
