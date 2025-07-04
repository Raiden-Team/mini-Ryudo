/**
 * @file controller_main.c
 *
 * @brief service for rc
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "controller_main.h"
#include "adapter_mcu.h"
#include "adapter_motors.h"
#include "adapter_rc_receiver.h"
#include "service_rc.h"

/*****************************************
 * Private Defines
 *****************************************/

#define MAIN_IDLE_INIT_DELAY (3000)

/*****************************************
 * Private Types
 *****************************************/

/**
 * @brief controller main struct
 */
typedef struct controller_main {
    controller_main_state_type state_current;
    controller_main_state_type state_previous;
    uint32_t                   state_timer;
} controller_main_type;

/*****************************************
 * Private Variables
 *****************************************/

adapter_motors_type adapter_motors_main = {
    .command_left = 0,
    .command_right = 0,
};

controller_main_type controller_main = {
    .state_current = MAIN_IDLE,
    .state_previous = MAIN_IDLE,
};

/*****************************************
 * Public Functions
 *****************************************/

void controller_main_init(void) {
    // Initialization
    adapter_mcu_init();
    adapter_motors_init();
    adapter_rc_receiver_init();
    service_rc_init();

    // Reset
    controller_main_reset();
}

void controller_main_reset(void) {
    controller_main.state_current = MAIN_IDLE;
    controller_main.state_previous = MAIN_IDLE;
    reset_timer(controller_main.state_timer);

    // Init MAIN_IDLE
    controller_main_state_init(MAIN_IDLE);
}

void controller_main_state_init(controller_main_state_type main_next_state) {
    controller_main.state_previous = controller_main.state_current;
    controller_main.state_current = main_next_state;
    reset_timer(controller_main.state_timer);

    switch (main_next_state) {
        case MAIN_IDLE:

            // Run Delay
            HAL_Delay(MAIN_IDLE_INIT_DELAY);
            break;

        case MAIN_RUN:

            // Initialization
            service_rc_reset();
            break;
    }
}

void controller_main_state_run(void) {
    switch (controller_main.state_current) {
        case MAIN_IDLE:

            // ACTION
            adapter_motors_main.direction_left = MOTOR_DIRECTION_BLOCK;
            adapter_motors_main.command_left = 0;
            adapter_motors_main.direction_right = MOTOR_DIRECTION_BLOCK;
            adapter_motors_main.command_right = 0;
            adapter_motors_control(&adapter_motors_main);

            // TRANSITION
            controller_main_state_init(MAIN_RUN);

            break;

        case MAIN_RUN:

            // ACTION
            service_rc_run();

            // TRANSITION
            break;
    }
}

void controller_main_run(void) {
    controller_main_state_run();
}
