/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xassert.h"
#include <stdio.h>

extern int TRIL_XTEST_FLAG_RESULT;
extern int TRIL_XTEST_FLAG_ERROR;

/*
  overview:
  >
  > Should let you assert a general expresson for a test case
  > that test the functionality of a feature in a project.
  >
  > If an assert fails the rest of the assertions will skip
  > output else if nothing is output at all then everything
  > in a given test case has passed.
  >

  usage:
  >
  > int val = 5;
  >
  > tri_xtest_assert(val == 5, "Is val equal to magic number 5");
  >
  args:
  -> expresson: The expresson being asserted for a test case
  -> message: The message that will act as a note for the assert
*/
void tril_xtest_assert(int expresson, const char * message)
{
    // skips the output for asserts in a project
    if (TRIL_XTEST_FLAG_RESULT == 1)
    {
        return;
    } // end if

    if (!expresson)
    {
        puts("\t->\n\t-> general assert failed given expresson:");
        printf("\t-> '%s'\n\t->\n", message);
        TRIL_XTEST_FLAG_RESULT = 1;
    } // end if
    else
    {
        //puts("\t-> general assert passed given expresson:");
    } // end else

} // end of func

/*
  overview:
  >
  > Should let you assert an expected expresson for a test case
  > that test the functionality of a feature in a project.
  >
  > If an expected assert fails the rest of the expections will
  > resume like nothing happened but just like assert it will add
  > to the fail count
  >

  usage:
  >
  > int val = 40;
  >
  > tri_xtest_expect(val == 40, "Is val equal to 40");
  >
  args:
  -> expresson: The expresson being expected for a test case
  -> message: The message that will act as a note for the assert
*/
void tril_xtest_expect(int expresson, const char *message)
{
    if (!expresson)
    {
        puts("\t->\n\t-> expected assert failed given expresson:");
        printf("\t-> '%s'\n\t->\n", message);
        TRIL_XTEST_FLAG_RESULT = 1;
    } // end if
    else
    {
        //puts("\t-> expected assert passed given expresson:");
    } // end else

} // end of func
