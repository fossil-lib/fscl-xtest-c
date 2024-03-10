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
#ifndef FSCL_XASSUME_H
#define FSCL_XASSUME_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// Enumerated error codes for assertion operations.
typedef enum {
    CDNA_ASSERT_SUCCESS = 0,       // Assertion successful.
    CDNA_ASSERT_FAILURE = -1,      // Assertion failed.
    CDNA_ASSERT_INVALID_OPERATION  // Invalid assertion operation.
} cdna_assert_error;

// Enumerated types for assertion operations.
typedef enum {
    CDNA_OPT_EQUAL,
    CDNA_OPT_NOT_EQUAL,
    CDNA_OPT_LESS_THAN,
    CDNA_OPT_LESS_THAN_OR_EQUAL,
    CDNA_OPT_GREATER_THAN,
    CDNA_OPT_GREATER_THAN_OR_EQUAL
} cdna_opt;

// Enumerated types for representing various data types.
typedef enum {
    CDNA_INT_TYPE,           // Integer type.
    CDNA_INT8_TYPE,          // 8-bit integer type.
    CDNA_INT16_TYPE,         // 16-bit integer type.
    CDNA_INT32_TYPE,         // 32-bit integer type.
    CDNA_INT64_TYPE,         // 64-bit integer type.
    CDNA_UINT_TYPE,          // Unsigned integer type.
    CDNA_UINT8_TYPE,         // 8-bit unsigned integer type.
    CDNA_UINT16_TYPE,        // 16-bit unsigned integer type.
    CDNA_UINT32_TYPE,        // 32-bit unsigned integer type.
    CDNA_UINT64_TYPE,        // 64-bit unsigned integer type.
    CDNA_OCTAL8_TYPE,        // 8-bit octal type.
    CDNA_OCTAL16_TYPE,       // 16-bit octal type.
    CDNA_OCTAL32_TYPE,       // 32-bit octal type.
    CDNA_OCTAL64_TYPE,       // 64-bit octal type.
    CDNA_BITWISE8_TYPE,      // 8-bit bitwise type.
    CDNA_BITWISE16_TYPE,     // 16-bit bitwise type.
    CDNA_BITWISE32_TYPE,     // 32-bit bitwise type.
    CDNA_BITWISE64_TYPE,     // 64-bit bitwise type.
    CDNA_HEX8_TYPE,          // 8-bit hexadecimal type.
    CDNA_HEX16_TYPE,         // 16-bit hexadecimal type.
    CDNA_HEX32_TYPE,         // 32-bit hexadecimal type.
    CDNA_HEX64_TYPE,         // 64-bit hexadecimal type.
    CDNA_FLOAT_TYPE,         // Floating-point type (float).
    CDNA_DOUBLE_TYPE,        // Floating-point type (double).
    CDNA_STRING_TYPE,        // String type.
    CDNA_CHAR_TYPE,          // Character type.
    CDNA_BOOLEAN_TYPE,       // Boolean type.
    CDNA_ARRAY_TYPE,         // Array type.
    CDNA_MAP_TYPE,           // Map type.
    CDNA_QBIT_TYPE,          // Quantum bit type (64-bit).
    CDNA_NULLPTR_TYPE,       // Null pointer type.
    CDNA_INVALID_TYPE,       // Invalid data structure type.
    CDNA_UNKNOWN_TYPE        // Unknown data type.
} cdna_type;

// Union to hold data of different types.
typedef union {
    int int_type;              // Integer type.
    int8_t int8_type;          // 8-bit integer type.
    int16_t int16_type;        // 16-bit integer type.
    int32_t int32_type;        // 32-bit integer type.
    int64_t int64_type;        // 64-bit integer type.
    unsigned int uint_type;    // Unsigned integer type.
    uint8_t uint8_type;        // 8-bit unsigned integer type.
    uint16_t uint16_type;      // 16-bit unsigned integer type.
    uint32_t uint32_type;      // 32-bit unsigned integer type.
    uint64_t uint64_type;      // 64-bit unsigned integer type.
    uint8_t octal8_type;       // 8-bit octal type.
    uint16_t octal16_type;     // 16-bit octal type.
    uint32_t octal32_type;     // 32-bit octal type.
    uint64_t octal64_type;     // 64-bit octal type.
    uint8_t bitwise8_type;     // 8-bit bitwise type.
    uint16_t bitwise16_type;   // 16-bit bitwise type.
    uint32_t bitwise32_type;   // 32-bit bitwise type.
    uint64_t bitwise64_type;   // 64-bit bitwise type.
    uint8_t hex8_type;         // 8-bit hexadecimal type.
    uint16_t hex16_type;       // 16-bit hexadecimal type.
    uint32_t hex32_type;       // 32-bit hexadecimal type.
    uint64_t hex64_type;       // 64-bit hexadecimal type.
    double double_type;        // Double precision floating-point type.
    float float_type;          // Single precision floating-point type.
    char* string_type;         // String type.
    char char_type;            // Character type.
    void* nullptr_type;        // Null pointer type.
    uint64_t qbit_type;        // 64-bit quantum bit type.
    bool boolean_type;         // Boolean type.
    struct {
        struct cdna* elements; // Array type.
        size_t size;           // Size of the array.
    } array_type;
    struct {
        struct cdna* key;       // Key type for a map.
        struct cdna* value;     // Value type for a map.
        size_t size;            // Size of the map.
    } map_type;
} cdna_data;

// Struct to represent the data and its type.
typedef struct {
    cdna_type type;  // The data type.
    cdna_data data;  // The data stored.
} cdna;

// Assertion operations
cdna_assert_error assume(cdna_opt op, const cdna* left, const cdna* right);
cdna_assert_error assume_not_equal(const cdna* left, const cdna* right);
cdna_assert_error assume_its_equal(const cdna* left, const cdna* right);
cdna_assert_error assume_its_less(const cdna* left, const cdna* right);
cdna_assert_error assume_its_more(const cdna* left, const cdna* right);
cdna_assert_error assume_less_or_equal(const cdna* left, const cdna* right);
cdna_assert_error assume_more_or_equal(const cdna* left, const cdna* right);

#ifdef __cplusplus
}
#endif

#endif