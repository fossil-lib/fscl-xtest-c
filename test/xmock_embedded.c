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
XTEST_DATA(TestHardware) {
    XMockActuator actuator;
    XMockSensor sensor;
    XMockMotor motor;
} hardware; // end of mock hardware

XTEST_DATA(TestHardwareRapPi) {
    XMockRaspberryPiGPIO gpio;
} raspi_controller; // end of mock hardware

XTEST_DATA(TestHardwareSTMicro) {
    XMockStMicroGPIO gpio;
} stm_controller; // end of mock hardware

XTEST_DATA(TestHardwareArduino) {
    XMockArduinoUnoGPIO gpio;
} uno_controller; // end of mock hardware

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_hardware_fixture);
XTEST_SETUP(xmockup_hardware_fixture) {
    // empty
} // end setup

XTEST_TEARDOWN(xmockup_hardware_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_sensor_init) {
    xmock_sensor_init(&hardware.sensor, 1);
    XASSERT_UINT8_EQUAL(1, hardware.sensor.sensor_id);
    XASSERT_FLOAT_WITHIN(0.001, 0.0, hardware.sensor.value);
}

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_sensor_read) {
    xmock_sensor_init(&hardware.sensor, 2);

    float initial_value = xmock_sensor_read(&hardware.sensor);
    float second_reading = xmock_sensor_read(&hardware.sensor);

    XASSERT_UINT8_EQUAL(2, hardware.sensor.sensor_id);
    XASSERT_FLOAT_WITHIN(0.001, 0.0, initial_value);
    XASSERT_FLOAT_WITHIN(0.001, 0.1, second_reading);
}

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_motor_init) {
    xmock_motor_init(&hardware.motor, 3);
    XASSERT_UINT8_EQUAL(3, hardware.motor.motor_id);
    XASSERT_INT_EQUAL(0, hardware.motor.speed);
}

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_motor_set_speed) {
    xmock_motor_init(&hardware.motor, 4);
    xmock_motor_set_speed(&hardware.motor, 100);
    XASSERT_UINT8_EQUAL(4, hardware.motor.motor_id);
    XASSERT_INT_EQUAL(100, hardware.motor.speed);
}

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_actuator_init) {
    xmock_actuator_init(&hardware.actuator, 5);
    XASSERT_UINT8_EQUAL(5, hardware.actuator.actuator_id);
    XASSERT_INT_EQUAL(0, hardware.actuator.state);
}

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_actuator_turn_on_off) {
    xmock_actuator_init(&hardware.actuator, 6);

    xmock_actuator_turn_on(&hardware.actuator);
    XASSERT_UINT8_EQUAL(6, hardware.actuator.actuator_id);
    XASSERT_INT_EQUAL(1, hardware.actuator.state);

    xmock_actuator_turn_off(&hardware.actuator);
    XASSERT_UINT8_EQUAL(6, hardware.actuator.actuator_id);
    XASSERT_INT_EQUAL(0, hardware.actuator.state);
}

//
// Micro Controller mock testing
//
// Testing micro controllers for use in embedded testing on things like
// Rasperry Pi, STMicro, Arduino, and much more
//

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_raspi3_fixture);
XTEST_SETUP(xmockup_raspi3_fixture) {
    raspi_controller.gpio = XMOCK_GPIO_PI3;
} // end setup

XTEST_TEARDOWN(xmockup_raspi3_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_raspi3_fixture, xmock_raspi3_init_pin) {
    uint32_t gpio_pin = 17;
    xmock_raspi_gpio_init_output(raspi_controller.gpio, gpio_pin);
    
    XASSERT_HEX_EQUAL(0x00000400, raspi_controller.gpio->GPFSEL[1]); // Assuming Pin 17 is in GPFSEL1
} // end of case

XTEST_CASE_FIXTURE(xmockup_raspi3_fixture, xmock_raspi3_set_pin) {
    uint32_t gpio_pin = 17;
    
    xmock_raspi_gpio_set_state(raspi_controller.gpio, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, raspi_controller.gpio->GPSET[0]); // Assuming Pin 17 is in GPSET0

    xmock_raspi_gpio_set_state(raspi_controller.gpio, gpio_pin, 0);
    XASSERT_HEX_EQUAL(1 << gpio_pin, raspi_controller.gpio->GPCLR[0]); // Assuming Pin 17 is in GPCLR0
} // end of case

XTEST_CASE_FIXTURE(xmockup_raspi3_fixture, xmock_raspi3_read_pin) {
    uint32_t gpio_pin = 17;
    
    raspi_controller.gpio->GPLEV[0] = 0; // Clear all bits
    uint32_t state = xmock_raspi_gpio_read_state(raspi_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(0, state);

    raspi_controller.gpio->GPLEV[0] = 1 << gpio_pin; // Set the bit corresponding to Pin 17
    state = xmock_raspi_gpio_read_state(raspi_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_raspi4_fixture);
XTEST_SETUP(xmockup_raspi4_fixture) {
    raspi_controller.gpio = XMOCK_GPIO_PI4;
} // end setup

XTEST_TEARDOWN(xmockup_raspi4_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_raspi4_fixture, xmock_raspi4_init_pin) {
    uint32_t gpio_pin = 17;
    xmock_raspi_gpio_init_output(raspi_controller.gpio, gpio_pin);
    
    XASSERT_HEX_EQUAL(0x00000400, raspi_controller.gpio->GPFSEL[1]); // Assuming Pin 17 is in GPFSEL1
} // end of case

XTEST_CASE_FIXTURE(xmockup_raspi4_fixture, xmock_raspi4_set_pin) {
    uint32_t gpio_pin = 17;
    
    xmock_raspi_gpio_set_state(raspi_controller.gpio, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, raspi_controller.gpio->GPSET[0]); // Assuming Pin 17 is in GPSET0

    xmock_raspi_gpio_set_state(raspi_controller.gpio, gpio_pin, 0);
    XASSERT_HEX_EQUAL(1 << gpio_pin, raspi_controller.gpio->GPCLR[0]); // Assuming Pin 17 is in GPCLR0
} // end of case

XTEST_CASE_FIXTURE(xmockup_raspi4_fixture, xmock_raspi4_read_pin) {
    uint32_t gpio_pin = 17;
    
    raspi_controller.gpio->GPLEV[0] = 0; // Clear all bits
    uint32_t state = xmock_raspi_gpio_read_state(raspi_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(0, state);

    raspi_controller.gpio->GPLEV[0] = 1 << gpio_pin; // Set the bit corresponding to Pin 17
    state = xmock_raspi_gpio_read_state(raspi_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_raspiz_fixture);
XTEST_SETUP(xmockup_raspiz_fixture) {
    raspi_controller.gpio = XMOCK_GPIO_ZERO;
} // end setup

XTEST_TEARDOWN(xmockup_raspiz_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_raspiz_fixture, xmock_raspiz_init_pin) {
    uint32_t gpio_pin = 17;
    xmock_raspi_gpio_init_output(raspi_controller.gpio, gpio_pin);
    
    XASSERT_HEX_EQUAL(0x00000400, raspi_controller.gpio->GPFSEL[1]); // Assuming Pin 17 is in GPFSEL1
} // end of case

XTEST_CASE_FIXTURE(xmockup_raspiz_fixture, xmock_raspiz_set_pin) {
    uint32_t gpio_pin = 17;
    
    xmock_raspi_gpio_set_state(raspi_controller.gpio, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, raspi_controller.gpio->GPSET[0]); // Assuming Pin 17 is in GPSET0

    xmock_raspi_gpio_set_state(raspi_controller.gpio, gpio_pin, 0);
    XASSERT_HEX_EQUAL(1 << gpio_pin, raspi_controller.gpio->GPCLR[0]); // Assuming Pin 17 is in GPCLR0
} // end of case

XTEST_CASE_FIXTURE(xmockup_raspiz_fixture, xmock_raspiz_read_pin) {
    uint32_t gpio_pin = 17;
    
    raspi_controller.gpio->GPLEV[0] = 0; // Clear all bits
    uint32_t state = xmock_raspi_gpio_read_state(raspi_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(0, state);

    raspi_controller.gpio->GPLEV[0] = 1 << gpio_pin; // Set the bit corresponding to Pin 17
    state = xmock_raspi_gpio_read_state(raspi_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_stma_fixture);
XTEST_SETUP(xmockup_stma_fixture) {
    stm_controller.gpio = XMOCK_GPIOA_DISCOVERY;
} // end setup

XTEST_TEARDOWN(xmockup_stma_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_stma_fixture, xmock_stma_init_pin) {
    uint32_t gpio_pin = 5;
    xmock_stm32_gpio_init_output(stm_controller.gpio, gpio_pin);
    
    XASSERT_HEX_EQUAL(1 << (gpio_pin * 2), stm_controller.gpio->MODER);
} // end of case

XTEST_CASE_FIXTURE(xmockup_stma_fixture, xmock_stma_set_pin) {
    uint32_t gpio_pin = 5;
    
    xmock_stm32_gpio_set_state(stm_controller.gpio, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, stm_controller.gpio->BSRR);

    xmock_stm32_gpio_set_state(stm_controller.gpio, gpio_pin, 0);
    XASSERT_HEX_EQUAL(1 << (gpio_pin + 16), stm_controller.gpio->BSRR);
} // end of case

XTEST_CASE_FIXTURE(xmockup_stma_fixture, xmock_stma_read_pin) {
    uint32_t gpio_pin = 5;
    
    stm_controller.gpio->IDR = 0; // Clear all bits
    uint32_t state = xmock_stm32_gpio_read_state(stm_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(0, state);

    stm_controller.gpio->IDR = 1 << gpio_pin; // Set the bit corresponding to Pin 5
    state = xmock_stm32_gpio_read_state(stm_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_stmb_fixture);
XTEST_SETUP(xmockup_stmb_fixture) {
    stm_controller.gpio = XMOCK_GPIOB_DISCOVERY;
} // end setup

XTEST_TEARDOWN(xmockup_stmb_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_stmb_fixture, xmock_stmb_init_pin) {
    uint32_t gpio_pin = 5;
    xmock_stm32_gpio_init_output(stm_controller.gpio, gpio_pin);
    
    XASSERT_HEX_EQUAL(1 << (gpio_pin * 2), stm_controller.gpio->MODER);
} // end of case

XTEST_CASE_FIXTURE(xmockup_stmb_fixture, xmock_stmb_set_pin) {
    uint32_t gpio_pin = 5;
    
    xmock_stm32_gpio_set_state(stm_controller.gpio, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, stm_controller.gpio->BSRR);

    xmock_stm32_gpio_set_state(stm_controller.gpio, gpio_pin, 0);
    XASSERT_HEX_EQUAL(1 << (gpio_pin + 16), stm_controller.gpio->BSRR);
} // end of case

XTEST_CASE_FIXTURE(xmockup_stmb_fixture, xmock_stmb_read_pin) {
    uint32_t gpio_pin = 5;
    
    stm_controller.gpio->IDR = 0; // Clear all bits
    uint32_t state = xmock_stm32_gpio_read_state(stm_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(0, state);

    stm_controller.gpio->IDR = 1 << gpio_pin; // Set the bit corresponding to Pin 5
    state = xmock_stm32_gpio_read_state(stm_controller.gpio, gpio_pin);
    XASSERT_UINT32_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_uno_portb_fixture);
XTEST_SETUP(xmockup_uno_portb_fixture) {
    uno_controller.gpio = XMOCK_GPIO_UNO_PORTB;
} // end setup

XTEST_TEARDOWN(xmockup_uno_portb_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_uno_portb_fixture, xmock_uno_portb_init_pin) {
    uint8_t gpio_pin = 13;
    xmock_arduino_uno_gpio_init_output(XMOCK_GPIO_UNO_PORTB, gpio_pin);
    
    XASSERT_HEX_EQUAL(1 << gpio_pin, XMOCK_GPIO_UNO_PORTB->DDRB);
} // end of case

XTEST_CASE_FIXTURE(xmockup_uno_portb_fixture, xmock_uno_portb_set_pin) {
    uint8_t gpio_pin = 13;
    
    xmock_arduino_uno_gpio_set_state(XMOCK_GPIO_UNO_PORTB, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, XMOCK_GPIO_UNO_PORTB->PORTB);

    xmock_arduino_uno_gpio_set_state(XMOCK_GPIO_UNO_PORTB, gpio_pin, 0);
    XASSERT_HEX_EQUAL(0, XMOCK_GPIO_UNO_PORTB->PORTB);
} // end of case

XTEST_CASE_FIXTURE(xmockup_uno_portb_fixture, xmock_uno_portb_read_pin) {
    uint8_t gpio_pin = 13;
    
    XMOCK_GPIO_UNO_PORTB->PINB = 0; // Clear all bits
    uint8_t state = xmock_arduino_uno_gpio_read_state(XMOCK_GPIO_UNO_PORTB, gpio_pin);
    XASSERT_UINT8_EQUAL(0, state);

    XMOCK_GPIO_UNO_PORTB->PINB = 1 << gpio_pin; // Set the bit corresponding to Pin 13
    state = xmock_arduino_uno_gpio_read_state(XMOCK_GPIO_UNO_PORTB, gpio_pin);
    XASSERT_UINT8_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_uno_portc_fixture);
XTEST_SETUP(xmockup_uno_portc_fixture) {
    uno_controller.gpio = XMOCK_GPIO_UNO_PORTC;
} // end setup

XTEST_TEARDOWN(xmockup_uno_portc_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_uno_portc_fixture, xmock_uno_portc_init_pin) {
    uint8_t gpio_pin = 13;
    xmock_arduino_uno_gpio_init_output(XMOCK_GPIO_UNO_PORTC, gpio_pin);
    
    XASSERT_HEX_EQUAL(1 << gpio_pin, XMOCK_GPIO_UNO_PORTC->DDRC);
} // end of case

XTEST_CASE_FIXTURE(xmockup_uno_portc_fixture, xmock_uno_portc_set_pin) {
    uint8_t gpio_pin = 13;
    
    xmock_arduino_uno_gpio_set_state(XMOCK_GPIO_UNO_PORTC, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, XMOCK_GPIO_UNO_PORTC->PORTC);

    xmock_arduino_uno_gpio_set_state(XMOCK_GPIO_UNO_PORTC, gpio_pin, 0);
    XASSERT_HEX_EQUAL(0, XMOCK_GPIO_UNO_PORTC->PORTC);
} // end of case

XTEST_CASE_FIXTURE(xmockup_uno_portc_fixture, xmock_uno_portc_read_pin) {
    uint8_t gpio_pin = 13;
    
    XMOCK_GPIO_UNO_PORTC->PINC = 0; // Clear all bits
    uint8_t state = xmock_arduino_uno_gpio_read_state(XMOCK_GPIO_UNO_PORTC, gpio_pin);
    XASSERT_UINT8_EQUAL(0, state);

    XMOCK_GPIO_UNO_PORTC->PINC = 1 << gpio_pin; // Set the bit corresponding to Pin 13
    state = xmock_arduino_uno_gpio_read_state(XMOCK_GPIO_UNO_PORTC, gpio_pin);
    XASSERT_UINT8_EQUAL(1, state);
} // end of case

//
// TEST FIXTURE
//
XTEST_FIXTURE(xmockup_uno_portd_fixture);
XTEST_SETUP(xmockup_uno_portd_fixture) {
    uno_controller.gpio = XMOCK_GPIO_UNO_PORTD;
} // end setup

XTEST_TEARDOWN(xmockup_uno_portd_fixture) {
    // empty
} // end teardown

//
// TEST CASES
//
XTEST_CASE_FIXTURE(xmockup_uno_portd_fixture, xmock_uno_portd_init_pin) {
    uint8_t gpio_pin = 13;
    xmock_arduino_uno_gpio_init_output(XMOCK_GPIO_UNO_PORTD, gpio_pin);
    
    XASSERT_HEX_EQUAL(1 << gpio_pin, XMOCK_GPIO_UNO_PORTD->DDRD);
} // end of case

XTEST_CASE_FIXTURE(xmockup_uno_portd_fixture, xmock_uno_portd_set_pin) {
    uint8_t gpio_pin = 13;
    
    xmock_arduino_uno_gpio_set_state(XMOCK_GPIO_UNO_PORTD, gpio_pin, 1);
    XASSERT_HEX_EQUAL(1 << gpio_pin, XMOCK_GPIO_UNO_PORTD->PORTD);

    xmock_arduino_uno_gpio_set_state(XMOCK_GPIO_UNO_PORTD, gpio_pin, 0);
    XASSERT_HEX_EQUAL(0, XMOCK_GPIO_UNO_PORTD->PORTD);
} // end of case

XTEST_CASE_FIXTURE(xmockup_uno_portd_fixture, xmock_uno_portd_read_pin) {
    uint8_t gpio_pin = 13;
    
    XMOCK_GPIO_UNO_PORTD->PIND = 0; // Clear all bits
    uint8_t state = xmock_arduino_uno_gpio_read_state(XMOCK_GPIO_UNO_PORTD, gpio_pin);
    XASSERT_UINT8_EQUAL(0, state);

    XMOCK_GPIO_UNO_PORTD->PIND = 1 << gpio_pin; // Set the bit corresponding to Pin 13
    state = xmock_arduino_uno_gpio_read_state(XMOCK_GPIO_UNO_PORTD, gpio_pin);
    XASSERT_UINT8_EQUAL(1, state);
} // end of case

//
// XTEST FIXTURE
//
void xmockup_hardware_group(XUnitRunner *runner) {
    xtest_run_test_fixture(&xmock_hardware_sensor_init,          &xmockup_hardware_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_hardware_sensor_read,          &xmockup_hardware_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_hardware_motor_init,           &xmockup_hardware_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_hardware_motor_set_speed,      &xmockup_hardware_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_hardware_actuator_init,        &xmockup_hardware_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_hardware_actuator_turn_on_off, &xmockup_hardware_fixture, &runner->stats);

    xtest_run_test_fixture(&xmock_raspi3_init_pin,    &xmockup_raspi3_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspi3_read_pin,    &xmockup_raspi3_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspi3_set_pin,     &xmockup_raspi3_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspi4_init_pin,    &xmockup_raspi4_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspi4_read_pin,    &xmockup_raspi4_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspi4_set_pin,     &xmockup_raspi4_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspiz_init_pin,    &xmockup_raspiz_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspiz_read_pin,    &xmockup_raspiz_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_raspiz_set_pin,     &xmockup_raspiz_fixture, &runner->stats);

    xtest_run_test_fixture(&xmock_stma_init_pin,      &xmockup_stma_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stma_read_pin,      &xmockup_stma_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stma_set_pin,       &xmockup_stma_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stmb_init_pin,      &xmockup_stmb_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stmb_read_pin,      &xmockup_stmb_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_stmb_set_pin,       &xmockup_stmb_fixture, &runner->stats);

    xtest_run_test_fixture(&xmock_uno_portb_init_pin, &xmockup_uno_portb_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portb_read_pin, &xmockup_uno_portb_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portb_set_pin,  &xmockup_uno_portb_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portc_init_pin, &xmockup_uno_portc_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portc_read_pin, &xmockup_uno_portc_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portc_set_pin,  &xmockup_uno_portc_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portd_init_pin, &xmockup_uno_portd_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portd_read_pin, &xmockup_uno_portd_fixture, &runner->stats);
    xtest_run_test_fixture(&xmock_uno_portd_set_pin,  &xmockup_uno_portd_fixture, &runner->stats);
} // end of fixture
