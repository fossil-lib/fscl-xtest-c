/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XTEST_H
#define TRILOBITE_XTEST_H

#ifdef __cplusplus
extern "C"
{
#endif

 // Define platform-specific macros
#ifdef _WIN32
    #define TRILOBITE_XTEST_EXPORT __declspec(dllexport)
    #define TRILOBITE_XTEST_IMPORT __declspec(dllimport)
#else
    #define TRILOBITE_XTEST_EXPORT __attribute__((visibility("default")))
    #define TRILOBITE_XTEST_IMPORT
#endif

// Define the MY_TEST_FRAMEWORK_API macro
#ifdef TRILOBITE_XTEST_SHARED
    #ifdef TRILOBITE_XTEST_BUILD
        #define XTEST_API TRILOBITE_XTEST_EXPORT
    #else
        #define XTEST_API TRILOBITE_XTEST_IMPORT
    #endif
#else
    #define XTEST_API
#endif
  
#ifdef __cplusplus
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <cstdio>
#include <cmath>
#include <ctime>

#else
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#endif

// Define a structure to represent a test case
typedef struct {
    const char* name;
    void (*test_function)(void);
    bool ignored;
    bool is_benchmark;     // New field for benchmark flag
    clock_t elapsed_time;  // New field for elapsed time
} XTestCase;

// Define a structure to represent a test fixture
typedef struct {
    void (*setup)(void);
    void (*teardown)(void);
} XTestFixture;

// Define a structure to hold test statistics
typedef struct {
    int passed_count;
    int failed_count;
    int ignored_count;
    int expected_count;
    int asserts_count;
    int total_count;
} XTestStats;

// Define an XUnitRunner structure to group test-related data
typedef struct {
    int argc;
    char** argv;
    XTestStats stats;
} XUnitRunner;


// Define XTEST_CASE macro for tests without fixtures
#define XTEST_CASE(name, expected, asserts) \
    void name##_xtest(void); \
    const XTestCase name = { #name, name##_xtest, false, false, 0 }; \
    void name##_xtest(void)

// Define XTEST_CASE_BENCH macro for benchmark tests without fixtures
#define XTEST_BENCH(name) \
    void name##_xtest(void); \
    const XTestCase name = { #name, name##_xtest, false, true, 0 }; \
    void name##_xtest(void)

// Define XTEST_FIXTURE macro for tests with fixtures
#define XTEST_FIXTURE(fixture_name) \
    void setup_##fixture_name(void); \
    void teardown_##fixture_name(void); \
    const XTestFixture fixture_name = { setup_##fixture_name, teardown_##fixture_name }; \
    void setup_##fixture_name(void) \
    void teardown_##fixture_name(void)

//
// Helper function to run a test case
//
XTEST_API XUnitRunner xtest_start(int argc, char **argv);
XTEST_API int xtest_end(XUnitRunner *runner);
XTEST_API void xtest_run_unit(const XTestCase* test_case, XTestStats* stats);
XTEST_API void xtest_run_fixture(const XTestCase* test_case, const XTestFixture* fixture, XTestStats* stats);

XTEST_API void xassert(bool expression, const char *message);
XTEST_API void xexpect(bool expression, const char *message);

/**
    @brief This macro adds an assertion to the current test case.

    @param expression: The expression to evaluate.
    @param message: The message to display if the assertion fails.

    @returns: If the expression evaluates to false, the assertion fails and
              the message is displayed. Otherwise, the assertion passes and
              nothing happens.
*/
#define XASSERT(expression, message) xassert(expression, message)

/**
    @brief This macro adds an expectation to the current test case.

    @param expression: The expression to evaluate.
    @param message: The message to display if the assertion fails.

    @returns: If the expression evaluates to false, the assertion fails and
              the message is displayed. Otherwise, the assertion passes and
              nothing happens.
*/
#define XEXPECT(expression, message) xexpect(expression, message)

/**
    @brief Asserts whether a test passes or fails

    @param boolean value - true if the test passed, false otherwise
    @param string message - a message to be displayed if the test fails

    @return void
*/
#define XTEST_FAIL(message) \
    do { \
        XASSERT(false, message); \
    } while (false)

/**
    @brief This macro defines a test that passes
    @param none
    @return void
*/
#define XTEST_PASS() \
    do { \
        XASSERT(true, "Test passed"); \
    } while (false)

/**
    This macro is used to indicate that a test is not yet implemented.

    @param none
    @return none
    @brief Prints out a message to stderr indicating that the test is not yet implemented.
*/
#define XTEST_NOT_IMPLEMENTED() \
    do { \
        XASSERT(false, "Test not implemented yet") \
    } while (false)

#ifdef __cplusplus
}
#endif

#endif
