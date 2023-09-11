source = files('xtest.c', 'hive.c')

lib = library('trilo-xtest-c',
    source,
    include_directories: dir)

trilo_xtest_c_dep = declare_dependency(link_with: lib,
    include_directories: dir)
