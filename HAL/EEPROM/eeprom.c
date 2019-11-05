#include "../../4.MCAL/I2C/i2c_int.h"
#include "eeprom_int.h"

#include "../../3.HAL/LCD/LCD_interface.h"
#include "util/delay.h"

extern u8 TargetSlaveADDRESS;


u8 EEPROM_u8WriteBYTE(u8 DATE_BYTE ,u16 ByteNO)
{
	u8 ErrorFlag = 0;

	if( ByteNO>=0 && ByteNO<=1023 )
	{
		/* Forming the Slave Address + select (Read/Write) mode */
		EEPROM_u8FormingSlaveAddress(ByteNO,W);
		/* Sending Start Bit followed by [ the Slave Address + (Read/Write) ] to start the communication */
		I2C_StarTrasnmit();
		/* Sending Memory Location Address scaled from 0 TO 255 for each EEPROM memory block (4 Blocks)  */
		I2C_u8SendDATA(  ByteNO % 256 );
		/* Writing the required DATA Byte to the memory location  */
		I2C_u8SendDATA(DATE_BYTE);
		/* Terminating the communication */
		I2C_u8StopTransmit();

	}
	else
	{
		/* Invalid Case : Error Flag will be set & function will exit */
		ErrorFlag = 1;
	}

	return ErrorFlag;
}


u8 EEPROM_u8ReadBYTE( u16 ByteNO , u8 *DATE_BYTE )
{
	u8 ErrorFlag = 0;

	if( ByteNO>=0 && ByteNO<=1023 )
	{
		/* Forming the Slave Address */
		EEPROM_u8FormingSlaveAddress(ByteNO,W);
		I2C_StarTrasnmit();
		I2C_u8SendDATA(  ByteNO % 256 ); /* Sending Memory Location Address = ByteNO % 256  */
		EEPROM_u8FormingSlaveAddress(ByteNO,R);       /* Storing the required DATA Byte                  */
		I2C_StarTrasnmit();
		I2C_u8readDATA( DATE_BYTE );
		I2C_u8StopTransmit();

	}
	else
	{
		/* Invalid Case : Error Flag will be set & function will exit */
		ErrorFlag = 1;
	}


	return ErrorFlag;
}

u8 EEPROM_u8FormingSlaveAddress( u16 ByteNO, enumDATA_RW RW )
{
	u8 ErrorFlag = 0;


	/* Forming the Slave Address :
	 *
	 * EEPROM Control Byte:
	 *       -----------------------------------------------------
	 *      | SLA3 | SLA2 | SLA1 | SLA0 |  E  |  B1  |  B0  | R/W |
	 *       -----------------------------------------------------
	 *       SLA : EEPROM ADDRESS NIBBLE (1010)
	 *       E   : Enable pin in the EEPROM chip (must be 1/0 according to the physical chip wiring)
	 *       B   : Memory Block selection (EEPROM has 4 memory blocks)
	 *       R/W : Select whether we want to read or write to the EEPROM
	 *
	 * */

	/* Selecting the EEPROM block to access : using 2-bits ( BlockSelect1 , BlockSelect0 ) */
	switch (RW)
	{
		case R:
		{
			if ( ByteNO>=0 && ByteNO<=255 )
			{
				/*  EEPROM MEMORY SEGMENT NO.1  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,0,0,EEPROM_READ_BIT)  );
			}
			else if ( ByteNO>=256 && ByteNO<=511 )
			{
				/*  EEPROM MEMORY SEGMENT NO.2  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,0,1,EEPROM_READ_BIT)  );
			}
			else if ( ByteNO>=512 && ByteNO<=767 )
			{
				/*  EEPROM MEMORY SEGMENT NO.3  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,1,0,EEPROM_READ_BIT)  );
			}
			else if ( ByteNO>=768 && ByteNO<=1023 )
			{
				/*  EEPROM MEMORY SEGMENT NO.4  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,1,1,EEPROM_READ_BIT)  );
			}
			else
			{
				/* Invalid Case : Error Flag will be set & function will exit */
				ErrorFlag = 1;
			}
		}
			break;


		case W:
		{
			if ( ByteNO>=0 && ByteNO<=255 )
			{
				/*  EEPROM MEMORY SEGMENT NO.1  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,0,0,EEPROM_WRITE_BIT)  );
			}
			else if ( ByteNO>=256 && ByteNO<=511 )
			{
				/*  EEPROM MEMORY SEGMENT NO.2  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,0,1,EEPROM_WRITE_BIT)  );
			}
			else if ( ByteNO>=512 && ByteNO<=767 )
			{
				/*  EEPROM MEMORY SEGMENT NO.3  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,1,0,EEPROM_WRITE_BIT)  );
			}
			else if ( ByteNO>=768 && ByteNO<=1023 )
			{
				/*  EEPROM MEMORY SEGMENT NO.4  */
				TargetSlaveADDRESS = NIBBLES_MERGE( DeviceAddress ,  NIBBLE_CONC( ENABLE_PIN ,1,1,EEPROM_WRITE_BIT)  );
			}
			else
			{
				/* Invalid Case : Error Flag will be set & function will exit */
				ErrorFlag = 1;
			}
		}
			break;

		default:
			ErrorFlag = 1;

	}


	return ErrorFlag;
}
