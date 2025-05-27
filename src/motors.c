/**
 * @file motors.c
 *
 * @brief motors related
 */

#include "motors.h"

/*****************************************
 * DEFINES
 *****************************************/

// PARAMETERS AFFECT DIRECTION OF MOTOR. IF = 1 -> ONE SETUP, ELSE -> OTHER SETUP. TO AVOID PHYSICAL RECONNECTION
#define LEFT_DIRECTION (0)
#define RIGHT_DIRECTION (1)

/*****************************************
 * STATIC VARIABLES
 *****************************************/

static uint32_t left_ch_1, left_ch_2, right_ch_1, right_ch_2;

/*****************************************
 * LOW LEVEL MODULES
 *****************************************/

void motors_direction_setup() {
    if (LEFT_DIRECTION == 1) {
        left_ch_1 = TIM_CHANNEL_1;
        left_ch_2 = TIM_CHANNEL_2;
    } else {
        left_ch_1 = TIM_CHANNEL_2;
        left_ch_2 = TIM_CHANNEL_1;
    }

    if (RIGHT_DIRECTION == 1) {
        right_ch_1 = TIM_CHANNEL_3;
        right_ch_2 = TIM_CHANNEL_4;
    } else {
        right_ch_1 = TIM_CHANNEL_4;
        right_ch_2 = TIM_CHANNEL_3;
    }
}

void motors_command(int motor_left, int motor_right) {
    int duty_cycle_left, duty_cycle_right;

    duty_cycle_left = motor_left * 10;
    duty_cycle_right = motor_right * 10;

    if (motor_left > 0) {
        __HAL_TIM_SET_COMPARE(&htim1, left_ch_1, duty_cycle_left);
        __HAL_TIM_SET_COMPARE(&htim1, left_ch_2, 0);
    } else {
        __HAL_TIM_SET_COMPARE(&htim1, left_ch_1, 0);
        __HAL_TIM_SET_COMPARE(&htim1, left_ch_2, -duty_cycle_left);
    }

    if (motor_right > 0) {
        __HAL_TIM_SET_COMPARE(&htim1, right_ch_1, duty_cycle_right);
        __HAL_TIM_SET_COMPARE(&htim1, right_ch_2, 0);
    } else {
        __HAL_TIM_SET_COMPARE(&htim1, right_ch_1, 0);
        __HAL_TIM_SET_COMPARE(&htim1, right_ch_2, -duty_cycle_right);
    }
}

void motors_control(int motor_left, int motor_right) {
    motors_command(motor_left, motor_right);
}
