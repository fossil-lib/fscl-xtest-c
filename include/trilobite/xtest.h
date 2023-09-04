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

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#ifdef __cplusplus
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <cstdio>
#include <cmath>
#include <ctime>
#endif

/**
    @param XAssert A struct containing a message and a boolean
    @returns If the boolean is true, the code will reach the
             return statement. Otherwise, it will not.
*/
typedef struct {
    const char *message;
    bool passed;
} XAssert;


/**
    @param passed_count: the number of tests that have passed
    @param failed_count: the number of tests that have failed
    @param run_tag: a tag that identifies the test run
    @returns XUnitRunner: a struct that contains the test results
*/
typedef struct {
    int passed_count;
    int failed_count;
    char *run_tag;
    void (*setup_function)(void);
    void (*teardown_function)(void);
} XUnitRunner;

/**
    @param XBench - Structure containing the benchmark name, benchmark function, setup function, teardown function, and elapsed time.
    @returns The elapsed time of the benchmark.
*/
typedef struct {
    const char *name;
    void (*benchmark_function)(void);
    clock_t elapsed_time;
} XBench;

/**
    @brief This is the definition of an XTestCase structure.

    @param name: A pointer to a constant character string that holds the name of the test case.
    @param test_function: A pointer to a function that holds the actual test code.
    @param setup_function: A pointer to a function that is used to setup the test, usually used to initialize variables and resources that are needed for the test.
    @param teardown_function: A pointer to a function that is used to clean up after the test, usually used to free resources allocated during the setup_function.
    @param assertions: A pointer to an array of XAssert structures that hold the assertions used in the test.
    @param num_assertions: An integer that holds the number of assertions in the assertions array.

    @returns: The XTestCase structure that holds the information about the test case.
*/
#ifdef __cplusplus
class XTestCase {
public:
    XTestCase(const char *name, void (*test_function)(void) = nullptr, XAssert *assertions = nullptr, size_t num_assertions = 0)
        : name(name), test_function(test_function), assertions(assertions), num_assertions(num_assertions) {}
    const char *name;
    void (*test_function)(void);
    XAssert *assertions;
    size_t num_assertions;
}; // end class

#else
typedef struct {
    const char *name;
    void (*test_function)(void);
    XAssert *assertions;
    size_t num_assertions;
} XTestCase; // end struct
#endif

/**
    This code defines a test case for the framework with the given name.

    @param name: The name of the test case
    @returns: A XTestCase structure with the given name and the test function pointer
              set to the function with the same name as the given name.
*/
#ifdef __cplusplus
#define XTEST_CASE(name) \
    void name##_xtest(void); \
    XTestCase name(#name, name##_xtest);
    void name##_xtest(void)
#else
#define XTEST_CASE(name) \
    void name##_xtest(void); \
    XTestCase name = { #name, name##_xtest, NULL, 0 }; \
    void name##_xtest(void)
#endif

/**
    @brief This code defines a XBench structure which can be used to benchmark functions.

    @param name: The name of the function to be benchmarked
    @returns: The XBench structure with the function name, the benchmark function, and
              other necessary details for the benchmarking process.
*/
#ifdef __cplusplus
#define XBENCH(name) \
    void name##_xbench(void); \
    XBench name = { #name, name##_xbench, 0 }; \
    void name##_xbench(void)
#else

#endif

//
// Helper function to run a test case
//

XUnitRunner xtest_start(int argc, char **argv);
int xtest_end(XUnitRunner *runner);
void xtest_run(XTestCase *test_case, XUnitRunner *runner);
void xbench_run(XBench *benchmark, XUnitRunner *runner);
void xtest_set_setup_teardown(XUnitRunner *runner, void (*setup_func)(void), void (*teardown_func)(void));
void xassert(bool expression, const char *message);
void xexpect(bool expression, const char *message);

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
