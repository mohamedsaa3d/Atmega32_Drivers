#include "spi_int.h"
#include "spi_config.h"
#include "../../Libraries/STD_TYPES.h"
#include "../../Libraries/BIT_MATH.h"




u8 SPI_u8Initialization(void)
{
	u8 ErrorFlag=0;

	/*  SPI ENABLE  */
	SET_BIT(SPCR,6);

	/*  Data Order : MSB */
	CLR_BIT(SPCR,5);


#if  SPI_MODE == MASTER

	/* SS   PIN : OUTPUT */
	DIO_u8SetPinDirection(PORT_B,PIN4,PIN_OUTPUT);
	DIO_u8SetPinValue(PORT_B,PIN4,PIN_LOW);
	/* MOSI PIN : OUTPUT */
	DIO_u8SetPinDirection(PORT_B,PIN5,PIN_OUTPUT);
	/* MISO PIN : INPUT */
	DIO_u8SetPinDirection(PORT_B,PIN6,PIN_INPUT);
	/* SCK  PIN : OUTPUT */
	DIO_u8SetPinDirection(PORT_B,PIN7,PIN_OUTPUT);

	/*  Select the MASTER mode */
	SET_BIT(SPCR,4);

	/* Clock Rate : Prescaler 8*/
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);


#elif   SPI_MODE == SLAVE

	/* SS   PIN : INPUT */
	DIO_u8SetPinDirection(PORT_B,PIN4,PIN_INPUT);
	DIO_u8SetPinValue(PORT_B,PIN4,PIN_HIGH);
	/* MOSI PIN : INPUT */
	DIO_u8SetPinDirection(PORT_B,PIN5,PIN_INPUT);
	/* MISO PIN : OUTPUT */
	DIO_u8SetPinDirection(PORT_B,PIN6,PIN_OUTPUT);
	/* SCK  PIN : INPUT */
	DIO_u8SetPinDirection(PORT_B,PIN7,PIN_INPUT);

	/*  Select the SLAVE mode */
	CLR_BIT(SPCR,4);


#endif


	/* Clock Polarity / Clock Phase  */
	CLR_BIT(SPCR,2);
	CLR_BIT(SPCR,3);


	return ErrorFlag;
}




u8 SPI_u8Transciever(u8 ByteToBeSend , u8* ReceivedByte)
{
	u8 ErrorFlag=0;

	SPDR = ByteToBeSend; /* Sending a Byte */

	while ( !GET_BIT(SPSR,7) ); /* Waiting until byte sending/receiving is completed */

	*ReceivedByte = SPDR; /* Storing a received Byte */

	return ErrorFlag;
}
