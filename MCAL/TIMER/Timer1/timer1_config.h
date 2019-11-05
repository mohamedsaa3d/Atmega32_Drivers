/*
 * timer_config.h
 *
 *  Created on: 20 Apr 2019
 *      Author: MohamedSaa3D
 */

#ifndef _TIMER1_CONFIG_H_
#define _TIMER1_CONFIG_H_


/*----------------------------------------------------------------------------------------------------*/
/* --------------------------------- T I M E R ( 1 )  C O N T R O L ----------------------------------*/
/*----------------------------------------------------------------------------------------------------*/
/*
                                   Select Waveform Generation Mode :

    ---------------------------------------------------------------------------------------------------
    Mode of Operation                            TOP               Update of OCR1x     TOV1 Flag Set On
	---------------------------------------------------------------------------------------------------
	MODE0  : Normal                              0xFFFF            Immediate           MAX
	MODE1  : PWM, Phase Correct, 8-bit           0x00FF            TOP                 BOTTOM
	MODE2  : PWM, Phase Correct, 9-bit           0x01FF            TOP                 BOTTOM
	MODE3  : PWM, Phase Correct, 10-bit          0x03FF            TOP                 BOTTOM
	MODE4  : CTC                                 OCR1A             Immediate           MAX
	MODE5  : Fast PWM, 8-bit                     0x00FF            TOP                 TOP
	MODE6  : Fast PWM, 9-bit                     0x01FF            TOP                 TOP
	MODE7  : Fast PWM, 10-bit                    0x03FF            TOP                 TOP
	MODE8  : PWM, Phase and Frequency Correct    ICR1              BOTTOM              BOTTOM     (NOTE: ICU DISABLED)
	MODE9  : PWM, Phase and Frequency Correct    OCR1A             BOTTOM              BOTTOM
	MODE10 : PWM, Phase Correct                  ICR1              TOP                 BOTTOM     (NOTE: ICU DISABLED)
	MODE11 : PWM, Phase Correct                  OCR1A             TOP                 BOTTOM
	MODE12 : CTC                                 ICR1              Immediate           MAX        (NOTE: ICU DISABLED)
	MODE13 : Fast PWM                            ICR1              TOP                 TOP        (NOTE: ICU DISABLED)
	MODE14 : Fast PWM                            OCR1A             TOP                 TOP
*/

#define Timer1_MODE        MODE0

/*
 * Select Compare Match Output PIN Mode :
 * (_DISCONNECT / _TOGGLE_ON_MATCH / _CLEAR_ON_MATCH / _SET_ON_MATCH)
 */
#define OC1A_MODE          _DISCONNECT
#define OC1B_MODE          _DISCONNECT


//#define OCR_InitialValue   0xFF

/*
 * Select Prescaler :
 * (_NO_CLOCK / _NO_PRESCALE / _CLK_8 / _CLK_64 / _CLK_256 / _CLK_1024 / _EXT_CLK_FALL / _EXT_CLK_RISE )
 */
#define T1_PRESCALER_MODE     _NO_CLOCK

/*
 * Timer 1 Interrupt Control
 * */
#define T1A_INTERRUPT_ONCOMPARE    DISABLED
#define T1B_INTERRUPT_ONCOMPARE    DISABLED

#define T1_INTERRUPT_OVERFLOW      DISABLED
#define T1_INTERRUPT_CAPTURE       DISABLED
#define ICU_EDGE                   RISING_EDGE
#define ICU_NOISE_CANCELLER        DISABLED




#endif /* _TIMER_CONFIG_H_ */
