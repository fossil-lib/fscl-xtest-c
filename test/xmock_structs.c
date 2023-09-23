/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "xtest_fixtures.h"
#include "trilobite/xmock.h"

//
// TEST DATA
//
XTEST_DATA(DataStructureTests) {
    XMockDoublyLinkedList *list;
    XMockQueue *queue;
    XMockStack *stack;
    XMockMap *map;
} structs;

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmock_list_test_fixture);
XTEST_SETUP(xmock_list_test_fixture) {
    structs.list = xmock_doubly_linked_list_create();
} // end setup

XTEST_TEARDOWN(xmock_list_test_fixture) {
    xmock_doubly_linked_list_destroy(structs.list);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmock_list_test_fixture, mock_list_push_front) {
    xmock_doubly_linked_list_push_front(structs.list, 22);
    xmock_doubly_linked_list_push_front(structs.list, 32);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(structs.list), 2);
}

XTEST_CASE_FIXTURE(xmock_list_test_fixture, mock_list_push_back) {
    xmock_doubly_linked_list_push_back(structs.list, 22);
    xmock_doubly_linked_list_push_back(structs.list, 32);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(structs.list), 2);
}

XTEST_CASE_FIXTURE(xmock_list_test_fixture, mock_list_pop_front) {
    xmock_doubly_linked_list_push_front(structs.list, 22);
    xmock_doubly_linked_list_push_front(structs.list, 32);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(structs.list), 2);

    xmock_doubly_linked_list_pop_front(structs.list);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(structs.list), 1);
}

XTEST_CASE_FIXTURE(xmock_list_test_fixture, mock_list_pop_back) {
    xmock_doubly_linked_list_push_back(structs.list, 22);
    xmock_doubly_linked_list_push_back(structs.list, 32);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(structs.list), 2);

    xmock_doubly_linked_list_pop_front(structs.list);

    XASSERT_INT_EQUAL(xmock_doubly_linked_list_size(structs.list), 1);
}

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmock_map_test_fixture);
XTEST_SETUP(xmock_map_test_fixture) {
    structs.map = xmock_map_create();
} // end setup

XTEST_TEARDOWN(xmock_map_test_fixture) {
    xmock_map_destroy(structs.map);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmock_map_test_fixture, mock_map_put_item) {
    xmock_map_put(structs.map, 22, 42);
    XASSERT_BOOL_TRUE(xmock_map_contains(structs.map, 22));
}

XTEST_CASE_FIXTURE(xmock_map_test_fixture, mock_map_remove) {
    xmock_map_put(structs.map, 22, 42);
    XASSERT_BOOL_TRUE(xmock_map_contains(structs.map, 22));
    xmock_map_remove(structs.map, 22);
    XASSERT_BOOL_FALSE(xmock_map_contains(structs.map, 22));
}

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmock_stack_test_fixture);
XTEST_SETUP(xmock_stack_test_fixture) {
    structs.stack = xmock_stack_create(100);
} // end setup

XTEST_TEARDOWN(xmock_stack_test_fixture) {
    xmock_stack_destroy(structs.stack);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmock_stack_test_fixture, mock_stack_push) {
    xmock_stack_push(structs.stack, 22);
    xmock_stack_push(structs.stack, 23);
    xmock_stack_push(structs.stack, 11);

    XASSERT_INT_EQUAL(xmock_stack_size(structs.stack), 3);
}

XTEST_CASE_FIXTURE(xmock_stack_test_fixture, mock_stack_pop) {
    xmock_stack_push(structs.stack, 22);
    xmock_stack_push(structs.stack, 23);
    xmock_stack_push(structs.stack, 11);

    XASSERT_INT_EQUAL(xmock_stack_size(structs.stack), 3);

    xmock_stack_pop(structs.stack);
    XASSERT_INT_EQUAL(xmock_stack_size(structs.stack), 2);
}

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmock_queue_test_fixture);
XTEST_SETUP(xmock_queue_test_fixture) {
    structs.queue = xmock_queue_create(100);
} // end setup

XTEST_TEARDOWN(xmock_queue_test_fixture) {
    xmock_queue_destroy(structs.queue);
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmock_queue_test_fixture, mock_queue_enqueue) {
    xmock_queue_enqueue(structs.queue, 22);
    xmock_queue_enqueue(structs.queue, 23);
    xmock_queue_enqueue(structs.queue, 11);

    XASSERT_INT_EQUAL(xmock_queue_size(structs.queue), 3);
}

XTEST_CASE_FIXTURE(xmock_queue_test_fixture, mock_queue_dequeue) {
    xmock_queue_enqueue(structs.queue, 22);
    xmock_queue_enqueue(structs.queue, 23);
    xmock_queue_enqueue(structs.queue, 11);

    XASSERT_INT_EQUAL(xmock_queue_size(structs.queue), 3);

    xmock_queue_dequeue(structs.queue);
    XASSERT_INT_EQUAL(xmock_queue_size(structs.queue), 2);
}

//
// XTEST FIXTURE
//
void xmockup_struct_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&mock_list_push_front, &xmock_list_test_fixture,  &runner->stats);
    xtest_run_test_fixture(&mock_list_push_back,  &xmock_list_test_fixture,  &runner->stats);
    xtest_run_test_fixture(&mock_list_pop_front,  &xmock_list_test_fixture,  &runner->stats);
    xtest_run_test_fixture(&mock_list_pop_back,   &xmock_list_test_fixture,  &runner->stats);
    xtest_run_test_fixture(&mock_map_put_item,    &xmock_map_test_fixture,   &runner->stats);
    xtest_run_test_fixture(&mock_map_remove,      &xmock_map_test_fixture,   &runner->stats);
    xtest_run_test_fixture(&mock_stack_push,      &xmock_stack_test_fixture, &runner->stats);
    xtest_run_test_fixture(&mock_stack_pop,       &xmock_stack_test_fixture, &runner->stats);
    xtest_run_test_fixture(&mock_queue_enqueue,   &xmock_queue_test_fixture, &runner->stats);
    xtest_run_test_fixture(&mock_queue_dequeue,   &xmock_queue_test_fixture, &runner->stats);
} // end of fixture
