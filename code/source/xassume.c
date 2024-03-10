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

// Helper function to compare two values based on the assertion operation
static bool compare_values(cdna_opt op, const cdna* value1, const cdna* value2) {
    if (value1->type != value2->type) {
        // Type mismatch
        return false;
    }

    switch (value1->type) {
        case CDNA_INT_TYPE:
        case CDNA_INT8_TYPE:
        case CDNA_INT16_TYPE:
        case CDNA_INT32_TYPE:
        case CDNA_INT64_TYPE:
        case CDNA_UINT_TYPE:
        case CDNA_UINT8_TYPE:
        case CDNA_UINT16_TYPE:
        case CDNA_UINT32_TYPE:
        case CDNA_UINT64_TYPE:
        case CDNA_OCTAL8_TYPE:
        case CDNA_OCTAL16_TYPE:
        case CDNA_OCTAL32_TYPE:
        case CDNA_OCTAL64_TYPE:
        case CDNA_BITWISE8_TYPE:
        case CDNA_BITWISE16_TYPE:
        case CDNA_BITWISE32_TYPE:
        case CDNA_BITWISE64_TYPE:
        case CDNA_HEX8_TYPE:
        case CDNA_HEX16_TYPE:
        case CDNA_HEX32_TYPE:
        case CDNA_HEX64_TYPE:
            // Integer and bitwise types
            return (memcmp(&value1->data, &value2->data, sizeof(value1->data)) == 0);
        case CDNA_FLOAT_TYPE:
        case CDNA_DOUBLE_TYPE:
            // Floating-point types
            return (memcmp(&value1->data, &value2->data, sizeof(value1->data)) == 0);
        case CDNA_STRING_TYPE:
            // String type
            return (strcmp(value1->data.string_type, value2->data.string_type) == 0);
        case CDNA_CHAR_TYPE:
            // Character type
            return (value1->data.char_type == value2->data.char_type);
        case CDNA_BOOLEAN_TYPE:
            // Boolean type
            return (value1->data.boolean_type == value2->data.boolean_type);
        case CDNA_ARRAY_TYPE:
        case CDNA_MAP_TYPE:
            // Compare pointers for array and map types
            return (value1->data.array_type.elements == value2->data.array_type.elements &&
                    value1->data.array_type.size == value2->data.array_type.size);
        case CDNA_QBIT_TYPE:
            // 64-bit quantum bit type
            return (value1->data.qbit_type == value2->data.qbit_type);
        case CDNA_NULLPTR_TYPE:
            // Null pointer type
            return (value1->data.nullptr_type == value2->data.nullptr_type);
        // Add other cases for additional types as needed
        default:
            return false;  // Invalid data type
    }
}

// Assertion operation
cdna_assert_error assume(cdna_opt op, const cdna* value1, const cdna* value2) {
    // Check if the assertion operation is valid
    if (op < CDNA_OPT_EQUAL || op > CDNA_OPT_GREATER_THAN_OR_EQUAL) {
        return CDNA_ASSERT_INVALID_OPERATION;
    }

    // Compare the values based on the assertion operation and type check
    bool result = compare_values(op, value1, value2);

    // Return the appropriate assertion result
    return result ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
}
