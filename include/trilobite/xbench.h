/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XBENCH_H
#define TRILOBITE_XBENCH_H

#ifdef __cplusplus
extern "C"
{
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published library with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting both c11 and c23 standards.
//

// Function to run a benchmark and calculate execution time
double tril_xbench_run(void (*func)(void));
void tril_xbench_out(const char* function_name, double elapsed_time);

#define XBENCH(name)                           \
   void xbench_##name();                       \
   void run_##name()                          \
   {                                          \
      printf("Running bench: %s\n", __func__); \
   }                                          \
   void xbench_##name()


#ifdef __cplusplus
}
#endif

#endif
