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

#endif // __INIT_H__
