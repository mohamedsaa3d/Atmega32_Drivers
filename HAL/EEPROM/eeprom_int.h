/*
 * eeprom_int.h
 *
 *  Created on: 18 May 2019
 *      Author: MohamedSaa3D
 */

#ifndef _EEPROM_INT_H_
#define _EEPROM_INT_H_

#include "eeprom_config.h"
#include "../../Libraries/STD_TYPES.h"
#include "../../Libraries/BIT_MATH.h"

u8 EEPROM_u8WriteBYTE(u8 BYTE ,u16 ByteNO);
u8 EEPROM_u8ReadBYTE( u16 ByteNO , u8 *DATE_BYTE );
u8 EEPROM_u8FormingSlaveAddress( u16 ByteNO, enumDATA_RW RW );






#endif /* 3_HAL_EEPROM_EEPROM_INT_H_ */
