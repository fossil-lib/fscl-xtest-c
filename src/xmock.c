/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xmock.h"


/**
 * @brief Creates a mocked file stream for testing and simulation purposes.
 *
 * This function simulates opening a file with the specified filename and mode. It returns an
 * XMockFile pointer representing the opened file stream.
 *
 * @param filename  The name of the file to open.
 * @param mode      The mode in which to open the file (e.g., "r" for read, "w" for write).
 *
 * @return An XMockFile pointer representing the opened file stream. Returns NULL if the file could
 * not be opened or if it is not found.
 */
XMockFile* xmock_io_fopen(const char* filename, const char* mode) {
    // For simplicity, we assume mode is always "r" for reading
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    } // end if

    // Determine the file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the XMockFile struct
    XMockFile* mock_file = (XMockFile*)malloc(sizeof(XMockFile));
    if (!mock_file) {
        fclose(file);
        return NULL;
    } // end if

    // Allocate memory for file data and read the file content into it
    mock_file->data = (char*)malloc(file_size);
    if (!mock_file->data) {
        free(mock_file);
        fclose(file);
        return NULL;
    } // end if

    fread(mock_file->data, 1, file_size, file);
    mock_file->size = file_size;
    mock_file->position = 0;

    fclose(file);
    return mock_file;
} // end of func

/**
 * @brief Reads data from a mocked file stream.
 *
 * This function simulates reading data from the specified file stream into the provided buffer.
 * It mimics the behavior of the standard C library's fread function.
 *
 * @param ptr       Pointer to the destination buffer to store the read data.
 * @param size      The size of each item to read (in bytes).
 * @param count     The number of items to read.
 * @param stream    The XMockFile pointer representing the file stream to read from.
 *
 * @return The total number of items successfully read, which may be less than (size * count) if
 * the end of the file is reached or an error occurs.
 */
size_t xmock_io_fread(void* ptr, size_t size, size_t count, XMockFile* stream) {
    if (!stream) {
        return 0;
    } // end if

    size_t bytes_to_read = size * count;
    if (stream->position + bytes_to_read > stream->size) {
        bytes_to_read = stream->size - stream->position;
    } // end if

    memcpy(ptr, stream->data + stream->position, bytes_to_read);
    stream->position += bytes_to_read;

    return bytes_to_read / size;
} // end of func

/**
 * @brief Closes a mocked file stream.
 *
 * This function simulates closing the specified file stream, releasing any associated resources.
 * It mimics the behavior of the standard C library's fclose function.
 *
 * @param stream    The XMockFile pointer representing the file stream to close.
 *
 * @return None.
 */
void xmock_io_fclose(XMockFile* stream) {
    if (stream) {
        free(stream->data);
        free(stream);
    } // end if
} // end of func

/**
 * @brief Creates a new XMockStack with the specified capacity.
 *
 * @param capacity The maximum number of elements the stack can hold.
 *
 * @return A pointer to the newly created XMockStack if successful, or NULL if memory allocation fails.
 */
XMockStack* xmock_stack_create(int capacity) {
    // Allocate memory for the stack structure
    XMockStack* stack = (XMockStack*)malloc(sizeof(XMockStack));

    if (stack == NULL) {
        return NULL; // Allocation failed
    } // end if

    // Allocate memory for the stack's data array
    stack->data = (int*)malloc(sizeof(int) * capacity);

    if (stack->data == NULL) {
        free(stack);
        return NULL; // Allocation failed
    } // end if

    // Initialize stack properties
    stack->size = 0;
    stack->capacity = capacity;

    return stack;
} // end of func

/**
 * @brief Pushes an integer element onto the stack.
 *
 * @param stack A pointer to the XMockStack.
 * @param element The integer element to push onto the stack.
 */
void xmock_stack_push(XMockStack* stack, int element) {
    if (stack->size < stack->capacity) {
        // Push the element onto the stack if it's not full
        stack->data[stack->size++] = element;
    } // end if
} // end of func

/**
 * @brief Pops and returns the top element from the stack.
 *
 * @param stack A pointer to the XMockStack.
 *
 * @return The popped integer element if the stack is not empty, or a default value of 0 if the stack is empty.
 */
int xmock_stack_pop(XMockStack* stack) {
    if (stack->size > 0) {
        // Pop and return the top element if the stack is not empty
        return stack->data[--stack->size];
    } // end if
    
    // Default return value for an empty stack (you can customize this behavior)
    return 0;
} // end of func

/**
 * @brief Returns the current size (number of elements) of the stack.
 *
 * @param stack A pointer to the XMockStack.
 *
 * @return The current size of the stack.
 */
int xmock_stack_size(XMockStack* stack) {
    return stack->size;
} // end of func

/**
 * @brief Destroys the XMockStack and frees the allocated memory.
 *
 * @param stack A pointer to the XMockStack to be destroyed.
 */
void xmock_stack_destroy(XMockStack* stack) {
    if (stack != NULL) {
        // Free memory for the data array and the stack structure
        free(stack->data);
        free(stack);
    } // end if
} // end of func

//
// LINKED LIST
//

/**
 * @brief Creates a new XMockDoublyLinkedList.
 *
 * @return A pointer to the newly created XMockDoublyLinkedList if successful, or NULL if memory allocation fails.
 */
XMockDoublyLinkedList* xmock_doubly_linked_list_create() {
    // Allocate memory for the linked list structure
    XMockDoublyLinkedList* list = (XMockDoublyLinkedList*)malloc(sizeof(XMockDoublyLinkedList));

    if (list == NULL) {
        return NULL; // Allocation failed
    } // end if

    // Initialize linked list properties
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
} // end of func

/**
 * @brief Pushes an integer element to the front of the linked list.
 *
 * @param list A pointer to the XMockDoublyLinkedList.
 * @param data The integer data to push to the front of the linked list.
 */
void xmock_doubly_linked_list_push_front(XMockDoublyLinkedList* list, int data) {
    // Allocate memory for a new list node
    XMockNode* newNode = (XMockNode*)malloc(sizeof(XMockNode));

    if (newNode == NULL) {
        return; // Allocation failed
    } // end if

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL) {
        list->head->prev = newNode;
    } // end if

    list->head = newNode;

    if (list->tail == NULL) {
        list->tail = newNode;
    } // end if

    list->size++;
} // end of func

/**
 * @brief Pushes an integer element to the back of the linked list.
 *
 * @param list A pointer to the XMockDoublyLinkedList.
 * @param data The integer data to push to the back of the linked list.
 */
void xmock_doubly_linked_list_push_back(XMockDoublyLinkedList* list, int data) {
    // Allocate memory for a new list node
    XMockNode* newNode = (XMockNode*)malloc(sizeof(XMockNode));

    if (newNode == NULL) {
        return; // Allocation failed
    } // end if

    newNode->data = data;
    newNode->prev = list->tail;
    newNode->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    } // end if

    list->tail = newNode;

    if (list->head == NULL) {
        list->head = newNode;
    } // end if

    list->size++;
} // end of func

/**
 * @brief Pops and returns the front element of the linked list.
 *
 * @param list A pointer to the XMockDoublyLinkedList.
 *
 * @return The popped integer element if the list is not empty, or a default value of 0 if the list is empty.
 */
int xmock_doubly_linked_list_pop_front(XMockDoublyLinkedList* list) {
    if (list->head == NULL) {
        return 0; // Default return value for an empty list (you can customize this behavior)
    } // end if

    XMockNode* frontNode = list->head;
    int data = frontNode->data;

    list->head = frontNode->next;

    if (list->head != NULL) {
        list->head->prev = NULL;
    } // end if

    free(frontNode);
    list->size--;

    return data;
} // end of func

/**
 * @brief Pops and returns the back element of the linked list.
 *
 * @param list A pointer to the XMockDoublyLinkedList.
 *
 * @return The popped integer element if the list is not empty, or a default value of 0 if the list is empty.
 */
int xmock_doubly_linked_list_pop_back(XMockDoublyLinkedList* list) {
    if (list->tail == NULL) {
        return 0; // Default return value for an empty list (you can customize this behavior)
    } // end if

    XMockNode* backNode = list->tail;
    int data = backNode->data;

    list->tail = backNode->prev;

    if (list->tail != NULL) {
        list->tail->next = NULL;
    } // end if

    free(backNode);
    list->size--;

    return data;
} // end of func

/**
 * @brief Returns the current size (number of elements) of the linked list.
 *
 * @param list A pointer to the XMockDoublyLinkedList.
 *
 * @return The current size of the linked list.
 */
int xmock_doubly_linked_list_size(XMockDoublyLinkedList* list) {
    return list->size;
} // end of func

/**
 * @brief Destroys the XMockDoublyLinkedList and frees the allocated memory.
 *
 * @param list A pointer to the XMockDoublyLinkedList to be destroyed.
 */
void xmock_doubly_linked_list_destroy(XMockDoublyLinkedList* list) {
    if (list != NULL) {
        // Free memory for each list node and the linked list structure
        XMockNode* current = list->head;
        while (current != NULL) {
            XMockNode* next = current->next;
            free(current);
            current = next;
        } // end while
        free(list);
    } // end if
} // end of func

//
//
//
/**
 * @brief Creates a new XMockQueue with the specified capacity.
 *
 * @param capacity The maximum number of elements the queue can hold.
 *
 * @return A pointer to the newly created XMockQueue if successful, or NULL if memory allocation fails.
 */
XMockQueue* xmock_queue_create(int capacity) {
    // Allocate memory for the queue structure
    XMockQueue* queue = (XMockQueue*)malloc(sizeof(XMockQueue));

    if (queue == NULL) {
        return NULL; // Allocation failed
    } // end if

    // Allocate memory for the queue data
    queue->data = (int*)malloc(sizeof(int) * capacity);

    if (queue->data == NULL) {
        free(queue);
        return NULL; // Allocation failed
    } // end if

    // Initialize queue properties
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
} // end of func

/**
 * @brief Enqueues an integer element into the XMockQueue.
 *
 * @param queue A pointer to the XMockQueue.
 * @param element The integer element to enqueue.
 */
void xmock_queue_enqueue(XMockQueue* queue, int element) {
    if (queue->size < queue->capacity) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->data[queue->rear] = element;
        queue->size++;
    } // end if
} // end of func

/**
 * @brief Dequeues and returns the front element from the XMockQueue.
 *
 * @param queue A pointer to the XMockQueue.
 *
 * @return The dequeued integer element if the queue is not empty, or a default value of 0 if the queue is empty.
 */
int xmock_queue_dequeue(XMockQueue* queue) {
    if (queue->size > 0) {
        int frontElement = queue->data[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        return frontElement;
    } // end if
    return 0; // Default return value for an empty queue (you can customize this behavior)
} // end of func

/**
 * @brief Returns the current size (number of elements) of the XMockQueue.
 *
 * @param queue A pointer to the XMockQueue.
 *
 * @return The current size of the XMockQueue.
 */
int xmock_queue_size(XMockQueue* queue) {
    return queue->size;
} // end of func

/**
 * @brief Destroys the XMockQueue and frees the allocated memory.
 *
 * @param queue A pointer to the XMockQueue to be destroyed.
 */
void xmock_queue_destroy(XMockQueue* queue) {
    if (queue != NULL) {
        free(queue->data);
        free(queue);
    } // end if
} // end of func

//
//
//
/**
 * @brief Creates a new XMockMap.
 *
 * @return A pointer to the newly created XMockMap if successful, or NULL if memory allocation fails.
 */
XMockMap* xmock_map_create() {
    // Allocate memory for the map structure
    XMockMap* map = (XMockMap*)malloc(sizeof(XMockMap));

    if (map == NULL) {
        return NULL; // Allocation failed
    } // end if

    // Initialize map properties
    map->size = 0;

    return map;
} // end of func

/**
 * @brief Inserts a key-value pair into the XMockMap.
 *
 * @param map A pointer to the XMockMap.
 * @param key The key to insert.
 * @param value The corresponding value to insert.
 */
void xmock_map_put(XMockMap* map, int key, int value) {
    if (map->size < XMOCK_MAP_MAX_SIZE) {
        map->entries[map->size].key = key;
        map->entries[map->size].value = value;
        map->size++;
    } // end if
} // end of func

/**
 * @brief Retrieves the value associated with a given key from the XMockMap.
 *
 * @param map A pointer to the XMockMap.
 * @param key The key to look up.
 *
 * @return The value associated with the key if found, or a default value of 0 if the key is not found (you can customize this behavior).
 */
int xmock_map_get(XMockMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        } // end if
    } // end for
    return 0; // Default return value for a key not found (you can customize this behavior)
} // end of func

/**
 * @brief Checks if a key exists in the XMockMap.
 *
 * @param map A pointer to the XMockMap.
 * @param key The key to check.
 *
 * @return 1 if the key exists in the map, 0 otherwise.
 */
int xmock_map_contains(XMockMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return 1; // Key exists
        } // end if
    } // end for
    return 0; // Key not found
} // end of func

/**
 * @brief Removes a key-value pair from the XMockMap based on the key.
 *
 * @param map A pointer to the XMockMap.
 * @param key The key to remove.
 */
void xmock_map_remove(XMockMap* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            for (int j = i; j < map->size - 1; j++) {
                map->entries[j] = map->entries[j + 1];
            } // end for
            map->size--;
            break;
        } // end if
    } // end for
} // end of func

/**
 * @brief Returns the current size (number of key-value pairs) of the XMockMap.
 *
 * @param map A pointer to the XMockMap.
 *
 * @return The current size of the XMockMap.
 */
int xmock_map_size(XMockMap* map) {
    return map->size;
} // end of func

/**
 * @brief Destroys the XMockMap and frees the allocated memory.
 *
 * @param map A pointer to the XMockMap to be destroyed.
 */
void xmock_map_destroy(XMockMap* map) {
    if (map != NULL) {
        free(map);
    } // end if
} // end of func
