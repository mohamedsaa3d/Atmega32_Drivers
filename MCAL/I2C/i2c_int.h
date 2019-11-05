/*
 * i2c_int.h
 *
 *  Created on: 17 May 2019
 *      Author: MohamedSaa3D
 */

#ifndef _I2C_INT_H_
#define _I2C_INT_H_

#include "../../Libraries/STD_TYPES.h"
#include"i2c_priv.h"
#include "i2c_config.h"

typedef enum
{
	R , W
}enumDATA_RW;


u8 I2C_u8Initialization(void);
/* Function Description:
 * This function is used to initialize the following features of the I2C module:
 * 		- The device address (To be able to receive data from other masters)
 * 		- Enabling/Disabling the listening of broadcasting mode
 * 		- Enabling/Disabling the acknowledge bit in the data format
 * 		- Setting up the clock frequency (Date transmitting rate: with a maximum of 400 KHZ)
 * */

u8 I2C_StarTrasnmit(void);
/* Function Description:
 * 		- Sends the start bit followed by the Slave Address byte
 * */

u8 I2C_u8SendDATA(u8 DataBYTE);
/* Function Description:
 * 		- Sends the data byte to the slave (Without terminating the communication)
 * */

u8 I2C_u8readDATA(u8 *DataBYTE);
/* Function Description:
 * 		- Listens to the incoming data and returning the received byte after that
 * */

u8 I2C_u8StopTransmit(void);
/* Function Description:
 * 		- Sends the stop bit to terminate the communication and release the bus
 * */

u8 I2C_u8SetSlaveAddress(u8 inputSlaveAddress , enumDATA_RW RW );
/* Function Description:
 * 		- Forms the (SLA+ R/W) byte and assigns it to the global slave address variable to be used in the transmitting
 * */


#endif
