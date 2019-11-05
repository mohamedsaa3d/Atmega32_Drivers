/*
 * ADC_private.h
 *
 *  Created on: 13 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_


#define ADCH   *( (volatile u8*)(0x25) )
#define ADCL   *( (volatile u8*)(0x24) )
#define ADCSRA *( (volatile u8*)(0x26) )
#define ADMUX  *( (volatile u8*)(0x27) )



#endif /* 4_MCAL_ADC_ADC_PRIVATE_H_ */
