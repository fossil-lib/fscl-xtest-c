/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XASSERTS_H
#define TRILOBITE_XASSERTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <math.h>

/*
    overview:
    >
    > This function is the main implementation of the assert functions.
    > It takes in four arguments:
    >
    > If the expression evaluates to false, then an error message
    > is printed.
    >
    args:
    -> expression: the expression to be evaluated
    -> file: the name of the file where the assertion occurred
    -> line: the line number where the assertion occurred
    -> func: the name of the function where the assertion occurred
*/
void _tril_xassert(int expresson, const char *file, int line, const char *func);

/*
  overview:
  >
  > This function checks if an expression is true. If it is false,
  > it prints an error message and exits the program.
  >
  > It also sets a flag that can be used to skip the assertion.
  >

  usage:
  >
  > int val = 5;
  >
  > TRIL_XASSERT(val == 5);
  >
  args:
  -> expresson: The expresson being asserted for a test case
*/
#define TRIL_XASSERT(expresson) \
    _tril_xassert(expresson, __FILE__, __LINE__, __func__);

#define TRIL_XASSERT_ITS_FALSE(expresson) \
    _tril_xassert(!expresson, __FILE__, __LINE__, __func__);

#define TRIL_XASSERT_ITS_TRUE(expresson) \
    _tril_xassert(expresson, __FILE__, __LINE__, __func__);

/*
  overview:
  >
  > This function is used to check if the given pointer it is NULL. If
  > the pointer is not NULL, then an assertion error is thrown.
  >
  args:
  -> ptr: the pointer value being tested
*/
#define TRIL_XASSERT_ITS_NULL(ptr)     \
    _tril_xassert((void *)ptr == NULL, \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This function is used to check if the given pointer is not NULL. If
  > the pointer is NULL, then an assertion error is thrown.
  >
  args:
  -> ptr: the pointer value being tested
*/
#define TRIL_XASSERT_NOT_NULL(ptr)     \
    _tril_xassert((void *)ptr != NULL, \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This macro will check if a given num is greater than value. If not,
  > an assertion error is raised.
  >
  args:
  -> num: the main value being tested
  -> value: the value we are testing with
*/
#define TRIL_XASSERT_GREATER_THAN(num, value) \
    _tril_xassert(num > value,                \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT_GREATER_THAN(num, value) \
    _tril_xassert((int)num > (int)value,          \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT8_GREATER_THAN(num, value) \
    _tril_xassert((int8_t)num > (int8_t)value,     \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT16_GREATER_THAN(num, value) \
    _tril_xassert((int16_t)num > (int16_t)value,    \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT32_GREATER_THAN(num, value) \
    _tril_xassert((int32_t)num > (int32_t)value,    \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT64_GREATER_THAN(num, value) \
    _tril_xassert((int64_t)num > (int64_t)value,    \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT_GREATER_THAN(num, value)         \
    _tril_xassert((unsigned int)num > (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT8_GREATER_THAN(num, value) \
    _tril_xassert((uint8_t)num > (uint8_t)value,    \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT16_GREATER_THAN(num, value) \
    _tril_xassert((uint16_t)num > (uint16_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT32_GREATER_THAN(num, value) \
    _tril_xassert((uint32_t)num > (uint32_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT64_GREATER_THAN(num, value) \
    _tril_xassert((uint64_t)num > (uint64_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_STR_GREATER_THAN(str, value)                 \
    _tril_xassert(strcmp((const char *)str, (const char *)value) > 0, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_GREATER_THAN(num, value) \
    _tril_xassert((float)num > (float)value,        \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_GREATER_THAN(num, value) \
    _tril_xassert((double)num > (double)value,       \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This macro will check if a given num is lesser than value. If not,
  > an assertion error is raised.
  >
  args:
  -> num: the main value being tested
  -> value: the value we are testing with
*/
#define TRIL_XASSERT_LESSER_THAN(num, value) \
    _tril_xassert(num < value,               \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT_LESSER_THAN(num, value) \
    _tril_xassert((int)num < (int)value,         \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT8_LESSER_THAN(num, value) \
    _tril_xassert((int8_t)num < (int8_t)value,    \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT16_LESSER_THAN(num, value) \
    _tril_xassert((int16_t)num < (int16_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT32_LESSER_THAN(num, value) \
    _tril_xassert((int32_t)num < (int32_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT64_LESSER_THAN(num, value) \
    _tril_xassert((int64_t)num < (int64_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT_LESSER_THAN(num, value)          \
    _tril_xassert((unsigned int)num < (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT8_LESSER_THAN(num, value) \
    _tril_xassert((uint8_t)num < (uint8_t)value,   \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT16_LESSER_THAN(num, value) \
    _tril_xassert((uint16_t)num < (uint16_t)value,  \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT32_LESSER_THAN(num, value) \
    _tril_xassert((uint32_t)num < (uint32_t)value,  \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT64_LESSER_THAN(num, value) \
    _tril_xassert((uint64_t)num < (uint64_t)value,  \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_STR_LESSER_THAN(num, value)                  \
    _tril_xassert(strcmp((const char *)str, (const char *)value) < 0, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_LESSER_THAN(num, value) \
    _tril_xassert((float)num < (float)value,       \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_LESSER_THAN(num, value) \
    _tril_xassert((double)num < (double)value,      \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This function is used to check whether a given number is greater
  > than or equal to a given value. If the condition is not met, an
  > assertion is triggered.
  >
  args:
  -> num: the main value being tested
  -> value: the value we are testing with
*/
#define TRIL_XASSERT_GREATER_OR_EQUAL(num, value) \
    _tril_xassert(num >= value, __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((int)num >= (int)value,             \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT8_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((int8_t)num >= (int8_t)value,        \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT16_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((int16_t)num >= (int16_t)value,       \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT32_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((int32_t)num >= (int32_t)value,       \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT64_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((int64_t)num >= (int64_t)value,       \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT_GREATER_OR_EQUAL(num, value)      \
    _tril_xassert((unsigned int)num >= (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT8_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((uint8_t)num >= (uint8_t)value,       \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT16_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((uint16_t)num >= (uint16_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT32_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((uint32_t)num >= (uint32_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT64_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((uint64_t)num >= (uint64_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((float)num >= (float)value,           \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_GREATER_OR_EQUAL(num, value) \
    _tril_xassert((double)num >= (double)value,          \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This function is used to check whether a given number is lesser
  > than or equal to a given value. If the condition is not met, an
  > assertion is triggered.
  >
  args:
  -> num: the main value being tested
  -> value: the value we are testing with
*/
#define TRIL_XASSERT_LESSER_OR_EQUAL(num, value) \
    _tril_xassert(num <= value, __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((int)num <= (int)value,            \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT8_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((int8_t)num <= (int8_t)value,       \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT16_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((int16_t)num <= (int16_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT32_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((int32_t)num <= (int32_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT64_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((int64_t)num <= (int64_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT_LESSER_OR_EQUAL(num, value)       \
    _tril_xassert((unsigned int)num <= (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT8_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((uint8_t)num <= (uint8_t)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT16_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((uint16_t)num <= (uint16_t)value,     \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT32_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((uint32_t)num <= (uint32_t)value,     \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT64_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((uint64_t)num <= (uint64_t)value,     \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((float)num <= (float)value,          \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_LESSER_OR_EQUAL(num, value) \
    _tril_xassert((double)num <= (double)value,         \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This macro is used to assert that a given number is equal to a
  > given value. It takes two arguments - num and value - and
  > compares them to see if they are equal. If not, it will throw
  > an error with the file, line, and function name.
  >
  args:
  -> num: the main value being tested
  -> value: the value we are testing with
*/
#define TRIL_XASSERT_ITS_EQUAL(num, value) \
    _tril_xassert(num == value, __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT_ITS_EQUAL(num, value) \
    _tril_xassert((int)num == (int)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT8_ITS_EQUAL(num, value) \
    _tril_xassert((int8_t)num == (int8_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT16_ITS_EQUAL(num, value)  \
    _tril_xassert((int16_t)num == (int16_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT32_ITS_EQUAL(num, value)  \
    _tril_xassert((int32_t)num == (int32_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT64_ITS_EQUAL(num, value)  \
    _tril_xassert((int64_t)num == (int64_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT_ITS_EQUAL(num, value)             \
    _tril_xassert((unsigned int)num == (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT8_ITS_EQUAL(num, value)  \
    _tril_xassert((uint8_t)num == (uint8_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT16_ITS_EQUAL(num, value)   \
    _tril_xassert((uint16_t)num == (uint16_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT32_ITS_EQUAL(num, value)   \
    _tril_xassert((uint32_t)num == (uint32_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT64_ITS_EQUAL(num, value)   \
    _tril_xassert((uint64_t)num == (uint64_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_BIT_ITS_EQUAL(num, value)              \
    _tril_xassert((unsigned int)num == (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_HEX_ITS_EQUAL(num, value)              \
    _tril_xassert((unsigned int)num == (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_OCT_ITS_EQUAL(num, value)              \
    _tril_xassert((unsigned int)num == (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_STR_ITS_EQUAL(str, value)                       \
    _tril_xassert(!(strcmp((const char *)str, (const char *)value)), \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_STR_ITS_EQUAL_LEN(str, value) \
    _tril_xassert(strlen(str) == value,            \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_CHAR_ITS_EQUAL(str, value)         \
    _tril_xassert((const char)str == (const char)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_ITS_EQUAL(num, value, epsilon)           \
    _tril_xassert(fabs((float)num - (float)value) > (float)epsilon, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_ITS_EQUAL(num, value, epsilon)     \
    _tril_xassert(labs((double)num - (double)value) > epsilon, \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This function is used to assert that a given num is not equal
  > to a given value. It is used to ensure that the code is running
  > as expected. "_tril_xassert()" is a helper function that is
  > used to handle the actual assertion. It takes in the comparison
  > result, the file name, line number, and function name as parameters.
  >
  args:
  -> num: the main value being tested
  -> value: the value we are testing with
*/
#define TRIL_XASSERT_NOT_EQUAL(num, value) \
    _tril_xassert(num != value, __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT_NOT_EQUAL(num, value) \
    _tril_xassert((int)num != (int)value,      \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT8_NOT_EQUAL(num, value) \
    _tril_xassert((int8_t)num != (int8_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT16_NOT_EQUAL(num, value)  \
    _tril_xassert((int16_t)num != (int16_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT32_NOT_EQUAL(num, value)  \
    _tril_xassert((int32_t)num != (int32_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_INT64_NOT_EQUAL(num, value)  \
    _tril_xassert((int64_t)num != (int64_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT_NOT_EQUAL(num, value)             \
    _tril_xassert((unsigned int)num != (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT8_NOT_EQUAL(num, value)  \
    _tril_xassert((uint8_t)num != (uint8_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT16_NOT_EQUAL(num, value)   \
    _tril_xassert((uint16_t)num != (uint16_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT32_NOT_EQUAL(num, value)   \
    _tril_xassert((uint32_t)num != (uint32_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_UINT64_NOT_EQUAL(num, value)   \
    _tril_xassert((uint64_t)num != (uint64_t)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_BIT_NOT_EQUAL(num, value)              \
    _tril_xassert((unsigned int)num != (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_HEX_NOT_EQUAL(num, value)              \
    _tril_xassert((unsigned int)num != (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_OCT_NOT_EQUAL(num, value)              \
    _tril_xassert((unsigned int)num != (unsigned int)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_STR_NOT_EQUAL(str, value)                      \
    _tril_xassert((strcmp((const char *)str, (const char *)value)), \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_CHAR_NOT_EQUAL(str, value)         \
    _tril_xassert((const char)str != (const char)value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_STR_NOT_EQUAL_LEN(str, value) \
    _tril_xassert(strlen(str) != value,            \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_NOT_EQUAL(num, value, epsilon)            \
    _tril_xassert(fabs((float)num - (float)value) <= (float)epsilon, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_NOT_EQUAL(num, value, epsilon)      \
    _tril_xassert(labs((double)num - (double)value) <= epsilon, \
                  __FILE__, __LINE__, __func__)

/*
  overview:
  >
  > This function checks if a given number is within a given range
  > (min_value and max_value). If it is not, an assertion is triggered.
  >
  args:
  -> num: the main value being tested
  -> min_value: the minimum value in a range to search
  -> max_value: the maximum value in a range to search
*/
#define TRIL_XASSERT_INT_WITHIN_RANGE(num, min_value, max_value)            \
    _tril_xassert((int)num >= (int)min_value && (int)num <= (int)max_value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_FLOAT_WITHIN_RANGE(num, min_value, max_value)                  \
    _tril_xassert((float)num >= (float)min_value && (float)num <= (float)max_value, \
                  __FILE__, __LINE__, __func__)

#define TRIL_XASSERT_DOUBLE_WITHIN_RANGE(num, min_value, max_value)                  \
    _tril_xassert((double)num >= (double)min_value && (double)num <= (double)max_value, \
                  __FILE__, __LINE__, __func__)

#ifdef __cplusplus
}
#endif

#endif
