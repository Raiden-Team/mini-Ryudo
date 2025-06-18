/**
 * @file main.c
 *
 * @brief Main function
 */
#include "adapter_mcu.h"
#include "adapter_rc_receiver.h"
#include "service_rc.h"

/*****************************************
 * Private Variables
 *****************************************/

#define MAIN_STARTUP_DELAY (3000)

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    // INIT modules
    adapter_mcu_init();
    service_rc_init();

    // Delay - to avoid motor movement without control
    HAL_Delay(MAIN_STARTUP_DELAY);

    // Main Loop
    for (;;) {
        service_rc_run();
    }
}

/*****************************************
 * Callbacks
 *****************************************/

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    adapter_rc_receiver_GPIO_EXTI_Callback(GPIO_Pin);
}
