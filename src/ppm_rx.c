/**
 * @file infrared_receiver.c
 *
 * @brief infrared receiver related
 */

#include "ppm_rx.h"
#include "mcu.h"

/*****************************************
 * GLOBAL VARIABLES
 *****************************************/
uint16_t startCH1Tick, startCH2Tick, endCH1Tick, endCH2Tick = 0;
volatile uint16_t CH1Tick, CH2Tick;
uint16_t ch1_mean[5], ch2_mean[5];
uint8_t i = 0;
uint8_t k = 0;
uint16_t media_ch1;
uint16_t media_ch2;

/*****************************************
 * LOW LEVEL MODULES
 *****************************************/

// Interrupt function
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    // PPM RX Left
    if (GPIO_Pin == GPIO_PIN_15) {
        // rising edge -> start counting signal
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == true) {
            __HAL_TIM_SET_COUNTER(&htim2, 0);
            startCH1Tick = __HAL_TIM_GET_COUNTER(&htim2);
        }

        // falling edge -> subtract original value
        else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == false) {
            endCH1Tick = __HAL_TIM_GET_COUNTER(&htim2);
            CH1Tick = endCH1Tick - startCH1Tick;
        }
    }

    // PPM RX Right
    else if (GPIO_Pin == GPIO_PIN_3) {
        // rising edge -> start counting signal
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == true) {
            __HAL_TIM_SET_COUNTER(&htim3, 0);
            startCH2Tick = __HAL_TIM_GET_COUNTER(&htim3);
        }

        // falling edge -> subtract original value
        else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == false) {
            endCH2Tick = __HAL_TIM_GET_COUNTER(&htim3);
            CH2Tick = endCH2Tick - startCH2Tick;
        }
    }
}
