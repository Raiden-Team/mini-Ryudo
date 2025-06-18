/**
 * @file adapter_motors.h
 *
 * @brief motors adapter for control
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __ADAPTER_MOTORS_H__
#define __ADAPTER_MOTORS_H__

#include <stdint.h>
#include <stdbool.h>

#include "handler_pwm.h"
#include "tim.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief motor direction enum
 */
typedef enum motor_direction {
    MOTOR_DIRECTION_FORWARD,
    MOTOR_DIRECTION_BACKWARDS,
    MOTOR_DIRECTION_BLOCK,
} motor_direction_enum;

/**
 * @brief motor adapter struct
 */
typedef struct adapter_motors {
    motor_direction_enum direction_right;
    uint16_t             command_right;

    motor_direction_enum direction_left;
    uint16_t             command_left;
} adapter_motors_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief initialize the motors adapter
 */
void adapter_motors_init(void);

/**
 * @brief Control the motors command
 *
 * @param motors_command pointer to motors_command struct with the PWM's duty cycle for both sides
 */
void adapter_motors_control(adapter_motors_type* adapter_motors);

#endif // __ADAPTER_MOTORS_H__
