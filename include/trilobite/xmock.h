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

int tril_xmock_stub_integer(int value);
const char *tril_xmock_stub_string(const char *value);
void tril_xmock_stub_loop(int iter);
void *tril_xmock_stub_nullptr(void);


#ifdef __cplusplus
}
#endif

#endif
