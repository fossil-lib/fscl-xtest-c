if get_option('with_test').enabled()
    configure_file(input: 'xtest_config.ini', output: 'xtest_config.ini', copy: true)
    configure_file(input: 'example.txt', output: 'example.txt', copy: true)

    test_src = ['xunit_runner.c']
    test_cubes = ['xexpect', 'xassert', 'bench']

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('xcli', test_src, include_directories: dir, dependencies: [tscl_xtest_c_dep])
    test('xunit_tests', pizza)  # Renamed the test target for clarity
endif
