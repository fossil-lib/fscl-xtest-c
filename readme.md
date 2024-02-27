# Fossil Logic XTest - `C`

Unleash the power of Fossil XTest to transcend the ordinary and make your foray into the realm of unparalleled software testing sophistication. This cutting-edge testing library isn't just a mere tool; it's a paradigm shift in how you approach quality assurance. Elevate your coding endeavors by integrating advanced testing methodologies that surpass the industry's benchmarks.

Within the intricate tapestry of software development, Fossil XTest stands as a stalwart guardian, offering an expansive array of testing solutions that leave no stone unturned. From meticulously crafted unit tests to the all-encompassing embrace of end-to-end testing, Fossil XTest redefines what it means to have a comprehensive testing suite. It's not merely about checking boxes; it's about orchestrating a symphony of tests that harmonize seamlessly with your codebase.

Fossil XTest seamlessly integrates into the very fabric of your development process, becoming an intrinsic component rather than a mere add-on. Witness a paradigm shift where testing is not an isolated phase but an ongoing narrative woven into every line of code. This integration doesn't just streamline workflows; it catalyzes a cultural shift where testing becomes synonymous with excellence.

Confidence in the reliability and functionality of your applications is no longer a distant goal but a tangible reality with Fossil XTest. This testing powerhouse empowers you to deliver software that not only meets expectations but transcends them, creating a legacy of performance and dependability.

Don't just adhere to industry standards; surpass them with Fossil XTest. This library sets new benchmarks for excellence, redefining what it means to achieve the pinnacle of software testing. Make verbose strides in your testing endeavors – Fossil XTest is not just a tool; it's your gateway to a future where every line of code resonates with quality and precision. Elevate, exceed, and make verbose with Fossil XTest!

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

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
