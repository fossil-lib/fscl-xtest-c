if get_option('with_test').enabled()
    test_source = files(
        'xtest_xexpect.c',  'xtest_xassert.c',
        'xtest_bench.c',   'xunit_runner.c')

    configure_file(input: 'example.txt', output: 'example.txt', copy: true)

    test('Execute project Xunit tests', 
        executable('xrunner', test_source,
        dependencies : [trilo_xtest_c_dep, trilo_xmock_c_dep]))
endif
