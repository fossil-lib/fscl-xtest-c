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

 // Define platform-specific macros
#ifdef _WIN32
    #define TRILOBITE_XMOCK_EXPORT __declspec(dllexport)
    #define TRILOBITE_XMOCK_IMPORT __declspec(dllimport)
#else
    #define TRILOBITE_XMOCK_EXPORT __attribute__((visibility("default")))
    #define TRILOBITE_XMOCK_IMPORT
#endif

// Define the MY_MOCK_FRAMEWORK_API macro
#ifdef TRILOBITE_XMOCK_SHARED
    #ifdef TRILOBITE_XMOCK_BUILD
        #define XMOCK_API TRILOBITE_XTEST_EXPORT
    #else
        #define XMOCK_API TRILOBITE_XTEST_IMPORT
    #endif
#else
    #define XMOCK_API
#endif

#ifdef __cplusplus
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cmath>
#else
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#endif

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
XMOCK_API XMockStack* xmock_stack_create(int capacity);

// Push an element onto the mock stack
// @param stack: Pointer to the stack
// @param element: Element to be pushed onto the stack
XMOCK_API void xmock_stack_push(XMockStack* stack, int element);

// Pop an element from the mock stack
// @param stack: Pointer to the stack
// @return: The popped element
XMOCK_API int xmock_stack_pop(XMockStack* stack);

// Get the size of the mock stack
// @param stack: Pointer to the stack
// @return: Current size of the stack
XMOCK_API int xmock_stack_size(XMockStack* stack);

// Destroy the mock stack and release resources
// @param stack: Pointer to the stack to be destroyed
XMOCK_API void xmock_stack_destroy(XMockStack* stack);


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
XMOCK_API XMockDoublyLinkedList* xmock_doubly_linked_list_create();

// @brief Insert an element at the beginning of the list.
// @param list The mock doubly linked list to which the element will be added.
// @param data The data to insert.
XMOCK_API void xmock_doubly_linked_list_push_front(XMockDoublyLinkedList* list, int data);

// @brief Insert an element at the end of the list.
// @param list The mock doubly linked list to which the element will be added.
// @param data The data to insert.
XMOCK_API void xmock_doubly_linked_list_push_back(XMockDoublyLinkedList* list, int data);

// @brief Remove and return the first element of the list.
// @param list The mock doubly linked list from which the first element will be removed.
// @return The value of the first element or 0 if the list is empty.
XMOCK_API int xmock_doubly_linked_list_pop_front(XMockDoublyLinkedList* list);

// @brief Remove and return the last element of the list.
// @param list The mock doubly linked list from which the last element will be removed.
// @return The value of the last element or 0 if the list is empty.
XMOCK_API int xmock_doubly_linked_list_pop_back(XMockDoublyLinkedList* list);

// @brief Get the size of the list.
// @param list The mock doubly linked list for which to determine the size.
// @return The current size of the list.
XMOCK_API int xmock_doubly_linked_list_size(XMockDoublyLinkedList* list);

// @brief Destroy the mock doubly linked list and release allocated resources.
// @param list The mock doubly linked list to destroy.
XMOCK_API void xmock_doubly_linked_list_destroy(XMockDoublyLinkedList* list);


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
XMOCK_API XMockQueue* xmock_queue_create(int capacity);

// @brief Enqueue an element into the mock queue.
// @param queue The mock queue to which the element will be enqueued.
// @param element The element to be enqueued.
XMOCK_API void xmock_queue_enqueue(XMockQueue* queue, int element);

// @brief Dequeue and return the front element of the mock queue.
// @param queue The mock queue from which the front element will be dequeued.
// @return The front element of the queue or 0 if the queue is empty.
XMOCK_API int xmock_queue_dequeue(XMockQueue* queue);

// @brief Get the size of the mock queue.
// @param queue The mock queue for which to determine the size.
// @return The current size of the queue.
XMOCK_API int xmock_queue_size(XMockQueue* queue);

// @brief Destroy the mock queue and release allocated resources.
// @param queue The mock queue to destroy.
XMOCK_API void xmock_queue_destroy(XMockQueue* queue);



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
XMOCK_API XMockMap* xmock_map_create();

// @brief Put a key-value pair into the mock map.
// @param map The mock map to which the entry will be added.
// @param key The key of the entry to add.
// @param value The value associated with the key.
XMOCK_API void xmock_map_put(XMockMap* map, int key, int value);

// @brief Get the value associated with a key from the mock map.
// @param map The mock map to search for the key.
// @param key The key to look up in the map.
// @return The value associated with the key or 0 if the key is not found.
XMOCK_API int xmock_map_get(XMockMap* map, int key);

// @brief Check if a key exists in the mock map.
// @param map The mock map to check for the key.
// @param key The key to check for existence.
// @return 1 if the key exists in the map, 0 otherwise.
XMOCK_API int xmock_map_contains(XMockMap* map, int key);

// @brief Remove a key-value pair from the mock map.
// @param map The mock map from which the entry will be removed.
// @param key The key of the entry to remove.
XMOCK_API void xmock_map_remove(XMockMap* map, int key);

// @brief Get the number of key-value pairs in the mock map.
// @param map The mock map for which to count the entries.
// @return The number of key-value pairs in the map.
XMOCK_API int xmock_map_size(XMockMap* map);

// @brief Destroy the mock map and release allocated resources.
// @param map The mock map to destroy.
XMOCK_API void xmock_map_destroy(XMockMap* map);


/**
 * @brief Mock Hardware Emulation Structures
 *
 * These structures, namely XMockSensor, XMockMotor, and XMockActuator, are designed
 * to emulate the behavior of various hardware components in a simulated environment.
 * They serve as placeholders for representing sensors, motors, and actuators, allowing
 * developers to create, manipulate, and interact with these virtual hardware components
 * for testing and simulation purposes.
 *
 * XMockSensor:
 *   - Represents a simulated sensor.
 *   - Contains a sensor ID for unique identification and a floating-point value
 *     to mimic sensor readings.
 *
 * XMockMotor:
 *   - Represents a simulated motor.
 *   - Contains a motor ID for unique identification and an integer value to represent
 *     the motor's speed.
 *
 * XMockActuator:
 *   - Represents a simulated actuator.
 *   - Contains an actuator ID for unique identification and an integer state, which
 *     can be either 0 for OFF or 1 for ON, to mimic the actuator's status.
 *
 * These structures are intended for use in software testing, debugging, and simulation
 * scenarios, allowing developers to model and simulate interactions with hardware
 * components without the need for physical hardware. They can be customized and extended
 * to simulate various hardware behaviors and are particularly useful in scenarios where
 * real hardware is unavailable or costly to access.
 *
 * Usage:
 *   - Initialize these structures using the provided initialization functions.
 *   - Interact with the hardware mock components by setting or reading their values.
 *   - Simulate hardware actions such as starting or stopping motors or changing sensor
 *     readings using the provided functions.
 *   - Customize these structures and functions as needed to match specific hardware
 *     behaviors in your simulated environment.
 *
 * Note: These mock structures are not intended for use in production code and are
 * solely designed for testing and simulation purposes.
 */

/**
 * @brief Structure representing a sensor in a simulated environment.
 */
typedef struct {
    uint8_t sensor_id; ///< The sensor's unique identifier.
    float value;       ///< The sensor's value.
} XMockSensor;

/**
 * @brief Structure representing a motor in a simulated environment.
 */
typedef struct {
    uint8_t motor_id; ///< The motor's unique identifier.
    int speed;        ///< The motor's speed.
} XMockMotor;

/**
 * @brief Structure representing an actuator in a simulated environment.
 */
typedef struct {
    uint8_t actuator_id; ///< The actuator's unique identifier.
    int state;           ///< The actuator's state (0 for OFF, 1 for ON).
} XMockActuator;

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
XMOCK_API void xmock_sensor_init(XMockSensor *sensor, uint8_t id);

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
XMOCK_API float xmock_sensor_read(XMockSensor *sensor);

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
XMOCK_API void xmock_motor_init(XMockMotor *motor, uint8_t id);

/**
 * @brief Sets the speed of an XMockMotor.
 *
 * @param motor Pointer to the XMockMotor instance to set the speed for.
 * @param speed The desired speed to set.
 *
 * @return None.
 */
XMOCK_API void xmock_motor_set_speed(XMockMotor *motor, int speed);

/**
 * @brief Gets the current speed of an XMockMotor.
 *
 * @param motor Pointer to the XMockMotor instance to get the speed from.
 *
 * @return The current speed of the motor.
 */
XMOCK_API int xmock_motor_get_speed(XMockMotor *motor);

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
XMOCK_API void xmock_motor_start(XMockMotor *motor);

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
XMOCK_API void xmock_motor_stop(XMockMotor *motor);

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
XMOCK_API void xmock_actuator_init(XMockActuator *actuator, uint8_t id);

/**
 * @brief Turns on an XMockActuator.
 *
 * This function sets the state of the actuator to ON (1).
 *
 * @param actuator Pointer to the XMockActuator instance to turn on.
 *
 * @return None.
 */
XMOCK_API void xmock_actuator_turn_on(XMockActuator *actuator);

/**
 * @brief Turns off an XMockActuator.
 *
 * This function sets the state of the actuator to OFF (0).
 *
 * @param actuator Pointer to the XMockActuator instance to turn off.
 *
 * @return None.
 */
XMOCK_API void xmock_actuator_turn_off(XMockActuator *actuator);

/**
 * @brief Gets the current state of an XMockActuator.
 *
 * @param actuator Pointer to the XMockActuator instance to get the state from.
 *
 * @return The current state of the actuator (0 for OFF, 1 for ON).
 */
XMOCK_API int xmock_actuator_get_state(XMockActuator *actuator);

/**
 * @brief Mock Peripheral Emulation Structures
 *
 * These structures represent a range of mock peripheral types commonly found in microcontroller-based
 * systems. They are designed for use in simulated environments to mimic the behavior and configuration
 * of real hardware peripherals, enabling developers to test and prototype software without the need
 * for physical hardware. These mock peripheral types include UART, I2S, CAN, Bluetooth, Modbus, SPI,
 * and I2C, each with its own set of attributes to model specific functionality.
 *
 * XMockUART:
 *   - Represents a simulated UART (Universal Asynchronous Receiver-Transmitter) peripheral.
 *   - Includes attributes such as UART ID, baud rate, data bits, stop bits, and parity settings.
 *
 * XMockI2S:
 *   - Represents a simulated I2S (Inter-IC Sound) peripheral.
 *   - Contains attributes like I2S ID, sample rate, data format, and channel mode settings.
 *
 * XMockCAN:
 *   - Represents a simulated CAN (Controller Area Network) peripheral.
 *   - Includes attributes such as CAN ID and bitrate settings.
 *
 * XMockBluetooth:
 *   - Represents a simulated Bluetooth peripheral.
 *   - Contains attributes like Bluetooth ID to emulate Bluetooth device interactions.
 *
 * XMockModbus:
 *   - Represents a simulated Modbus peripheral.
 *   - Includes attributes such as Modbus ID and baud rate for Modbus communication.
 *
 * XMockSPI:
 *   - Represents a simulated SPI (Serial Peripheral Interface) peripheral.
 *   - Contains attributes like SPI ID, SPI mode, clock speed, data order, chip select,
 *     data bits, and duplex mode settings.
 *
 * XMockI2C:
 *   - Represents a simulated I2C (Inter-Integrated Circuit) peripheral.
 *   - Includes attributes like I2C ID, I2C speed, device address, transfer direction,
 *     repeated start condition, and acknowledge settings.
 *
 * These structures are intended for use in software testing, debugging, and simulation scenarios,
 * allowing developers to model and simulate interactions with a wide range of microcontroller
 * peripherals. By customizing and extending these structures, developers can create versatile
 * mock peripherals that closely resemble real hardware components in their virtual environments.
 *
 * Usage:
 *   - Initialize these structures using the provided initialization functions.
 *   - Configure and interact with the mock peripherals using their respective attributes.
 *   - Customize these structures to match specific peripheral behaviors in your simulated
 *     microcontroller environment.
 *
 * Note: These mock structures are not intended for use in production code and are solely
 * designed for testing and simulation purposes.
 */

// Mock UART Peripheral Structure
typedef struct {
    uint8_t uart_id;
    uint32_t baud_rate; // Baud rate in bits per second
    uint8_t data_bits;  // Number of data bits (e.g., 8 bits)
    uint8_t stop_bits;  // Number of stop bits (e.g., 1 stop bit)
    uint8_t parity;     // Parity setting (e.g., none, even, odd)
} XMockUART;

// Mock I2S Peripheral Structure
typedef struct {
    uint8_t i2s_id;
    uint32_t sample_rate; // Sample rate in Hz
    uint8_t data_format;  // Data format (e.g., I2S, PCM)
    uint8_t channel_mode; // Channel mode (e.g., stereo, mono)
} XMockI2S;

// Mock CAN Peripheral Structure
typedef struct {
    uint8_t can_id;
    uint32_t bitrate; // Bitrate in bits per second
} XMockCAN;

// Mock Bluetooth Peripheral Structure
typedef struct {
    uint8_t bluetooth_id;
} XMockBluetooth;

// Mock Modbus Peripheral Structure
typedef struct {
    uint8_t modbus_id;
    uint32_t baud_rate; // Baud rate in bits per second
} XMockModbus;

// Mock SPI Peripheral Structure
typedef struct {
    uint8_t spi_id;
    uint8_t spi_mode;       // SPI mode (0, 1, 2, or 3)
    uint32_t clock_speed;   // Clock speed in Hz
    uint8_t data_order;     // Data order (MSB first or LSB first)
    uint8_t chip_select;    // Chip select state (0 or 1)
    uint8_t data_bits;      // Number of data bits (e.g., 8 bits)
    uint8_t duplex_mode;    // Duplex mode (full or half)
} XMockSPI;

// Mock I2C Peripheral Structure
typedef struct {
    uint8_t i2c_id;
    uint32_t i2c_speed;      // I2C speed or frequency
    uint8_t device_address;  // I2C device address
    uint8_t transfer_dir;    // Transfer direction (read or write)
    uint8_t repeated_start;  // Repeated start condition (0 or 1)
    uint8_t acknowledge;     // Acknowledge setting (0 or 1)
} XMockI2C;

// Initialization function for mock peripheral
XMOCK_API void xmock_uart_init(XMockUART *uart, uint8_t id, uint32_t baud_rate, uint8_t data_bits, uint8_t stop_bits, uint8_t parity);
XMOCK_API void xmock_i2s_init(XMockI2S *i2s, uint8_t id, uint32_t sample_rate, uint8_t data_format, uint8_t channel_mode);
XMOCK_API void xmock_can_init(XMockCAN *can, uint8_t id, uint32_t bitrate);
XMOCK_API void xmock_bluetooth_init(XMockBluetooth *bluetooth, uint8_t id);
XMOCK_API void xmock_modbus_init(XMockModbus *modbus, uint8_t id, uint32_t baud_rate);
XMOCK_API void xmock_i2c_init(XMockI2C *i2c, uint8_t id, uint32_t speed, uint8_t address, uint8_t dir, uint8_t start, uint8_t ack);
XMOCK_API void xmock_spi_init(XMockSPI *spi, uint8_t id, uint8_t mode, uint32_t speed, uint8_t order, uint8_t cs, uint8_t bits, uint8_t duplex);

// Transmit function for mock peripheral
XMOCK_API void xmock_uart_transmit(XMockUART *uart, uint8_t *tx_buffer, uint32_t length);
XMOCK_API void xmock_i2s_transmit(XMockI2S *i2s, uint8_t *tx_buffer, uint32_t length);
XMOCK_API void xmock_can_transmit(XMockCAN *can, uint8_t *tx_buffer, uint32_t length);
XMOCK_API void xmock_bluetooth_transmit(XMockBluetooth *bluetooth, uint8_t *tx_buffer, uint32_t length);
XMOCK_API void xmock_modbus_transmit(XMockModbus *modbus, uint8_t *tx_buffer, uint32_t length);
XMOCK_API void xmock_i2c_write(XMockI2C *i2c, uint8_t device_address, uint8_t *data, uint32_t length);
XMOCK_API void xmock_spi_transfer(XMockSPI *spi, uint8_t *tx_buffer, uint8_t *rx_buffer, uint32_t length);

// Receive function for mock peripheral
XMOCK_API void xmock_uart_receive(XMockUART *uart, uint8_t *rx_buffer, uint32_t length);
XMOCK_API void xmock_can_receive(XMockCAN *can, uint8_t *rx_buffer, uint32_t length);
XMOCK_API void xmock_bluetooth_receive(XMockBluetooth *bluetooth, uint8_t *rx_buffer, uint32_t length);
XMOCK_API void xmock_modbus_receive(XMockModbus *modbus, uint8_t *rx_buffer, uint32_t length);
XMOCK_API void xmock_i2c_read(XMockI2C *i2c, uint8_t device_address, uint8_t *data, uint32_t length);


/**
 * @struct XMockBattery
 * @brief Represents a mock battery with voltage, current, capacity, and charging status.
 *
 * This structure simulates the behavior of a battery for testing and simulation purposes.
 *
 * @var XMockBattery::battery_id
 *   The unique identifier of the battery.
 * @var XMockBattery::voltage
 *   The voltage of the battery in volts.
 * @var XMockBattery::current
 *   The current of the battery in amperes (positive for charging, negative for discharging).
 * @var XMockBattery::capacity
 *   The capacity of the battery in ampere-hours.
 * @var XMockBattery::charging
 *   The charging status of the battery (0 for not charging, 1 for charging).
 */
typedef struct {
    uint8_t battery_id;
    float voltage;
    float current;
    float capacity;
    int charging;
} XMockBattery;

/**
 * @brief Initializes an XMockBattery instance with the provided parameters.
 *
 * This function sets up the initial state of an XMockBattery instance, including its ID, voltage,
 * capacity, and charging status.
 *
 * @param battery   Pointer to the XMockBattery instance to initialize.
 * @param id        The unique identifier of the battery.
 * @param voltage   The initial voltage of the battery in volts.
 * @param capacity  The capacity of the battery in ampere-hours.
 */
XMOCK_API void xmock_battery_init(XMockBattery *battery, uint8_t id, float voltage, float capacity);

/**
 * @brief Sets the current for the battery to simulate charging or discharging.
 *
 * This function allows you to set the current of the battery. A positive current value represents
 * charging, while a negative current value represents discharging (power consumption).
 *
 * @param battery   Pointer to the XMockBattery instance.
 * @param current   The current to set for the battery in amperes.
 */
XMOCK_API void xmock_battery_set_current(XMockBattery *battery, float current);

/**
 * @brief Gets the voltage of the battery.
 *
 * This function returns the current voltage of the battery, which is a measure of its electrical
 * potential in volts.
 *
 * @param battery   Pointer to the XMockBattery instance.
 * @return The voltage of the battery in volts.
 */
XMOCK_API float xmock_battery_get_voltage(XMockBattery *battery);

/**
 * @brief Gets the current of the battery.
 *
 * This function returns the current of the battery, which represents its charging (positive) or
 * discharging (negative) rate in amperes.
 *
 * @param battery   Pointer to the XMockBattery instance.
 * @return The current of the battery in amperes.
 */
XMOCK_API float xmock_battery_get_current(XMockBattery *battery);

/**
 * @brief Gets the capacity of the battery.
 *
 * This function returns the total capacity of the battery, which is the amount of charge it can
 * store in ampere-hours.
 *
 * @param battery   Pointer to the XMockBattery instance.
 * @return The capacity of the battery in ampere-hours.
 */
XMOCK_API float xmock_battery_get_capacity(XMockBattery *battery);

/**
 * @brief Sets the charging status of the battery.
 *
 * This function allows you to simulate the charging status of the battery. A value of 1 indicates
 * that the battery is charging, while 0 indicates that it is not charging.
 *
 * @param battery       Pointer to the XMockBattery instance.
 * @param is_charging   A flag indicating whether the battery is charging (1) or not (0).
 */
XMOCK_API void xmock_battery_set_charging(XMockBattery *battery, int is_charging);

#ifdef __cplusplus
}
#endif

#endif
