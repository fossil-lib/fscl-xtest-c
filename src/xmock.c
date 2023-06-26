/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xmock.h"
#include <stdlib.h>


/*
  overview:
  > Should return a large integer value, the value
  > of 100
  >
  args:
  -> ...: N/A
*/
int tril_xmock_stub_large_int(void)
{
    return 100;
} // end of func


/*
  overview:
  > Should return a medium integer value, the value
  > of 50
  >
  args:
  -> ...: N/A
*/
int tril_xmock_stub_medium_int(void)
{
    return 50;
} // end of func


/*
  overview:
  > Should return a small integer value, the value
  > of 5
  >
  args:
  -> ...: N/A
*/
int tril_xmock_stub_small_int(void)
{
    return 5;
} // end of func


/*
  overview:
  > Should return a zero integer value
  >
  args:
  -> ...: N/A
*/
int tril_xmock_stub_zero_int(void)
{
    return 0;
} // end of func


/*
  overview:
  > Should return a long string value
  >
  args:
  -> ...: N/A
*/
char *tril_xmock_stub_long_str(void)
{
    return "Some kind of long message for testing";
} // end of func


/*
  overview:
  > Should return a medium string value
  >
  args:
  -> ...: N/A
*/
char *tril_xmock_stub_medium_str(void)
{
    return "Some cool message to test";
} // end of func


/*
  overview:
  > Should return a short string value
  >
  args:
  -> ...: N/A
*/
char *tril_xmock_stub_short_str(void)
{
    return "Just a message";
} // end of func


/*
  overview:
  > Should return a empty string value
  >
  args:
  -> ...: N/A
*/
char *tril_xmock_stub_empty_str(void)
{
    return "";
} // end of func


/*
  overview:
  > Should return a null value or use where
  > null value is used
  >
  args:
  -> ...: N/A
*/
void *tril_xmock_stub_nullptr(void)
{
    return NULL;
} // end of func
