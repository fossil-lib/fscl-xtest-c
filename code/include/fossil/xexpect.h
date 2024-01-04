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
#ifndef FSCL_EXPECT_H
#define FSCL_EXPECT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

#ifdef __cplusplus
// If compiled as C++, include the C++ version of the libraries
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <cwctype>
#include <cwchar>
#include <cctype>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#else
// If compiled as C, include the C version of the libraries
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <wctype.h>
#include <wchar.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#endif

#define EXPECT_FLOAT_EPSILON 1e-6 // Define your desired epsilon value
#define EXPECT_DOUBLE_EPSILON 1e-9 // Define your desired epsilon value

// ----------------------------------------------------------------
// Memory assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL_MEMORY(actual, expected, size)     TEST_EXPECT(memcmp(actual, expected, size) != 0, "Expectation for memory equality not met")
#define TEST_EXPECT_NOT_EQUAL_MEMORY(actual, expected, size) TEST_EXPECT(memcmp(actual, expected, size) == 0, "Expectation for memory inequality not met")
#define TEST_EXPECT_CONTAINS_MEMORY(haystack, needle, haystackSize, needleSize) \
bool found = false; \
for (size_t i = 0; i <= (haystackSize - needleSize); i++) { \
    if (memcmp(haystack + i, needle, needleSize) == 0) { \
        found = true; \
        break; \
    } \
} \
TEST_EXPECT(!found, "Memory contains assertion failed");

#define TEST_EXPECT_NOT_CONTAINS_MEMORY(haystack, needle, haystackSize, needleSize) \
bool found = false; \
for (size_t i = 0; i <= (haystackSize - needleSize); i++) { \
    if (memcmp(haystack + i, needle, needleSize) == 0) { \
        found = true; \
        break; \
    } \
} \
TEST_EXPECT(found, "Memory not contains assertion failed");

#define TEST_EXPECT_COPIED_MEMORY(dest, source, size)     TEST_EXPECT((memcmp(dest, source, size) == 0), "Memory copy check failed");
#define TEST_EXPECT_NOT_COPIED_MEMORY(dest, source, size) TEST_EXPECT((memcmp(dest, source, size) != 0), "Memory not copied check failed");

// ----------------------------------------------------------------
// Boolean assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL(actual, expected)     TEST_EXPECT((bool)(actual) == (bool)(expected), "Expectation for equality not met")
#define TEST_EXPECT_NOT_EQUAL(actual, expected) TEST_EXPECT((bool)(actual) != (bool)(expected), "Expectation for inequality not met")
#define TEST_EXPECT_LESS(actual, expected)      TEST_EXPECT((bool)(actual) <  (bool)(expected), "Expectation for less than not met")
#define TEST_EXPECT_GREATER(actual, expected)   TEST_EXPECT((bool)(actual) >  (bool)(expected), "Expectation for greater than not met")
#define TEST_EXPECT_UNLESS(expression)          TEST_EXPECT((expression), "Expectation not met")
#define TEST_EXPECT_TRUE(expression)            TEST_EXPECT((expression), "Expectation for true not met")
#define TEST_EXPECT_FALSE(expression)           TEST_EXPECT(!(expression), "Expectation for false not met")
#define TEST_EXPECT_MSG(expression, message)    TEST_EXPECT(!(expression), message)

#define TEST_EXPECT_EQUAL_BOOL(actual, expected)     TEST_EXPECT((bool)(actual) == (bool)(expected), "Expectation for equality not met")
#define TEST_EXPECT_NOT_EQUAL_BOOL(actual, expected) TEST_EXPECT((bool)(actual) != (bool)(expected), "Expectation for inequality not met")
#define TEST_EXPECT_LESS_BOOL(actual, expected)      TEST_EXPECT((bool)(actual) <  (bool)(expected), "Expectation for less than not met")
#define TEST_EXPECT_GREATER_BOOL(actual, expected)   TEST_EXPECT((bool)(actual) >  (bool)(expected), "Expectation for greater than not met")
#define TEST_EXPECT_UNLESS_BOOL(expression)          TEST_EXPECT((expression), "Expectation not met")
#define TEST_EXPECT_TRUE_BOOL(expression)            TEST_EXPECT((expression), "Expectation for true not met")
#define TEST_EXPECT_FALSE_BOOL(expression)           TEST_EXPECT(!(expression), "Expectation for false not met")
#define TEST_EXPECT_MSG_BOOL(expression, message)    TEST_EXPECT(!(expression), message)

// ----------------------------------------------------------------
// Enum assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL_ENUM(actual, expected)         TEST_EXPECT((actual) == (expected), "Enum equality check failed")
#define TEST_EXPECT_NOT_EQUAL_ENUM(actual, expected)     TEST_EXPECT((actual) != (expected), "Enum inequality check failed")
#define TEST_EXPECT_LESS_ENUM(actual, expected)          TEST_EXPECT((actual) <  (expected), "Enum less-than check failed")
#define TEST_EXPECT_GREATER_ENUM(actual, expected)       TEST_EXPECT((actual) >  (expected), "Enum greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_ENUM(actual, expected)    TEST_EXPECT((actual) <= (expected), "Enum less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_ENUM(actual, expected) TEST_EXPECT((actual) >= (expected), "Enum greater-than-or-equal check failed")

// ----------------------------------------------------------------
// Integer assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL_INT(actual, expected)         TEST_EXPECT((signed)(actual) == (signed)(expected), "Integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_INT(actual, expected)     TEST_EXPECT((signed)(actual) != (signed)(expected), "Integer inequality check failed")
#define TEST_EXPECT_LESS_INT(actual, expected)          TEST_EXPECT((signed)(actual) <  (signed)(expected), "Integer less-than check failed")
#define TEST_EXPECT_GREATER_INT(actual, expected)       TEST_EXPECT((signed)(actual) >  (signed)(expected), "Integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_INT(actual, expected)    TEST_EXPECT((signed)(actual) <= (signed)(expected), "Integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_INT(actual, expected) TEST_EXPECT((signed)(actual) >= (signed)(expected), "Integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_INT8(actual, expected)         TEST_EXPECT((int8_t)(actual) == (int8_t)(expected), "8-bit Integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_INT8(actual, expected)     TEST_EXPECT((int8_t)(actual) != (int8_t)(expected), "8-bit Integer inequality check failed")
#define TEST_EXPECT_LESS_INT8(actual, expected)          TEST_EXPECT((int8_t)(actual) <  (int8_t)(expected), "8-bit Integer less-than check failed")
#define TEST_EXPECT_GREATER_INT8(actual, expected)       TEST_EXPECT((int8_t)(actual) >  (int8_t)(expected), "8-bit Integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_INT8(actual, expected)    TEST_EXPECT((int8_t)(actual) <= (int8_t)(expected), "8-bit Integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_INT8(actual, expected) TEST_EXPECT((int8_t)(actual) >= (int8_t)(expected), "8-bit Integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_INT16(actual, expected)         TEST_EXPECT((int16_t)(actual) == (int16_t)(expected), "16-bit Integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_INT16(actual, expected)     TEST_EXPECT((int16_t)(actual) != (int16_t)(expected), "16-bit Integer inequality check failed")
#define TEST_EXPECT_LESS_INT16(actual, expected)          TEST_EXPECT((int16_t)(actual) <  (int16_t)(expected), "16-bit Integer less-than check failed")
#define TEST_EXPECT_GREATER_INT16(actual, expected)       TEST_EXPECT((int16_t)(actual) >  (int16_t)(expected), "16-bit Integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_INT16(actual, expected)    TEST_EXPECT((int16_t)(actual) <= (int16_t)(expected), "16-bit Integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_INT16(actual, expected) TEST_EXPECT((int16_t)(actual) >= (int16_t)(expected), "16-bit Integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_INT32(actual, expected)         TEST_EXPECT((int32_t)(actual) == (int32_t)(expected), "32-bit Integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_INT32(actual, expected)     TEST_EXPECT((int32_t)(actual) != (int32_t)(expected), "32-bit Integer inequality check failed")
#define TEST_EXPECT_LESS_INT32(actual, expected)          TEST_EXPECT((int32_t)(actual) <  (int32_t)(expected), "32-bit Integer less-than check failed")
#define TEST_EXPECT_GREATER_INT32(actual, expected)       TEST_EXPECT((int32_t)(actual) >  (int32_t)(expected), "32-bit Integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_INT32(actual, expected)    TEST_EXPECT((int32_t)(actual) <= (int32_t)(expected), "32-bit Integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_INT32(actual, expected) TEST_EXPECT((int32_t)(actual) >= (int32_t)(expected), "32-bit Integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_INT64(actual, expected)         TEST_EXPECT((int64_t)(actual) == (int64_t)(expected), "64-bit Integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_INT64(actual, expected)     TEST_EXPECT((int64_t)(actual) != (int64_t)(expected), "64-bit Integer inequality check failed")
#define TEST_EXPECT_LESS_INT64(actual, expected)          TEST_EXPECT((int64_t)(actual) <  (int64_t)(expected), "64-bit Integer less-than check failed")
#define TEST_EXPECT_GREATER_INT64(actual, expected)       TEST_EXPECT((int64_t)(actual) >  (int64_t)(expected), "64-bit Integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_INT64(actual, expected)    TEST_EXPECT((int64_t)(actual) <= (int64_t)(expected), "64-bit Integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_INT64(actual, expected) TEST_EXPECT((int64_t)(actual) >= (int64_t)(expected), "64-bit Integer greater-than-or-equal check failed")

// ----------------------------------------------------------------
// Unsinged Integer assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL_UINT(actual, expected)         TEST_EXPECT((unsigned)(actual) == (unsigned)(expected), "Unsigned integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_UINT(actual, expected)     TEST_EXPECT((unsigned)(actual) != (unsigned)(expected), "Unsigned integer inequality check failed")
#define TEST_EXPECT_LESS_UINT(actual, expected)          TEST_EXPECT((unsigned)(actual) <  (unsigned)(expected), "Unsigned integer less-than check failed")
#define TEST_EXPECT_GREATER_UINT(actual, expected)       TEST_EXPECT((unsigned)(actual) >  (unsigned)(expected), "Unsigned integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_UINT(actual, expected)    TEST_EXPECT((unsigned)(actual) <= (unsigned)(expected), "Unsigned integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_UINT(actual, expected) TEST_EXPECT((unsigned)(actual) >= (unsigned)(expected), "Unsigned integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_UINT8(actual, expected)         TEST_EXPECT((uint8_t)(actual) == (uint8_t)(expected), "8-bit Unsigned integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_UINT8(actual, expected)     TEST_EXPECT((uint8_t)(actual) != (uint8_t)(expected), "8-bit Unsigned integer inequality check failed")
#define TEST_EXPECT_LESS_UINT8(actual, expected)          TEST_EXPECT((uint8_t)(actual) <  (uint8_t)(expected), "8-bit Unsigned integer less-than check failed")
#define TEST_EXPECT_GREATER_UINT8(actual, expected)       TEST_EXPECT((uint8_t)(actual) >  (uint8_t)(expected), "8-bit Unsigned integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_UINT8(actual, expected)    TEST_EXPECT((uint8_t)(actual) <= (uint8_t)(expected), "8-bit Unsigned integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_UINT8(actual, expected) TEST_EXPECT((uint8_t)(actual) >= (uint8_t)(expected), "8-bit Unsigned integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_UINT16(actual, expected)         TEST_EXPECT((uint16_t)(actual) == (uint16_t)(expected), "16-bit Unsigned integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_UINT16(actual, expected)     TEST_EXPECT((uint16_t)(actual) != (uint16_t)(expected), "16-bit Unsigned integer inequality check failed")
#define TEST_EXPECT_LESS_UINT16(actual, expected)          TEST_EXPECT((uint16_t)(actual) <  (uint16_t)(expected), "16-bit Unsigned integer less-than check failed")
#define TEST_EXPECT_GREATER_UINT16(actual, expected)       TEST_EXPECT((uint16_t)(actual) >  (uint16_t)(expected), "16-bit Unsigned integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_UINT16(actual, expected)    TEST_EXPECT((uint16_t)(actual) <= (uint16_t)(expected), "16-bit Unsigned integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_UINT16(actual, expected) TEST_EXPECT((uint16_t)(actual) >= (uint16_t)(expected), "16-bit Unsigned integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_UINT32(actual, expected)         TEST_EXPECT((uint32_t)(actual) == (uint32_t)(expected), "32-bit Unsigned integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_UINT32(actual, expected)     TEST_EXPECT((uint32_t)(actual) != (uint32_t)(expected), "32-bit Unsigned integer inequality check failed")
#define TEST_EXPECT_LESS_UINT32(actual, expected)          TEST_EXPECT((uint32_t)(actual) <  (uint32_t)(expected), "32-bit Unsigned integer less-than check failed")
#define TEST_EXPECT_GREATER_UINT32(actual, expected)       TEST_EXPECT((uint32_t)(actual) >  (uint32_t)(expected), "32-bit Unsigned integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_UINT32(actual, expected)    TEST_EXPECT((uint32_t)(actual) <= (uint32_t)(expected), "32-bit Unsigned integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_UINT32(actual, expected) TEST_EXPECT((uint32_t)(actual) >= (uint32_t)(expected), "32-bit Unsigned integer greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_UINT64(actual, expected)         TEST_EXPECT((uint64_t)(actual) == (uint64_t)(expected), "64-bit Unsigned integer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_UINT64(actual, expected)     TEST_EXPECT((uint64_t)(actual) != (uint64_t)(expected), "64-bit Unsigned integer inequality check failed")
#define TEST_EXPECT_LESS_UINT64(actual, expected)          TEST_EXPECT((uint64_t)(actual) <  (uint64_t)(expected), "64-bit Unsigned integer less-than check failed")
#define TEST_EXPECT_GREATER_UINT64(actual, expected)       TEST_EXPECT((uint64_t)(actual) >  (uint64_t)(expected), "64-bit Unsigned integer greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_UINT64(actual, expected)    TEST_EXPECT((uint64_t)(actual) <= (uint64_t)(expected), "64-bit Unsigned integer less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_UINT64(actual, expected) TEST_EXPECT((uint64_t)(actual) >= (uint64_t)(expected), "64-bit Unsigned integer greater-than-or-equal check failed")

// ----------------------------------------------------------------
// Hex assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL_HEX(actual, expected)         TEST_EXPECT((signed)(actual) == (signed)(expected), "Hexadecimal equality check failed")
#define TEST_EXPECT_NOT_EQUAL_HEX(actual, expected)     TEST_EXPECT((signed)(actual) != (signed)(expected), "Hexadecimal inequality check failed")
#define TEST_EXPECT_LESS_HEX(actual, expected)          TEST_EXPECT((signed)(actual) <  (signed)(expected), "Hexadecimal less-than check failed")
#define TEST_EXPECT_GREATER_HEX(actual, expected)       TEST_EXPECT((signed)(actual) >  (signed)(expected), "Hexadecimal greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_HEX(actual, expected)    TEST_EXPECT((signed)(actual) <= (signed)(expected), "Hexadecimal less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_HEX(actual, expected) TEST_EXPECT((signed)(actual) >= (signed)(expected), "Hexadecimal greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_HEX8(actual, expected)         TEST_EXPECT((uint8_t)(actual) == (uint8_t)(expected), "8-bit Hexadecimal equality check failed")
#define TEST_EXPECT_NOT_EQUAL_HEX8(actual, expected)     TEST_EXPECT((uint8_t)(actual) != (uint8_t)(expected), "8-bit Hexadecimal inequality check failed")
#define TEST_EXPECT_LESS_HEX8(actual, expected)          TEST_EXPECT((uint8_t)(actual) <  (uint8_t)(expected), "8-bit Hexadecimal less-than check failed")
#define TEST_EXPECT_GREATER_HEX8(actual, expected)       TEST_EXPECT((uint8_t)(actual) >  (uint8_t)(expected), "8-bit Hexadecimal greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_HEX8(actual, expected)    TEST_EXPECT((uint8_t)(actual) <= (uint8_t)(expected), "8-bit Hexadecimal less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_HEX8(actual, expected) TEST_EXPECT((uint8_t)(actual) >= (uint8_t)(expected), "8-bit Hexadecimal greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_HEX16(actual, expected)         TEST_EXPECT((uint16_t)(actual) == (uint16_t)(expected), "16-bit Hexadecimal equality check failed")
#define TEST_EXPECT_NOT_EQUAL_HEX16(actual, expected)     TEST_EXPECT((uint16_t)(actual) != (uint16_t)(expected), "16-bit Hexadecimal inequality check failed")
#define TEST_EXPECT_LESS_HEX16(actual, expected)          TEST_EXPECT((uint16_t)(actual) <  (uint16_t)(expected), "16-bit Hexadecimal less-than check failed")
#define TEST_EXPECT_GREATER_HEX16(actual, expected)       TEST_EXPECT((uint16_t)(actual) >  (uint16_t)(expected), "16-bit Hexadecimal greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_HEX16(actual, expected)    TEST_EXPECT((uint16_t)(actual) <= (uint16_t)(expected), "16-bit Hexadecimal less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_HEX16(actual, expected) TEST_EXPECT((uint16_t)(actual) >= (uint16_t)(expected), "16-bit Hexadecimal greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_HEX32(actual, expected)         TEST_EXPECT((uint32_t)(actual) == (uint32_t)(expected), "32-bit Hexadecimal equality check failed")
#define TEST_EXPECT_NOT_EQUAL_HEX32(actual, expected)     TEST_EXPECT((uint32_t)(actual) != (uint32_t)(expected), "32-bit Hexadecimal inequality check failed")
#define TEST_EXPECT_LESS_HEX32(actual, expected)          TEST_EXPECT((uint32_t)(actual) <  (uint32_t)(expected), "32-bit Hexadecimal less-than check failed")
#define TEST_EXPECT_GREATER_HEX32(actual, expected)       TEST_EXPECT((uint32_t)(actual) >  (uint32_t)(expected), "32-bit Hexadecimal greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_HEX32(actual, expected)    TEST_EXPECT((uint32_t)(actual) <= (uint32_t)(expected), "32-bit Hexadecimal less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_HEX32(actual, expected) TEST_EXPECT((uint32_t)(actual) >= (uint32_t)(expected), "32-bit Hexadecimal greater-than-or-equal check failed")

#define TEST_EXPECT_EQUAL_HEX64(actual, expected)         TEST_EXPECT((uint64_t)(actual) == (uint64_t)(expected), "64-bit Hexadecimal equality check failed")
#define TEST_EXPECT_NOT_EQUAL_HEX64(actual, expected)     TEST_EXPECT((uint64_t)(actual) != (uint64_t)(expected), "64-bit Hexadecimal inequality check failed")
#define TEST_EXPECT_LESS_HEX64(actual, expected)          TEST_EXPECT((uint64_t)(actual) <  (uint64_t)(expected), "64-bit Hexadecimal less-than check failed")
#define TEST_EXPECT_GREATER_HEX64(actual, expected)       TEST_EXPECT((uint64_t)(actual) >  (uint64_t)(expected), "64-bit Hexadecimal greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_HEX64(actual, expected)    TEST_EXPECT((uint64_t)(actual) <= (uint64_t)(expected), "64-bit Hexadecimal less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_HEX64(actual, expected) TEST_EXPECT((uint64_t)(actual) >= (uint64_t)(expected), "64-bit Hexadecimal greater-than-or-equal check failed")

// ----------------------------------------------------------------
// Oct assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_EQUAL_OCT(actual, expected)         TEST_EXPECT((signed)(actual) == (signed)(expected), "Octal equality check failed")
#define TEST_EXPECT_NOT_EQUAL_OCT(actual, expected)     TEST_EXPECT((signed)(actual) != (signed)(expected), "Octal inequality check failed")
#define TEST_EXPECT_LESS_OCT(actual, expected)          TEST_EXPECT((signed)(actual) <  (signed)(expected), "Octal less-than check failed")
#define TEST_EXPECT_GREATER_OCT(actual, expected)       TEST_EXPECT((signed)(actual) >  (signed)(expected), "Octal greater-than check failed")
#define TEST_EXPECT_LESS_EQUAL_OCT(actual, expected)    TEST_EXPECT((signed)(actual) <= (signed)(expected), "Octal less-than-or-equal check failed")
#define TEST_EXPECT_GREATER_EQUAL_OCT(actual, expected) TEST_EXPECT((signed)(actual) >= (signed)(expected), "Octal greater-than-or-equal check failed")

// ----------------------------------------------------------------
// Bitwise assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_BIT_EQUAL(actual, expected)            TEST_EXPECT((signed)(actual) == (signed)(expected), "Bitwise equality check failed")
#define TEST_EXPECT_BIT_NOT_EQUAL(actual, expected)        TEST_EXPECT((signed)(actual) != (signed)(expected), "Bitwise inequality check failed")
#define TEST_EXPECT_BIT_LESS(actual, expected)             TEST_EXPECT((signed)(actual) <  (signed)(expected), "Bitwise less-than check failed")
#define TEST_EXPECT_BIT_GREATER(actual, expected)          TEST_EXPECT((signed)(actual) >  (signed)(expected), "Bitwise greater-than check failed")
#define TEST_EXPECT_BIT_LESS_EQUAL(actual, expected)       TEST_EXPECT((signed)(actual) <= (signed)(expected), "Bitwise less-than-or-equal check failed")
#define TEST_EXPECT_BIT_GREATER_EQUAL(actual, expected)    TEST_EXPECT((signed)(actual) >= (signed)(expected), "Bitwise greater-than-or-equal check failed")
#define TEST_EXPECT_BIT_NOT_HIGH(value, bitIndex)          TEST_EXPECT(!((signed)(value) & (1 << (signed)(bitIndex))), "Bit is high check failed")
#define TEST_EXPECT_BIT_HIGH(value, bitIndex)              TEST_EXPECT((signed)(value) &   (1 << (signed)(bitIndex)), "Bit is not high check failed")
#define TEST_EXPECT_BIT_NOT_LOW(value, bitIndex)           TEST_EXPECT((signed)(value) &   (1 << (signed)(bitIndex)), "Bit is low check failed")
#define TEST_EXPECT_BIT_LOW(value, bitIndex)               TEST_EXPECT(!((signed)(value) & (1 << (signed)(bitIndex))), "Bit is not low check failed")

#define TEST_EXPECT_BITS_NOT_HIGH(value, mask)             TEST_EXPECT(((signed)(value) & (signed)(mask)) != (signed)(mask), "Bits are all high check failed")
#define TEST_EXPECT_BITS_HIGH(value, mask)                 TEST_EXPECT(((signed)(value) & (signed)(mask)) == (signed)(mask), "Bits are not all high check failed")
#define TEST_EXPECT_BITS_NOT_LOW(value, mask)              TEST_EXPECT(((signed)(value) & (signed)(mask)) != 0, "Bits are not all low check failed")
#define TEST_EXPECT_BITS_LOW(value, mask)                  TEST_EXPECT(((signed)(value) & (signed)(mask)) == 0, "Bits are not all low check failed")
#define TEST_EXPECT_BITS_NOT_EQUAL(actual, expected, mask) TEST_EXPECT(((signed)(actual) & (signed)(mask)) != ((signed)(expected) & (signed)(mask)), "Bitwise equality check failed")
#define TEST_EXPECT_BITS_EQUAL(actual, expected, mask)     TEST_EXPECT(((signed)(actual) & (signed)(mask)) == ((signed)(expected) & (signed)(mask)), "Bitwise inequality check failed")
#define TEST_EXPECT_BITS_NOT_LESS(actual, expected, mask)  TEST_EXPECT(((signed)(actual) & (signed)(mask)) >= ((signed)(expected) & (signed)(mask)), "Bitwise less-than check failed")
#define TEST_EXPECT_BITS_LESS(actual, expected, mask)      TEST_EXPECT(((signed)(actual) & (signed)(mask)) < ((signed)(expected) & (signed)(mask)), "Bitwise greater-than check failed")
#define TEST_EXPECT_BITS_NOT_GREATER(actual, expected, mask)            TEST_EXPECT(((signed)(actual) & (signed)(mask)) <= ((signed)(expected) & (signed)(mask)), "Bitwise less-than-or-equal check failed")
#define TEST_EXPECT_BITS_GREATER(actual, expected, mask)                TEST_EXPECT(((signed)(actual) & (signed)(mask)) > ((signed)(expected) & (signed)(mask)), "Bitwise greater-than-or-equal check failed")
#define TEST_EXPECT_BITS_NOT_LESS_EQUAL(actual, expected, mask)         TEST_EXPECT(((signed)(actual) & (signed)(mask)) > ((signed)(expected) & (signed)(mask)), "Bitwise less-than-or-equal check failed")
#define TEST_EXPECT_BITS_LESS_EQUAL(actual, expected, mask)             TEST_EXPECT(((signed)(actual) & (signed)(mask)) <= ((signed)(expected) & (signed)(mask)), "Bitwise greater-than-or-equal check failed")
#define TEST_EXPECT_BITS_NOT_GREATER_EQUAL(actual, expected, mask)      TEST_EXPECT(((signed)(actual) & (signed)(mask)) < ((signed)(expected) & (signed)(mask)), "Bitwise less-than-or-equal check failed")
#define TEST_EXPECT_BITS_GREATER_EQUAL(actual, expected, mask)          TEST_EXPECT(((signed)(actual) & (signed)(mask)) >= ((signed)(expected) & (signed)(mask)), "Bitwise greater-than-or-equal check failed")

// ----------------------------------------------------------------
// Within assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_INT_WITHIN(actual, expected, tolerance)     TEST_EXPECT(((signed)(actual)  >= ((signed)(expected)  - (signed)(tolerance)))  && ((signed)(actual)  <= ((signed)(expected)  + (signed)(tolerance))),  "Integer value not within tolerance")
#define TEST_EXPECT_INT8_WITHIN(actual, expected, tolerance)    TEST_EXPECT(((int8_t)(actual)  >= ((int8_t)(expected)  - (int8_t)(tolerance)))  && ((int8_t)(actual)  <= ((int8_t)(expected)  + (int8_t)(tolerance))),  "8-bit Integer value not within tolerance")
#define TEST_EXPECT_INT16_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((int16_t)(actual) >= ((int16_t)(expected) - (int16_t)(tolerance))) && ((int16_t)(actual) <= ((int16_t)(expected) + (int16_t)(tolerance))), "16-bit Integer value not within tolerance")
#define TEST_EXPECT_INT32_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((int32_t)(actual) >= ((int32_t)(expected) - (int32_t)(tolerance))) && ((int32_t)(actual) <= ((int32_t)(expected) + (int32_t)(tolerance))), "32-bit Integer value not within tolerance")
#define TEST_EXPECT_INT64_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((int64_t)(actual) >= ((int64_t)(expected) - (int64_t)(tolerance))) && ((int64_t)(actual) <= ((int64_t)(expected) + (int64_t)(tolerance))), "64-bit Integer value not within tolerance")
#define TEST_EXPECT_UINT_WITHIN(actual, expected, tolerance)    TEST_EXPECT(((unsigned)(actual) >= ((unsigned)(expected) - (unsigned)(tolerance))) && ((unsigned)(actual) <= ((unsigned)(expected) + (unsigned)(tolerance))), "Unsigned integer value not within tolerance")
#define TEST_EXPECT_UINT8_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((uint8_t)(actual)  >= ((uint8_t)(expected)  - (uint8_t)(tolerance)))  && ((uint8_t)(actual)  <= ((uint8_t)(expected)  + (uint8_t)(tolerance))),  "8-bit Unsigned Integer value not within tolerance")
#define TEST_EXPECT_UINT16_WITHIN(actual, expected, tolerance)  TEST_EXPECT(((uint16_t)(actual) >= ((uint16_t)(expected) - (uint16_t)(tolerance))) && ((uint16_t)(actual) <= ((uint16_t)(expected) + (uint16_t)(tolerance))), "16-bit Unsigned Integer value not within tolerance")
#define TEST_EXPECT_UINT32_WITHIN(actual, expected, tolerance)  TEST_EXPECT(((uint32_t)(actual) >= ((uint32_t)(expected) - (uint32_t)(tolerance))) && ((uint32_t)(actual) <= ((uint32_t)(expected) + (uint32_t)(tolerance))), "32-bit Unsigned Integer value not within tolerance")
#define TEST_EXPECT_UINT64_WITHIN(actual, expected, tolerance)  TEST_EXPECT(((uint64_t)(actual) >= ((uint64_t)(expected) - (uint64_t)(tolerance))) && ((uint64_t)(actual) <= ((uint64_t)(expected) + (uint64_t)(tolerance))), "64-bit Unsigned Integer value not within tolerance")
#define TEST_EXPECT_HEX_WITHIN(actual, expected, tolerance)     TEST_EXPECT(((signed)(actual)   >= ((signed)(expected)   - (signed)(tolerance)))   && ((signed)(actual)   <= ((signed)(expected)   + (signed)(tolerance))),   "Hexadecimal value not within tolerance")
#define TEST_EXPECT_HEX8_WITHIN(actual, expected, tolerance)    TEST_EXPECT(((uint8_t)(actual)  >= ((uint8_t)(expected)  - (uint8_t)(tolerance)))  && ((uint8_t)(actual)  <= ((uint8_t)(expected)  + (uint8_t)(tolerance))),  "8-bit Hexadecimal value not within tolerance")
#define TEST_EXPECT_HEX16_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((uint16_t)(actual) >= ((uint16_t)(expected) - (uint16_t)(tolerance))) && ((uint16_t)(actual) <= ((uint16_t)(expected) + (uint16_t)(tolerance))), "16-bit Hexadecimal value not within tolerance")
#define TEST_EXPECT_HEX32_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((uint32_t)(actual) >= ((uint32_t)(expected) - (uint32_t)(tolerance))) && ((uint32_t)(actual) <= ((uint32_t)(expected) + (uint32_t)(tolerance))), "32-bit Hexadecimal value not within tolerance")
#define TEST_EXPECT_HEX64_WITHIN(actual, expected, tolerance)   TEST_EXPECT(((uint64_t)(actual) >= ((uint64_t)(expected) - (uint64_t)(tolerance))) && ((uint64_t)(actual) <= ((uint64_t)(expected) + (uint64_t)(tolerance))), "64-bit Hexadecimal value not within tolerance")
#define TEST_EXPECT_BIN_WITHIN(actual, expected, tolerance)     TEST_EXPECT(((signed)(actual) >= ((signed)(expected) - (signed)(tolerance))) && ((signed)(actual) <= ((signed)(expected) + (signed)(tolerance))), "Binary value not within tolerance")
#define TEST_EXPECT_OCT_WITHIN(actual, expected, tolerance)     TEST_EXPECT(((signed)(actual) >= ((signed)(expected) - (signed)(tolerance))) && ((signed)(actual) <= ((signed)(expected) + (signed)(tolerance))), "Octal value not within tolerance")

#define TEST_EXPECT_FLOAT_WITHIN(actual, expected, epsilon)     TEST_EXPECT(fabs((float)(actual) - (float)(expected)) <= (float)(epsilon), "Float value not within epsilon")
#define TEST_EXPECT_DOUBLE_WITHIN(actual, expected, epsilon)    TEST_EXPECT(fabs((double)(actual) - (double)(expected)) <= (double)(epsilon), "Double value not within epsilon")

#define TEST_EXPECT_CHAR_WITHIN(actual, min, max)               TEST_EXPECT((actual) > (min) || (actual) < (max), "Character value not within range")
#define TEST_EXPECT_WCHAR_WITHIN(actual, min, max)              TEST_EXPECT((actual) > (min) || (actual) < (max), "W-Character value not within range")

// ----------------------------------------------------------------
// Float assertions
// ----------------------------------------------------------------
#ifdef __cplusplus
#define TEST_EXPECT_FLOAT_EQUAL(actual, expected)         TEST_EXPECT(std::fabs((float)(actual) -  (float)(expected)) < EXPECT_FLOAT_EPSILON, "Floating-point value not equal within epsilon")
#define TEST_EXPECT_FLOAT_NOT_EQUAL(actual, expected)     TEST_EXPECT(std::fabs((float)(actual) -  (float)(expected)) <= EXPECT_FLOAT_EPSILON, "Floating-point value equal within epsilon")
#define TEST_EXPECT_FLOAT_LESS(actual, expected)          TEST_EXPECT((float)(actual)      <  (float)(expected),   "Floating-point value not less")
#define TEST_EXPECT_FLOAT_GREATER(actual, expected)       TEST_EXPECT((float)(actual)      >  (float)(expected),   "Floating-point value not greater")
#define TEST_EXPECT_FLOAT_GREATER_EQUAL(actual, expected) TEST_EXPECT((float)(actual)      >= (float)(expected),   "Floating-point value not greater or equal")
#define TEST_EXPECT_FLOAT_LESS_EQUAL(actual, expected)    TEST_EXPECT((float)(actual)      <= (float)(expected),   "Floating-point value not less or equal")
#define TEST_EXPECT_FLOAT_IS_NOT_INF(value)               TEST_EXPECT(!std::isinf((float)value) || (float)(value) <= 0, "Floating-point value is infinite")
#define TEST_EXPECT_FLOAT_IS_INF(value)                   TEST_EXPECT(std::isinf((float)value)  && (float)(value) > 0,  "Floating-point value is not positive infinity")
#define TEST_EXPECT_FLOAT_IS_NOT_NEG_INF(value)           TEST_EXPECT(!std::isinf((float)value) || (float)(value) >= 0, "Floating-point value is negative infinity")
#define TEST_EXPECT_FLOAT_IS_NEG_INF(value)               TEST_EXPECT(std::isinf((float)value)  && (float)(value) < 0,  "Floating-point value is not negative infinity")
#define TEST_EXPECT_FLOAT_IS_NOT_FINITE(value)            TEST_EXPECT(!std::isfinite((float)value), "Floating-point value is finite")
#define TEST_EXPECT_FLOAT_IS_FINITE(value)                TEST_EXPECT(std::isfinite((float)value),  "Floating-point value is not finite")
#define TEST_EXPECT_FLOAT_IS_NOT_NAN(value)               TEST_EXPECT(!std::isnan((float)value),    "Floating-point value is NaN")
#define TEST_EXPECT_FLOAT_IS_NAN(value)                   TEST_EXPECT(std::isnan((float)value),     "Floating-point value is not NaN")
#define TEST_EXPECT_FLOAT_IS_DETERMINATE(actual)         TEST_EXPECT(!std::isnan((float)actual) && std::isfinite((float)actual), "Floating-precision value not deterministic")
#define TEST_EXPECT_FLOAT_IS_NOT_DETERMINATE(actual)     TEST_EXPECT(std::isnan((float)actual)  || std::isinf((float)actual),    "Floating-precision value deterministic")
#else
#define TEST_EXPECT_FLOAT_EQUAL(actual, expected)         TEST_EXPECT(fabs((float)(actual) -  (float)(expected)) < EXPECT_FLOAT_EPSILON, "Floating-point value not equal within epsilon")
#define TEST_EXPECT_FLOAT_NOT_EQUAL(actual, expected)     TEST_EXPECT(fabs((float)(actual) -  (float)(expected)) <= EXPECT_FLOAT_EPSILON, "Floating-point value equal within epsilon")
#define TEST_EXPECT_FLOAT_LESS(actual, expected)          TEST_EXPECT((float)(actual)      <  (float)(expected),   "Floating-point value not less")
#define TEST_EXPECT_FLOAT_GREATER(actual, expected)       TEST_EXPECT((float)(actual)      >  (float)(expected),   "Floating-point value not greater")
#define TEST_EXPECT_FLOAT_GREATER_EQUAL(actual, expected) TEST_EXPECT((float)(actual)      >= (float)(expected),   "Floating-point value not greater or equal")
#define TEST_EXPECT_FLOAT_LESS_EQUAL(actual, expected)    TEST_EXPECT((float)(actual)      <= (float)(expected),   "Floating-point value not less or equal")
#define TEST_EXPECT_FLOAT_IS_NOT_INF(value)               TEST_EXPECT(!isinf((float)value) || (float)(value) <= 0, "Floating-point value is infinite")
#define TEST_EXPECT_FLOAT_IS_INF(value)                   TEST_EXPECT(isinf((float)value)  && (float)(value) > 0,  "Floating-point value is not positive infinity")
#define TEST_EXPECT_FLOAT_IS_NOT_NEG_INF(value)           TEST_EXPECT(!isinf((float)value) || (float)(value) >= 0, "Floating-point value is negative infinity")
#define TEST_EXPECT_FLOAT_IS_NEG_INF(value)               TEST_EXPECT(isinf((float)value)  && (float)(value) < 0,  "Floating-point value is not negative infinity")
#define TEST_EXPECT_FLOAT_IS_NOT_FINITE(value)            TEST_EXPECT(!isfinite((float)value), "Floating-point value is finite")
#define TEST_EXPECT_FLOAT_IS_FINITE(value)                TEST_EXPECT(isfinite((float)value),  "Floating-point value is not finite")
#define TEST_EXPECT_FLOAT_IS_NOT_NAN(value)               TEST_EXPECT(!isnan((float)value),    "Floating-point value is NaN")
#define TEST_EXPECT_FLOAT_IS_NAN(value)                   TEST_EXPECT(isnan((float)value),     "Floating-point value is not NaN")
#define TEST_EXPECT_FLOAT_IS_DETERMINATE(actual)         TEST_EXPECT(!isnan((float)actual) && isfinite((float)actual), "Floating-precision value not deterministic")
#define TEST_EXPECT_FLOAT_IS_NOT_DETERMINATE(actual)     TEST_EXPECT(isnan((float)actual)  || isinf((float)actual),    "Floating-precision value deterministic")
#endif

// ----------------------------------------------------------------
// Double assertions
// ----------------------------------------------------------------
#ifdef __cplusplus
#define TEST_EXPECT_DOUBLE_EQUAL(actual, expected)         TEST_EXPECT(fabs((double)(actual) - (double)(expected)) <  EXPECT_DOUBLE_EPSILON, "Double-precision value not equal within epsilon")
#define TEST_EXPECT_DOUBLE_NOT_EQUAL(actual, expected)     TEST_EXPECT(fabs((double)(actual) - (double)(expected)) <= EXPECT_DOUBLE_EPSILON, "Double-precision value equal within epsilon")
#define TEST_EXPECT_DOUBLE_LESS(actual, expected)          TEST_EXPECT((double)(actual) <  (double)(expected), "Double-precision value not less")
#define TEST_EXPECT_DOUBLE_GREATER(actual, expected)       TEST_EXPECT((double)(actual) >  (double)(expected), "Double-precision value not greater")
#define TEST_EXPECT_DOUBLE_GREATER_EQUAL(actual, expected) TEST_EXPECT((double)(actual) >= (double)(expected), "Double-precision value not greater or equal")
#define TEST_EXPECT_DOUBLE_LESS_EQUAL(actual, expected)    TEST_EXPECT((double)(actual) <= (double)(expected), "Double-precision value not less or equal")
#define TEST_EXPECT_DOUBLE_IS_NOT_INF(value)               TEST_EXPECT(!std::isinf((double)value) || (double)(value) <= 0, "Double-precision value is infinite")
#define TEST_EXPECT_DOUBLE_IS_INF(value)                   TEST_EXPECT(std::isinf((double)value) &&  (double)(value) > 0,  "Double-precision value is not positive infinity")
#define TEST_EXPECT_DOUBLE_IS_NOT_NEG_INF(value)           TEST_EXPECT(!std::isinf((double)value) || (double)(value) >= 0, "Double-precision value is negative infinity")
#define TEST_EXPECT_DOUBLE_IS_NEG_INF(value)               TEST_EXPECT(std::isinf((double)value) &&  (double)(value) < 0,  "Double-precision value is not negative infinity")
#define TEST_EXPECT_DOUBLE_IS_NOT_FINITE(value)            TEST_EXPECT(!std::isfinite((double)value), "Double-precision value is finite")
#define TEST_EXPECT_DOUBLE_IS_FINITE(value)                TEST_EXPECT(std::isfinite((double)value),  "Double-precision value is not finite")
#define TEST_EXPECT_DOUBLE_IS_NOT_NAN(value)               TEST_EXPECT(!std::isnan((double)value),    "Double-precision value is NaN")
#define TEST_EXPECT_DOUBLE_IS_NAN(value)                   TEST_EXPECT(std::isnan((double)value),     "Double-precision value is not NaN")
#define TEST_EXPECT_DOUBLE_IS_DETERMINATE(actual)          TEST_EXPECT(!std::isnan((double)actual) && std::isfinite((double)actual), "Double-precision value not deterministic")
#define TEST_EXPECT_DOUBLE_IS_NOT_DETERMINATE(actual)      TEST_EXPECT(std::isnan((double)actual)  || std::isinf((double)actual),    "Double-precision value deterministic")
#else
#define TEST_EXPECT_DOUBLE_EQUAL(actual, expected)         TEST_EXPECT(fabs((double)(actual) - (double)(expected)) <  EXPECT_DOUBLE_EPSILON, "Double-precision value not equal within epsilon")
#define TEST_EXPECT_DOUBLE_NOT_EQUAL(actual, expected)     TEST_EXPECT(fabs((double)(actual) - (double)(expected)) <= EXPECT_DOUBLE_EPSILON, "Double-precision value equal within epsilon")
#define TEST_EXPECT_DOUBLE_LESS(actual, expected)          TEST_EXPECT((double)(actual) <  (double)(expected), "Double-precision value not less")
#define TEST_EXPECT_DOUBLE_GREATER(actual, expected)       TEST_EXPECT((double)(actual) >  (double)(expected), "Double-precision value not greater")
#define TEST_EXPECT_DOUBLE_GREATER_EQUAL(actual, expected) TEST_EXPECT((double)(actual) >= (double)(expected), "Double-precision value not greater or equal")
#define TEST_EXPECT_DOUBLE_LESS_EQUAL(actual, expected)    TEST_EXPECT((double)(actual) <= (double)(expected), "Double-precision value not less or equal")
#define TEST_EXPECT_DOUBLE_IS_NOT_INF(value)               TEST_EXPECT(!isinf((double)value) || (double)(value) <= 0, "Double-precision value is infinite")
#define TEST_EXPECT_DOUBLE_IS_INF(value)                   TEST_EXPECT(isinf((double)value) &&  (double)(value) > 0,  "Double-precision value is not positive infinity")
#define TEST_EXPECT_DOUBLE_IS_NOT_NEG_INF(value)           TEST_EXPECT(!isinf((double)value) || (double)(value) >= 0, "Double-precision value is negative infinity")
#define TEST_EXPECT_DOUBLE_IS_NEG_INF(value)               TEST_EXPECT(isinf((double)value) &&  (double)(value) < 0,  "Double-precision value is not negative infinity")
#define TEST_EXPECT_DOUBLE_IS_NOT_FINITE(value)            TEST_EXPECT(!isfinite((double)value), "Double-precision value is finite")
#define TEST_EXPECT_DOUBLE_IS_FINITE(value)                TEST_EXPECT(isfinite((double)value),  "Double-precision value is not finite")
#define TEST_EXPECT_DOUBLE_IS_NOT_NAN(value)               TEST_EXPECT(!isnan((double)value),    "Double-precision value is NaN")
#define TEST_EXPECT_DOUBLE_IS_NAN(value)                   TEST_EXPECT(isnan((double)value),     "Double-precision value is not NaN")
#define TEST_EXPECT_DOUBLE_IS_DETERMINATE(actual)          TEST_EXPECT(!isnan((double)actual) && isfinite((double)actual), "Double-precision value not deterministic")
#define TEST_EXPECT_DOUBLE_IS_NOT_DETERMINATE(actual)      TEST_EXPECT(isnan((double)actual)  || isinf((double)actual),    "Double-precision value deterministic")
#endif

// ----------------------------------------------------------------
// Pointer assertions
// ----------------------------------------------------------------
#ifdef __cplusplus
#define TEST_EXPECT_CNULLPTR(pointer)      TEST_EXPECT((pointer) == nullptr, "Expected nullptr")
#define TEST_EXPECT_NOT_CNULLPTR(pointer)  TEST_EXPECT((pointer) != nullptr, "Expected not nullptr")
#define TEST_EXPECT_INVALID_PTR(pointer)   TEST_EXPECT((pointer) != nullptr, "Invalid pointer error")
#define TEST_EXPECT_EMPTY_PTR(pointer)     TEST_EXPECT((pointer) == nullptr, "Expected empty pointer")
#define TEST_EXPECT_NOT_EMPTY_PTR(pointer) TEST_EXPECT((pointer) != nullptr, "Expected not empty pointer")
#define TEST_EXPECT_INVALID_MEMORY_ACCESS_PTR(pointer) TEST_EXPECT(pointer != nullptr, "Invalid memory access")
#else
#define TEST_EXPECT_CNULLPTR(pointer)      TEST_EXPECT((pointer) == NULL, "Expected NULL")
#define TEST_EXPECT_NOT_CNULLPTR(pointer)  TEST_EXPECT((pointer) != NULL, "Expected not NULL")
#define TEST_EXPECT_INVALID_PTR(pointer)   TEST_EXPECT((pointer) != NULL, "Invalid pointer error")
#define TEST_EXPECT_EMPTY_PTR(pointer)     TEST_EXPECT((pointer) == NULL, "Expected empty pointer")
#define TEST_EXPECT_NOT_EMPTY_PTR(pointer) TEST_EXPECT((pointer) != NULL, "Expected not empty pointer")
#define TEST_EXPECT_INVALID_MEMORY_ACCESS_PTR(pointer) TEST_EXPECT(pointer != NULL, "Invalid memory access")
#endif
#define TEST_EXPECT_ARRAY_BOUNDS_PTR(pointer, index, size) TEST_EXPECT((index) >= 0 && (index) < (size), "Array index out of bounds")
#define TEST_EXPECT_EQUAL_PTR(actual, expected)            TEST_EXPECT((actual) == (expected), "Pointer equality check failed")
#define TEST_EXPECT_NOT_EQUAL_PTR(actual, expected)        TEST_EXPECT((actual) != (expected), "Pointer inequality check failed")
#define TEST_EXPECT_LESS_PTR(actual, expected)             TEST_EXPECT((actual) < (expected), "Pointer less than comparison failed")
#define TEST_EXPECT_GREATER_PTR(actual, expected)          TEST_EXPECT((actual) > (expected), "Pointer greater than comparison failed")
#define TEST_EXPECT_LESS_EQUAL_PTR(actual, expected)       TEST_EXPECT((actual) <= (expected), "Pointer less than or equal comparison failed")
#define TEST_EXPECT_GREATER_EQUAL_PTR(actual, expected)    TEST_EXPECT((actual) >= (expected), "Pointer greater than or equal comparison failed")

// ----------------------------------------------------------------
// String assertions
// ----------------------------------------------------------------
#ifdef __cplusplus
#define TEST_EXPECT_EQUAL_STRING(actual, expected) TEST_EXPECT((actual) == (expected), "String equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_STRING(actual, expected) TEST_EXPECT((actual) != (expected), "String inequality expectation not met")
#define TEST_EXPECT_LENGTH_STRING(actual, expected) TEST_EXPECT((actual).length() == (expected), "String length expectation not met")
#define TEST_EXPECT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_EXPECT(strstr((string), (substring)) != nullptr, "Substring not found")
#define TEST_EXPECT_NOT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_EXPECT(strstr((string), (substring)) == nullptr, "Substring found")
#define TEST_EXPECT_STARTS_WITH_STRING(string, prefix) TEST_EXPECT(strncmp((string), (prefix), strlen(prefix)) == 0, "String doesn't start with the prefix")
#define TEST_EXPECT_ENDS_WITH_STRING(string, suffix) TEST_EXPECT(strstr((string), (suffix) != nullptr && (strlen(string) - strlen(suffix)) == (strstr(string, suffix) - string)), "String doesn't end with the suffix")
#define TEST_EXPECT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "Case-insensitive string equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "Case-insensitive string inequality expectation not met")

#define TEST_EXPECT_EQUAL_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "String equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "String inequality expectation not met")
#define TEST_EXPECT_LENGTH_CSTRING(actual, expected) TEST_EXPECT(strlen((actual)) == (expected), "String length expectation not met")
#define TEST_EXPECT_CONTAINS_SUBSTRING_CSTRING(string, substring) TEST_EXPECT(strstr((string), (substring)) != NULL, "Substring not found")
#define TEST_EXPECT_NOT_CONTAINS_SUBSTRING_CSTRING(string, substring) TEST_EXPECT(strstr((string), (substring)) == NULL, "Substring found")
#define TEST_EXPECT_STARTS_WITH_CSTRING(string, prefix) TEST_EXPECT(strncmp((string), (prefix), strlen(prefix)) == 0, "String doesn't start with the prefix")
#define TEST_EXPECT_ENDS_WITH_CSTRING(string, suffix) TEST_EXPECT((strstr(string, suffix) != NULL && strlen(string) >= strlen(suffix) && strcmp(string + strlen(string) - strlen(suffix), suffix)), "String doesn't end with the suffix")
#define TEST_EXPECT_EQUAL_CASE_INSENSITIVE_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "Case-insensitive string equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CASE_INSENSITIVE_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "Case-insensitive string inequality expectation not met")
#else
#define TEST_EXPECT_EQUAL_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "String equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "String inequality expectation not met")
#define TEST_EXPECT_LENGTH_CSTRING(actual, expected) TEST_EXPECT(strlen((actual)) == (expected), "String length expectation not met")
#define TEST_EXPECT_CONTAINS_SUBSTRING_CSTRING(string, substring) TEST_EXPECT(strstr((string), (substring)) != NULL, "Substring not found")
#define TEST_EXPECT_NOT_CONTAINS_SUBSTRING_CSTRING(string, substring) TEST_EXPECT(strstr((string), (substring)) == NULL, "Substring found")
#define TEST_EXPECT_STARTS_WITH_CSTRING(string, prefix) TEST_EXPECT(strncmp((string), (prefix), strlen(prefix)) == 0, "String doesn't start with the prefix")
#define TEST_EXPECT_ENDS_WITH_CSTRING(string, suffix) TEST_EXPECT((strstr(string, suffix) != NULL && strlen(string) >= strlen(suffix) && strcmp(string + strlen(string) - strlen(suffix), suffix)), "String doesn't end with the suffix")
#define TEST_EXPECT_EQUAL_CASE_INSENSITIVE_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "Case-insensitive string equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CASE_INSENSITIVE_CSTRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "Case-insensitive string inequality expectation not met")

#define TEST_EXPECT_EQUAL_STRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "String equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_STRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "String inequality expectation not met")
#define TEST_EXPECT_LENGTH_STRING(actual, expected) TEST_EXPECT(strlen((actual)) == (expected), "String length expectation not met")
#define TEST_EXPECT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_EXPECT(strstr((string), (substring)) != NULL, "Substring not found")
#define TEST_EXPECT_NOT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_EXPECT(strstr((string), (substring)) == NULL, "Substring found")
#define TEST_EXPECT_STARTS_WITH_STRING(string, prefix) TEST_EXPECT(strncmp((string), (prefix), strlen(prefix)) == 0, "String doesn't start with the prefix")
#define TEST_EXPECT_ENDS_WITH_STRING(string, suffix) TEST_EXPECT((strstr(string, suffix) != NULL && strlen(string) >= strlen(suffix) && strcmp(string + strlen(string) - strlen(suffix), suffix)), "String doesn't end with the suffix")
#define TEST_EXPECT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) == 0, "Case-insensitive string equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_EXPECT(strcmp((actual), (expected)) != 0, "Case-insensitive string inequality expectation not met")
#endif

// ----------------------------------------------------------------
// Char assertions
// ----------------------------------------------------------------
#ifdef __cplusplus
#define TEST_EXPECT_EQUAL_CHAR(actual, expected)          TEST_EXPECT((actual) == (expected), "Character equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CHAR(actual, expected)      TEST_EXPECT((actual) != (expected), "Character inequality expectation not met")
#define TEST_EXPECT_LESS_CHAR(actual, expected)           TEST_EXPECT((actual) < (expected), "Character less-than expectation not met")
#define TEST_EXPECT_GREATER_CHAR(actual, expected)        TEST_EXPECT((actual) > (expected), "Character greater-than expectation not met")
#define TEST_EXPECT_LESS_EQUAL_CHAR(actual, expected)     TEST_EXPECT((actual) <= (expected), "Character less-than-or-equal expectation not met")
#define TEST_EXPECT_GREATER_EQUAL_CHAR(actual, expected)  TEST_EXPECT((actual) >= (expected), "Character greater-than-or-equal expectation not met")
#define TEST_EXPECT_IN_RANGE_CHAR(character, min, max)    TEST_EXPECT((character >= (min) && character <= (max)), "Character not in the specified range")
#define TEST_EXPECT_IS_UPPERCASE_CHAR(character)          TEST_EXPECT(std::isupper(character), "Character is not uppercase")
#define TEST_EXPECT_IS_LOWERCASE_CHAR(character)          TEST_EXPECT(std::islower(character), "Character is not lowercase")
#define TEST_EXPECT_TO_UPPER_CHAR(character, expected)    TEST_EXPECT(std::toupper(character) == expected, "Character not converted to uppercase as expected")
#define TEST_EXPECT_TO_LOWER_CHAR(character, expected)    TEST_EXPECT(std::tolower(character) == expected, "Character not converted to lowercase as expected")

#define TEST_EXPECT_EQUAL_WCHAR(actual, expected)         TEST_EXPECT((actual) == (expected), "Wide character equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_WCHAR(actual, expected)     TEST_EXPECT((actual) != (expected), "Wide character inequality expectation not met")
#define TEST_EXPECT_LESS_WCHAR(actual, expected)          TEST_EXPECT((actual) < (expected), "Wide character less-than expectation not met")
#define TEST_EXPECT_GREATER_WCHAR(actual, expected)       TEST_EXPECT((actual) > (expected), "Wide character greater-than expectation not met")
#define TEST_EXPECT_LESS_EQUAL_WCHAR(actual, expected)    TEST_EXPECT((actual) <= (expected), "Wide character less-than-or-equal expectation not met")
#define TEST_EXPECT_GREATER_EQUAL_WCHAR(actual, expected) TEST_EXPECT((actual) >= (expected), "Wide character greater-than-or-equal expectation not met")
#define TEST_EXPECT_IN_RANGE_WCHAR(character, min, max)   TEST_EXPECT((character >= (min) && character <= (max)), "Wide character not in the specified range")
#define TEST_EXPECT_IS_UPPERCASE_WCHAR(character)         TEST_EXPECT(std::iswupper(character), "Wide character is not uppercase")
#define TEST_EXPECT_IS_LOWERCASE_WCHAR(character)         TEST_EXPECT(std::iswlower(character), "Wide character is not lowercase")
#define TEST_EXPECT_TO_UPPER_WCHAR(character, expected)   TEST_EXPECT(std::towupper(character) == expected, "Wide character not converted to uppercase as expected")
#define TEST_EXPECT_TO_LOWER_WCHAR(character, expected)   TEST_EXPECT(std::towlower(character) == expected, "Wide character not converted to lowercase as expected")
#else
#define TEST_EXPECT_EQUAL_CHAR(actual, expected)          TEST_EXPECT((actual) == (expected), "Character equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_CHAR(actual, expected)      TEST_EXPECT((actual) != (expected), "Character inequality expectation not met")
#define TEST_EXPECT_LESS_CHAR(actual, expected)           TEST_EXPECT((actual) < (expected), "Character less-than expectation not met")
#define TEST_EXPECT_GREATER_CHAR(actual, expected)        TEST_EXPECT((actual) > (expected), "Character greater-than expectation not met")
#define TEST_EXPECT_LESS_EQUAL_CHAR(actual, expected)     TEST_EXPECT((actual) <= (expected), "Character less-than-or-equal expectation not met")
#define TEST_EXPECT_GREATER_EQUAL_CHAR(actual, expected)  TEST_EXPECT((actual) >= (expected), "Character greater-than-or-equal expectation not met")
#define TEST_EXPECT_IN_RANGE_CHAR(character, min, max)    TEST_EXPECT((character >= (min) && character <= (max)), "Character not in the specified range")
#define TEST_EXPECT_IS_UPPERCASE_CHAR(character)          TEST_EXPECT(isupper(character), "Character is not uppercase")
#define TEST_EXPECT_IS_LOWERCASE_CHAR(character)          TEST_EXPECT(islower(character), "Character is not lowercase")
#define TEST_EXPECT_TO_UPPER_CHAR(character, expected)    TEST_EXPECT(toupper(character) == expected, "Character not converted to uppercase as expected")
#define TEST_EXPECT_TO_LOWER_CHAR(character, expected)    TEST_EXPECT(tolower(character) == expected, "Character not converted to lowercase as expected")

#define TEST_EXPECT_EQUAL_WCHAR(actual, expected)         TEST_EXPECT((actual) == (expected), "Wide character equality expectation not met")
#define TEST_EXPECT_NOT_EQUAL_WCHAR(actual, expected)     TEST_EXPECT((actual) != (expected), "Wide character inequality expectation not met")
#define TEST_EXPECT_LESS_WCHAR(actual, expected)          TEST_EXPECT((actual) < (expected), "Wide character less-than expectation not met")
#define TEST_EXPECT_GREATER_WCHAR(actual, expected)       TEST_EXPECT((actual) > (expected), "Wide character greater-than expectation not met")
#define TEST_EXPECT_LESS_EQUAL_WCHAR(actual, expected)    TEST_EXPECT((actual) <= (expected), "Wide character less-than-or-equal expectation not met")
#define TEST_EXPECT_GREATER_EQUAL_WCHAR(actual, expected) TEST_EXPECT((actual) >= (expected), "Wide character greater-than-or-equal expectation not met")
#define TEST_EXPECT_IN_RANGE_WCHAR(character, min, max)   TEST_EXPECT((character >= (min) && character <= (max)), "Wide character not in the specified range")
#define TEST_EXPECT_IS_UPPERCASE_WCHAR(character)         TEST_EXPECT(iswupper(character), "Wide character is not uppercase")
#define TEST_EXPECT_IS_LOWERCASE_WCHAR(character)         TEST_EXPECT(iswlower(character), "Wide character is not lowercase")
#define TEST_EXPECT_TO_UPPER_WCHAR(character, expected)   TEST_EXPECT(towupper(character) == expected, "Wide character not converted to uppercase as expected")
#define TEST_EXPECT_TO_LOWER_WCHAR(character, expected)   TEST_EXPECT(towlower(character) == expected, "Wide character not converted to lowercase as expected")
#endif

// ----------------------------------------------------------------
// Array assertions
// ----------------------------------------------------------------
#define TEST_EXPECT_INVALID_SIZE_ARRAY(size)               TEST_EXPECT((size) > 0, "Invalid array size")
#define TEST_EXPECT_INDEX_OUT_OF_BOUNDS_ARRAY(index, size) TEST_EXPECT((index) >= 0 && (index) < (size), "Array index out of bounds")
#define TEST_EXPECT_CNULLPTR_POINTER_ARRAY(array)              TEST_EXPECT((array) != NULL, "Null array pointer")
#define TEST_EXPECT_INVALID_OPERATION_ARRAY(condition)     TEST_EXPECT(condition, "Invalid array operation")
#define TEST_EXPECT_INDEX_ARRAY(array, index)              TEST_EXPECT((index) >= 0 && (index) < sizeof(array) / sizeof(array[0]), "Array index out of bounds")

#ifdef __cplusplus
template<typename T>
bool test_expect_equal_array(const T* actual, const T* expected, size_t elem, const char* message) {
    bool success = true;
    for (size_t i = 0; i < elem; i++) {
        if (actual[i] != expected[i]) {
            success = false;
            break;
        }
    }
    TEST_EXPECT(success, message);
    return success;
}

#define TEST_EXPECT_EQUAL_INT_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT8_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int8_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT16_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int16_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT32_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int32_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT64_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int64_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT_ARRAY(actual, expected, elem) \
    test_expect_equal_array<unsigned>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT8_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint8_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT16_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint16_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT32_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint32_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT64_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint64_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX8_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint8_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX16_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint16_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX32_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint32_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX64_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint64_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_OCT_ARRAY(actual, expected, elem) \
    test_expect_equal_array<int>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_PTR_ARRAY(actual, expected, elem) \
    test_expect_equal_array<void*>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_STRING_ARRAY(actual, expected, elem) \
    test_expect_equal_array<const char*>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_CHAR_ARRAY(actual, expected, elem) \
    test_expect_equal_array<char>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_MEMORY_ARRAY(actual, expected, elem) \
    test_expect_equal_array<uint8_t>(actual, expected, elem, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_FLOAT_ARRAY(actual, expected, elem) \
    do { \
        bool success = true; \
        for (size_t i = 0; i < elem; i++) { \
            if (fabs((actual)[i] - (expected)[i]) >= ASSERT_FLOAT_EPSILON) { \
                success = false; \
                break; \
            } \
        } \
        TEST_EXPECT(success, "Array equality expectation not met"); \
    } while (false)

#define TEST_EXPECT_EQUAL_DOUBLE_ARRAY(actual, expected, elem) \
    do { \
        bool success = true; \
        for (size_t i = 0; i < elem; i++) { \
            if (fabs((actual)[i] - (expected)[i]) >= ASSERT_DOUBLE_EPSILON) { \
                success = false; \
                break; \
            } \
        } \
        TEST_EXPECT(success, "Array equality expectation not met"); \
    } while (false)
#else
inline void test_expect_equal_array(const void* actual, const void* expected, size_t elem, size_t size, const char* message) {
    bool success = true;
    for (size_t i = 0; i < elem; i++) {
        const char* actual_ptr = (const char*)actual + i * size;
        const char* expected_ptr = (const char*)expected + i * size;
        if (memcmp(actual_ptr, expected_ptr, size) != 0) {
            success = false;
            break;
        }
    }
    TEST_EXPECT(success, message);
}

#define TEST_EXPECT_EQUAL_INT_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT8_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int8_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT16_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int16_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT32_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int32_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_INT64_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int64_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, unsigned, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT8_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint8_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT16_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint16_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT32_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint32_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_UINT64_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint64_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX8_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint8_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX16_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint16_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX32_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint32_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_HEX64_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint64_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_OCT_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, int, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_PTR_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, void*, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_STRING_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, const char*, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_CHAR_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, char, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_MEMORY_ARRAY(actual, expected, elem) \
    TEST_EXPECT_EQUAL_ARRAY(actual, expected, elem, uint8_t, "Array equality expectation not met")

#define TEST_EXPECT_EQUAL_FLOAT_ARRAY(actual, expected, elem) \
    do { \
        bool success = true; \
        for (size_t i = 0; i < elem; i++) { \
            if (fabs((actual)[i] - (expected)[i]) >= ASSERT_FLOAT_EPSILON) { \
                success = false; \
                break; \
            } \
        } \
        TEST_EXPECT(success, "Array equality expectation not met"); \
    } while (false)

#define TEST_EXPECT_EQUAL_DOUBLE_ARRAY(actual, expected, elem) \
    do { \
        bool success = true; \
        for (size_t i = 0; i < elem; i++) { \
            if (fabs((actual)[i] - (expected)[i]) >= ASSERT_DOUBLE_EPSILON) { \
                success = false; \
                break; \
            } \
        } \
        TEST_EXPECT(success, "Array equality expectation not met"); \
    } while (false)
#endif


// ----------------------------------------------------------------
// File Stream assertions
// ----------------------------------------------------------------
#ifdef __cplusplus
#define TEST_EXPECT_OPEN_FILE(file) TEST_EXPECT((file).is_open(), "Failed to open file")
#define TEST_EXPECT_READ_FILE(file, buffer, size) \
    TEST_EXPECT((file).read(buffer, size), "Failed to read from file")
#define TEST_EXPECT_WRITE_FILE(file, data, size) \
    TEST_EXPECT((file).write(data, size), "Failed to write to file")
#define TEST_EXPECT_SEEK_FILE(file, offset, whence) \
    TEST_EXPECT((file).seekg(offset, whence).good(), "Failed to seek within file")
#define TEST_EXPECT_TELL_FILE(file) \
    TEST_EXPECT((file).tellg() != std::streampos(-1), "Failed to get file position")
#define TEST_EXPECT_CLOSE_FILE(file) \
    do { \
        (file).close(); \
        TEST_EXPECT(!(file).fail(), "Failed to close file"); \
    } while (false)
#define TEST_EXPECT_EOF_FILE(stream) \
    TEST_EXPECT(!(stream).eof(), "End of file (EOF) reached")
#define TEST_EXPECT_FILE_NO_ERROR(file) \
    TEST_EXPECT(!(file).fail(), "File operation error occurred")

#else
#define TEST_EXPECT_OPEN_FILE(file) TEST_EXPECT((file) != NULL, "Failed to open file")
#define TEST_EXPECT_READ_FILE(file, buffer, size) \
    TEST_EXPECT(fread(buffer, sizeof(char), size, file) == size, "Failed to read from file")
#define TEST_EXPECT_WRITE_FILE(file, data, size) \
    TEST_EXPECT(fwrite(data, sizeof(char), size, file) == size, "Failed to write to file")
#define TEST_EXPECT_SEEK_FILE(file, offset, whence) \
    TEST_EXPECT(fseek(file, offset, whence) == 0, "Failed to seek within file")
#define TEST_EXPECT_TELL_FILE(file) \
    TEST_EXPECT(ftell(file) != -1L, "Failed to get file position")
#define TEST_EXPECT_CLOSE_FILE(file) \
    TEST_EXPECT(fclose(file) == 0, "Failed to close file")
#define TEST_EXPECT_EOF_FILE(stream) \
    TEST_EXPECT(!feof(stream), "End of file (EOF) reached")
#define TEST_EXPECT_FILE_NO_ERROR(file) \
    TEST_EXPECT(ferror(file) == 0, "File operation error occurred")
#endif

#ifdef __cplusplus
}
#endif

#endif
