/**
 * @file mcu.c
 *
 * @brief MCU related
 */

#include "mcu.h"

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
