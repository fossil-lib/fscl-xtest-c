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

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.

//   
// classic integers
//
// signed integers
typedef char xmock_int8;
typedef short xmock_int16;
typedef int xmock_int32;
typedef long xmock_int64;

// unsigned integers
typedef unsigned char xmock_uint8;
typedef unsigned short xmock_uint16;
typedef unsigned int xmock_uint32;
typedef unsigned long xmock_uint64;

// const integers
//
// const signed integers
typedef const char c_xmock_int8;
typedef const short c_xmock_int16;
typedef const int c_xmock_int32;
typedef const long c_xmock_int64;

// const unsigned integers
typedef const unsigned char c_xmock_uint8;
typedef const unsigned short c_xmock_uint16;
typedef const unsigned int c_xmock_uint32;
typedef const unsigned long c_xmock_uint64;

// floating point types
//
// float
typedef float xmock_float;
typedef double xmock_double;

// strings and char types
//
// strings
typedef char *xmock_string;
typedef const char *c_xmock_string;

// pointer types
//
// pointers
typedef void *xmock_ptr;
typedef const void *c_xmock_ptr;

// boolean value types
//
// boolean
typedef enum xmock_boolean
{
    xmock_true,
    xmock_false
} xmock_blooean; // end of enum

//
// STUBS and FAKES
//

int tril_xmock_stub_integer(int value);
const char *tril_xmock_stub_string(const char value);
void tril_xmock_stub_loop(int iter);
void *tril_xmock_stub_nullptr(void);


#ifdef __cplusplus
}
#endif

#endif
