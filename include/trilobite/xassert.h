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

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.
//   
void tril_xtest_assert(int expresson, const char * message);
void tril_xtest_expect(int expresson, const char * message);

#ifdef __cplusplus
}
#endif

#endif
