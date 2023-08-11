/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XTEST_H
#define TRILOBITE_XTEST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xbench.h"
#include "xmock.h"
#include "xassert.h"

#include <stdio.h>

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.
//

typedef struct XTestRunner XTestRunner; // end struct

#define XTEST(name)                           \
   void xtest_##name();                       \
   void run_##name()                          \
   {                                          \
      printf("Running test: %s\n", __func__); \
   }                                          \
   void xtest_##name()

#define XBENCH(name)                           \
   void xbench_##name();                       \
   void run_##name()                          \
   {                                          \
      printf("Running bench: %s\n", __func__); \
   }                                          \
   void xbench_##name()

XTestRunner *tril_xtest_create_runner(void (*setup)(), void (*teardown)());
int tril_xtest_end_runner(XTestRunner *runner);
void tril_xtest_flag_skip(int flag);
void tril_xtest_setup(XTestRunner *runner, void (*func)());
void tril_xtest_teardown(XTestRunner *runner, void (*func)());
void tril_xtest_run(XTestRunner *runner, void (*test)());

#ifdef __cplusplus
}
#endif

#endif
