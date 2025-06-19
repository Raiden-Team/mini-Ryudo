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

    uint16_t           tick_start;
    uint16_t           tick_end;
    volatile uint16_t  tick;
} handler_ppm_rx_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief PPM RX Init
 *
 * @param ppm_rx Pointer to PPM RX
 */
void handler_ppm_rx_init(handler_ppm_rx_type* handler_ppm_rx);

/**
 * @brief PPM GPIO EXTI Callback Handling Function
 *
 * @param ppm_rx Pointer to PWM receiver handler.
 */
void handler_ppm_rx_GPIO_EXTI_Callback(handler_ppm_rx_type* handler_ppm_rx);

#endif // __HANDLER_PPM_RX_H__
