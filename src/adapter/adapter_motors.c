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
 * Private Defines
 *****************************************/

#define MOTOR_LEFT_SETUP (0)
#define MOTOR_RIGHT_SETUP (1)

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
    if (MOTOR_RIGHT_SETUP == 1) {
        handler_pwm_right_1.tim_channel = TIM_CHANNEL_3;
        handler_pwm_right_2.tim_channel = TIM_CHANNEL_4;
    } else {
        handler_pwm_right_1.tim_channel = TIM_CHANNEL_4;
        handler_pwm_right_2.tim_channel = TIM_CHANNEL_3;
    }

    // Init Timers
    MX_TIM1_Init();

    // Init PWM HANDLER
    handler_pwm_init(&handler_pwm_left_1);
    handler_pwm_init(&handler_pwm_left_2);
    handler_pwm_init(&handler_pwm_right_1);
    handler_pwm_init(&handler_pwm_right_2);
}

void adapter_motors_control(adapter_motors_type* adapter_motors) {
    // LEFT
    // BLOCK
    if (adapter_motors->direction_left == MOTOR_DIRECTION_BLOCK) {
        handler_pwm_command(&handler_pwm_left_1, MOTOR_DUTY_CYCLE_MAX);
        handler_pwm_command(&handler_pwm_left_2, MOTOR_DUTY_CYCLE_MAX);
    }

    // FORWARD
    else if (adapter_motors->direction_left == MOTOR_DIRECTION_FORWARD) {
        handler_pwm_command(&handler_pwm_left_1, adapter_motors->command_left);
        handler_pwm_command(&handler_pwm_left_2, MOTOR_DUTY_CYCLE_MIN);
    }

    // BACKWARDS
    else if (adapter_motors->direction_left == MOTOR_DIRECTION_BACKWARDS) {
        handler_pwm_command(&handler_pwm_left_1, MOTOR_DUTY_CYCLE_MIN);
        handler_pwm_command(&handler_pwm_left_2, adapter_motors->command_left);
    }

    // RIGHT
    // BLOCK
    if (adapter_motors->direction_right == MOTOR_DIRECTION_BLOCK) {
        handler_pwm_command(&handler_pwm_right_1, MOTOR_DUTY_CYCLE_MAX);
        handler_pwm_command(&handler_pwm_right_2, MOTOR_DUTY_CYCLE_MAX);
    }

    // FORWARD
    else if (adapter_motors->direction_right == MOTOR_DIRECTION_FORWARD) {
        handler_pwm_command(&handler_pwm_right_1, adapter_motors->command_right);
        handler_pwm_command(&handler_pwm_right_2, MOTOR_DUTY_CYCLE_MIN);
    }

    // BACKWARDS
    else if (adapter_motors->direction_right == MOTOR_DIRECTION_BACKWARDS) {
        handler_pwm_command(&handler_pwm_right_1, MOTOR_DUTY_CYCLE_MIN);
        handler_pwm_command(&handler_pwm_right_2, adapter_motors->command_right);
    }
}
