/**
 * @file main.c
 *
 * @brief Main function
 */
#include "controller_main.h"
#include "adapter_rc_receiver.h"

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    // INIT modules
    controller_main_init();

    // Main Loop
    for (;;) {
        controller_main_run();
    }
}

/*****************************************
 * Callbacks
 *****************************************/

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    adapter_rc_receiver_GPIO_EXTI_Callback(GPIO_Pin);
}
