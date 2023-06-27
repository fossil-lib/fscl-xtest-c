/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xbench.h"
#include <stdio.h>
#include <time.h>

clock_t timer;

/*
  overview:
  >
  > This starts the timer for a benchmark which at this point
  > keeps track of the time value in the "clock()" function until
  > the "tril_xbench_end()" is called which will end the timer.
  >

  usage:
  >
  > tri_xbench_start(); // sets the timer var to the value in "clock()"
  >
  > ... before tri_xbench_end() ...
  >
  args:
  -> ...: N/A
*/
void tril_xbench_start(void)
{
    timer = clock();
} // end of func

/*
  overview:
  >
  > This ends the timer and computes the elapsed of a running process
  > then outputs that in standard output as seconds elapsed when the
  > function was called to perform a task.
  >

  usage:
  >
  > ... after tri_xbench_start() ...
  >
  > tri_xbench_end(); // process time elapsed into seconds
  >
  args:
  -> ...: N/A
*/
void tril_xbench_end(void)
{
    double elapsed = (double)(clock() - timer) / CLOCKS_PER_SEC;
    printf(" ->\n -> Done in %f seconds\n ->\n", elapsed);
} // end of func
