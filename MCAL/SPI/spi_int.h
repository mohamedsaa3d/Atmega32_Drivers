#ifndef _SPI_INT_H_
#define _SPI_INT_H_

#include "../../2.Libraries/STD_TYPES.h"
#include "spi_priv.h"
#include "spi_config.h"
#include "../DIO/DIO.h"



u8 SPI_u8Initialization(void);

u8 SPI_u8Transciever(u8 ByteToBeSend , u8* ReceivedByte);


#endif
