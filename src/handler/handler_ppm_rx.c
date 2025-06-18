/**
 * @file handler_ppm_rx.c
 *
 * @brief Handler for PPM RX.
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "handler_ppm_rx.h"

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void handler_ppm_rx_init(handler_ppm_rx_type* handler_ppm_rx) {
    // Check If TIMER
    if (handler_ppm_rx->htim != NULL) {
        // Init TIMER
        HAL_TIM_Base_Start(handler_ppm_rx->htim);

        // Reset Ticks
        handler_ppm_rx->tick_start = 0;
        handler_ppm_rx->tick_end = 0;
        handler_ppm_rx->tick = 0;
    }
}

void handler_ppm_rx_GPIO_EXTI_Callback(handler_ppm_rx_type* handler_ppm_rx) {
    //
    if (HAL_GPIO_ReadPin(handler_ppm_rx->gpio_port, handler_ppm_rx->gpio_pin) == GPIO_PIN_SET) {
        __HAL_TIM_SET_COUNTER(handler_ppm_rx->htim, 0);
        handler_ppm_rx->tick_start = __HAL_TIM_GET_COUNTER(handler_ppm_rx->htim);
    }

    //
    else if (HAL_GPIO_ReadPin(handler_ppm_rx->gpio_port, handler_ppm_rx->gpio_pin) == GPIO_PIN_RESET) {
        handler_ppm_rx->tick_end = __HAL_TIM_GET_COUNTER(handler_ppm_rx->htim);
        handler_ppm_rx->tick = handler_ppm_rx->tick_end - handler_ppm_rx->tick_start;
    }
}
