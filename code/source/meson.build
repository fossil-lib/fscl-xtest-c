lib_xtest = library('trilo-xtest-c',
    'xtest.c',
    install : true,
    include_directories: dir)

lib_xmock = library('trilo-xmock-c',
    'xmock.c',
    install : true,
    include_directories: dir)

trilo_xtest_c_dep = declare_dependency(
    link_with: lib_xtest,
    include_directories: dir)

trilo_xmock_c_dep = declare_dependency(
    link_with: lib_xmock,
    include_directories: dir)
