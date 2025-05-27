/**
 * @file main.c
 *
 * @brief Main function
 */
#include "mcu.h"
#include "motors.h"
#include "ppm_rx.h"

/*****************************************
 * DEFINES
 *****************************************/
#define STARTUP_DELAY 3000

/*****************************************
 * GLOBAL VARIABLES
 *****************************************/
int32_t CH1MotorRC, CH2MotorRC;
volatile extern uint16_t CH1Tick, CH2Tick;

/*****************************************
 * MAIN LOOP
 *****************************************/

int main(void) {
    // INIT modules
    mcu_init();
    motors_init();
    ppm_rx_init_left();
    ppm_rx_init_right();

    // Delay - to avoid motor movement without control
    HAL_Delay(STARTUP_DELAY);

    // Main Loop
    for (;;) {
        CH1MotorRC = (CH1Tick - 1500) * (200) / 1000;
        CH2MotorRC = (CH2Tick - 1500) * (200) / 1000;

        // Dumb filter - to avoid noise for low speed
        if ((CH1MotorRC > -20) && (CH1MotorRC < 20)) {
            CH1MotorRC = 0;
        }

        if ((CH2MotorRC > -20) && (CH2MotorRC < 20)) {
            CH2MotorRC = 0;
        }

        motors_control(CH1MotorRC, CH2MotorRC);
    }
}
