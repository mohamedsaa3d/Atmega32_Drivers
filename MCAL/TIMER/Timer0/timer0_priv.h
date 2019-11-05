/*
 * 		Timer Private Header File
 *
 *  	Created on: 20 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _TIMER0_PRIV_H_
#define _TIMER0_PRIV_H_
/*---------------------------------------------------------------------------------------*/
/* -------------------------- Addressing the Timer0 registers  --------------------------*/
/*---------------------------------------------------------------------------------------*/

#ifndef _TIMSK_
#define _TIMSK_
/*-----------------------------------------*/
#define TIMSK   *( (volatile u8* )(0x59) )
/*-----------------------------------------*/
#endif

#ifndef _TIFR_
#define _TIFR_
/*-----------------------------------------*/
#define TIFR    *( (volatile u8* )(0x58) )
/*-----------------------------------------*/
#endif


#define TCCR0   *( (volatile u8* )(0x53) )
#define TCNT0   *( (volatile u8* )(0x52) )
#define OCR0    *( (volatile u8* )(0x5C) )




/*---------------------------------------------------------------------------------------*/
/* ------------------------ Indexing the configuration options  -------------------------*/
/*---------------------------------------------------------------------------------------*/

#ifndef _TIMER_INDEX_
#define _TIMER_INDEX_

#define  DISABLED              0
#define  ENABLED               1


#define  _DISCONNECT           0
#define  _TOGGLE_ON_MATCH      1
#define  _CLEAR_ON_MATCH       2
#define  _SET_ON_MATCH         3


#define  _NORMAL               0
#define  _PWM_PHASE_CORRECT    1
#define  _CTC                  2
#define  _FAST_PWM             3


#define  _NO_CLOCK             0
#define  _NO_PRESCALE          1
#define  _CLK_8                2
#define  _CLK_64               3
#define  _CLK_256              4
#define  _CLK_1024             5
#define  _EXT_CLK_FALL         6
#define  _EXT_CLK_RISE         7



//#define FALLING_EDGE           0
//#define RISING_EDGE            1

#endif

#endif /* _TIMER_PRIV_H_ */
