/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XEXPECT_H
#define TRILOBITE_XEXPECT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

/**
 * @brief Macros for Expecting Various Boolean Comparisons
 *
 * These macros provide a convenient way to perform boolean comparisons within
 * test cases using the XUnit testing framework. They cover boolean equality,
 * inequality, less-than, greater-than, and simple boolean checks.
 *
 * Common macros for all boolean types:
 * - `XEXPECT_BOOL_EQUAL(actual, expected)` expects boolean equality.
 * - `XEXPECT_BOOL_NOT_EQUAL(actual, expected)` expects boolean inequality.
 * - `XEXPECT_BOOL_LESS(actual, expected)` expects boolean less-than.
 * - `XEXPECT_BOOL_GREATER(actual, expected)` expects boolean greater-than.
 * - `XEXPECT_BOOL_UNLESS(expression)` expects the given expression to be false.
 * - `XEXPECT_BOOL_TRUE(expression)` expects the given expression to be true.
 * - `XEXPECT_BOOL_FALSE(expression)` expects the given expression to be false.
 * - `XEXPECT_BOOL_MSG(expression, message)` expects the given expression to be false with a custom message.
 *
 * Example usage:
 *
 * ```c
 * bool actual = true;
 * bool expected = true;
 *
 * XEXPECT_BOOL_EQUAL(actual, expected); // Expect booleans to be equal.
 * XEXPECT_BOOL_TRUE(actual); // Expect actual to be true.
 * XEXPECT_BOOL_UNLESS(actual == false); // Expect actual to be false.
 * ```
 */

#define XEXPECT_BOOL_EQUAL(actual, expected)              XEXPECT((actual) == (expected), "Expectation for equality not met")
#define XEXPECT_BOOL_NOT_EQUAL(actual, expected)          XEXPECT((actual) != (expected), "Expectation for inequality not met")
#define XEXPECT_BOOL_LESS(actual, expected)               XEXPECT((actual) < (expected), "Expectation for less than not met")
#define XEXPECT_BOOL_GREATER(actual, expected)            XEXPECT((actual) > (expected), "Expectation for greater than not met")
#define XEXPECT_BOOL_UNLESS(expression)         XEXPECT((expression), "Expectation not met")
#define XEXPECT_BOOL_TRUE(expression)           XEXPECT((expression), "Expectation for true not met")
#define XEXPECT_BOOL_FALSE(expression)          XEXPECT(!(expression), "Expectation for false not met")
#define XEXPECT_BOOL_MSG(expression, message)   XEXPECT(!(expression), message)

/**
 * @brief Macros for Expecting Various Integer Comparisons
 *
 * These macros provide a convenient way to perform integer comparisons within
 * test cases using the XUnit testing framework. They cover integer equality,
 * inequality, less-than, greater-than, less-than-or-equal, and greater-than-or-equal checks.
 *
 * Common macros for all types:
 * - `XEXPECT_INT_EQUAL(actual, expected)` expects integer equality.
 * - `XEXPECT_INT_NOT_EQUAL(actual, expected)` expects integer inequality.
 * - `XEXPECT_INT_LESS(actual, expected)` expects integer less-than.
 * - `XEXPECT_INT_GREATER(actual, expected)` expects integer greater-than.
 * - `XEXPECT_INT_LESS_EQUAL(actual, expected)` expects integer less-than-or-equal.
 * - `XEXPECT_INT_GREATER_EQUAL(actual, expected)` expects integer greater-than-or-equal.
 *
 * Macros for specific integer sizes:
 * - `XEXPECT_INT8_EQUAL(actual, expected)` for 8-bit integer equality check.
 * - `XEXPECT_INT16_EQUAL(actual, expected)` for 16-bit integer equality check.
 * - `XEXPECT_INT32_EQUAL(actual, expected)` for 32-bit integer equality check.
 * - `XEXPECT_INT64_EQUAL(actual, expected)` for 64-bit integer equality check.
 *
 * Example usage:
 *
 * ```c
 * int actual = 42;
 * int expected = 42;
 *
 * XEXPECT_INT_EQUAL(actual, expected); // Expect integers to be equal.
 * XEXPECT_INT_LESS(actual, expected); // Expect actual to be less than expected.
 * ```
 */

#define XEXPECT_INT_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "Integer equality check failed")
#define XEXPECT_INT_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "Integer inequality check failed")
#define XEXPECT_INT_LESS(actual, expected)          XEXPECT((actual) < (expected), "Integer less-than check failed")
#define XEXPECT_INT_GREATER(actual, expected)       XEXPECT((actual) > (expected), "Integer greater-than check failed")
#define XEXPECT_INT_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "Integer less-than-or-equal check failed")
#define XEXPECT_INT_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "Integer greater-than-or-equal check failed")

#define XEXPECT_INT8_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "8-bit Integer equality check failed")
#define XEXPECT_INT8_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "8-bit Integer inequality check failed")
#define XEXPECT_INT8_LESS(actual, expected)          XEXPECT((actual) < (expected), "8-bit Integer less-than check failed")
#define XEXPECT_INT8_GREATER(actual, expected)       XEXPECT((actual) > (expected), "8-bit Integer greater-than check failed")
#define XEXPECT_INT8_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "8-bit Integer less-than-or-equal check failed")
#define XEXPECT_INT8_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "8-bit Integer greater-than-or-equal check failed")

#define XEXPECT_INT16_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "16-bit Integer equality check failed")
#define XEXPECT_INT16_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "16-bit Integer inequality check failed")
#define XEXPECT_INT16_LESS(actual, expected)          XEXPECT((actual) < (expected), "16-bit Integer less-than check failed")
#define XEXPECT_INT16_GREATER(actual, expected)       XEXPECT((actual) > (expected), "16-bit Integer greater-than check failed")
#define XEXPECT_INT16_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "16-bit Integer less-than-or-equal check failed")
#define XEXPECT_INT16_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "16-bit Integer greater-than-or-equal check failed")

#define XEXPECT_INT32_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "32-bit Integer equality check failed")
#define XEXPECT_INT32_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "32-bit Integer inequality check failed")
#define XEXPECT_INT32_LESS(actual, expected)          XEXPECT((actual) < (expected), "32-bit Integer less-than check failed")
#define XEXPECT_INT32_GREATER(actual, expected)       XEXPECT((actual) > (expected), "32-bit Integer greater-than check failed")
#define XEXPECT_INT32_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "32-bit Integer less-than-or-equal check failed")
#define XEXPECT_INT32_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "32-bit Integer greater-than-or-equal check failed")

#define XEXPECT_INT64_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "64-bit Integer equality check failed")
#define XEXPECT_INT64_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "64-bit Integer inequality check failed")
#define XEXPECT_INT64_LESS(actual, expected)          XEXPECT((actual) < (expected), "64-bit Integer less-than check failed")
#define XEXPECT_INT64_GREATER(actual, expected)       XEXPECT((actual) > (expected), "64-bit Integer greater-than check failed")
#define XEXPECT_INT64_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "64-bit Integer less-than-or-equal check failed")
#define XEXPECT_INT64_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "64-bit Integer greater-than-or-equal check failed")

/**
 * @brief Macros for Expecting Various Unsigned Integer Comparisons
 *
 * These macros provide a convenient way to perform unsigned integer comparisons within
 * test cases using the XUnit testing framework. They cover unsigned integer equality,
 * inequality, less-than, greater-than, less-than-or-equal, and greater-than-or-equal checks.
 *
 * Common macros for all types:
 * - `XEXPECT_UINT_EQUAL(actual, expected)` expects unsigned integer equality.
 * - `XEXPECT_UINT_NOT_EQUAL(actual, expected)` expects unsigned integer inequality.
 * - `XEXPECT_UINT_LESS(actual, expected)` expects unsigned integer less-than.
 * - `XEXPECT_UINT_GREATER(actual, expected)` expects unsigned integer greater-than.
 * - `XEXPECT_UINT_LESS_EQUAL(actual, expected)` expects unsigned integer less-than-or-equal.
 * - `XEXPECT_UINT_GREATER_EQUAL(actual, expected)` expects unsigned integer greater-than-or-equal.
 *
 * Macros for specific integer sizes:
 * - `XEXPECT_UINT8_EQUAL(actual, expected)` for 8-bit unsigned integer equality check.
 * - `XEXPECT_UINT16_EQUAL(actual, expected)` for 16-bit unsigned integer equality check.
 * - `XEXPECT_UINT32_EQUAL(actual, expected)` for 32-bit unsigned integer equality check.
 * - `XEXPECT_UINT64_EQUAL(actual, expected)` for 64-bit unsigned integer equality check.
 *
 * Example usage:
 *
 * ```c
 * unsigned int actual = 42;
 * unsigned int expected = 42;
 *
 * XEXPECT_UINT_EQUAL(actual, expected); // Expect unsigned integers to be equal.
 * XEXPECT_UINT_LESS(actual, expected); // Expect actual to be less than expected.
 * ```
 */

#define XEXPECT_UINT_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "Unsigned integer equality check failed")
#define XEXPECT_UINT_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "Unsigned integer inequality check failed")
#define XEXPECT_UINT_LESS(actual, expected)          XEXPECT((actual) < (expected), "Unsigned integer less-than check failed")
#define XEXPECT_UINT_GREATER(actual, expected)       XEXPECT((actual) > (expected), "Unsigned integer greater-than check failed")
#define XEXPECT_UINT_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "Unsigned integer less-than-or-equal check failed")
#define XEXPECT_UINT_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "Unsigned integer greater-than-or-equal check failed")

#define XEXPECT_UINT8_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "8-bit Unsigned integer equality check failed")
#define XEXPECT_UINT8_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "8-bit Unsigned integer inequality check failed")
#define XEXPECT_UINT8_LESS(actual, expected)          XEXPECT((actual) < (expected), "8-bit Unsigned integer less-than check failed")
#define XEXPECT_UINT8_GREATER(actual, expected)       XEXPECT((actual) > (expected), "8-bit Unsigned integer greater-than check failed")
#define XEXPECT_UINT8_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "8-bit Unsigned integer less-than-or-equal check failed")
#define XEXPECT_UINT8_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "8-bit Unsigned integer greater-than-or-equal check failed")

#define XEXPECT_UINT16_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "16-bit Unsigned integer equality check failed")
#define XEXPECT_UINT16_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "16-bit Unsigned integer inequality check failed")
#define XEXPECT_UINT16_LESS(actual, expected)          XEXPECT((actual) < (expected), "16-bit Unsigned integer less-than check failed")
#define XEXPECT_UINT16_GREATER(actual, expected)       XEXPECT((actual) > (expected), "16-bit Unsigned integer greater-than check failed")
#define XEXPECT_UINT16_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "16-bit Unsigned integer less-than-or-equal check failed")
#define XEXPECT_UINT16_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "16-bit Unsigned integer greater-than-or-equal check failed")

#define XEXPECT_UINT32_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "32-bit Unsigned integer equality check failed")
#define XEXPECT_UINT32_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "32-bit Unsigned integer inequality check failed")
#define XEXPECT_UINT32_LESS(actual, expected)          XEXPECT((actual) < (expected), "32-bit Unsigned integer less-than check failed")
#define XEXPECT_UINT32_GREATER(actual, expected)       XEXPECT((actual) > (expected), "32-bit Unsigned integer greater-than check failed")
#define XEXPECT_UINT32_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "32-bit Unsigned integer less-than-or-equal check failed")
#define XEXPECT_UINT32_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "32-bit Unsigned integer greater-than-or-equal check failed")

#define XEXPECT_UINT64_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "64-bit Unsigned integer equality check failed")
#define XEXPECT_UINT64_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "64-bit Unsigned integer inequality check failed")
#define XEXPECT_UINT64_LESS(actual, expected)          XEXPECT((actual) < (expected), "64-bit Unsigned integer less-than check failed")
#define XEXPECT_UINT64_GREATER(actual, expected)       XEXPECT((actual) > (expected), "64-bit Unsigned integer greater-than check failed")
#define XEXPECT_UINT64_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "64-bit Unsigned integer less-than-or-equal check failed")
#define XEXPECT_UINT64_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "64-bit Unsigned integer greater-than-or-equal check failed")

/**
 * @brief Macros for Expecting Various Hexadecimal Number Comparisons
 *
 * These macros provide a convenient way to perform hexadecimal number comparisons within
 * test cases using the XUnit testing framework. They cover hexadecimal number equality,
 * inequality, less-than, greater-than, less-than-or-equal, and greater-than-or-equal checks.
 *
 * Common macros for all types:
 * - `XEXPECT_HEX_EQUAL(actual, expected)` expects hexadecimal number equality.
 * - `XEXPECT_HEX_NOT_EQUAL(actual, expected)` expects hexadecimal number inequality.
 * - `XEXPECT_HEX_LESS(actual, expected)` expects hexadecimal number less-than.
 * - `XEXPECT_HEX_GREATER(actual, expected)` expects hexadecimal number greater-than.
 * - `XEXPECT_HEX_LESS_EQUAL(actual, expected)` expects hexadecimal number less-than-or-equal.
 * - `XEXPECT_HEX_GREATER_EQUAL(actual, expected)` expects hexadecimal number greater-than-or-equal.
 *
 * Macros for specific integer sizes:
 * - `XEXPECT_HEX8_EQUAL(actual, expected)` for 8-bit hexadecimal equality check.
 * - `XEXPECT_HEX16_EQUAL(actual, expected)` for 16-bit hexadecimal equality check.
 * - `XEXPECT_HEX32_EQUAL(actual, expected)` for 32-bit hexadecimal equality check.
 * - `XEXPECT_HEX64_EQUAL(actual, expected)` for 64-bit hexadecimal equality check.
 *
 * Example usage:
 *
 * ```c
 * int actual = 0x12; // Hexadecimal: 0x12
 * int expected = 0x15; // Hexadecimal: 0x15
 *
 * XEXPECT_HEX_EQUAL(actual, expected); // Expect hexadecimal numbers to be equal.
 * XEXPECT_HEX_LESS(actual, expected); // Expect actual to be less than expected.
 * ```
 */

#define XEXPECT_HEX_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "Hexadecimal equality check failed")
#define XEXPECT_HEX_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "Hexadecimal inequality check failed")
#define XEXPECT_HEX_LESS(actual, expected)          XEXPECT((actual) < (expected), "Hexadecimal less-than check failed")
#define XEXPECT_HEX_GREATER(actual, expected)       XEXPECT((actual) > (expected), "Hexadecimal greater-than check failed")
#define XEXPECT_HEX_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "Hexadecimal less-than-or-equal check failed")
#define XEXPECT_HEX_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "Hexadecimal greater-than-or-equal check failed")

#define XEXPECT_HEX8_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "8-bit Hexadecimal equality check failed")
#define XEXPECT_HEX8_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "8-bit Hexadecimal inequality check failed")
#define XEXPECT_HEX8_LESS(actual, expected)          XEXPECT((actual) < (expected), "8-bit Hexadecimal less-than check failed")
#define XEXPECT_HEX8_GREATER(actual, expected)       XEXPECT((actual) > (expected), "8-bit Hexadecimal greater-than check failed")
#define XEXPECT_HEX8_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "8-bit Hexadecimal less-than-or-equal check failed")
#define XEXPECT_HEX8_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "8-bit Hexadecimal greater-than-or-equal check failed")

#define XEXPECT_HEX16_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "16-bit Hexadecimal equality check failed")
#define XEXPECT_HEX16_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "16-bit Hexadecimal inequality check failed")
#define XEXPECT_HEX16_LESS(actual, expected)          XEXPECT((actual) < (expected), "16-bit Hexadecimal less-than check failed")
#define XEXPECT_HEX16_GREATER(actual, expected)       XEXPECT((actual) > (expected), "16-bit Hexadecimal greater-than check failed")
#define XEXPECT_HEX16_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "16-bit Hexadecimal less-than-or-equal check failed")
#define XEXPECT_HEX16_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "16-bit Hexadecimal greater-than-or-equal check failed")

#define XEXPECT_HEX32_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "32-bit Hexadecimal equality check failed")
#define XEXPECT_HEX32_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "32-bit Hexadecimal inequality check failed")
#define XEXPECT_HEX32_LESS(actual, expected)          XEXPECT((actual) < (expected), "32-bit Hexadecimal less-than check failed")
#define XEXPECT_HEX32_GREATER(actual, expected)       XEXPECT((actual) > (expected), "32-bit Hexadecimal greater-than check failed")
#define XEXPECT_HEX32_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "32-bit Hexadecimal less-than-or-equal check failed")
#define XEXPECT_HEX32_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "32-bit Hexadecimal greater-than-or-equal check failed")

#define XEXPECT_HEX64_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "64-bit Hexadecimal equality check failed")
#define XEXPECT_HEX64_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "64-bit Hexadecimal inequality check failed")
#define XEXPECT_HEX64_LESS(actual, expected)          XEXPECT((actual) < (expected), "64-bit Hexadecimal less-than check failed")
#define XEXPECT_HEX64_GREATER(actual, expected)       XEXPECT((actual) > (expected), "64-bit Hexadecimal greater-than check failed")
#define XEXPECT_HEX64_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "64-bit Hexadecimal less-than-or-equal check failed")
#define XEXPECT_HEX64_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "64-bit Hexadecimal greater-than-or-equal check failed")

/**
 * @brief Macros for Expecting Various Octal Number Comparisons
 *
 * These macros provide a convenient way to perform octal number comparisons within
 * test cases using the XUnit testing framework. They cover octal number equality,
 * inequality, less-than, greater-than, less-than-or-equal, and greater-than-or-equal checks.
 *
 * Common macros for all types:
 * - `XEXPECT_OCT_EQUAL(actual, expected)` expects octal number equality.
 * - `XEXPECT_OCT_NOT_EQUAL(actual, expected)` expects octal number inequality.
 * - `XEXPECT_OCT_LESS(actual, expected)` expects octal number less-than.
 * - `XEXPECT_OCT_GREATER(actual, expected)` expects octal number greater-than.
 * - `XEXPECT_OCT_LESS_EQUAL(actual, expected)` expects octal number less-than-or-equal.
 * - `XEXPECT_OCT_GREATER_EQUAL(actual, expected)` expects octal number greater-than-or-equal.
 *
 * Example usage:
 *
 * ```c
 * int actual = 012; // Octal: 12
 * int expected = 015; // Octal: 15
 *
 * XEXPECT_OCT_EQUAL(actual, expected); // Expect octal numbers to be equal.
 * XEXPECT_OCT_LESS(actual, expected); // Expect actual to be less than expected.
 * ```
 */

#define XEXPECT_OCT_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "Octal equality check failed")
#define XEXPECT_OCT_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "Octal inequality check failed")
#define XEXPECT_OCT_LESS(actual, expected)          XEXPECT((actual) < (expected), "Octal less-than check failed")
#define XEXPECT_OCT_GREATER(actual, expected)       XEXPECT((actual) > (expected), "Octal greater-than check failed")
#define XEXPECT_OCT_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "Octal less-than-or-equal check failed")
#define XEXPECT_OCT_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "Octal greater-than-or-equal check failed")

/**
 * @brief Macros for Expecting Various Bitwise Comparisons
 *
 * These macros provide a convenient way to perform bitwise comparisons and checks on
 * integer values within test cases using the XUnit testing framework. They cover
 * bitwise equality, inequality, less-than, greater-than, high/low bit checks, and more.
 *
 * Common macros for all types:
 * - `XEXPECT_BIT_EQUAL(actual, expected)` expects bitwise equality.
 * - `XEXPECT_BIT_NOT_EQUAL(actual, expected)` expects bitwise inequality.
 * - `XEXPECT_BIT_LESS(actual, expected)` expects bitwise less-than.
 * - `XEXPECT_BIT_GREATER(actual, expected)` expects bitwise greater-than.
 * - `XEXPECT_BIT_LESS_EQUAL(actual, expected)` expects bitwise less-than-or-equal.
 * - `XEXPECT_BIT_GREATER_EQUAL(actual, expected)` expects bitwise greater-than-or-equal.
 *
 * Bit position-specific macros:
 * - `XEXPECT_BIT_NOT_HIGH(value, bitIndex)` expects that a specific bit is not high (1).
 * - `XEXPECT_BIT_HIGH(value, bitIndex)` expects that a specific bit is high (1).
 * - `XEXPECT_BIT_NOT_LOW(value, bitIndex)` expects that a specific bit is not low (0).
 * - `XEXPECT_BIT_LOW(value, bitIndex)` expects that a specific bit is low (0).
 *
 * Bit mask-specific macros:
 * - `XEXPECT_BITS_NOT_HIGH(value, mask)` expects that all bits specified by a mask are not high (1).
 * - `XEXPECT_BITS_HIGH(value, mask)` expects that all bits specified by a mask are high (1).
 * - `XEXPECT_BITS_NOT_LOW(value, mask)` expects that at least one bit specified by a mask is not low (0).
 * - `XEXPECT_BITS_LOW(value, mask)` expects that all bits specified by a mask are low (0).
 * - `XEXPECT_BITS_NOT_EQUAL(actual, expected, mask)` expects bitwise equality within a specified mask.
 * - `XEXPECT_BITS_EQUAL(actual, expected, mask)` expects bitwise inequality within a specified mask.
 * - `XEXPECT_BITS_NOT_LESS(actual, expected, mask)` expects bitwise less-than within a specified mask.
 * - `XEXPECT_BITS_LESS(actual, expected, mask)` expects bitwise greater-than within a specified mask.
 * - `XEXPECT_BITS_NOT_GREATER(actual, expected, mask)` expects bitwise less-than-or-equal within a specified mask.
 * - `XEXPECT_BITS_GREATER(actual, expected, mask)` expects bitwise greater-than-or-equal within a specified mask.
 *
 * Example usage:
 *
 * ```c
 * int actual = 0b1010; // Binary: 1010
 * int expected = 0b1100; // Binary: 1100
 *
 * XEXPECT_BIT_NOT_HIGH(actual, 2); // Expect that bit 2 is not high (0)
 * XEXPECT_BIT_HIGH(expected, 2); // Expect that bit 2 is high (1)
 *
 * XEXPECT_BITS_NOT_LOW(actual, 0b1000); // Expect that at least one bit specified by the mask is not low (1)
 * XEXPECT_BITS_LOW(expected, 0b0011); // Expect that all bits specified by the mask are low (0)
 * ```
 */
#define XEXPECT_BIT_EQUAL(actual, expected)            XEXPECT((actual) == (expected), "Bitwise equality check failed")
#define XEXPECT_BIT_NOT_EQUAL(actual, expected)        XEXPECT((actual) != (expected), "Bitwise inequality check failed")
#define XEXPECT_BIT_LESS(actual, expected)             XEXPECT((actual) < (expected), "Bitwise less-than check failed")
#define XEXPECT_BIT_GREATER(actual, expected)          XEXPECT((actual) > (expected), "Bitwise greater-than check failed")
#define XEXPECT_BIT_LESS_EQUAL(actual, expected)       XEXPECT((actual) <= (expected), "Bitwise less-than-or-equal check failed")
#define XEXPECT_BIT_GREATER_EQUAL(actual, expected)    XEXPECT((actual) >= (expected), "Bitwise greater-than-or-equal check failed")
#define XEXPECT_BIT_NOT_HIGH(value, bitIndex)          XEXPECT(!((value) & (1 << (bitIndex))), "Bit is high check failed")
#define XEXPECT_BIT_HIGH(value, bitIndex)              XEXPECT((value) & (1 << (bitIndex)), "Bit is not high check failed")
#define XEXPECT_BIT_NOT_LOW(value, bitIndex)           XEXPECT((value) & (1 << (bitIndex)), "Bit is low check failed")
#define XEXPECT_BIT_LOW(value, bitIndex)               XEXPECT(!((value) & (1 << (bitIndex))), "Bit is not low check failed")

#define XEXPECT_BITS_NOT_HIGH(value, mask)             XEXPECT(((value) & (mask)) != (mask), "Bits are all high check failed")
#define XEXPECT_BITS_HIGH(value, mask)                 XEXPECT(((value) & (mask)) == (mask), "Bits are not all high check failed")
#define XEXPECT_BITS_NOT_LOW(value, mask)              XEXPECT(((value) & (mask)) != 0, "Bits are not all low check failed")
#define XEXPECT_BITS_LOW(value, mask)                  XEXPECT(((value) & (mask)) == 0, "Bits are not all low check failed")
#define XEXPECT_BITS_NOT_EQUAL(actual, expected, mask) XEXPECT(((actual) & (mask)) != ((expected) & (mask)), "Bitwise equality check failed")
#define XEXPECT_BITS_EQUAL(actual, expected, mask)     XEXPECT(((actual) & (mask)) == ((expected) & (mask)), "Bitwise inequality check failed")
#define XEXPECT_BITS_NOT_LESS(actual, expected, mask)  XEXPECT(((actual) & (mask)) >= ((expected) & (mask)), "Bitwise less-than check failed")
#define XEXPECT_BITS_LESS(actual, expected, mask)      XEXPECT(((actual) & (mask)) < ((expected) & (mask)), "Bitwise greater-than check failed")
#define XEXPECT_BITS_NOT_GREATER(actual, expected, mask)            XEXPECT(((actual) & (mask)) <= ((expected) & (mask)), "Bitwise less-than-or-equal check failed")
#define XEXPECT_BITS_GREATER(actual, expected, mask)                XEXPECT(((actual) & (mask)) > ((expected) & (mask)), "Bitwise greater-than-or-equal check failed")
#define XEXPECT_BITS_NOT_LESS_EQUAL(actual, expected, mask)         XEXPECT(((actual) & (mask)) > ((expected) & (mask)), "Bitwise less-than-or-equal check failed")
#define XEXPECT_BITS_LESS_EQUAL(actual, expected, mask)             XEXPECT(((actual) & (mask)) <= ((expected) & (mask)), "Bitwise greater-than-or-equal check failed")
#define XEXPECT_BITS_NOT_GREATER_EQUAL(actual, expected, mask)      XEXPECT(((actual) & (mask)) < ((expected) & (mask)), "Bitwise less-than-or-equal check failed")
#define XEXPECT_BITS_GREATER_EQUAL(actual, expected, mask)          XEXPECT(((actual) & (mask)) >= ((expected) & (mask)), "Bitwise greater-than-or-equal check failed")

/**
 * @brief Macros for Expecting Various Value Comparisons
 *
 * These macros provide a convenient way to perform comparisons and checks on various
 * types of values within test cases using the XUnit testing framework. They cover
 * integer types, hexadecimal values, binary values, octal values, floating-point
 * values, and character values.
 *
 * Common macros for all types:
 * - `XEXPECT_INT_WITHIN(actual, expected, tolerance)` expects that the difference
 *   between two integers is within a specified tolerance.
 * - Similar macros exist for 8-bit, 16-bit, 32-bit, and 64-bit integer types.
 * - `XEXPECT_HEX_WITHIN(actual, expected, tolerance)` expects that the difference
 *   between two hexadecimal values is within a specified tolerance.
 * - Similar macros exist for 8-bit, 16-bit, 32-bit, and 64-bit hexadecimal values.
 * - `XEXPECT_UINT_WITHIN(actual, expected, tolerance)` expects that the difference
 *   between two unsigned integers is within a specified tolerance.
 * - Similar macros exist for 8-bit, 16-bit, 32-bit, and 64-bit unsigned integer types.
 * - `XEXPECT_BIN_WITHIN(actual, expected, tolerance)` expects that the difference
 *   between two binary values is within a specified tolerance.
 * - `XEXPECT_OCT_WITHIN(actual, expected, tolerance)` expects that the difference
 *   between two octal values is within a specified tolerance.
 * - `XEXPECT_FLOAT_WITHIN(actual, expected, epsilon)` expects that the difference
 *   between two float values is within a specified epsilon.
 * - `XEXPECT_DOUBLE_WITHIN(actual, expected, epsilon)` expects that the difference
 *   between two double values is within a specified epsilon.
 * - `XEXPECT_CHAR_WITHIN(actual, min, max)` expects that a character value is within
 *   a specified range.
 * - `XEXPECT_WCHAR_WITHIN(actual, min, max)` expects that a wide character value is
 *   within a specified range.
 *
 * Example usage:
 *
 * ```c
 * int actual = 10;
 * int expected = 15;
 * int tolerance = 2;
 * XEXPECT_INT_WITHIN(actual, expected, tolerance); // Expect actual and expected within a tolerance of 2
 *
 * float fActual = 3.14f;
 * float fExpected = 3.14159f;
 * float epsilon = 0.01f;
 * XEXPECT_FLOAT_WITHIN(fActual, fExpected, epsilon); // Expect nearly equal float values within epsilon
 *
 * char cValue = 'A';
 * char min = 'A';
 * char max = 'Z';
 * XEXPECT_CHAR_WITHIN(cValue, min, max); // Expect character 'A' within the range 'A' to 'Z'
 * ```
 */

#define XEXPECT_INT_WITHIN(actual, expected, tolerance)     XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "Integer value not within tolerance")
#define XEXPECT_INT8_WITHIN(actual, expected, tolerance)    XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "8-bit Integer value not within tolerance")
#define XEXPECT_INT16_WITHIN(actual, expected, tolerance)   XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "16-bit Integer value not within tolerance")
#define XEXPECT_INT32_WITHIN(actual, expected, tolerance)   XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "32-bit Integer value not within tolerance")
#define XEXPECT_INT64_WITHIN(actual, expected, tolerance)   XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "64-bit Integer value not within tolerance")
#define XEXPECT_UINT_WITHIN(actual, expected, tolerance)    XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "Unsigned integer value not within tolerance")
#define XEXPECT_UINT64_WITHIN(actual, expected, tolerance)  XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "64-bit Unsigned Integer value not within tolerance")
#define XEXPECT_HEX_WITHIN(actual, expected, tolerance)     XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "Hexadecimal value not within tolerance")
#define XEXPECT_HEX8_WITHIN(actual, expected, tolerance)    XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "8-bit Hexadecimal value not within tolerance")
#define XEXPECT_HEX16_WITHIN(actual, expected, tolerance)   XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "16-bit Hexadecimal value not within tolerance")
#define XEXPECT_HEX32_WITHIN(actual, expected, tolerance)   XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "32-bit Hexadecimal value not within tolerance")
#define XEXPECT_HEX64_WITHIN(actual, expected, tolerance)   XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "64-bit Hexadecimal value not within tolerance")
#define XEXPECT_BIN_WITHIN(actual, expected, tolerance)     XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "Binary value not within tolerance")
#define XEXPECT_OCT_WITHIN(actual, expected, tolerance)     XEXPECT(((actual) >= ((expected) - (tolerance))) && ((actual) <= ((expected) + (tolerance))), "Octal value not within tolerance")

#define XEXPECT_FLOAT_WITHIN(actual, expected, epsilon)     XEXPECT(fabs((actual) - (expected)) <= (epsilon), "Float value not within epsilon")
#define XEXPECT_DOUBLE_WITHIN(actual, expected, epsilon)    XEXPECT(fabs((actual) - (expected)) <= (epsilon), "Double value not within epsilon")

#define XEXPECT_CHAR_WITHIN(actual, min, max)               XEXPECT((actual) > (min) || (actual) < (max), "Character value not within range")
#define XEXPECT_WCHAR_WITHIN(actual, min, max)              XEXPECT((actual) > (min) || (actual) < (max), "W-Character value not within range")

/**
 * @brief Macros for Expecting Float Value Comparisons
 *
 * These macros provide a convenient way to perform comparisons and checks on
 * single-precision floating-point (float) values within test cases using the XUnit
 * testing framework. They cover equality, inequality, less-than, greater-than,
 * infinity, finite, and NaN checks.
 *
 * Common macros for both C and C++:
 * - `XEXPECT_FLOAT_EQUAL(actual, expected, epsilon)` expects that the difference
 *   between `actual` and `expected` is within a specified `epsilon`.
 * - `XEXPECT_FLOAT_NOT_EQUAL(actual, expected, epsilon)` expects that the
 *   difference between `actual` and `expected` is outside the specified `epsilon`.
 * - `XEXPECT_FLOAT_LESS(actual, expected)` expects that `actual` is less than `expected`.
 * - `XEXPECT_FLOAT_GREATER(actual, expected)` expects that `actual` is greater than `expected`.
 * - `XEXPECT_FLOAT_GREATER_EQUAL(actual, expected)` expects that `actual` is greater
 *   than or equal to `expected`.
 * - `XEXPECT_FLOAT_LESS_EQUAL(actual, expected)` expects that `actual` is less than
 *   or equal to `expected`.
 * - `XEXPECT_FLOAT_IS_NOT_INF(value)` expects that `value` is not positive infinity.
 * - `XEXPECT_FLOAT_IS_INF(value)` expects that `value` is positive infinity.
 * - `XEXPECT_FLOAT_IS_NOT_NEG_INF(value)` expects that `value` is not negative infinity.
 * - `XEXPECT_FLOAT_IS_NEG_INF(value)` expects that `value` is negative infinity.
 * - `XEXPECT_FLOAT_IS_NOT_FINITE(value)` expects that `value` is not finite.
 * - `XEXPECT_FLOAT_IS_FINITE(value)` expects that `value` is finite.
 * - `XEXPECT_FLOAT_IS_NOT_NAN(value)` expects that `value` is not NaN.
 * - `XEXPECT_FLOAT_IS_NAN(value)` expects that `value` is NaN.
 *
 * Example usage (C++):
 *
 * ```cpp
 * float actual = 3.141592653589793f;
 * float expected = 3.14159f;
 * XEXPECT_FLOAT_EQUAL(actual, expected, 0.0001f); // Expect nearly equal values within 0.0001 epsilon
 * XEXPECT_FLOAT_LESS(actual, 4.0f);             // Expect actual to be less than 4.0
 * XEXPECT_FLOAT_IS_INF(INFINITY);              // Expect positive infinity
 * ```
 *
 * Example usage (C):
 *
 * ```c
 * float actual = 3.141592653589793f;
 * float expected = 3.14159f;
 * XEXPECT_FLOAT_EQUAL(actual, expected, 0.0001f); // Expect nearly equal values within 0.0001 epsilon
 * XEXPECT_FLOAT_LESS(actual, 4.0f);             // Expect actual to be less than 4.0
 * XEXPECT_FLOAT_IS_INF(INFINITY);              // Expect positive infinity
 * ```
 */

#define XEXPECT_FLOAT_EQUAL(actual, expected, epsilon)     XEXPECT(fabs((actual) - (expected)) <= (epsilon), "Floating-point value not equal within epsilon")
#define XEXPECT_FLOAT_NOT_EQUAL(actual, expected, epsilon) XEXPECT(fabs((actual) - (expected)) < (epsilon), "Floating-point value equal within epsilon")
#define XEXPECT_FLOAT_LESS(actual, expected)               XEXPECT((actual) < (expected), "Floating-point value not less")
#define XEXPECT_FLOAT_GREATER(actual, expected)            XEXPECT((actual) > (expected), "Floating-point value not greater")
#define XEXPECT_FLOAT_GREATER_EQUAL(actual, expected)      XEXPECT((actual) >= (expected), "Floating-point value not greater or equal")
#define XEXPECT_FLOAT_LESS_EQUAL(actual, expected)         XEXPECT((actual) <= (expected), "Floating-point value not less or equal")
#define XEXPECT_FLOAT_IS_NOT_INF(value)                    XEXPECT(!isinf(value) || (value) <= 0, "Floating-point value is infinite")
#define XEXPECT_FLOAT_IS_INF(value)                        XEXPECT(isinf(value) && (value) > 0, "Floating-point value is not positive infinity")
#define XEXPECT_FLOAT_IS_NOT_NEG_INF(value)                XEXPECT(!isinf(value) || (value) >= 0, "Floating-point value is negative infinity")
#define XEXPECT_FLOAT_IS_NEG_INF(value)                    XEXPECT(isinf(value) && (value) < 0, "Floating-point value is not negative infinity")
#define XEXPECT_FLOAT_IS_NOT_FINITE(value)                 XEXPECT(!isfinite(value), "Floating-point value is finite")
#define XEXPECT_FLOAT_IS_FINITE(value)                     XEXPECT(isfinite(value), "Floating-point value is not finite")
#define XEXPECT_FLOAT_IS_NOT_NAN(value)                    XEXPECT(!isnan(value), "Floating-point value is NaN")
#define XEXPECT_FLOAT_IS_NAN(value)                        XEXPECT(isnan(value), "Floating-point value is not NaN")

/**
 * @brief Macros for Expecting Double-Precision Value Comparisons
 *
 * These macros provide a convenient way to perform comparisons and checks on
 * double-precision floating-point values within test cases using the XUnit
 * testing framework. They cover equality, inequality, less-than, greater-than,
 * infinity, finite, and NaN checks.
 *
 * Common macros for both C and C++:
 * - `XEXPECT_DOUBLE_EQUAL(actual, expected, epsilon)` expects that the difference
 *   between `actual` and `expected` is within a specified `epsilon`.
 * - `XEXPECT_DOUBLE_NOT_EQUAL(actual, expected, epsilon)` expects that the
 *   difference between `actual` and `expected` is outside the specified `epsilon`.
 * - `XEXPECT_DOUBLE_LESS(actual, expected)` expects that `actual` is less than `expected`.
 * - `XEXPECT_DOUBLE_GREATER(actual, expected)` expects that `actual` is greater than `expected`.
 * - `XEXPECT_DOUBLE_GREATER_EQUAL(actual, expected)` expects that `actual` is greater
 *   than or equal to `expected`.
 * - `XEXPECT_DOUBLE_LESS_EQUAL(actual, expected)` expects that `actual` is less than
 *   or equal to `expected`.
 * - `XEXPECT_DOUBLE_IS_NOT_INF(value)` expects that `value` is not positive infinity.
 * - `XEXPECT_DOUBLE_IS_INF(value)` expects that `value` is positive infinity.
 * - `XEXPECT_DOUBLE_IS_NOT_NEG_INF(value)` expects that `value` is not negative infinity.
 * - `XEXPECT_DOUBLE_IS_NEG_INF(value)` expects that `value` is negative infinity.
 * - `XEXPECT_DOUBLE_IS_NOT_FINITE(value)` expects that `value` is not finite.
 * - `XEXPECT_DOUBLE_IS_FINITE(value)` expects that `value` is finite.
 * - `XEXPECT_DOUBLE_IS_NOT_NAN(value)` expects that `value` is not NaN.
 * - `XEXPECT_DOUBLE_IS_NAN(value)` expects that `value` is NaN.
 *
 * Example usage (C++):
 *
 * ```cpp
 * double actual = 3.141592653589793;
 * double expected = 3.14159;
 * XEXPECT_DOUBLE_EQUAL(actual, expected, 0.0001); // Expect nearly equal values within 0.0001 epsilon
 * XEXPECT_DOUBLE_LESS(actual, 4.0);             // Expect actual to be less than 4.0
 * XEXPECT_DOUBLE_IS_INF(INFINITY);              // Expect positive infinity
 * ```
 *
 * Example usage (C):
 *
 * ```c
 * double actual = 3.141592653589793;
 * double expected = 3.14159;
 * XEXPECT_DOUBLE_EQUAL(actual, expected, 0.0001); // Expect nearly equal values within 0.0001 epsilon
 * XEXPECT_DOUBLE_LESS(actual, 4.0);             // Expect actual to be less than 4.0
 * XEXPECT_DOUBLE_IS_INF(INFINITY);              // Expect positive infinity
 * ```
 */

#define XEXPECT_DOUBLE_EQUAL(actual, expected, epsilon)     XEXPECT(fabs((actual) - (expected)) <= (epsilon), "Double-precision value not equal within epsilon")
#define XEXPECT_DOUBLE_NOT_EQUAL(actual, expected, epsilon) XEXPECT(fabs((actual) - (expected)) < (epsilon), "Double-precision value equal within epsilon")
#define XEXPECT_DOUBLE_LESS(actual, expected)               XEXPECT((actual) < (expected), "Double-precision value not less")
#define XEXPECT_DOUBLE_GREATER(actual, expected)            XEXPECT((actual) > (expected), "Double-precision value not greater")
#define XEXPECT_DOUBLE_GREATER_EQUAL(actual, expected)      XEXPECT((actual) >= (expected), "Double-precision value not greater or equal")
#define XEXPECT_DOUBLE_LESS_EQUAL(actual, expected)         XEXPECT((actual) <= (expected), "Double-precision value not less or equal")
#define XEXPECT_DOUBLE_IS_NOT_INF(value)                    XEXPECT(!isinf(value) || (value) <= 0, "Double-precision value is infinite")
#define XEXPECT_DOUBLE_IS_INF(value)                        XEXPECT(isinf(value) && (value) > 0, "Double-precision value is not positive infinity")
#define XEXPECT_DOUBLE_IS_NOT_NEG_INF(value)                XEXPECT(!isinf(value) || (value) >= 0, "Double-precision value is negative infinity")
#define XEXPECT_DOUBLE_IS_NEG_INF(value)                    XEXPECT(isinf(value) && (value) < 0, "Double-precision value is not negative infinity")
#define XEXPECT_DOUBLE_IS_NOT_FINITE(value)                 XEXPECT(!isfinite(value), "Double-precision value is finite")
#define XEXPECT_DOUBLE_IS_FINITE(value)                     XEXPECT(isfinite(value), "Double-precision value is not finite")
#define XEXPECT_DOUBLE_IS_NOT_NAN(value)                    XEXPECT(!isnan(value), "Double-precision value is NaN")
#define XEXPECT_DOUBLE_IS_NAN(value)                        XEXPECT(isnan(value), "Double-precision value is not NaN")

/**
 * @brief Macros for Expecting Pointer Equality, Inequality, Validity, and Bounds
 *
 * These macros provide a convenient way to perform pointer comparisons and validity checks
 * within test cases using the XUnit testing framework. They differ depending on whether
 * the code is being compiled in a C++ or C environment.
 *
 * For C++:
 * - `XEXPECT_PTR_NULL(pointer)` expects that `pointer` is nullptr.
 * - `XEXPECT_PTR_NOT_NULL(pointer)` expects that `pointer` is not nullptr.
 * - `XEXPECT_PTR_INVALID(pointer)` expects that `pointer` is not nullptr (invalid pointer error).
 * - `XEXPECT_PTR_EMPTY(pointer)` expects that `pointer` is nullptr (empty pointer).
 * - `XEXPECT_PTR_NOT_EMPTY(pointer)` expects that `pointer` is not nullptr (not empty pointer).
 * - `XEXPECT_PTR_INVALID_MEMORY_ACCESS(pointer)` expects that `pointer` is not nullptr (invalid memory access).
 *
 * For C:
 * - `XEXPECT_PTR_NULL(pointer)` expects that `pointer` is NULL.
 * - `XEXPECT_PTR_NOT_NULL(pointer)` expects that `pointer` is not NULL.
 * - `XEXPECT_PTR_INVALID(pointer)` expects that `pointer` is not NULL (invalid pointer error).
 * - `XEXPECT_PTR_EMPTY(pointer)` expects that `pointer` is NULL (empty pointer).
 * - `XEXPECT_PTR_NOT_EMPTY(pointer)` expects that `pointer` is not NULL (not empty pointer).
 * - `XEXPECT_PTR_INVALID_MEMORY_ACCESS(pointer)` expects that `pointer` is not NULL (invalid memory access).
 *
 * Common macros for both C and C++:
 * - `XEXPECT_PTR_ARRAY_BOUNDS(pointer, index, size)` expects that the array index `index` is within bounds `[0, size)`.
 * - `XEXPECT_PTR_EQUAL(actual, expected)` expects that `actual` and `expected` pointers are equal.
 * - `XEXPECT_PTR_NOT_EQUAL(actual, expected)` expects that `actual` and `expected` pointers are not equal.
 * - `XEXPECT_PTR_LESS(actual, expected)` expects that `actual` is less than `expected`.
 * - `XEXPECT_PTR_GREATER(actual, expected)` expects that `actual` is greater than `expected`.
 * - `XEXPECT_PTR_LESS_EQUAL(actual, expected)` expects that `actual` is less than or equal to `expected`.
 * - `XEXPECT_PTR_GREATER_EQUAL(actual, expected)` expects that `actual` is greater than or equal to `expected`.
 *
 * Example usage (C++):
 *
 * ```cpp
 * int* ptr1 = nullptr;
 * int* ptr2 = new int(42);
 * XEXPECT_PTR_NULL(ptr1);                     // Expect ptr1 to be nullptr
 * XEXPECT_PTR_NOT_NULL(ptr2);                 // Expect ptr2 not to be nullptr
 * XEXPECT_PTR_INVALID(ptr1);                  // Expect invalid pointer error for ptr1
 * XEXPECT_PTR_EMPTY(ptr1);                    // Expect empty pointer for ptr1
 * XEXPECT_PTR_NOT_EMPTY(ptr2);                // Expect not empty pointer for ptr2
 * XEXPECT_PTR_INVALID_MEMORY_ACCESS(ptr1);    // Expect invalid memory access for ptr1
 * ```
 *
 * Example usage (C):
 *
 * ```c
 * int* ptr1 = NULL;
 * int* ptr2 = malloc(sizeof(int));
 * XEXPECT_PTR_NULL(ptr1);                     // Expect ptr1 to be NULL
 * XEXPECT_PTR_NOT_NULL(ptr2);                 // Expect ptr2 not to be NULL
 * XEXPECT_PTR_INVALID(ptr1);                  // Expect invalid pointer error for ptr1
 * XEXPECT_PTR_EMPTY(ptr1);                    // Expect empty pointer for ptr1
 * XEXPECT_PTR_NOT_EMPTY(ptr2);                // Expect not empty pointer for ptr2
 * XEXPECT_PTR_INVALID_MEMORY_ACCESS(ptr1);    // Expect invalid memory access for ptr1
 * ```
 */

#ifdef __cplusplus
#define XEXPECT_PTR_NULL(pointer)      XEXPECT((pointer) == nullptr, "Expected nullptr")
#define XEXPECT_PTR_NOT_NULL(pointer)  XEXPECT((pointer) != nullptr, "Expected not nullptr")
#define XEXPECT_PTR_INVALID(pointer)   XEXPECT((pointer) != nullptr, "Invalid pointer error")
#define XEXPECT_PTR_EMPTY(pointer)     XEXPECT((pointer) == nullptr, "Expected empty pointer")
#define XEXPECT_PTR_NOT_EMPTY(pointer) XEXPECT((pointer) != nullptr, "Expected not empty pointer")
#define XEXPECT_PTR_INVALID_MEMORY_ACCESS(pointer) XEXPECT(pointer != nullptr, "Invalid memory access")
#else
#define XEXPECT_PTR_NULL(pointer)      XEXPECT((pointer) == NULL, "Expected NULL")
#define XEXPECT_PTR_NOT_NULL(pointer)  XEXPECT((pointer) != NULL, "Expected not NULL")
#define XEXPECT_PTR_INVALID(pointer)   XEXPECT((pointer) != NULL, "Invalid pointer error")
#define XEXPECT_PTR_EMPTY(pointer)     XEXPECT((pointer) == NULL, "Expected empty pointer")
#define XEXPECT_PTR_NOT_EMPTY(pointer) XEXPECT((pointer) != NULL, "Expected not empty pointer")
#define XEXPECT_PTR_INVALID_MEMORY_ACCESS(pointer) XEXPECT(pointer != NULL, "Invalid memory access")
#endif
#define XEXPECT_PTR_ARRAY_BOUNDS(pointer, index, size) XEXPECT((index) >= 0 && (index) < (size), "Array index out of bounds")
#define XEXPECT_PTR_EQUAL(actual, expected)            XEXPECT((actual) == (expected), "Pointer equality check failed")
#define XEXPECT_PTR_NOT_EQUAL(actual, expected)        XEXPECT((actual) != (expected), "Pointer inequality check failed")
#define XEXPECT_PTR_LESS(actual, expected)             XEXPECT((actual) < (expected), "Pointer less than comparison failed")
#define XEXPECT_PTR_GREATER(actual, expected)          XEXPECT((actual) > (expected), "Pointer greater than comparison failed")
#define XEXPECT_PTR_LESS_EQUAL(actual, expected)       XEXPECT((actual) <= (expected), "Pointer less than or equal comparison failed")
#define XEXPECT_PTR_GREATER_EQUAL(actual, expected)    XEXPECT((actual) >= (expected), "Pointer greater than or equal comparison failed")

/**
 * @brief Macros for Expecting String Equality, Inequality, and Length
 *
 * These macros provide a convenient way to perform string comparisons within test cases
 * using the XUnit testing framework. They differ depending on whether the code is being
 * compiled in a C++ or C environment.
 *
 * For C++:
 * - `XEXPECT_STRING_EQUAL(actual, expected)` expects that `actual` and `expected` strings are equal.
 * - `XEXPECT_STRING_NOT_EQUAL(actual, expected)` expects that `actual` and `expected` strings are not equal.
 * - `XEXPECT_STRING_LENGTH(actual, expected)` expects that the length of `actual` string is equal to `expected`.
 *
 * For C:
 * - `XEXPECT_STRING_EQUAL(actual, expected)` expects that `actual` and `expected` strings are equal using `strcmp`.
 * - `XEXPECT_STRING_NOT_EQUAL(actual, expected)` expects that `actual` and `expected` strings are not equal using `strcmp`.
 * - `XEXPECT_STRING_LENGTH(actual, expected)` expects that the length of `actual` string is equal to `expected` using `strlen`.
 *
 * Example usage (C++):
 *
 * ```cpp
 * std::string str1 = "Hello";
 * std::string str2 = "World";
 * XEXPECT_STRING_EQUAL(str1, "Hello");  // Expect str1 to be equal to "Hello"
 * XEXPECT_STRING_LENGTH(str2, 5);      // Expect str2 to have a length of 5
 * ```
 *
 * Example usage (C):
 *
 * ```c
 * const char* cstr1 = "C programming";
 * const char* cstr2 = "C++ programming";
 * XEXPECT_STRING_NOT_EQUAL(cstr1, cstr2);  // Expect cstr1 and cstr2 to be different
 * XEXPECT_STRING_LENGTH(cstr1, 13);         // Expect cstr1 to have a length of 13
 * ```
 */

#ifdef __cplusplus
#define XEXPECT_STRING_EQUAL(actual, expected) XEXPECT((actual) == (expected), "String equality expectation not met")
#define XEXPECT_STRING_NOT_EQUAL(actual, expected) XEXPECT((actual) != (expected), "String inequality expectation not met")
#define XEXPECT_STRING_LENGTH(actual, expected) XEXPECT((actual).length() == (expected), "String length expectation not met")
#else
#define XEXPECT_STRING_EQUAL(actual, expected) XEXPECT(strcmp((actual), (expected)) == 0, "String equality expectation not met")
#define XEXPECT_STRING_NOT_EQUAL(actual, expected) XEXPECT(strcmp((actual), (expected)) != 0, "String inequality expectation not met")
#define XEXPECT_STRING_LENGTH(actual, expected) XEXPECT(strlen((actual)) == (expected), "String length expectation not met")
#endif

/**
 * @brief Macros for Expecting Character and Wide Character Equality, Inequality, and Ordering
 *
 * These macros provide a convenient way to perform various character and wide character
 * comparisons within test cases using the XUnit testing framework.
 *
 * - `XEXPECT_CHAR_EQUAL(actual, expected)` expects that `actual` and `expected` characters are equal.
 * - `XEXPECT_CHAR_NOT_EQUAL(actual, expected)` expects that `actual` and `expected` characters are not equal.
 * - `XEXPECT_CHAR_LESS(actual, expected)` expects that `actual` is less than `expected`.
 * - `XEXPECT_CHAR_GREATER(actual, expected)` expects that `actual` is greater than `expected`.
 * - `XEXPECT_CHAR_LESS_EQUAL(actual, expected)` expects that `actual` is less than or equal to `expected`.
 * - `XEXPECT_CHAR_GREATER_EQUAL(actual, expected)` expects that `actual` is greater than or equal to `expected`.
 *
 * Similar macros are provided for wide characters (`wchar_t`) using `XEXPECT_WCHAR_...` prefixes.
 *
 * Example usage:
 *
 * ```c
 * char ch1 = 'A';
 * char ch2 = 'B';
 * XEXPECT_CHAR_LESS(ch1, ch2);  // Expect ch1 to be less than ch2
 *
 * wchar_t wc1 = L'A';
 * wchar_t wc2 = L'B';
 * XEXPECT_WCHAR_GREATER(wc2, wc1);  // Expect wc2 to be greater than wc1
 * ```
 */

#define XEXPECT_CHAR_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "Character equality expectation not met")
#define XEXPECT_CHAR_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "Character inequality expectation not met")
#define XEXPECT_CHAR_LESS(actual, expected)          XEXPECT((actual) < (expected), "Character less-than expectation not met")
#define XEXPECT_CHAR_GREATER(actual, expected)       XEXPECT((actual) > (expected), "Character greater-than expectation not met")
#define XEXPECT_CHAR_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "Character less-than-or-equal expectation not met")
#define XEXPECT_CHAR_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "Character greater-than-or-equal expectation not met")

#define XEXPECT_WCHAR_EQUAL(actual, expected)         XEXPECT((actual) == (expected), "Wide character equality expectation not met")
#define XEXPECT_WCHAR_NOT_EQUAL(actual, expected)     XEXPECT((actual) != (expected), "Wide character inequality expectation not met")
#define XEXPECT_WCHAR_LESS(actual, expected)          XEXPECT((actual) < (expected), "Wide character less-than expectation not met")
#define XEXPECT_WCHAR_GREATER(actual, expected)       XEXPECT((actual) > (expected), "Wide character greater-than expectation not met")
#define XEXPECT_WCHAR_LESS_EQUAL(actual, expected)    XEXPECT((actual) <= (expected), "Wide character less-than-or-equal expectation not met")
#define XEXPECT_WCHAR_GREATER_EQUAL(actual, expected) XEXPECT((actual) >= (expected), "Wide character greater-than-or-equal expectation not met")

/**
 * @brief Macros for Expecting Various Array Operations
 *
 * These macros provide a convenient way to perform checks and expectations related
 * to array operations, such as array size validation, index bounds, null pointers,
 * and other array-related conditions.
 *
 * Common macros for array operations:
 * - `XEXPECT_ARRAY_INVALID_SIZE(size)` expects a valid (non-zero) array size.
 * - `XEXPECT_ARRAY_INDEX_OUT_OF_BOUNDS(index, size)` expects that the index is within bounds.
 * - `XEXPECT_ARRAY_NULL_POINTER(array)` expects that the array pointer is not null.
 * - `XEXPECT_ARRAY_INVALID_OPERATION(condition)` expects the given condition to be true for valid array operations.
 * - `XEXPECT_ARRAY_INDEX(array, index)` expects that the index is within bounds of the given array.
 *
 * Example usage:
 *
 * ```c
 * int array[10];
 * int size = 10;
 * int index = 5;
 *
 * XEXPECT_ARRAY_INVALID_SIZE(size); // Expect a valid array size.
 * XEXPECT_ARRAY_INDEX_OUT_OF_BOUNDS(index, size); // Expect index within bounds.
 * XEXPECT_ARRAY_NULL_POINTER(array); // Expect a non-null array pointer.
 * XEXPECT_ARRAY_INVALID_OPERATION(index >= 0 && index < size); // Expect a valid array operation.
 * XEXPECT_ARRAY_INDEX(array, index); // Expect index within bounds of the array.
 * ```
 */

#define XEXPECT_ARRAY_INVALID_SIZE(size)               XEXPECT((size) > 0, "Invalid array size")
#define XEXPECT_ARRAY_INDEX_OUT_OF_BOUNDS(index, size) XEXPECT((index) >= 0 && (index) < (size), "Array index out of bounds")
#define XEXPECT_ARRAY_NULL_POINTER(array)              XEXPECT((array) != NULL, "Null array pointer")
#define XEXPECT_ARRAY_INVALID_OPERATION(condition)     XEXPECT(condition, "Invalid array operation")
#define XEXPECT_ARRAY_INDEX(array, index)              XEXPECT((index) >= 0 && (index) < sizeof(array) / sizeof(array[0]), "Array index out of bounds")

/**
 * @brief Macros for Expecting Various File Operations
 *
 * These macros provide a convenient way to perform checks and expectations related
 * to file operations, such as file open, read, write, seek, tell, close, and checking
 * for the end of file (EOF).
 *
 * Common macros for file operations:
 * - `XEXPECT_FILE_OPEN(file)` expects a successful file open operation.
 * - `XEXPECT_FILE_READ(file)` expects a successful file read operation.
 * - `XEXPECT_FILE_WRITE(file)` expects a successful file write operation.
 * - `XEXPECT_FILE_SEEK(file, offset, whence)` expects a successful file seek operation.
 * - `XEXPECT_FILE_TELL(file)` expects a successful file tell operation.
 * - `XEXPECT_FILE_CLOSE(file)` expects a successful file close operation.
 * - `XEXPECT_FILE_EOF(stream)` expects that the end of file (EOF) is not reached.
 *
 * Example usage:
 *
 * ```c
 * FILE* file = fopen("example.txt", "r");
 * char buffer[100];
 * size_t size = 100;
 * long offset = 10;
 *
 * XEXPECT_FILE_OPEN(file); // Expect successful file open.
 * XEXPECT_FILE_READ(file); // Expect successful file read.
 * XEXPECT_FILE_WRITE(file); // Expect successful file write.
 * XEXPECT_FILE_SEEK(file, offset, SEEK_SET); // Expect successful file seek.
 * XEXPECT_FILE_TELL(file); // Expect successful file tell.
 * XEXPECT_FILE_CLOSE(file); // Expect successful file close.
 * XEXPECT_FILE_EOF(file); // Expect not reaching the end of file.
 * ```
 */

#define XEXPECT_FILE_OPEN(file)                 XEXPECT((file) != NULL, "Failed to open file")
#define XEXPECT_FILE_READ(file, buffer, size)   XEXPECT(fread(buffer, sizeof(char), size, file) == size, "Failed to read from file")
#define XEXPECT_FILE_WRITE(file, data, size)    XEXPECT(fwrite(data, sizeof(char), size, file) == size, "Failed to write to file")
#define XEXPECT_FILE_SEEK(file, offset, whence) XEXPECT(fseek(file, offset, whence) == 0, "Failed to seek within file")
#define XEXPECT_FILE_TELL(file)                 XEXPECT(ftell(file) != -1L, "Failed to get file position")
#define XEXPECT_FILE_CLOSE(file)                XEXPECT(fclose(file) == 0, "Failed to close file")
#define XEXPECT_FILE_EOF(stream)                XEXPECT(!feof(stream), "End of file (EOF) reached")

#ifdef __cplusplus
}
#endif

#endif
