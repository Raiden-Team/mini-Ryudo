/**
 * @file handler_ppm_rx.h
 *
 * @brief Handler for PPM RX.
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __HANDLER_PPM_RX_H__
#define __HANDLER_PPM_RX_H__

#include <stdint.h>
#include "gpio.h"
#include "tim.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief PPM RX Struct
 */
typedef struct handler_ppm_rx {
    GPIO_TypeDef*      gpio_port;
    uint16_t           gpio_pin;

    TIM_HandleTypeDef* htim;

    uint16_t           tick_rising_edge;
    uint16_t           tick_falling_edge;
    volatile uint16_t  high_ticks;
    volatile uint16_t  low_ticks;
} handler_ppm_rx_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief initialize handler for ppm receiver
 *
 * @param ppm_rx pointer to ppm receiver handler
 */
void handler_ppm_rx_init(handler_ppm_rx_type* handler_ppm_rx);

/**
 * @brief ppm receiver GPIO EXTI Callback Handling Function
 *
 * @param ppm_rx pointer to ppm receiver handler.
 */
void handler_ppm_rx_GPIO_EXTI_Callback(handler_ppm_rx_type* handler_ppm_rx);

#endif // __HANDLER_PPM_RX_H__
