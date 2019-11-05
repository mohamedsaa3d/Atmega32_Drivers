/*
 * stepper.hSTEPPER_DIRECTION
 *
 *  Created on: 8 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _STEPPER_H_
#define _STEPPER_H_

#include "../../Libraries/BIT_MATH.h"
#include "../../Libraries/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/KEYPAD/keypad.h"

#define STEPPER_PORT     PORT_A
#define STEPPER_BLUE     PIN4
#define STEPPER_PINK     PIN5
#define STEPPER_YELLOW   PIN6
#define STEPPER_ORANGE   PIN7

typedef enum
{
	FORWARD  = 0 , BACKWARD = 1
}motion_direction;

u8 Stepper_u8Initialization(void);
u8 Stepper_u8Rotate( motion_direction STEPPER_DIRECTION );


#endif /* 3_HAL_STEPPER_STEPPER_H_ */
