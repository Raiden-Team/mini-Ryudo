/**
 * @file adapter_rc_receiver.h
 *
 * @brief RC receiver adapter
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __ADAPTER_RC_RECEIVER_H__
#define __ADAPTER_RC_RECEIVER_H__

#include <stdint.h>
#include <stdbool.h>

#include "handler_pwm.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief rc receiver adapter struct
 */
typedef struct adapter_rc_receiver {
    int16_t command_left;
    int16_t command_right;
} adapter_rc_receiver_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief initialize the rc receiver adapter
 */
void adapter_rc_receiver_init(void);

/**
 * @brief rc receiver GPIO_EXTI_Callback
 *
 * @param GPIO_Pin GPIO Pin
 */
void adapter_rc_receiver_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

/**
 * @brief get left command from rc receiver adapter
 */
int16_t adapter_rc_receiver_get_command_left(void);

/**
 * @brief get right command from rc receiver adapter
 */
int16_t adapter_rc_receiver_get_command_right(void);

#endif // __ADAPTER_RC_RECEIVER_H__
