/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XERRORS_H
#define TRILOBITE_XERRORS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

/**
 * @brief Expect and Handle Exception in XUnit Test Cases
 *
 * The `XERRORS_EXPECT_THROW` macro is used to specify that an exception is expected
 * during an XUnit test case. It evaluates the given `expression` and checks if it throws
 * an exception of the specified `exceptionType`. You can also provide an optional
 * `message` for additional context.
 *
 * Example usage:
 *
 * ```c
 * XERRORS_EXPECT_THROW(my_function(), "ExceptionType", "Exception message");
 * ```
 *
 * If the `expression` does not throw the expected exception, the test case will fail.
 */
#define XERRORS_EXPECT_THROW(expression, error_type, error_msg, message) XERRORS(expression, error_type, error_msg, message)

/**
 * @brief Expect Exception with Specific Message in XUnit Test Cases
 *
 * The `XERRORS_EXPECT_THROW_WITH_MESSAGE` macro is used to specify that an exception
 * with a specific message is expected during an XUnit test case. It evaluates the given
 * `expression` and checks if it throws an exception of the specified `exceptionType`
 * with the `expectedMessage`. You can also provide an optional `message` for additional
 * context.
 *
 * Example usage:
 *
 * ```c
 * XERRORS_EXPECT_THROW_WITH_MESSAGE(my_function(), "ExceptionType", "Expected message", "Additional context.");
 * ```
 *
 * If the `expression` does not throw the expected exception or the message does not match,
 * the test case will fail.
 */
#define XERRORS_EXPECT_THROW_WITH_MESSAGE(expression, error_type, error_msg, message) XERRORS(expression, error_type, error_msg, message)

/**
 * @brief Expect Custom Error in XUnit Test Cases
 *
 * The `XERRORS_EXPECT_CUSTOM_ERROR` macro is used to specify that a custom error is
 * expected during an XUnit test case. It evaluates the given `expression` and checks if
 * it throws an exception of the specified `customErrorType`. You can provide an optional
 * `message` for additional context.
 *
 * Example usage:
 *
 * ```c
 * XERRORS_EXPECT_CUSTOM_ERROR(my_function(), "CustomErrorType", "Custom error message");
 * ```
 *
 * If the `expression` does not throw the expected custom error, the test case will fail.
 */
#define XERRORS_EXPECT_CUSTOM_ERROR(expression, error_type, error_msg, message) XERRORS(expression, error_type, error_msg, message)

#ifdef __cplusplus
}
#endif

#endif
