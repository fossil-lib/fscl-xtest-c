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

// Helper function to get string representation of cdna_type
const char* cdna_type_to_string(cdna_type type) {
    switch (type) {
        case CDNA_INT_TYPE:       return "int";
        case CDNA_INT8_TYPE:      return "int8";
        case CDNA_INT16_TYPE:     return "int16";
        case CDNA_INT32_TYPE:     return "int32";
        case CDNA_INT64_TYPE:     return "int64";
        case CDNA_UINT_TYPE:      return "uint";
        case CDNA_UINT8_TYPE:     return "uint8";
        case CDNA_UINT16_TYPE:    return "uint16";
        case CDNA_UINT32_TYPE:    return "uint32";
        case CDNA_UINT64_TYPE:    return "uint64";
        case CDNA_OCTAL8_TYPE:    return "octal8";
        case CDNA_OCTAL16_TYPE:   return "octal16";
        case CDNA_OCTAL32_TYPE:   return "octal32";
        case CDNA_OCTAL64_TYPE:   return "octal64";
        case CDNA_BITWISE8_TYPE:  return "bitwise8";
        case CDNA_BITWISE16_TYPE: return "bitwise16";
        case CDNA_BITWISE32_TYPE: return "bitwise32";
        case CDNA_BITWISE64_TYPE: return "bitwise64";
        case CDNA_HEX8_TYPE:      return "hex8";
        case CDNA_HEX16_TYPE:     return "hex16";
        case CDNA_HEX32_TYPE:     return "hex32";
        case CDNA_HEX64_TYPE:     return "hex64";
        case CDNA_FLOAT_TYPE:     return "float";
        case CDNA_DOUBLE_TYPE:    return "double";
        case CDNA_STRING_TYPE:    return "string";
        case CDNA_CHAR_TYPE:      return "char";
        case CDNA_BOOLEAN_TYPE:   return "boolean";
        case CDNA_ARRAY_TYPE:     return "array";
        case CDNA_MAP_TYPE:       return "map";
        case CDNA_QBIT_TYPE:      return "qbit";
        case CDNA_NULLPTR_TYPE:   return "nullptr";
        case CDNA_INVALID_TYPE:   return "invalid";
        case CDNA_UNKNOWN_TYPE:   return "ghost";
        default: return "Unknown type";
    }
}

// Helper function to get string representation of cdna_opt
const char* cdna_opt_to_string(cdna_opt opt) {
    switch (opt) {
        case CDNA_OPT_EQUAL:                 return "==";
        case CDNA_OPT_NOT_EQUAL:             return "!=";
        case CDNA_OPT_LESS_THAN:             return "<";
        case CDNA_OPT_GREATER_THAN:          return ">";
        case CDNA_OPT_LESS_THAN_OR_EQUAL:    return "<=";
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

// Helper function to compare octal types
static bool compare_octal(cdna_opt op, uint64_t left, uint64_t right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        default: return false;
    }
}

// Helper function to compare float types
static bool compare_int(cdna_opt op, uint64_t left, uint64_t right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        case CDNA_OPT_LESS_THAN: return left < right;
        case CDNA_OPT_GREATER_THAN: return left > right;
        case CDNA_OPT_LESS_THAN_OR_EQUAL: return left <= right;
        case CDNA_OPT_GREATER_THAN_OR_EQUAL: return left >= right;
        default: return false;
    }
}

// Helper function to compare bitwise types
static bool compare_bitwise(cdna_opt op, uint64_t left, uint64_t right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        default: return false;
    }
}

// Helper function to compare hexadecimal types
static bool compare_hexadecimal(cdna_opt op, uint64_t left, uint64_t right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        default: return false;
    }
}

// Helper function to compare float types
static bool compare_float(cdna_opt op, double left, double right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        case CDNA_OPT_LESS_THAN: return left < right;
        case CDNA_OPT_GREATER_THAN: return left > right;
        case CDNA_OPT_LESS_THAN_OR_EQUAL: return left <= right;
        case CDNA_OPT_GREATER_THAN_OR_EQUAL: return left >= right;
        default: return false;
    }
}

// Helper function to compare string types
static bool compare_string(cdna_opt op, const char* left, const char* right) {
    int compare_result = strcmp(left, right);
    switch (op) {
        case CDNA_OPT_EQUAL: return compare_result == 0;
        case CDNA_OPT_NOT_EQUAL: return compare_result != 0;
        default: return false;
    }
}

// Helper function to compare char types
static bool compare_char(cdna_opt op, char left, char right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        case CDNA_OPT_LESS_THAN: return left < right;
        case CDNA_OPT_GREATER_THAN: return left > right;
        case CDNA_OPT_LESS_THAN_OR_EQUAL: return left <= right;
        case CDNA_OPT_GREATER_THAN_OR_EQUAL: return left >= right;
        default: return false;
    }
}

// Helper function to compare boolean types
static bool compare_boolean(cdna_opt op, bool left, bool right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        default: return false;
    }
}

// Helper function to compare array types
static bool compare_array(cdna_opt op, const struct cdna* left, const struct cdna* right) {
    // Implement comparison logic for array types
    // (Assuming arrays of the same type and size)
    if (left->data.array_type.size != right->data.array_type.size) {
        return false;  // Different sizes, not equal
    }

    for (size_t i = 0; i < left->data.array_type.size; ++i) {
        if (!assume(op, &left->data.array_type.elements[i], &right->data.array_type.elements[i])) {
            return false;  // Element-wise comparison failed
        }
    }

    return true;  // All elements are equal
}

// Helper function to compare map types
static bool compare_map(cdna_opt op, const struct cdna* left, const struct cdna* right) {
    // Implement comparison logic for map types
    // (Assuming maps of the same size and keys/values of the same type)
    if (left->data.map_type.size != right->data.map_type.size) {
        return false;  // Different sizes, not equal
    }

    for (size_t i = 0; i < left->data.map_type.size; ++i) {
        if (!assume(op, &left->data.map_type.key[i], &right->data.map_type.key[i]) ||
            !assume(op, &left->data.map_type.value[i], &right->data.map_type.value[i])) {
            return false;  // Key or value comparison failed
        }
    }

    return true;  // All keys and values are equal
}

// Helper function to compare qbit types
static bool compare_qbit(cdna_opt op, uint64_t left, uint64_t right) {
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        default: return false;
    }
}

// Helper function to compare nullptr types
static bool compare_nullptr(cdna_opt op, const void* left, const void* right) {
    // Null pointer comparison logic
    switch (op) {
        case CDNA_OPT_EQUAL: return left == right;
        case CDNA_OPT_NOT_EQUAL: return left != right;
        default: return false;
    }
}

// Utility function to simplify assignment assumptions and return a pointer to a static cdna variable
cdna* assign_gene(cdna_type type, cdna_data value) {
    // Declare a static cdna variable
    static cdna variable;

    // Set the type and data of the cdna variable
    variable.type = type;
    variable.data = value;

    // Return a pointer to the static cdna variable
    return &variable;
}

// Assertion operation
cdna_assert_error assume(cdna_opt op, const cdna* left, const cdna* right) {
    if (!are_types_equal(left->type, right->type)) {
        // Types are not equal, handle error
        const char* error_message = build_error_message(op, left, right);
        fprintf(stderr, "Error: %s\n", error_message);
        free((void*)error_message);  // Free allocated memory
        return CDNA_ASSERT_INVALID_OPERATION;
    }

    switch (left->type) {
        case CDNA_INT_TYPE:
            return compare_int(op, left->data.int_type, right->data.int_type);
        case CDNA_UINT_TYPE:
            return compare_int(op, left->data.uint_type, right->data.uint_type);
        case CDNA_INT8_TYPE:
            return compare_int(op, left->data.int8_type, right->data.int8_type);
        case CDNA_INT16_TYPE:
            return compare_int(op, left->data.int16_type, right->data.int16_type);
        case CDNA_INT32_TYPE:
            return compare_int(op, left->data.int32_type, right->data.int32_type);
        case CDNA_INT64_TYPE:
            return compare_int(op, left->data.int64_type, right->data.int64_type);
        case CDNA_UINT8_TYPE:
            return compare_int(op, left->data.uint8_type, right->data.uint8_type);
        case CDNA_UINT16_TYPE:
            return compare_int(op, left->data.uint16_type, right->data.uint16_type);
        case CDNA_UINT32_TYPE:
            return compare_int(op, left->data.uint32_type, right->data.uint32_type);
        case CDNA_UINT64_TYPE:
            return compare_int(op, left->data.uint64_type, right->data.uint64_type);
        case CDNA_OCTAL8_TYPE:
            return compare_octal(op, left->data.octal8_type, right->data.octal8_type);
        case CDNA_OCTAL16_TYPE:
            return compare_octal(op, left->data.octal16_type, right->data.octal16_type);
        case CDNA_OCTAL32_TYPE:
            return compare_octal(op, left->data.octal32_type, right->data.octal32_type);
        case CDNA_OCTAL64_TYPE:
            return compare_octal(op, left->data.octal64_type, right->data.octal64_type);
        case CDNA_BITWISE8_TYPE:
            return compare_bitwise(op, left->data.bitwise8_type, right->data.bitwise8_type);
        case CDNA_BITWISE16_TYPE:
            return compare_bitwise(op, left->data.bitwise16_type, right->data.bitwise16_type);
        case CDNA_BITWISE32_TYPE:
            return compare_bitwise(op, left->data.bitwise32_type, right->data.bitwise32_type);
        case CDNA_BITWISE64_TYPE:
            return compare_bitwise(op, left->data.bitwise64_type, right->data.bitwise64_type);
        case CDNA_HEX8_TYPE:
            return compare_hexadecimal(op, left->data.hex8_type, right->data.hex8_type);
        case CDNA_HEX16_TYPE:
            return compare_hexadecimal(op, left->data.hex16_type, right->data.hex16_type);
        case CDNA_HEX32_TYPE:
            return compare_hexadecimal(op, left->data.hex32_type, right->data.hex32_type);
        case CDNA_HEX64_TYPE:
            return compare_hexadecimal(op, left->data.hex64_type, right->data.hex64_type);
        case CDNA_FLOAT_TYPE:
            return compare_float(op, left->data.float_type, right->data.float_type);
        case CDNA_DOUBLE_TYPE:
            return compare_float(op, left->data.double_type, right->data.double_type);
        case CDNA_STRING_TYPE:
            return compare_string(op, left->data.string_type, right->data.string_type);
        case CDNA_CHAR_TYPE:
            return compare_char(op, left->data.char_type, right->data.char_type);
        case CDNA_BOOLEAN_TYPE:
            return compare_boolean(op, left->data.boolean_type, right->data.boolean_type);
        case CDNA_ARRAY_TYPE:
            return compare_array(op, &left->data.array_type.elements[0], &right->data.array_type.elements[0]);
        case CDNA_MAP_TYPE:
            return compare_map(op, left, right);  // Pass the maps directly
        case CDNA_QBIT_TYPE:
            return compare_qbit(op, left->data.qbit_type, right->data.qbit_type);
        case CDNA_NULLPTR_TYPE:
            return compare_nullptr(op, left->data.nullptr_type, right->data.nullptr_type);
        case CDNA_INVALID_TYPE:
        case CDNA_UNKNOWN_TYPE:
            return CDNA_ASSERT_FAILURE;  // Unsupported types
    }

    // Assertion failed
    const char* error_message = build_error_message(op, left, right);
    fprintf(stderr, "Assertion failed: %s\n", error_message);
    free((void*)error_message);  // Free allocated memory
    return CDNA_ASSERT_FAILURE;
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

cdna_assert_error assume_less_or_equal(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_LESS_THAN_OR_EQUAL, left, right);
    return XTEST_PASS_SCAN;
}

cdna_assert_error assume_more_or_equal(const cdna* left, const cdna* right) {
    XTEST_PASS_SCAN = assume(CDNA_OPT_GREATER_THAN_OR_EQUAL, left, right);
    return XTEST_PASS_SCAN;
}
