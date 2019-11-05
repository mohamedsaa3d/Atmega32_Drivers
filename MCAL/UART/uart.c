#include "uart_int.h"
#include "../../2.Libraries/STD_TYPES.h"
#include "../../2.Libraries/BIT_MATH.h"


u8 UART_u8Initialization(void)
{
	u8 ErrorFlag=0;

	/* FULL DUPLEX */
	UCSRB |= (1<<4)|(1<<3);


	/* Character Size : 8 */
	/* No Parity          */
	/* Asynchronous Mode */
	UCSRC |= (1<<7) | (1<<2) | (1<<1) ;

	/* BAUD RATE : AT 8 MHZ | 9600 BPS */
	//UBRRH = 0;
	UBRRL = 51;


	return ErrorFlag;
}



u8 UART_u8RecieveByte(u8* DATA)
{
	u8 ErrorFlag=0;

	while(   !GET_BIT(UCSRA,7)   ); /* Wait until there are unread data in the receive buffer (RXC Flag) */

	*DATA = UDR;

	return ErrorFlag;
}

u8 UART_u8SendByte(u8 DATA)
{
	u8 ErrorFlag=0;

	while(   !GET_BIT(UCSRA,5)   ); /* Wait until the transmit buffer (UDR) is ready to receive new data (UDRE Flag) */

	UDR = DATA;

	return ErrorFlag;
}
