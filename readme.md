# Xunit test framework

Introducing the Trilobite Xunit Test: a robust and versatile unit testing framework designed to elevate your software development process. Crafted with meticulous attention to detail, this lightweight testing solution, coded in C11 and newer standards, empowers developers with an arsenal of cutting-edge features.

The Trilobite Xunit Test stands out with its comprehensive approach, offering a wide array of testing types to ensure your software's quality and reliability. From UI and UX testing to enhance user experience, the framework covers it all. Its IO testing capabilities guarantee seamless data interaction.

One of the framework's standout features is its extensive collection of assertions, providing you with an abundance of options to validate your code's correctness. To facilitate isolation and control, Trilobite also incorporates a robust mocking system, allowing you to create controlled environments for testing intricate scenarios.

Benchmark testing becomes a breeze with the Trilobite Xunit Test, allowing you to measure performance with precision. The integration of a CLI interface ensures user-friendly execution of tests, and the colored text output provides clarity in result interpretation.

The Trilobite Xunit Test seamlessly integrates into your development process by leveraging the Meson build system. Its compatibility with the Meson WrapDB tool simplifies installation and keeps dependencies in check, enabling a seamless setup experience.

In essence, the Trilobite Xunit Test redefines unit testing for C developers, offering a comprehensive, lightweight, and adaptable framework that propels your software projects toward excellence.

## Intended Audience

This guide is aimed at developers of all levels who wish to utilize the Meson build system for their projects. It assumes a basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before you proceed, ensure you have the following prerequisites installed:

- **Meson Build System**: The project relies on the Meson build system. If you do not have Meson installed, please visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for instructions on how to install it.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions provided on the [Meson website](https://mesonbuild.com/Getting-meson.html) based on your operating system.

## Setup, Compile, Install, and Run the Project

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/trilobite-stdlib/trio-xtest-c
   cd trilobite-stdlib/trio-xtest-c
   ```

2. **Configure the Build**:
   ```bash
   meson setup builddir
   ```

3. **Compile the Project**:
   ```bash
   meson compile -C builddir
   ```

4. **Test the Project**:
   ```bash
   meson test -C builddir -v
   ```

5. **Install the Project**:
   ```bash
   meson install -C builddir
   ```

## Example

Example of the usage in C

```c
#include <trilobite/xtest.h>   // basic test tools

//
// XTEST DATA
//
XTEST_DATA(some_data) {
    int some_data;
    const char* some_other_data;
};

//
// XTEST FIXTURE
//
// Define a test fixture using XTEST_FIXTURE
XTEST_FIXTURE(basic_fixture);
XTEST_SETUP(basic_fixture) {
     // Perform setup operations here
     printf("Setting up the test fixture\n");
 }

 XTEST_TEARDOWN(basic_fixture) {
     // Perform teardown operations here
     printf("Tearing down the test fixture\n");
}

//
// XUNIT TESTS
//
XTEST_CASE_FIXTURE(basic_fixture, passing_case) {
    // This test will always pass.
    XTEST_PASS();
} // end of case

XTEST_CASE_FIXTURE(basic_fixture, failing_case) {
    // This test will always fail.
    XTEST_FAIL("This test intentionally fails");
} // end of case

//
// XTEST RUNNER
//
int main(int argc, char** argv) {
    XUnitRunner runner = xtest_start(argc, argv);

    // Register test cases with the fixture
    xtest_run_test_fixture(&passing_case, &basic_fixture, &runner->stats);
    xtest_run_test_fixture(&failing_case, &basic_fixture, &runner->stats);

    // Finalize the runner and print test results
    return xtest_end(&runner);
} // end of function main
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or raising issues on the [GitHub repository](https://github.com/trilobite-stdlib/trio-xtest-c) and be sure to read the docs on the owners' [website](https://trilobite.code.blog).

## Feedback and Support

If you come across any issues, have questions, or would like to provide feedback, feel free to open an issue on the [GitHub repository](https://github.com/trilobite-stdlib/trio-xtest-c/issues).

## License

This project is licensed under the [Apache License 2.0](LICENSE).

---

Thank you for choosing this project with the Meson build system. Enjoy coding and building great projects!

## contact

* * *

If you want to contact me and have a few questions
regarding the solutions in the programming you can
find a method on my [website](https://trilobite.code.blog/contact/).
