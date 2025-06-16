/**
 * @file motors.h
 *
 * @brief motors related
 */

#ifndef __MOTORS_H__
#define __MOTORS_H__

#include "tim.h"
#include <stdint.h>
#include <stdio.h>

/*****************************************
 * LOW LEVEL MODULES
 *****************************************/

/**
 * @brief Set direction according to parameters defined in .c file (if == 1, one direction, else, other)
 */
void motors_direction_setup();

/**
 * @brief Send PWM to both motors
 */
void motors_command(int motor_left, int motor_right);

/**
 * @brief Control motors Target Speed
 */
void motors_control(int motor_left, int motor_right);

#endif // __MOTORS_H__
