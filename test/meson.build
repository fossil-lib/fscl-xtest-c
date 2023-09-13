if get_option('with_tests').enabled()
    exe = executable('xtest-runner',
        'xtest_runner.c',
        'xtest_cases.c',
        'xtest_xignore.c',
        'xtest_xexpect.c',
        'xtest_xassert.c',
        'xtest_mocks.c',
        'xtest_bench.c',
        dependencies : [trilo_xtest_c_dep])


    test('Execute project tests', exe)
    test('Execute C Sample', executable('c-sample', 'sample.c', dependencies : [trilo_xtest_c_dep]))
    if add_languages('cpp', required : false)
        test('Execute C++ Sample', executable('c-sample', 'sample.cpp', dependencies : [trilo_xtest_c_dep]))
    endif
endif
