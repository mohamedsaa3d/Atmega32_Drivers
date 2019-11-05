/*
 * DIO_interface.h
 *
 *  Created on: 23 Mar 2019
 *      Author: MohamedSaa3D
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../2.Libraries/STD_TYPES.h"
#include "DIO_private.h"

/*###########################################*/
#define PORT_A DIO_PORTA_INDEX    /*User Input*/
#define PORT_B DIO_PORTB_INDEX    /*User Input*/
#define PORT_C DIO_PORTC_INDEX    /*User Input*/
#define PORT_D DIO_PORTD_INDEX    /*User Input*/


/*###########################################*/
#define PIN0  DIO_PIN0           /*User Input*/
#define PIN1  DIO_PIN1           /*User Input*/
#define PIN2  DIO_PIN2           /*User Input*/
#define PIN3  DIO_PIN3           /*User Input*/
#define PIN4  DIO_PIN4           /*User Input*/
#define PIN5  DIO_PIN5           /*User Input*/
#define PIN6  DIO_PIN6           /*User Input*/
#define PIN7  DIO_PIN7           /*User Input*/


/*###########################################*/
#define PIN_INPUT  DIO_INPUT_DIR          /*User Input*/
#define PIN_OUTPUT DIO_OUTPUT_DIR         /*User Input*/

/*###########################################*/
#define PIN_LOW   DIO_PIN_LOW        /*User Input*/
#define PIN_HIGH  DIO_PIN_HIGH       /*User Input*/

/*###########################################*/
#define PORT_OUTPUT 0xFF     /*User Input*/
#define PORT_INPUT  0x00     /*User Input*/

#define PORT_HIGH 0xFF       /*User Input*/
#define PORT_LOW  0x00       /*User Input*/

/*###########################################*/


u8 DIO_u8SetPinDirection(u8 u8PortNO , u8 u8PinNO , u8 u8Dir);
/* Function Description :
	 * This function is used to initialize a pin to be input or output
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Pin number indexed as below :
	 * 							PIN0 = 0
	 * 							PIN1 = 1
	 * 							PIN2 = 2
	 * 							PIN3 = 3
	 * 							PIN4 = 4
	 * 							PIN5 = 5
	 * 							PIN6 = 6
	 * 							PIN7 = 7
	 * 						* Pin Direction (Input/Output) :
	 * 							PIN_INPUT  = 0
	 * 							PIN_OUTPUT = 1
	 */


u8 DIO_u8SetPinValue( u8 u8PortNO , u8 u8PinNO , u8 u8Value   );
/* Function Description :
	 * This function is used to set a pin to be HIGH or LOW
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Pin number indexed as below :
	 * 							PIN0 = 0
	 * 							PIN1 = 1
	 * 							PIN2 = 2
	 * 							PIN3 = 3
	 * 							PIN4 = 4
	 * 							PIN5 = 5
	 * 							PIN6 = 6
	 * 							PIN7 = 7
	 * 						* Pin Value :
	 * 							PIN_LOW  = 0
	 * 							PIN_HIGH = 1
	 */

u8 DIO_u8GetPinValue( u8 u8PortNO , u8 u8PinNO , u8* u8Value  );
/* Function Description :
	 * This function is used to read a pin value
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Pin number indexed as below :
	 * 							PIN0 = 0
	 * 							PIN1 = 1
	 * 							PIN2 = 2
	 * 							PIN3 = 3
	 * 							PIN4 = 4
	 * 							PIN5 = 5
	 * 							PIN6 = 6
	 * 							PIN7 = 7
	 * 						* Address of variable to store the pin value :
	 * 							the address of the variable that will holds the pin value
	 * 							if pin is LOW return value is  0
	 * 							if pin is HIGH return value is 1
	 */

/*----------------------------------------------------------------------------------------------*/
u8 DIO_u8SetPortDirection(u8 u8PortNO , u8 u8Dir);
/* Function Description :
	 * This function is used to initialize a pin to be input or output
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Port Direction (Input/Output) :
	 * 							PORT_INPUT  = 0
	 * 							PORT_OUTPUT = 1
	 */


u8 DIO_u8SetPortValue( u8 u8PortNO , u8 u8Value   );
/* Function Description :
	 * This function is used to set a pin to be HIGH or LOW
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Port Value :
	 * 							PORT_LOW  = 0
	 * 							PORT_HIGH = 1
	 */

u8 DIO_u8GetPortValue( u8 u8PortNO , u8* u8Value  );
/* Function Description :
	 * This function is used to read a pin value
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Return Pin Value storing address :
	 * 							the address of the variable that will holds the pin value
	 * 							if pin is LOW return value is  0
	 * 							if pin is HIGH return value is 1
	 */

u8 DIO_u8SetNibbleDirection( u8 u8PortNO, u8 NibbleDir , Nibble SelectNibble );
/* Function Description :
	 * This function is used to initialize a port nibble to be input or output
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Nibble pins Direction (Input/Output) :
	 * 							The function will consider the first 4 bits only of the entered byte
	 * 						* Nibble Selection :
	 * 						    LOWER  : enter this to select the lower port nibble
	 * 						    HIGHER : enter this to select the higher port nibble
	 *
	 */

u8 DIO_u8SetNibbleValue( u8 u8PortNO, u8 NibbleValue , Nibble SelectNibble );
/* Function Description :
	 * This function is used to initialize a port nibble to be input or output
	 * the function takes 3 arguments :
	 * 						* Port number indexed as below :
	 * 							PORT_A = 0
	 * 							PORT_B = 1
	 * 							PORT_C = 2
	 * 							PORT_D = 3
	 * 						* Nibble pins value (High/Low) :
	 * 							The function will consider the first 4 bits only of the entered byte
	 * 						* Nibble Selection :
	 * 						    LOWER  : enter this to select the lower port nibble
	 * 						    HIGHER : enter this to select the higher port nibble
	 *
	 */

#endif /* DIO_INTERFACE_H_ */
