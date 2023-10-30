/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.code.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_TEST_ASSERT_H
#define TRILOBITE_TEST_ASSERT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

#define ASSERT_FLOAT_EPSILON 1e-6 // Define your desired epsilon value
#define ASSERT_DOUBLE_EPSILON 1e-9 // Define your desired epsilon value

/**
 * @brief Memory Assertion Macros
 *
 * These macros are designed for asserting memory-related operations, such as memory equality, inequality,
 * memory copy, memory containing, and memory not containing. They use the `memcmp` function to compare memory
 * blocks and check if they meet the specified expectations.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_MEMORY to check if two memory blocks are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_MEMORY to assert that two memory blocks are not equal.
 *   - Use TEST_ASSERT_CONTAINS_MEMORY to check if a larger memory block contains a smaller one.
 *   - Use TEST_ASSERT_NOT_CONTAINS_MEMORY to check that a memory block does not contain another.
 *   - Use TEST_ASSERT_COPIED_MEMORY to check if one memory block has been copied to another.
 *   - Use TEST_ASSERT_NOT_COPIED_MEMORY to verify that a memory block has not been copied to another.
 *
 * @param actual      A pointer to the actual memory block.
 * @param expected    A pointer to the expected memory block for comparison.
 * @param size        The size of the memory block in bytes.
 * @param haystack    A pointer to the larger memory block.
 * @param needle      A pointer to the smaller memory block to search for.
 * @param haystackSize The size of the larger memory block in bytes.
 * @param needleSize  The size of the smaller memory block in bytes.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL_MEMORY(actual, expected, size)     TEST_ASSERT(memcmp(actual, expected, size) != 0, "Expectation for memory equality not met")
#define TEST_ASSERT_NOT_EQUAL_MEMORY(actual, expected, size) TEST_ASSERT(memcmp(actual, expected, size) == 0, "Expectation for memory inequality not met")
#define TEST_ASSERT_CONTAINS_MEMORY(haystack, needle, haystackSize, needleSize) \
bool found = false; \
for (size_t i = 0; i <= (haystackSize - needleSize); i++) { \
    if (memcmp(haystack + i, needle, needleSize) == 0) { \
        found = true; \
        break; \
    } \
} \
TEST_ASSERT(!found, "Memory contains assertion failed");

#define TEST_ASSERT_NOT_CONTAINS_MEMORY(haystack, needle, haystackSize, needleSize) \
bool found = false; \
for (size_t i = 0; i <= (haystackSize - needleSize); i++) { \
    if (memcmp(haystack + i, needle, needleSize) == 0) { \
        found = true; \
        break; \
    } \
} \
TEST_ASSERT(found, "Memory not contains assertion failed");

#define TEST_ASSERT_COPIED_MEMORY(dest, source, size)     TEST_ASSERT((memcmp(dest, source, size) == 0), "Memory copy check failed");
#define TEST_ASSERT_NOT_COPIED_MEMORY(dest, source, size) TEST_ASSERT((memcmp(dest, source, size) != 0), "Memory not copied check failed");

/**
 * @brief Boolean Assertion Macros
 *
 * These macros are designed for asserting boolean values using various comparison operations.
 * They provide a way to verify boolean equality, inequality, and order (less than, greater than, etc.)
 * between boolean values. These macros work with standard boolean values (0 for false, 1 for true).
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL to check if two boolean values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL to assert that two boolean values are not equal.
 *   - Use TEST_ASSERT_LESS to check if one boolean value is less than another (0 < 1).
 *   - Use TEST_ASSERT_GREATER to verify that one boolean value is greater than another (1 > 0).
 *   - Use TEST_ASSERT_TRUE to assert that an expression is true (1).
 *   - Use TEST_ASSERT_FALSE to assert that an expression is false (0).
 *   - Use TEST_ASSERT_MSG to provide a custom message with a boolean assertion.
 *
 * @param actual     The actual boolean value for the assertion.
 * @param expected   The expected boolean value for comparison.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL(actual, expected)     TEST_ASSERT((bool)(actual) == (bool)(expected), "Expectation for equality not met")
#define TEST_ASSERT_NOT_EQUAL(actual, expected) TEST_ASSERT((bool)(actual) != (bool)(expected), "Expectation for inequality not met")
#define TEST_ASSERT_LESS(actual, expected)      TEST_ASSERT((bool)(actual) <  (bool)(expected), "Expectation for less than not met")
#define TEST_ASSERT_GREATER(actual, expected)   TEST_ASSERT((bool)(actual) >  (bool)(expected), "Expectation for greater than not met")
#define TEST_ASSERT_UNLESS(expression)          TEST_ASSERT((expression), "Expectation not met")
#define TEST_ASSERT_TRUE(expression)            TEST_ASSERT((expression), "Expectation for true not met")
#define TEST_ASSERT_FALSE(expression)           TEST_ASSERT(!(expression), "Expectation for false not met")
#define TEST_ASSERT_MSG(expression, message)    TEST_ASSERT(!(expression), message)

#define TEST_ASSERT_EQUAL_BOOL(actual, expected)     TEST_ASSERT((bool)(actual) == (bool)(expected), "Expectation for equality not met")
#define TEST_ASSERT_NOT_EQUAL_BOOL(actual, expected) TEST_ASSERT((bool)(actual) != (bool)(expected), "Expectation for inequality not met")
#define TEST_ASSERT_LESS_BOOL(actual, expected)      TEST_ASSERT((bool)(actual) <  (bool)(expected), "Expectation for less than not met")
#define TEST_ASSERT_GREATER_BOOL(actual, expected)   TEST_ASSERT((bool)(actual) >  (bool)(expected), "Expectation for greater than not met")
#define TEST_ASSERT_UNLESS_BOOL(expression)          TEST_ASSERT((expression), "Expectation not met")
#define TEST_ASSERT_TRUE_BOOL(expression)            TEST_ASSERT((expression), "Expectation for true not met")
#define TEST_ASSERT_FALSE_BOOL(expression)           TEST_ASSERT(!(expression), "Expectation for false not met")
#define TEST_ASSERT_MSG_BOOL(expression, message)    TEST_ASSERT(!(expression), message)

/**
 * @brief Enum Assertion Macros
 *
 * These macros are used for asserting equality, inequality, and order comparisons between enumeration values.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_ENUM to check if two enum values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_ENUM to assert that two enum values are not equal.
 *   - Use TEST_ASSERT_LESS_ENUM to check if one enum value is less than another (ordering defined in the enum).
 *   - Use TEST_ASSERT_GREATER_ENUM to verify that one enum value is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_ENUM to check if one enum value is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_ENUM to verify that one enum value is greater than or equal to another.
 *
 * @param actual     The actual enumeration value for the assertion.
 * @param expected   The expected enumeration value for comparison.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL_ENUM(actual, expected)         TEST_ASSERT((actual) == (expected), "Enum equality check failed")
#define TEST_ASSERT_NOT_EQUAL_ENUM(actual, expected)     TEST_ASSERT((actual) != (expected), "Enum inequality check failed")
#define TEST_ASSERT_LESS_ENUM(actual, expected)          TEST_ASSERT((actual) <  (expected), "Enum less-than check failed")
#define TEST_ASSERT_GREATER_ENUM(actual, expected)       TEST_ASSERT((actual) >  (expected), "Enum greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_ENUM(actual, expected)    TEST_ASSERT((actual) <= (expected), "Enum less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_ENUM(actual, expected) TEST_ASSERT((actual) >= (expected), "Enum greater-than-or-equal check failed")

/**
 * @brief Integer Assertion Macros
 *
 * These macros are designed for asserting integer values using various comparison operations.
 * They provide a way to verify integer equality, inequality, and order (less than, greater than, etc.)
 * between integer values.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_INT to check if two integer values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_INT to assert that two integer values are not equal.
 *   - Use TEST_ASSERT_LESS_INT to check if one integer value is less than another.
 *   - Use TEST_ASSERT_GREATER_INT to verify that one integer value is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_INT to assert that one integer value is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_INT to verify that one integer value is greater than or equal to another.
 *
 * Additionally, there are 8/16/32/64-bit versions of these macros available for different integer widths.
 *
 * @param actual     The actual integer value for the assertion.
 * @param expected   The expected integer value for comparison.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL_INT(actual, expected)         TEST_ASSERT((signed)(actual) == (signed)(expected), "Integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_INT(actual, expected)     TEST_ASSERT((signed)(actual) != (signed)(expected), "Integer inequality check failed")
#define TEST_ASSERT_LESS_INT(actual, expected)          TEST_ASSERT((signed)(actual) <  (signed)(expected), "Integer less-than check failed")
#define TEST_ASSERT_GREATER_INT(actual, expected)       TEST_ASSERT((signed)(actual) >  (signed)(expected), "Integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_INT(actual, expected)    TEST_ASSERT((signed)(actual) <= (signed)(expected), "Integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_INT(actual, expected) TEST_ASSERT((signed)(actual) >= (signed)(expected), "Integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_INT8(actual, expected)         TEST_ASSERT((int8_t)(actual) == (int8_t)(expected), "8-bit Integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_INT8(actual, expected)     TEST_ASSERT((int8_t)(actual) != (int8_t)(expected), "8-bit Integer inequality check failed")
#define TEST_ASSERT_LESS_INT8(actual, expected)          TEST_ASSERT((int8_t)(actual) <  (int8_t)(expected), "8-bit Integer less-than check failed")
#define TEST_ASSERT_GREATER_INT8(actual, expected)       TEST_ASSERT((int8_t)(actual) >  (int8_t)(expected), "8-bit Integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_INT8(actual, expected)    TEST_ASSERT((int8_t)(actual) <= (int8_t)(expected), "8-bit Integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_INT8(actual, expected) TEST_ASSERT((int8_t)(actual) >= (int8_t)(expected), "8-bit Integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_INT16(actual, expected)         TEST_ASSERT((int16_t)(actual) == (int16_t)(expected), "16-bit Integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_INT16(actual, expected)     TEST_ASSERT((int16_t)(actual) != (int16_t)(expected), "16-bit Integer inequality check failed")
#define TEST_ASSERT_LESS_INT16(actual, expected)          TEST_ASSERT((int16_t)(actual) <  (int16_t)(expected), "16-bit Integer less-than check failed")
#define TEST_ASSERT_GREATER_INT16(actual, expected)       TEST_ASSERT((int16_t)(actual) >  (int16_t)(expected), "16-bit Integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_INT16(actual, expected)    TEST_ASSERT((int16_t)(actual) <= (int16_t)(expected), "16-bit Integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_INT16(actual, expected) TEST_ASSERT((int16_t)(actual) >= (int16_t)(expected), "16-bit Integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_INT32(actual, expected)         TEST_ASSERT((int32_t)(actual) == (int32_t)(expected), "32-bit Integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_INT32(actual, expected)     TEST_ASSERT((int32_t)(actual) != (int32_t)(expected), "32-bit Integer inequality check failed")
#define TEST_ASSERT_LESS_INT32(actual, expected)          TEST_ASSERT((int32_t)(actual) <  (int32_t)(expected), "32-bit Integer less-than check failed")
#define TEST_ASSERT_GREATER_INT32(actual, expected)       TEST_ASSERT((int32_t)(actual) >  (int32_t)(expected), "32-bit Integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_INT32(actual, expected)    TEST_ASSERT((int32_t)(actual) <= (int32_t)(expected), "32-bit Integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_INT32(actual, expected) TEST_ASSERT((int32_t)(actual) >= (int32_t)(expected), "32-bit Integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_INT64(actual, expected)         TEST_ASSERT((int64_t)(actual) == (int64_t)(expected), "64-bit Integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_INT64(actual, expected)     TEST_ASSERT((int64_t)(actual) != (int64_t)(expected), "64-bit Integer inequality check failed")
#define TEST_ASSERT_LESS_INT64(actual, expected)          TEST_ASSERT((int64_t)(actual) <  (int64_t)(expected), "64-bit Integer less-than check failed")
#define TEST_ASSERT_GREATER_INT64(actual, expected)       TEST_ASSERT((int64_t)(actual) >  (int64_t)(expected), "64-bit Integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_INT64(actual, expected)    TEST_ASSERT((int64_t)(actual) <= (int64_t)(expected), "64-bit Integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_INT64(actual, expected) TEST_ASSERT((int64_t)(actual) >= (int64_t)(expected), "64-bit Integer greater-than-or-equal check failed")

/**
 * @brief Unsigned Integer Assertion Macros
 *
 * These macros are designed for asserting unsigned integer values using various comparison operations.
 * They provide a way to verify unsigned integer equality, inequality, and order (less than, greater than, etc.)
 * between unsigned integer values.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_UINT to check if two unsigned integer values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_UINT to assert that two unsigned integer values are not equal.
 *   - Use TEST_ASSERT_LESS_UINT to check if one unsigned integer value is less than another.
 *   - Use TEST_ASSERT_GREATER_UINT to verify that one unsigned integer value is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_UINT to assert that one unsigned integer value is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_UINT to verify that one unsigned integer value is greater than or equal to another.
 *
 * Additionally, there are 8/16/32/64-bit versions of these macros available for different integer widths.
 *
 * @param actual     The actual unsigned integer value for the assertion.
 * @param expected   The expected unsigned integer value for comparison.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL_UINT(actual, expected)         TEST_ASSERT((unsigned)(actual) == (unsigned)(expected), "Unsigned integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_UINT(actual, expected)     TEST_ASSERT((unsigned)(actual) != (unsigned)(expected), "Unsigned integer inequality check failed")
#define TEST_ASSERT_LESS_UINT(actual, expected)          TEST_ASSERT((unsigned)(actual) <  (unsigned)(expected), "Unsigned integer less-than check failed")
#define TEST_ASSERT_GREATER_UINT(actual, expected)       TEST_ASSERT((unsigned)(actual) >  (unsigned)(expected), "Unsigned integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_UINT(actual, expected)    TEST_ASSERT((unsigned)(actual) <= (unsigned)(expected), "Unsigned integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_UINT(actual, expected) TEST_ASSERT((unsigned)(actual) >= (unsigned)(expected), "Unsigned integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_UINT8(actual, expected)         TEST_ASSERT((uint8_t)(actual) == (uint8_t)(expected), "8-bit Unsigned integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_UINT8(actual, expected)     TEST_ASSERT((uint8_t)(actual) != (uint8_t)(expected), "8-bit Unsigned integer inequality check failed")
#define TEST_ASSERT_LESS_UINT8(actual, expected)          TEST_ASSERT((uint8_t)(actual) <  (uint8_t)(expected), "8-bit Unsigned integer less-than check failed")
#define TEST_ASSERT_GREATER_UINT8(actual, expected)       TEST_ASSERT((uint8_t)(actual) >  (uint8_t)(expected), "8-bit Unsigned integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_UINT8(actual, expected)    TEST_ASSERT((uint8_t)(actual) <= (uint8_t)(expected), "8-bit Unsigned integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_UINT8(actual, expected) TEST_ASSERT((uint8_t)(actual) >= (uint8_t)(expected), "8-bit Unsigned integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_UINT16(actual, expected)         TEST_ASSERT((uint16_t)(actual) == (uint16_t)(expected), "16-bit Unsigned integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_UINT16(actual, expected)     TEST_ASSERT((uint16_t)(actual) != (uint16_t)(expected), "16-bit Unsigned integer inequality check failed")
#define TEST_ASSERT_LESS_UINT16(actual, expected)          TEST_ASSERT((uint16_t)(actual) <  (uint16_t)(expected), "16-bit Unsigned integer less-than check failed")
#define TEST_ASSERT_GREATER_UINT16(actual, expected)       TEST_ASSERT((uint16_t)(actual) >  (uint16_t)(expected), "16-bit Unsigned integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_UINT16(actual, expected)    TEST_ASSERT((uint16_t)(actual) <= (uint16_t)(expected), "16-bit Unsigned integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_UINT16(actual, expected) TEST_ASSERT((uint16_t)(actual) >= (uint16_t)(expected), "16-bit Unsigned integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_UINT32(actual, expected)         TEST_ASSERT((uint32_t)(actual) == (uint32_t)(expected), "32-bit Unsigned integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_UINT32(actual, expected)     TEST_ASSERT((uint32_t)(actual) != (uint32_t)(expected), "32-bit Unsigned integer inequality check failed")
#define TEST_ASSERT_LESS_UINT32(actual, expected)          TEST_ASSERT((uint32_t)(actual) <  (uint32_t)(expected), "32-bit Unsigned integer less-than check failed")
#define TEST_ASSERT_GREATER_UINT32(actual, expected)       TEST_ASSERT((uint32_t)(actual) >  (uint32_t)(expected), "32-bit Unsigned integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_UINT32(actual, expected)    TEST_ASSERT((uint32_t)(actual) <= (uint32_t)(expected), "32-bit Unsigned integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_UINT32(actual, expected) TEST_ASSERT((uint32_t)(actual) >= (uint32_t)(expected), "32-bit Unsigned integer greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_UINT64(actual, expected)         TEST_ASSERT((uint64_t)(actual) == (uint64_t)(expected), "64-bit Unsigned integer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_UINT64(actual, expected)     TEST_ASSERT((uint64_t)(actual) != (uint64_t)(expected), "64-bit Unsigned integer inequality check failed")
#define TEST_ASSERT_LESS_UINT64(actual, expected)          TEST_ASSERT((uint64_t)(actual) <  (uint64_t)(expected), "64-bit Unsigned integer less-than check failed")
#define TEST_ASSERT_GREATER_UINT64(actual, expected)       TEST_ASSERT((uint64_t)(actual) >  (uint64_t)(expected), "64-bit Unsigned integer greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_UINT64(actual, expected)    TEST_ASSERT((uint64_t)(actual) <= (uint64_t)(expected), "64-bit Unsigned integer less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_UINT64(actual, expected) TEST_ASSERT((uint64_t)(actual) >= (uint64_t)(expected), "64-bit Unsigned integer greater-than-or-equal check failed")

/**
 * @brief Hexadecimal Assertion Macros
 *
 * These macros are designed for asserting hexadecimal integer values using various comparison operations.
 * They provide a way to verify hexadecimal equality, inequality, and order (less than, greater than, etc.)
 * between hexadecimal integer values.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_HEX to check if two hexadecimal values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_HEX to assert that two hexadecimal values are not equal.
 *   - Use TEST_ASSERT_LESS_HEX to check if one hexadecimal value is less than another.
 *   - Use TEST_ASSERT_GREATER_HEX to verify that one hexadecimal value is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_HEX to assert that one hexadecimal value is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_HEX to verify that one hexadecimal value is greater than or equal to another.
 *
 * Additionally, there are 8/16/32/64-bit versions of these macros available.
 *
 * @param actual     The actual hexadecimal integer value for the assertion.
 * @param expected   The expected hexadecimal integer value for comparison.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL_HEX(actual, expected)         TEST_ASSERT((signed)(actual) == (signed)(expected), "Hexadecimal equality check failed")
#define TEST_ASSERT_NOT_EQUAL_HEX(actual, expected)     TEST_ASSERT((signed)(actual) != (signed)(expected), "Hexadecimal inequality check failed")
#define TEST_ASSERT_LESS_HEX(actual, expected)          TEST_ASSERT((signed)(actual) <  (signed)(expected), "Hexadecimal less-than check failed")
#define TEST_ASSERT_GREATER_HEX(actual, expected)       TEST_ASSERT((signed)(actual) >  (signed)(expected), "Hexadecimal greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_HEX(actual, expected)    TEST_ASSERT((signed)(actual) <= (signed)(expected), "Hexadecimal less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_HEX(actual, expected) TEST_ASSERT((signed)(actual) >= (signed)(expected), "Hexadecimal greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_HEX8(actual, expected)         TEST_ASSERT((uint8_t)(actual) == (uint8_t)(expected), "8-bit Hexadecimal equality check failed")
#define TEST_ASSERT_NOT_EQUAL_HEX8(actual, expected)     TEST_ASSERT((uint8_t)(actual) != (uint8_t)(expected), "8-bit Hexadecimal inequality check failed")
#define TEST_ASSERT_LESS_HEX8(actual, expected)          TEST_ASSERT((uint8_t)(actual) <  (uint8_t)(expected), "8-bit Hexadecimal less-than check failed")
#define TEST_ASSERT_GREATER_HEX8(actual, expected)       TEST_ASSERT((uint8_t)(actual) >  (uint8_t)(expected), "8-bit Hexadecimal greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_HEX8(actual, expected)    TEST_ASSERT((uint8_t)(actual) <= (uint8_t)(expected), "8-bit Hexadecimal less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_HEX8(actual, expected) TEST_ASSERT((uint8_t)(actual) >= (uint8_t)(expected), "8-bit Hexadecimal greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_HEX16(actual, expected)         TEST_ASSERT((uint16_t)(actual) == (uint16_t)(expected), "16-bit Hexadecimal equality check failed")
#define TEST_ASSERT_NOT_EQUAL_HEX16(actual, expected)     TEST_ASSERT((uint16_t)(actual) != (uint16_t)(expected), "16-bit Hexadecimal inequality check failed")
#define TEST_ASSERT_LESS_HEX16(actual, expected)          TEST_ASSERT((uint16_t)(actual) <  (uint16_t)(expected), "16-bit Hexadecimal less-than check failed")
#define TEST_ASSERT_GREATER_HEX16(actual, expected)       TEST_ASSERT((uint16_t)(actual) >  (uint16_t)(expected), "16-bit Hexadecimal greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_HEX16(actual, expected)    TEST_ASSERT((uint16_t)(actual) <= (uint16_t)(expected), "16-bit Hexadecimal less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_HEX16(actual, expected) TEST_ASSERT((uint16_t)(actual) >= (uint16_t)(expected), "16-bit Hexadecimal greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_HEX32(actual, expected)         TEST_ASSERT((uint32_t)(actual) == (uint32_t)(expected), "32-bit Hexadecimal equality check failed")
#define TEST_ASSERT_NOT_EQUAL_HEX32(actual, expected)     TEST_ASSERT((uint32_t)(actual) != (uint32_t)(expected), "32-bit Hexadecimal inequality check failed")
#define TEST_ASSERT_LESS_HEX32(actual, expected)          TEST_ASSERT((uint32_t)(actual) <  (uint32_t)(expected), "32-bit Hexadecimal less-than check failed")
#define TEST_ASSERT_GREATER_HEX32(actual, expected)       TEST_ASSERT((uint32_t)(actual) >  (uint32_t)(expected), "32-bit Hexadecimal greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_HEX32(actual, expected)    TEST_ASSERT((uint32_t)(actual) <= (uint32_t)(expected), "32-bit Hexadecimal less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_HEX32(actual, expected) TEST_ASSERT((uint32_t)(actual) >= (uint32_t)(expected), "32-bit Hexadecimal greater-than-or-equal check failed")

#define TEST_ASSERT_EQUAL_HEX64(actual, expected)         TEST_ASSERT((uint64_t)(actual) == (uint64_t)(expected), "64-bit Hexadecimal equality check failed")
#define TEST_ASSERT_NOT_EQUAL_HEX64(actual, expected)     TEST_ASSERT((uint64_t)(actual) != (uint64_t)(expected), "64-bit Hexadecimal inequality check failed")
#define TEST_ASSERT_LESS_HEX64(actual, expected)          TEST_ASSERT((uint64_t)(actual) <  (uint64_t)(expected), "64-bit Hexadecimal less-than check failed")
#define TEST_ASSERT_GREATER_HEX64(actual, expected)       TEST_ASSERT((uint64_t)(actual) >  (uint64_t)(expected), "64-bit Hexadecimal greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_HEX64(actual, expected)    TEST_ASSERT((uint64_t)(actual) <= (uint64_t)(expected), "64-bit Hexadecimal less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_HEX64(actual, expected) TEST_ASSERT((uint64_t)(actual) >= (uint64_t)(expected), "64-bit Hexadecimal greater-than-or-equal check failed")

/**
 * @brief Octal Assertion Macros
 *
 * These macros are designed for asserting octal integer values using various comparison operations.
 * They provide a way to verify octal equality, inequality, and order (less than, greater than, etc.)
 * between octal integer values.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_OCT to check if two octal values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_OCT to assert that two octal values are not equal.
 *   - Use TEST_ASSERT_LESS_OCT to check if one octal value is less than another.
 *   - Use TEST_ASSERT_GREATER_OCT to verify that one octal value is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_OCT to assert that one octal value is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_OCT to verify that one octal value is greater than or equal to another.
 *
 * @param actual     The actual octal integer value for the assertion.
 * @param expected   The expected octal integer value for comparison.
 *
 * @return None
 */


#define TEST_ASSERT_EQUAL_OCT(actual, expected)         TEST_ASSERT((signed)(actual) == (signed)(expected), "Octal equality check failed")
#define TEST_ASSERT_NOT_EQUAL_OCT(actual, expected)     TEST_ASSERT((signed)(actual) != (signed)(expected), "Octal inequality check failed")
#define TEST_ASSERT_LESS_OCT(actual, expected)          TEST_ASSERT((signed)(actual) <  (signed)(expected), "Octal less-than check failed")
#define TEST_ASSERT_GREATER_OCT(actual, expected)       TEST_ASSERT((signed)(actual) >  (signed)(expected), "Octal greater-than check failed")
#define TEST_ASSERT_LESS_EQUAL_OCT(actual, expected)    TEST_ASSERT((signed)(actual) <= (signed)(expected), "Octal less-than-or-equal check failed")
#define TEST_ASSERT_GREATER_EQUAL_OCT(actual, expected) TEST_ASSERT((signed)(actual) >= (signed)(expected), "Octal greater-than-or-equal check failed")

/**
 * @brief Bitwise Assertion Macros
 *
 * These macros are designed for asserting bitwise conditions and operations on integer values.
 * They provide a way to verify whether specific bits are set or unset in integer values, compare
 * integer values using bitwise operations, and check if specific bits meet the expected criteria.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_BIT_EQUAL to check if two values are equal using bitwise comparison.
 *   - Use TEST_ASSERT_BIT_NOT_EQUAL to assert that two values are not equal using bitwise comparison.
 *   - Use TEST_ASSERT_BIT_LESS to check if one value is less than another using bitwise comparison.
 *   - Use TEST_ASSERT_BIT_GREATER to verify that one value is greater than another using bitwise comparison.
 *   - Use TEST_ASSERT_BIT_NOT_HIGH to assert that a specific bit is not set (high) in an integer value.
 *   - Use TEST_ASSERT_BIT_HIGH to verify that a specific bit is set (high) in an integer value.
 *   - Use TEST_ASSERT_BIT_NOT_LOW to assert that a specific bit is not unset (low) in an integer value.
 *   - Use TEST_ASSERT_BIT_LOW to verify that a specific bit is unset (low) in an integer value.
 *   - Use TEST_ASSERT_BITS_NOT_HIGH to check that specific bits are not all set (high) in an integer value.
 *   - Use TEST_ASSERT_BITS_HIGH to assert that specific bits are all set (high) in an integer value.
 *   - Use TEST_ASSERT_BITS_NOT_LOW to check that specific bits are not all unset (low) in an integer value.
 *   - Use TEST_ASSERT_BITS_LOW to verify that specific bits are all unset (low) in an integer value.
 *   - Use TEST_ASSERT_BITS_NOT_EQUAL to check bitwise equality within a specific mask.
 *   - Use TEST_ASSERT_BITS_EQUAL to verify bitwise inequality within a specific mask.
 *   - Use TEST_ASSERT_BITS_NOT_LESS to assert that one value is not less than another within a mask.
 *   - Use TEST_ASSERT_BITS_LESS to check if one value is less than another within a mask.
 *   - Use TEST_ASSERT_BITS_NOT_GREATER to assert that one value is not greater than another within a mask.
 *   - Use TEST_ASSERT_BITS_GREATER to verify if one value is greater than another within a mask.
 *   - Use TEST_ASSERT_BITS_NOT_LESS_EQUAL to assert that one value is not less than or equal to another within a mask.
 *   - Use TEST_ASSERT_BITS_LESS_EQUAL to check if one value is less than or equal to another within a mask.
 *   - Use TEST_ASSERT_BITS_NOT_GREATER_EQUAL to assert that one value is not greater than or equal to another within a mask.
 *   - Use TEST_ASSERT_BITS_GREATER_EQUAL to verify if one value is greater than or equal to another within a mask.
 *
 * @param actual     The actual integer value or bit mask for the assertion.
 * @param expected   The expected integer value for comparison.
 * @param bitIndex   The bit index to check for high or low conditions.
 * @param mask       The bit mask to apply to the bitwise operations.
 *
 * @return None
 */

#define TEST_ASSERT_BIT_EQUAL(actual, expected)            TEST_ASSERT((signed)(actual) == (signed)(expected), "Bitwise equality check failed")
#define TEST_ASSERT_BIT_NOT_EQUAL(actual, expected)        TEST_ASSERT((signed)(actual) != (signed)(expected), "Bitwise inequality check failed")
#define TEST_ASSERT_BIT_LESS(actual, expected)             TEST_ASSERT((signed)(actual) <  (signed)(expected), "Bitwise less-than check failed")
#define TEST_ASSERT_BIT_GREATER(actual, expected)          TEST_ASSERT((signed)(actual) >  (signed)(expected), "Bitwise greater-than check failed")
#define TEST_ASSERT_BIT_LESS_EQUAL(actual, expected)       TEST_ASSERT((signed)(actual) <= (signed)(expected), "Bitwise less-than-or-equal check failed")
#define TEST_ASSERT_BIT_GREATER_EQUAL(actual, expected)    TEST_ASSERT((signed)(actual) >= (signed)(expected), "Bitwise greater-than-or-equal check failed")
#define TEST_ASSERT_BIT_NOT_HIGH(value, bitIndex)          TEST_ASSERT(!((signed)(value) & (1 << (signed)(bitIndex))), "Bit is high check failed")
#define TEST_ASSERT_BIT_HIGH(value, bitIndex)              TEST_ASSERT((signed)(value) &   (1 << (signed)(bitIndex)), "Bit is not high check failed")
#define TEST_ASSERT_BIT_NOT_LOW(value, bitIndex)           TEST_ASSERT((signed)(value) &   (1 << (signed)(bitIndex)), "Bit is low check failed")
#define TEST_ASSERT_BIT_LOW(value, bitIndex)               TEST_ASSERT(!((signed)(value) & (1 << (signed)(bitIndex))), "Bit is not low check failed")

#define TEST_ASSERT_BITS_NOT_HIGH(value, mask)             TEST_ASSERT(((signed)(value) & (signed)(mask)) != (signed)(mask), "Bits are all high check failed")
#define TEST_ASSERT_BITS_HIGH(value, mask)                 TEST_ASSERT(((signed)(value) & (signed)(mask)) == (signed)(mask), "Bits are not all high check failed")
#define TEST_ASSERT_BITS_NOT_LOW(value, mask)              TEST_ASSERT(((signed)(value) & (signed)(mask)) != 0, "Bits are not all low check failed")
#define TEST_ASSERT_BITS_LOW(value, mask)                  TEST_ASSERT(((signed)(value) & (signed)(mask)) == 0, "Bits are not all low check failed")
#define TEST_ASSERT_BITS_NOT_EQUAL(actual, expected, mask) TEST_ASSERT(((signed)(actual) & (signed)(mask)) != ((signed)(expected) & (signed)(mask)), "Bitwise equality check failed")
#define TEST_ASSERT_BITS_EQUAL(actual, expected, mask)     TEST_ASSERT(((signed)(actual) & (signed)(mask)) == ((signed)(expected) & (signed)(mask)), "Bitwise inequality check failed")
#define TEST_ASSERT_BITS_NOT_LESS(actual, expected, mask)  TEST_ASSERT(((signed)(actual) & (signed)(mask)) >= ((signed)(expected) & (signed)(mask)), "Bitwise less-than check failed")
#define TEST_ASSERT_BITS_LESS(actual, expected, mask)      TEST_ASSERT(((signed)(actual) & (signed)(mask)) < ((signed)(expected) & (signed)(mask)), "Bitwise greater-than check failed")
#define TEST_ASSERT_BITS_NOT_GREATER(actual, expected, mask)            TEST_ASSERT(((signed)(actual) & (signed)(mask)) <= ((signed)(expected) & (signed)(mask)), "Bitwise less-than-or-equal check failed")
#define TEST_ASSERT_BITS_GREATER(actual, expected, mask)                TEST_ASSERT(((signed)(actual) & (signed)(mask)) > ((signed)(expected) & (signed)(mask)), "Bitwise greater-than-or-equal check failed")
#define TEST_ASSERT_BITS_NOT_LESS_EQUAL(actual, expected, mask)         TEST_ASSERT(((signed)(actual) & (signed)(mask)) > ((signed)(expected) & (signed)(mask)), "Bitwise less-than-or-equal check failed")
#define TEST_ASSERT_BITS_LESS_EQUAL(actual, expected, mask)             TEST_ASSERT(((signed)(actual) & (signed)(mask)) <= ((signed)(expected) & (signed)(mask)), "Bitwise greater-than-or-equal check failed")
#define TEST_ASSERT_BITS_NOT_GREATER_EQUAL(actual, expected, mask)      TEST_ASSERT(((signed)(actual) & (signed)(mask)) < ((signed)(expected) & (signed)(mask)), "Bitwise less-than-or-equal check failed")
#define TEST_ASSERT_BITS_GREATER_EQUAL(actual, expected, mask)          TEST_ASSERT(((signed)(actual) & (signed)(mask)) >= ((signed)(expected) & (signed)(mask)), "Bitwise greater-than-or-equal check failed")

/**
 * @brief Within Tolerance Assertion Macros
 *
 * These macros are designed for asserting that a value is within a specified tolerance range.
 * They are provided for various data types and use cases. You can use these macros to check if
 * an integer, floating-point, hexadecimal, binary, or octal value is within a defined tolerance
 * range. For integer types, you can specify a tolerance value, and for floating-point values,
 * you can specify an epsilon value for tolerance.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_INT_WITHIN to check if an integer is within a tolerance range.
 *   - Use TEST_ASSERT_UINT_WITHIN to validate an unsigned integer within a tolerance range.
 *   - Use TEST_ASSERT_HEX_WITHIN to assert that a hexadecimal value is within a tolerance range.
 *   - Use TEST_ASSERT_BIN_WITHIN to confirm that a binary value is within a tolerance range.
 *   - Use TEST_ASSERT_OCT_WITHIN to check if an octal value is within a tolerance range.
 *   - Use TEST_ASSERT_FLOAT_WITHIN to verify that a float value is within a specified epsilon.
 *   - Use TEST_ASSERT_DOUBLE_WITHIN to check if a double value is within a specified epsilon.
 *   - Use TEST_ASSERT_CHAR_WITHIN to assert that a character value is within a specified range.
 *   - Use TEST_ASSERT_WCHAR_WITHIN to validate a wide character value within a specified range.
 *
 * @param actual    The actual value to check for tolerance.
 * @param expected  The expected value to compare with.
 * @param tolerance The tolerance range for integer values.
 * @param epsilon   The epsilon value for floating-point values.
 * @param min       The minimum range boundary for character types.
 * @param max       The maximum range boundary for character types.
 *
 * @return None
 */

#define TEST_ASSERT_INT_WITHIN(actual, expected, tolerance)     TEST_ASSERT(((signed)(actual)  >= ((signed)(expected)  - (signed)(tolerance)))  && ((signed)(actual)  <= ((signed)(expected)  + (signed)(tolerance))),  "Integer value not within tolerance")
#define TEST_ASSERT_INT8_WITHIN(actual, expected, tolerance)    TEST_ASSERT(((int8_t)(actual)  >= ((int8_t)(expected)  - (int8_t)(tolerance)))  && ((int8_t)(actual)  <= ((int8_t)(expected)  + (int8_t)(tolerance))),  "8-bit Integer value not within tolerance")
#define TEST_ASSERT_INT16_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((int16_t)(actual) >= ((int16_t)(expected) - (int16_t)(tolerance))) && ((int16_t)(actual) <= ((int16_t)(expected) + (int16_t)(tolerance))), "16-bit Integer value not within tolerance")
#define TEST_ASSERT_INT32_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((int32_t)(actual) >= ((int32_t)(expected) - (int32_t)(tolerance))) && ((int32_t)(actual) <= ((int32_t)(expected) + (int32_t)(tolerance))), "32-bit Integer value not within tolerance")
#define TEST_ASSERT_INT64_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((int64_t)(actual) >= ((int64_t)(expected) - (int64_t)(tolerance))) && ((int64_t)(actual) <= ((int64_t)(expected) + (int64_t)(tolerance))), "64-bit Integer value not within tolerance")
#define TEST_ASSERT_UINT_WITHIN(actual, expected, tolerance)    TEST_ASSERT(((unsigned)(actual) >= ((unsigned)(expected) - (unsigned)(tolerance))) && ((unsigned)(actual) <= ((unsigned)(expected) + (unsigned)(tolerance))), "Unsigned integer value not within tolerance")
#define TEST_ASSERT_UINT8_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((uint8_t)(actual)  >= ((uint8_t)(expected)  - (uint8_t)(tolerance)))  && ((uint8_t)(actual)  <= ((uint8_t)(expected)  + (uint8_t)(tolerance))),  "8-bit Unsigned Integer value not within tolerance")
#define TEST_ASSERT_UINT16_WITHIN(actual, expected, tolerance)  TEST_ASSERT(((uint16_t)(actual) >= ((uint16_t)(expected) - (uint16_t)(tolerance))) && ((uint16_t)(actual) <= ((uint16_t)(expected) + (uint16_t)(tolerance))), "16-bit Unsigned Integer value not within tolerance")
#define TEST_ASSERT_UINT32_WITHIN(actual, expected, tolerance)  TEST_ASSERT(((uint32_t)(actual) >= ((uint32_t)(expected) - (uint32_t)(tolerance))) && ((uint32_t)(actual) <= ((uint32_t)(expected) + (uint32_t)(tolerance))), "32-bit Unsigned Integer value not within tolerance")
#define TEST_ASSERT_UINT64_WITHIN(actual, expected, tolerance)  TEST_ASSERT(((uint64_t)(actual) >= ((uint64_t)(expected) - (uint64_t)(tolerance))) && ((uint64_t)(actual) <= ((uint64_t)(expected) + (uint64_t)(tolerance))), "64-bit Unsigned Integer value not within tolerance")
#define TEST_ASSERT_HEX_WITHIN(actual, expected, tolerance)     TEST_ASSERT(((signed)(actual)   >= ((signed)(expected)   - (signed)(tolerance)))   && ((signed)(actual)   <= ((signed)(expected)   + (signed)(tolerance))),   "Hexadecimal value not within tolerance")
#define TEST_ASSERT_HEX8_WITHIN(actual, expected, tolerance)    TEST_ASSERT(((uint8_t)(actual)  >= ((uint8_t)(expected)  - (uint8_t)(tolerance)))  && ((uint8_t)(actual)  <= ((uint8_t)(expected)  + (uint8_t)(tolerance))),  "8-bit Hexadecimal value not within tolerance")
#define TEST_ASSERT_HEX16_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((uint16_t)(actual) >= ((uint16_t)(expected) - (uint16_t)(tolerance))) && ((uint16_t)(actual) <= ((uint16_t)(expected) + (uint16_t)(tolerance))), "16-bit Hexadecimal value not within tolerance")
#define TEST_ASSERT_HEX32_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((uint32_t)(actual) >= ((uint32_t)(expected) - (uint32_t)(tolerance))) && ((uint32_t)(actual) <= ((uint32_t)(expected) + (uint32_t)(tolerance))), "32-bit Hexadecimal value not within tolerance")
#define TEST_ASSERT_HEX64_WITHIN(actual, expected, tolerance)   TEST_ASSERT(((uint64_t)(actual) >= ((uint64_t)(expected) - (uint64_t)(tolerance))) && ((uint64_t)(actual) <= ((uint64_t)(expected) + (uint64_t)(tolerance))), "64-bit Hexadecimal value not within tolerance")
#define TEST_ASSERT_BIN_WITHIN(actual, expected, tolerance)     TEST_ASSERT(((signed)(actual) >= ((signed)(expected) - (signed)(tolerance))) && ((signed)(actual) <= ((signed)(expected) + (signed)(tolerance))), "Binary value not within tolerance")
#define TEST_ASSERT_OCT_WITHIN(actual, expected, tolerance)     TEST_ASSERT(((signed)(actual) >= ((signed)(expected) - (signed)(tolerance))) && ((signed)(actual) <= ((signed)(expected) + (signed)(tolerance))), "Octal value not within tolerance")

#define TEST_ASSERT_FLOAT_WITHIN(actual, expected, epsilon)     TEST_ASSERT(fabs((float)(actual) - (float)(expected)) <= (float)(epsilon), "Float value not within epsilon")
#define TEST_ASSERT_DOUBLE_WITHIN(actual, expected, epsilon)    TEST_ASSERT(fabs((double)(actual) - (double)(expected)) <= (double)(epsilon), "Double value not within epsilon")

#define TEST_ASSERT_CHAR_WITHIN(actual, min, max)               TEST_ASSERT((actual) > (min) || (actual) < (max), "Character value not within range")
#define TEST_ASSERT_WCHAR_WITHIN(actual, min, max)              TEST_ASSERT((actual) > (min) || (actual) < (max), "W-Character value not within range")

/**
 * @brief Single-Precision (Float) Assertion Macros
 *
 * These macros are designed to assist in asserting conditions related to single-precision
 * floating-point values (float). They cover various aspects of single-precision equality,
 * inequality, comparison, checks for infinity, finite values, and NaN (Not-a-Number) values.
 * These macros also allow for checking the determinacy of single-precision values, ensuring
 * they are not NaN or infinite. These macros are suitable for validating single-precision
 * floating-point numbers in tests and ensuring that they meet the expected conditions.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_FLOAT_EQUAL to check if two float values are equal within epsilon.
 *   - Use TEST_ASSERT_FLOAT_NOT_EQUAL to verify that two float values are not equal within epsilon.
 *   - Use TEST_ASSERT_FLOAT_LESS to assert that one value is less than another.
 *   - Use TEST_ASSERT_FLOAT_GREATER to confirm that one value is greater than another.
 *   - Use TEST_ASSERT_FLOAT_LESS_EQUAL to check if one value is less than or equal to another.
 *   - Use TEST_ASSERT_FLOAT_GREATER_EQUAL to determine if one value is greater than or equal to another.
 *   - Use TEST_ASSERT_FLOAT_IS_NOT_INF to verify that a value is not positive infinity.
 *   - Use TEST_ASSERT_FLOAT_IS_INF to check if a value is positive infinity.
 *   - Use TEST_ASSERT_FLOAT_IS_NOT_NEG_INF to verify that a value is not negative infinity.
 *   - Use TEST_ASSERT_FLOAT_IS_NEG_INF to check if a value is negative infinity.
 *   - Use TEST_ASSERT_FLOAT_IS_NOT_FINITE to ensure that a value is not finite.
 *   - Use TEST_ASSERT_FLOAT_IS_FINITE to confirm that a value is finite.
 *   - Use TEST_ASSERT_FLOAT_IS_NOT_NAN to check if a value is not NaN.
 *   - Use TEST_ASSERT_FLOAT_IS_NAN to verify that a value is NaN.
 *   - Use TEST_ASSERT_FLOAT_IS_DETERMINATE to check if a value is deterministic (not NaN or infinite).
 *   - Use TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE to ensure that a value is not deterministic (NaN or infinite).
 *
 * @param actual    The actual single-precision (float) value for comparison.
 * @param expected  The expected single-precision (float) value for comparison.
 * @param value     The single-precision (float) value for specific checks (e.g., infinity, finite, NaN).
 *
 * @return None
 */

#define TEST_ASSERT_FLOAT_EQUAL(actual, expected)         TEST_ASSERT(fabs((float)(actual) -  (float)(expected)) < ASSERT_FLOAT_EPSILON, "Floating-point value not equal within epsilon")
#define TEST_ASSERT_FLOAT_NOT_EQUAL(actual, expected)     TEST_ASSERT(fabs((float)(actual) -  (float)(expected)) <= ASSERT_FLOAT_EPSILON, "Floating-point value equal within epsilon")
#define TEST_ASSERT_FLOAT_LESS(actual, expected)          TEST_ASSERT((float)(actual)      <  (float)(expected),   "Floating-point value not less")
#define TEST_ASSERT_FLOAT_GREATER(actual, expected)       TEST_ASSERT((float)(actual)      >  (float)(expected),   "Floating-point value not greater")
#define TEST_ASSERT_FLOAT_GREATER_EQUAL(actual, expected) TEST_ASSERT((float)(actual)      >= (float)(expected),   "Floating-point value not greater or equal")
#define TEST_ASSERT_FLOAT_LESS_EQUAL(actual, expected)    TEST_ASSERT((float)(actual)      <= (float)(expected),   "Floating-point value not less or equal")
#define TEST_ASSERT_FLOAT_IS_NOT_INF(value)               TEST_ASSERT(!isinf((float)value) || (float)(value) <= 0, "Floating-point value is infinite")
#define TEST_ASSERT_FLOAT_IS_INF(value)                   TEST_ASSERT(isinf((float)value)  && (float)(value) > 0,  "Floating-point value is not positive infinity")
#define TEST_ASSERT_FLOAT_IS_NOT_NEG_INF(value)           TEST_ASSERT(!isinf((float)value) || (float)(value) >= 0, "Floating-point value is negative infinity")
#define TEST_ASSERT_FLOAT_IS_NEG_INF(value)               TEST_ASSERT(isinf((float)value)  && (float)(value) < 0,  "Floating-point value is not negative infinity")
#define TEST_ASSERT_FLOAT_IS_NOT_FINITE(value)            TEST_ASSERT(!isfinite((float)value), "Floating-point value is finite")
#define TEST_ASSERT_FLOAT_IS_FINITE(value)                TEST_ASSERT(isfinite((float)value),  "Floating-point value is not finite")
#define TEST_ASSERT_FLOAT_IS_NOT_NAN(value)               TEST_ASSERT(!isnan((float)value),    "Floating-point value is NaN")
#define TEST_ASSERT_FLOAT_IS_NAN(value)                   TEST_ASSERT(isnan((float)value),     "Floating-point value is not NaN")
#define TEST_ASSERT_FLOAT_IS_DETERMINATE(actual)         TEST_ASSERT(!isnan((float)actual) && isfinite((float)actual), "Floating-precision value not deterministic")
#define TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE(actual)     TEST_ASSERT(isnan((float)actual)  || isinf((float)actual),    "Floating-precision value deterministic")

/**
 * @brief Double-Precision Assertion Macros
 *
 * These macros are designed to assist in asserting conditions related to double-precision
 * floating-point values. They cover various aspects of double-precision equality, inequality,
 * comparison, checks for infinity, finite values, and NaN (Not-a-Number) values. These macros
 * also allow for checking the determinacy of double-precision values, ensuring they are not NaN
 * or infinite. These macros are suitable for validating double-precision floating-point
 * numbers in tests and ensuring that they meet the expected conditions.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_DOUBLE_EQUAL to check if two double-precision values are equal within epsilon.
 *   - Use TEST_ASSERT_DOUBLE_NOT_EQUAL to verify that two double-precision values are not equal
 *     within epsilon.
 *   - Use TEST_ASSERT_DOUBLE_LESS to assert that one value is less than another.
 *   - Use TEST_ASSERT_DOUBLE_GREATER to confirm that one value is greater than another.
 *   - Use TEST_ASSERT_DOUBLE_LESS_EQUAL to check if one value is less than or equal to another.
 *   - Use TEST_ASSERT_DOUBLE_GREATER_EQUAL to determine if one value is greater than or equal to another.
 *   - Use TEST_ASSERT_DOUBLE_IS_NOT_INF to verify that a value is not positive infinity.
 *   - Use TEST_ASSERT_DOUBLE_IS_INF to check if a value is positive infinity.
 *   - Use TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF to verify that a value is not negative infinity.
 *   - Use TEST_ASSERT_DOUBLE_IS_NEG_INF to check if a value is negative infinity.
 *   - Use TEST_ASSERT_DOUBLE_IS_NOT_FINITE to ensure that a value is not finite.
 *   - Use TEST_ASSERT_DOUBLE_IS_FINITE to confirm that a value is finite.
 *   - Use TEST_ASSERT_DOUBLE_IS_NOT_NAN to check if a value is not NaN.
 *   - Use TEST_ASSERT_DOUBLE_IS_NAN to verify that a value is NaN.
 *   - Use TEST_ASSERT_DOUBLE_IS_DETERMINATE to check if a value is deterministic (not NaN or infinite).
 *   - Use TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE to ensure that a value is not deterministic (NaN or infinite).
 *
 * @param actual    The actual double-precision value for comparison.
 * @param expected  The expected double-precision value for comparison.
 * @param value     The double-precision value for specific checks (e.g., infinity, finite, NaN).
 *
 * @return None
 */

#define TEST_ASSERT_DOUBLE_EQUAL(actual, expected)         TEST_ASSERT(fabs((double)(actual) - (double)(expected)) <  ASSERT_DOUBLE_EPSILON, "Double-precision value not equal within epsilon")
#define TEST_ASSERT_DOUBLE_NOT_EQUAL(actual, expected)     TEST_ASSERT(fabs((double)(actual) - (double)(expected)) <= ASSERT_DOUBLE_EPSILON, "Double-precision value equal within epsilon")
#define TEST_ASSERT_DOUBLE_LESS(actual, expected)          TEST_ASSERT((double)(actual) <  (double)(expected), "Double-precision value not less")
#define TEST_ASSERT_DOUBLE_GREATER(actual, expected)       TEST_ASSERT((double)(actual) >  (double)(expected), "Double-precision value not greater")
#define TEST_ASSERT_DOUBLE_GREATER_EQUAL(actual, expected) TEST_ASSERT((double)(actual) >= (double)(expected), "Double-precision value not greater or equal")
#define TEST_ASSERT_DOUBLE_LESS_EQUAL(actual, expected)    TEST_ASSERT((double)(actual) <= (double)(expected), "Double-precision value not less or equal")
#define TEST_ASSERT_DOUBLE_IS_NOT_INF(value)               TEST_ASSERT(!isinf((double)value) || (double)(value) <= 0, "Double-precision value is infinite")
#define TEST_ASSERT_DOUBLE_IS_INF(value)                   TEST_ASSERT(isinf((double)value) &&  (double)(value) > 0,  "Double-precision value is not positive infinity")
#define TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF(value)           TEST_ASSERT(!isinf((double)value) || (double)(value) >= 0, "Double-precision value is negative infinity")
#define TEST_ASSERT_DOUBLE_IS_NEG_INF(value)               TEST_ASSERT(isinf((double)value) &&  (double)(value) < 0,  "Double-precision value is not negative infinity")
#define TEST_ASSERT_DOUBLE_IS_NOT_FINITE(value)            TEST_ASSERT(!isfinite((double)value), "Double-precision value is finite")
#define TEST_ASSERT_DOUBLE_IS_FINITE(value)                TEST_ASSERT(isfinite((double)value),  "Double-precision value is not finite")
#define TEST_ASSERT_DOUBLE_IS_NOT_NAN(value)               TEST_ASSERT(!isnan((double)value),    "Double-precision value is NaN")
#define TEST_ASSERT_DOUBLE_IS_NAN(value)                   TEST_ASSERT(isnan((double)value),     "Double-precision value is not NaN")
#define TEST_ASSERT_DOUBLE_IS_DETERMINATE(actual)          TEST_ASSERT(!isnan((double)actual) && isfinite((double)actual), "Double-precision value not deterministic")
#define TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE(actual)      TEST_ASSERT(isnan((double)actual)  || isinf((double)actual),    "Double-precision value deterministic")

/**
 * @brief Pointer Assertion Macros
 *
 * These macros are designed to assist in asserting conditions related to pointers and memory access.
 * They provide a way to check for null pointers, non-null pointers, empty and non-empty pointers,
 * invalid memory access, and array index bounds. Additionally, these macros enable pointer equality,
 * inequality, and comparison. These macros are suitable for both C and C++ code, where C++ uses nullptr
 * while C uses NULL for null pointer checks.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_NULL_PTR to verify a null pointer.
 *   - Use TEST_ASSERT_NOT_NULL_PTR to ensure a non-null pointer.
 *   - Use TEST_ASSERT_EMPTY_PTR to check for an empty pointer (null in C).
 *   - Use TEST_ASSERT_NOT_EMPTY_PTR to check for a non-empty pointer (not null in C).
 *   - Use TEST_ASSERT_INVALID_MEMORY_ACCESS_PTR to assert invalid memory access.
 *   - Use TEST_ASSERT_ARRAY_BOUNDS_PTR to check if an array index is within bounds.
 *   - Use TEST_ASSERT_EQUAL_PTR to check if two pointers are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_PTR to check if two pointers are not equal.
 *   - Use TEST_ASSERT_LESS_PTR to check if one pointer is less than another.
 *   - Use TEST_ASSERT_GREATER_PTR to check if one pointer is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_PTR to check if one pointer is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_PTR to check if one pointer is greater than or equal to another.
 *
 * @param pointer A pointer to be tested.
 * @param index   The index for array bounds checking.
 * @param size    The size of the array (for array bounds checking).
 * @param actual  The actual pointer for comparison (for pointer equality and comparisons).
 * @param expected The expected pointer for comparison (for pointer equality and comparisons).
 *
 * @return None
 */

#ifdef __cplusplus
#define TEST_ASSERT_NULL_PTR(pointer)      TEST_ASSERT((pointer) == nullptr, "Expected nullptr")
#define TEST_ASSERT_NOT_NULL_PTR(pointer)  TEST_ASSERT((pointer) != nullptr, "Expected not nullptr")
#define TEST_ASSERT_INVALID_PTR(pointer)   TEST_ASSERT((pointer) != nullptr, "Invalid pointer error")
#define TEST_ASSERT_EMPTY_PTR(pointer)     TEST_ASSERT((pointer) == nullptr, "Expected empty pointer")
#define TEST_ASSERT_NOT_EMPTY_PTR(pointer) TEST_ASSERT((pointer) != nullptr, "Expected not empty pointer")
#define TEST_ASSERT_INVALID_MEMORY_ACCESS_PTR(pointer) TEST_ASSERT(pointer != nullptr, "Invalid memory access")
#else
#define TEST_ASSERT_NULL_PTR(pointer)      TEST_ASSERT((pointer) == NULL, "Expected NULL")
#define TEST_ASSERT_NOT_NULL_PTR(pointer)  TEST_ASSERT((pointer) != NULL, "Expected not NULL")
#define TEST_ASSERT_INVALID_PTR(pointer)   TEST_ASSERT((pointer) != NULL, "Invalid pointer error")
#define TEST_ASSERT_EMPTY_PTR(pointer)     TEST_ASSERT((pointer) == NULL, "Expected empty pointer")
#define TEST_ASSERT_NOT_EMPTY_PTR(pointer) TEST_ASSERT((pointer) != NULL, "Expected not empty pointer")
#define TEST_ASSERT_INVALID_MEMORY_ACCESS_PTR(pointer) TEST_ASSERT(pointer != NULL, "Invalid memory access")
#endif
#define TEST_ASSERT_ARRAY_BOUNDS_PTR(pointer, index, size) TEST_ASSERT((index) >= 0 && (index) < (size), "Array index out of bounds")
#define TEST_ASSERT_EQUAL_PTR(actual, expected)            TEST_ASSERT((actual) == (expected), "Pointer equality check failed")
#define TEST_ASSERT_NOT_EQUAL_PTR(actual, expected)        TEST_ASSERT((actual) != (expected), "Pointer inequality check failed")
#define TEST_ASSERT_LESS_PTR(actual, expected)             TEST_ASSERT((actual) < (expected), "Pointer less than comparison failed")
#define TEST_ASSERT_GREATER_PTR(actual, expected)          TEST_ASSERT((actual) > (expected), "Pointer greater than comparison failed")
#define TEST_ASSERT_LESS_EQUAL_PTR(actual, expected)       TEST_ASSERT((actual) <= (expected), "Pointer less than or equal comparison failed")
#define TEST_ASSERT_GREATER_EQUAL_PTR(actual, expected)    TEST_ASSERT((actual) >= (expected), "Pointer greater than or equal comparison failed")

/**
 * @brief String Assertion Macros
 *
 * These macros are used to assert expectations related to C and C++ string values. They allow you to check for
 * equality, inequality, string length, substring presence, prefix/suffix matches, and case-insensitive comparisons.
 * The behavior of these macros differs based on whether you are using C or C++.
 *
 * Usage Example (C++):
 *   - Use TEST_ASSERT_EQUAL_STRING to check if two C++ strings are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_STRING to assert that two C++ strings are not equal.
 *   - Use TEST_ASSERT_LENGTH_STRING to check if the length of a C++ string matches the expected value.
 *   - Use TEST_ASSERT_CONTAINS_SUBSTRING_STRING to check if a substring is present in a C++ string.
 *   - Use TEST_ASSERT_NOT_CONTAINS_SUBSTRING_STRING to check if a substring is not present in a C++ string.
 *   - Use TEST_ASSERT_STARTS_WITH_STRING to check if a C++ string starts with the specified prefix.
 *   - Use TEST_ASSERT_ENDS_WITH_STRING to check if a C++ string ends with the specified suffix.
 *   - Use TEST_ASSERT_EQUAL_CASE_INSENSITIVE_STRING for case-insensitive string equality comparisons.
 *   - Use TEST_ASSERT_NOT_EQUAL_CASE_INSENSITIVE_STRING for case-insensitive string inequality comparisons.
 *
 * Usage Example (C):
 *   - Replace "TEST_ASSERT_EQUAL_STRING" with "TEST_ASSERT_EQUAL_STRING" for comparing C strings.
 *   - Replace "TEST_ASSERT_NOT_EQUAL_STRING" with "TEST_ASSERT_NOT_EQUAL_STRING" for comparing C strings.
 *   - Replace "TEST_ASSERT_LENGTH_STRING" with "TEST_ASSERT_LENGTH_STRING" for checking C string length.
 *   - Replace "TEST_ASSERT_CONTAINS_SUBSTRING_STRING" with "TEST_ASSERT_CONTAINS_SUBSTRING_STRING" for substring presence.
 *   - Replace "TEST_ASSERT_NOT_CONTAINS_SUBSTRING_STRING" with "TEST_ASSERT_NOT_CONTAINS_SUBSTRING_STRING" for absence.
 *   - Replace "TEST_ASSERT_STARTS_WITH_STRING" with "TEST_ASSERT_STARTS_WITH_STRING" for prefix checks.
 *   - Replace "TEST_ASSERT_ENDS_WITH_STRING" with "TEST_ASSERT_ENDS_WITH_STRING" for suffix checks.
 *   - Replace "TEST_ASSERT_EQUAL_CASE_INSENSITIVE_STRING" with "TEST_ASSERT_EQUAL_CASE_INSENSITIVE_STRING" for case-insensitive comparisons.
 *   - Replace "TEST_ASSERT_NOT_EQUAL_CASE_INSENSITIVE_STRING" with "TEST_ASSERT_NOT_EQUAL_CASE_INSENSITIVE_STRING" for case-insensitive inequality checks.
 *
 * @param actual      The actual string or C++ string value.
 * @param expected    The expected string or C++ string value for comparison.
 * @param string      The string to search for substrings and perform prefix/suffix checks.
 * @param substring   The substring to search for within the string.
 * @param prefix      The prefix to check at the beginning of the string.
 * @param suffix      The suffix to check at the end of the string.
 * @param min         The minimum value for character range checking.
 * @param max         The maximum value for character range checking.
 *
 * @return None
 */

#ifdef __cplusplus
#define TEST_ASSERT_EQUAL_STRING(actual, expected) TEST_ASSERT((actual) == (expected), "String equality expectation not met")
#define TEST_ASSERT_NOT_EQUAL_STRING(actual, expected) TEST_ASSERT((actual) != (expected), "String inequality expectation not met")
#define TEST_ASSERT_LENGTH_STRING(actual, expected) TEST_ASSERT((actual).length() == (expected), "String length expectation not met")
#define TEST_ASSERT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_ASSERT(strstr((string), (substring)) != nullptr, "Substring not found")
#define TEST_ASSERT_NOT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_ASSERT(strstr((string), (substring)) == nullptr, "Substring found")
#define TEST_ASSERT_STARTS_WITH_STRING(string, prefix) TEST_ASSERT(strncmp((string), (prefix), strlen(prefix)) == 0, "String doesn't start with the prefix")
#define TEST_ASSERT_ENDS_WITH_STRING(string, suffix) TEST_ASSERT(strstr((string), (suffix) != nullptr && (strlen(string) - strlen(suffix)) == (strstr(string, suffix) - string), "String doesn't end with the suffix"))
#define TEST_ASSERT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_ASSERT(stricmp((actual), (expected)) == 0, "Case-insensitive string equality expectation not met")
#define TEST_ASSERT_NOT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_ASSERT(stricmp((actual), (expected)) != 0, "Case-insensitive string inequality expectation not met")
#else
#define TEST_ASSERT_EQUAL_STRING(actual, expected) TEST_ASSERT(strcmp((actual), (expected)) == 0, "String equality expectation not met")
#define TEST_ASSERT_NOT_EQUAL_STRING(actual, expected) TEST_ASSERT(strcmp((actual), (expected)) != 0, "String inequality expectation not met")
#define TEST_ASSERT_LENGTH_STRING(actual, expected) TEST_ASSERT(strlen((actual)) == (expected), "String length expectation not met")
#define TEST_ASSERT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_ASSERT(strstr((string), (substring)) != NULL, "Substring not found")
#define TEST_ASSERT_NOT_CONTAINS_SUBSTRING_STRING(string, substring) TEST_ASSERT(strstr((string), (substring)) == NULL, "Substring found")
#define TEST_ASSERT_STARTS_WITH_STRING(string, prefix) TEST_ASSERT(strncmp((string), (prefix), strlen(prefix)) == 0, "String doesn't start with the prefix")
#define TEST_ASSERT_ENDS_WITH_STRING(string, suffix) TEST_ASSERT(strstr((string), (suffix) != NULL && (strlen(string) - strlen(suffix)) == (strstr(string, suffix) - string), "String doesn't end with the suffix"))
#define TEST_ASSERT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_ASSERT(stricmp((actual), (expected)) == 0, "Case-insensitive string equality expectation not met")
#define TEST_ASSERT_NOT_EQUAL_CASE_INSENSITIVE_STRING(actual, expected) TEST_ASSERT(stricmp((actual), (expected)) != 0, "Case-insensitive string inequality expectation not met")
#endif

/**
 * @brief Character and Wide Character Assertion Macros
 *
 * These macros are used to assert expectations related to character values, including equality, inequality,
 * ordering (less than, greater than, etc.), and range checks. The wide character versions apply to wide character
 * types (e.g., wchar_t), while the standard character versions are for char types.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_EQUAL_CHAR to check if two character values are equal.
 *   - Use TEST_ASSERT_NOT_EQUAL_CHAR to assert that two character values are not equal.
 *   - Use TEST_ASSERT_LESS_CHAR to check if one character value is less than another.
 *   - Use TEST_ASSERT_GREATER_CHAR to assert that one character value is greater than another.
 *   - Use TEST_ASSERT_LESS_EQUAL_CHAR to check if a character value is less than or equal to another.
 *   - Use TEST_ASSERT_GREATER_EQUAL_CHAR to assert that a character value is greater than or equal to another.
 *   - Use TEST_ASSERT_IN_RANGE_CHAR to check if a character is within a specified range.
 *   - Use TEST_ASSERT_IS_UPPERCASE_CHAR to check if a character is an uppercase character.
 *   - Use TEST_ASSERT_IS_LOWERCASE_CHAR to check if a character is a lowercase character.
 *   - Use TEST_ASSERT_TO_UPPER_CHAR to verify that converting a character to uppercase produces the expected result.
 *   - Use TEST_ASSERT_TO_LOWER_CHAR to verify that converting a character to lowercase produces the expected result.
 *   - Use TEST_ASSERT_EQUAL_WCHAR, TEST_ASSERT_NOT_EQUAL_WCHAR, and others for wide characters.
 *
 * @param actual      The actual character value.
 * @param expected    The expected character value for comparison.
 * @param character   A character value to be tested.
 * @param min         The minimum value for character range checking.
 * @param max         The maximum value for character range checking.
 *
 * @return None
 */

#define TEST_ASSERT_EQUAL_CHAR(actual, expected)          TEST_ASSERT((actual) == (expected), "Character equality expectation not met")
#define TEST_ASSERT_NOT_EQUAL_CHAR(actual, expected)      TEST_ASSERT((actual) != (expected), "Character inequality expectation not met")
#define TEST_ASSERT_LESS_CHAR(actual, expected)           TEST_ASSERT((actual) < (expected), "Character less-than expectation not met")
#define TEST_ASSERT_GREATER_CHAR(actual, expected)        TEST_ASSERT((actual) > (expected), "Character greater-than expectation not met")
#define TEST_ASSERT_LESS_EQUAL_CHAR(actual, expected)     TEST_ASSERT((actual) <= (expected), "Character less-than-or-equal expectation not met")
#define TEST_ASSERT_GREATER_EQUAL_CHAR(actual, expected)  TEST_ASSERT((actual) >= (expected), "Character greater-than-or-equal expectation not met")
#define TEST_ASSERT_IN_RANGE_CHAR(character, min, max)    TEST_ASSERT((character >= (min) && character <= (max)), "Character not in the specified range")
#define TEST_ASSERT_IS_UPPERCASE_CHAR(character)          TEST_ASSERT(isupper(character), "Character is not uppercase")
#define TEST_ASSERT_IS_LOWERCASE_CHAR(character)          TEST_ASSERT(islower(character), "Character is not lowercase")
#define TEST_ASSERT_TO_UPPER_CHAR(character)              TEST_ASSERT(toupper(character) == expected, "Character not converted to uppercase as expected")
#define TEST_ASSERT_TO_LOWER_CHAR(character)              TEST_ASSERT(tolower(character) == expected, "Character not converted to lowercase as expected")

#define TEST_ASSERT_EQUAL_WCHAR(actual, expected)         TEST_ASSERT((actual) == (expected), "Wide character equality expectation not met")
#define TEST_ASSERT_NOT_EQUAL_WCHAR(actual, expected)     TEST_ASSERT((actual) != (expected), "Wide character inequality expectation not met")
#define TEST_ASSERT_LESS_WCHAR(actual, expected)          TEST_ASSERT((actual) < (expected), "Wide character less-than expectation not met")
#define TEST_ASSERT_GREATER_WCHAR(actual, expected)       TEST_ASSERT((actual) > (expected), "Wide character greater-than expectation not met")
#define TEST_ASSERT_LESS_EQUAL_WCHAR(actual, expected)    TEST_ASSERT((actual) <= (expected), "Wide character less-than-or-equal expectation not met")
#define TEST_ASSERT_GREATER_EQUAL_WCHAR(actual, expected) TEST_ASSERT((actual) >= (expected), "Wide character greater-than-or-equal expectation not met")
#define TEST_ASSERT_IN_RANGE_WCHAR(character, min, max)   TEST_ASSERT((character >= (min) && character <= (max)), "Wide character not in the specified range")
#define TEST_ASSERT_IS_UPPERCASE_WCHAR(character)         TEST_ASSERT(iswupper(character), "Wide character is not uppercase")
#define TEST_ASSERT_IS_LOWERCASE_WCHAR(character)         TEST_ASSERT(iswlower(character), "Wide character is not lowercase")
#define TEST_ASSERT_TO_UPPER_WCHAR(character, expected)   TEST_ASSERT(towupper(character) == expected, "Wide character not converted to uppercase as expected")
#define TEST_ASSERT_TO_LOWER_WCHAR(character, expected)   TEST_ASSERT(towlower(character) == expected, "Wide character not converted to lowercase as expected")

/**
 * @brief Array Assertion Macros
 *
 * These macros are designed to assist in asserting conditions related to arrays.
 * They cover a wide range of use cases, from validating array size and index bounds
 * to checking for equality and valid operations on array elements. Additionally, there
 * are specific macros for comparing arrays of various data types, including integers,
 * hexadecimals, floats, doubles, pointers, strings, and memory. These macros are intended
 * for use in testing and validation to ensure the correctness of array-related operations.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_INVALID_SIZE_ARRAY to check for invalid array size.
 *   - Use TEST_ASSERT_INDEX_OUT_OF_BOUNDS_ARRAY to validate array index bounds.
 *   - Use TEST_ASSERT_NULL_POINTER_ARRAY to verify a non-null array pointer.
 *   - Use TEST_ASSERT_INVALID_OPERATION_ARRAY to assert custom array operation conditions.
 *   - Use TEST_ASSERT_EQUAL_INT_ARRAY, TEST_ASSERT_EQUAL_INT8_ARRAY, and so on, to compare
 *     arrays of various integer types for equality.
 *   - Use TEST_ASSERT_EQUAL_HEX_ARRAY, TEST_ASSERT_EQUAL_HEX8_ARRAY, and so on, to compare
 *     arrays of hexadecimal values for equality.
 *   - Use TEST_ASSERT_EQUAL_FLOAT_ARRAY to compare arrays of float numbers for equality.
 *   - Use TEST_ASSERT_EQUAL_DOUBLE_ARRAY to compare arrays of double numbers for equality.
 *   - Use TEST_ASSERT_EQUAL_PTR_ARRAY to compare arrays of pointers for equality.
 *   - Use TEST_ASSERT_EQUAL_STRING_ARRAY to compare arrays of strings for equality.
 *   - Use TEST_ASSERT_EQUAL_MEMORY_ARRAY to compare arrays of memory for equality.
 *
 * @param size      The size or length of an array (for size and index bounds assertions).
 * @param index     The index of an array element (for index bounds assertions).
 * @param array     A pointer to an array (for null pointer assertions).
 * @param condition A custom condition to assert (for custom operation assertions).
 * @param actual    The actual array to be compared (for array equality assertions).
 * @param expected  The expected array for comparison (for array equality assertions).
 * @param elem      The number of elements in the arrays (for array equality assertions).
 *
 * @return None
 */

#define TEST_ASSERT_INVALID_SIZE_ARRAY(size)               TEST_ASSERT((size) > 0, "Invalid array size")
#define TEST_ASSERT_INDEX_OUT_OF_BOUNDS_ARRAY(index, size) TEST_ASSERT((index) >= 0 && (index) < (size), "Array index out of bounds")
#define TEST_ASSERT_NULL_POINTER_ARRAY(array)              TEST_ASSERT((array) != NULL, "Null array pointer")
#define TEST_ASSERT_INVALID_OPERATION_ARRAY(condition)     TEST_ASSERT(condition, "Invalid array operation")
#define TEST_ASSERT_INDEX_ARRAY(array, index)              TEST_ASSERT((index) >= 0 && (index) < sizeof(array) / sizeof(array[0]), "Array index out of bounds")

#define TEST_ASSERT_EQUAL_INT_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((signed)(actual)[i]!= (signed)(expected)[i]) {     \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_INT8_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((int8_t)(actual)[i]!= (int8_t)(expected)[i]) {     \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_INT16_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((int16_t)(actual)[i]!= (int16_t)(expected)[i]) {   \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_INT32_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((int32_t)(actual)[i]!= (int32_t)(expected)[i]) {   \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_INT64_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((int64_t)(actual)[i]!= (int64_t)(expected)[i]) {   \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_UINT_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((unsigned)(actual)[i]!= (unsigned)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint8_t)(actual)[i]!= (uint8_t)(expected)[i]) {   \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_UINT16_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint16_t)(actual)[i]!= (uint16_t)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_UINT32_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint32_t)(actual)[i]!= (uint32_t)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_UINT64_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint64_t)(actual)[i]!= (uint64_t)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_HEX_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((signed)(actual)[i]!= (signed)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_HEX8_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint8_t)(actual)[i]!= (uint8_t)(expected)[i]) {   \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_HEX16_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint16_t)(actual)[i]!= (uint16_t)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_HEX32_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint32_t)(actual)[i]!= (uint32_t)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_HEX64_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((uint64_t)(actual)[i]!= (uint64_t)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_OCT_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((signed)(actual)[i]!= (signed)(expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_PTR_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if ((actual)[i] != (expected)[i]) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_STRING_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if (strcmp((actual)[i], (expected)[i] != 0)) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_MEMORY_ARRAY(actual, expected, elem)    \
    bool success = true;                                       \
    for (size_t i = 0; i < elem; i++) {                        \
        if (memcmp(actual, expected, (elem) * sizeof(*(actual)) != 0)) { \
            success = false; break;                            \
        }                                                      \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_FLOAT_ARRAY(actual, expected, elem)             \
    bool success = true;                                                  \
    for (size_t i = 0; i < elem; i++) {                                   \
        if (fabs((actual)[i] - (expected)[i]) >= ASSERT_FLOAT_EPSILON) {  \
            success = false; break;                                       \
        }                                                                 \
    } TEST_ASSERT(success, "Array equality expectation not met")

#define TEST_ASSERT_EQUAL_DOUBLE_ARRAY(actual, expected, elem)            \
    bool success = true;                                                  \
    for (size_t i = 0; i < elem; i++) {                                   \
        if (fabs((actual)[i] - (expected)[i]) >= ASSERT_DOUBLE_EPSILON) { \
            success = false; break;                                       \
        }                                                                 \
    } TEST_ASSERT(success, "Array equality expectation not met")

/**
 * @brief File Assertion Macros
 *
 * These macros provide a set of assertions for file operations. They are used to check file-related operations
 * such as opening, reading, writing, seeking, and closing files. Additionally, they help in detecting file errors
 * and verifying that the end of a file (EOF) has not been reached.
 *
 * Usage Example:
 *   - Use TEST_ASSERT_OPEN_FILE to verify the successful opening of a file.
 *   - Use TEST_ASSERT_READ_FILE to ensure the expected number of bytes are read from a file.
 *   - Use TEST_ASSERT_WRITE_FILE to confirm that the expected number of bytes are written to a file.
 *   - Use TEST_ASSERT_SEEK_FILE to check if seeking within a file is successful.
 *   - Use TEST_ASSERT_TELL_FILE to get and check the current file position.
 *   - Use TEST_ASSERT_CLOSE_FILE to verify the successful closure of a file.
 *   - Use TEST_ASSERT_EOF_FILE to check if the end of a file (EOF) has not been reached.
 *   - Use TEST_ASSERT_FILE_NO_ERROR to assert that no file operation errors have occurred.
 *
 * @param file     The file pointer being operated on.
 * @param buffer   The buffer used for reading or writing.
 * @param size     The size of data being read or written.
 * @param offset   The offset used for seeking.
 * @param whence   The position used for seeking.
 * @param stream   The file stream being checked for EOF.
 *
 * @return None
 */

#define TEST_ASSERT_OPEN_FILE(file) TEST_ASSERT((file) != NULL, "Failed to open file")
#define TEST_ASSERT_READ_FILE(file, buffer, size) \
    TEST_ASSERT(fread(buffer, sizeof(char), size, file) == size, "Failed to read from file")
#define TEST_ASSERT_WRITE_FILE(file, data, size) \
    TEST_ASSERT(fwrite(data, sizeof(char), size, file) == size, "Failed to write to file")
#define TEST_ASSERT_SEEK_FILE(file, offset, whence) \
    TEST_ASSERT(fseek(file, offset, whence) == 0, "Failed to seek within file")
#define TEST_ASSERT_TELL_FILE(file) \
    TEST_ASSERT(ftell(file) != -1L, "Failed to get file position")
#define TEST_ASSERT_CLOSE_FILE(file) \
    TEST_ASSERT(fclose(file) == 0, "Failed to close file")
#define TEST_ASSERT_EOF_FILE(stream) \
    TEST_ASSERT(!feof(stream), "End of file (EOF) reached")
// Assert that no file error has occurred
#define TEST_ASSERT_FILE_NO_ERROR(file) \
    TEST_ASSERT(ferror(file) == 0, "File operation error occurred")

#ifdef __cplusplus
}
#endif

#endif
