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

// Define the mock function return type using macro selection
#define XMOCK_FUNC_RETURN_TYPE(type) XMOCK_##type

// Define the macro to convert a value to the mocked function return type
#define XMOCK_FUNC_RETVAL(type, value) (XMOCK_FUNC_RETURN_TYPE(type))(value)

// Define mock function return types based on types
#define XMOCK_int int
#define XMOCK_int8_t int8_t
#define XMOCK_int16_t int16_t
#define XMOCK_int32_t int32_t
#define XMOCK_int64_t int64_t
#define XMOCK_unsignedint unsigned int
#define XMOCK_uint8_t uint8_t
#define XMOCK_uint16_t uint16_t
#define XMOCK_uint32_t uint32_t
#define XMOCK_uint64_t uint64_t
#define XMOCK_float float
#define XMOCK_double double
#define XMOCK_charp char *
#define XMOCK_default void *

// Define a mocked function using macro concatenation
#define XMOCK_FUNC(type, name) XMOCK_FUNC_RETURN_TYPE(type) xmock_##name(type arg)

#ifdef __cplusplus
}
#endif

#endif
