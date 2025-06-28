/**
 * @file mcu.c
 *
 * @brief MCU related
 */

#include "adapter_mcu.h"

/*****************************************
 * Public Functions Prototypes
 *****************************************/

void adapter_mcu_init(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
}
