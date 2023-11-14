if get_option('with_demo').enabled()
    demo_apps = ['tdd', 'bdd']

    foreach iter : demo_apps
        executable('demo_' + iter, 'demo_' + iter + '.c', dependencies : [trilo_xtest_c_dep, trilo_xmock_c_dep])
    endforeach
endif
