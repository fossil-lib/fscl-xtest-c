# Trilobite XUnit test framework

## overview

* * *

Trilobite Xtest - A Lightweight Unit Testing Framework with Mocking and Benchmarking for C

Trilobite Xtest is a compact yet feature-rich unit testing framework specially crafted for C programming. Built with simplicity and efficiency in mind, Trilobite Xtest empowers developers to write and execute unit tests effortlessly, ensuring the accuracy and reliability of their C codebase. This versatile framework goes beyond traditional unit testing by incorporating advanced capabilities for mocking and benchmarking, making it an indispensable tool for comprehensive testing and performance analysis.

Trilobite Xtest is a valuable companion for C developers seeking a streamlined and powerful unit testing framework. With its support for mocking and benchmarking, developers can effectively evaluate the correctness, maintainability, and performance of their C codebase, fostering a robust and resilient software development process.

## tooling

* * *

The targeted audience we are building for is *Windows 10*, *MacOSX*, *ChromeOS*
and *Linux* users. This project uses [Meson](https://mesonbuild.com/) `1.0.0`
and newer, uses `c11` standards for the initial implementation of the package. The
objective by far is usability, security, transparency, and lightweight, packages
for all your application development needs.

## Setup, Compile and Install

* * *

Using this package should be fairly simple just add the git wrap file
in your subprojects directory and include the dependency in your project.

```console
[wrap-git]
directory = trilo-xtest-c
url = https://github.com/trilobite-stdlib/trilo-xtest-c.git
revision = main

[provide]
trilo-xtest-c = trilo_xtest_c_dep
```

The next step should be to add the package to your Meson project:

```meson
trilo_dep = dependency('trilo-xtest-c')

executable('prog', 'main.c',
    dependencies : [trilo_dep])

```

And finally, we set up, and compile the project just like normal.

## usage

* * *

Here is a simple sample application that should get you up and
running with using this library as soon as possible but to learn
more please view the API documentation thanks.

### Usage in C

**source file:**:

```c
XTEST(custom_assert_check)
{
    TRILXASSERT(true);
} // end of case

//
// XTEST FIXTURE
//
void xtest_fixture_basic_cases(XTestRunner *runner)
{
    //
    // setup and teardown methods get set here
    // before any of the listed test cases are
    // run.
    tril_xtest_setup(runner, setup);
    tril_xtest_teardown(runner, teardown);

    //
    // list of test cases for the current test fixture
    //
    tril_xtest_run(runner, xtest_custom_assert_check);
} // end of fixture
```

**header file:**

```c
#ifndef TRILOBITE_XTEST_FIXTURE_H
#define TRILOBITE_XTEST_FIXTURE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xtest.h"

void xtest_fixture_basic_cases(XTestRunner *runner);

#ifdef __cplusplus
}
#endif

#endif
```

**main file:**

```c
/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include <stdlib.h>
#include "my_fixtures.h"

//
// main is where all good examples start
//
int main(void)
{
    //
    // setup and teardown can be set to nullptr.
    XTestRunner *runner = tril_xtest_create_runner();

    xtest_fixture_basic_cases(runner);

    return tril_xtest_end_runner(runner);
} // end of function main

```

## contact

If you want to contact me and have a few questions
regarding the solutions in the programming you can
find a method on my [website](https://trilobite.code.blog/contact/).
