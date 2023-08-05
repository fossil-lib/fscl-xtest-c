/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xassert.h"
#include <stdio.h>
#include <stdlib.h>

extern int TRIL_XTEST_FLAG_RESULT;
extern int TRIL_XTEST_FLAG_SKIP;

/*
  overview:
  >
  > This function is used to check if an expression is true,
  > and if not, it will call the "tril_xassert()" function
  > with the expression, filename, line number and function
  > name as parameters.
  >
  > It also sets a flag that can be used to skip the assertion.
  >
  usage:
  >
  > int val = 5;
  >
  > tril_xassert(val == 5);
  >
  args:
  -> expresson: The expresson being asserted for a test case
  -> file: path value to the file
  -> line: line number the assert was ran on
  -> func: the function name
*/
void _tril_xassert(int expresson, const char *file, int line, const char * func)
{
    if (!expresson)
    {
        TRIL_XTEST_FLAG_RESULT = 1;
        fprintf(stderr, "Assert failed at %s:%d in function %s(...)", file, line, func);
        exit(EXIT_FAILURE);
    } // end if
    
} // end of func