if get_option('with_test').enabled()
    fs = import('fs')
    fs.copyfile('example.txt', '.')

    test_src = ['xunit_runner.c']
    test_cubes = ['xexpect', 'xassert', 'bench']

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('xcli', test_src, include_directories: dir, dependencies : trilo_xtest_c_dep)
    test('Execute project Xunit tests', pizza)
endif
