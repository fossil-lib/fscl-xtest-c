source = files('xtest.c')

lib = library('trilo-xtest-c',
    source,
    include_directories: inc_dir)

trilo_xtest_c_dep = declare_dependency(link_with: trilo_lib,
    include_directories: inc_dir)
