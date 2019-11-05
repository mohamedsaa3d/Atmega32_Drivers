#ifndef LCD_CONFIG_
#define LCD_CONFIG_

#include "LCD_priv.h"

/* LCD Pins Configuration */
#define LCD_DATA_PORT     PORT_A
#define LCD_CONTROL_PORT  PORT_C
#define LCD_RS            PIN5
#define LCD_RW            PIN6
#define LCD_EN            PIN7

/* In case of 4-Bit Mode : Select the higher or lower port nibble */
#define LCD_DATA_NIBBLE  LOWER            /*Select LOWER / HIGHER */

/* LCD Option Configurations */

/*  Set LCD_TYPE 4 or 8        :  To Select 4/8 bit mode                                    *
 *  Set DISP   0 or 1          :  To Turn on/off the display                                *
 *  Set CURSOR 0 or 1          :  To Turn on/off the cursor                                 *
 *  Set BLINK  0 or 1          :  To Turn on/off the cursor blinking                        *
 *  Set DATA_LENGTH   0 or 1   :  Sets interface data length   (1) 8-bit    / (0) 4-bit     *
 *  Set NO_OF_LINES   0 or 1   :  Sets numbers of display line (1) 2-line   / (0) 1-line    *
 *  Set FONT          0 or 1   :  Sets display font type       (1) 5x11dots / (0) 5x8dots   */

#define LCD_TYPE      4
#define DISP          ON
#define CURSOR        ON
#define BLINK         ON
#define NO_OF_LINES   ON
#define FONT          ON

#if    LCD_TYPE == 4

	#define DATA_LENGTH   0

#elif  LCD_TYPE == 8

	#define DATA_LENGTH   1

#endif

/* Forming the Control Byte by concatenating the control bits */

#define DisplayControl  BYTE_CONC(0,0,0,0,1,DISP,CURSOR,BLINK)

#define FunctionSet     BYTE_CONC(0,0,1,DATA_LENGTH,NO_OF_LINES,FONT,0,0)


#endif
