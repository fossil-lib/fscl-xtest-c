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
  >
  > This stub returns a given value from the tester as
  > the value, if the value is nullptr it will just return
  > 0 as its default value.
  >

  usage:
  >
  > tril_xmock_stub_integer(42);
  >
  args:
  -> value: The value being passed by the stub
*/
int tril_xmock_stub_integer(int value)
{
    if (!value)
    {
        return 0;
    } // end if

    return value;
} // end of func

/*
  overview:
  >
  > This stub returns a given value from the tester as
  > the value, if the value is nullptr it will just return
  > an empty string like so -> "" as its default value.
  >

  usage:
  >
  > tril_xmock_stub_string("Coco beans");
  >
  args:
  -> value: The value being passed by the stub
*/
const char *tril_xmock_stub_string(const char *value)
{
    if (!value)
    {
        return "";
    } // end if

    return value;
} // end of func

/*
  overview:
  >
  > This stub returns nothing, its for simulating an
  > algorithem which can be handy for benchmarking.
  > If we get a zero we just return out of the function.
  >

  usage:
  >
  > tril_xmock_stub_loop(7); // loops 7 times
  >
  args:
  -> iter: The times to iter in the loop
*/
void tril_xmock_stub_loop(int iter)
{
    if (iter == 0)
    {
        return;
    } // end if

    for (size_t it = 0; it < iter; it++)
    {
        /* mock algorithm code */
    } // end for

} // end of func

/*
  overview:
  >
  > This stub returns a fixed value of null as the main
  > value.
  >

  usage:
  >
  > tril_xmock_stub_nullptr();
  >
  args:
  -> ...: N/A
*/
void *tril_xmock_stub_nullptr(void)
{
    return NULL;
} // end of func
