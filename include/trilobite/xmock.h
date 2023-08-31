/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XMOCK_H
#define TRILOBITE_XMOCK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

//
// Define the mock function return type using _Generic
// @param type: The type of the value being returned by the mock function.
// @return: The appropriate type for the return value based on the input type.
//
#define XMOCK_FUNC_RETURN_TYPE(type) _Generic((type), \
    int: int, \
    int8_t: int8_t, \
    int16_t: int16_t, \
    int32_t: int32_t, \
    int64_t: int64_t, \
    unsigned int: unsigned int, \
    uint8_t: uint8_t, \
    uint16_t: uint16_t, \
    uint32_t: uint32_t, \
    uint64_t: uint64_t, \
    float: float, \
    double: double, \
    char *: char *, \
    default: void * \
)

//
// Define the macro to convert a value to the mocked function return type
// @param type: The type of the value being converted.
// @param value: The value to be converted to the return type.
// @return: The value is converted to the appropriate return type.
//
#define XMOCK_FUNC_RETVAL(type, value) (XMOCK_FUNC_RETURN_TYPE(type))(value)

//
// Define a mocked function using _Generic
// @param type: The return type of the mocked function.
// @param name: The name of the mocked function.
//
#define XMOCK_FUNC(type, name) XMOCK_FUNC_RETURN_TYPE(type) xmock_##name(type arg)

#ifdef __cplusplus
}
#endif

#endif
