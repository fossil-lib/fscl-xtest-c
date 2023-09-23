/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XMOCK_H
#define TRILOBITE_XMOCK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

// Define mock function return types based on types.
typedef int xmock_int;
typedef int8_t xmock_int8_t;
typedef int16_t xmock_int16_t;
typedef int32_t xmock_int32_t;
typedef int64_t xmock_int64_t;
typedef unsigned int xmock_uint;
typedef uint8_t xmock_uint8_t;
typedef uint16_t xmock_uint16_t;
typedef uint32_t xmock_uint32_t;
typedef uint64_t xmock_uint64_t;
typedef uint8_t xmock_hex8_t;
typedef uint16_t xmock_hex16_t;
typedef uint32_t xmock_hex32_t;
typedef uint64_t xmock_hex64_t;
typedef float xmock_float;
typedef double xmock_double;

// Define a macro for char type.
typedef char xmock_char;

// Define a macro for char * type.
typedef char *xmock_string;

typedef void *xmock_default;

/**
 * @def XMOCK_FUNC
 * @brief Macro for creating a mock function with the specified return type, name, and parameters.
 *
 * This macro simplifies the creation of mock functions by defining a function with the given return
 * type, name, and parameters. The function name will be prefixed with "xmock_" to clearly indicate
 * that it is a mock function.
 *
 * @param return_type   The return type of the mock function.
 * @param name          The name of the mock function.
 * @param ...           The parameters of the mock function in the format: (type1 param1, type2 param2, ...).
 * @return The return type specified for the mock function.
 */
#define XMOCK_FUNC(return_type, name, ...) return_type xmock_##name(__VA_ARGS__)

/**
 * @file mock_data_structures.h
 *
 * @brief Mock Data Structures
 *
 * This file defines a set of mock data structures and associated functions for educational
 * purposes. These data structures are simplified versions of common data structures used
 * in computer science and software development.
 *
 * 1. Mock Stack:
 *    - The `XMockStack` structure represents a stack, a Last-In, First-Out (LIFO) data structure.
 *    - It consists of an array (`data`) to store stack elements, the current size (`size`) of
 *      the stack, and the maximum capacity (`capacity`) of the stack.
 *    - Functions:
 *      - `XMockStack* xmock_stack_create(int capacity)`:
 *        Creates and initializes a mock stack with the given capacity.
 *      - `void xmock_stack_push(XMockStack* stack, int element)`:
 *        Pushes an element onto the stack.
 *      - `int xmock_stack_pop(XMockStack* stack)`:
 *        Pops an element from the stack.
 *      - `int xmock_stack_size(XMockStack* stack)`:
 *        Returns the current size of the stack.
 *      - `void xmock_stack_destroy(XMockStack* stack)`:
 *        Destroys the mock stack and releases allocated resources.
 *
 * 2. Mock Doubly Linked List:
 *    - The `XMockDoublyLinkedList` structure represents a doubly linked list.
 *    - It consists of nodes (`XMockNode`) with integer data, where each node has pointers to
 *      the previous (`prev`) and next (`next`) nodes.
 *    - The linked list maintains pointers to the `head` (first node) and `tail` (last node),
 *      as well as the current size (`size`) of the list.
 *    - Functions:
 *      - `XMockDoublyLinkedList* xmock_doubly_linked_list_create()`:
 *        Creates and initializes a mock doubly linked list.
 *      - `void xmock_doubly_linked_list_push_front(XMockDoublyLinkedList* list, int data)`:
 *        Inserts an element at the beginning of the list.
 *      - `void xmock_doubly_linked_list_push_back(XMockDoublyLinkedList* list, int data)`:
 *        Inserts an element at the end of the list.
 *      - `int xmock_doubly_linked_list_pop_front(XMockDoublyLinkedList* list)`:
 *        Removes and returns the first element of the list.
 *      - `int xmock_doubly_linked_list_pop_back(XMockDoublyLinkedList* list)`:
 *        Removes and returns the last element of the list.
 *      - `int xmock_doubly_linked_list_size(XMockDoublyLinkedList* list)`:
 *        Returns the current size of the list.
 *      - `void xmock_doubly_linked_list_destroy(XMockDoublyLinkedList* list)`:
 *        Destroys the mock doubly linked list and releases allocated resources.
 *
 * 3. Mock Queue:
 *    - The `XMockQueue` structure represents a queue, a First-In, First-Out (FIFO) data structure.
 *    - It consists of an array (`data`) to store queue elements, pointers to the `front` and `rear`
 *      indices, the current size (`size`) of the queue, and the maximum capacity (`capacity`) of
 *      the queue.
 *    - Functions:
 *      - `XMockQueue* xmock_queue_create(int capacity)`:
 *        Creates and initializes a mock queue with the given capacity.
 *      - `void xmock_queue_enqueue(XMockQueue* queue, int element)`:
 *        Enqueues an element into the queue.
 *      - `int xmock_queue_dequeue(XMockQueue* queue)`:
 *        Dequeues and returns the front element of the queue.
 *      - `int xmock_queue_size(XMockQueue* queue)`:
 *        Returns the current size of the queue.
 *      - `void xmock_queue_destroy(XMockQueue* queue)`:
 *        Destroys the mock queue and releases allocated resources.
 *
 * 4. Mock Map:
 *    - The `XMockMap` structure represents a simple key-value map.
 *    - It consists of an array of key-value pairs (`entries`), the current size (`size`) of the map,
 *      and a maximum size defined by `XMOCK_MAP_MAX_SIZE`.
 *    - Functions:
 *      - `XMockMap* xmock_map_create()`:
 *        Creates and initializes a mock map.
 *      - `void xmock_map_put(XMockMap* map, int key, int value)`:
 *        Puts a key-value pair into the map.
 *      - `int xmock_map_get(XMockMap* map, int key)`:
 *        Gets the value associated with a key from the map.
 *      - `int xmock_map_contains(XMockMap* map, int key)`:
 *        Checks if a key exists in
 */

//
// MOCK STACK
//

// Define the mock stack structure
typedef struct {
    int* data;      // Array to store stack elements
    int size;       // Current size of the stack
    int capacity;   // Maximum capacity of the stack
} XMockStack;

// Create and initialize a mock stack
// @param capacity: Maximum capacity of the stack
// @return: A pointer to the newly created stack
XTEST_API XMockStack* xmock_stack_create(int capacity);

// Push an element onto the mock stack
// @param stack: Pointer to the stack
// @param element: Element to be pushed onto the stack
XTEST_API void xmock_stack_push(XMockStack* stack, int element);

// Pop an element from the mock stack
// @param stack: Pointer to the stack
// @return: The popped element
XTEST_API int xmock_stack_pop(XMockStack* stack);

// Get the size of the mock stack
// @param stack: Pointer to the stack
// @return: Current size of the stack
XTEST_API int xmock_stack_size(XMockStack* stack);

// Destroy the mock stack and release resources
// @param stack: Pointer to the stack to be destroyed
XTEST_API void xmock_stack_destroy(XMockStack* stack);


//
// MOCK LINKED LIST
//

// Define the mock doubly linked list node structure
typedef struct XMockNode {
    int data;                   // Data stored in the node
    struct XMockNode* prev;     // Pointer to the previous node
    struct XMockNode* next;     // Pointer to the next node
} XMockNode;

// Define the mock doubly linked list structure
typedef struct {
    XMockNode* head;            // Pointer to the first node
    XMockNode* tail;            // Pointer to the last node
    int size;                   // Current size of the list
} XMockDoublyLinkedList;

// @brief Create and initialize a mock doubly linked list.
// @return A pointer to the created mock doubly linked list or NULL if allocation fails.
XTEST_API XMockDoublyLinkedList* xmock_doubly_linked_list_create();

// @brief Insert an element at the beginning of the list.
// @param list The mock doubly linked list to which the element will be added.
// @param data The data to insert.
XTEST_API void xmock_doubly_linked_list_push_front(XMockDoublyLinkedList* list, int data);

// @brief Insert an element at the end of the list.
// @param list The mock doubly linked list to which the element will be added.
// @param data The data to insert.
XTEST_API void xmock_doubly_linked_list_push_back(XMockDoublyLinkedList* list, int data);

// @brief Remove and return the first element of the list.
// @param list The mock doubly linked list from which the first element will be removed.
// @return The value of the first element or 0 if the list is empty.
XTEST_API int xmock_doubly_linked_list_pop_front(XMockDoublyLinkedList* list);

// @brief Remove and return the last element of the list.
// @param list The mock doubly linked list from which the last element will be removed.
// @return The value of the last element or 0 if the list is empty.
XTEST_API int xmock_doubly_linked_list_pop_back(XMockDoublyLinkedList* list);

// @brief Get the size of the list.
// @param list The mock doubly linked list for which to determine the size.
// @return The current size of the list.
XTEST_API int xmock_doubly_linked_list_size(XMockDoublyLinkedList* list);

// @brief Destroy the mock doubly linked list and release allocated resources.
// @param list The mock doubly linked list to destroy.
XTEST_API void xmock_doubly_linked_list_destroy(XMockDoublyLinkedList* list);


//
// XMOCK QUEUE
//

// @brief Define the mock queue structure.
typedef struct {
    int* data;       // @brief Array to store queue elements.
    int front;       // @brief Index of the front element.
    int rear;        // @brief Index of the rear element.
    int size;        // @brief Current size of the queue.
    int capacity;    // @brief Maximum capacity of the queue.
} XMockQueue;

// @brief Create and initialize a mock queue.
// @param capacity The maximum capacity of the queue.
// @return A pointer to the created mock queue or NULL if allocation fails.
XTEST_API XMockQueue* xmock_queue_create(int capacity);

// @brief Enqueue an element into the mock queue.
// @param queue The mock queue to which the element will be enqueued.
// @param element The element to be enqueued.
XTEST_API void xmock_queue_enqueue(XMockQueue* queue, int element);

// @brief Dequeue and return the front element of the mock queue.
// @param queue The mock queue from which the front element will be dequeued.
// @return The front element of the queue or 0 if the queue is empty.
XTEST_API int xmock_queue_dequeue(XMockQueue* queue);

// @brief Get the size of the mock queue.
// @param queue The mock queue for which to determine the size.
// @return The current size of the queue.
XTEST_API int xmock_queue_size(XMockQueue* queue);

// @brief Destroy the mock queue and release allocated resources.
// @param queue The mock queue to destroy.
XTEST_API void xmock_queue_destroy(XMockQueue* queue);



//
// XMOCK MAP
//

// @brief Define the maximum number of key-value pairs the mock map can hold.
#define XMOCK_MAP_MAX_SIZE 100

// @brief Define the key-value pair structure.
typedef struct {
    int key;    // @brief The key of the entry.
    int value;  // @brief The value associated with the key.
} XMockMapEntry;

// @brief Define the mock map structure.
typedef struct {
    XMockMapEntry entries[XMOCK_MAP_MAX_SIZE];  // @brief Array of key-value pairs.
    int size;                                   // @brief Current number of entries in the map.
} XMockMap;

// @brief Create and initialize a mock map.
XTEST_API XMockMap* xmock_map_create();

// @brief Put a key-value pair into the mock map.
// @param map The mock map to which the entry will be added.
// @param key The key of the entry to add.
// @param value The value associated with the key.
XTEST_API void xmock_map_put(XMockMap* map, int key, int value);

// @brief Get the value associated with a key from the mock map.
// @param map The mock map to search for the key.
// @param key The key to look up in the map.
// @return The value associated with the key or 0 if the key is not found.
XTEST_API int xmock_map_get(XMockMap* map, int key);

// @brief Check if a key exists in the mock map.
// @param map The mock map to check for the key.
// @param key The key to check for existence.
// @return 1 if the key exists in the map, 0 otherwise.
XTEST_API int xmock_map_contains(XMockMap* map, int key);

// @brief Remove a key-value pair from the mock map.
// @param map The mock map from which the entry will be removed.
// @param key The key of the entry to remove.
XTEST_API void xmock_map_remove(XMockMap* map, int key);

// @brief Get the number of key-value pairs in the mock map.
// @param map The mock map for which to count the entries.
// @return The number of key-value pairs in the map.
XTEST_API int xmock_map_size(XMockMap* map);

// @brief Destroy the mock map and release allocated resources.
// @param map The mock map to destroy.
XTEST_API void xmock_map_destroy(XMockMap* map);


#ifdef __cplusplus
}
#endif

#endif
