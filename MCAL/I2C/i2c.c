#include "../../2.Libraries/BIT_MATH.h"
#include "i2c_int.h"
#include "../DIO/DIO.h"

u8 TargetSlaveADDRESS; /* Global Variable to save the target slave address */

u8 I2C_u8Initialization(void)
{
	u8 ErrorFlag = 0;
  /* _______________________________________________________________________________________
	 ----------------------- Setting up the device slave address ---------------------------
	 _______________________________________________________________________________________ */
	TWAR = (u8)(mySLAVE_ADDRESS<<1);

  /* _______________________________________________________________________________________
	 ----------- Enable/Disable Broadcasting mode (General Call Recognition) ---------------
	 _______________________________________________________________________________________ */
	CLR_BIT(TWAR,0); /*  Disabled : NOTE >> The Broadcasting address is 0x00  */

  /* _______________________________________________________________________________________
	 ---------------------------- Enable/Disable ACK bit -----------------------------------
	 _______________________________________________________________________________________ */
	CLR_BIT(TWCR,TWEA);

  /* _______________________________________________________________________________________
   * ------------------- Setting up the clock frequency using the formula ------------------
	 *
	 *                             CPU Clock frequency         8 MHZ
	 *           SCL frequency = ________________________ = _____________ = 400 KHZ
	 *                                             (TWPS)             (0)
	 *                             16 + 2(TWBR) * 4          16+2(2)*4
	 _______________________________________________________________________________________*/
	TWBR = 0x02;
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

  /* _______________________________________________________________________________________
	 -------- Setting up the communication bus SDA , SCK as "Open-Drain" pins mode ---------
	 _______________________________________________________________________________________ */
	DIO_u8SetPinValue( PORT_C , PIN0 , PIN_HIGH );
	DIO_u8SetPinValue( PORT_C , PIN1 , PIN_HIGH );


	return ErrorFlag;
}


u8 I2C_StarTrasnmit(void)
{
	u8 ErrorFlag = 0;

	/* _______________________________________________________________________________________________________________
		 *
		 *               --------------------------------------------------------------------------------
		 *              |Start|   Load Slave Address + W  | ACK |   Load DATA  Address + W  | ACK | STOP |
		 *               --------------------------------------------------------------------------------
		 *                    ^                                 ^                                 ^
		 *                    |                                 |                                 |
		 *                TWINT set                         TWINT set                         TWINT set
	     *         & Status code indicates             Status code indicates           & Status code indicates
	     *           START condition sent             SLA+W sent, ACK received         data sent, ACK received
		 *
		 * _______________________________________________________________________________________________________________*/


		/* Send START condition : Clearing the TWI interrupt flag , Setting Start Condition bit , Setting TWI enable */
		TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);

		/* Wait for TWINT Flag set. This indicates that the START condition has been transmitted */
		while ( !GET_BIT(TWCR,TWINT) );

		/* Load SlaveAddress into TWDR Register. Clear TWINT bit in TWCR to start transmission of address */
		TWDR = TargetSlaveADDRESS;
		TWCR = (1<<TWINT) | (1<<TWEN);

	    /* Wait for TWINT Flag set. This indicates that the SlaveAddress has been transmitted, and ACK/NACK has been received. */
		while ( !GET_BIT(TWCR,TWINT) );


	return ErrorFlag;
}


u8 I2C_u8SendDATA(u8 DataBYTE)
{
	u8 ErrorFlag = 0;

	/* Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data */
	TWDR = DataBYTE;
	TWCR = (1<<TWINT) | (1<<TWEN);

	/* Wait for TWINT Flag set. This indicates that the DATA has been transmitted/received, and ACK/NACK has been received. */
	while ( !GET_BIT(TWCR,TWINT) );


	return ErrorFlag;
}







u8 I2C_u8readDATA(u8 *DataBYTE)
{
	u8 ErrorFlag = 0;

	/* Clear TWINT bit in TWCR to start receiving of data */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* Wait for TWINT Flag set. This indicates that the DATA has been transmitted/received, and ACK/NACK has been received. */
	while ( !GET_BIT(TWCR,TWINT) );
	*DataBYTE = TWDR;

	return ErrorFlag;
}


u8 I2C_u8StopTransmit(void)
{
	u8 ErrorFlag=0;

	/* Transmit STOP condition */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

	return ErrorFlag;
}


u8 I2C_u8SetSlaveAddress( u8 inputSlaveAddress , enumDATA_RW RW  )
{
	u8 ErrorFlag = 0;

	TargetSlaveADDRESS = inputSlaveAddress << 1;

	switch(RW)
	{
		case R:
			SET_BIT( TargetSlaveADDRESS , 0 );
			break;

		case W:
			CLR_BIT( TargetSlaveADDRESS , 0 );
			break;

		default:
			ErrorFlag = 1;
	}

	return ErrorFlag;
}

