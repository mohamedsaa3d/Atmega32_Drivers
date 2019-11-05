/*
 * DIO_prog.c
 *
 *  Created on: 23 Mar 2019
 *      Author: MohamedSaa3D
 */

#include "DIO.h"
#include "../../2.Libraries/BIT_MATH.h"
#include "../../2.Libraries/STD_TYPES.h"


u8 DIO_u8SetPinDirection(u8 u8PortNO , u8 u8PinNO , u8 u8Dir )
{
	/* Function internal Error Flag */
	u8 u8ErrorState = 0;

	/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
	if (    ( u8PortNO      <=  DIO_PORTD_INDEX   )
	     && ( u8PinNO       <=  HIGHEST_PIN_INDEX )
	     && (( DIO_OUTPUT_DIR   == u8Dir )  ||  ( DIO_INPUT_DIR ==  u8Dir ))
	   )
	{
		/* Fetching the port number index */
		switch( u8PortNO )
			{
				case DIO_PORTA_INDEX:
					if( DIO_OUTPUT_DIR == u8Dir )
					{
						/* The pin is requested to be O/P */
						SET_BIT( DDRA ,u8PinNO );
					}
					else if (DIO_INPUT_DIR == u8Dir )
					{
						/* The pin is requested to be I/P */
						CLR_BIT( DDRA ,u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

				case DIO_PORTB_INDEX:
					if( DIO_OUTPUT_DIR == u8Dir )
					{
						/* The pin is requested to be O/P */
						SET_BIT( DDRB,u8PinNO );
					}
					else if (DIO_INPUT_DIR == u8Dir )
					{
						/* The pin is requested to be I/P */
						CLR_BIT( DDRB,u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

				case DIO_PORTC_INDEX:
					if( DIO_OUTPUT_DIR == u8Dir )
					{
						/* The pin is requested to be O/P */
						SET_BIT( DDRC,u8PinNO );
					}
					else if (DIO_INPUT_DIR == u8Dir )
					{
						/* The pin is requested to be I/P */
						CLR_BIT( DDRC,u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

				case DIO_PORTD_INDEX:
					if( DIO_OUTPUT_DIR == u8Dir )
					{
						/* The pin is requested to be O/P */
						SET_BIT( DDRD,u8PinNO );
					}
					else if (DIO_INPUT_DIR == u8Dir )
					{
						/* The pin is requested to be I/P */
						CLR_BIT( DDRD,u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

			}
	}
	else
	{
		u8ErrorState = 1;
	}

	return u8ErrorState;

}

u8 DIO_u8SetPinValue( u8 u8PortNO , u8 u8PinNO , u8 u8Value  )
{
	/* Function internal Error Flag */
	u8 u8ErrorState = 0;

	/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
	if (    ( u8PortNO      <=  DIO_PORTD_INDEX   )
	     && ( u8PinNO       <=  HIGHEST_PIN_INDEX )
	     && (( DIO_PIN_LOW   == u8Value  )  ||  ( DIO_PIN_HIGH ==  u8Value ))
	   )
	{
		/* Fetching the port number index */
		switch( u8PortNO )
			{
				case DIO_PORTA_INDEX:
					if( DIO_PIN_LOW == u8Value )
					{
						/* The pin is requested to be LOW */
						CLR_BIT( PORTA , u8PinNO );
					}
					else if (DIO_PIN_HIGH == u8Value )
					{
						/* The pin is requested to be HIGH */
						SET_BIT( PORTA , u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

				case DIO_PORTB_INDEX:
					if( DIO_PIN_LOW == u8Value )
					{
						/* The pin is requested to be LOW */
						CLR_BIT( PORTB , u8PinNO );
					}
					else if (DIO_PIN_HIGH == u8Value )
					{
						/* The pin is requested to be HIGH */
						SET_BIT( PORTB , u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

				case DIO_PORTC_INDEX:
					if( DIO_PIN_LOW == u8Value )
					{
						/* The pin is requested to be LOW */
						CLR_BIT( PORTC , u8PinNO );
					}
					else if (DIO_PIN_HIGH == u8Value )
					{
						/* The pin is requested to be HIGH */
						SET_BIT( PORTC , u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

				case DIO_PORTD_INDEX:
					if( DIO_PIN_LOW == u8Value )
					{
						/* The pin is requested to be LOW */
						CLR_BIT( PORTD , u8PinNO );
					}
					else if (DIO_PIN_HIGH == u8Value )
					{
						/* The pin is requested to be HIGH */
						SET_BIT( PORTD , u8PinNO );
					}
					else
					{
						/* Wrong Direction index */
					}
					break;

			}
	}
	else
	{
		u8ErrorState = 1;
	}

	return u8ErrorState;
}


u8 DIO_u8GetPinValue( u8 u8PortNO , u8 u8PinNO , u8* u8Value )
{
	/* Function internal Error Flag */
	u8 u8ErrorState = 0;

	/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
	if (     ( u8PortNO   <=  DIO_PORTD_INDEX   )
		  && ( u8PinNO    <=  HIGHEST_PIN_INDEX )
		  && ( NULL       !=  u8Value           )
	   )
	{
		/* Fetching the port number index */
		switch( u8PortNO )
			{
				case DIO_PORTA_INDEX:
					/* Returning the PIN value */
					*u8Value = GET_BIT( PINA , u8PinNO );
					break;

				case DIO_PORTB_INDEX:
					/* Returning the PIN value */
					*u8Value = GET_BIT( PINB , u8PinNO );
					break;

				case DIO_PORTC_INDEX:
					/* Returning the PIN value */
					*u8Value = GET_BIT( PINC , u8PinNO );
					break;

				case DIO_PORTD_INDEX:
					/* Returning the PIN value */
					*u8Value = GET_BIT( PIND , u8PinNO );
					break;

			}
	}
	else
	{
		u8ErrorState = 1;
	}

	return u8ErrorState;
}

/*------------------------------------------------------------------------------------*/

u8 DIO_u8SetPortDirection(u8 u8PortNO , u8 u8Dir )
{
	/* Function internal Error Flag */
	u8 u8ErrorState = 0;

	/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
	if (  ( u8PortNO <= DIO_PORTD_INDEX )&&(  PORT_OUTPUT >= u8Dir )  )
	{
		/* Fetching the port number index */
		switch( u8PortNO )
			{
				case DIO_PORTA_INDEX:

					DDRA = u8Dir;
					break;

				case DIO_PORTB_INDEX:

					DDRB = u8Dir;
					break;

				case DIO_PORTC_INDEX:

					DDRC = u8Dir;
					break;

				case DIO_PORTD_INDEX:

					DDRD = u8Dir;
					break;

			}
	}
	else
	{
		u8ErrorState = 1;
	}

	return u8ErrorState;

}

u8 DIO_u8SetPortValue( u8 u8PortNO , u8 u8Value  )
{
	/* Function internal Error Flag */
	u8 u8ErrorState = 0;

	/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
	if (    ( u8PortNO  <=  DIO_PORTD_INDEX ) && (PORT_HIGH >=  u8Value)  )
	{
		/* Fetching the port number index */
		switch( u8PortNO )
			{
				case DIO_PORTA_INDEX:

					PORTA = u8Value;
					break;

				case DIO_PORTB_INDEX:

					PORTB = u8Value;
					break;

				case DIO_PORTC_INDEX:

					PORTC = u8Value;
					break;

				case DIO_PORTD_INDEX:

					PORTD = u8Value;
					break;
			}
	}
	else
	{
		u8ErrorState = 1;
	}

	return u8ErrorState;
}

u8 DIO_u8GetPortValue( u8 u8PortNO , u8* u8Value )
{
	/* Function internal Error Flag */
	u8 u8ErrorState = 0;

	/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
	if (    ( u8PortNO   <=  DIO_PORTD_INDEX ) && ( NULL  !=  u8Value )    )
	{
		/* Fetching the port number index */
		switch( u8PortNO )
			{
				case DIO_PORTA_INDEX:
					/* Returning the PORTA value */
					*u8Value = PINA;
					break;

				case DIO_PORTB_INDEX:
					/* Returning the PORTB value */
					*u8Value = PINB;
					break;

				case DIO_PORTC_INDEX:
					/* Returning the PORTC value */
					*u8Value = PINC;
					break;

				case DIO_PORTD_INDEX:
					/* Returning the PORTD value */
					*u8Value = PIND;
					break;
			}
	}
	else
	{
		u8ErrorState = 1;
	}

	return u8ErrorState;
}

u8 DIO_u8SetNibbleDirection( u8 u8PortNO, u8 NibbleDir , Nibble SelectNibble )
{
	/* Function internal Error Flag */
		u8 u8ErrorState = 0;

		/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
		if (  ( u8PortNO <= DIO_PORTD_INDEX )  )
		{
			/* Fetching the port number index */

			if(SelectNibble==LOWER)
			{
				DIO_u8SetPinDirection(u8PortNO , PIN0 , GET_BIT(NibbleDir,PIN0) );
				DIO_u8SetPinDirection(u8PortNO , PIN1 , GET_BIT(NibbleDir,PIN1) );
				DIO_u8SetPinDirection(u8PortNO , PIN2 , GET_BIT(NibbleDir,PIN2) );
				DIO_u8SetPinDirection(u8PortNO , PIN3 , GET_BIT(NibbleDir,PIN3) );
			}
			else if(SelectNibble==HIGHER)
			{
				DIO_u8SetPinDirection(u8PortNO , PIN4 , GET_BIT(NibbleDir,PIN0) );
				DIO_u8SetPinDirection(u8PortNO , PIN5 , GET_BIT(NibbleDir,PIN1) );
				DIO_u8SetPinDirection(u8PortNO , PIN6 , GET_BIT(NibbleDir,PIN2) );
				DIO_u8SetPinDirection(u8PortNO , PIN7 , GET_BIT(NibbleDir,PIN3) );
			}
			else
			{
				/*Invalid Input*/
				u8ErrorState = 1;
			}
		}
		else
		{
			u8ErrorState = 1;
		}

		return u8ErrorState;

}

u8 DIO_u8SetNibbleValue( u8 u8PortNO, u8 NibbleValue , Nibble SelectNibble )
{
	/* Function internal Error Flag */
		u8 u8ErrorState = 0;

		/* Invalid Input Protection : checking if the arguments indexes are in a valid range */
		if (  ( u8PortNO <= DIO_PORTD_INDEX )  )
		{
			/* Fetching the port number index */

			if(SelectNibble==LOWER)
			{
				DIO_u8SetPinValue(u8PortNO , PIN0 , GET_BIT(NibbleValue,PIN0) );
				DIO_u8SetPinValue(u8PortNO , PIN1 , GET_BIT(NibbleValue,PIN1) );
				DIO_u8SetPinValue(u8PortNO , PIN2 , GET_BIT(NibbleValue,PIN2) );
				DIO_u8SetPinValue(u8PortNO , PIN3 , GET_BIT(NibbleValue,PIN3) );
			}
			else if(SelectNibble==HIGHER)
			{
				DIO_u8SetPinValue(u8PortNO , PIN4 , GET_BIT(NibbleValue,PIN0) );
				DIO_u8SetPinValue(u8PortNO , PIN5 , GET_BIT(NibbleValue,PIN1) );
				DIO_u8SetPinValue(u8PortNO , PIN6 , GET_BIT(NibbleValue,PIN2) );
				DIO_u8SetPinValue(u8PortNO , PIN7 , GET_BIT(NibbleValue,PIN3) );
			}
			else
			{
				/*Invalid Input*/
				u8ErrorState = 1;
			}
		}
		else
		{
			u8ErrorState = 1;
		}

		return u8ErrorState;
}
