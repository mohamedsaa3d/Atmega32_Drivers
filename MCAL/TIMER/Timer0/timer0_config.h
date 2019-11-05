/*
 * timer_config.h
 *
 *  Created on: 20 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _TIMER0_CONFIG_H_
#define _TIMER0_CONFIG_H_

/*---------------------------------------------------------------------------------*/
/* ------------------------- T I M E R ( 0 )  C O N T R O L -----------------------*/
/*---------------------------------------------------------------------------------*/

/*
 * Select Waveform Generation Mode :
 * (_NORMAL / _PWM_PHASE_CORRECT / _CTC / _FAST_PWM)
 */
#define Timer0_MODE        _NORMAL

/*
 * Select Compare Match Output PIN Mode :
 * (_DISCONNECT / _TOGGLE_ON_MATCH / _CLEAR_ON_MATCH / _SET_ON_MATCH)
 */
#define OC0_MODE           _CLEAR_ON_MATCH
#define OCR_InitialValue   0xFF

/*
 * Select Prescaler :
 * (_NO_CLOCK / _NO_PRESCALE / _CLK_8 / _CLK_64 / _CLK_256 / _CLK_1024 / _EXT_CLK_FALL / _EXT_CLK_RISE )
 */
#define T0_PRESCALER_MODE     _CLK_8

/*
 * Timer 0 Interrupt Control : Interrupt Initialization must be called first
 * */
#define T0_INTERRUPT_OVERFLOW    ENABLED
#define T0_INTERRUPT_ONCOMPARE   DISABLED



#endif /* _TIMER_CONFIG_H_ */
