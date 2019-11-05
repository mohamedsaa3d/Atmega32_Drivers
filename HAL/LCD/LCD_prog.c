#include "util/delay.h"

#include "LCD_interface.h"

#define F_CPU 8000000UL

u8 LCD_u8StatusBYTE ;

u8 LCD_u8ReadStatus(void)
{
	u8 ErrorFlag = 0;

	DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_RS , PIN_LOW);  /* RS : IR*/
	DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_RW , PIN_HIGH);  /* RW : Read*/


	DIO_u8GetPortValue(LCD_DATA_PORT , &LCD_u8StatusBYTE);

	DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN */
	_delay_ms(2);
	DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);  /* EN */

	return ErrorFlag;
}


u8 LCD_u8Initialization(void)
{
	u8 ErrorFlag = 0;

	/* Command Control PINS Config */
	DIO_u8SetPinDirection(LCD_CONTROL_PORT , LCD_RS , PIN_OUTPUT); /* RS */
	DIO_u8SetPinDirection(LCD_CONTROL_PORT , LCD_RW , PIN_OUTPUT); /* RW */
	DIO_u8SetPinDirection(LCD_CONTROL_PORT , LCD_EN , PIN_OUTPUT); /* EN */

	/* Data Bus PINS Config */
#if   LCD_TYPE == 4
	/* Setting the higher port nibble as o/p */
	DIO_u8SetNibbleDirection(LCD_DATA_PORT,NIBBLE_OUTPUT,LCD_DATA_NIBBLE);

#elif   LCD_TYPE == 8

	DIO_u8SetPortDirection(LCD_DATA_PORT , PORT_OUTPUT); /* Setting the full port 8-bits as o/p */

#endif

	/* Wait for 15ms, Power on initialization time  */
	_delay_ms(25);

	/*  DATA_LENGTH (4/8-Bit) /  NO_OF_LINES (2-Lines) /  FONT (5x11 dots) */

	LCD_u8WriteCMD( FunctionSet );

	_delay_ms(10);

	/*  Display (ON) /  CURSOR (ON) /  BLINKING (ON) */
	LCD_u8WriteCMD( DisplayControl );

	_delay_ms(5);

	LCD_u8WriteCMD( ClearDisplay );

	_delay_ms(5);


	return ErrorFlag;

}

u8 LCD_u8WriteCMD( s8 CMD )
{
	u8 ErrorFlag = 0;

	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_RS , PIN_LOW);  /* RS */
	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_RW , PIN_LOW);  /* RW */
	 _delay_ms(1);
	 /*_________________________________________________________________________________*/
	 #if   LCD_TYPE == 4

	 	 /* Sending the high nibble (4-bits) */
	 	 DIO_u8SetNibbleValue(LCD_DATA_PORT,  (CMD>>4)  ,LCD_DATA_NIBBLE);

	 	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN Trigger */
	 	 _delay_ms(1);
	 	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);   /* EN Trigger */

	 	 _delay_ms(5);

	 	 /* Sending the low nibble (4-bits) */
	 	DIO_u8SetNibbleValue(LCD_DATA_PORT, CMD ,LCD_DATA_NIBBLE);

	 	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN Trigger */
	 	 _delay_ms(1);
	 	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);   /* EN Trigger */

	 #elif LCD_TYPE == 8

	 	 DIO_u8SetPortValue(LCD_DATA_PORT    , CMD );

	 	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN Trigger */
	 	 _delay_ms(2);
	 	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);  /* EN Trigger */

	 #endif
	 /*_________________________________________________________________________________*/


	 return ErrorFlag;
}


u8 LCD_u8WriteDATA( s8 DATA )
{
	u8 ErrorFlag = 0;


	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_RS , PIN_HIGH);  /* RS */
	 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_RW , PIN_LOW );  /* RW */
	 _delay_ms(1);

	 /*_________________________________________________________________________________*/
	 #if   LCD_TYPE == 4

		 /* Sending the high nibble (4-bits) */
	 	 DIO_u8SetNibbleValue(LCD_DATA_PORT,  (DATA>>4)  ,LCD_DATA_NIBBLE);

		 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN Trigger */
		 _delay_ms(1);
		 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);   /* EN Trigger */

		 _delay_ms(5);

		 /* Sending the low nibble (4-bits) */
	     DIO_u8SetNibbleValue(LCD_DATA_PORT,  DATA   ,LCD_DATA_NIBBLE);

		 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN Trigger */
		 _delay_ms(1);
		 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);   /* EN Trigger */

	 #elif LCD_TYPE == 8

		 DIO_u8SetPortValue(LCD_DATA_PORT    , DATA );

		 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_HIGH);  /* EN Trigger */
		 _delay_ms(2);
		 DIO_u8SetPinValue (LCD_CONTROL_PORT , LCD_EN , PIN_LOW);  /* EN Trigger */

	 #endif
	 /*_________________________________________________________________________________*/


	 return ErrorFlag;
}


u8 LCD_u8WriteLINE(s8 DATA[])
{
	u8 ErrorFlag = 0;
	u8 loop_index = 0;

	while( DATA[loop_index] != '\0' )
	{
		LCD_u8WriteDATA( DATA[loop_index] );
		loop_index++;
	}

	return ErrorFlag;
}

u8 LCD_u8WriteNUMBER(s32 DATA)
{
	u8 ErrorFlag = 0;
	u32 Temp = 1;
	u8 counts=0;

	if(DATA<0)
	{
		DATA = DATA * -1;
		LCD_u8WriteDATA('-');
	}
	else if(DATA==0)
	{
		LCD_u8WriteDATA('0');
	}

	while(DATA !=0 )
	{
		/* Reversing the Number */
		Temp = (Temp*10) + (DATA%10);
		DATA=DATA/10;
		counts++;
	}
	while(counts !=0 )
	{
		LCD_u8WriteDATA( (Temp%10)+'0' );
		Temp = Temp/10;
		counts--;
	}

	return ErrorFlag;
}

u8 LCD_u8GOTO_XY(u8 X_AXIS, u8 Y_AXIS)
{
	u8 ErrorFlag = 0;

	if(X_AXIS<=16 && Y_AXIS<=2)
	{
		if( 1 == Y_AXIS )
		{
			LCD_u8WriteCMD( FISRT_LINE_POS + X_AXIS-1 );
		}
		else if( 2 == Y_AXIS )
		{
			LCD_u8WriteCMD( SECOND_LINE_POS + X_AXIS-1 );
		}
	}
	else
	{
		ErrorFlag=1;
	}


	return ErrorFlag;
}

u8 LCD_u8GeneratePattern()
{
	u8 ErrorFlag = 0;

	/* Set DDRAM address in address Counter. */
	LCD_u8WriteCMD( CGRAM_ADDRESS );
	/* Start Writing the pattern */
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x0F );
	LCD_u8WriteDATA( 0x09 );
	LCD_u8WriteDATA( 0x09 );
	LCD_u8WriteDATA( 0x1F );
	LCD_u8WriteDATA( 0x00 );

	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x0C );
	LCD_u8WriteDATA( 0x02 );
	LCD_u8WriteDATA( 0x1F );
	LCD_u8WriteDATA( 0x00 );

	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x00 );
	LCD_u8WriteDATA( 0x01 );
	LCD_u8WriteDATA( 0x01 );
	LCD_u8WriteDATA( 0x07 );
	LCD_u8WriteDATA( 0x00 );

	LCD_u8WriteCMD( ClearDisplay );


	return ErrorFlag;
}
