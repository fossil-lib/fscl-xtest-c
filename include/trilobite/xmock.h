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

// Define the mock function macro using _Generic
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

#define XMOCK_FUNC_RETVAL(type, value) (XMOCK_FUNC_RETURN_TYPE(type))(value)

// Mocked function using _Generic
#define XMOCK_FUNC(type, name) XMOCK_FUNC_RETURN_TYPE(type) xmock_##name(type arg) { \
    return XMOCK_FUNC_RETVAL(type, arg); \
} // end macro

#ifdef __cplusplus
}
#endif

#endif
