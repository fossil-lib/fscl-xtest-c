if get_option('with_tests').enabled()

    test_01_exe = executable('dummy',
        'xtest_runner.c',
        'xtest_cases.c',
        'xtest_mocks.c',
        'xtest_bench.c',
        dependencies : [trilo_xtest_c_dep])

    test('Execute project tests', test_01_exe)
endif
