source = files('xtest.c', 'xmock.c', 'xhive.c')>>>>>>> main

lib = library('trilo-xtest-c',
    source,
    install : true,
    include_directories: dir)

trilo_xtest_c_dep = declare_dependency(link_with: lib,
    include_directories: dir)
