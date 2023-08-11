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

#include <stddef.h>

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.

//
// STUB
//
typedef struct XMockStub
{
   void *(*func_ptr)(void *);
   void *_result;
   size_t _size;
} XMockStub;

XMockStub *tril_xmock_stub_create(void *(*func_ptr)(void *), void *result, size_t size);
void tril_xmock_stub_erase(XMockStub *stub);
void *tril_xmock_stub_call(XMockStub *stub, void *arg);



#ifdef __cplusplus
}
#endif

#endif
