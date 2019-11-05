/*
 * interrupt.h
 *
 *  Created on: 12 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include "interrupt_private.h"
#include "interrupt_config.h"
#include "../../Libraries/STD_TYPES.h"


#define RESET_vect                 __vector_0
#define INT0_vect                  __vector_1
#define INT1_vect                  __vector_2
#define INT2_vect                  __vector_3
#define TIMER2_COMPARE_vect        __vector_4
#define TIMER2_OVERFLOW_vect       __vector_5
#define TIMER1_Capture_Event       __vector_6
//#define TIMER1A_COMPARE_vect       __vector_7
#define TIMER1B_COMPARE_vect       __vector_8
#define TIMER1_OVERFLOW_vect       __vector_9
#define TIMER0_COMPARE_vect        __vector_10
#define TIMER0_OVERFLOW_vect       __vector_11
#define SERIAL_COMPLETE_vect       __vector_12
#define USART_RX_COMPLETE_vect     __vector_13
#define USART_DATA_EMPTY_vect      __vector_14
#define USART_TX_COMPLETE_vect     __vector_15
#define ADC_CONVERSION_vect        __vector_16
#define EEPROM_READY_vect          __vector_17
#define ANALOG_COMPARATOR_vect     __vector_18
#define TWO_WIRE_SERIAL_vect       __vector_19
#define STORE_PROGRAM_MEMORY_vect  __vector_20


#define ISR(vector_no) void vector_no(void)__attribute__((signal,__INTR_ATTRS)); \
					   void vector_no(void)

typedef enum
{
	  GI_ENABLE
	, GI_DISABLE

}GlobalINT_STATE;

typedef enum
{
	  LOW_LEVEL
	, ANY_LOGIC_CHANGE
	, FALLING_EDGE
	, RISING_EDGE

}enumINT_SENSE;

typedef enum
{
	  EXT_INT0
	, EXT_INT1
	, EXT_INT2

}enumEXTI;

typedef enum
{
   INT0
 , INT1
 , INT2
 , TIMER2_COMPARE
 , TIMER2_OVERFLOW
 , TIMER1_Capture
 , TIMER1A_COMPARE
 , TIMER1B_COMPARE
 , TIMER1_OVERFLOW
 , TIMER0_COMPARE
 , TIMER0_OVERFLOW
 , SERIAL_COMPLETE
 , USART_RX_COMPLETE
 , USART_DATA_EMPTY
 , USART_TX_COMPLETE
 , ADC_CONVERSION
 , EEPROM_READY
 , ANALOG_COMPARATOR
 , TWO_WIRE_SERIAL
 , STORE_PROGRAM_MEMORY

}enumISR_VECTORS;


u8 Interrupt_u8GI(GlobalINT_STATE GI_SELECT);
u8 Interrupt_u8EXTINT ( enumEXTI ChannelSelect , enumINT_SENSE Sense_Select);
u8 ISR_CALLBACK( enumISR_VECTORS ISR_vector_ID , void(*functionPTR)(void)  );



#endif /* _INTERRUPT_H_ */
