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

// Define macros for handling exceptions and errors
#define XERRORS_EXPECT_THROW(expression, exceptionType, message) \
    XERRORS(expression, exceptionType, message)

#define XERRORS_EXPECT_NO_THROW(expression, message) \
    XERRORS(expression, NULL, message)

#define XERRORS_EXPECT_THROW_WITH_MESSAGE(expression, exceptionType, expectedMessage, message) \
    XERRORS(expression, exceptionType, expectedMessage)

#define XERRORS_EXPECT_CUSTOM_ERROR(expression, customErrorType, message) \
    XERRORS(expression, customErrorType, message)

#define XERRORS_EXPECT_CUSTOM_ERROR_WITH_PREDICATE(expression, customErrorType, errorPredicate, message) \
    do { \
        if (setjmp(errorBuffer) == 0) { \
            expression; \
            fprintf(stderr, "Test failed: Expected custom error '%s' but none was thrown.\n", customErrorType); \
        } else { \
            CustomError* error = (CustomError*)__builtin_extract_return_addr(__builtin_return_address(0)); \
            if (strcmp(error->type, customErrorType) != 0) { \
                fprintf(stderr, "Test failed: Expected custom error '%s' but got '%s'.\n", customErrorType, error->type); \
            } else if (!errorPredicate(error->message)) { \
                fprintf(stderr, "Test failed: Custom error predicate failed.\n"); \
            } \
        } \
    } while (0)


/*
void test_exception_handling() {
    XERRORS_EXPECT_THROW(xerrors_throw("Exception", "Test"), "Exception", "Test");
    XERRORS_EXPECT_NO_THROW(printf("No exception\n"));
    XERRORS_EXPECT_THROW_WITH_MESSAGE(xerrors_throw("Exception", "Test"), "Exception", "Test", "Custom message");
    XERRORS_EXPECT_CUSTOM_ERROR(xerrors_throw("CustomError", "Test"), "CustomError", "Test");
    XERRORS_EXPECT_CUSTOM_ERROR_WITH_PREDICATE(xerrors_throw("CustomError", "Test"), "CustomError", custom_error_predicate, "CustomErrorMessage");
}
*/

#ifdef __cplusplus
}
#endif

#endif
