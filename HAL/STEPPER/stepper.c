/*
 * stepper.c
 *
 *  Created on: 8 Apr 2019
 *      Author: MohamedSaa3D
 */

#include "stepper.h"
#include "avr\delay.h"

u8 Stepper_u8Initialization(void)
{
	u8 ErrorFlag = 0;

	DIO_u8SetPinDirection(STEPPER_PORT , STEPPER_BLUE   , PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT , STEPPER_PINK   , PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT , STEPPER_YELLOW , PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT , STEPPER_ORANGE , PIN_OUTPUT);

	DIO_u8SetPinValue(STEPPER_PORT , STEPPER_BLUE   , PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT , STEPPER_PINK   , PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT , STEPPER_YELLOW , PIN_LOW);
	DIO_u8SetPinValue(STEPPER_PORT , STEPPER_ORANGE , PIN_LOW);


	return ErrorFlag;

}


u8 Stepper_u8Rotate(motion_direction STEPPER_DIRECTION)
{
	u8 ErrorFlag = 0;
	static u8 counter=0;

	if(counter>3)
	{
		counter = 0;
	}
	else
	{
		counter++;
	}

	switch(STEPPER_DIRECTION)
	{
	case FORWARD:
		switch(counter)
		{
		case 0:
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_BLUE   , PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_PINK   , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_YELLOW , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_ORANGE , PIN_LOW);
			break;

		case 1:
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_BLUE   , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_PINK   , PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_YELLOW , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_ORANGE , PIN_LOW);
			break;

		case 2:
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_BLUE   , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_PINK   , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_YELLOW , PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_ORANGE , PIN_LOW);
			break;

		case 3:
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_BLUE   , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_PINK   , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_YELLOW , PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT , STEPPER_ORANGE , PIN_HIGH);
			break;

		}
		break;

	case BACKWARD:
		break;
	}


	return ErrorFlag;
}
