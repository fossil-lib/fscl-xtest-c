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
#include <string.h>

// Helper function to get string representation of cdna_type
const char* cdna_type_to_string(cdna_type type) {
    switch (type) {
        case CDNA_INT_TYPE: return "int";
        case CDNA_INT8_TYPE: return "int8";
        case CDNA_INT16_TYPE: return "int16";
        case CDNA_INT32_TYPE: return "int32";
        case CDNA_INT64_TYPE: return "int64";
        case CDNA_UINT_TYPE: return "uint";
        case CDNA_UINT8_TYPE: return "uint8";
        case CDNA_UINT16_TYPE: return "uint16";
        case CDNA_UINT32_TYPE: return "uint32";
        case CDNA_UINT64_TYPE: return "uint64";
        case CDNA_OCTAL8_TYPE: return "octal8";
        case CDNA_OCTAL16_TYPE: return "octal16";
        case CDNA_OCTAL32_TYPE: return "octal32";
        case CDNA_OCTAL64_TYPE: return "octal64";
        case CDNA_BITWISE8_TYPE: return "bitwise8";
        case CDNA_BITWISE16_TYPE: return "bitwise16";
        case CDNA_BITWISE32_TYPE: return "bitwise32";
        case CDNA_BITWISE64_TYPE: return "bitwise64";
        case CDNA_HEX8_TYPE: return "hex8";
        case CDNA_HEX16_TYPE: return "hex16";
        case CDNA_HEX32_TYPE: return "hex32";
        case CDNA_HEX64_TYPE: return "hex64";
        case CDNA_FLOAT_TYPE: return "float";
        case CDNA_DOUBLE_TYPE: return "double";
        case CDNA_STRING_TYPE: return "string";
        case CDNA_CHAR_TYPE: return "char";
        case CDNA_BOOLEAN_TYPE: return "boolean";
        case CDNA_ARRAY_TYPE: return "array";
        case CDNA_MAP_TYPE: return "map";
        case CDNA_QBIT_TYPE: return "qbit";
        case CDNA_NULLPTR_TYPE: return "nullptr";
        case CDNA_INVALID_TYPE: return "invalid";
        case CDNA_UNKNOWN_TYPE: return "unknown";
        default: return "Unknown type";
    }
}

// Helper function to get string representation of cdna_opt
const char* cdna_opt_to_string(cdna_opt opt) {
    switch (opt) {
        case CDNA_OPT_EQUAL: return "==";
        case CDNA_OPT_NOT_EQUAL: return "!=";
        case CDNA_OPT_LESS_THAN: return "<";
        case CDNA_OPT_GREATER_THAN: return ">";
        case CDNA_OPT_LESS_THAN_OR_EQUAL: return "<=";
        case CDNA_OPT_GREATER_THAN_OR_EQUAL: return ">=";
        default: return "Invalid operation";
    }
}

// Helper function to check if types are equal
static bool are_types_equal(cdna_type type1, cdna_type type2) {
    return type1 == type2;
}

// Helper function to build error message
static const char* build_error_message(cdna_opt op, const cdna* left, const cdna* right) {
    // Example: "Assertion failed: int == float (assume_equal)"
    const char* left_type_str = cdna_type_to_string(left->type);
    const char* right_type_str = cdna_type_to_string(right->type);
    const char* op_str = cdna_opt_to_string(op);

    // Length calculation for error message
    size_t message_length = strlen("Assertion failed:  ==  (assume_)") + strlen(left_type_str) + strlen(right_type_str) + strlen(op_str);
    char* error_message = (char*)malloc(message_length + 1);

    // Construct error message
    snprintf(error_message, message_length + 1, "Assertion failed: %s %s %s (assume%s)", left_type_str, op_str, right_type_str, op_str);

    return error_message;
}

// Assertion operation
cdna_assert_error assume(cdna_opt op, const cdna* left, const cdna* right) {
    // Check if the assertion operation is valid
    if (op < CDNA_OPT_EQUAL || op > CDNA_OPT_GREATER_THAN_OR_EQUAL) {
        return CDNA_ASSERT_INVALID_OPERATION;
    }

    // Compare the values based on the assertion operation and type check
    bool result = compare_values(op, left, right);

    // Return the appropriate assertion result
    return result ? CDNA_ASSERT_SUCCESS : CDNA_ASSERT_FAILURE;
}

// Specific assertion functions
cdna_assert_error assume_not_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_NOT_EQUAL, left, right);
}

cdna_assert_error assume_its_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_EQUAL, left, right);
}

cdna_assert_error assume_its_less(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_LESS_THAN, left, right);
}

cdna_assert_error assume_its_more(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_GREATER_THAN, left, right);
}

cdna_assert_error assume_less_or_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_LESS_THAN_OR_EQUAL, left, right);
}

cdna_assert_error assume_more_or_equal(const cdna* left, const cdna* right) {
    return assume(CDNA_OPT_GREATER_THAN_OR_EQUAL, left, right);
}
