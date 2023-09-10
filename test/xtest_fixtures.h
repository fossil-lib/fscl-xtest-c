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
#include "trilobite/xexpect.h"

#include <stdint.h>

void xmockup_test_group(XUnitRunner *runner);
void unit_test_c_group(XUnitRunner *runner);
void unit_test_cpp_group(XUnitRunner *runner);
void xignore_test_group(XUnitRunner *runner);
void xexpect_test_group(XUnitRunner *runner);
void xassert_test_group(XUnitRunner *runner);

#ifdef __cplusplus
}
#endif

#endif
