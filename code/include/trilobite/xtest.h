/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.code.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_XTEST_H
#define TRILOBITE_XTEST_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <ctime>
#else
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
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
    uint16_t passed_count;     // Number of passed tests
    uint16_t failed_count;     // Number of failed tests
    uint16_t ignored_count;    // Number of ignored tests
    uint16_t total_count;      // Total number of tests
} XTestStats;

/**
 * @brief Structure to group test-related data.
 *
 * This structure is used to group test statistics within an XUnit test runner.
 */
typedef struct {
    XTestStats stats;  // Test statistics including passed, failed, and ignored counts
    bool dry_run;
} XUnitRunner;

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
XUnitRunner xtest_start(int argc, char **argv);

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
int xtest_end(XUnitRunner *runner);

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
void xtest_run_test_unit(XTestCase* test_case, XTestStats* stats);

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
void xtest_run_test_fixture(XTestCase* test_case, XTestFixture* fixture, XTestStats* stats);

/**
 * @brief Define a test group function.
 *
 * This macro is used to define a test group function.
 *
 * @param group_name The name of the test group function.
 * @param runner The XUnitRunner instance for the test group function is available in each unique test group function.
 */
#define XTEST_GROUP_DEFINE(group_name) \
    void group_name(XUnitRunner *runner) \

/**
 * @brief Declare a test group function as extern.
 *
 * This macro is used to declare a test group function as extern,
 * allowing it to be used in other files without including a header.
 *
 * @param group_name The name of the test group function.
 */
#define XTEST_GROUP_EXTERN(group_name) \
    extern void group_name(XUnitRunner *runner) \

/**
 * @brief Register a test group function with a specific runner.
 *
 * This macro is used to register a test group function with a specific runner.
 *
 * @param group_name The name of the test group function.
 * @param runner The XUnitRunner instance for the test group function.
 */
#define XTEST_GROUP_REGISTER(group_name, runner) \
    group_name(&runner) \

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
#define XTEST_RUNNER_START(argc, argv) xtest_start(argc, argv)

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
#define XTEST_RUNNER_END(runner) xtest_end(&runner)

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
#define XTEST_RUN_UNIT(test_case, runner) xtest_run_test_unit(&test_case, &runner->stats)

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
#define XTEST_RUN_FIXTURE(test_case, fixture, runner) xtest_run_test_fixture(&test_case, &fixture, &runner->stats)

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
void xignore(const char* reason, const char* file, int line, const char* func);

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
void xassert(bool expression, const char *message, const char* file, int line, const char* func);

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
void xexpect(bool expression, const char *message, const char* file, int line, const char* func);

/**
 * @brief Adds an assertion to the current test case.
 *
 * @param expression  The expression to evaluate.
 * @param message     The message to display if the assertion fails.
 *
 * @return            If the expression evaluates to false, the assertion fails, and the message is displayed.
 *                    Otherwise, the assertion passes, and nothing happens.
 */
#define TEST_ASSERT(expression, message) xassert(expression, message, __FILE__, __LINE__, __func__)

/**
 * @brief Adds an expectation to the current test case.
 *
 * @param expression  The expression to evaluate.
 * @param message     The message to display if the expectation fails.
 *
 * @return            If the expression evaluates to false, the expectation fails, and the message is displayed.
 *                    Otherwise, the expectation passes, and nothing happens.
 */
#define TEST_EXPECT(expression, message) xexpect(expression, message, __FILE__, __LINE__, __func__)

/**
 * @brief Asserts whether a test passes or fails.
 *
 * @param message  A message to be displayed if the test fails.
 *
 * @return         This macro calls TEST_ASSERT(false, message), indicating a test failure with the provided message.
 */
#define XTEST_FAIL(message) \
    do { \
        TEST_ASSERT(false, message); \
    } while (false)

/**
 * @brief Defines a test that passes.
 *
 * @return  This macro calls TEST_ASSERT(true, "Test passed"), indicating a successful test.
 */
#define XTEST_PASS() \
    do { \
        TEST_ASSERT(true, "Test passed"); \
    } while (false)

/**
 * @brief A macro for adding comments or notes to the code.
 *
 * This macro allows developers to insert comments or notes directly into the code
 * for debugging, documentation, or explanatory purposes. It prints the provided
 * comment text with a "XTEST NOTE:" prefix to the standard error stream (stderr).
 *
 * Example usage:
 *   XTEST_NOTE("This is a custom note for debugging.");
 *
 * @param comment The comment or note text to be added to the code.
 */
#define XTEST_NOTE(comment) do { \
    fprintf(stderr, "XTEST NOTE: %s\n", comment); \
} while(0)

/**
 * @brief Indicates that a test is not yet implemented.
 *
 * @return  This macro calls TEST_ASSERT(false, "Test not implemented yet"), indicating that the test is incomplete.
 *          A message is printed to stderr to indicate that the test is not yet implemented.
 */
#define XTEST_NOT_IMPLEMENTED() \
    do { \
        TEST_ASSERT(false, "Test not implemented yet") \
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
