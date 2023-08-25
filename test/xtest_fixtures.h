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
#include "trilobite/xassert.h"

void xfixture_basic_cases(XUnitRunner *runner);
void xfixture_mocking_cases(XUnitRunner *runner);
void xfixture_bench_cases(XUnitRunner *runner);

#ifdef __cplusplus
}
#endif

#endif