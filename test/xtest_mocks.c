/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

//
// MOCK FUNCTIONS
//
XMOCK_FUNC(xmock_float, bar) {
    return arg * 1.5f;
}

XMOCK_FUNC(xmock_string, baz) {
    return arg;
}

XMOCK_FUNC(xmock_int, foo) {
    return arg * 2;
}

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_test_fixture);

XTEST_SETUP(xmockup_test_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xmockup_test_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_test_fixture, xmock_stub_bar) {
    xmock_float result = xmock_bar(3.0f); // Result: 4.500000
    XASSERT_FLOAT_EQUAL(result, 4.6f, 4.3);
} // end of case

XTEST_CASE_FIXTURE(xmockup_test_fixture, xmock_stub_baz) {
    xmock_string result = xmock_baz("Hello, world!");
    XASSERT_STRING_EQUAL(result, "Hello, world!");
} // end of case

XTEST_CASE_FIXTURE(xmockup_test_fixture, xmock_stub_foo) {
    xmock_int result = xmock_foo(10);
    XASSERT_INT_EQUAL(result, 20);
} // end of case

//
// TEST DATA
//
XTEST_DATA(mock_structures) {
    XMockDoublyLinkedList *list;
    XMockQueue *queue;
    XMockStack *stack;
    XMockMap *map;
} mock_structs;

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmock_list_test_fixture);
XTEST_SETUP(xmock_list_test_fixture) {
    mock_structs.list = xmock_doubly_linked_list_create();
} // end setup

XTEST_TEARDOWN(xmock_list_test_fixture) {
    xmock_doubly_linked_list_destroy(mock_structs.list);
} // end teardown

XTEST_FIXTURE(xmock_map_test_fixture);
XTEST_SETUP(xmock_map_test_fixture) {
    mock_structs.map = xmock_map_create();
} // end setup

XTEST_TEARDOWN(xmock_map_test_fixture) {
    xmock_map_destroy(mock_structs.map);
} // end teardown

XTEST_FIXTURE(xmock_stack_test_fixture);
XTEST_SETUP(xmock_stack_test_fixture) {
    mock_structs.stack = xmock_stack_create(100);
} // end setup

XTEST_TEARDOWN(xmock_stack_test_fixture) {
    xmock_stack_destroy(mock_structs.stack);
} // end teardown

XTEST_FIXTURE(xmock_queue_test_fixture);
XTEST_SETUP(xmock_queue_test_fixture) {
    mock_structs.queue = xmock_queue_create(100);
} // end setup

XTEST_TEARDOWN(xmock_queue_test_fixture) {
    xmock_queue_destroy(mock_structs.queue);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmock_list_test_fixture, mock_list_operations) {
    xmock_doubly_linked_list_push_front(mock_structs.list, 22);
    xmock_doubly_linked_list_push_front(mock_structs.list, 32);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(mock_structs.list), 2);

    xmock_doubly_linked_list_pop_front(mock_structs.list);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(mock_structs.list), 1);
}

XTEST_CASE_FIXTURE(xmock_map_test_fixture, mock_map_operations) {
    xmock_map_put(mock_structs.map, 22, 42);
    XASSERT_BOOL_TRUE(xmock_map_contains(mock_structs.map, 22));
}

XTEST_CASE_FIXTURE(xmock_stack_test_fixture, mock_stack_operations) {
    xmock_stack_push(mock_structs.stack, 22);
    xmock_stack_push(mock_structs.stack, 23);
    xmock_stack_push(mock_structs.stack, 11);

    XASSERT_INT_EQUAL(xmock_stack_size(mock_structs.stack), 3);
}

XTEST_CASE_FIXTURE(xmock_queue_test_fixture, mock_queue_operations) {
    xmock_queue_enqueue(mock_structs.queue, 22);
    xmock_queue_enqueue(mock_structs.queue, 23);
    xmock_queue_enqueue(mock_structs.queue, 11);

    XASSERT_INT_EQUAL(xmock_queue_size(mock_structs.queue), 3);
}

//
// XTEST FIXTURE
//
void xmockup_test_group(XUnitRunner *runner)
{
    xtest_run_test_fixture(&xmock_stub_foo, &xmockup_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stub_bar, &xmockup_test_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stub_baz, &xmockup_test_fixture, &runner->stats);

    xtest_run_test_fixture(&mock_list_operations, &xmock_list_test_fixture, &runner->stats);
    xtest_run_test_fixture(&mock_map_operations, &xmock_map_test_fixture, &runner->stats);
    xtest_run_test_fixture(&mock_stack_operations, &xmock_stack_test_fixture, &runner->stats);
    xtest_run_test_fixture(&mock_queue_operations, &xmock_queue_test_fixture, &runner->stats);
} // end of fixture
