/*
 * ADC.h
 *
 *  Created on: 13 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _ADC_H_
#define _ADC_H_

#include "../../2.Libraries/BIT_MATH.h"
#include "../../2.Libraries/STD_TYPES.h"
#include "ADC_private.h"
#include "ADC_config.h"

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7



u8 ADC_u8Initialization(void);
u8 ADC_u8ReadPin(u8 PinNO , u8* value);


#endif /* 4_MCAL_ADC_ADC_H_ */
