/**
 * @file handler_pwm.h
 *
 * @brief Handler for PWM.
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __HANDLER_PWM_H__
#define __HANDLER_PWM_H__

#include <stdint.h>
#include "gpio.h"
#include "tim.h"

/*****************************************
 * Public Defines
 *****************************************/

#define MOTOR_DUTY_CYCLE_MAX (1000)
#define MOTOR_DUTY_CYCLE_MIN (0)

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief PPM RX Struct
 */
typedef struct handler_pwm {
    TIM_HandleTypeDef* htim;
    uint16_t           tim_channel;
} handler_pwm_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief PWM Init
 *
 * @param handler_pwm Pointer to PWM
 */
void handler_pwm_init(handler_pwm_type* handler_pwm);

/**
 * @brief Control PWM duty cycle
 *
 * @param handler_pwm Pointer to handler_pwm.
 * @param duty_cyle PWM's duty cycle value
 */
void handler_pwm_command(handler_pwm_type* handler_pwm, uint16_t duty_cycle);

#endif // __HANDLER_PWM_H__
