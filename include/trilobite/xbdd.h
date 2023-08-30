/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XBDD_H
#define TRILOBITE_XBDD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

// Define macros for BDD structure
#define GIVEN(description) \
    do { \
        printf("Given %s\n", description); \
        static bool givenExecuted = true; \
        (void)givenExecuted; \
    } while (0)

#define WHEN(description) \
    do { \
        static bool whenExecuted = true; \
        if (!givenExecuted || whenExecuted) { \
            fprintf(stderr, "Error: Invalid use of WHEN\n"); \
        } else { \
            printf("When %s\n", description); \
            whenExecuted = true; \
        } \
    } while (0)

#define THEN(description) \
    do { \
        static bool thenExecuted = true; \
        if (!givenExecuted || !whenExecuted || thenExecuted) { \
            fprintf(stderr, "Error: Invalid use of THEN\n"); \
        } else { \
            printf("Then %s\n", description); \
            thenExecuted = true; \
        } \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif
