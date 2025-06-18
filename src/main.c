/**
 * @file main.c
 *
 * @brief Main function
 */
#include "mcu.h"
#include "service_rc.h"

/*****************************************
 * DEFINES
 *****************************************/
#define STARTUP_DELAY 3000

/*****************************************
 * GLOBAL VARIABLES
 *****************************************/

/*****************************************
 * MAIN LOOP
 *****************************************/

int main(void) {
    // INIT modules
    mcu_init();
    service_rc_init();

    // Delay - to avoid motor movement without control
    HAL_Delay(STARTUP_DELAY);

    // Main Loop
    for (;;) {
        service_rc_run();
    }
}
