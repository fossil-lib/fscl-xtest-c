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

// Define mock function return types based on types.
typedef int xmock_int;
typedef int8_t xmock_int8_t;
typedef int16_t xmock_int16_t;
typedef int32_t xmock_int32_t;
typedef int64_t xmock_int64_t;
typedef unsigned int xmock_uint;
typedef uint8_t xmock_uint8_t;
typedef uint16_t xmock_uint16_t;
typedef uint32_t xmock_uint32_t;
typedef uint64_t xmock_uint64_t;
typedef uint8_t xmock_hex8_t;
typedef uint16_t xmock_hex16_t;
typedef uint32_t xmock_hex32_t;
typedef uint64_t xmock_hex64_t;
typedef float xmock_float;
typedef double xmock_double;

// Define a macro for char type.
typedef char xmock_char;

// Define a macro for char * type.
typedef char *xmock_string;

typedef void *xmock_default;

// Define a mocked function using macro concatenation.
// This macro provides a way to define mocked functions with specified return types and arguments.
#define XMOCK_FUNC(type, name) type xmock_##name(type arg)

#ifdef __cplusplus
}
#endif

#endif
