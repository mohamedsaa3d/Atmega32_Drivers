/*
 * SEVEN_SEG.h
 *
 *  Created on: 25 Mar 2019
 *      Author: MohamedSaa3D
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "../../2.Libraries/STD_TYPES.h"
#include "..\..\4.MCAL\DIO\DIO.h"

#define ZERO   0
#define ONE    1
#define TWO    2
#define THREE  3
#define FOUR   4
#define FIVE   5
#define SIX    6
#define SEVEN  7
#define EIGHT  8
#define NINE   9

#define INTPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 0

#define LED_OFF 0
#define LED_ON 1

#define LED_A_PORT    PORT_B
#define LED_A_PIN     PIN0

#define LED_B_PORT    PORT_B
#define LED_B_PIN     PIN1

#define LED_C_PORT    PORT_B
#define LED_C_PIN     PIN2

#define LED_D_PORT    PORT_B
#define LED_D_PIN     PIN3

#define LED_E_PORT    PORT_B
#define LED_E_PIN     PIN4

#define LED_F_PORT    PORT_B
#define LED_F_PIN     PIN5

#define LED_G_PORT    PORT_B
#define LED_G_PIN     PIN6

#define LED_DOT_PORT  PORT_B
#define LED_DOT_PIN   PIN7


typedef union
{
	struct
	{
		u8 a:1 ;
		u8 b:1 ;
		u8 c:1 ;
		u8 d:1 ;
		u8 e:1 ;
		u8 f:1 ;
		u8 g:1 ;
		u8 dot:1;

	};

	u8 BYTE;

}SevenSEG;

u8 Seven_SEG_u8Initilization(void);

u8 SevenSEG_u8WriteDigit( u8 u8Digit );


#endif /* SEVEN_SEG_H_ */
