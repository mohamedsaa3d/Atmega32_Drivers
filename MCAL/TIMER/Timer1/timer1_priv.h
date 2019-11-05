/*
 * 		Timer Private Header File
 *
 *  	Created on: 20 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _TIMER1_PRIV_H_
#define _TIMER1_PRIV_H_
/*---------------------------------------------------------------------------------------*/
/* -------------------------- Addressing the Timers registers  --------------------------*/
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

#define TCCR1A  *( (volatile u8* )(0x4F) )
#define TCCR1B  *( (volatile u8* )(0x4E) )
#define OCR1A   *( (volatile u16*)(0x4A) )
#define OCR1B   *( (volatile u16*)(0x48) )
#define TCNT1   *( (volatile u16*)(0x4C) )
#define ICR1    *( (volatile u16*)(0x46) )



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

#define  MOD0                  0
#define  MOD1                  1
#define  MOD2                  2
#define  MOD3                  3
#define  MOD4                  4
#define  MOD5                  5
#define  MOD6                  6
#define  MOD7                  7
#define  MOD8                  8
#define  MOD9                  9
#define  MOD10                 10
#define  MOD11                 11
#define  MOD12                 12
#define  MOD13                 13
#define  MOD14                 14

//#define FALLING_EDGE           0
//#define RISING_EDGE            1

#endif

#endif /* _TIMER_PRIV_H_ */
