if get_option('with_tests').enabled()
    trilo_utest_dep = dependency('trilo-utest-c')

    test_exe = executable('dummy',
        'test_cases.c',
        dependencies : [trilo_utest_dep, trilo_dep])

    test('Execute project tests', test_exe)
endif
