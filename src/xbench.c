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
  > This function "tril_xbench_run()" takes a void pointer
  > to a function as an argument and returns the elapsed
  > time in seconds for that function. It is used to measure
  > the performance of a function by timing how long it takes
  > to execute.
  >
  args:
  -> func: the pointer function being benchmarked
*/
double tril_xbench_run(void (*func)(void))
{
    clock_t start_time, end_time;
    double elapsed_time;

    start_time = clock();
    func();
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return elapsed_time;
} // end of func

/*
  overview:
  >
  > This function prints the execution time for a given function 
  > function_name to the console. The execution time is passed in
  > as elapsed_time.
  >
  args:
  -> function_name: function name tag
  -> elapsed_time: the elapsed time
*/
void tril_xbench_out(const char* function_name, double elapsed_time)
{
    printf("Execution time for %s: %f seconds\n", function_name, elapsed_time);
} // end of func
