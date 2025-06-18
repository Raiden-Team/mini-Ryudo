/**
 * @file service_rc.c
 *
 * @brief service for rc
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "service_rc.h"
#include "adapter_rc_receiver.h"
#include "adapter_motors.h"

/*****************************************
 * Public Defines
 *****************************************/

/*****************************************
 * Public Variables
 *****************************************/

/*****************************************
 * Private Variables
 *****************************************/

adapter_motors_type adapter_motors_rc = {
    .command_left = 0,
    .command_right = 0,
};

/*****************************************
 * Public Functions
 *****************************************/

void service_rc_init(void) {
    service_rc_reset();
}

void service_rc_reset(void) {
    // Init ADAPTER RC
    adapter_rc_receiver_init();

    // Set ADAPTER MOTORS
    adapter_motors_init();
    adapter_motors_rc.command_left = 0;
    adapter_motors_rc.command_right = 0;
}

void service_rc_run(void) {
    // Get PPM ADAPTER COMMAND
    int16_t command_left = adapter_rc_receiver_get_command_left();
    int16_t command_right = adapter_rc_receiver_get_command_right();

    // Set MOTORS ADAPTER COMMAND
    if (command_left < -20) {
        adapter_motors_rc.command_left = -command_left;
        adapter_motors_rc.direction_left = MOTOR_DIRECTION_BACKWARDS;
    } else if (command_left > 20) {
        adapter_motors_rc.command_left = command_left;
        adapter_motors_rc.direction_left = MOTOR_DIRECTION_FORWARD;
    } else {
        adapter_motors_rc.command_left = 0;
        adapter_motors_rc.direction_left = MOTOR_DIRECTION_FORWARD;
    }

    if (command_right < -20) {
        adapter_motors_rc.command_right = -command_right;
        adapter_motors_rc.direction_right = MOTOR_DIRECTION_BACKWARDS;
    } else if (command_right > 20) {
        adapter_motors_rc.command_right = command_right;
        adapter_motors_rc.direction_right = MOTOR_DIRECTION_FORWARD;
    } else {
        adapter_motors_rc.command_right = 0;
        adapter_motors_rc.direction_right = MOTOR_DIRECTION_FORWARD;
    }

    adapter_motors_control(&adapter_motors_rc);
}
