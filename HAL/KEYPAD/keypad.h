#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "..\..\4.MCAL\DIO\DIO.h"
#include "util/delay.h"
#include "../../2.Libraries/BIT_MATH.h"
#include "../../2.Libraries/STD_TYPES.h"

#define KEYPAD_PORT PORT_D


u8 Keypad_Initialization(void);
u8 Keypad_ReadKey(volatile u8* KeyValue , volatile u8* KeyPressedFlag);

#endif
