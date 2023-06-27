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

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.
//

typedef struct UTestRunner UTestRunner; // end struct

UTestRunner *tril_xtest_create_runner(void);
int tril_xtest_end_runner(UTestRunner *runner);
void tril_xtest_flag_skip(int flag);
void tril_xtest_flag_output(int flag);
void tril_xtest_setup(UTestRunner *runner, void (*func)());
void tril_xtest_teardown(UTestRunner *runner, void (*func)());
void tril_xtest_run(UTestRunner *runner, void (*test)());

#ifdef __cplusplus
}
#endif

#endif
