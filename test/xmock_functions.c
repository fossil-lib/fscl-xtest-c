/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"
#include <stdio.h> // for printf and file reading

//
// MOCK FUNCTIONS
//
// Example mocked functions
XMOCK_FUNC(int, get_value) {
    return 42;
}

XMOCK_FUNC(float, calculate_average, int x, int y) {
    return (float)(x + y) / 2;
}

XMOCK_FUNC(void, log_message, const char* message, int level) {
    printf("Log: %s (Level: %d)\n", message, level);
}

// Define the mocked 'min' and 'max' functions
XMOCK_FUNC(int, min_int, int a, int b) {
    return (a < b) ? a : b;
}

XMOCK_FUNC(int, max_int, int a, int b) {
    return (a > b) ? a : b;
}

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_func_fixture);

XTEST_SETUP(xmockup_func_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xmockup_func_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_get_value) {
    int result = xmock_get_value();
    XASSERT_INT_EQUAL(42, result);
}

XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_calculate_average) {
    float result = xmock_calculate_average(10, 20);
    XASSERT_FLOAT_WITHIN(0.01f, 15.0f, result);
}

// Additional test cases
XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_get_value_negative) {
    int result = xmock_get_value();
    XASSERT_INT_NOT_EQUAL(0, result);
}

XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_calculate_average_large_numbers) {
    float result = xmock_calculate_average(1000, 2000);
    XASSERT_FLOAT_WITHIN(0.01f, 1500.0f, result);
}

XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_log_message) {
    // Redirect stdout to capture the output
    freopen("log.txt", "w", stdout);
    
    // Invoke the mocked log_message function
    xmock_log_message("Test log message", 3);

    // Restore stdout
    freopen("/dev/tty", "w", stdout);

    // Read the log file and verify the logged message
    FILE* logFile = fopen("log.txt", "r");
    char buffer[100];
    fgets(buffer, sizeof(buffer), logFile);
    XASSERT_STRING_EQUAL("Log: Test log message (Level: 3)\n", buffer);

    fclose(logFile);
}

XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_min_int) {
    int result = xmock_min_int(5, 10);
    XASSERT_INT_EQUAL(5, result); // Expected minimum is 5

    result = xmock_min_int(10, 5);
    XASSERT_INT_EQUAL(5, result); // Expected minimum is 5
}

// Test case for 'max' function
XTEST_CASE_FIXTURE(xmockup_func_fixture, xmock_func_max_int) {
    int result = xmock_max_int(5, 10);
    XASSERT_INT_EQUAL(10, result); // Expected maximum is 10

    result = xmock_max_int(10, 5);
    XASSERT_INT_EQUAL(10, result); // Expected maximum is 10
}

//
// XTEST FIXTURE
//
void xmockup_test_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xmock_func_calculate_average,               &xmockup_func_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_func_calculate_average_large_numbers, &xmockup_func_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_func_get_value,                       &xmockup_func_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_func_get_value_negative,              &xmockup_func_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_func_log_message,                     &xmockup_func_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_func_min_int,                         &xmockup_func_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_func_max_int,                         &xmockup_func_fixture, &runner->stats);
} // end of fixture
