/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
extern crate trilobite;
use trilobite::xtest::*;

//
// XTEST DATA
//
#[derive(Default)]
struct SomeData {
    some_data: i32,
    some_other_data: *const i8,
} // end of test data

lazy_static::lazy_static! {
    static ref MY_DATA: SomeData = SomeData {
        some_data: 0,
        some_other_data: std::ptr::null(),
    };
}

//
// XTEST FIXTURE
//
struct BasicFixture;

impl XTestSetup for BasicFixture {
    fn setup(&mut self) {
        println!("Setting up the test fixture");
        // Perform setup operations here
    }
} // end of setup

impl XTestTeardown for BasicFixture {
    fn teardown(&mut self) {
        println!("Tearing down the test fixture");
        // Perform teardown operations here
    }
}

//
// XUNIT TESTS
//
#[test]
fn passing_case() {
    XTEST_PASS(); // This test will always pass.
}

#[test]
fn failing_case() {
    XTEST_FAIL("This test intentionally fails"); // This test will always fail.
}

//
// XTEST RUNNER
//
fn main() {
    let mut runner = XUnitRunner::new();

    runner.run_test_fixture::<BasicFixture>();
    runner.stats.print_results();
}
