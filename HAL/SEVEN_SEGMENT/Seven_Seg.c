
#include "SEVEN_SEG.h"


/**********************/
/*       __a__        */
/*      |     |       */
/*      f _g_ b       */
/*      e     c       */
/*      |__d__|(dot)  */
/*                    */
/**********************/

SevenSEG Struct_SEVEN_SEGMENT ;

u8 Seven_SEG_u8Initilization(void)
{
	u8 u8ErrorState = 0;


	/* Setting the Seven Segment pins as OUTPUT */
	DIO_u8SetPinDirection( LED_A_PORT   , LED_A_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_B_PORT   , LED_B_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_C_PORT   , LED_C_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_D_PORT   , LED_D_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_E_PORT   , LED_E_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_F_PORT   , LED_F_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_G_PORT   , LED_G_PIN   , OUTPUT );
	DIO_u8SetPinDirection( LED_DOT_PORT , LED_DOT_PIN , OUTPUT );

	SevenSEG_u8WriteDigit(0);

	return u8ErrorState;
}

u8 SevenSEG_u8WriteDigit( u8 u8Digit )
{
	u8 u8ErrorState = 0;

	if ( 0 <= u8Digit && u8Digit <= 9 )
	{
		switch(u8Digit)
		{
			case ZERO:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_ON;
				Struct_SEVEN_SEGMENT.f   = LED_ON;
				Struct_SEVEN_SEGMENT.g   = LED_OFF;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case ONE:
				Struct_SEVEN_SEGMENT.a   = LED_OFF;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_OFF;
				Struct_SEVEN_SEGMENT.e   = LED_OFF;
				Struct_SEVEN_SEGMENT.f   = LED_OFF;
				Struct_SEVEN_SEGMENT.g   = LED_OFF;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case TWO:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_OFF;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_ON;
				Struct_SEVEN_SEGMENT.f   = LED_OFF;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case THREE:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_OFF;
				Struct_SEVEN_SEGMENT.f   = LED_OFF;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case FOUR:
				Struct_SEVEN_SEGMENT.a   = LED_OFF;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_OFF;
				Struct_SEVEN_SEGMENT.e   = LED_OFF;
				Struct_SEVEN_SEGMENT.f   = LED_ON;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case FIVE:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_OFF;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_OFF;
				Struct_SEVEN_SEGMENT.f   = LED_ON;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case SIX:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_OFF;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_ON;
				Struct_SEVEN_SEGMENT.f   = LED_ON;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case SEVEN:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_OFF;
				Struct_SEVEN_SEGMENT.e   = LED_OFF;
				Struct_SEVEN_SEGMENT.f   = LED_OFF;
				Struct_SEVEN_SEGMENT.g   = LED_OFF;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case EIGHT:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_ON;
				Struct_SEVEN_SEGMENT.f   = LED_ON;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

			case NINE:
				Struct_SEVEN_SEGMENT.a   = LED_ON;
				Struct_SEVEN_SEGMENT.b   = LED_ON;
				Struct_SEVEN_SEGMENT.c   = LED_ON;
				Struct_SEVEN_SEGMENT.d   = LED_ON;
				Struct_SEVEN_SEGMENT.e   = LED_OFF;
				Struct_SEVEN_SEGMENT.f   = LED_ON;
				Struct_SEVEN_SEGMENT.g   = LED_ON;
				Struct_SEVEN_SEGMENT.dot = LED_OFF;
				break;

		}



		/* Writing the data to the pins */
		DIO_u8SetPinValue( LED_A_PORT   , LED_A_PIN   , Struct_SEVEN_SEGMENT.a   );
		DIO_u8SetPinValue( LED_B_PORT   , LED_B_PIN   , Struct_SEVEN_SEGMENT.b   );
		DIO_u8SetPinValue( LED_C_PORT   , LED_C_PIN   , Struct_SEVEN_SEGMENT.c   );
		DIO_u8SetPinValue( LED_D_PORT   , LED_D_PIN   , Struct_SEVEN_SEGMENT.d   );
		DIO_u8SetPinValue( LED_E_PORT   , LED_E_PIN   , Struct_SEVEN_SEGMENT.e   );
		DIO_u8SetPinValue( LED_F_PORT   , LED_F_PIN   , Struct_SEVEN_SEGMENT.f   );
		DIO_u8SetPinValue( LED_G_PORT   , LED_G_PIN   , Struct_SEVEN_SEGMENT.g   );
		DIO_u8SetPinValue( LED_DOT_PORT , LED_DOT_PIN , Struct_SEVEN_SEGMENT.dot );
	}
	else
	{
		/* Invalid input Digit*/
		u8ErrorState = 1;
	}



	return u8ErrorState;
}
