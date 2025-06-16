/**
 * @file adapter_motors.c
 *
 * @brief motors adapter for control
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "adapter_motors.h"
#include "handler_pwm.h"

/*****************************************
 * Public Defines
 *****************************************/

#define MOTOR_LEFT_SETUP (0)
#define MOTOR_RIGHT_SETUP (1)

/*****************************************
 * Public Variables
 *****************************************/

/*****************************************
 * Private Variables
 *****************************************/

handler_pwm_type handler_pwm_right_1 = {
    .htim = &htim1,
    .tim_channel = TIM_CHANNEL_1
};

handler_pwm_type handler_pwm_right_2 = {
    .htim = &htim1,
    .tim_channel = TIM_CHANNEL_2
};

handler_pwm_type handler_pwm_left_1 = {
    .htim = &htim1,
    .tim_channel = TIM_CHANNEL_3
};

handler_pwm_type handler_pwm_left_2 = {
    .htim = &htim1,
    .tim_channel = TIM_CHANNEL_4
};

/*****************************************
 * Public Functions
 *****************************************/

void adapter_motors_init(void) {
    // SETUP LEFT
    if (MOTOR_LEFT_SETUP == 1) {
        handler_pwm_left_1.tim_channel = TIM_CHANNEL_1;
        handler_pwm_left_2.tim_channel = TIM_CHANNEL_2;
    } else {
        handler_pwm_left_1.tim_channel = TIM_CHANNEL_2;
        handler_pwm_left_2.tim_channel = TIM_CHANNEL_1;
    }

    // SETUP RIGHT
    if (MOTOR_LEFT_SETUP == 1) {
        handler_pwm_right_1.tim_channel = TIM_CHANNEL_1;
        handler_pwm_right_2.tim_channel = TIM_CHANNEL_2;
    } else {
        handler_pwm_right_1.tim_channel = TIM_CHANNEL_2;
        handler_pwm_right_2.tim_channel = TIM_CHANNEL_1;
    }

    // Init PWM HANDLER
    handler_pwm_init(&handler_pwm_right_1);
    handler_pwm_init(&handler_pwm_right_2);
    handler_pwm_init(&handler_pwm_left_1);
    handler_pwm_init(&handler_pwm_left_1);
}

void adapter_motors_control(adapter_motors_type* adapter_motors) {
    // RIGHT
    if (adapter_motors->direction_right == MOTOR_DIRECTION_BLOCK) {
        handler_pwm_command(&handler_pwm_right_1, 1000);
        handler_pwm_command(&handler_pwm_right_2, 1000);
    } else if (adapter_motors->direction_right == MOTOR_DIRECTION_FORWARD) {
        handler_pwm_command(&handler_pwm_right_1, adapter_motors->command_right);
        handler_pwm_command(&handler_pwm_right_2, 0);
    } else if (adapter_motors->direction_right == MOTOR_DIRECTION_BACKWARDS) {
        handler_pwm_command(&handler_pwm_right_1, 0);
        handler_pwm_command(&handler_pwm_right_2, adapter_motors->command_right);
    }

    // LEFT
    if (adapter_motors->direction_left == MOTOR_DIRECTION_BLOCK) {
        handler_pwm_command(&handler_pwm_left_1, 1000);
        handler_pwm_command(&handler_pwm_left_2, 1000);
    } else if (adapter_motors->direction_left == MOTOR_DIRECTION_FORWARD) {
        handler_pwm_command(&handler_pwm_left_1, adapter_motors->command_left);
        handler_pwm_command(&handler_pwm_left_2, 0);
    } else if (adapter_motors->direction_left == MOTOR_DIRECTION_BACKWARDS) {
        handler_pwm_command(&handler_pwm_left_1, 0);
        handler_pwm_command(&handler_pwm_left_2, adapter_motors->command_left);
    }
}
