/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_XTEST_IMPL_H
#define FSCL_XTEST_IMPL_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
#include <cstdint>
#include <ctime>
#if defined(_WIN32)
#include <Windows.h>
#endif
#else
// Use _GNU_SOURCE to enable POSIX features and additional GNU extensions
#define _GNU_SOURCE
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#if defined(_WIN32)
#include <Windows.h>
#endif
#endif

#ifdef __cplusplus
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <cwctype>
#include <cwchar>
#include <cctype>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#else
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <wctype.h>
#include <wchar.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#endif

// Used in floating point asserts
#define XTEST_FLOAT_EPSILON 1e-6
#define XTEST_DOUBLE_EPSILON 1e-9

typedef struct {
    clock_t elapsed;     // Elapsed time for all tests
    clock_t start;       // Elapsed time for start of tests
    clock_t end;         // Elapsed time for end of tests
} xtime;

typedef struct {
    bool ignored;             // Indicates if the test case is ignored
    bool is_mark;             // Flag to identify benchmark tests
    bool is_fish;             // Flag to identify Fish AI tests
} xconfig;

typedef struct {
    void (*setup)(void);     // Setup function for the fixture
    void (*teardown)(void);  // Teardown function for the fixture
} xfixture;

typedef struct {
    const char* name;            // Name of the test case
    void (*test_function)(void); // Function pointer to the test case's implementation
    xfixture fixture;            // The fixture settings
    xconfig config;              // Configuration
    xtime timer;                 // Xtest timer for tracking time
} xtest;

typedef struct {
    uint16_t passed_count;     // Number of passed tests
    uint16_t failed_count;     // Number of failed tests
    uint16_t ignored_count;    // Number of ignored tests
    uint16_t error_count;      // Number of error tests
    uint16_t mark_count;      // Number of benchmarks tests
    uint16_t fish_count;      // Number of fish AI tests
    uint16_t test_count;      // Number of fish AI tests
    uint16_t total_count;      // Total number of tests
} xstats;

typedef struct {
    xstats stats;  // Test statistics including passed, failed, and ignored counts
    xtime timer;   // Xtest timer for tracking time
} xengine;

// =================================================================
// Initial implementation
// =================================================================

// Function prototypes for Xtest
xengine xtest_create(int argc, char **argv);
int xtest_erase(xengine *runner);
void xtest_run_as_test(xengine* engine, xtest* test_case);
void xtest_run_as_fixture(xengine* engine, xtest* test_case, xfixture* fixture);

// Function prototypes for Xmark
void xmark_start_benchmark(void);
uint64_t xmark_stop_benchmark(void);
void xmark_assert_seconds(uint64_t elapsed_time_ns, double max_seconds);
void xmark_assert_minutes(uint64_t elapsed_time_ns, double max_minutes);
void xmark_expect_seconds(uint64_t elapsed_time_ns, double max_seconds);
void xmark_expect_minutes(uint64_t elapsed_time_ns, double max_minutes);

// Function prototypes for asserts
void xerrors(const char* reason, const char* file, int line, const char* func);
void xignore(const char* reason, const char* file, int line, const char* func);
void xassert(bool expression, const char *message, const char* file, int line, const char* func);
void xexpect(bool expression, const char *message, const char* file, int line, const char* func);

#ifdef __cplusplus
}
#endif

#endif