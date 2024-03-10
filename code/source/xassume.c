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
#include "fossil/xassume.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t XTEST_PASS_SCAN = true;

// Utility function for equality (==)
static cdna_assert_error compare_equal(const cdna_data* left_data, const cdna_data* right_data) {
    return (memcmp(left_data, right_data, sizeof(cdna_data)) == 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
}

// Utility function for inequality (!=)
static cdna_assert_error compare_not_equal(const cdna_data* left_data, const cdna_data* right_data) {
    return (memcmp(left_data, right_data, sizeof(cdna_data)) != 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
}

// Utility function for less than (<)
static cdna_assert_error compare_less(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type < right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type < right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for not less than (>=)
static cdna_assert_error compare_not_less(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type >= right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type >= right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for less than or equal to (<=)
static cdna_assert_error compare_less_or_equal(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type <= right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type <= right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for not less than or equal to (>)
static cdna_assert_error compare_not_less_or_equal(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type > right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type > right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for greater than (>)
static cdna_assert_error compare_more(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type > right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type > right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for not greater than (<=)
static cdna_assert_error compare_not_more(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type <= right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type <= right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for greater than or equal to (>=)
static cdna_assert_error compare_more_or_equal(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type >= right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type >= right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for not greater than or equal to (<)
static cdna_assert_error compare_not_more_or_equal(const cdna_data* left_data, const cdna_data* right_data) {
    switch (left_data->type) {
        case CDNA_INT_TYPE:
            return (left_data->int_type < right_data->int_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (left_data->float_type < right_data->float_type) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
    }
}

// Utility function for bit high
static cdna_assert_error compare_bit_high(const cdna_data* value_data, unsigned bit_position) {
    switch (value_data->type) {
        case CDNA_INT_TYPE:
            return ((value_data->int_type & (1u << bit_position)) != 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_UINT_TYPE:
            return ((value_data->uint_type & (1u << bit_position)) != 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for bit comparison
    }
}

// Utility function for not bit high
static cdna_assert_error compare_not_bit_high(const cdna_data* value_data, unsigned bit_position) {
    switch (value_data->type) {
        case CDNA_INT_TYPE:
            return ((value_data->int_type & (1u << bit_position)) == 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_UINT_TYPE:
            return ((value_data->uint_type & (1u << bit_position)) == 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for bit comparison
    }
}

// Utility function for bit low
static cdna_assert_error compare_bit_low(const cdna_data* value_data, unsigned bit_position) {
    switch (value_data->type) {
        case CDNA_INT_TYPE:
            return ((value_data->int_type & (1u << bit_position)) == 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_UINT_TYPE:
            return ((value_data->uint_type & (1u << bit_position)) == 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for bit comparison
    }
}

// Utility function for not bit low
static cdna_assert_error compare_not_bit_low(const cdna_data* value_data, unsigned bit_position) {
    switch (value_data->type) {
        case CDNA_INT_TYPE:
            return ((value_data->int_type & (1u << bit_position)) != 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        case CDNA_UINT_TYPE:
            return ((value_data->uint_type & (1u << bit_position)) != 0) ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for bit comparison
    }
}

// Utility function for within range
static cdna_assert_error compare_within(const cdna_data* value_data, const cdna_data* lower_bound_data, const cdna_data* upper_bound_data) {
    switch (value_data->type) {
        case CDNA_INT_TYPE:
            return (value_data->int_type >= lower_bound_data->int_type && value_data->int_type <= upper_bound_data->int_type)
                       ? CDNA_ASSERT_SUCCESS
                       : CDNA_ASSERT_FAILURE;
        case CDNA_UINT_TYPE:
            return (value_data->uint_type >= lower_bound_data->uint_type && value_data->uint_type <= upper_bound_data->uint_type)
                       ? CDNA_ASSERT_SUCCESS
                       : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (value_data->float_type >= lower_bound_data->float_type && value_data->float_type <= upper_bound_data->float_type)
                       ? CDNA_ASSERT_SUCCESS
                       : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for range comparison
    }
}

// Utility function for not within range
static cdna_assert_error compare_not_within(const cdna_data* value_data, const cdna_data* lower_bound_data, const cdna_data* upper_bound_data) {
    switch (value_data->type) {
        case CDNA_INT_TYPE:
            return (value_data->int_type < lower_bound_data->int_type || value_data->int_type > upper_bound_data->int_type)
                       ? CDNA_ASSERT_SUCCESS
                       : CDNA_ASSERT_FAILURE;
        case CDNA_UINT_TYPE:
            return (value_data->uint_type < lower_bound_data->uint_type || value_data->uint_type > upper_bound_data->uint_type)
                       ? CDNA_ASSERT_SUCCESS
                       : CDNA_ASSERT_FAILURE;
        case CDNA_FLOAT_TYPE:
            return (value_data->float_type < lower_bound_data->float_type || value_data->float_type > upper_bound_data->float_type)
                       ? CDNA_ASSERT_SUCCESS
                       : CDNA_ASSERT_FAILURE;
        // Add cases for other types as needed
        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for range comparison
    }
}

cdna_assert_error assume(cdna_opt op, const cdna* left, const cdna* right) {
    // Implementation of the assume function based on the specified operation (op)
    // Compare the data in 'left' and 'right' based on the given operation.
    // Return the appropriate assertion error code.

    switch (op) {
        case CDNA_OPT_ITS_EQUAL:
            return compare_equal(&left->data, &right->data);

        case CDNA_OPT_NOT_EQUAL:
            return compare_not_equal(&left->data, &right->data);

        case CDNA_OPT_ITS_LESS:
            return compare_less(&left->data, &right->data);

        case CDNA_OPT_NOT_LESS:
            return compare_not_less(&left->data, &right->data);

        case CDNA_OPT_ITS_LESS_OR_EQUAL:
            return compare_less_or_equal(&left->data, &right->data);

        case CDNA_OPT_NOT_LESS_OR_EQUAL:
            return compare_not_less_or_equal(&left->data, &right->data);

        case CDNA_OPT_ITS_MORE:
            return compare_more(&left->data, &right->data);

        case CDNA_OPT_NOT_MORE:
            return compare_not_more(&left->data, &right->data);

        case CDNA_OPT_ITS_MORE_OR_EQUAL:
            return compare_more_or_equal(&left->data, &right->data);

        case CDNA_OPT_NOT_MORE_OR_EQUAL:
            return compare_not_more_or_equal(&left->data, &right->data);

        case CDNA_OPT_ITS_BIT_HIGH:
            return compare_bit_high(&left->data, &right->data);

        case CDNA_OPT_NOT_BIT_HIGH:
            return compare_not_bit_high(&left->data, &right->data);

        case CDNA_OPT_ITS_BIT_LOW:
            return compare_bit_low(&left->data, &right->data);

        case CDNA_OPT_NOT_BIT_LOW:
            return compare_not_bit_low(&left->data, &right->data);

        default:
            return CDNA_ASSERT_INVALID_OPERATION; // Invalid operation specified
    }
}

cdna_assert_error assume_not_cnullptr(const cdna* left) {
    XTEST_PASS_SCAN = assume_not_equal(left, NULL);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_its_cnullptr(const cdna* left) {
    XTEST_PASS_SCAN = assume_its_equal(left, NULL);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_not_empty(const cdna* left) {
    XTEST_PASS_SCAN = assume_not_equal(left, NULL);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_its_empty(const cdna* left) {
    XTEST_PASS_SCAN = assume_its_equal(left, NULL);
    return XTEST_PASS_SCAN;
}

// Specific assertion functions
cdna_assert_error assume_not_equal(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_NOT_EQUAL, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_its_equal(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_EQUAL, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_its_less(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_LESS_THAN, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_its_more(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_GREATER_THAN, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_not_less(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = !assume_its_less(left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_not_more(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = !assume_its_more(left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_less_or_equal(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_LESS_THAN_OR_EQUAL, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_more_or_equal(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_GREATER_THAN_OR_EQUAL, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_bit_its_high(const cdna* value, unsigned bit_position) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_BIT_HIGH, value, xtest_as_uint(bit_position));
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_bit_not_high(const cdna* value, unsigned bit_position) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_BIT_NOT_HIGH, value, xtest_as_uint(bit_position));
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_bit_its_low(const cdna* value, unsigned bit_position) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_BIT_LOW, value, xtest_as_uint(bit_position));
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_bit_not_low(const cdna* value, unsigned bit_position) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_BIT_NOT_LOW, value, xtest_as_uint(bit_position));
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_its_within(const cdna* value, cdna lower_bound, cdna upper_bound) {
    XTEST_PASS_SCAN = (assume(CDNA_OPT_WITHIN, value, &lower_bound) != CDNA_ASSERT_SUCCESS ||
            assume(CDNA_OPT_WITHIN, value, &upper_bound) != CDNA_ASSERT_SUCCESS)
               ? CDNA_ASSERT_ERROR_OUT_OF_RANGE
               : CDNA_ASSERT_SUCCESS;
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_not_within(const cdna* value, cdna lower_bound, cdna upper_bound) {
    XTEST_PASS_SCAN = !assume_its_within(value, lower_bound, upper_bound);
    return XTEST_PASS_SCAN;
}
