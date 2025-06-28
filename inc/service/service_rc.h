/**
 * @file service_rc.h
 *
 * @brief service for rc
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __SERVICE_RC_H__
#define __SERVICE_RC_H__

#include <stdint.h>
#include <stdbool.h>

#include "adapter_motors.h"

/*****************************************
 * Public Types
 *****************************************/

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief initialize radio-control service
 */
void service_rc_init(void);

/**
 * @brief reset radio-control service
 */
void service_rc_reset(void);

/**
 * @brief run radio-control service
 */
void service_rc_run(void);

#endif // __SERVICE_RC_H__
