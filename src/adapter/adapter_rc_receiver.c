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
#include "handler_ppm_rx.h"

/*****************************************
 * Private Variables
 *****************************************/

handler_ppm_rx_type handler_ppm_rx_left = {
    .gpio_port = GPIOA,
    .gpio_pin = GPIO_PIN_15,
    .htim = &htim2,
};

handler_ppm_rx_type handler_ppm_rx_right = {
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
    // Init PPM Handler
    handler_ppm_rx_init(&handler_ppm_rx_left);
    handler_ppm_rx_init(&handler_ppm_rx_right);

    // Reset Commands
    adapter_rc_receiver.command_left = 0;
    adapter_rc_receiver.command_right = 0;
}

void adapter_rc_receiver_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    // LEFT
    if (GPIO_Pin == handler_ppm_rx_left.gpio_pin) {
        handler_ppm_rx_GPIO_EXTI_Callback(&handler_ppm_rx_left);
        adapter_rc_receiver.command_left = (handler_ppm_rx_left.tick - 1500) * (200) / 1000;
    }

    // RIGHT
    else if (GPIO_Pin == handler_ppm_rx_right.gpio_pin) {
        handler_ppm_rx_GPIO_EXTI_Callback(&handler_ppm_rx_right);
        adapter_rc_receiver.command_right = (handler_ppm_rx_right.tick - 1500) * (200) / 1000;
    }
}

int16_t adapter_rc_receiver_get_command_left(void) {
    return adapter_rc_receiver.command_left;
}

int16_t adapter_rc_receiver_get_command_right(void) {
    return adapter_rc_receiver.command_right;
}
