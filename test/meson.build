if get_option('with_tests').enabled()
    exe = executable('xtest-runner',
        'xtest_runner.c',
        'xtest_cases.c',
        'xtest_xignore.c',
        'xtest_xexpect.c',
        'xtest_xassert.c',
        'xmock_structs.c',
        'xmock_functions.c',
        'xtest_bench.c',
        dependencies : [trilo_xtest_c_dep])

    test('Execute project tests', exe)
endif

if get_option('with_demo').enabled()
    test('Execute C Sample', executable('c-sample', 'sample.c', dependencies : [trilo_xtest_c_dep]))
    if add_languages('cpp', required : false)
        test('Execute C++ Sample', executable('cpp-sample', 'sample.cpp', dependencies : [trilo_xtest_c_dep]))
    endif
endif
