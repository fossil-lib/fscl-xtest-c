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
#ifndef FSCL_XTEST_H
#define FSCL_XTEST_H

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
#include <stdint.h>
#include <time.h>
#if defined(_WIN32)
#include <Windows.h>
#endif
#endif

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <wctype.h>
#include <wchar.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

// Used in floating-point asserts
#define XTEST_FLOAT_EPSILON 1e-6
#define XTEST_DOUBLE_EPSILON 1e-9

// Structure to hold timing information for tests
typedef struct {
    clock_t elapsed;  // Elapsed time for all tests
    clock_t start;    // Elapsed time for the start of tests
    clock_t end;      // Elapsed time for the end of tests
} xtime;

// Configuration settings for a test case
typedef struct {
    bool ignored;    // Indicates if the test case is ignored
    bool is_mark;    // Flag to identify benchmark tests
    bool is_fish;    // Flag to identify Fish AI tests
} xconfig;

// Fixture information with setup and teardown functions
typedef struct {
    void (*setup)(void);     // Setup function for the fixture
    void (*teardown)(void);  // Teardown function for the fixture
} xfixture;

// Structure representing a test case
typedef struct {
    const char* name;            // Name of the test case
    void (*test_function)(void); // Function pointer to the test case's implementation
    xfixture fixture;            // The fixture settings
    xconfig config;              // Configuration
    xtime timer;                 // Xtest timer for tracking time
} xtest;

// Statistics for tracking test results
typedef struct {
    uint16_t passed_count;   // Number of passed tests
    uint16_t failed_count;   // Number of failed tests
    uint16_t ignored_count;  // Number of ignored tests
    uint16_t error_count;    // Number of error tests
    uint16_t mark_count;     // Number of benchmark tests
    uint16_t fish_count;     // Number of Fish AI tests
    uint16_t test_count;     // Number of tests
    uint16_t total_count;    // Total number of tests
} xstats;

// Engine structure to hold overall test statistics and timing information
typedef struct {
    xstats stats;  // Test statistics including passed, failed, and ignored counts
    xtime timer;   // Xtest timer for tracking time
} xengine;

// =================================================================
// Initial implementation
// =================================================================

// Function prototypes for Xtest
// Creates an instance of the testing engine and initializes it with command-line arguments.
xengine xtest_create(int argc, char **argv);

// Erases (cleans up) the instance of the testing engine.
// Returns an integer indicating the result of the operation.
int xtest_erase(xengine *runner);

// Runs a test case as a standalone test within the testing engine.
void xtest_run_as_test(xengine* engine, xtest* test_case);

// Runs a test case with a specified fixture within the testing engine.
void xtest_run_as_fixture(xengine* engine, xtest* test_case, xfixture* fixture);

// Function prototypes for Xmark
// Marks the start of a performance benchmark.
void xmark_start_benchmark(void);

// Marks the end of a performance benchmark and returns the elapsed time in nanoseconds.
uint64_t xmark_stop_benchmark(void);

// Asserts that the elapsed time in nanoseconds does not exceed a specified maximum in seconds.
void xmark_assert_seconds(uint64_t elapsed_time_ns, double max_seconds);

// Asserts that the elapsed time in nanoseconds does not exceed a specified maximum in minutes.
void xmark_assert_minutes(uint64_t elapsed_time_ns, double max_minutes);

// Expects that the elapsed time in nanoseconds does not exceed a specified maximum in seconds.
void xmark_expect_seconds(uint64_t elapsed_time_ns, double max_seconds);

// Expects that the elapsed time in nanoseconds does not exceed a specified maximum in minutes.
void xmark_expect_minutes(uint64_t elapsed_time_ns, double max_minutes);

// Function prototypes for asserts
// Logs information about an error condition in a test.
void xerrors(const char* reason, const char* file, int line, const char* func);

// Logs a message indicating that a test is being ignored, providing a reason.
void xignore(const char* reason, const char* file, int line, const char* func);

// Asserts a boolean expression in a test, failing the test if the expression is false.
void xassert(bool expression, const char *message, const char* file, int line, const char* func);

// Expects a boolean expression in a test, failing the test if the expression is false.
void xexpect(bool expression, const char *message, const char* file, int line, const char* func);

// =================================================================
// XTest create and erase commands
// =================================================================

// Macro to create an instance of the testing engine with specified command line arguments.
// Usage: XTEST_CREATE(argc, argv);
//        // Run tests or perform other testing operations using the 'runner' instance.
//        // ...
//        // Erase the 'runner' instance when done with testing.
//        XTEST_ERASE();
#define XTEST_CREATE(argc, argv) xengine runner = xtest_create(argc, argv)

// Macro to erase (clean up) the instance of the testing engine.
// Usage: XTEST_ERASE();
#define XTEST_ERASE() xtest_erase(&runner)


// =================================================================
// XTest run commands
// =================================================================

// Macro to run a standalone test case.
// Usage: XTEST_RUN_UNIT(test_case);
#define XTEST_RUN_UNIT(test_case) xtest_run_as_test(runner, &test_case)

// Macro to run a test case with a fixture.
// Usage: XTEST_RUN_FIXTURE(test_case, fixture);
#define XTEST_RUN_FIXTURE(test_case, fixture) xtest_run_as_fixture(runner, &test_case, &fixture)

// Macro to define a test case with a fixture.
// Usage: XTEST_CASE_FIXTURE(fixture_name, test_case) {
//          // Define and implement the test case
//        }
#define XTEST_CASE_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, {NULL, NULL}, {false, false, false}, {0, 0, 0}}; \
    void test_case##_xtest_##fixture_name(void)

// Macro to define a marked (excluded) test case with a fixture.
// Usage: XTEST_MARK_FIXTURE(fixture_name, test_case) {
//          // Define and implement the test case
//        }
#define XTEST_MARK_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, {NULL, NULL}, {false, true, false}, {0, 0, 0}}; \
    void test_case##_xtest_##fixture_name(void)

// Macro to define a focused (exclusive) test case with a fixture.
// Usage: XTEST_FISH_FIXTURE(fixture_name, test_case) {
//          // Define and implement the test case
//        }
#define XTEST_FISH_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, {NULL, NULL}, {false, false, true}, {0, 0, 0}}; \
    void test_case##_xtest_##fixture_name(void)

// Macro to define a fixture.
// Usage: XTEST_FIXTURE(fixture_name) {
//          // Define setup and teardown functions for the fixture
//        }
#define XTEST_FIXTURE(fixture_name) \
    void setup_##fixture_name(void); \
    void teardown_##fixture_name(void); \
    xfixture fixture_name = { setup_##fixture_name, teardown_##fixture_name };

// Macro to define the setup function for a fixture.
// Usage: XTEST_SETUP(fixture_name) {
//          // Define the setup function for the fixture
//        }
#define XTEST_SETUP(fixture_name) void setup_##fixture_name(void)

// Macro to define the teardown function for a fixture.
// Usage: XTEST_TEARDOWN(fixture_name) {
//          // Define the teardown function for the fixture
//        }
#define XTEST_TEARDOWN(fixture_name) void teardown_##fixture_name(void)

// =================================================================
// Test pool commands
// =================================================================

// Macro to define a test pool function with a specified group name.
// Usage: XTEST_DEFINE_POOL(group_name) {
//          // Define test cases within this pool
//        }
#define XTEST_DEFINE_POOL(group_name) void group_name(xengine *runner)

// Macro to declare a test pool function with a specified group name.
// Usage: XTEST_EXTERN_POOL(group_name);
#define XTEST_EXTERN_POOL(group_name) extern void group_name(xengine *runner)

// Macro to import a test pool by invoking its function with a given runner instance.
// Usage: XTEST_IMPORT_POOL(group_name);
#define XTEST_IMPORT_POOL(group_name) group_name(&runner)


// =================================================================
// Implement test commands
// =================================================================

// Macro to define a basic test case.
// Usage: XTEST_CASE(test_name) {
//          // Test case implementation
//        }
#define XTEST_CASE(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, {NULL, NULL}, {false, false, false}, {0, 0, 0}}; \
    void name##_xtest(void)

// Macro to define a test case and mark it for exclusion from the test suite.
// Usage: XTEST_MARK(test_name) {
//          // Test case implementation
//        }
#define XTEST_MARK(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, {NULL, NULL}, {false, true, false}, {0, 0, 0}}; \
    void name##_xtest(void)

// Macro to define a test case with a focus on specific functionality.
// Usage: XTEST_FISH(test_name) {
//          // Test case implementation
//        }
#define XTEST_FISH(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, {NULL, NULL}, {false, false, true}, {0, 0, 0}}; \
    void name##_xtest(void)

// =================================================================
// BDD specific commands
// =================================================================

// Macro to describe a pre-condition or initial state in a behavior-driven development (BDD) test.
// Usage: GIVEN("some context or condition") {
//           // Code representing the given state or context
//        }
#define GIVEN(description) \
    if (0) { \
        printf("Given %s\n", description); \
    } else

// Macro to describe an action or event in a BDD test.
// Usage: WHEN("some action or event occurs") {
//           // Code representing the action or event
//        }
#define WHEN(description) \
    if (0) { \
        printf("When %s\n", description); \
    } else

// Macro to describe an expected outcome or result in a BDD test.
// Usage: THEN("some expected outcome or result") {
//           // Code representing the expected outcome or result verification
//        }
#define THEN(description) \
    if (0) { \
        printf("Then %s\n", description); \
    } else

// =================================================================
// XMark specific commands for benchmarking
// =================================================================

// Macro to initiate the start of a performance benchmark.
// This macro is used to mark the beginning of the code section to be benchmarked.
#define XMARK_START_BENCHMARK() xmark_start_benchmark()

// Macro to signal the end of a performance benchmark.
// Use this macro to mark the conclusion of the code section under benchmark.
#define XMARK_STOP_BENCHMARK() xmark_stop_benchmark()

// Macro to assert that the elapsed time, given in nanoseconds, does not exceed a specified maximum time in seconds.
// It is intended for use in test scenarios where a strict upper limit on execution time is crucial.
#define XMARK_ASSERT_SECONDS(elapsed_time_ns, max_seconds) xmark_assert_seconds(elapsed_time_ns, max_seconds)

// Macro to assert that the elapsed time, given in nanoseconds, does not exceed a specified maximum time in minutes.
// Similar to XMARK_ASSERT_SECONDS but with the time limit specified in minutes.
#define XMARK_ASSERT_MINUTES(elapsed_time_ns, max_minutes) xmark_assert_minutes(elapsed_time_ns, max_minutes)

// Macro to set an expectation that the elapsed time should not exceed a specified maximum time in seconds.
// It is used for expressing a non-strict upper limit on the execution time in test scenarios.
#define XMARK_EXPECT_SECONDS(elapsed_time_ns, max_seconds) xmark_expect_seconds(elapsed_time_ns, max_seconds)

// Macro to set an expectation that the elapsed time should not exceed a specified maximum time in minutes.
// Similar to XMARK_EXPECT_SECONDS but with the time limit specified in minutes.
#define XMARK_EXPECT_MINUTES(elapsed_time_ns, max_minutes) xmark_expect_minutes(elapsed_time_ns, max_minutes)

// ------------------------------------------------------------------------
//
// List of handy assert types from the XUnit Test framework
//
// ------------------------------------------------------------------------
//
// TEST_EXPECT: Expectation function with an optional message.
//              Use it to express a non-critical expectation in tests.
//
// TEST_ASSERT: Assertion function with an optional message.
//              Use it to validate critical conditions in tests. Fails the test if the condition is false.
//
// TEST_ASSUME: Smart assertion function with an optional message.
//              Similar to TEST_ASSERT but allows test execution to continue even if the condition fails.
//
// TEST_IGNORE: Ignored test with a specified reason, printed to stderr.
//              Use it for temporarily skipping tests without affecting test results.
//
// TEST_XERROR: Information about an error condition in a test.
//              Marks the test as failed and provides a reason.
//
// ------------------------------------------------------------------------

// Macro to assert a given expression in a test. If the expression is false, the test fails.
// Usage: TEST_ASSERT(expression, message);
#define TEST_ASSERT(expression, message) xassert(expression, message, __FILE__, __LINE__, __func__)

// Macro to expect a given expression in a test. If the expression is false, the test fails,
// and the test execution continues.
// Usage: TEST_EXPECT(expression, message);
#define TEST_EXPECT(expression, message) xexpect(expression, message, __FILE__, __LINE__, __func__)

// Macro to ignore a test with a specified reason.
// Usage: TEST_IGNORE(reason);
#define TEST_IGNORE(reason) xignore(reason, __FILE__, __LINE__, __func__)

// Macro to handle an error condition in a test. It marks the test as failed and provides a reason.
// Usage: TEST_XERROR(reason);
#define TEST_XERROR(reason) xerrors(reason, __FILE__, __LINE__, __func__)

// =================================================================
// XTest utility commands
// =================================================================

// Macro to define test data structure for a specific group of tests.
// Usage: XTEST_DATA(group_name) {
//          // Define the structure of test data for the group
//        };
#define XTEST_DATA(group_name) typedef struct group_name##_xdata group_name##_xdata; struct group_name##_xdata

// Macro to indicate test failure with a specified message.
// Usage: XTEST_FAIL(message);
#define XTEST_FAIL(message) TEST_ASSERT(false, message);

// Macro to indicate test success.
// Usage: XTEST_PASS();
#define XTEST_PASS() TEST_ASSERT(true, "Test passed");

// Macro to output a note during test execution.
// Usage: XTEST_NOTE(comment);
#define XTEST_NOTE(comment) fprintf(stderr, "XTEST NOTE: %s\n", comment);

// Macro to indicate that a test is not yet implemented.
// Usage: XTEST_NOT_IMPLEMENTED();
#define XTEST_NOT_IMPLEMENTED() TEST_ASSERT(false, "Test not implemented yet")

#ifdef __cplusplus
}
#endif

#endif
