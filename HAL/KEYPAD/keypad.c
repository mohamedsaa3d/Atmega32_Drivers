#include "keypad.h"
//#include "..\LCD\LCD_interface.h"

u8 Keypad_Initialization(void)
{
	u8 ErrorFlag=0;

	/*
	 * KEYPAD PORT LAYOUT
	 *
	 * C4 C3 C2 C1 | R4 R3 R2 R1
	 *
	 *---------------------------------------*
	 *         |         |         |         *
	 *    1    |    2    |    3    |    +    *
	 *---------------------------------------*
	 *         |         |         |         *
	 *    4    |    5    |    6    |    -    *
	 *---------------------------------------*
	 *         |         |         |         *
	 *    7    |    8    |    9    |    *    *
	 *---------------------------------------*
	 *         |         |         |         *
	 *   DEL   |    0    |  ENTER  |    /    *
	 *---------------------------------------*
	 */

	DIO_u8SetPortDirection( KEYPAD_PORT, 0xF0);
	DIO_u8SetPortValue(KEYPAD_PORT , PORT_HIGH );


	return ErrorFlag;
}

u8 Keypad_ReadKey(volatile u8* KeyValue , volatile u8* KeyPressedFlag)
{
	u8 ErrorFlag=0;

	u8 row_iteration;
	u8 col_iteration;

	u8 row_reading;

	u8 ReturnData=0;

	*KeyPressedFlag = 0; /*Setting the flag : indicates that no key is pressed yet , user must reset it after reading*/
	*KeyValue = 0;

	for ( col_iteration=0 ; col_iteration<4 ; col_iteration++ )
	{
		DIO_u8SetPinValue( KEYPAD_PORT, col_iteration+4 , PIN_LOW ); /*Connect the COLUMN to GND*/


		for ( row_iteration=0 ; row_iteration<4 ; row_iteration++ )
		{
			DIO_u8GetPinValue( KEYPAD_PORT, row_iteration , &row_reading );


			if( !row_reading ) /*Checking the ROW == 0*/
			{
				switch(row_iteration)
				{
					case 0:
						switch(col_iteration)
						{
							case 0:
								ReturnData=1;
								break;
							case 1:
								ReturnData=2;
								break;
							case 2:
								ReturnData=3;
								break;
							case 3:
								ReturnData='+';
								break;
						}
						break;
					case 1:
						switch(col_iteration)
						{
							case 0:
								ReturnData=4;
								break;
							case 1:
								ReturnData=5;
								break;
							case 2:
								ReturnData=6;
								break;
							case 3:
								ReturnData='-';
								break;
						}
						break;
					case 2:
						switch(col_iteration)
						{
							case 0:
								ReturnData=7;
								break;
							case 1:
								ReturnData=8;
								break;
							case 2:
								ReturnData=9;
								break;
							case 3:
								ReturnData='*';
								break;
						}
						break;
					case 3:
						switch(col_iteration)
						{
							case 0:
								ReturnData='D';
								break;
							case 1:
								ReturnData=0;
								break;
							case 2:
								ReturnData='E';
								break;
							case 3:
								ReturnData='/';
								break;
						}
						break;

				}

				*KeyPressedFlag = 1; /*Setting the flag : indicates that a key is pressed and ready to be send*/
				*KeyValue = ReturnData; /* Returning the pressed key value */
				_delay_ms(250);
			}


		}
		DIO_u8SetPinValue( KEYPAD_PORT, col_iteration+4 , PIN_HIGH ); /*Connect the COLUMN to GND*/

	}

	return ErrorFlag;
}
