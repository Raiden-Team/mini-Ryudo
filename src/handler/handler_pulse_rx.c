/**
 * @file handler_pulse_rx.h
 *
 * @brief Handler for pulse receiver.
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "handler_pulse_rx.h"

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void handler_pulse_rx_init(handler_pulse_rx_type* handler_pulse_rx) {
    // Check If TIMER
    if (handler_pulse_rx->htim != NULL) {
        // Init TIMER
        HAL_TIM_Base_Start(handler_pulse_rx->htim);

        // Reset Ticks
        handler_pulse_rx->tick_rising_edge = 0;
        handler_pulse_rx->tick_falling_edge = 0;
        handler_pulse_rx->high_ticks = 0;
        handler_pulse_rx->low_ticks = 0;
    }
}

void handler_pulse_rx_GPIO_EXTI_Callback(handler_pulse_rx_type* handler_pulse_rx) {
    // Rising Edge
    if (HAL_GPIO_ReadPin(handler_pulse_rx->gpio_port, handler_pulse_rx->gpio_pin) == GPIO_PIN_SET) {
        // Get Low Ticks
        handler_pulse_rx->low_ticks = __HAL_TIM_GET_COUNTER(handler_pulse_rx->htim) -
                                      handler_pulse_rx->tick_falling_edge;

        // Set Rising Edge Ticks
        __HAL_TIM_SET_COUNTER(handler_pulse_rx->htim, 0);
        handler_pulse_rx->tick_rising_edge = __HAL_TIM_GET_COUNTER(handler_pulse_rx->htim);
    }

    // Falling Edge
    else if (HAL_GPIO_ReadPin(handler_pulse_rx->gpio_port, handler_pulse_rx->gpio_pin) == GPIO_PIN_RESET) {
        // Set Falling Edge Ticks
        handler_pulse_rx->tick_falling_edge = __HAL_TIM_GET_COUNTER(handler_pulse_rx->htim);

        // Get Hight Ticks
        handler_pulse_rx->high_ticks = handler_pulse_rx->tick_falling_edge - handler_pulse_rx->tick_rising_edge;
    }
}
