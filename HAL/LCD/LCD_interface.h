
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../2.Libraries/BIT_MATH.h"
#include "../../2.Libraries/STD_TYPES.h"
#include "..\..\4.MCAL\DIO\DIO.h"
#include "LCD_CONFIG.h"

/* LCD Commands Binary Codes */
#define ClearDisplay    0b00000001
#define ReturnHome      0b00000010
#define FISRT_LINE_POS  0b10000000
#define SECOND_LINE_POS 0b11000000
#define CGRAM_ADDRESS   0b01000000
#define ShiftCursorL    0b00010000
#define ShiftCursorR    0b00010100


u8 LCD_u8Initialization(void);
u8 LCD_u8WriteCMD(s8 CMD);
u8 LCD_u8WriteDATA(s8 DATA);
u8 LCD_u8WriteLINE(s8 DATA[]);
u8 LCD_u8WriteNUMBER(s32 DATA);
u8 LCD_u8ReadBusy(void);

u8 LCD_u8GOTO_XY(u8 X_AXIS, u8 Y_AXIS);


#endif /* LCD_INTERFACE_H_ */
