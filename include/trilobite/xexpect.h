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
   This code defines a set of macros used for asserting the equality,
   inequality, and other relational operators between two values.

    @param actual - The actual value to be tested
    @param expected - The expected value to be tested against
    @param message - The message to be displayed if the assertion fails

    @returns If the assertion fails, the code will return an error message with
             the given message.
*/

#define XEXPECT_INT_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_INT_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_INT_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_INT_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_INT_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_INT_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_INT8_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_INT8_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_INT8_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_INT8_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_INT8_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_INT8_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_INT16_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_INT16_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_INT16_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_INT16_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_INT16_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_INT16_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_INT32_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_INT32_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_INT32_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_INT32_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_INT32_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_INT32_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_INT64_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_INT64_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_INT64_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_INT64_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_INT64_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_INT64_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_UINT_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_UINT_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_UINT_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_UINT_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_UINT_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_UINT_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_UINT8_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_UINT8_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_UINT8_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_UINT8_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_UINT8_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_UINT8_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_UINT16_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_UINT16_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_UINT16_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_UINT16_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_UINT16_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_UINT16_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_UINT32_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_UINT32_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_UINT32_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_UINT32_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_UINT32_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_UINT32_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_UINT64_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_UINT64_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_UINT64_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_UINT64_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_UINT64_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_UINT64_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_HEX_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_HEX_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_HEX_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_HEX_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_HEX_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_HEX_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_HEX8_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_HEX8_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_HEX8_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_HEX8_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_HEX8_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_HEX8_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_HEX16_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_HEX16_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_HEX16_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_HEX16_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_HEX16_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_HEX16_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_HEX32_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_HEX32_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_HEX32_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_HEX32_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_HEX32_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_HEX32_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_HEX64_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_HEX64_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_HEX64_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_HEX64_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_HEX64_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_HEX64_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_OCT_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_OCT_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_OCT_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_OCT_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_OCT_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_OCT_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_BIT_EQUAL(actual, expected, message)            XEXPECT((actual) == (expected), message)
#define XEXPECT_BIT_NOT_EQUAL(actual, expected, message)        XEXPECT((actual) != (expected), message)
#define XEXPECT_BIT_LESS(actual, expected, message)             XEXPECT((actual) < (expected), message)
#define XEXPECT_BIT_GREATER(actual, expected, message)          XEXPECT((actual) > (expected), message)
#define XEXPECT_BIT_LESS_EQUAL(actual, expected, message)       XEXPECT((actual) <= (expected), message)
#define XEXPECT_BIT_GREATER_EQUAL(actual, expected, message)    XEXPECT((actual) >= (expected), message)
#define XEXPECT_BIT_NOT_HIGH(value, bitIndex, message)          XEXPECT(!((value) & (1 << (bitIndex))), message)
#define XEXPECT_BIT_HIGH(value, bitIndex, message)              XEXPECT((value) & (1 << (bitIndex)), message)
#define XEXPECT_BIT_NOT_LOW(value, bitIndex, message)           XEXPECT((value) & (1 << (bitIndex)), message)
#define XEXPECT_BIT_LOW(value, bitIndex, message)               XEXPECT(!((value) & (1 << (bitIndex))), message)
#define XEXPECT_BITS_NOT_HIGH(value, mask, message)             XEXPECT(((value) & (mask)) != (mask), message)
#define XEXPECT_BITS_HIGH(value, mask, message)                 XEXPECT(((value) & (mask)) == (mask), message)
#define XEXPECT_BITS_NOT_LOW(value, mask, message)              XEXPECT(((value) & (mask)) != 0, message)
#define XEXPECT_BITS_LOW(value, mask, message)                  XEXPECT(((value) & (mask)) == 0, message)
#define XEXPECT_BITS_NOT_EQUAL(actual, expected, mask, message) XEXPECT(((actual) & (mask)) != ((expected) & (mask)), message)
#define XEXPECT_BITS_EQUAL(actual, expected, mask, message)     XEXPECT(((actual) & (mask)) == ((expected) & (mask)), message)
#define XEXPECT_BITS_NOT_LESS(actual, expected, mask, message)  XEXPECT(((actual) & (mask)) >= ((expected) & (mask)), message)
#define XEXPECT_BITS_LESS(actual, expected, mask, message)      XEXPECT(((actual) & (mask)) < ((expected) & (mask)), message)
#define XEXPECT_BITS_NOT_GREATER(actual, expected, mask, message) XEXPECT(((actual) & (mask)) <= ((expected) & (mask)), message)
#define XEXPECT_BITS_GREATER(actual, expected, mask, message)   XEXPECT(((actual) & (mask)) > ((expected) & (mask)), message)
#define XEXPECT_BITS_NOT_LESS_EQUAL(actual, expected, mask, message) XEXPECT(((actual) & (mask)) > ((expected) & (mask)), message)
#define XEXPECT_BITS_LESS_EQUAL(actual, expected, mask, message) XEXPECT(((actual) & (mask)) <= ((expected) & (mask)), message)
#define XEXPECT_BITS_NOT_GREATER_EQUAL(actual, expected, mask, message) XEXPECT(((actual) & (mask)) < ((expected) & (mask)), message)
#define XEXPECT_BITS_GREATER_EQUAL(actual, expected, mask, message) XEXPECT(((actual) & (mask)) >= ((expected) & (mask)), message)

/**
    This macro is used to check if a given value is within a certain
    tolerance of the expected value.

    @param actual: The actual value to be compared
    @param expected: The value to compare against
    @param tolerance: The allowed difference between the actual and expected values
    @param message: The message to be displayed if the comparison fails

    @returns true if the actual is within the tolerance of the expected value, false otherwise.
*/

#define XEXPECT_INT_WITHIN(actual, expected, tolerance, message) XEXPECT(fabs((actual) - (expected)) <= (tolerance), message)
#define XEXPECT_UINT_WITHIN(actual, expected, tolerance, message) XEXPECT(fabs((actual) - (expected)) <= (tolerance), message)
#define XEXPECT_HEX_WITHIN(actual, expected, tolerance, message) XEXPECT(fabs((actual) - (expected)) <= (tolerance), message)
#define XEXPECT_BIN_WITHIN(actual, expected, tolerance, message) XEXPECT(fabs((actual) - (expected)) <= (tolerance), message)
#define XEXPECT_OCT_WITHIN(actual, expected, tolerance, message) XEXPECT(fabs((actual) - (expected)) <= (tolerance), message)
#define XEXPECT_FLOAT_WITHIN(actual, expected, epsilon, message) XEXPECT(fabs((actual) - (expected)) <= (epsilon), message)
#define XEXPECT_DOUBLE_WITHIN(actual, expected, epsilon, message) XEXPECT(fabs((actual) - (expected)) <= (epsilon), message)
#define XEXPECT_CHAR_WITHIN(actual, min, max, message) XEXPECT((value) > (min) || (value) < (max), message)

/**
    This macro framework provides an easy way to assert the equality,
    inequality, greater than, less than, greater than or equal to, and
    less than or equal to of floats and doubles.

    For example, to assert that a float is equal to a certain value within
    an epsilon, use the macro XASSERT_FLOAT_EQUAL(actual, expected, epsilon, message).

    @param actual: The actual value to be tested
    @param expected: The expected value to be tested against
    @param epsilon: The allowed difference between the actual and expected values
    @param message: The message to be printed if the assertion fails

    @returns: If the assertion passes, the code will continue to execute. If the assertion fails,
              the code will terminate and the message will be printed.
*/

#define XEXPECT_FLOAT_EQUAL(actual, expected, epsilon, message)     XEXPECT(fabs((actual) - (expected)) <= (epsilon), message)
#define XEXPECT_FLOAT_NOT_EQUAL(actual, expected, epsilon, message) XEXPECT(fabs((actual) - (expected)) < (epsilon), message)
#define XEXPECT_FLOAT_LESS(actual, expected, message)               XEXPECT((actual) < (expected), message)
#define XEXPECT_FLOAT_GREATER(actual, expected, message)            XEXPECT((actual) > (expected), message)
#define XEXPECT_FLOAT_GREATER_EQUAL(actual, expected, message)      XEXPECT((actual) >= (expected), message)
#define XEXPECT_FLOAT_LESS_EQUAL(actual, expected, message)         XEXPECT((actual) <= (expected), message)
#define XEXPECT_FLOAT_IS_NOT_INF(value, message) XEXPECT(!isinf(value) || (value) <= 0, message)
#define XEXPECT_FLOAT_IS_INF(value, message) XEXPECT(isinf(value) && (value) > 0, message)
#define XEXPECT_FLOAT_IS_NOT_NEG_INF(value, message) XEXPECT(!isinf(value) || (value) >= 0, message)
#define XEXPECT_FLOAT_IS_NEG_INF(value, message) XEXPECT(isinf(value) && (value) < 0, message)
#define XEXPECT_FLOAT_IS_NOT_FINITE(value, message) XEXPECT(!isfinite(value), message)
#define XEXPECT_FLOAT_IS_FINITE(value, message) XEXPECT(isfinite(value), message)
#define XEXPECT_FLOAT_IS_NOT_NAN(value, message) XEXPECT(!isnan(value), message)
#define XEXPECT_FLOAT_IS_NAN(value, message) XEXPECT(isnan(value), message)


#define XEXPECT_DOUBLE_EQUAL(actual, expected, epsilon, message)     XEXPECT(fabs((actual) - (expected)) <= (epsilon), message)
#define XEXPECT_DOUBLE_NOT_EQUAL(actual, expected, epsilon, message) XEXPECT(fabs((actual) - (expected)) < (epsilon), message)
#define XEXPECT_DOUBLE_LESS(actual, expected, message)               XEXPECT((actual) < (expected), message)
#define XEXPECT_DOUBLE_GREATER(actual, expected, message)            XEXPECT((actual) > (expected), message)
#define XEXPECT_DOUBLE_GREATER_EQUAL(actual, expected, message)      XEXPECT((actual) >= (expected), message)
#define XEXPECT_DOUBLE_LESS_EQUAL(actual, expected, message)         XEXPECT((actual) <= (expected), message)
#define XEXPECT_DOUBLE_IS_NOT_INF(value, message) XEXPECT(!isinf(value) || (value) <= 0, message)
#define XEXPECT_DOUBLE_IS_INF(value, message) XEXPECT(isinf(value) && (value) > 0, message)
#define XEXPECT_DOUBLE_IS_NOT_NEG_INF(value, message) XEXPECT(!isinf(value) || (value) >= 0, message)
#define XEXPECT_DOUBLE_IS_NEG_INF(value, message) XEXPECT(isinf(value) && (value) < 0, message)
#define XEXPECT_DOUBLE_IS_NOT_FINITE(value, message) XEXPECT(!isfinite(value), message)
#define XEXPECT_DOUBLE_IS_FINITE(value, message) XEXPECT(isfinite(value), message)
#define XEXPECT_DOUBLE_IS_NOT_NAN(value, message) XEXPECT(!isnan(value), message)
#define XEXPECT_DOUBLE_IS_NAN(value, message) XEXPECT(isnan(value), message)

/**
    This framework contains four assert macros to check for null,
    not null, true and false values.

    @param pointer A pointer to the value to be checked
    @param expression An expression to be evaluated to check for true or false
    @param message A message to be printed if the assertion fails

    @returns If the assertion fails, the program will terminate with an error message.
*/

#ifdef __cplusplus
#define XEXPECT_NULL(pointer, message)      XEXPECT((pointer) == nullptr, message)
#define XEXPECT_NOT_NULL(pointer, message)  XEXPECT((pointer) != nullptr, message)
#define XEXPECT_EMPTY(pointer, message)     XEXPECT((pointer) == nullptr, message)
#define XEXPECT_NOT_EMPTY(pointer, message) XEXPECT((pointer) != nullptr, message)
#else
#define XEXPECT_NULL(pointer, message)      XEXPECT((pointer) == NULL, message)
#define XEXPECT_NOT_NULL(pointer, message)  XEXPECT((pointer) != NULL, message)
#define XEXPECT_EMPTY(pointer, message)     XEXPECT((pointer) == NULL, message)
#define XEXPECT_NOT_EMPTY(pointer, message) XEXPECT((pointer) != NULL, message)
#endif

#define XEXPECT_PTR_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_PTR_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_PTR_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_PTR_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_PTR_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_PTR_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_UNLESS(expression, message)  XEXPECT((expression), message)
#define XEXPECT_TRUE(expression, message)    XEXPECT((expression), message)
#define XEXPECT_FALSE(expression, message)   XEXPECT(!(expression), message)

/**
    This macro can be used to compare two strings.

    @param actual: The actual string to be compared
    @param expected: The expected string to be compared
    @param message: The message to be displayed when the assertion fails

    @returns If actualis equal to expected, the code will continue. If actual
             is not equal to expected, the code will be terminated and the message
             will be displayed.
*/

#ifdef __cplusplus
#define XEXPECT_STRING_EQUAL(actual, expected, message) XEXPECT((actual) == (expected), message)
#else
#define XEXPECT_STRING_EQUAL(actual, expected, message) XEXPECT(strcmp((actual), (expected)) == 0, message)
#endif

#ifdef __cplusplus
#define XEXPECT_STRING_NOT_EQUAL(actual, expected, message) XEXPECT((actual) != (expected), message)
#else
#define XEXPECT_STRING_NOT_EQUAL(actual, expected, message) XEXPECT(strcmp((actual), (expected)) != 0, message)
#endif

#define XEXPECT_STRING_LENGTH(actual, expected, message) XEXPECT(strlen((actual)) == (expected), message)

// char and wchar types
#define XEXPECT_CHAR_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_CHAR_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_CHAR_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_CHAR_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_CHAR_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_CHAR_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#define XEXPECT_WCHAR_EQUAL(actual, expected, message)         XEXPECT((actual) == (expected), message)
#define XEXPECT_WCHAR_NOT_EQUAL(actual, expected, message)     XEXPECT((actual) != (expected), message)
#define XEXPECT_WCHAR_LESS(actual, expected, message)          XEXPECT((actual) < (expected), message)
#define XEXPECT_WCHAR_GREATER(actual, expected, message)       XEXPECT((actual) > (expected), message)
#define XEXPECT_WCHAR_LESS_EQUAL(actual, expected, message)    XEXPECT((actual) <= (expected), message)
#define XEXPECT_WCHAR_GREATER_EQUAL(actual, expected, message) XEXPECT((actual) >= (expected), message)

#ifdef __cplusplus
}
#endif

#endif
