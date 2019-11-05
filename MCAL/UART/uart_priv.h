/*
 * uart_priv.h
 *
 *  Created on: 10 May 2019
 *      Author: MohamedSaa3D
 */

#ifndef _UART_PRIV_H_
#define _UART_PRIV_H_

/*----------------- UART Registers Addresses -----------------*/

#define UDR      *( (volatile u8*)(0x2C) )
#define UCSRA    *( (volatile u8*)(0x2B) )
#define UCSRB    *( (volatile u8*)(0x2A) )
#define UBRRH    *( (volatile u8*)(0x40) )
#define UCSRC    *( (volatile u8*)(0x40) )
#define UBRRL    *( (volatile u8*)(0x29) )




#endif /* 4_MCAL_UART_UART_PRIV_H_ */
