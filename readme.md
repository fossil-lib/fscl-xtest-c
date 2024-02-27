# Fossil XTest - **C**

Fossil XTest is your go-to library for robust and comprehensive testing solutions. Elevate the quality of your software by incorporating advanced testing methodologies, ensuring that your code not only meets but exceeds industry standards. With Fossil XTest, testing becomes an integral part of your development process, providing confidence in the reliability and functionality of your applications.
## Who is This For?

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting up, Compiling, Installing, and Running the Project

**Fetch Wrap Dependency**:

   To fetch a wrap file from the Fossil WrapDB repositories for this package simply run this command:

   ```bash
meson wrap install --type git --source https://github.com/fossil-lib/fscl-xtest-c.git --subproject-dir upstream
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

```bash
meson setup builddir -Dwith_test=enabled
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or creating issues on the [GitHub repository](https://github.com/fossil-lib/fscl-xtest-c).

## Feedback and Support

If you encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue on the [GitHub repository](https://github.com/fossil-lib/fscl-xtest-c/issues).

## License

This project is licensed under the [Mozilla Public License](LICENSE).

---

Thank you for choosing this project with the Meson build system. Happy coding and building amazing projects!
