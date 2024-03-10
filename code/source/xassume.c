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

// Function to build an error message based on the assertion error code.
const char* build_assertion_error_message(cdna_assert_error error) {
    switch (error) {
        case CDNA_ASSERT_SUCCESS:
            return "Assertion successful.";
        case CDNA_ASSERT_FAILURE:
            return "Assertion failed.";
        case CDNA_ASSERT_INVALID_OPERATION:
            return "Invalid assertion operation.";
        case CDNA_ASSERT_ERROR_BIT_HIGH:
            return "Bit assertion failed: Bit is not high.";
        case CDNA_ASSERT_ERROR_BIT_NOT_HIGH:
            return "Bit assertion failed: Bit is high.";
        case CDNA_ASSERT_ERROR_BIT_LOW:
            return "Bit assertion failed: Bit is not low.";
        case CDNA_ASSERT_ERROR_BIT_NOT_LOW:
            return "Bit assertion failed: Bit is low.";
        case CDNA_ASSERT_ERROR_OUT_OF_RANGE:
            return "Assertion failed: Value is out of range.";
        default:
            return "Unknown assertion error.";
    }
    return "Unknown assertion error.";
}

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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
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
    return CDNA_ASSERT_INVALID_OPERATION; // Unsupported type for comparison
}

cdna_assert_error assume(cdna_opt op, const cdna* left, const cdna* right) {
    cdna_assert_error result = CDNA_ASSERT_SUCCESS;
    switch (op) {
        case CDNA_OPT_ITS_EQUAL:
            result = compare_equal(&left->data, &right->data);

        case CDNA_OPT_NOT_EQUAL:
            result = compare_not_equal(&left->data, &right->data);

        case CDNA_OPT_ITS_LESS:
            result = compare_less(&left->data, &right->data);

        case CDNA_OPT_NOT_LESS:
            result = compare_not_less(&left->data, &right->data);

        case CDNA_OPT_ITS_LESS_OR_EQUAL:
            result = compare_less_or_equal(&left->data, &right->data);

        case CDNA_OPT_NOT_LESS_OR_EQUAL:
            result = compare_not_less_or_equal(&left->data, &right->data);

        case CDNA_OPT_ITS_MORE:
            result = compare_more(&left->data, &right->data);

        case CDNA_OPT_NOT_MORE:
            result = compare_not_more(&left->data, &right->data);

        case CDNA_OPT_ITS_MORE_OR_EQUAL:
            result = compare_more_or_equal(&left->data, &right->data);

        case CDNA_OPT_NOT_MORE_OR_EQUAL:
            result = compare_not_more_or_equal(&left->data, &right->data);

        case CDNA_OPT_ITS_BIT_HIGH:
            result = compare_bit_high(&left->data, &right->data);

        case CDNA_OPT_NOT_BIT_HIGH:
            result = compare_not_bit_high(&left->data, &right->data);

        case CDNA_OPT_ITS_BIT_LOW:
            result = compare_bit_low(&left->data, &right->data);

        case CDNA_OPT_NOT_BIT_LOW:
            result = compare_not_bit_low(&left->data, &right->data);

        default:
            result = CDNA_ASSERT_INVALID_OPERATION; // Invalid operation specified
    }
    // Print error message on failure if XTEST_PASS_SCAN flag is set
    if (result != CDNA_ASSERT_SUCCESS) {
        XTEST_PASS_SCAN = false;
        printf("Assertion failed: %s\n", build_assertion_error_message(result));
    }
    return result;
}

cdna_assert_error assume_not_cnullptr(const cdna* left) {
    return assume(CDNA_OPT_NOT_EQUAL, left, xtest_as_ptr(NULL));
}

cdna_assert_error assume_its_cnullptr(const cdna* left) {
    return assume(CDNA_OPT_ITS_EQUAL, left, xtest_as_ptr(NULL));
}

cdna_assert_error assume_not_empty(const cdna* left) {
    return assume(CDNA_OPT_NOT_EQUAL, left, xtest_as_size(0));
}

cdna_assert_error assume_its_empty(const cdna* left) {
    return assume(CDNA_OPT_ITS_EQUAL, left, xtest_as_size(0));
}

// Specific assertion functions
cdna_assert_error assume_not_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_NOT_EQUAL, left, right);
}

cdna_assert_error assume_its_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_ITS_EQUAL, left, right);
}

cdna_assert_error assume_its_less(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_ITS_LESS, left, right);
}

cdna_assert_error assume_its_more(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_ITS_MORE, left, right);
}

cdna_assert_error assume_not_less(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_NOT_LESS, left, right);
}

cdna_assert_error assume_not_more(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_NOT_MORE, left, right);
}

cdna_assert_error assume_less_or_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_ITS_LESS_OR_EQUAL, left, right);
}

cdna_assert_error assume_more_or_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_ITS_MORE_OR_EQUAL, left, right);
}

cdna_assert_error assume_bit_its_high(const cdna* value, unsigned bit_position) {
    return assume(CDNA_OPT_ITS_BIT_HIGH, value, xtest_as_uint(bit_position));
}

cdna_assert_error assume_bit_not_high(const cdna* value, unsigned bit_position) {
    return assume(CDNA_OPT_NOT_BIT_HIGH, value, xtest_as_uint(bit_position));
}

cdna_assert_error assume_bit_its_low(const cdna* value, unsigned bit_position) {
    return assume(CDNA_OPT_ITS_BIT_LOW, value, xtest_as_uint(bit_position));
}

cdna_assert_error assume_bit_not_low(const cdna* value, unsigned bit_position) {
    return assume(CDNA_OPT_NOT_BIT_LOW, value, xtest_as_uint(bit_position));
}
