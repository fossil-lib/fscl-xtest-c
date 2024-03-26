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
#include <fossil/xtest.h>
#include <fossil/xassume.h>

#include <stdint.h>
#include <wchar.h>

//
// TEST CASES
//
// Test case for memory equality
XTEST_CASE(assume_case_memory_equality) {
    char expected[] = "Hello, World!";
    char actual[] = "Hello, World!";
    size_t size = sizeof(expected);

    TEST_ASSUME_EQUAL_MEMORY(actual, expected, size); // Should pass
}

// Test case for memory inequality
XTEST_CASE(assume_case_memory_inequality) {
    char expected[] = "Hello, World!";
    char actual[] = "Goodbye, World!";
    size_t size = sizeof(expected);

    TEST_ASSUME_NOT_EQUAL_MEMORY(actual, expected, size); // Should pass
}

// Test case for memory contains
XTEST_CASE(assume_case_memory_contains) {
    char haystack[] = "This is a test string.";
    char needle[] = "test";
    size_t haystackSize = sizeof(haystack);
    size_t needleSize = sizeof(needle) - 1; // Exclude the null terminator

    TEST_ASSUME_CONTAINS_MEMORY(haystack, needle, haystackSize, needleSize); // Should pass
}

// Test case for memory not contains
XTEST_CASE(assume_case_memory_not_contains) {
    char haystack[] = "This is a test string.";
    char needle[] = "example";
    size_t haystackSize = sizeof(haystack);
    size_t needleSize = sizeof(needle) - 1; // Exclude the null terminator

    TEST_ASSUME_NOT_CONTAINS_MEMORY(haystack, needle, haystackSize, needleSize); // Should pass
}

// Test case for memory copied
XTEST_CASE(assume_case_memory_copied) {
    char source[] = "Source String";
    char dest[sizeof(source)];
    size_t size = sizeof(source);

    memcpy(dest, source, size);

    TEST_ASSUME_COPIED_MEMORY(dest, source, size); // Should pass
}

// Test case for memory not copied
XTEST_CASE(assume_case_memory_not_copied) {
    char source[] = "Source String";
    char dest[sizeof(source)];
    size_t size = sizeof(source);

    memset(dest, 0, size); // Ensure memory is not copied

    TEST_ASSUME_NOT_COPIED_MEMORY(dest, source, size); // Should pass
}

// Test case for boolean equality
XTEST_CASE(assume_case_boolean_equality) {
    bool expected = true;
    bool actual = true;

    TEST_ASSUME_EQUAL_BOOL(actual, expected); // Should pass
}

// Test case for boolean inequality
XTEST_CASE(assume_case_boolean_inequality) {
    bool expected = true;
    bool actual = false;

    TEST_ASSUME_NOT_EQUAL_BOOL(actual, expected); // Should pass
}

// Test case for boolean less than
XTEST_CASE(assume_case_boolean_less_than) {
    bool expected = false;
    bool actual = true;

    TEST_ASSUME_LESS_BOOL(actual, expected); // Should pass
}

// Test case for boolean greater than
XTEST_CASE(assume_case_boolean_greater_than) {
    bool expected = true;
    bool actual = false;

    TEST_ASSUME_GREATER_BOOL(actual, expected); // Should pass
}

// Test case for boolean unless
XTEST_CASE(assume_case_boolean_unless) {
    bool condition = false;

    TEST_ASSUME_UNLESS_BOOL(condition); // Should pass
}

// Test case for boolean true
XTEST_CASE(assume_case_boolean_true) {
    bool condition = true;

    TEST_ASSUME_TRUE_BOOL(condition); // Should pass
}

// Test case for boolean false
XTEST_CASE(assume_case_boolean_false) {
    bool condition = false;

    TEST_ASSUME_FALSE_BOOL(condition); // Should pass
}

// Test case for boolean message
XTEST_CASE(assume_case_boolean_message) {
    bool condition = false;

    TEST_ASSUME_MSG_BOOL(condition, "This is a custom message."); // Should pass with the custom message
}

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

// Test case for enum equality
XTEST_CASE(assume_case_enum_equality) {
    Color expected = GREEN;
    Color actual = GREEN;

    TEST_ASSUME_EQUAL_ENUM(actual, expected); // Should pass
}

// Test case for enum inequality
XTEST_CASE(assume_case_enum_inequality) {
    Color expected = RED;
    Color actual = BLUE;

    TEST_ASSUME_NOT_EQUAL_ENUM(actual, expected); // Should pass
}

// Test case for enum less than
XTEST_CASE(assume_case_enum_less_than) {
    Color expected = RED;
    Color actual = BLUE;

    TEST_ASSUME_LESS_ENUM(actual, expected); // Should pass
}

// Test case for enum greater than
XTEST_CASE(assume_case_enum_greater_than) {
    Color expected = BLUE;
    Color actual = RED;

    TEST_ASSUME_GREATER_ENUM(actual, expected); // Should pass
}

// Test case for enum less than or equal
XTEST_CASE(assume_case_enum_less_than_or_equal) {
    Color expected = GREEN;
    Color actual = BLUE;

    TEST_ASSUME_LESS_EQUAL_ENUM(actual, expected); // Should pass
}

// Test case for enum greater than or equal
XTEST_CASE(assume_case_enum_greater_than_or_equal) {
    Color expected = RED;
    Color actual = RED;

    TEST_ASSUME_GREATER_EQUAL_ENUM(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_int_equality) {
    int expected = 42;
    int actual = 42;

    TEST_ASSUME_EQUAL_INT(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_int_inequality) {
    int expected = 42;
    int actual = 20;

    TEST_ASSUME_NOT_EQUAL_INT(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_int_less_than) {
    int expected = 20;
    int actual = 42;

    TEST_ASSUME_LESS_INT(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_int_greater_than) {
    int expected = 20;
    int actual = 42;

    TEST_ASSUME_GREATER_INT(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_int_less_than_or_equal) {
    int expected = 42;
    int actual = 42;

    TEST_ASSUME_LESS_EQUAL_INT(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_int_greater_than_or_equal) {
    int expected = 42;
    int actual = 20;

    TEST_ASSUME_GREATER_EQUAL_INT(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_int8_equality) {
    int8_t expected = 42;
    int8_t actual = 42;

    TEST_ASSUME_EQUAL_INT8(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_int8_inequality) {
    int8_t expected = 42;
    int8_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_INT8(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_int8_less_than) {
    int8_t expected = 20;
    int8_t actual = 42;

    TEST_ASSUME_LESS_INT8(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_int8_greater_than) {
    int8_t expected = 20;
    int8_t actual = 42;

    TEST_ASSUME_GREATER_INT8(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_int8_less_than_or_equal) {
    int8_t expected = 42;
    int8_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_INT8(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_int8_greater_than_or_equal) {
    int8_t expected = 42;
    int8_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_INT8(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_int16_equality) {
    int16_t expected = 42;
    int16_t actual = 42;

    TEST_ASSUME_EQUAL_INT16(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_int16_inequality) {
    int16_t expected = 42;
    int16_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_INT16(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_int16_less_than) {
    int16_t expected = 20;
    int16_t actual = 42;

    TEST_ASSUME_LESS_INT16(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_int16_greater_than) {
    int16_t expected = 20;
    int16_t actual = 42;

    TEST_ASSUME_GREATER_INT16(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_int16_less_than_or_equal) {
    int16_t expected = 42;
    int16_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_INT16(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_int16_greater_than_or_equal) {
    int16_t expected = 42;
    int16_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_INT16(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_int32_equality) {
    int32_t expected = 42;
    int32_t actual = 42;

    TEST_ASSUME_EQUAL_INT32(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_int32_inequality) {
    int32_t expected = 42;
    int32_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_INT32(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_int32_less_than) {
    int32_t expected = 20;
    int32_t actual = 42;

    TEST_ASSUME_LESS_INT32(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_int32_greater_than) {
    int32_t expected = 20;
    int32_t actual = 42;

    TEST_ASSUME_GREATER_INT32(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_int32_less_than_or_equal) {
    int32_t expected = 42;
    int32_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_INT32(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_int32_greater_than_or_equal) {
    int32_t expected = 42;
    int32_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_INT32(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_int64_equality) {
    int64_t expected = 42;
    int64_t actual = 42;

    TEST_ASSUME_EQUAL_INT64(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_int64_inequality) {
    int64_t expected = 42;
    int64_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_INT64(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_int64_less_than) {
    int64_t expected = 20;
    int64_t actual = 42;

    TEST_ASSUME_LESS_INT64(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_int64_greater_than) {
    int64_t expected = 20;
    int64_t actual = 42;

    TEST_ASSUME_GREATER_INT64(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_int64_less_than_or_equal) {
    int64_t expected = 42;
    int64_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_INT64(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_int64_greater_than_or_equal) {
    int64_t expected = 42;
    int64_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_INT64(actual, expected); // Should pass
}





// Test case for integer equality
XTEST_CASE(assume_case_uint8_equality) {
    uint8_t expected = 42;
    uint8_t actual = 42;

    TEST_ASSUME_EQUAL_UINT8(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_uint8_inequality) {
    uint8_t expected = 42;
    uint8_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_UINT8(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_uint8_less_than) {
    uint8_t expected = 20;
    uint8_t actual = 42;

    TEST_ASSUME_LESS_UINT8(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_uint8_greater_than) {
    uint8_t expected = 20;
    uint8_t actual = 42;

    TEST_ASSUME_GREATER_UINT8(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_uint8_less_than_or_equal) {
    uint8_t expected = 42;
    uint8_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_UINT8(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_uint8_greater_than_or_equal) {
    uint8_t expected = 42;
    uint8_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_UINT8(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_uint16_equality) {
    uint16_t expected = 42;
    uint16_t actual = 42;

    TEST_ASSUME_EQUAL_UINT16(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_uint16_inequality) {
    uint16_t expected = 42;
    uint16_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_UINT16(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_uint16_less_than) {
    uint16_t expected = 20;
    uint16_t actual = 42;

    TEST_ASSUME_LESS_UINT16(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_uint16_greater_than) {
    uint16_t expected = 20;
    uint16_t actual = 42;

    TEST_ASSUME_GREATER_UINT16(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_uint16_less_than_or_equal) {
    uint16_t expected = 42;
    uint16_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_UINT16(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_uint16_greater_than_or_equal) {
    uint16_t expected = 42;
    uint16_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_UINT16(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_uint32_equality) {
    uint32_t expected = 42;
    uint32_t actual = 42;

    TEST_ASSUME_EQUAL_UINT32(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_uint32_inequality) {
    uint32_t expected = 42;
    uint32_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_UINT32(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_uint32_less_than) {
    uint32_t expected = 20;
    uint32_t actual = 42;

    TEST_ASSUME_LESS_UINT32(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_uint32_greater_than) {
    uint32_t expected = 20;
    uint32_t actual = 42;

    TEST_ASSUME_GREATER_UINT32(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_uint32_less_than_or_equal) {
    uint32_t expected = 42;
    uint32_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_UINT32(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_uint32_greater_than_or_equal) {
    uint32_t expected = 42;
    uint32_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_UINT32(actual, expected); // Should pass
}

// Test case for integer equality
XTEST_CASE(assume_case_uint64_equality) {
    uint64_t expected = 42;
    uint64_t actual = 42;

    TEST_ASSUME_EQUAL_UINT64(actual, expected); // Should pass
}

// Test case for integer inequality
XTEST_CASE(assume_case_uint64_inequality) {
    uint64_t expected = 42;
    uint64_t actual = 20;

    TEST_ASSUME_NOT_EQUAL_UINT64(actual, expected); // Should pass
}

// Test case for integer less than
XTEST_CASE(assume_case_uint64_less_than) {
    uint64_t expected = 20;
    uint64_t actual = 42;

    TEST_ASSUME_LESS_UINT64(actual, expected); // Should pass
}

// Test case for integer greater than
XTEST_CASE(assume_case_uint64_greater_than) {
    uint64_t expected = 20;
    uint64_t actual = 42;

    TEST_ASSUME_GREATER_UINT64(actual, expected); // Should pass
}

// Test case for integer less than or equal
XTEST_CASE(assume_case_uint64_less_than_or_equal) {
    uint64_t expected = 42;
    uint64_t actual = 42;

    TEST_ASSUME_LESS_EQUAL_UINT64(actual, expected); // Should pass
}

// Test case for integer greater than or equal
XTEST_CASE(assume_case_uint64_greater_than_or_equal) {
    uint64_t expected = 42;
    uint64_t actual = 20;

    TEST_ASSUME_GREATER_EQUAL_UINT64(actual, expected); // Should pass
}

// Test case for hexadecimal equality
XTEST_CASE(assume_case_hex_equality) {
    int expected = 0x42;
    int actual = 0x42;

    TEST_ASSUME_EQUAL_HEX(actual, expected); // Should pass
}

// Test case for hexadecimal inequality
XTEST_CASE(assume_case_hex_inequality) {
    int expected = 0x42;
    int actual = 0x20;

    TEST_ASSUME_NOT_EQUAL_HEX(actual, expected); // Should pass
}

// Test case for hexadecimal less than
XTEST_CASE(assume_case_hex_less_than) {
    int expected = 0x20;
    int actual = 0x42;

    TEST_ASSUME_LESS_HEX(actual, expected); // Should pass
}

// Test case for hexadecimal greater than
XTEST_CASE(assume_case_hex_greater_than) {
    int expected = 0x20;
    int actual = 0x42;

    TEST_ASSUME_GREATER_HEX(actual, expected); // Should pass
}

// Test case for hexadecimal less than or equal
XTEST_CASE(assume_case_hex_less_than_or_equal) {
    int expected = 0x42;
    int actual = 0x42;

    TEST_ASSUME_LESS_EQUAL_HEX(actual, expected); // Should pass
}

// Test case for hexadecimal greater than or equal
XTEST_CASE(assume_case_hex_greater_than_or_equal) {
    int expected = 0x42;
    int actual = 0x20;

    TEST_ASSUME_GREATER_EQUAL_HEX(actual, expected); // Should pass
}

// Test case for 8-bit hexadecimal equality
XTEST_CASE(assume_case_hex8_equality) {
    uint8_t expected = 0x42;
    uint8_t actual = 0x42;

    TEST_ASSUME_EQUAL_HEX8(actual, expected); // Should pass
}

// Test case for 8-bit hexadecimal inequality
XTEST_CASE(assume_case_hex8_inequality) {
    uint8_t expected = 0x42;
    uint8_t actual = 0x20;

    TEST_ASSUME_NOT_EQUAL_HEX8(actual, expected); // Should pass
}

// Test case for 8-bit hexadecimal less than
XTEST_CASE(assume_case_hex8_less_than) {
    uint8_t expected = 0x20;
    uint8_t actual = 0x42;

    TEST_ASSUME_LESS_HEX8(actual, expected); // Should pass
}

// Test case for 8-bit hexadecimal greater than
XTEST_CASE(assume_case_hex8_greater_than) {
    uint8_t expected = 0x20;
    uint8_t actual = 0x42;

    TEST_ASSUME_GREATER_HEX8(actual, expected); // Should pass
}

// Test case for 8-bit hexadecimal less than or equal
XTEST_CASE(assume_case_hex8_less_than_or_equal) {
    uint8_t expected = 0x42;
    uint8_t actual = 0x42;

    TEST_ASSUME_LESS_EQUAL_HEX8(actual, expected); // Should pass
}

// Test case for 8-bit hexadecimal greater than or equal
XTEST_CASE(assume_case_hex8_greater_than_or_equal) {
    uint8_t expected = 0x42;
    uint8_t actual = 0x20;

    TEST_ASSUME_GREATER_EQUAL_HEX8(actual, expected); // Should pass
}

// Test case for 16-bit hexadecimal equality
XTEST_CASE(assume_case_hex16_equality) {
    uint16_t expected = 0x1234;
    uint16_t actual = 0x1234;

    TEST_ASSUME_EQUAL_HEX16(actual, expected); // Should pass
}

// Test case for 16-bit hexadecimal inequality
XTEST_CASE(assume_case_hex16_inequality) {
    uint16_t expected = 0x1234;
    uint16_t actual = 0xABCD;

    TEST_ASSUME_NOT_EQUAL_HEX16(actual, expected); // Should pass
}

// Test case for 16-bit hexadecimal less than
XTEST_CASE(assume_case_hex16_less_than) {
    uint16_t expected = 0xABCD;
    uint16_t actual = 0x1234;

    TEST_ASSUME_LESS_HEX16(actual, expected); // Should pass
}

// Test case for 16-bit hexadecimal greater than
XTEST_CASE(assume_case_hex16_greater_than) {
    uint16_t expected = 0x1234;
    uint16_t actual = 0xABCD;

    TEST_ASSUME_GREATER_HEX16(actual, expected); // Should pass
}

// Test case for 16-bit hexadecimal less than or equal
XTEST_CASE(assume_case_hex16_less_than_or_equal) {
    uint16_t expected = 0x1234;
    uint16_t actual = 0x1234;

    TEST_ASSUME_LESS_EQUAL_HEX16(actual, expected); // Should pass
}

// Test case for 16-bit hexadecimal greater than or equal
XTEST_CASE(assume_case_hex16_greater_than_or_equal) {
    uint16_t expected = 0x1234;
    uint16_t actual = 0xABCD;

    TEST_ASSUME_GREATER_EQUAL_HEX16(actual, expected); // Should pass
}

// Test case for 32-bit hexadecimal equality
XTEST_CASE(assume_case_hex32_equality) {
    uint32_t expected = 0x12345678;
    uint32_t actual = 0x12345678;

    TEST_ASSUME_EQUAL_HEX32(actual, expected); // Should pass
}

// Test case for 32-bit hexadecimal inequality
XTEST_CASE(assume_case_hex32_inequality) {
    uint32_t expected = 0x12345678;
    uint32_t actual = 0xABCD1234;

    TEST_ASSUME_NOT_EQUAL_HEX32(actual, expected); // Should pass
}

// Test case for 32-bit hexadecimal less than
XTEST_CASE(assume_case_hex32_less_than) {
    uint32_t expected = 0xABCDEF00;
    uint32_t actual = 0x12345678;

    TEST_ASSUME_LESS_HEX32(actual, expected); // Should pass
}

// Test case for 32-bit hexadecimal greater than
XTEST_CASE(assume_case_hex32_greater_than) {
    uint32_t expected = 0x12345678;
    uint32_t actual = 0xABCDEF00;

    TEST_ASSUME_GREATER_HEX32(actual, expected); // Should pass
}

// Test case for 32-bit hexadecimal less than or equal
XTEST_CASE(assume_case_hex32_less_than_or_equal) {
    uint32_t expected = 0x12345678;
    uint32_t actual = 0x12345678;

    TEST_ASSUME_LESS_EQUAL_HEX32(actual, expected); // Should pass
}

// Test case for 32-bit hexadecimal greater than or equal
XTEST_CASE(assume_case_hex32_greater_than_or_equal) {
    uint32_t expected = 0x12345678;
    uint32_t actual = 0xABCDEF00;

    TEST_ASSUME_GREATER_EQUAL_HEX32(actual, expected); // Should pass
}

// Test case for 64-bit hexadecimal equality
XTEST_CASE(assume_case_hex64_equality) {
    uint64_t expected = 0x1234567890ABCDEF;
    uint64_t actual = 0x1234567890ABCDEF;

    TEST_ASSUME_EQUAL_HEX64(actual, expected); // Should pass
}

// Test case for 64-bit hexadecimal inequality
XTEST_CASE(assume_case_hex64_inequality) {
    uint64_t expected = 0x1234567890ABCDEF;
    uint64_t actual = 0xFEDCBA0987654321;

    TEST_ASSUME_NOT_EQUAL_HEX64(actual, expected); // Should pass
}

// Test case for 64-bit hexadecimal less than
XTEST_CASE(assume_case_hex64_less_than) {
    uint64_t expected = 0xFEDCBA0987654321;
    uint64_t actual = 0x1234567890ABCDEF;

    TEST_ASSUME_LESS_HEX64(actual, expected); // Should pass
}

// Test case for 64-bit hexadecimal greater than
XTEST_CASE(assume_case_hex64_greater_than) {
    uint64_t expected = 0x1234567890ABCDEF;
    uint64_t actual = 0xFEDCBA0987654321;

    TEST_ASSUME_GREATER_HEX64(actual, expected); // Should pass
}

// Test case for 64-bit hexadecimal less than or equal
XTEST_CASE(assume_case_hex64_less_than_or_equal) {
    uint64_t expected = 0x1234567890ABCDEF;
    uint64_t actual = 0x1234567890ABCDEF;

    TEST_ASSUME_LESS_EQUAL_HEX64(actual, expected); // Should pass
}

// Test case for 64-bit hexadecimal greater than or equal
XTEST_CASE(assume_case_hex64_greater_than_or_equal) {
    uint64_t expected = 0xFEDCBA0987654321;
    uint64_t actual = 0x1234567890ABCDEF;

    TEST_ASSUME_GREATER_EQUAL_HEX64(actual, expected); // Should pass
}

// Test case for octal equality
XTEST_CASE(assume_case_oct_equality) {
    unsigned expected = 01234; // Octal representation
    unsigned actual = 01234;

    TEST_ASSUME_EQUAL_OCT(actual, expected); // Should pass
}

// Test case for octal inequality
XTEST_CASE(assume_case_oct_inequality) {
    unsigned expected = 01234; // Octal representation
    unsigned actual = 05671; // Different octal value

    TEST_ASSUME_NOT_EQUAL_OCT(actual, expected); // Should pass
}

// Test case for octal less than
XTEST_CASE(assume_case_oct_less_than) {
    unsigned expected = 01234; // Octal representation
    unsigned actual = 06754; // Different octal value

    TEST_ASSUME_LESS_OCT(actual, expected); // Should pass
}

// Test case for octal greater than
XTEST_CASE(assume_case_oct_greater_than) {
    unsigned expected = 06754; // Octal representation
    unsigned actual = 01234; // Different octal value

    TEST_ASSUME_GREATER_OCT(actual, expected); // Should pass
}

// Test case for octal less than or equal
XTEST_CASE(assume_case_oct_less_than_or_equal) {
    unsigned expected = 01234; // Octal representation
    unsigned actual = 01234;

    TEST_ASSUME_LESS_EQUAL_OCT(actual, expected); // Should pass
}

// Test case for octal greater than or equal
XTEST_CASE(assume_case_oct_greater_than_or_equal) {
    unsigned expected = 06754; // Octal representation
    unsigned actual = 01234; // Different octal value

    TEST_ASSUME_GREATER_EQUAL_OCT(actual, expected); // Should pass
}


//
//
//
// Test case for bitwise equality
XTEST_CASE(assume_case_bit_equality) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x0F;   // Binary 00001111

    TEST_ASSUME_BIT_EQUAL(actual, expected); // Should pass
}

// Test case for bitwise inequality
XTEST_CASE(assume_case_bit_inequality) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011

    TEST_ASSUME_BIT_NOT_EQUAL(actual, expected); // Should pass
}

// Test case for bitwise less than
XTEST_CASE(assume_case_bit_less_than) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011

    TEST_ASSUME_BIT_LESS(actual, expected); // Should pass
}

// Test case for bitwise greater than
XTEST_CASE(assume_case_bit_greater_than) {
    unsigned expected = 0x33;   // Binary 00110011
    unsigned actual = 0x0F; // Binary 00001111

    TEST_ASSUME_BIT_GREATER(actual, expected); // Should pass
}

// Test case for bitwise less than or equal
XTEST_CASE(assume_case_bit_less_than_or_equal) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x0F;   // Binary 00001111

    TEST_ASSUME_BIT_LESS_EQUAL(actual, expected); // Should pass
}

// Test case for bitwise greater than or equal
XTEST_CASE(assume_case_bit_greater_than_or_equal) {
    unsigned expected = 0x33;   // Binary 00110011
    unsigned actual = 0x0F; // Binary 00001111

    TEST_ASSUME_BIT_GREATER_EQUAL(actual, expected); // Should pass
}

// Test case for checking that a bit is not high
XTEST_CASE(assume_case_bit_not_high) {
    unsigned value = 0x0F; // Binary 00001111
    int bitIndex = 3;

    TEST_ASSUME_BIT_NOT_HIGH(value, bitIndex); // Should pass
}

// Test case for checking that a bit is high
XTEST_CASE(assume_case_bit_high) {
    unsigned value = 0x0F; // Binary 00001111
    int bitIndex = 3;

    TEST_ASSUME_BIT_HIGH(value, bitIndex); // Should pass
}

// Test case for checking that a bit is not low
XTEST_CASE(assume_case_bit_not_low) {
    unsigned value = 0x0F; // Binary 00001111
    int bitIndex = 3;

    TEST_ASSUME_BIT_NOT_LOW(value, bitIndex); // Should pass
}

// Test case for checking that a bit is low
XTEST_CASE(assume_case_bit_low) {
    unsigned value = 0x0F; // Binary 00001111
    int bitIndex = 4;

    TEST_ASSUME_BIT_LOW(value, bitIndex); // Should pass
}

// Test case for checking that no bits are high
XTEST_CASE(assume_case_bits_not_high) {
    unsigned value = 0x0F; // Binary 00001111
    unsigned mask = 0x80;  // Binary 10000000

    TEST_ASSUME_BITS_NOT_HIGH(value, mask); // Should pass
}

// Test case for checking that all bits are high
XTEST_CASE(assume_case_bits_high) {
    unsigned value = 0xFF; // Binary 11111111
    unsigned mask = 0xF0;  // Binary 11110000

    TEST_ASSUME_BITS_HIGH(value, mask); // Should pass
}

// Test case for checking that no bits are low
XTEST_CASE(assume_case_bits_not_low) {
    unsigned value = 0xFF; // Binary 11111111
    unsigned mask = 0xF0;  // Binary 11110000

    TEST_ASSUME_BITS_NOT_LOW(value, mask); // Should pass
}

// Test case for checking that all bits are low
XTEST_CASE(assume_case_bits_low) {
    unsigned value = 0x0F; // Binary 00001111
    unsigned mask = 0x80;  // Binary 10000000

    TEST_ASSUME_BITS_LOW(value, mask); // Should pass
}

// Test case for checking bitwise equality using a mask
XTEST_CASE(assume_case_bits_equal) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011
    unsigned mask = 0x0F;     // Binary 00001111

    TEST_ASSUME_BITS_EQUAL(actual, expected, mask); // Should pass
}

// Test case for checking bitwise inequality using a mask
XTEST_CASE(assume_case_bits_not_equal) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011
    unsigned mask = 0x0F;     // Binary 00001111

    TEST_ASSUME_BITS_NOT_EQUAL(actual, expected, mask); // Should pass
}

// Test case for checking bitwise less than using a mask
XTEST_CASE(assume_case_bits_less_than) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011
    unsigned mask = 0x0F;     // Binary 00001111

    TEST_ASSUME_BITS_LESS(actual, expected, mask); // Should pass
}

// Test case for checking bitwise greater than using a mask
XTEST_CASE(assume_case_bits_greater_than) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011
    unsigned mask = 0x0F;     // Binary 00001111

    TEST_ASSUME_BITS_NOT_GREATER(actual, expected, mask); // Should pass
}

// Test case for checking bitwise less than or equal using a mask
XTEST_CASE(assume_case_bits_less_than_or_equal) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011
    unsigned mask = 0x0F;     // Binary 00001111

    TEST_ASSUME_BITS_NOT_LESS_EQUAL(actual, expected, mask); // Should pass
}

// Test case for checking bitwise greater than or equal using a mask
XTEST_CASE(assume_case_bits_greater_than_or_equal) {
    unsigned expected = 0x0F; // Binary 00001111
    unsigned actual = 0x33;   // Binary 00110011
    unsigned mask = 0x0F;     // Binary 00001111

    TEST_ASSUME_BITS_GREATER_EQUAL(actual, expected, mask); // Should pass
}




// Test case for checking an integer value within tolerance
XTEST_CASE(assume_case_int_within_tolerance) {
    int actual = 10;
    int expected = 12;
    int tolerance = 2;

    TEST_ASSUME_INT_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking an integer value not within tolerance
XTEST_CASE(assume_case_int_not_within_tolerance) {
    int actual = 10;
    int expected = 12;
    int tolerance = 1;

    TEST_ASSUME_INT_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking an 8-bit integer value within tolerance
XTEST_CASE(assume_case_int8_within_tolerance) {
    int8_t actual = 10;
    int8_t expected = 12;
    int8_t tolerance = 2;

    TEST_ASSUME_INT8_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking an 8-bit integer value not within tolerance
XTEST_CASE(assume_case_int8_not_within_tolerance) {
    int8_t actual = 10;
    int8_t expected = 12;
    int8_t tolerance = 1;

    TEST_ASSUME_INT8_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 16-bit integer value within tolerance
XTEST_CASE(assume_case_int16_within_tolerance) {
    int16_t actual = 1000;
    int16_t expected = 1010;
    int16_t tolerance = 20;

    TEST_ASSUME_INT16_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 16-bit integer value not within tolerance
XTEST_CASE(assume_case_int16_not_within_tolerance) {
    int16_t actual = 1000;
    int16_t expected = 1010;
    int16_t tolerance = 5;

    TEST_ASSUME_INT16_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 32-bit integer value within tolerance
XTEST_CASE(assume_case_int32_within_tolerance) {
    int32_t actual = 10000;
    int32_t expected = 10020;
    int32_t tolerance = 30;

    TEST_ASSUME_INT32_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 32-bit integer value not within tolerance
XTEST_CASE(assume_case_int32_not_within_tolerance) {
    int32_t actual = 10000;
    int32_t expected = 10020;
    int32_t tolerance = 5;

    TEST_ASSUME_INT32_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 64-bit integer value within tolerance
XTEST_CASE(assume_case_int64_within_tolerance) {
    int64_t actual = 1000000;
    int64_t expected = 1000020;
    int64_t tolerance = 30;

    TEST_ASSUME_INT64_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 64-bit integer value not within tolerance
XTEST_CASE(assume_case_int64_not_within_tolerance) {
    int64_t actual = 1000000;
    int64_t expected = 1000020;
    int64_t tolerance = 5;

    TEST_ASSUME_INT64_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking an unsigned integer value within tolerance
XTEST_CASE(assume_case_uint_within_tolerance) {
    unsigned actual = 10;
    unsigned expected = 12;
    unsigned tolerance = 2;

    TEST_ASSUME_UINT_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking an unsigned integer value not within tolerance
XTEST_CASE(assume_case_uint_not_within_tolerance) {
    unsigned actual = 10;
    unsigned expected = 12;
    unsigned tolerance = 1;

    TEST_ASSUME_UINT_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking an 8-bit unsigned integer value within tolerance
XTEST_CASE(assume_case_uint8_within_tolerance) {
    uint8_t actual = 10;
    uint8_t expected = 12;
    uint8_t tolerance = 2;

    TEST_ASSUME_UINT8_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking an 8-bit unsigned integer value not within tolerance
XTEST_CASE(assume_case_uint8_not_within_tolerance) {
    uint8_t actual = 10;
    uint8_t expected = 12;
    uint8_t tolerance = 1;

    TEST_ASSUME_UINT8_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 16-bit unsigned integer value within tolerance
XTEST_CASE(assume_case_uint16_within_tolerance) {
    uint16_t actual = 1000;
    uint16_t expected = 1010;
    uint16_t tolerance = 20;

    TEST_ASSUME_UINT16_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 16-bit unsigned integer value not within tolerance
XTEST_CASE(assume_case_uint16_not_within_tolerance) {
    uint16_t actual = 1000;
    uint16_t expected = 1010;
    uint16_t tolerance = 5;

    TEST_ASSUME_UINT16_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 32-bit unsigned integer value within tolerance
XTEST_CASE(assume_case_uint32_within_tolerance) {
    uint32_t actual = 10000;
    uint32_t expected = 10020;
    uint32_t tolerance = 30;

    TEST_ASSUME_UINT32_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 32-bit unsigned integer value not within tolerance
XTEST_CASE(assume_case_uint32_not_within_tolerance) {
    uint32_t actual = 10000;
    uint32_t expected = 10020;
    uint32_t tolerance = 5;

    TEST_ASSUME_UINT32_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 64-bit unsigned integer value within tolerance
XTEST_CASE(assume_case_uint64_within_tolerance) {
    uint64_t actual = 1000000;
    uint64_t expected = 1000020;
    uint64_t tolerance = 30;

    TEST_ASSUME_UINT64_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 64-bit unsigned integer value not within tolerance
XTEST_CASE(assume_case_uint64_not_within_tolerance) {
    uint64_t actual = 1000000;
    uint64_t expected = 1000020;
    uint64_t tolerance = 5;

    TEST_ASSUME_UINT64_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a hexadecimal value within tolerance
XTEST_CASE(assume_case_hex_within_tolerance) {
    int actual = 0x1234;
    int expected = 0x1236;
    int tolerance = 2;

    TEST_ASSUME_HEX_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a hexadecimal value not within tolerance
XTEST_CASE(assume_case_hex_not_within_tolerance) {
    int actual = 0x1234;
    int expected = 0x1236;
    int tolerance = 1;

    TEST_ASSUME_HEX_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking an 8-bit hexadecimal value within tolerance
XTEST_CASE(assume_case_hex8_within_tolerance) {
    uint8_t actual = 0x12;
    uint8_t expected = 0x14;
    uint8_t tolerance = 2;

    TEST_ASSUME_HEX8_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking an 8-bit hexadecimal value not within tolerance
XTEST_CASE(assume_case_hex8_not_within_tolerance) {
    uint8_t actual = 0x12;
    uint8_t expected = 0x14;
    uint8_t tolerance = 1;

    TEST_ASSUME_HEX8_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 16-bit hexadecimal value within tolerance
XTEST_CASE(assume_case_hex16_within_tolerance) {
    uint16_t actual = 0x1234;
    uint16_t expected = 0x1236;
    uint16_t tolerance = 2;

    TEST_ASSUME_HEX16_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 16-bit hexadecimal value not within tolerance
XTEST_CASE(assume_case_hex16_not_within_tolerance) {
    uint16_t actual = 0x1234;
    uint16_t expected = 0x1236;
    uint16_t tolerance = 1;

    TEST_ASSUME_HEX16_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 32-bit hexadecimal value within tolerance
XTEST_CASE(assume_case_hex32_within_tolerance) {
    uint32_t actual = 0x12345678;
    uint32_t expected = 0x1234567A;
    uint32_t tolerance = 2;

    TEST_ASSUME_HEX32_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 32-bit hexadecimal value not within tolerance
XTEST_CASE(assume_case_hex32_not_within_tolerance) {
    uint32_t actual = 0x12345678;
    uint32_t expected = 0x1234567A;
    uint32_t tolerance = 1;

    TEST_ASSUME_HEX32_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a 64-bit hexadecimal value within tolerance
XTEST_CASE(assume_case_hex64_within_tolerance) {
    uint64_t actual = 0x123456789ABCDEF0;
    uint64_t expected = 0x123456789ABCDEF2;
    uint64_t tolerance = 2;

    TEST_ASSUME_HEX64_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a 64-bit hexadecimal value not within tolerance
XTEST_CASE(assume_case_hex64_not_within_tolerance) {
    uint64_t actual = 0x123456789ABCDEF0;
    uint64_t expected = 0x123456789ABCDEF2;
    uint64_t tolerance = 1;

    TEST_ASSUME_HEX64_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a binary value within tolerance
XTEST_CASE(assume_case_bin_within_tolerance) {
    int actual = 0b1100;
    int expected = 0b1101;
    int tolerance = 1;

    TEST_ASSUME_BIN_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking a binary value not within tolerance
XTEST_CASE(assume_case_bin_not_within_tolerance) {
    int actual = 0b1100;
    int expected = 0b1101;
    int tolerance = 0;

    TEST_ASSUME_BIN_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking an octal value within tolerance
XTEST_CASE(assume_case_oct_within_tolerance) {
    int actual = 012;
    int expected = 013;
    int tolerance = 1;

    TEST_ASSUME_OCT_WITHIN(actual, expected, tolerance); // Should pass
}

// Test case for checking an octal value not within tolerance
XTEST_CASE(assume_case_oct_not_within_tolerance) {
    int actual = 012;
    int expected = 013;
    int tolerance = 0;

    TEST_ASSUME_OCT_WITHIN(actual, expected, tolerance); // Should fail
}

// Test case for checking a float value within epsilon
XTEST_CASE(assume_case_float_within_epsilon) {
    float actual = 3.14;
    float expected = 3.14159;
    float epsilon = 0.01;

    TEST_ASSUME_FLOAT_WITHIN(actual, expected, epsilon); // Should pass
}

// Test case for checking a float value not within epsilon
XTEST_CASE(assume_case_float_not_within_epsilon) {
    float actual = 3.14;
    float expected = 3.14159;
    float epsilon = 0.001;

    TEST_ASSUME_FLOAT_WITHIN(actual, expected, epsilon); // Should fail
}

// Test case for checking a double value within epsilon
XTEST_CASE(assume_case_double_within_epsilon) {
    double actual = 3.14;
    double expected = 3.14159;
    double epsilon = 0.01;

    TEST_ASSUME_DOUBLE_WITHIN(actual, expected, epsilon); // Should pass
}

// Test case for checking a double value not within epsilon
XTEST_CASE(assume_case_double_not_within_epsilon) {
    double actual = 3.14;
    double expected = 3.14159;
    double epsilon = 0.001;

    TEST_ASSUME_DOUBLE_WITHIN(actual, expected, epsilon); // Should fail
}

// Test case for checking a character value within a range
XTEST_CASE(assume_case_char_within_range) {
    char actual = 'A';
    char min = 'A';
    char max = 'Z';

    TEST_ASSUME_CHAR_WITHIN(actual, min, max); // Should pass
}

// Test case for checking a character value not within a range
XTEST_CASE(assume_case_char_not_within_range) {
    char actual = 'a';
    char min = 'A';
    char max = 'Z';

    TEST_ASSUME_CHAR_WITHIN(actual, min, max); // Should fail
}

// Test case for checking a wide character value within a range
XTEST_CASE(assume_case_wchar_within_range) {
    wchar_t actual = L'Ω';
    wchar_t min = L'Α';
    wchar_t max = L'Ω';

    TEST_ASSUME_WCHAR_WITHIN(actual, min, max); // Should pass
}

// Test case for checking a wide character value not within a range
XTEST_CASE(assume_case_wchar_not_within_range) {
    wchar_t actual = L'ß';
    wchar_t min = L'Α';
    wchar_t max = L'Ω';

    TEST_ASSUME_WCHAR_WITHIN(actual, min, max); // Should fail
}

// Test case for checking if two floating-point values are equal within epsilon
XTEST_CASE(assume_case_float_equal) {
    float actual = 3.14159f;
    float expected = 3.1415926f;

    TEST_ASSUME_FLOAT_EQUAL(actual, expected); // Should pass
}

// Test case for checking if two floating-point values are not equal within epsilon
XTEST_CASE(assume_case_float_not_equal) {
    float actual = 3.14159f;
    float expected = 3.1415926f;

    TEST_ASSUME_FLOAT_NOT_EQUAL(actual, expected); // Should fail
}

// Test case for checking if a floating-point value is less than another
XTEST_CASE(assume_case_float_less) {
    float actual = 3.0f;
    float expected = 3.14159f;

    TEST_ASSUME_FLOAT_LESS(actual, expected); // Should pass
}

// Test case for checking if a floating-point value is not less than another
XTEST_CASE(assume_case_float_not_less) {
    float actual = 3.14159f;
    float expected = 3.0f;

    TEST_ASSUME_FLOAT_LESS(actual, expected); // Should fail
}

// Test case for checking if a floating-point value is greater than another
XTEST_CASE(assume_case_float_greater) {
    float actual = 3.14159f;
    float expected = 3.0f;

    TEST_ASSUME_FLOAT_GREATER(actual, expected); // Should pass
}

// Test case for checking if a floating-point value is not greater than another
XTEST_CASE(assume_case_float_not_greater) {
    float actual = 3.0f;
    float expected = 3.14159f;

    TEST_ASSUME_FLOAT_GREATER(actual, expected); // Should fail
}

// Test case for checking if a floating-point value is greater than or equal to another
XTEST_CASE(assume_case_float_greater_equal) {
    float actual = 3.14159f;
    float expected = 3.0f;

    TEST_ASSUME_FLOAT_GREATER_EQUAL(actual, expected); // Should pass
}

// Test case for checking if a floating-point value is not greater than or equal to another
XTEST_CASE(assume_case_float_not_greater_equal) {
    float actual = 2.0f;
    float expected = 3.14159f;

    TEST_ASSUME_FLOAT_GREATER_EQUAL(actual, expected); // Should fail
}

// Test case for checking if a floating-point value is less than or equal to another
XTEST_CASE(assume_case_float_less_equal) {
    float actual = 3.0f;
    float expected = 3.14159f;

    TEST_ASSUME_FLOAT_LESS_EQUAL(actual, expected); // Should pass
}

// Test case for checking if a floating-point value is not less than or equal to another
XTEST_CASE(assume_case_float_not_less_equal) {
    float actual = 3.14159f;
    float expected = 2.0f;

    TEST_ASSUME_FLOAT_LESS_EQUAL(actual, expected); // Should fail
}

// Test case for checking if a floating-point value is not infinity
XTEST_CASE(assume_case_float_not_inf) {
    float value = 3.14159f;

    TEST_ASSUME_FLOAT_IS_NOT_INF(value); // Should pass
}

// Test case for checking if a floating-point value is infinity
XTEST_CASE(assume_case_float_inf) {
    float value = INFINITY;

    TEST_ASSUME_FLOAT_IS_INF(value); // Should pass
}

// Test case for checking if a floating-point value is not negative infinity
XTEST_CASE(assume_case_float_not_neg_inf) {
    float value = 3.14159f;

    TEST_ASSUME_FLOAT_IS_NOT_NEG_INF(value); // Should pass
}

// Test case for checking if a floating-point value is negative infinity
XTEST_CASE(assume_case_float_neg_inf) {
    float value = -INFINITY;

    TEST_ASSUME_FLOAT_IS_NEG_INF(value); // Should pass
}

// Test case for checking if a floating-point value is finite
XTEST_CASE(assume_case_float_finite) {
    float value = 3.14159f;

    TEST_ASSUME_FLOAT_IS_FINITE(value); // Should pass
}

// Test case for checking if a floating-point value is not finite
XTEST_CASE(assume_case_float_not_finite) {
    float value = INFINITY;

    TEST_ASSUME_FLOAT_IS_NOT_FINITE(value); // Should fail
}

// Test case for checking if a floating-point value is not NaN
XTEST_CASE(assume_case_float_not_nan) {
    float value = 3.14159f;

    TEST_ASSUME_FLOAT_IS_NOT_NAN(value); // Should pass
}

// Test case for checking if a floating-point value is NaN
XTEST_CASE(assume_case_float_nan) {
    float value = NAN;

    TEST_ASSUME_FLOAT_IS_NAN(value); // Should pass
}

// Test case for checking if a floating-point value is deterministic (not NaN or inf)
XTEST_CASE(assume_case_float_is_determinate) {
    float actual = 3.14159f;

    TEST_ASSUME_FLOAT_IS_DETERMINATE(actual); // Should pass
}

// Test case for checking if a floating-point value is not deterministic (NaN or inf)
XTEST_CASE(assume_case_float_is_not_determinate) {
    float value = INFINITY;

    TEST_ASSUME_FLOAT_IS_NOT_DETERMINATE(value); // Should fail
}

// Test case for checking if two double-precision floating-point values are equal within epsilon
XTEST_CASE(assume_case_double_equal) {
    double actual = 3.14159;
    double expected = 3.1415926;

    TEST_ASSUME_DOUBLE_EQUAL(actual, expected); // Should pass
}

// Test case for checking if two double-precision floating-point values are not equal within epsilon
XTEST_CASE(assume_case_double_not_equal) {
    double actual = 3.14159;
    double expected = 3.1415926;

    TEST_ASSUME_DOUBLE_NOT_EQUAL(actual, expected); // Should fail
}

// Test case for checking if a double-precision floating-point value is less than another
XTEST_CASE(assume_case_double_less) {
    double actual = 3.0;
    double expected = 3.14159;

    TEST_ASSUME_DOUBLE_LESS(actual, expected); // Should pass
}

// Test case for checking if a double-precision floating-point value is not less than another
XTEST_CASE(assume_case_double_not_less) {
    double actual = 3.14159;
    double expected = 3.0;

    TEST_ASSUME_DOUBLE_LESS(actual, expected); // Should fail
}

// Test case for checking if a double-precision floating-point value is greater than another
XTEST_CASE(assume_case_double_greater) {
    double actual = 3.14159;
    double expected = 3.0;

    TEST_ASSUME_DOUBLE_GREATER(actual, expected); // Should pass
}

// Test case for checking if a double-precision floating-point value is not greater than another
XTEST_CASE(assume_case_double_not_greater) {
    double actual = 3.0;
    double expected = 3.14159;

    TEST_ASSUME_DOUBLE_GREATER(actual, expected); // Should fail
}

// Test case for checking if a double-precision floating-point value is greater than or equal to another
XTEST_CASE(assume_case_double_greater_equal) {
    double actual = 3.14159;
    double expected = 3.0;

    TEST_ASSUME_DOUBLE_GREATER_EQUAL(actual, expected); // Should pass
}

// Test case for checking if a double-precision floating-point value is not greater than or equal to another
XTEST_CASE(assume_case_double_not_greater_equal) {
    double actual = 2.0;
    double expected = 3.14159;

    TEST_ASSUME_DOUBLE_GREATER_EQUAL(actual, expected); // Should fail
}

// Test case for checking if a double-precision floating-point value is less than or equal to another
XTEST_CASE(assume_case_double_less_equal) {
    double actual = 3.0;
    double expected = 3.14159;

    TEST_ASSUME_DOUBLE_LESS_EQUAL(actual, expected); // Should pass
}

// Test case for checking if a double-precision floating-point value is not less than or equal to another
XTEST_CASE(assume_case_double_not_less_equal) {
    double actual = 3.14159;
    double expected = 2.0;

    TEST_ASSUME_DOUBLE_LESS_EQUAL(actual, expected); // Should fail
}

// Test case for checking if a double-precision floating-point value is not infinity
XTEST_CASE(assume_case_double_not_inf) {
    double value = 3.14159;

    TEST_ASSUME_DOUBLE_IS_NOT_INF(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is infinity
XTEST_CASE(assume_case_double_inf) {
    double value = INFINITY;

    TEST_ASSUME_DOUBLE_IS_INF(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is not negative infinity
XTEST_CASE(assume_case_double_not_neg_inf) {
    double value = 3.14159;

    TEST_ASSUME_DOUBLE_IS_NOT_NEG_INF(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is negative infinity
XTEST_CASE(assume_case_double_neg_inf) {
    double value = -INFINITY;

    TEST_ASSUME_DOUBLE_IS_NEG_INF(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is finite
XTEST_CASE(assume_case_double_finite) {
    double value = 3.14159;

    TEST_ASSUME_DOUBLE_IS_FINITE(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is not finite
XTEST_CASE(assume_case_double_not_finite) {
    double value = INFINITY;

    TEST_ASSUME_DOUBLE_IS_NOT_FINITE(value); // Should fail
}

// Test case for checking if a double-precision floating-point value is not NaN
XTEST_CASE(assume_case_double_not_nan) {
    double value = 3.14159;

    TEST_ASSUME_DOUBLE_IS_NOT_NAN(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is NaN
XTEST_CASE(assume_case_double_nan) {
    double value = NAN;

    TEST_ASSUME_DOUBLE_IS_NAN(value); // Should pass
}

// Test case for checking if a double-precision floating-point value is deterministic (not NaN or inf)
XTEST_CASE(assume_case_double_is_determinate) {
    double actual = 3.14159;

    TEST_ASSUME_DOUBLE_IS_DETERMINATE(actual); // Should pass
}

// Test case for checking if a double-precision floating-point value is not deterministic (NaN or inf)
XTEST_CASE(assume_case_double_is_not_determinate) {
    double value = INFINITY;

    TEST_ASSUME_DOUBLE_IS_NOT_DETERMINATE(value); // Should fail
}

// Test case for checking if a pointer is NULL
XTEST_CASE(assume_case_null_ptr) {
    void* pointer = NULL;

    TEST_ASSUME_CNULLPTR(pointer); // Should pass
}

// Test case for checking if a pointer is not NULL
XTEST_CASE(assume_case_not_null_ptr) {
    void* pointer = (void*)12345;

    TEST_ASSUME_NOT_CNULLPTR(pointer); // Should pass
}

// Test case for checking if a pointer is invalid (not NULL)
XTEST_CASE(assume_case_invalid_ptr) {
    void* pointer = (void*)12345;

    TEST_ASSUME_INVALID_PTR(pointer); // Should fail
}

// Test case for checking if a pointer is empty (NULL)
XTEST_CASE(assume_case_empty_ptr) {
    void* pointer = NULL;

    TEST_ASSUME_EMPTY_PTR(pointer); // Should pass
}

// Test case for checking if a pointer is not empty (not NULL)
XTEST_CASE(assume_case_not_empty_ptr) {
    void* pointer = (void*)12345;

    TEST_ASSUME_NOT_EMPTY_PTR(pointer); // Should fail
}

// Test case for checking if a pointer is a valid memory access
XTEST_CASE(assume_case_valid_memory_access_ptr) {
    void* pointer = (void*)12345;

    TEST_ASSUME_INVALID_MEMORY_ACCESS_PTR(pointer); // Should fail
}

// Test case for checking if an array index is within bounds
XTEST_CASE(assume_case_array_bounds_ptr) {
    int arr[] = {1, 2, 3, 4, 5};
    int index = 3;
    int size = 5;

    TEST_ASSUME_ARRAY_BOUNDS_PTR(arr, index, size); // Should pass
    (void)arr;
}

// Test case for checking if two pointers are equal
XTEST_CASE(assume_case_equal_ptr) {
    void* pointer1 = (void*)12345;
    void* pointer2 = pointer1;

    TEST_ASSUME_EQUAL_PTR(pointer1, pointer2); // Should pass
}

// Test case for checking if two pointers are not equal
XTEST_CASE(assume_case_not_equal_ptr) {
    void* pointer1 = (void*)12345;
    void* pointer2 = (void*)54321;

    TEST_ASSUME_NOT_EQUAL_PTR(pointer1, pointer2); // Should pass
}

// Test case for checking if one pointer is less than another
XTEST_CASE(assume_case_less_ptr) {
    void* pointer1 = (void*)12345;
    void* pointer2 = (void*)54321;

    TEST_ASSUME_LESS_PTR(pointer1, pointer2); // Should pass
}

// Test case for checking if one pointer is greater than another
XTEST_CASE(assume_case_greater_ptr) {
    void* pointer1 = (void*)54321;
    void* pointer2 = (void*)12345;

    TEST_ASSUME_GREATER_PTR(pointer1, pointer2); // Should pass
}

// Test case for checking if one pointer is less than or equal to another
XTEST_CASE(assume_case_less_equal_ptr) {
    void* pointer1 = (void*)12345;
    void* pointer2 = (void*)54321;

    TEST_ASSUME_LESS_EQUAL_PTR(pointer1, pointer2); // Should pass
}

// Test case for checking if one pointer is greater than or equal to another
XTEST_CASE(assume_case_greater_equal_ptr) {
    void* pointer1 = (void*)54321;
    void* pointer2 = (void*)12345;

    TEST_ASSUME_GREATER_EQUAL_PTR(pointer1, pointer2); // Should pass
}

// Test case for checking if two strings are equal
XTEST_CASE(assume_case_equal_string) {
    const char* actual = "Hello, World!";
    const char* expected = "Hello, World!";

    TEST_ASSUME_EQUAL_STRING(actual, expected); // Should pass
}

// Test case for checking if two strings are not equal
XTEST_CASE(assume_case_not_equal_string) {
    const char* actual = "Hello, World!";
    const char* expected = "Hello, OpenAI!";

    TEST_ASSUME_NOT_EQUAL_STRING(actual, expected); // Should pass
}

// Test case for checking the length of a string
XTEST_CASE(assume_case_length_string) {
    const char* actual = "Hello, World!";
    size_t expected = 13;

    TEST_ASSUME_LENGTH_STRING(actual, expected); // Should pass
}

// Test case for checking if a string contains a substring
XTEST_CASE(assume_case_contains_substring_string) {
    const char* string = "Hello, World!";
    const char* substring = "World";

    TEST_ASSUME_CONTAINS_SUBSTRING_STRING(string, substring); // Should pass
}

// Test case for checking if a string does not contain a substring
XTEST_CASE(assume_case_not_contains_substring_string) {
    const char* string = "Hello, World!";
    const char* substring = "OpenAI";

    TEST_ASSUME_NOT_CONTAINS_SUBSTRING_STRING(string, substring); // Should pass
}

// Test case for checking if a string starts with a prefix
XTEST_CASE(assume_case_starts_with_string) {
    const char* string = "Hello, World!";
    const char* prefix = "Hello";

    TEST_ASSUME_STARTS_WITH_STRING(string, prefix); // Should pass
}

// Test case for checking if a string ends with a suffix
XTEST_CASE(assume_case_ends_with_string) {
    const char* string = "Hello, World!";
    const char* suffix = "World!";

    TEST_ASSUME_ENDS_WITH_STRING(string, suffix); // Should pass
}

// Test case for checking if two strings are equal in a case-insensitive manner
XTEST_CASE(assume_case_equal_case_insensitive_string) {
    const char* actual = "Hello, World!";
    const char* expected = "hello, World!";

    TEST_ASSUME_EQUAL_CASE_INSENSITIVE_STRING(actual, expected); // Should pass
}

// Test case for checking if two strings are not equal in a case-insensitive manner
XTEST_CASE(assume_case_not_equal_case_insensitive_string) {
    const char* actual = "Hello, World!";
    const char* expected = "OpenAI, World!";

    TEST_ASSUME_NOT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected); // Should pass
}

// Test case for checking if two characters are equal
XTEST_CASE(assume_case_equal_char) {
    char actual = 'A';
    char expected = 'A';

    TEST_ASSUME_EQUAL_CHAR(actual, expected); // Should pass
}

// Test case for checking if two characters are not equal
XTEST_CASE(assume_case_not_equal_char) {
    char actual = 'A';
    char expected = 'B';

    TEST_ASSUME_NOT_EQUAL_CHAR(actual, expected); // Should pass
}

// Test case for checking if a character is less than another character
XTEST_CASE(assume_case_less_char) {
    char actual = 'A';
    char expected = 'B';

    TEST_ASSUME_LESS_CHAR(actual, expected); // Should pass
}

// Test case for checking if a character is greater than another character
XTEST_CASE(assume_case_greater_char) {
    char actual = 'B';
    char expected = 'A';

    TEST_ASSUME_GREATER_CHAR(actual, expected); // Should pass
}

// Test case for checking if a character is less than or equal to another character
XTEST_CASE(assume_case_less_equal_char) {
    char actual = 'A';
    char expected = 'A';

    TEST_ASSUME_LESS_EQUAL_CHAR(actual, expected); // Should pass
}

// Test case for checking if a character is greater than or equal to another character
XTEST_CASE(assume_case_greater_equal_char) {
    char actual = 'B';
    char expected = 'A';

    TEST_ASSUME_GREATER_EQUAL_CHAR(actual, expected); // Should pass
}

// Test case for checking if a character is in a specified range
XTEST_CASE(assume_case_in_range_char) {
    char character = 'C';
    char min = 'A';
    char max = 'Z';

    TEST_ASSUME_IN_RANGE_CHAR(character, min, max); // Should pass
}

// Test case for checking if a character is uppercase
XTEST_CASE(assume_case_is_uppercase_char) {
    char character = 'A';

    TEST_ASSUME_IS_UPPERCASE_CHAR(character); // Should pass
}

// Test case for checking if a character is lowercase
XTEST_CASE(assume_case_is_lowercase_char) {
    char character = 'a';

    TEST_ASSUME_IS_LOWERCASE_CHAR(character); // Should pass
}

// Test case for converting a character to uppercase
XTEST_CASE(assume_case_to_upper_char) {
    char character = 'a';
    char expected = 'A';

    TEST_ASSUME_TO_UPPER_CHAR(character, expected); // Should pass
}

// Test case for converting a character to lowercase
XTEST_CASE(assume_case_to_lower_char) {
    char character = 'A';
    char expected = 'a';

    TEST_ASSUME_TO_LOWER_CHAR(character, expected); // Should pass
}

// Test case for checking if two wide characters are equal
XTEST_CASE(assume_case_equal_wchar) {
    wchar_t actual = L'A';
    wchar_t expected = L'A';

    TEST_ASSUME_EQUAL_WCHAR(actual, expected); // Should pass
}

// Test case for checking if two wide characters are not equal
XTEST_CASE(assume_case_not_equal_wchar) {
    wchar_t actual = L'A';
    wchar_t expected = L'B';

    TEST_ASSUME_NOT_EQUAL_WCHAR(actual, expected); // Should pass
}

// Test case for checking if a wide character is less than another wide character
XTEST_CASE(assume_case_less_wchar) {
    wchar_t actual = L'A';
    wchar_t expected = L'B';

    TEST_ASSUME_LESS_WCHAR(actual, expected); // Should pass
}

// Test case for checking if a wide character is greater than another wide character
XTEST_CASE(assume_case_greater_wchar) {
    wchar_t actual = L'B';
    wchar_t expected = L'A';

    TEST_ASSUME_GREATER_WCHAR(actual, expected); // Should pass
}

// Test case for checking if a wide character is less than or equal to another wide character
XTEST_CASE(assume_case_less_equal_wchar) {
    wchar_t actual = L'A';
    wchar_t expected = L'A';

    TEST_ASSUME_LESS_EQUAL_WCHAR(actual, expected); // Should pass
}

// Test case for checking if a wide character is greater than or equal to another wide character
XTEST_CASE(assume_case_greater_equal_wchar) {
    wchar_t actual = L'B';
    wchar_t expected = L'A';

    TEST_ASSUME_GREATER_EQUAL_WCHAR(actual, expected); // Should pass
}

// Test case for checking if a wide character is in a specified range
XTEST_CASE(assume_case_in_range_wchar) {
    wchar_t character = L'C';
    wchar_t min = L'A';
    wchar_t max = L'Z';

    TEST_ASSUME_IN_RANGE_WCHAR(character, min, max); // Should pass
}

// Test case for checking if a wide character is uppercase
XTEST_CASE(assume_case_is_uppercase_wchar) {
    wchar_t character = L'A';

    TEST_ASSUME_IS_UPPERCASE_WCHAR(character); // Should pass
}

// Test case for checking if a wide character is lowercase
XTEST_CASE(assume_case_is_lowercase_wchar) {
    wchar_t character = L'a';

    TEST_ASSUME_IS_LOWERCASE_WCHAR(character); // Should pass
}

// Test case for converting a wide character to uppercase
XTEST_CASE(assume_case_to_upper_wchar) {
    wchar_t character = L'a';
    wchar_t expected = L'A';

    TEST_ASSUME_TO_UPPER_WCHAR(character, expected); // Should pass
}

// Test case for converting a wide character to lowercase
XTEST_CASE(assume_case_to_lower_wchar) {
    wchar_t character = L'A';
    wchar_t expected = L'a';

    TEST_ASSUME_TO_LOWER_WCHAR(character, expected); // Should pass
}

// Test case for opening a file
XTEST_CASE(assume_case_open_file) {
    FILE* file = fopen("example.txt", "r");
    TEST_ASSUME_OPEN_FILE(file); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

// Test case for reading from a file
XTEST_CASE(assume_case_read_file) {
    FILE* file = fopen("example.txt", "r");
    char buffer[100];
    size_t size = 10;

    TEST_ASSUME_OPEN_FILE(file); // Open the file
    TEST_ASSUME_READ_FILE(file, buffer, size); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

// Test case for writing to a file
XTEST_CASE(assume_case_write_file) {
    FILE* file = fopen("output.txt", "w");
    char data[] = "Hello, World!";
    size_t size = strlen(data);

    TEST_ASSUME_OPEN_FILE(file); // Open the file
    TEST_ASSUME_WRITE_FILE(file, data, size); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

// Test case for seeking within a file
XTEST_CASE(assume_case_seek_file) {
    FILE* file = fopen("example.txt", "r");
    
    TEST_ASSUME_OPEN_FILE(file); // Open the file
    TEST_ASSUME_SEEK_FILE(file, 5, SEEK_SET); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

// Test case for getting the file position
XTEST_CASE(assume_case_tell_file) {
    FILE* file = fopen("example.txt", "r");
    
    TEST_ASSUME_OPEN_FILE(file); // Open the file
    TEST_ASSUME_TELL_FILE(file); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

// Test case for checking the end of a file
XTEST_CASE(assume_case_eof_file) {
    FILE* file = fopen("example.txt", "r");

    TEST_ASSUME_OPEN_FILE(file); // Open the file
    TEST_ASSUME_EOF_FILE(file); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

// Test case for checking file operations with no errors
XTEST_CASE(assume_case_file_no_error) {
    FILE* file = fopen("example.txt", "r");

    TEST_ASSUME_OPEN_FILE(file); // Open the file
    // Perform some file operations...
    TEST_ASSUME_FILE_NO_ERROR(file); // Should pass
    TEST_ASSUME_CLOSE_FILE(file); // Close the file
}

//
// LOCAL TEST GROUP
//
XTEST_DEFINE_POOL(xassume_test_group) {
    XTEST_RUN_UNIT(assume_case_boolean_equality);
    XTEST_RUN_UNIT(assume_case_boolean_false);
    XTEST_RUN_UNIT(assume_case_boolean_greater_than);
    XTEST_RUN_UNIT(assume_case_boolean_inequality);
    XTEST_RUN_UNIT(assume_case_boolean_message);
    XTEST_RUN_UNIT(assume_case_boolean_true);
    XTEST_RUN_UNIT(assume_case_boolean_unless);
    XTEST_RUN_UNIT(assume_case_memory_contains);
    XTEST_RUN_UNIT(assume_case_memory_copied);
    XTEST_RUN_UNIT(assume_case_memory_equality);
    XTEST_RUN_UNIT(assume_case_memory_inequality);
    XTEST_RUN_UNIT(assume_case_memory_not_contains);

    XTEST_RUN_UNIT(assume_case_enum_equality);
    XTEST_RUN_UNIT(assume_case_enum_greater_than);
    XTEST_RUN_UNIT(assume_case_enum_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_enum_inequality);
    XTEST_RUN_UNIT(assume_case_enum_less_than);
    XTEST_RUN_UNIT(assume_case_enum_less_than_or_equal);

    XTEST_RUN_UNIT(assume_case_int_equality);
    XTEST_RUN_UNIT(assume_case_int_greater_than);
    XTEST_RUN_UNIT(assume_case_int_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int_inequality);
    XTEST_RUN_UNIT(assume_case_int_less_than);
    XTEST_RUN_UNIT(assume_case_int_less_than_or_equal);

    XTEST_RUN_UNIT(assume_case_int8_equality);
    XTEST_RUN_UNIT(assume_case_int8_greater_than);
    XTEST_RUN_UNIT(assume_case_int8_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int8_inequality);
    XTEST_RUN_UNIT(assume_case_int8_less_than);
    XTEST_RUN_UNIT(assume_case_int8_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int16_equality);
    XTEST_RUN_UNIT(assume_case_int16_greater_than);
    XTEST_RUN_UNIT(assume_case_int16_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int16_inequality);
    XTEST_RUN_UNIT(assume_case_int16_less_than);
    XTEST_RUN_UNIT(assume_case_int16_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int32_equality);
    XTEST_RUN_UNIT(assume_case_int32_greater_than);
    XTEST_RUN_UNIT(assume_case_int32_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int32_inequality);
    XTEST_RUN_UNIT(assume_case_int32_less_than);
    XTEST_RUN_UNIT(assume_case_int32_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int64_equality);
    XTEST_RUN_UNIT(assume_case_int64_greater_than);
    XTEST_RUN_UNIT(assume_case_int64_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_int64_inequality);
    XTEST_RUN_UNIT(assume_case_int64_less_than);
    XTEST_RUN_UNIT(assume_case_int64_less_than_or_equal);

    XTEST_RUN_UNIT(assume_case_uint8_equality);
    XTEST_RUN_UNIT(assume_case_uint8_greater_than);
    XTEST_RUN_UNIT(assume_case_uint8_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint8_inequality);
    XTEST_RUN_UNIT(assume_case_uint8_less_than);
    XTEST_RUN_UNIT(assume_case_uint8_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint16_equality);
    XTEST_RUN_UNIT(assume_case_uint16_greater_than);
    XTEST_RUN_UNIT(assume_case_uint16_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint16_inequality);
    XTEST_RUN_UNIT(assume_case_uint16_less_than);
    XTEST_RUN_UNIT(assume_case_uint16_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint32_equality);
    XTEST_RUN_UNIT(assume_case_uint32_greater_than);
    XTEST_RUN_UNIT(assume_case_uint32_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint32_inequality);
    XTEST_RUN_UNIT(assume_case_uint32_less_than);
    XTEST_RUN_UNIT(assume_case_uint32_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint64_equality);
    XTEST_RUN_UNIT(assume_case_uint64_greater_than);
    XTEST_RUN_UNIT(assume_case_uint64_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_uint64_inequality);
    XTEST_RUN_UNIT(assume_case_uint64_less_than);
    XTEST_RUN_UNIT(assume_case_uint64_less_than_or_equal);

    XTEST_RUN_UNIT(assume_case_hex8_equality);
    XTEST_RUN_UNIT(assume_case_hex8_greater_than);
    XTEST_RUN_UNIT(assume_case_hex8_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex8_inequality);
    XTEST_RUN_UNIT(assume_case_hex8_less_than);
    XTEST_RUN_UNIT(assume_case_hex8_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex16_equality);
    XTEST_RUN_UNIT(assume_case_hex16_greater_than);
    XTEST_RUN_UNIT(assume_case_hex16_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex16_inequality);
    XTEST_RUN_UNIT(assume_case_hex16_less_than);
    XTEST_RUN_UNIT(assume_case_hex16_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex32_equality);
    XTEST_RUN_UNIT(assume_case_hex32_greater_than);
    XTEST_RUN_UNIT(assume_case_hex32_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex32_inequality);
    XTEST_RUN_UNIT(assume_case_hex32_less_than);
    XTEST_RUN_UNIT(assume_case_hex32_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex64_equality);
    XTEST_RUN_UNIT(assume_case_hex64_greater_than);
    XTEST_RUN_UNIT(assume_case_hex64_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_hex64_inequality);
    XTEST_RUN_UNIT(assume_case_hex64_less_than);
    XTEST_RUN_UNIT(assume_case_hex64_less_than_or_equal);

    XTEST_RUN_UNIT(assume_case_oct_equality);
    XTEST_RUN_UNIT(assume_case_oct_greater_than);
    XTEST_RUN_UNIT(assume_case_oct_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_oct_inequality);
    XTEST_RUN_UNIT(assume_case_oct_less_than);
    XTEST_RUN_UNIT(assume_case_oct_less_than_or_equal);

    XTEST_RUN_UNIT(assume_case_bit_equality);
    XTEST_RUN_UNIT(assume_case_bit_greater_than);
    XTEST_RUN_UNIT(assume_case_bit_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_bit_high);
    XTEST_RUN_UNIT(assume_case_bit_inequality);
    XTEST_RUN_UNIT(assume_case_bit_less_than);
    XTEST_RUN_UNIT(assume_case_bit_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_bit_low);
    XTEST_RUN_UNIT(assume_case_bit_not_high);
    XTEST_RUN_UNIT(assume_case_bit_not_low);
    XTEST_RUN_UNIT(assume_case_bits_equal);
    XTEST_RUN_UNIT(assume_case_bits_greater_than);
    XTEST_RUN_UNIT(assume_case_bits_greater_than_or_equal);
    XTEST_RUN_UNIT(assume_case_bits_high);
    XTEST_RUN_UNIT(assume_case_bits_less_than);
    XTEST_RUN_UNIT(assume_case_bits_less_than_or_equal);
    XTEST_RUN_UNIT(assume_case_bits_low);
    XTEST_RUN_UNIT(assume_case_bits_not_equal);
    XTEST_RUN_UNIT(assume_case_bits_not_high);
    XTEST_RUN_UNIT(assume_case_bits_not_low);

    XTEST_RUN_UNIT(assume_case_int_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int8_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int8_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int16_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int16_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int32_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int32_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int64_within_tolerance);
    XTEST_RUN_UNIT(assume_case_int64_not_within_tolerance);

    XTEST_RUN_UNIT(assume_case_uint_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint8_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint8_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint16_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint16_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint32_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint32_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint64_within_tolerance);
    XTEST_RUN_UNIT(assume_case_uint64_not_within_tolerance);

    XTEST_RUN_UNIT(assume_case_hex_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex8_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex8_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex16_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex16_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex32_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex32_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex64_within_tolerance);
    XTEST_RUN_UNIT(assume_case_hex64_not_within_tolerance);

    XTEST_RUN_UNIT(assume_case_bin_within_tolerance);
    XTEST_RUN_UNIT(assume_case_bin_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_oct_within_tolerance);
    XTEST_RUN_UNIT(assume_case_oct_not_within_tolerance);
    XTEST_RUN_UNIT(assume_case_float_within_epsilon);
    XTEST_RUN_UNIT(assume_case_float_not_within_epsilon);
    XTEST_RUN_UNIT(assume_case_double_within_epsilon);
    XTEST_RUN_UNIT(assume_case_double_not_within_epsilon);
    XTEST_RUN_UNIT(assume_case_char_within_range);
    XTEST_RUN_UNIT(assume_case_char_not_within_range);
    XTEST_RUN_UNIT(assume_case_wchar_within_range);
    XTEST_RUN_UNIT(assume_case_wchar_not_within_range);

    XTEST_RUN_UNIT(assume_case_float_equal);
    XTEST_RUN_UNIT(assume_case_float_finite);
    XTEST_RUN_UNIT(assume_case_float_greater);
    XTEST_RUN_UNIT(assume_case_float_greater_equal);
    XTEST_RUN_UNIT(assume_case_float_inf);
    XTEST_RUN_UNIT(assume_case_float_is_determinate);
    XTEST_RUN_UNIT(assume_case_float_is_not_determinate);
    XTEST_RUN_UNIT(assume_case_float_less);
    XTEST_RUN_UNIT(assume_case_float_less_equal);
    XTEST_RUN_UNIT(assume_case_float_nan);
    XTEST_RUN_UNIT(assume_case_float_neg_inf);
    XTEST_RUN_UNIT(assume_case_float_not_equal);
    XTEST_RUN_UNIT(assume_case_float_not_greater);
    XTEST_RUN_UNIT(assume_case_float_not_finite);
    XTEST_RUN_UNIT(assume_case_float_not_greater_equal);
    XTEST_RUN_UNIT(assume_case_float_not_inf);
    XTEST_RUN_UNIT(assume_case_float_not_less);
    XTEST_RUN_UNIT(assume_case_float_not_less_equal);
    XTEST_RUN_UNIT(assume_case_float_not_nan);
    XTEST_RUN_UNIT(assume_case_float_not_neg_inf);

    XTEST_RUN_UNIT(assume_case_double_equal);
    XTEST_RUN_UNIT(assume_case_double_finite);
    XTEST_RUN_UNIT(assume_case_double_greater);
    XTEST_RUN_UNIT(assume_case_double_greater_equal);
    XTEST_RUN_UNIT(assume_case_double_inf);
    XTEST_RUN_UNIT(assume_case_double_is_determinate);
    XTEST_RUN_UNIT(assume_case_double_is_not_determinate);
    XTEST_RUN_UNIT(assume_case_double_less);
    XTEST_RUN_UNIT(assume_case_double_less_equal);
    XTEST_RUN_UNIT(assume_case_double_nan);
    XTEST_RUN_UNIT(assume_case_double_neg_inf);
    XTEST_RUN_UNIT(assume_case_double_not_equal);
    XTEST_RUN_UNIT(assume_case_double_not_greater);
    XTEST_RUN_UNIT(assume_case_double_not_finite);
    XTEST_RUN_UNIT(assume_case_double_not_greater_equal);
    XTEST_RUN_UNIT(assume_case_double_not_inf);
    XTEST_RUN_UNIT(assume_case_double_not_less);
    XTEST_RUN_UNIT(assume_case_double_not_less_equal);
    XTEST_RUN_UNIT(assume_case_double_not_nan);
    XTEST_RUN_UNIT(assume_case_double_not_neg_inf);

    XTEST_RUN_UNIT(assume_case_null_ptr);
    XTEST_RUN_UNIT(assume_case_not_null_ptr);
    XTEST_RUN_UNIT(assume_case_invalid_ptr);
    XTEST_RUN_UNIT(assume_case_empty_ptr);
    XTEST_RUN_UNIT(assume_case_not_empty_ptr);
    XTEST_RUN_UNIT(assume_case_valid_memory_access_ptr);
    XTEST_RUN_UNIT(assume_case_array_bounds_ptr);
    XTEST_RUN_UNIT(assume_case_equal_ptr);
    XTEST_RUN_UNIT(assume_case_not_equal_ptr);
    XTEST_RUN_UNIT(assume_case_less_equal_ptr);
    XTEST_RUN_UNIT(assume_case_less_ptr);
    XTEST_RUN_UNIT(assume_case_greater_ptr);
    XTEST_RUN_UNIT(assume_case_greater_equal_ptr);

    XTEST_RUN_UNIT(assume_case_equal_string);
    XTEST_RUN_UNIT(assume_case_not_equal_string);
    XTEST_RUN_UNIT(assume_case_length_string);
    XTEST_RUN_UNIT(assume_case_contains_substring_string);
    XTEST_RUN_UNIT(assume_case_not_contains_substring_string);
    XTEST_RUN_UNIT(assume_case_starts_with_string);
    XTEST_RUN_UNIT(assume_case_ends_with_string);
    XTEST_RUN_UNIT(assume_case_equal_case_insensitive_string);
    XTEST_RUN_UNIT(assume_case_not_equal_case_insensitive_string);

    XTEST_RUN_UNIT(assume_case_equal_char);
    XTEST_RUN_UNIT(assume_case_not_equal_char);
    XTEST_RUN_UNIT(assume_case_less_char);
    XTEST_RUN_UNIT(assume_case_greater_char);
    XTEST_RUN_UNIT(assume_case_less_equal_char);
    XTEST_RUN_UNIT(assume_case_greater_equal_char);
    XTEST_RUN_UNIT(assume_case_in_range_char);
    XTEST_RUN_UNIT(assume_case_is_uppercase_char);
    XTEST_RUN_UNIT(assume_case_is_lowercase_char);
    XTEST_RUN_UNIT(assume_case_to_upper_char);
    XTEST_RUN_UNIT(assume_case_to_lower_char);
    XTEST_RUN_UNIT(assume_case_equal_wchar);
    XTEST_RUN_UNIT(assume_case_not_equal_wchar);
    XTEST_RUN_UNIT(assume_case_less_wchar);
    XTEST_RUN_UNIT(assume_case_greater_wchar);
    XTEST_RUN_UNIT(assume_case_less_equal_wchar);
    XTEST_RUN_UNIT(assume_case_greater_equal_wchar);
    XTEST_RUN_UNIT(assume_case_in_range_wchar);
    XTEST_RUN_UNIT(assume_case_is_uppercase_wchar);
    XTEST_RUN_UNIT(assume_case_is_lowercase_wchar);
    XTEST_RUN_UNIT(assume_case_to_upper_wchar);
    XTEST_RUN_UNIT(assume_case_to_lower_wchar);

    XTEST_RUN_UNIT(assume_case_open_file);
    XTEST_RUN_UNIT(assume_case_read_file);
    XTEST_RUN_UNIT(assume_case_write_file);
    XTEST_RUN_UNIT(assume_case_seek_file);
    XTEST_RUN_UNIT(assume_case_tell_file);
    XTEST_RUN_UNIT(assume_case_eof_file);
    XTEST_RUN_UNIT(assume_case_file_no_error);
} // end of group
