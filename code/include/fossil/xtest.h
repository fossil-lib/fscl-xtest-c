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

#include "xtest/internal.h"

// =================================================================
// XTest create and erase commands
// =================================================================
#define XTEST_CREATE(argc, argv) xengine runner = xtest_create(argc, argv)
#define XTEST_ERASE() xtest_erase(&runner)

// =================================================================
// XTest run commands
// =================================================================
#define XTEST_RUN_UNIT(test_case) xtest_run_as_test(runner, &test_case)
#define XTEST_RUN_FIXTURE(test_case, fixture) xtest_run_as_fixture(runner, &test_case, &fixture)

#define XTEST_CASE_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, {NULL, NULL}, {false, false, false}, {0, 0, 0}}; \
    void test_case##_xtest_##fixture_name(void)

#define XTEST_MARK_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, {NULL, NULL}, {false, true, false}, {0, 0, 0}}; \
    void test_case##_xtest_##fixture_name(void)

#define XTEST_FISH_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    xtest test_case = { #test_case, test_case##_xtest_##fixture_name, {NULL, NULL}, {false, false, true}, {0, 0, 0}}; \
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
    xtest name = { #name, name##_xtest, {NULL, NULL}, {false, false, false}, {0, 0, 0}}; \
    void name##_xtest(void)

#define XTEST_MARK(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, {NULL, NULL}, {false, true, false}, {0, 0, 0}}; \
    void name##_xtest(void)

#define XTEST_FISH(name) \
    void name##_xtest(void); \
    xtest name = { #name, name##_xtest, {NULL, NULL}, {false, false, true}, {0, 0, 0}}; \
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

// =================================================================
// XMark specific commands for benchmarking
// =================================================================

#define XMARK_START_BENCHMARK() xmark_start_benchmark()
#define XMARK_STOP_BENCHMARK() xmark_stop_benchmark()
#define XMARK_ASSERT_SECONDS(elapsed_time_ns, max_seconds) xmark_assert_seconds(elapsed_time_ns, max_seconds)
#define XMARK_ASSERT_MINUTES(elapsed_time_ns, max_minutes) xmark_assert_minutes(elapsed_time_ns, max_minutes)
#define XMARK_EXPECT_SECONDS(elapsed_time_ns, max_seconds) xmark_expect_seconds(elapsed_time_ns, max_seconds)
#define XMARK_EXPECT_MINUTES(elapsed_time_ns, max_minutes) xmark_expect_minutes(elapsed_time_ns, max_minutes)

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
#define XTEST_FAIL(message) TEST_ASSERT(false, message);
#define XTEST_PASS() TEST_ASSERT(true, "Test passed");
#define XTEST_NOTE(comment) fprintf(stderr, "XTEST NOTE: %s\n", comment);
#define XTEST_NOT_IMPLEMENTED() TEST_ASSERT(false, "Test not implemented yet")


#ifdef __cplusplus
}
#endif

#endif
