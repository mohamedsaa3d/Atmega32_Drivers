#include "../../../2.Libraries/BIT_MATH.h"
#include "../../../2.Libraries/STD_TYPES.h"
#include "../../INTERRUPT/interrupt.h"
#include "../../DIO/DIO.h"
#include "timer0_int.h"

u8 Timer0_u8Initialization(void)
{
	u8 ErrorFlag=0;


/*  ------------------------------ Waveform Generation Mode : NORMAL ------------------------------------------- */
#if    Timer0_MODE == _NORMAL

	CLR_BIT( TCCR0 , 3 );
	CLR_BIT( TCCR0 , 6 );

/*  ------------------------- Waveform Generation Mode : PWM PHASE CORRECT  ----------------------------------- */
#elif  Timer0_MODE == _PWM_PHASE_CORRECT

	CLR_BIT( TCCR0 , 3 );
	SET_BIT( TCCR0 , 6 );

/*  -------------------------------- Waveform Generation Mode : CTC ------------------------------------------- */
#elif  Timer0_MODE == _CTC

	SET_BIT( TCCR0 , 3 );
	CLR_BIT( TCCR0 , 6 );


/*  ------------------------------- Waveform Generation Mode : FAST PWM  -------------------------------------- */
#elif  Timer0_MODE == _FAST_PWM

	SET_BIT( TCCR0 , 3 );
	SET_BIT( TCCR0 , 6 );

#endif


/* - - - - - - - - - - - - - - - -Initialize Compare Match Register - - - - - - - - - - - - - - - */

#if Timer0_MODE == _CTC || Timer0_MODE == _FAST_PWM || Timer0_MODE == _PWM_PHASE_CORRECT
//
	OCR0 = OCR_InitialValue;

	DIO_u8SetPinDirection( PORT_B , PIN3 ,PIN_OUTPUT ); /* Set OC0 Pin as OUTPUT */

/* - - - - - - - - - - - - - - - - - - OC0 PIN MODE SELECT - - - - - - - - - - - - - - - - - - - -*/
#if    OC0_MODE == _DISCONNECT
	CLR_BIT( TCCR0 , 4 );
	CLR_BIT( TCCR0 , 5 );
#elif  OC0_MODE == _TOGGLE_ON_MATCH
	SET_BIT( TCCR0 , 4 );
	CLR_BIT( TCCR0 , 5 );
#elif  OC0_MODE == _CLEAR_ON_MATCH
	CLR_BIT( TCCR0 , 4 );
	SET_BIT( TCCR0 , 5 );
#elif  OC0_MODE == _SET_ON_MATCH
	SET_BIT( TCCR0 , 4 );
	SET_BIT( TCCR0 , 5 );
#endif

#endif

	/*  --------------------------------- Timer Clock Prescaler  -------------------------------------- */
#if		 T0_PRESCALER_MODE == _NO_CLOCK
	CLR_BIT( TCCR0 , 0 );
	CLR_BIT( TCCR0 , 1 );
	CLR_BIT( TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _NO_PRESCALE
	SET_BIT(TCCR0 , 0 );
	CLR_BIT(TCCR0 , 1 );
	CLR_BIT(TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _CLK_8
	CLR_BIT(TCCR0 , 0 );
	SET_BIT(TCCR0 , 1 );
	CLR_BIT(TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _CLK_64
	SET_BIT(TCCR0 , 0 );
	SET_BIT(TCCR0 , 1 );
	CLR_BIT(TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _CLK_256
	CLR_BIT(TCCR0 , 0 );
	CLR_BIT(TCCR0 , 1 );
	SET_BIT(TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _CLK_1024
	SET_BIT(TCCR0 , 0 );
	CLR_BIT(TCCR0 , 1 );
	SET_BIT(TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _EXT_CLK_FALL
	CLR_BIT(TCCR0 , 0 );
	SET_BIT(TCCR0 , 1 );
	SET_BIT(TCCR0 , 2 );

#elif    T0_PRESCALER_MODE == _CLK_RISE
	SET_BIT(TCCR0 , 0 );
	SET_BIT(TCCR0 , 1 );
	SET_BIT(TCCR0 , 2 );

#endif


/* -------------------- Enable Timer Interrupt : Timer/Counter0 Overflow Interrupt Enable --------------------- */
#if T0_INTERRUPT_OVERFLOW == ENABLED

	SET_BIT( TIMSK , 0 );

#endif

#if T0_INTERRUPT_ONCOMPARE == ENABLED

	SET_BIT( TIMSK , 1 );

#endif



/* ---------------------------------------- Timer 1 : Interrupt  --------------------------------------------*/
	//SET_BIT( TIMSK , 5 ); //ICU


/* ------------------------------------ Initialize TCNT0 (Counter Value) ---------------------------------------*/
//#if Timer0_MODE != T0_CTC
//	TCNT0 = 0x00;
//	/*
//	 *  As modifying the counter (TCNT0) while the counter is running, introduces a risk of missing
//	 *  a compare match between TCNT0 and the OCR0 Register.
//	 */
//#endif

	return ErrorFlag;

}


//u8 Timer0_u8StopTimer(void)
//{
//	u8 ErrorFlag=0;
//
//	CLR_BIT(TCCR0 , 0 );
//	CLR_BIT(TCCR0 , 1 );
//	CLR_BIT(TCCR0 , 2 );
//
//	return ErrorFlag;
//
//}
//
//
//u8 Timer0_u8ISR(void)
//{
//	u8 ErrorFlag=0;
//
//	/* Clear Interrupt Flag */
//	SET_BIT( TIFR , 0 );
//
//	return ErrorFlag;
//}
//
//
//u8 Timer0_u8SetISR(void)
//{
//	u8 ErrorFlag=0;
//
//
//	return ErrorFlag;
//
//}
