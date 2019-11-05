#ifndef _UART_INT_H_
#define _UART_INT_H_

#include "../../Libraries/STD_TYPES.h"
#include "uart_priv.h"
#include "uart_config.h"



u8 UART_u8Initialization(void);

u8 UART_u8RecieveByte(u8* DATA);

u8 UART_u8SendByte(u8 DATA);



#endif /* 4_MCAL_UART_UART_INT_H_ */
