/*  ----------------------------------------------------------------------------
    File: xmock.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xmock.h"

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

/**
 * @brief Initializes an XMockActuator instance.
 *
 * This function sets the actuator's ID and initializes its state to OFF (0).
 *
 * @param actuator Pointer to the XMockActuator instance to initialize.
 * @param id       The actuator's unique identifier.
 *
 * @return None.
 */
void xmock_actuator_init(XMockActuator *actuator, uint8_t id) {
    actuator->actuator_id = id;
    actuator->state = 0; // Initialize to OFF
} // end of func

/**
 * @brief Turns on an XMockActuator.
 *
 * This function sets the state of the actuator to ON (1).
 *
 * @param actuator Pointer to the XMockActuator instance to turn on.
 *
 * @return None.
 */
void xmock_actuator_turn_on(XMockActuator *actuator) {
    actuator->state = 1;
} // end of func

/**
 * @brief Turns off an XMockActuator.
 *
 * This function sets the state of the actuator to OFF (0).
 *
 * @param actuator Pointer to the XMockActuator instance to turn off.
 *
 * @return None.
 */
void xmock_actuator_turn_off(XMockActuator *actuator) {
    actuator->state = 0;
} // end of func

/**
 * @brief Gets the current state of an XMockActuator.
 *
 * @param actuator Pointer to the XMockActuator instance to get the state from.
 *
 * @return The current state of the actuator (0 for OFF, 1 for ON).
 */
int xmock_actuator_get_state(XMockActuator *actuator) {
    return actuator->state;
} // end of func

/**
 * @brief Initializes an XMockMotor instance.
 *
 * This function sets the motor's ID and initializes its speed to 0.
 *
 * @param motor Pointer to the XMockMotor instance to initialize.
 * @param id    The motor's unique identifier.
 *
 * @return None.
 */
void xmock_motor_init(XMockMotor *motor, uint8_t id) {
    motor->motor_id = id;
    motor->speed = 0;
} // end of func

/**
 * @brief Sets the speed of an XMockMotor.
 *
 * @param motor Pointer to the XMockMotor instance to set the speed for.
 * @param speed The desired speed to set.
 *
 * @return None.
 */
void xmock_motor_set_speed(XMockMotor *motor, int speed) {
    motor->speed = speed;
} // end of func

/**
 * @brief Gets the current speed of an XMockMotor.
 *
 * @param motor Pointer to the XMockMotor instance to get the speed from.
 *
 * @return The current speed of the motor.
 */
int xmock_motor_get_speed(XMockMotor *motor) {
    return motor->speed;
} // end of func

/**
 * @brief Starts an XMockMotor.
 *
 * This function simulates starting the motor (replace with actual motor start logic).
 * For demonstration, it prints a message indicating that the motor has started.
 *
 * @param motor Pointer to the XMockMotor instance to start.
 *
 * @return None.
 */
void xmock_motor_start(XMockMotor *motor) {
    // Simulate starting the motor (replace with actual motor start logic)
    // For demonstration, we'll print a message.
    printf("Motor %d started\n", motor->motor_id);
} // end of func

/**
 * @brief Stops an XMockMotor.
 *
 * This function simulates stopping the motor (replace with actual motor stop logic).
 * For demonstration, it prints a message indicating that the motor has stopped.
 *
 * @param motor Pointer to the XMockMotor instance to stop.
 *
 * @return None.
 */
void xmock_motor_stop(XMockMotor *motor) {
    // Simulate stopping the motor (replace with actual motor stop logic)
    // For demonstration, we'll print a message.
    printf("Motor %d stopped\n", motor->motor_id);
} // end of func

/**
 * @brief Initializes an XMockSensor instance.
 *
 * This function sets the sensor's ID and initializes its value to 0.0f.
 *
 * @param sensor Pointer to the XMockSensor instance to initialize.
 * @param id     The sensor's unique identifier.
 *
 * @return None.
 */
void xmock_sensor_init(XMockSensor *sensor, uint8_t id) {
    sensor->sensor_id = id;
    sensor->value = 0.0f;
} // end of func

/**
 * @brief Reads the value from an XMockSensor.
 *
 * This function simulates reading a sensor value (replace with actual sensor behavior).
 * For demonstration, we increment the sensor's value by 0.1f with each read.
 *
 * @param sensor Pointer to the XMockSensor instance to read from.
 *
 * @return The current sensor value.
 */
float xmock_sensor_read(XMockSensor *sensor) {
    // Simulate sensor reading (replace with actual sensor behavior)
    // For demonstration, we'll increment the value by 0.1f in each read.
    sensor->value += 0.1f;
    return sensor->value;
} // end of func

/**
 * @brief Initializes an XMockUART (UART Peripheral) instance.
 *
 * This function initializes the attributes of an XMockUART instance, including its ID, baud rate,
 * data bits, stop bits, and parity setting. These attributes simulate the configuration of a UART
 * peripheral for testing and simulation purposes.
 *
 * @param uart      Pointer to the XMockUART instance to initialize.
 * @param id        The UART peripheral's unique identifier.
 * @param baud_rate The baud rate in bits per second for UART communication.
 * @param data_bits The number of data bits (e.g., 8 bits).
 * @param stop_bits The number of stop bits (e.g., 1 stop bit).
 * @param parity    The parity setting (e.g., none, even, odd).
 *
 * @return None.
 */
void xmock_uart_init(XMockUART *uart, uint8_t id, uint32_t baud_rate, uint8_t data_bits, uint8_t stop_bits, uint8_t parity) {
    uart->uart_id = id;
    uart->baud_rate = baud_rate;
    uart->data_bits = data_bits;
    uart->stop_bits = stop_bits;
    uart->parity = parity;
} // end of func

/**
 * @brief Performs a UART transmission using the XMockUART (UART Peripheral).
 *
 * This function simulates a UART transmission using the specified XMockUART peripheral. In a real
 * application, this function would perform the actual UART transmission of data. For demonstration,
 * it prints a message indicating the UART transmission on the specified UART peripheral.
 *
 * @param uart         Pointer to the XMockUART instance to use for the transmission.
 * @param tx_buffer    Pointer to the transmit (TX) buffer containing UART data.
 * @param length       The number of bytes to transmit.
 *
 * @return None.
 */
void xmock_uart_transmit(XMockUART *uart, uint8_t *tx_buffer, uint32_t length) {
    // Simulate UART transmission (replace with actual UART transmit logic)
    printf("UART Transmit on UART %d\n", uart->uart_id);
} // end of func

/**
 * @brief Performs a UART reception using the XMockUART (UART Peripheral).
 *
 * This function simulates a UART reception using the specified XMockUART peripheral. In a real
 * application, this function would perform the actual UART reception of data. For demonstration,
 * it prints a message indicating the UART reception on the specified UART peripheral.
 *
 * @param uart         Pointer to the XMockUART instance to use for the reception.
 * @param rx_buffer    Pointer to the receive (RX) buffer to store the received data.
 * @param length       The number of bytes to receive.
 *
 * @return None.
 */
void xmock_uart_receive(XMockUART *uart, uint8_t *rx_buffer, uint32_t length) {
    // Simulate UART reception (replace with actual UART receive logic)
    printf("UART Receive on UART %d\n", uart->uart_id);
} // end of func

/**
 * @brief Initializes an XMockCAN (CAN Peripheral) instance.
 *
 * This function initializes the attributes of an XMockCAN instance, including its ID and
 * bitrate for CAN communication. These attributes simulate the configuration of a CAN peripheral
 * for testing and simulation purposes.
 *
 * @param can      Pointer to the XMockCAN instance to initialize.
 * @param id       The CAN peripheral's unique identifier.
 * @param bitrate  The bitrate in bits per second for CAN communication.
 *
 * @return None.
 */
void xmock_can_init(XMockCAN *can, uint8_t id, uint32_t bitrate) {
    can->can_id = id;
    can->bitrate = bitrate;
} // end of func

/**
 * @brief Performs a CAN transmission using the XMockCAN (CAN Peripheral).
 *
 * This function simulates a CAN transmission using the specified XMockCAN peripheral. In a real
 * application, this function would perform the actual CAN transmission of data. For demonstration,
 * it prints a message indicating the CAN transmission on the specified CAN peripheral.
 *
 * @param can         Pointer to the XMockCAN instance to use for the transmission.
 * @param tx_buffer   Pointer to the transmit (TX) buffer containing CAN data.
 * @param length      The number of bytes to transmit.
 *
 * @return None.
 */
void xmock_can_transmit(XMockCAN *can, uint8_t *tx_buffer, uint32_t length) {
    // Simulate CAN transmission (replace with actual CAN transmit logic)
    printf("CAN Transmit on CAN %d\n", can->can_id);
} // end of func

/**
 * @brief Performs a CAN reception using the XMockCAN (CAN Peripheral).
 *
 * This function simulates a CAN reception using the specified XMockCAN peripheral. In a real
 * application, this function would perform the actual CAN reception of data. For demonstration,
 * it prints a message indicating the CAN reception on the specified CAN peripheral.
 *
 * @param can         Pointer to the XMockCAN instance to use for the reception.
 * @param rx_buffer   Pointer to the receive (RX) buffer to store the received data.
 * @param length      The number of bytes to receive.
 *
 * @return None.
 */
void xmock_can_receive(XMockCAN *can, uint8_t *rx_buffer, uint32_t length) {
    // Simulate CAN reception (replace with actual CAN receive logic)
    printf("CAN Receive on CAN %d\n", can->can_id);
} // end of func

/**
 * @brief Initializes an XMockI2S (I2S Peripheral) instance.
 *
 * This function initializes the attributes of an XMockI2S instance, including its ID, sample rate,
 * data format, and channel mode. These attributes simulate the configuration of an I2S peripheral
 * for testing and simulation purposes.
 *
 * @param i2s          Pointer to the XMockI2S instance to initialize.
 * @param id           The I2S peripheral's unique identifier.
 * @param sample_rate  The sample rate in Hz for audio data.
 * @param data_format  The data format (e.g., I2S, PCM) for audio data.
 * @param channel_mode The channel mode (e.g., stereo, mono) for audio data.
 *
 * @return None.
 */
void xmock_i2s_init(XMockI2S *i2s, uint8_t id, uint32_t sample_rate, uint8_t data_format, uint8_t channel_mode) {
    i2s->i2s_id = id;
    i2s->sample_rate = sample_rate;
    i2s->data_format = data_format;
    i2s->channel_mode = channel_mode;
} // end of func

/**
 * @brief Performs an I2S transmission using the XMockI2S (I2S Peripheral).
 *
 * This function simulates an I2S transmission using the specified XMockI2S peripheral. In a real
 * application, this function would perform the actual I2S transmission of audio data. For demonstration,
 * it prints a message indicating the I2S transmission on the specified I2S peripheral.
 *
 * @param i2s         Pointer to the XMockI2S instance to use for the transmission.
 * @param tx_buffer   Pointer to the transmit (TX) buffer containing audio data.
 * @param length      The number of audio samples to transmit.
 *
 * @return None.
 */
void xmock_i2s_transmit(XMockI2S *i2s, uint8_t *tx_buffer, uint32_t length) {
    // Simulate I2S transmission (replace with actual I2S transmit logic)
    printf("I2S Transmit on I2S %d\n", i2s->i2s_id);
} // end of func

/**
 * @brief Initializes an XMockBluetooth (Bluetooth Peripheral) instance.
 *
 * This function initializes the attributes of an XMockBluetooth instance, including its ID.
 * These attributes simulate the configuration of a Bluetooth peripheral for testing and
 * simulation purposes.
 *
 * @param bluetooth  Pointer to the XMockBluetooth instance to initialize.
 * @param id         The Bluetooth peripheral's unique identifier.
 *
 * @return None.
 */
void xmock_bluetooth_init(XMockBluetooth *bluetooth, uint8_t id) {
    bluetooth->bluetooth_id = id;
} // end of func

/**
 * @brief Performs a Bluetooth transmission using the XMockBluetooth (Bluetooth Peripheral).
 *
 * This function simulates a Bluetooth transmission using the specified XMockBluetooth peripheral. In
 * a real application, this function would perform the actual Bluetooth transmission. For demonstration,
 * it prints a message indicating the Bluetooth transmission on the specified Bluetooth peripheral.
 *
 * @param bluetooth   Pointer to the XMockBluetooth instance to use for the transmission.
 * @param tx_buffer   Pointer to the transmit (TX) buffer.
 * @param length      The number of bytes to transmit.
 *
 * @return None.
 */
void xmock_bluetooth_transmit(XMockBluetooth *bluetooth, uint8_t *tx_buffer, uint32_t length) {
    // Simulate Bluetooth transmission (replace with actual Bluetooth transmit logic)
    printf("Bluetooth Transmit on Bluetooth %d\n", bluetooth->bluetooth_id);
} // end of func

/**
 * @brief Performs a Bluetooth reception using the XMockBluetooth (Bluetooth Peripheral).
 *
 * This function simulates a Bluetooth reception using the specified XMockBluetooth peripheral. In a
 * real application, this function would perform the actual Bluetooth reception. For demonstration,
 * it prints a message indicating the Bluetooth reception on the specified Bluetooth peripheral.
 *
 * @param bluetooth   Pointer to the XMockBluetooth instance to use for the reception.
 * @param rx_buffer   Pointer to the receive (RX) buffer to store the received data.
 * @param length      The number of bytes to receive.
 *
 * @return None.
 */
void xmock_bluetooth_receive(XMockBluetooth *bluetooth, uint8_t *rx_buffer, uint32_t length) {
    // Simulate Bluetooth reception (replace with actual Bluetooth receive logic)
    printf("Bluetooth Receive on Bluetooth %d\n", bluetooth->bluetooth_id);
} // end of func

/**
 * @brief Initializes an XMockModbus (Modbus Peripheral) instance.
 *
 * This function initializes the attributes of an XMockModbus instance, including its ID and
 * baud rate for Modbus communication. These attributes simulate the configuration of a
 * Modbus peripheral for testing and simulation purposes.
 *
 * @param modbus    Pointer to the XMockModbus instance to initialize.
 * @param id        The Modbus peripheral's unique identifier.
 * @param baud_rate The baud rate in bits per second for Modbus communication.
 *
 * @return None.
 */
void xmock_modbus_init(XMockModbus *modbus, uint8_t id, uint32_t baud_rate) {
    modbus->modbus_id = id;
    modbus->baud_rate = baud_rate;
} // end of func

/**
 * @brief Performs a Modbus transmission using the XMockModbus (Modbus Peripheral).
 *
 * This function simulates a Modbus transmission using the specified XMockModbus peripheral. In
 * a real application, this function would perform the actual Modbus transmission. For demonstration,
 * it prints a message indicating the Modbus transmission on the specified Modbus peripheral.
 *
 * @param modbus     Pointer to the XMockModbus instance to use for the transmission.
 * @param tx_buffer  Pointer to the transmit (TX) buffer.
 * @param length     The number of bytes to transmit.
 *
 * @return None.
 */
void xmock_modbus_transmit(XMockModbus *modbus, uint8_t *tx_buffer, uint32_t length) {
    // Simulate Modbus transmission (replace with actual Modbus transmit logic)
    printf("Modbus Transmit on Modbus %d\n", modbus->modbus_id);
} // end of func

/**
 * @brief Performs a Modbus reception using the XMockModbus (Modbus Peripheral).
 *
 * This function simulates a Modbus reception using the specified XMockModbus peripheral. In a
 * real application, this function would perform the actual Modbus reception. For demonstration,
 * it prints a message indicating the Modbus reception on the specified Modbus peripheral.
 *
 * @param modbus     Pointer to the XMockModbus instance to use for the reception.
 * @param rx_buffer  Pointer to the receive (RX) buffer to store the received data.
 * @param length     The number of bytes to receive.
 *
 * @return None.
 */
void xmock_modbus_receive(XMockModbus *modbus, uint8_t *rx_buffer, uint32_t length) {
    // Simulate Modbus reception (replace with actual Modbus receive logic)
    printf("Modbus Receive on Modbus %d\n", modbus->modbus_id);
} // end of func

/**
 * @brief Initializes an XMockI2C (I2C Peripheral) instance.
 *
 * This function initializes the attributes of an XMockI2C instance, including its ID, I2C speed,
 * device address, transfer direction, repeated start condition, and acknowledge setting. These
 * attributes simulate the configuration of an I2C peripheral for testing and simulation purposes.
 *
 * @param i2c      Pointer to the XMockI2C instance to initialize.
 * @param id       The I2C peripheral's unique identifier.
 * @param speed    The I2C speed or frequency.
 * @param address  The I2C device address.
 * @param dir      The transfer direction (0 for write, 1 for read).
 * @param start    The repeated start condition (0 or 1).
 * @param ack      The acknowledge setting (0 or 1).
 *
 * @return None.
 */
void xmock_i2c_init(XMockI2C *i2c, uint8_t id, uint32_t speed, uint8_t address, uint8_t dir, uint8_t start, uint8_t ack) {
    i2c->i2c_id = id;
    i2c->i2c_speed = speed;
    i2c->device_address = address;
    i2c->transfer_dir = dir;
    i2c->repeated_start = start;
    i2c->acknowledge = ack;
} // end of func

/**
 * @brief Performs an I2C write operation using the XMockI2C (I2C Peripheral).
 *
 * This function simulates an I2C write operation using the specified XMockI2C peripheral. In a real
 * application, this function would perform the actual I2C write operation. For demonstration, it
 * prints a message indicating the I2C write operation on the specified I2C peripheral.
 *
 * @param i2c            Pointer to the XMockI2C instance to use for the write operation.
 * @param device_address The device address to write to.
 * @param data           Pointer to the data to write.
 * @param length         The number of bytes to write.
 *
 * @return None.
 */
void xmock_i2c_write(XMockI2C *i2c, uint8_t device_address, uint8_t *data, uint32_t length) {
    // Simulate I2C write (replace with actual I2C write logic)
    printf("I2C Write on I2C %d\n", i2c->i2c_id);
} // end of func

/**
 * @brief Performs an I2C read operation using the XMockI2C (I2C Peripheral).
 *
 * This function simulates an I2C read operation using the specified XMockI2C peripheral. In a real
 * application, this function would perform the actual I2C read operation. For demonstration, it
 * prints a message indicating the I2C read operation on the specified I2C peripheral.
 *
 * @param i2c            Pointer to the XMockI2C instance to use for the read operation.
 * @param device_address The device address to read from.
 * @param data           Pointer to the data buffer to store the read data.
 * @param length         The number of bytes to read.
 *
 * @return None.
 */
void xmock_i2c_read(XMockI2C *i2c, uint8_t device_address, uint8_t *data, uint32_t length) {
    // Simulate I2C read (replace with actual I2C read logic)
    printf("I2C Read on I2C %d\n", i2c->i2c_id);
} // end of func

/**
 * @brief Initializes an XMockSPI (SPI Peripheral) instance.
 *
 * This function initializes the attributes of an XMockSPI instance, including its ID, mode,
 * clock speed, data order, chip select, data bits, and duplex mode. These attributes simulate
 * the configuration of an SPI peripheral for testing and simulation purposes.
 *
 * @param spi     Pointer to the XMockSPI instance to initialize.
 * @param id      The SPI peripheral's unique identifier.
 * @param mode    The SPI mode (0, 1, 2, or 3).
 * @param speed   The clock speed in Hz.
 * @param order   The data order (0 for MSB first, 1 for LSB first).
 * @param cs      The chip select state (0 or 1).
 * @param bits    The number of data bits (e.g., 8 bits).
 * @param duplex  The duplex mode (full or half).
 *
 * @return None.
 */
void xmock_spi_init(XMockSPI *spi, uint8_t id, uint8_t mode, uint32_t speed, uint8_t order, uint8_t cs, uint8_t bits, uint8_t duplex) {
    spi->spi_id = id;
    spi->spi_mode = mode;
    spi->clock_speed = speed;
    spi->data_order = order;
    spi->chip_select = cs;
    spi->data_bits = bits;
    spi->duplex_mode = duplex;
} // end of func

/**
 * @brief Performs a data transfer using the XMockSPI (SPI Peripheral).
 *
 * This function simulates a data transfer using the specified XMockSPI peripheral. In a real
 * application, this function would perform the actual SPI data transfer. For demonstration,
 * it prints a message indicating the SPI transfer on the specified SPI peripheral.
 *
 * @param spi         Pointer to the XMockSPI instance to use for the transfer.
 * @param tx_buffer   Pointer to the transmit (TX) buffer.
 * @param rx_buffer   Pointer to the receive (RX) buffer.
 * @param length      The number of bytes to transfer.
 *
 * @return None.
 */
void xmock_spi_transfer(XMockSPI *spi, uint8_t *tx_buffer, uint8_t *rx_buffer, uint32_t length) {
    // Simulate SPI transfer (replace with actual SPI transfer logic)
    printf("SPI Transfer on SPI %d\n", spi->spi_id);
} // end of func

/**
 * @brief Initializes an XMockBattery instance.
 *
 * This function initializes the attributes of an XMockBattery instance, including its ID, voltage, capacity,
 * and charging status. These attributes simulate the characteristics of a battery for testing and
 * simulation purposes.
 *
 * @param battery   Pointer to the XMockBattery instance to initialize.
 * @param id        The battery's unique identifier.
 * @param voltage   The initial voltage of the battery.
 * @param capacity  The capacity of the battery.
 *
 * @return None.
 */
void xmock_battery_init(XMockBattery *battery, uint8_t id, float voltage, float capacity) {
    battery->battery_id = id;
    battery->voltage = voltage;
    battery->current = 0.0f; // Initialize current to 0
    battery->capacity = capacity;
    battery->charging = 0; // Not charging by default
} // end of func

/**
 * @brief Sets the current for the battery (simulate power consumption or charging).
 *
 * This function simulates setting the current for the battery. A positive current value represents
 * charging, while a negative current value represents power consumption or discharging.
 *
 * @param battery   Pointer to the XMockBattery instance.
 * @param current   The current to set for the battery.
 *
 * @return None.
 */
void xmock_battery_set_current(XMockBattery *battery, float current) {
    battery->current = current;
} // end of func

/**
 * @brief Gets the voltage of the battery.
 *
 * This function returns the voltage of the battery, which is a measure of its electrical potential.
 *
 * @param battery   Pointer to the XMockBattery instance.
 *
 * @return The voltage of the battery.
 */
float xmock_battery_get_voltage(XMockBattery *battery) {
    return battery->voltage;
} // end of func

/**
 * @brief Gets the current of the battery.
 *
 * This function returns the current of the battery, which represents its charging or discharging rate.
 *
 * @param battery   Pointer to the XMockBattery instance.
 *
 * @return The current of the battery.
 */
float xmock_battery_get_current(XMockBattery *battery) {
    return battery->current;
} // end of func

/**
 * @brief Gets the capacity of the battery.
 *
 * This function returns the capacity of the battery, which is the total amount of charge it can store.
 *
 * @param battery   Pointer to the XMockBattery instance.
 *
 * @return The capacity of the battery.
 */
float xmock_battery_get_capacity(XMockBattery *battery) {
    return battery->capacity;
} // end of func

/**
 * @brief Sets the charging status of the battery.
 *
 * This function simulates setting the charging status of the battery. If 'is_charging' is non-zero (true),
 * it indicates that the battery is currently charging; otherwise, it's not charging.
 *
 * @param battery       Pointer to the XMockBattery instance.
 * @param is_charging   A flag indicating whether the battery is charging (1) or not (0).
 *
 * @return None.
 */
void xmock_battery_set_charging(XMockBattery *battery, int is_charging) {
    battery->charging = is_charging;
} // end of func
