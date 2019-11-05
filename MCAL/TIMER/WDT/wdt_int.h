/*
 * timer_int.h
 *
 *  Created on: 20 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _TIMER0_INT_H_
#define _TIMER0_INT_H_

#include "../../../Libraries/STD_TYPES.h"
#include "wdt_config.h"
#include "wdt_priv.h"

u8 WatchDogTimer_u8Initialization(void);
u8 WatchDogTimer_u8Enable(void);


#endif /*_TIMER_INT_H_ */
