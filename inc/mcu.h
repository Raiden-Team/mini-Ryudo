/**
 * @file mcu.h
 *
 * @brief MCU related
 */

#ifndef __MCU_H__
#define __MCU_H__

#include "gpio.h"
#include "main.h"
#include "tim.h"
#include <stdint.h>

/*****************************************
 * DEFINES
 *****************************************/

/*****************************************
 * INITIALIZATION MODULES
 *****************************************/

/**
 * @brief Initializes MCU and some peripherals.
 */
void mcu_init(void);

/**
 * @brief Initializes System Clock.
 * @note  Defined by cube.
 */
void SystemClock_Config(void);

/**
 * @brief Initializes motors.
 * @note
 */
void motors_init();

/**
 * @brief Initializes ppm receiver (left channel).
 * @note
 */
void ppm_rx_init_left();

/**
 * @brief Initializes ppm receiver (right channel).
 * @note
 */
void ppm_rx_init_right();

#endif // __INIT_H__
