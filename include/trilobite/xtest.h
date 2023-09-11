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

// Define platform-specific macros for desktop platforms

// Windows (32-bit and 64-bit)
#ifdef _WIN32
#define XIGNORE_ON_WINDOWS
#endif

// Linux (Various distributions)
#ifdef __linux__
#define XIGNORE_ON_LINUX
#endif

// macOS (Apple Macintosh)
#ifdef __APPLE__
#define XIGNORE_ON_MACOS
#endif

// FreeBSD (Unix-like OS)
#ifdef __FreeBSD__
#define XIGNORE_ON_FREEBSD
#endif

// OpenBSD (Secure Unix-like OS)
#ifdef __OpenBSD__
#define XIGNORE_ON_OPENBSD
#endif

// NetBSD (Unix-like OS)
#ifdef __NetBSD__
#define XIGNORE_ON_NETBSD
#endif

// Solaris (Unix-based OS)
#ifdef __sun
#define XIGNORE_ON_SOLARIS
#endif

// AIX (IBM's Unix OS)
#ifdef _AIX
#define XIGNORE_ON_AIX
#endif

// HP-UX (Hewlett-Packard Unix)
#ifdef __hpux
#define XIGNORE_ON_HPUX
#endif

// Haiku (Open-source OS inspired by BeOS)
#ifdef __HAIKU__
#define XIGNORE_ON_HAIKU
#endif

// ReactOS (Open-source Windows-compatible OS)
#ifdef __REACTOS__
#define XIGNORE_ON_REACTOS
#endif

// Plan 9 (Distributed OS by Bell Labs)
#ifdef __plan9__
#define XIGNORE_ON_PLAN9
#endif

// Custom desktop OS
#ifdef __CUSTOM_DESKTOP_OS__
#define XIGNORE_ON_CUSTOM_DESKTOP
#endif

// Define platform-specific macros for mobile platforms

// Android
#ifdef __ANDROID__
#define XIGNORE_ON_ANDROID
#endif

// iOS (iPhone, iPad, iPod Touch)
#ifdef __APPLE__
#define XIGNORE_ON_IOS
#endif

// Windows Phone
#ifdef _WIN32
#define XIGNORE_ON_WINDOWS_PHONE
#endif

// BlackBerry
#ifdef __QNX__
#define XIGNORE_ON_BLACKBERRY
#endif

// Tizen
#ifdef __TIZEN__
#define XIGNORE_ON_TIZEN
#endif

// Firefox OS
#ifdef __B2G__
#define XIGNORE_ON_FIREFOX_OS
#endif

// Sailfish OS
#ifdef __SAILFISH__
#define XIGNORE_ON_SAILFISH
#endif

// Ubuntu Touch
#ifdef __UBUNTU_TOUCH__
#define XIGNORE_ON_UBUNTU_TOUCH
#endif

// KaiOS
#ifdef __KAIOS__
#define XIGNORE_ON_KAIOS
#endif

// HarmonyOS (Huawei)
#ifdef __HARMONYOS__
#define XIGNORE_ON_HARMONYOS
#endif

// Custom embedded OS (e.g., feature phone)
#ifdef __CUSTOM_EMBEDDED_OS__
#define XIGNORE_ON_CUSTOM_EMBEDDED
#endif

// Define platform-specific macros for embedded platforms

// ARM Cortex-M series
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define XIGNORE_ON_CORTEX_M
#endif

// PIC microcontrollers
#if defined(__PIC16__) || defined(__PIC18__) || defined(__PIC32__)
#define XIGNORE_ON_PIC
#endif

// Atmel AVR microcontrollers
#if defined(__AVR__)
#define XIGNORE_ON_AVR
#endif

// Texas Instruments MSP430 series
#if defined(__MSP430__)
#define XIGNORE_ON_MSP430
#endif

// STM32 microcontrollers from STMicroelectronics
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F2)
#define XIGNORE_ON_STM32
#endif

// Nordic Semiconductor nRF series
#if defined(NRF51) || defined(NRF52)
#define XIGNORE_ON_NRF
#endif

// ESP8266 and ESP32
#if defined(ESP8266) || defined(ESP32)
#define XIGNORE_ON_ESP
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
#include <setjmp.h>
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
// XERRORS: throw error function with optional message.
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
XTEST_API void xignore(const char* reason);

/**
 * @brief Report Error and Raise Exception
 *
 * The `xerrors` function is used to report an error in the program and raise an exception.
 *
 * @param expression The expression or context in which the error occurred.
 * @param exception_type The type of exception to raise (e.g., "RuntimeError").
 * @param exception_message The message associated with the exception.
 *
 * This function is typically used when a critical error condition is encountered that
 * should be reported, and the program's execution needs to be halted by raising an exception.
 * It can be used for debugging and error handling purposes.
 *
 * Example usage:
 *
 * ```c
 * xerrors("Division by zero", "RuntimeError", "Cannot divide by zero.");
 * ```
 *
 * @note This function is part of the XUnit testing framework.
 * @note The behavior of this function may vary depending on the specific testing framework
 *       or runtime environment in use.
 */
XTEST_API void xerrors(void (*expression)(const char*, const char*), const char* exception_type, const char* exception_message, const char *message);

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
XTEST_API void xassert(bool expression, const char *message);

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
XTEST_API void xexpect(bool expression, const char *message);

/**
 * @brief Throw an Exception with Custom Type and Message
 *
 * The `xerrors_throw` function is used to throw an exception with a custom type and message.
 *
 * @param type The type of the exception to throw (e.g., "RuntimeError").
 * @param message The message associated with the exception.
 *
 * This function is typically used to raise an exception with specific error information. It
 * allows for customizing the exception type and message when reporting an error or exceptional
 * condition in the program.
 *
 * Example usage:
 *
 * ```c
 * xerrors_throw("RuntimeError", "Custom error message.");
 * ```
 *
 * @note This function is part of the XUnit testing framework.
 * @note The behavior of this function may vary depending on the specific testing framework
 *       or runtime environment in use.
 */
XTEST_API void *xerrors_throw(const char* type, const char* message);

/**
 * @brief Adds an assertion to the current test case.
 *
 * @param expression  The expression to evaluate.
 * @param message     The message to display if the assertion fails.
 *
 * @return            If the expression evaluates to false, the assertion fails, and the message is displayed.
 *                    Otherwise, the assertion passes, and nothing happens.
 */
#define XASSERT(expression, message) xassert(expression, message)

/**
 * @brief Verify and Report an Exception Using a Macro
 *
 * The `XERRORS` macro is used to verify and report an exception in the context of testing
 * using the XUnit framework. It evaluates an expression, checks whether it raises an exception
 * of the specified type, and verifies the expected exception message.
 *
 * @param expression The expression to evaluate, which should raise an exception.
 * @param exception_type The expected type of the exception (e.g., "RuntimeError").
 * @param expected_message The expected message associated with the exception.
 *
 * This macro simplifies the process of testing whether a specific expression raises an exception
 * of the expected type and with the expected message during unit testing.
 *
 * Example usage:
 *
 * ```c
 * XERRORS(some_function(), "RuntimeError", "Expected error message.");
 * ```
 *
 * @note This macro is part of the XUnit testing framework.
 * @note The behavior of this macro may vary depending on the specific testing framework
 *       or runtime environment in use.
 */
#define XERRORS(expression, exception_type, expected_message, message) xerrors(expression, exception_type, expected_message, message)

/**
 * @brief Throw an Exception with Custom Type and Message Using a Macro
 *
 * The `XERRORS_THROW` macro is a convenient way to throw an exception with a custom type and message
 * using the `xerrors_throw` function.
 *
 * @param type The type of the exception to throw (e.g., "RuntimeError").
 * @param message The message associated with the exception.
 *
 * This macro simplifies the process of raising an exception with specific error information. It allows
 * for customizing the exception type and message when reporting an error or exceptional condition
 * in the program.
 *
 * Example usage:
 *
 * ```c
 * XERRORS_THROW("RuntimeError", "Custom error message.");
 * ```
 *
 * @note This macro is part of the XUnit testing framework.
 * @note The behavior of this macro may vary depending on the specific testing framework
 *       or runtime environment in use.
 */
#define XERRORS_THROW(type, message) xerrors_throw(type, message)

/**
 * @brief Adds an expectation to the current test case.
 *
 * @param expression  The expression to evaluate.
 * @param message     The message to display if the expectation fails.
 *
 * @return            If the expression evaluates to false, the expectation fails, and the message is displayed.
 *                    Otherwise, the expectation passes, and nothing happens.
 */
#define XEXPECT(expression, message) xexpect(expression, message)

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
        xignore(reason); \
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
