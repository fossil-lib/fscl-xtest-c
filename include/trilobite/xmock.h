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
// STUB
//
typedef struct XMockStub
{
   void *(*func_ptr)(void *);
   void *_result;
   size_t _size;
} XMockStub;

XMockStub *xmock_stub_create(void *(*func_ptr)(void *), void *result, size_t size);
void xmock_stub_erase(XMockStub *stub);
void *xmock_stub_call(XMockStub *stub, void *arg);



#ifdef __cplusplus
}
#endif

#endif
