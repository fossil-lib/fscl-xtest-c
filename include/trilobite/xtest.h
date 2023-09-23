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
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cmath>
#include <ctime>
#else
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#endif
   
/**
 * @brief Structure representing a test case.
 *
 * This structure encapsulates information about a test case, including its name, test function,
 * whether it's ignored, whether it's a benchmark, and the elapsed time (for benchmarks).
 */
typedef struct {
    const char* name;         // Name of the test case
    void (*test_function)(void);  // Function pointer to the test case's implementation
    bool ignored;             // Indicates if the test case is ignored
    bool is_benchmark;        // Flag to identify benchmark tests
    clock_t elapsed_time;     // Elapsed time for benchmark tests
} XTestCase;

/**
 * @brief Structure representing a test fixture.
 *
 * This structure defines a test fixture, which includes setup and teardown functions that
 * can be associated with test cases.
 */
typedef struct {
    void (*setup)(void);     // Setup function for the fixture
    void (*teardown)(void);  // Teardown function for the fixture
} XTestFixture;

/**
 * @brief Structure to hold test statistics.
 *
 * This structure stores various statistics related to test execution, such as the number of
 * passed, failed, ignored tests, the number of expected outcomes, and the number of assertions.
 */
typedef struct {
    int passed_count;     // Number of passed tests
    int failed_count;     // Number of failed tests
    int ignored_count;    // Number of ignored tests
    int total_count;      // Total number of tests
} XTestStats;

/**
 * @brief Structure to group test-related data.
 *
 * This structure is used to group test statistics within an XUnit test runner.
 */
typedef struct {
    XTestStats stats;  // Test statistics including passed, failed, and ignored counts
} XUnitRunner;

/**
 * @brief Structure representing a command-line option for a CLI or application.
 *
 * This structure is used to define and organize information about a command-line option,
 * including its long name (e.g., "--verbose"), short name (e.g., "-v"), a description for
 * usage instructions, and a pointer to a flag that stores the option's value or status.
 */
typedef struct {
    const char* option_long_name;  // Long name of the option (e.g., "--verbose")
    const char* option_short_name; // Short name of the option (e.g., "-v")
    const char* description;       // Description of the option for usage instructions
    bool* flag;                     // Pointer to a flag storing the option's value/status
} XTestCliOption;

/**
 * @brief Define a data structure for a group of test data.
 *
 * This macro is used to define a data structure associated with a specific group or category of test data.
 * It typically allows you to organize and encapsulate test data relevant to a particular set of test cases
 * or scenarios.
 *
 * @param group_name  The name of the group for which the data structure is defined.
 * @typedef           Define a typedef for the data structure with the given group name.
 * @struct            Start defining the data structure.
 */
#define XTEST_DATA(group_name) typedef struct group_name##_xdata group_name##_xdata; struct group_name##_xdata

/**
 * @brief Define a simple test case without a fixture.
 *
 * This macro is used to define a test case along with its associated test function.
 *
 * @param name  The name of the test case.
 */
#define XTEST_CASE(name) \
    void name##_xtest(void); \
    XTestCase name = { #name, name##_xtest, false, false, 0 }; \
    void name##_xtest(void)

/**
 * @brief Define a benchmark test without a fixture.
 *
 * This macro is used to define a benchmark test along with its associated test function.
 *
 * @param name  The name of the benchmark test.
 */
#define XTEST_BENCH(name) \
    void name##_xtest(void); \
    XTestCase name = { #name, name##_xtest, false, true, 0 }; \
    void name##_xtest(void)

/**
 * @brief Define a test fixture with setup and teardown functions.
 *
 * This macro is used to define a test fixture along with its associated setup and teardown functions.
 *
 * @param fixture_name  The name of the test fixture.
 */
#define XTEST_FIXTURE(fixture_name) \
    void setup_##fixture_name(void); \
    void teardown_##fixture_name(void); \
    XTestFixture fixture_name = { setup_##fixture_name, teardown_##fixture_name };

/**
 * @brief Define a setup function for a test fixture.
 *
 * This macro is used to define a setup function for a specific test fixture identified by 'fixture_name'.
 * The setup function is responsible for preparing the test environment and resources before each test case
 * within the fixture is executed.
 *
 * @param fixture_name The name of the test fixture for which the setup function is defined.
 */
#define XTEST_SETUP(fixture_name) void setup_##fixture_name(void)

/**
 * @brief Define a teardown function for a test fixture.
 *
 * This macro is used to define a teardown function for a specific test fixture identified by 'fixture_name'.
 * The teardown function is responsible for cleaning up resources and restoring the test environment after each
 * test case within the fixture has been executed.
 *
 * @param fixture_name The name of the test fixture for which the teardown function is defined.
 */
#define XTEST_TEARDOWN(fixture_name) void teardown_##fixture_name(void)

/**
 * @brief Define a test case that uses a fixture.
 *
 * This macro is used to define a test case that relies on a specific fixture. It associates the test case
 * with the fixture's setup and teardown functions.
 *
 * @param fixture_name  The name of the fixture to use.
 * @param test_case     The name of the test case.
 */
#define XTEST_CASE_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    XTestCase test_case = { #test_case, test_case##_xtest_##fixture_name, false, false, 0 }; \
    void test_case##_xtest_##fixture_name(void)

/**
 * @brief Define a benchmark test that uses a fixture.
 *
 * This macro is used to define a benchmark test that relies on a specific fixture. It associates the benchmark
 * test with the fixture's setup and teardown functions.
 *
 * @param fixture_name  The name of the fixture to use.
 * @param test_case     The name of the benchmark test.
 */
#define XTEST_BENCH_FIXTURE(fixture_name, test_case) \
    void test_case##_xtest_##fixture_name(void); \
    XTestCase test_case = { #test_case, test_case##_xtest_##fixture_name, false, true, 0 }; \
    void test_case##_xtest_##fixture_name(void)

//
// Helper function to run a test case
//

/**
 * @brief Initializes an XUnitRunner and processes command-line arguments.
 *
 * This function initializes an XUnitRunner, processes command-line arguments to handle custom options,
 * and displays version information or usage instructions if requested.
 *
 * @param argc  Number of command-line arguments.
 * @param argv  Array of command-line argument strings.
 *
 * @return      An initialized XUnitRunner structure.
 */
XTEST_API XUnitRunner xtest_start(int argc, char **argv);

/**
 * @brief Finalizes the execution of a Trilobite XUnit runner and displays test results.
 *
 * This function prints the test results, including the number of tests passed, failed, ignored,
 * and the total count. It also returns the count of failed tests.
 *
 * @param runner    Pointer to the Trilobite XUnit runner containing test statistics.
 *
 * @return          The count of failed tests.
 */
XTEST_API int xtest_end(XUnitRunner *runner);

/**
 * @brief Runs a unit test case and updates test statistics.
 *
 * This function executes a unit test case, records the execution time, and updates the
 * test statistics based on the test result.
 *
 * @param test_case   Pointer to the unit test case to be executed.
 * @param stats       Structure containing test statistics.
 *
 * @return            None.
 */
XTEST_API void xtest_run_test_unit(XTestCase* test_case, XTestStats* stats);

/**
 * @brief Runs a test case within a test fixture and updates test statistics.
 *
 * This function executes a test case within a given test fixture, records the execution time,
 * and updates the test statistics based on the test result.
 *
 * @param test_case   Pointer to the test case to be executed.
 * @param fixture     Pointer to the test fixture containing setup and teardown functions.
 * @param stats       Pointer to the structure containing test statistics.
 *
 * @return            None.
 */
XTEST_API void xtest_run_test_fixture(XTestCase* test_case, XTestFixture* fixture, XTestStats* stats);

//
// ------------------------------------------------------------------------
//
// List of handy assert types from the XUnit Test framewrok
//
// ------------------------------------------------------------------------
//
// XEXPECT: expectation function with optional message.
// XASSERT: assertion function with optional message.
// XIGNORE: ignored with a specified reason and prints it to stderr
//
// ------------------------------------------------------------------------
//

/**
 * @brief Marks a test case as ignored with a specified reason and prints it to stderr.
 *
 * This function is used to indicate that a test case should be ignored and provides a reason
 * for the omission. It prints the specified reason to the standard error stream (stderr).
 *
 * @param reason  The reason for ignoring the test case.
 */
XTEST_API void xignore(const char* reason, const char* file, int line, const char* func);

/**
 * @brief Custom assertion function with optional message.
 *
 * This function allows custom assertions and displays a message if the assertion fails.
 * It also provides an option to disable further assertion scanning after the first failure.
 *
 * @param expression  The expression to be asserted (should evaluate to true for success).
 * @param message     An optional message to be displayed when the assertion fails.
 *
 * @return            None.
 */
XTEST_API void xassert(bool expression, const char *message, const char* file, int line, const char* func);

/**
 * @brief Custom expectation function with optional message.
 *
 * This function allows custom expectations and displays a message if the expectation fails.
 * It also provides an option to disable further expectation scanning after the first failure.
 *
 * @param expression  The expression to be expected (should evaluate to true for success).
 * @param message     An optional message to be displayed when the expectation fails.
 *
 * @return            None.
 */
XTEST_API void xexpect(bool expression, const char *message, const char* file, int line, const char* func);

/**
 * @brief Adds an assertion to the current test case.
 *
 * @param expression  The expression to evaluate.
 * @param message     The message to display if the assertion fails.
 *
 * @return            If the expression evaluates to false, the assertion fails, and the message is displayed.
 *                    Otherwise, the assertion passes, and nothing happens.
 */
#define XASSERT(expression, message) xassert(expression, message, __FILE__, __LINE__, __func__)

/**
 * @brief Adds an expectation to the current test case.
 *
 * @param expression  The expression to evaluate.
 * @param message     The message to display if the expectation fails.
 *
 * @return            If the expression evaluates to false, the expectation fails, and the message is displayed.
 *                    Otherwise, the expectation passes, and nothing happens.
 */
#define XEXPECT(expression, message) xexpect(expression, message, __FILE__, __LINE__, __func__)

/**
 * @brief Asserts whether a test passes or fails.
 *
 * @param message  A message to be displayed if the test fails.
 *
 * @return         This macro calls XASSERT(false, message), indicating a test failure with the provided message.
 */
#define XTEST_FAIL(message) \
    do { \
        XASSERT(false, message); \
    } while (false)

/**
 * @brief Defines a test that passes.
 *
 * @return  This macro calls XASSERT(true, "Test passed"), indicating a successful test.
 */
#define XTEST_PASS() \
    do { \
        XASSERT(true, "Test passed"); \
    } while (false)

/**
 * @brief Indicates that a test is not yet implemented.
 *
 * @return  This macro calls XASSERT(false, "Test not implemented yet"), indicating that the test is incomplete.
 *          A message is printed to stderr to indicate that the test is not yet implemented.
 */
#define XTEST_NOT_IMPLEMENTED() \
    do { \
        XASSERT(false, "Test not implemented yet") \
    } while (false)

/**
 * @brief Marks the current test case as ignored with a given reason and returns early.
 *
 * This macro is used to indicate that the current test case should be ignored with a provided reason.
 * It calls the `xignore` function with the specified reason and then returns from the current test case
 * immediately.
 *
 * @param reason  The reason for ignoring the test case.
 */
#define XTEST_IGNORE(reason) \
    do { \
        xignore(reason, __FILE__, __LINE__, __func__); \
        return; \
    } while (false)

/**
 * @brief Macros for defining a Behavior-Driven Development (BDD) structure with descriptions.
 *
 * These macros provide a way to structure and describe different phases (Given, When, Then) of a
 * test scenario in a BDD-style format. However, they don't have functional behavior by themselves
 * and are used for descriptive purposes.
 */
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

#ifdef __cplusplus
}
#endif

#endif
