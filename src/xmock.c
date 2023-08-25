/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xmock.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/*
  overview:
  >
  > This macro creates a XMockStub struct and initializes
  > it with the given parameters. It returns a pointer to
  > the newly created XMockStub struct or NULL if the
  > allocation failed.
  >
  args:
  -> func_ptr: the stub function being used
  -> result: result value of the mock
  -> size: the size of the arg being used
*/
XMockStub *xmock_stub_create(void *(*func_ptr)(void *), void *result, size_t size)
{
    XMockStub *stub = malloc(sizeof(XMockStub));
    if (stub)
    {
        stub->func_ptr = func_ptr;
        stub->_result = result;
        stub->_size = size;
    } // end if
    return stub;
} // end of func

/*
  overview:
  >
  > This function tril_xmock_stub_erase() is used to free
  > the memory allocated to the XMockStub pointer stub.
  > The function checks if the stub pointer is valid before
  > freeing the memory.
  >
  args:
  -> stub: That stub structure being used
*/
void xmock_stub_erase(XMockStub *stub)
{
    if (stub)
    {
        free(stub);
    } // end if    
} // end of func

// ============================================================
//
// Internal inline functions are functions that are declared
// inside another function and can only be used within that
// function. They are declared with the keyword 'inline' and
// can be used to reduce the overhead of calling a function
// multiple times.
//
// ============================================================

//
// This macro is used to cast a void * pointer to an 
// int * pointer. It is useful for mocking functions
// that take an int * as an argument.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
inline void *_xmock_stub_arg_int(void *value)
{
    return (int *)value;
} // end of inline func

//
// This macro is used to cast a void * pointer to an 
// uint * pointer. It is useful for mocking functions
// that take an uint * as an argument.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
inline void *_xmock_stub_arg_uint(void *value)
{
    return (unsigned int *)value;
} // end of inline func

//
// This macro is used to cast a void * pointer to an 
// float * pointer. It is useful for mocking functions
// that take an float * as an argument.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
inline void *_xmock_stub_arg_float(void *value)
{
    return (float *)value;
} // end of inline func

//
// This macro is used to cast a void * pointer to an 
// double * pointer. It is useful for mocking functions
// that take an double * as an argument.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
inline void *_xmock_stub_arg_double(void *value)
{
    return (double *)value;
} // end of inline func

//
// This macro is used to cast a void * pointer to an 
// char * pointer. It is useful for mocking functions
// that take an char * as an argument.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
inline void *_xmock_stub_arg_string(void *value)
{
    return (char *)value;
} // end of inline func

//
// This macro is used to cast a void * pointer to an 
// char pointer. It is useful for mocking functions
// that take an char as an argument.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - -
inline void *_xmock_stub_arg_char(void *value)
{
    return value;
} // end of inline func

//
// ???
//
inline void *_xmock_stub_arg_generic(void *value)
{
    return NULL;
} // end of inline func

//
// This macro is used to provide a generic way to pass arguments to
// a function stub. It will match the type of the argument provided
// and call the corresponding function stub for that type.
//
#define XMOCK_STUB_ARG(type) _Generic((type),   \
    int:          &_xmock_stub_arg_int,    \
    unsigned int: &_xmock_stub_arg_uint,   \
    char *:       &_xmock_stub_arg_string, \
    char:         &_xmock_stub_arg_char,   \
    float:        &_xmock_stub_arg_float,  \
    double:       &_xmock_stub_arg_double, \
    default:      &_xmock_stub_arg_generic \
)


/*
  overview:
  >
  > This macro checks if the function pointer and size
  > of the stub are valid, then checks if the argument
  > handler is valid and compares the argument with the
  > stub size. If all conditions are met, it returns the
  > stub result, otherwise it returns NULL and falls back
  > to the real function call.
  >
  args:
  -> stub: That stub structure being used
  -> arg: That generic data type being passed in
*/
void *xmock_stub_call(XMockStub *stub, void *arg)
{
    if (stub && stub->func_ptr && stub->_size > 0)
    {
        void* (*arg_handler)(void*) = XMOCK_STUB_ARG(*arg);
        if (arg_handler && memcmp(arg_handler(arg), arg, stub->_size) == 0)
        {
            return stub->_result;
        } // end if
    } // end if
    return NULL; // Fallback to real function call
} // end of func
