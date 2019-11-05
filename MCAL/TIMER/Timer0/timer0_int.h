/*
 * timer_int.h
 *
 *  Created on: 20 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _TIMER0_INT_H_
#define _TIMER0_INT_H_

#include "../../../2.Libraries/STD_TYPES.h"
#include "timer0_config.h"
#include "timer0_priv.h"

u8 Timer0_u8Initialization(void);
u8 Timer0_u8StartTimer(void);
u8 Timer0_u8StopTimer(void);
u8 Timer0_u8ISR(void);
u8 Timer0_u8SetISR(void);


#endif /*_TIMER_INT_H_ */
