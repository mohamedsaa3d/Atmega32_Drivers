/*
 * DIO_private.h
 *
 *  Created on: 13 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*###########################################*/
/* DIO Registers Addressing Definitions */
#define DDRA *((volatile u8*)(0x3A))
#define DDRB *((volatile u8*)(0x37))
#define DDRC *((volatile u8*)(0x34))
#define DDRD *((volatile u8*)(0x31))

#define PORTA *((volatile u8*)(0x3B))
#define PORTB *((volatile u8*)(0x38))
#define PORTC *((volatile u8*)(0x35))
#define PORTD *((volatile u8*)(0x32))

#define PINA *((volatile u8*)(0x39))
#define PINB *((volatile u8*)(0x36))
#define PINC *((volatile u8*)(0x33))
#define PIND *((volatile u8*)(0x30))

/*##########################################*/
#define DIO_PORTA_INDEX 0
#define DIO_PORTB_INDEX 1
#define DIO_PORTC_INDEX 2
#define DIO_PORTD_INDEX 3

#define LOWEST_PIN_INDEX  0
#define HIGHEST_PIN_INDEX 7

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_INPUT_DIR  0
#define DIO_OUTPUT_DIR 1

#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

#define NIBBLE_OUTPUT  0b1111
#define NIBBLE_INPUT   0b0000

typedef enum
{
	LOWER  = 0
  , HIGHER = 1
}Nibble;



#endif /* _MCAL_DIO_DIO_PRIVATE_H_ */
