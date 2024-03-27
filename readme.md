# Fossil Logic XTest - `C`

XTest is a cutting-edge test library developed by Fossil Logic, designed to streamline and enhance the testing process for modern software development. Combining the power of rich assertion capabilities, behavior-driven development (BDD), test-driven development (TDD), and a command-line interface (CLI), XDream empowers developers to achieve unparalleled efficiency and reliability in their testing workflows. Xtest streamlines the testing process, enabling faster feedback cycles and accelerated development workflows. The intuitive CLI interface makes it easy for developers to interact with the test framework, facilitating seamless integration into existing development environments.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up, Compiling, Installing, and Running the Project

**Adding Dependency**:

Create a directory named subprojects in the root directory, next create a file named `fscl-xtest-c.wrap` in the `subprojects` directory of your project with the following content:

   ```ini
   [wrap-git]
   url = https://github.com/fossil-lib/fscl-xtest-c.git
   revision = main
   
   [provide]
   fscl-xtest-c = fscl_xtest_c_dep
   ```

**Integrate Dependency**:
   ```meson
   project('my_project', 'c')

   exe = executable('my_project', 'my_project.c',
       dependencies : dependency('fscl-xtest-c')) # add this line

   test('basic', exe)
   ```

## Including the Demo and Running Tests

To run tests, you can use the following options when configuring the build:

- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```zsh
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

If you're interested in contributing to this project, encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue or visit the [Fossil Logic Docs](https://fossillogic.com/the-docs) for more information.
