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
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <ctime>
#else
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#endif

typedef struct {
    const char* name;         // Name of the test case
    void (*test_function)(void);  // Function pointer to the test case's implementation
    bool ignored;             // Indicates if the test case is ignored
    bool is_mark;             // Flag to identify benchmark tests
    bool is_fish;             // Flag to identify FishAI tests
    clock_t elapsed_time;     // Elapsed time for benchmark tests
} xtest;

typedef struct {
    void (*setup)(void);     // Setup function for the fixture
    void (*teardown)(void);  // Teardown function for the fixture
} xfixture;

typedef struct {
    uint16_t passed_count;     // Number of passed tests
    uint16_t failed_count;     // Number of failed tests
    uint16_t ignored_count;    // Number of ignored tests
    uint16_t error_count;      // Number of ignored tests
    uint16_t total_count;      // Total number of tests
} xstats;

typedef struct {
    xstats stats;  // Test statistics including passed, failed, and ignored counts
} xengine;


// =================================================================
// Initial implementation
// =================================================================
xengine xtest_start(int argc, char **argv);
int xtest_end(xengine *runner);

void xtest_run_test_unit(xtest* test_case, xstats* stats);
void xtest_run_test_fixture(xtest* test_case, xfixture* fixture, xstats* stats);

void xerrors(const char* reason, const char* file, int line, const char* func);
void xignore(const char* reason, const char* file, int line, const char* func);
void xassert(bool expression, const char *message, const char* file, int line, const char* func);
void xexpect(bool expression, const char *message, const char* file, int line, const char* func);

// =================================================================
// XTest create and erase commands
// =================================================================
#define XTEST_CREATE(argc, argv) xengine runner = xtest_start(argc, argv)
#define XTEST_ERASE() xtest_end(&runner)

// =================================================================
// XTest run commands
// =================================================================
#define XTEST_RUN_UNIT(test_case) xtest_run_test_unit(&test_case, &runner->stats)
#define XTEST_RUN_FIXTURE(test_case, fixture) xtest_run_test_fixture(&test_case, &fixture, &runner->stats)

#define XTEST_CASE_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, false, false, false, 0 }; \
    void test_case##_xtest_##fixture_name(void)

#define XTEST_MARK_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, false, true, false, 0 }; \
    void test_case##_xtest_##fixture_name(void)

#define XTEST_FISH_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, false, false, true, 0 }; \
    void test_case##_xtest_##fixture_name(void)

#define XTEST_FIXTURE(fixture_name) \
    void setup_##fixture_name(void); \
    void teardown_##fixture_name(void); \
    xfixture fixture_name = { setup_##fixture_name, teardown_##fixture_name };

#define XTEST_SETUP(fixture_name) void setup_##fixture_name(void)
#define XTEST_TEARDOWN(fixture_name) void teardown_##fixture_name(void)

// =================================================================
// Test pool commands
// =================================================================
#define XTEST_DEFINE_POOL(group_name) void group_name(xengine *runner)
#define XTEST_EXTERN_POOL(group_name) extern void group_name(xengine *runner)
#define XTEST_IMPORT_POOL(group_name) group_name(&runner)

// =================================================================
// Implement test commands
// =================================================================
#define XTEST_CASE(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, false, false, false, 0 }; \
    void name##_xtest(void)

#define XTEST_MARK(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, false, true, false, 0 }; \
    void name##_xtest(void)

#define XTEST_FISH(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, false, false, true, 0 }; \
    void name##_xtest(void)

// =================================================================
// BDD specific commands
// =================================================================
#define GIVEN(description) \
    if (0) { \
        printf("Given %s\n", description); \
    } else

#define WHEN(description) \
    if (0) { \
        printf("When %s\n", description); \
    } else

#define THEN(description) \
    if (0) { \
        printf("Then %s\n", description); \
    } else

//
// ------------------------------------------------------------------------
//
// List of handy assert types from the XUnit Test framewrok
//
// ------------------------------------------------------------------------
//
// TEST_EXPECT: expectation function with optional message.
// TEST_ASSERT: assertion function with optional message.
// TEST_IGNORE: ignored with a specified reason and prints it to stderr
// TEST_XERROR: information about an error condition
// ------------------------------------------------------------------------
//

#define TEST_ASSERT(expression, message) xassert(expression, message, __FILE__, __LINE__, __func__)
#define TEST_EXPECT(expression, message) xexpect(expression, message, __FILE__, __LINE__, __func__)
#define TEST_IGNORE(reason) xignore(reason, __FILE__, __LINE__, __func__)
#define TEST_XERROR(reason) xerrors(reason, __FILE__, __LINE__, __func__)

// =================================================================
// XTest utility commands
// =================================================================
#define XTEST_DATA(group_name) typedef struct group_name##_xdata group_name##_xdata; struct group_name##_xdata

#define XTEST_FAIL(message) \
    do { \
        TEST_ASSERT(false, message); \
    } while (false)

#define XTEST_PASS() \
    do { \
        TEST_ASSERT(true, "Test passed"); \
    } while (false)

#define XTEST_NOTE(comment) do { \
    fprintf(stderr, "XTEST NOTE: %s\n", comment); \
} while(0)

#define XTEST_NOT_IMPLEMENTED() \
    do { \
        TEST_ASSERT(false, "Test not implemented yet") \
    } while (false)


#ifdef __cplusplus
}
#endif

#endif