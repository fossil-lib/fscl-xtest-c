/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XTEST_FIXTURE_H
#define TRILOBITE_XTEST_FIXTURE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xtest.h"

void xtest_fixture_basic_cases(XTestRunner *runner);
void xtest_fixture_mocking_cases(XTestRunner *runner);
void xtest_fixture_benchmark_cases(XTestRunner *runner);

#ifdef __cplusplus
}
#endif

#endif
