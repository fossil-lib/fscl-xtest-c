from conan import ConanFile
from conan.tools.meson import Meson, MesonToolchain

class FsclXTestCConan(ConanFile):
    name = "Xtest"
    version = "1.1.2"
    license = "MPL-2.0"
    url = "https://github.com/fossil-lib/fscl-xtest-c"
    description = "Fossil XTest is your go-to library for robust and comprehensive testing solutions in C."
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    topics = ("meson", "mesonbuild", "fossillogic")
    author = "Fossil Logic"

    def generate(self):
        tc = MesonToolchain(self)
        tc.generate()

    def build(self):
        meson = Meson(self)
        meson.configure(source_folder="code", build_folder="builddir")
        meson.build()

    def package(self):
        self.copy("*.h", dst="include", src="code/include/fossil")
        self.copy("*.a", dst="lib", src="builddir")

    def package_info(self):
        self.cpp_info.libs = ["fscl-xtest-c"]
