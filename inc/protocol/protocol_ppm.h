/**
 * @file protocol_ppm.h
 *
 * @brief PPM protocol
 *
 * @author Diego Jun Sato Kurashima
 *
 * @date 05/2025
 */

#ifndef __PROTOCOL_PPM_H__
#define __PROTOCOL_PPM_H__

#include <stdint.h>
#include <stdbool.h>

/*****************************************
 * Public Defines
 *****************************************/

#define PPM_MAX_PERIOD (2000)
#define PPM_MIN_PERIOD (1000)
#define PPM_ZERO_PERIOD ((PPM_MAX_PERIOD + PPM_MIN_PERIOD) / 2)

/*****************************************
 * Public Types
 *****************************************/

/*****************************************
 * Public Functions Prototypes
 *****************************************/

#endif // __PROTOCOL_PPM_H__
