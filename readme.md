# **Xunit test framework**

Trilobite XUnit Test Framework is a powerful and versatile testing framework designed for C and C++ developers. It offers a comprehensive suite of testing tools and features to ensure the quality and reliability of your codebase. Whether you’re developing in C11, C23, C++17, or C++23, Trilobite has you covered.

Refer to the documentation and examples to quickly get started with Trilobite and begin testing your C and C++ projects effectively.

Trilobite XUnit Test Framework empowers developers to write reliable, high-quality code by providing a rich set of testing and evaluation tools. Whether you’re working on C, C++, D or Rust projects, Trilobites help you deliver robust software. Start testing with Trilobite XUnit today!

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
XTEST_FIXTURE(basic_fixture);
XTEST_SETUP(basic_fixture) {
     printf("Setting up the test fixture\n"); // Perform setup operations here
 }

 XTEST_TEARDOWN(basic_fixture) {
     printf("Tearing down the test fixture\n"); // Perform teardown operations here
}

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

    xtest_run_test_fixture(&passing_case, &basic_fixture, &runner->stats);
    xtest_run_test_fixture(&failing_case, &basic_fixture, &runner->stats);

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
