/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include <trilobite/xtest.h>   // basic test tools
#include <iostream>

//
// XTEST DATA
//
XTEST_DATA(SomeData) {
    int some_data;
    const char* some_other_data;
}my_data;

//
// XTEST FIXTURE
//
XTEST_FIXTURE(basic_fixture);
XTEST_SETUP(basic_fixture) {
     std::cout << "Setting up the test fixture" << std::endl; // Perform setup operations here
 } // end of setup

 XTEST_TEARDOWN(basic_fixture) {
     std::cout << "Tearing down the test fixture\n" << std::endl; // Perform teardown operations here
} // end of teardown

//
// XUNIT TESTS
//
XTEST_CASE_FIXTURE(basic_fixture, passing_case) {
    XTEST_PASS(); // This test will always pass.
} // end of case

XTEST_CASE_FIXTURE(basic_fixture, failing_case) {
    XTEST_FAIL("This test intentionally fails"); // This test will always fail.
} // end of case

//
// XTEST RUNNER
//
int main(int argc, char** argv) {
    XUnitRunner runner = xtest_start(argc, argv);

    xtest_run_test_fixture(&passing_case, &basic_fixture, &runner.stats);
    xtest_run_test_fixture(&failing_case, &basic_fixture, &runner.stats);

    return xtest_end(&runner);
} // end of function main
