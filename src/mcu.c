/**
 * @file mcu.c
 *
 * @brief MCU related
 */

#include "mcu.h"
#include "motors.h"

/*****************************************
 * INITIALIZATION MODULES
 *****************************************/

void mcu_init(void) {
    /*
     * Standard initialization
     */
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
}

void motors_init() {
    // Init TIMER 1
    MX_TIM1_Init();

    // Enable PWM Generation
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

    // Setup Configuration
    motors_direction_setup();
}

void ppm_rx_init_left() {
    MX_TIM2_Init();
    HAL_TIM_Base_Start(&htim2);
}

void ppm_rx_init_right() {
    MX_TIM3_Init();
    HAL_TIM_Base_Start(&htim3);
}
