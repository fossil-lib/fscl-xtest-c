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
    XMockBattery battery;
} hardware; // end of mock hardware

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
    XASSERT_FLOAT_WITHIN(0.0, hardware.sensor.value, 1.1920929);
}

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_sensor_read) {
    xmock_sensor_init(&hardware.sensor, 2);

    float initial_value = xmock_sensor_read(&hardware.sensor);
    float second_reading = xmock_sensor_read(&hardware.sensor);

    XASSERT_UINT8_EQUAL(2, hardware.sensor.sensor_id);
    XASSERT_FLOAT_WITHIN(initial_value, 0.1, 0.001);
    XASSERT_FLOAT_WITHIN(second_reading, 0.2, 0.001);
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

XTEST_CASE_FIXTURE(xmockup_hardware_fixture, xmock_hardware_battery) {
    XMockBattery battery;
    xmock_battery_init(&battery, 1, 3.7f, 2000.0f); // Initialize a battery with 3.7V and 2000mAh capacity

    // Simulate discharging with a current of 100mA
    xmock_battery_set_current(&battery, -0.1f);

    // Check battery voltage and current
    XASSERT_FLOAT_EQUAL(3.7f, xmock_battery_get_voltage(&battery), 1.1920929);
    XASSERT_FLOAT_EQUAL(-0.1f, xmock_battery_get_current(&battery), 1.1920929);

    // Simulate charging with a current of 500mA
    xmock_battery_set_charging(&battery, 1);
    xmock_battery_set_current(&battery, 0.5f);

    // Check battery charging status and current
    XASSERT_INT_EQUAL(1, battery.charging);
    XASSERT_FLOAT_EQUAL(0.5f, xmock_battery_get_current(&battery), 1.1920929);
}

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
    xtest_run_test_fixture(&xmock_hardware_battery,              &xmockup_hardware_fixture, &runner->stats);
} // end of fixture
