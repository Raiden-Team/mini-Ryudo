/**
 * @file handler_pwm.c
 *
 * @brief Handler for PWM.
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "handler_pwm.h"

/*****************************************
 * Private Defines
 *****************************************/
#define DUTY_CYCLE_MAX (1000)
#define DUTY_CYCLE_MIN (0)

/*****************************************
 * Public Functions Prototypes
 *****************************************/

void handler_pwm_init(handler_pwm_type* handler_pwm) {
    HAL_TIM_PWM_Start(handler_pwm->htim,
                      handler_pwm->tim_channel);
}

void handler_pwm_command(handler_pwm_type* handler_pwm, uint16_t duty_cycle) {
    // Map Duty Cycle
    uint16_t duty_cycle_corrected = duty_cycle;

    if (duty_cycle > DUTY_CYCLE_MAX) {
        duty_cycle_corrected = DUTY_CYCLE_MAX;
    } else if (duty_cycle < DUTY_CYCLE_MIN) {
        duty_cycle_corrected = DUTY_CYCLE_MIN;
    }

    // Set Duty Cycle
    __HAL_TIM_SET_COMPARE(handler_pwm->htim,
                          handler_pwm->tim_channel,
                          duty_cycle_corrected);
}
