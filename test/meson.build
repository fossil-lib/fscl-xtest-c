if get_option('with_tests').enabled()

    test_01_exe = executable('dummy',
        'test_cases.c',
        dependencies : [trilo_xtest_c_dep])

    test('Execute project tests', test_01_exe)
endif
