trilo_src = files(
    'package.c')

trilo_lib = static_library('trilo_lib-c',
    trilo_src,
    include_directories: inc_dir)

trilo_dep = declare_dependency(link_with: trilo_lib,
    include_directories: inc_dir)
