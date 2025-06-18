/**
 * @file main.c
 *
 * @brief Main function
 */
#include "adapter_mcu.h"
#include "service_rc.h"

/*****************************************
 * DEFINES
 *****************************************/
#define MAIN_STARTUP_DELAY (3000)

/*****************************************
 * GLOBAL VARIABLES
 *****************************************/

/*****************************************
 * MAIN LOOP
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
