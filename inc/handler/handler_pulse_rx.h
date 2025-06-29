/**
 * @file handler_pulse_rx.h
 *
 * @brief Handler for pulse receiver.
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __HANDLER_PULSE_RX_H__
#define __HANDLER_PULSE_RX_H__

#include <stdint.h>
#include "gpio.h"
#include "tim.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief pulse receiver struct
 */
typedef struct handler_pulse_rx {
    GPIO_TypeDef*      gpio_port;
    uint16_t           gpio_pin;

    TIM_HandleTypeDef* htim;

    uint16_t           tick_rising_edge;
    uint16_t           tick_falling_edge;
    volatile uint16_t  high_ticks;
    volatile uint16_t  low_ticks;
} handler_pulse_rx_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief initialize handler for pulse receiver
 *
 * @param pulse_rx pointer to pulse receiver handler
 */
void handler_pulse_rx_init(handler_pulse_rx_type* handler_pulse_rx);

/**
 * @brief pulse receiver GPIO EXTI Callback Handling Function
 *
 * @param pulse_rx pointer to pulse receiver handler.
 */
void handler_pulse_rx_GPIO_EXTI_Callback(handler_pulse_rx_type* handler_pulse_rx);

#endif // __HANDLER_PULSE_RX_H__
