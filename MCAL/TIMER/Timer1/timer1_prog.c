#include "../../../Libraries/BIT_MATH.h"
#include "../../../Libraries/STD_TYPES.h"
#include "../../INTERRUPT/interrupt.h"
#include "../../DIO/DIO.h"
#include "timer1_int.h"


u8 Timer1_u8Initialization(void)
{
	u8 ErrorFlag=0;

/*  ------------------------------ Waveform Generation Mode : MODE0 ------------------------------------------- */
#if    Timer1_MODE == MODE0

	CLR_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE1

	SET_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE2

	CLR_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE3

	SET_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE4

	CLR_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE5

	SET_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE6

	CLR_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE7

	SET_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	CLR_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE8

	CLR_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE9

	SET_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE10

	CLR_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE11

	SET_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	CLR_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE12

	CLR_BIT( TCCR1A , 0 );
	CLR_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE13

	CLR_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#elif  Timer1_MODE == MODE14

	SET_BIT( TCCR1A , 0 );
	SET_BIT( TCCR1A , 1 );
	SET_BIT( TCCR1B , 3 );
	SET_BIT( TCCR1B , 4 );

#endif


/* - - - - - - - - - - - - - - - - - - OC1A PIN MODE SELECT - - - - - - - - - - - - - - - - - - - -*/
#if OC1A_MODE != _DISCONNECT

	DIO_u8SetPinDirection( PORT_D , PIN5 ,PIN_OUTPUT ); /* Set OC1A Pin as OUTPUT */

#if  OC1A_MODE == _TOGGLE_ON_MATCH
	SET_BIT( TCCR1A , 6 );
	CLR_BIT( TCCR1A , 7 );
#elif  OC1A_MODE == _CLEAR_ON_MATCH
	CLR_BIT( TCCR1A , 6 );
	SET_BIT( TCCR1A , 7 );
#elif  OC1A_MODE == _SET_ON_MATCH
	SET_BIT( TCCR1A , 6 );
	SET_BIT( TCCR1A , 7 );
#endif

#endif

/* - - - - - - - - - - - - - - - - - - OC1A PIN MODE SELECT - - - - - - - - - - - - - - - - - - - -*/
#if  OC1B_MODE != _DISCONNECT

	DIO_u8SetPinDirection( PORT_D , PIN4 ,PIN_OUTPUT ); /* Set OC1B Pin as OUTPUT */

#if    OC1B_MODE == _TOGGLE_ON_MATCH
	SET_BIT( TCCR1A , 4 );
	CLR_BIT( TCCR1A , 5 );
#elif  OC1B_MODE == _CLEAR_ON_MATCH
	CLR_BIT( TCCR1A , 4 );
	SET_BIT( TCCR1A , 5 );
#elif  OC1B_MODE == _SET_ON_MATCH
	SET_BIT( TCCR1A , 4 );
	SET_BIT( TCCR1A , 5 );
#endif

#endif


/*  --------------------------------- Timer1 Clock Prescaler  -------------------------------------- */
#if		 T1_PRESCALER_MODE == _NO_CLOCK
	CLR_BIT( TCCR1B , 0 );
	CLR_BIT( TCCR1B , 1 );
	CLR_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _NO_PRESCALE
	SET_BIT( TCCR1B , 0 );
	CLR_BIT( TCCR1B , 1 );
	CLR_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _CLK_8
	CLR_BIT( TCCR1B , 0 );
	SET_BIT( TCCR1B , 1 );
	CLR_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _CLK_64
	SET_BIT( TCCR1B , 0 );
	SET_BIT( TCCR1B , 1 );
	CLR_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _CLK_256
	CLR_BIT( TCCR1B , 0 );
	CLR_BIT( TCCR1B , 1 );
	SET_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _CLK_1024
	SET_BIT( TCCR1B , 0 );
	CLR_BIT( TCCR1B , 1 );
	SET_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _EXT_CLK_FALL
	CLR_BIT( TCCR1B , 0 );
	SET_BIT( TCCR1B , 1 );
	SET_BIT( TCCR1B , 2 );

#elif    T1_PRESCALER_MODE == _CLK_RISE
	SET_BIT( TCCR1B , 0 );
	SET_BIT( TCCR1B , 1 );
	SET_BIT( TCCR1B , 2 );

#endif

/* --------------------------------------- Enable Timer Interrupts ----------------------------------- */
#if T1A_INTERRUPT_ONCOMPARE == ENABLED

	SET_BIT( TIMSK , 4 );

#endif

#if T1B_INTERRUPT_ONCOMPARE == ENABLED

	SET_BIT( TIMSK , 3 );

#endif

#if T1_INTERRUPT_OVERFLOW == ENABLED

	SET_BIT( TIMSK , 2 );

#endif

#if T1_INTERRUPT_CAPTURE == ENABLED

	DIO_u8SetPinDirection( PORT_D , PIN6 ,PIN_INPUT ); /* ICP PIN */
	SET_BIT(PORTD,6); //ICP PULL UP
	SET_BIT( TIMSK , 5 );

#if  ICU_EDGE == RISING_EDGE

	SET_BIT( TCCR1B , 6 );

#endif

#if  ICU_NOISE_CANCELLER == ENABLED

	SET_BIT( TCCR1B , 7 );

#endif

#endif


	return ErrorFlag;
}

