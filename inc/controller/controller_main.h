/**
 * @file controller_main.h
 *
 * @brief main controller
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __CONTROLLER_MAIN_H__
#define __CONTROLLER_MAIN_H__

#include <stdint.h>
#include <stdbool.h>

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief controller main state enum
 */
typedef enum controller_main_state {
    MAIN_IDLE,
    MAIN_RUN
} controller_main_state_type;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief initialize main controller
 */
void controller_main_init(void);

/**
 * @brief reset main controller
 */
void controller_main_reset(void);

/**
 * @brief initialize the next state from main controller
 */
void controller_main_state_init(controller_main_state_type main_next_state);

/**
 * @brief run the action and check transitions from current state from main controller
 */
void controller_main_state_run(void);

/**
 * @brief run the main controller
 */
void controller_main_run(void);

#endif // __CONTROLLER_MAIN_H__
