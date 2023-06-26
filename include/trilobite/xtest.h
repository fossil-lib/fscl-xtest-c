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

/*
  overview:
  > As the name suggests, UTestRunner is a tool
  > that is used to run or execute tests and track
  > results. The runner has a setup and teardown
  > function built-in and are set to nullptr by
  > default, the structure also has a range of
  > score values for pass/fail and more.
  >
  args:
  -> _pass: pass test score value
  -> _fail: fail test score value
  -> _skip: skip test score value
  -> _error: error test score value
  -> _total: total test score run
  -> _setup: Test case setup function
  -> _teardown: Test case teardown function
*/
typedef struct UTestRunner
{
    // pass/fail counters
    int _pass;
    int _fail;
    int _error;
    int _skip;
    int _total;

    // setup/teardown functions
    void (*_setup)();
    void (*_teardown)();

} UTestRunner; // end struct

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.
//   
UTestRunner *tril_xtest_create_runner(void);
int tril_xtest_end_runner(UTestRunner *runner);
void tril_xtest_setup(UTestRunner *runner, void (*func)());
void tril_xtest_teardown(UTestRunner *runner, void (*func)());
void tril_xtest_run(UTestRunner *runner, void (*test)());

#ifdef __cplusplus
}
#endif

#endif
