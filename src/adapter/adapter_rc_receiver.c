/**
 * @file adapter_rc_receiver.h
 *
 * @brief RC receiver adapter
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#include "adapter_rc_receiver.h"
#include "handler_pulse_rx.h"
#include "protocol_ppm.h"

/*****************************************
 * Private Defines
 *****************************************/

#define RC_MAX_COMMAND (1000)
#define RC_MIN_COMMAND (-1000)

/*****************************************
 * Private Variables
 *****************************************/

handler_pulse_rx_type handler_pulse_rx_ppm_left = {
    .gpio_port = GPIOA,
    .gpio_pin = GPIO_PIN_15,
    .htim = &htim2,
};

handler_pulse_rx_type handler_pulse_rx_ppm_right = {
    .gpio_port = GPIOB,
    .gpio_pin = GPIO_PIN_3,
    .htim = &htim3,
};

adapter_rc_receiver_type adapter_rc_receiver = {
    .command_left = 0,
    .command_right = 0,
};

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void adapter_rc_receiver_init(void) {
    // Init Timers
    MX_TIM2_Init();
    MX_TIM3_Init();

    // Init pulse handler
    handler_pulse_rx_init(&handler_pulse_rx_ppm_left);
    handler_pulse_rx_init(&handler_pulse_rx_ppm_right);

    // Reset
    adapter_rc_receiver_reset();
}

void adapter_rc_receiver_reset(void) {
    // Reset Commands
    adapter_rc_receiver.command_left = 0;
    adapter_rc_receiver.command_right = 0;
}

void adapter_rc_receiver_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    // LEFT
    if (GPIO_Pin == handler_pulse_rx_ppm_left.gpio_pin) {
        handler_pulse_rx_GPIO_EXTI_Callback(&handler_pulse_rx_ppm_left);

        // handling ppm protocol
        adapter_rc_receiver.command_left = (handler_pulse_rx_ppm_left.high_ticks - PPM_ZERO_PERIOD) *
                                           (RC_MAX_COMMAND - RC_MIN_COMMAND) /
                                           (PPM_MAX_PERIOD - PPM_MIN_PERIOD);
    }

    // RIGHT
    else if (GPIO_Pin == handler_pulse_rx_ppm_right.gpio_pin) {
        handler_pulse_rx_GPIO_EXTI_Callback(&handler_pulse_rx_ppm_right);

        // handling ppm protocol
        adapter_rc_receiver.command_right = (handler_pulse_rx_ppm_right.high_ticks - PPM_ZERO_PERIOD) *
                                            (RC_MAX_COMMAND - RC_MIN_COMMAND) /
                                            (PPM_MAX_PERIOD - PPM_MIN_PERIOD);
    }
}

int16_t adapter_rc_receiver_get_command_left(void) {
    return adapter_rc_receiver.command_left;
}

int16_t adapter_rc_receiver_get_command_right(void) {
    return adapter_rc_receiver.command_right;
}
