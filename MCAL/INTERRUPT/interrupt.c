#include "interrupt.h"
#include "interrupt_private.h"
#include "..\..\Libraries\BIT_MATH.h"
#include "..\..\Libraries\STD_TYPES.h"
#include "..\DIO\DIO.h"

/* GLOBAL Pointers to the callback functions (Will be called inside ISRs) */
void  (*ISR_INT0_FUNC_PTR)(void)     = NULL;
void  (*ISR_INT1_FUNC_PTR)(void)     = NULL;
void  (*ISR_INT2_FUNC_PTR)(void)     = NULL;
void  (*ISR_T2COMP_FUNC_PTR)(void)   = NULL;
void  (*ISR_T2OV_FUNC_PTR)(void)     = NULL;
void  (*ISR_T1CU_FUNC_PTR)(void)     = NULL;
void  (*ISR_T1ACOMP_FUNC_PTR)(void)  = NULL;
void  (*ISR_T1BCOMP_FUNC_PTR)(void)  = NULL;
void  (*ISR_T1OV_FUNC_PTR)(void)     = NULL;
void  (*ISR_T0COMP_FUNC_PTR)(void)   = NULL;
void  (*ISR_SERIAL_FUNC_PTR)(void)   = NULL;
void  (*ISR_URX_FUNC_PTR)(void)      = NULL;
void  (*ISR_UDATA_FUNC_PTR)(void)    = NULL;
void  (*ISR_UTX_FUNC_PTR)(void)      = NULL;
void  (*ISR_ADC_FUNC_PTR)(void)      = NULL;
void  (*ISR_EEPROM_FUNC_PTR)(void)   = NULL;
void  (*ISR_ACOMP_FUNC_PTR)(void)    = NULL;
void  (*ISR_TWI_FUNC_PTR)(void)      = NULL;
void  (*ISR_PROGMEM_FUNC_PTR)(void)  = NULL;
void  (*ISR_T0OV_FUNC_PTR)(void)     = NULL;

u8 Interrupt_u8GI(GlobalINT_STATE GI_SELECT)
{
	u8 ErrorFlag=0;

	switch(GI_SELECT)
	{
	case GI_ENABLE:
		SET_BIT(SREG,7);
		break;
	case GI_DISABLE:
		CLR_BIT(SREG,7);
		break;
	default:
		ErrorFlag=1;
	}

	return ErrorFlag;
}


u8 Interrupt_u8EXTINT ( enumEXTI ChannelSelect , enumINT_SENSE Sense_Select)
{
	u8 ErrorFlag=0;

	/*---------------------------------------------- EXT INT0 ----------------------------------------------------*/
	if(ChannelSelect == EXT_INT0)
	{
		DIO_u8SetPinDirection( PORT_D , PIN2 , PIN_INPUT);    /* INT0 PIN INPUT   */
		DIO_u8SetPinValue( PORT_D , PIN2 , PIN_HIGH);         /* INT0 PIN PULL UP */
		SET_BIT(GICR,6);                                      /* Enabling INT0    */

		switch(Sense_Select)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
		default:
			ErrorFlag=1;

		}
	}
	/*---------------------------------------------- EXT INT1 ----------------------------------------------------*/
	else if (ChannelSelect == EXT_INT1)
	{
		DIO_u8SetPinDirection( PORT_D , PIN3 , PIN_INPUT);    /* INT1 PIN INPUT   */
		DIO_u8SetPinValue( PORT_D , PIN3 , PIN_HIGH);         /* INT1 PIN PULL UP */
		SET_BIT(GICR,7);                                      /* INT1 ENABLE      */

		switch(Sense_Select)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
		default:
			ErrorFlag=1;

		}
	}
	/*---------------------------------------------- EXT INT2 ----------------------------------------------------*/
	else if (ChannelSelect == EXT_INT2)
	{
		DIO_u8SetPinDirection( PORT_B , PIN2 , PIN_INPUT);    /* INT2 PIN INPUT   */
		DIO_u8SetPinValue( PORT_B , PIN2 , PIN_HIGH);         /* INT2 PIN PULL UP */
		SET_BIT(GICR,5);                                      /* INT2 ENABLE      */

		switch(Sense_Select)
		{
		case FALLING_EDGE:
			CLR_BIT(MCUCSR,6);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,6);
			break;
		default:
			ErrorFlag=1;
		}
	}
	else
	{
		ErrorFlag=1;
	}


	return ErrorFlag;
}


u8 ISR_CALLBACK( enumISR_VECTORS ISR_vector_ID , void(*functionPTR)(void)  )
{
	u8 ErrorFlag=0;

	switch (ISR_vector_ID)
	{
		case INT0:
			ISR_INT0_FUNC_PTR = functionPTR;
			break;
		case INT1:
			ISR_INT1_FUNC_PTR = functionPTR;
			break;
		case INT2:
			ISR_INT2_FUNC_PTR = functionPTR;
			break;
		case TIMER2_COMPARE:
			ISR_T2COMP_FUNC_PTR = functionPTR;
			break;
		case TIMER2_OVERFLOW:
			ISR_T2OV_FUNC_PTR = functionPTR;
			break;
		case TIMER1_Capture:
			ISR_T1CU_FUNC_PTR = functionPTR;
			break;
		case TIMER1A_COMPARE:
			ISR_T1ACOMP_FUNC_PTR = functionPTR;
			break;
		case TIMER1B_COMPARE:
			ISR_T1BCOMP_FUNC_PTR = functionPTR;
			break;
		case TIMER1_OVERFLOW:
			ISR_T1OV_FUNC_PTR = functionPTR;
			break;
		case TIMER0_COMPARE:
			ISR_T0COMP_FUNC_PTR = functionPTR;
			break;
		case TIMER0_OVERFLOW:
			ISR_T0OV_FUNC_PTR = functionPTR;
			break;
		case SERIAL_COMPLETE:
			ISR_SERIAL_FUNC_PTR = functionPTR;
			break;
		case USART_RX_COMPLETE:
			ISR_URX_FUNC_PTR = functionPTR;
			break;
		case USART_DATA_EMPTY:
			ISR_UDATA_FUNC_PTR = functionPTR;
			break;
		case USART_TX_COMPLETE:
			ISR_UTX_FUNC_PTR = functionPTR;
			break;
		case ADC_CONVERSION:
			ISR_ADC_FUNC_PTR = functionPTR;
			break;
		case EEPROM_READY:
			ISR_EEPROM_FUNC_PTR = functionPTR;
			break;
		case ANALOG_COMPARATOR:
			ISR_ACOMP_FUNC_PTR = functionPTR;
			break;
		case TWO_WIRE_SERIAL:
			ISR_TWI_FUNC_PTR = functionPTR;
			break;
		case STORE_PROGRAM_MEMORY:
			ISR_PROGMEM_FUNC_PTR = functionPTR;
			break;

		default:
			ErrorFlag=1;
			break;

	}

	return ErrorFlag;
}


/*---------------------------------------  ISR Definitions ---------------------------------------------------*/
ISR( INT0_vect )
{

	if( ISR_INT0_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_INT0_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( INT1_vect )
{

	if( ISR_INT1_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_INT1_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( INT2_vect )
{

	if( ISR_INT2_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_INT2_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TIMER2_COMPARE_vect )
{

	if( ISR_T2COMP_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T2COMP_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TIMER2_OVERFLOW_vect )
{

	if( ISR_T2OV_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T2OV_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TIMER1_Capture_Event )
{

	if( ISR_T1CU_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T1CU_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

/*ISR( TIMER1A_COMPARE_vect )
{

	if( ISR_T1ACOMP_FUNC_PTR != NULL )
	{
		 Call the desired function if it has been assigned to the ISR
		ISR_T1ACOMP_FUNC_PTR();

	}
	else
	{
		 Nothing to do
	}

}*/

ISR( TIMER1B_COMPARE_vect )
{

	if( ISR_T1BCOMP_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T1BCOMP_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TIMER1_OVERFLOW_vect )
{

	if( ISR_T1OV_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T1OV_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TIMER0_COMPARE_vect )
{

	if( ISR_T0COMP_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T0COMP_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TIMER0_OVERFLOW_vect )
{

	if( ISR_T0OV_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_T0OV_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( SERIAL_COMPLETE_vect )
{

	if( ISR_SERIAL_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_SERIAL_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( USART_RX_COMPLETE_vect )
{

	if( ISR_URX_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_URX_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( USART_DATA_EMPTY_vect )
{

	if( ISR_UDATA_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_UDATA_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( USART_TX_COMPLETE_vect )
{

	if( ISR_UTX_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_UTX_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( ADC_CONVERSION_vect )
{

	if( ISR_ADC_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_ADC_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( EEPROM_READY_vect )
{

	if( ISR_EEPROM_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_EEPROM_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( ANALOG_COMPARATOR_vect )
{

	if( ISR_ACOMP_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_ACOMP_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( TWO_WIRE_SERIAL_vect )
{

	if( ISR_TWI_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_TWI_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}

ISR( STORE_PROGRAM_MEMORY_vect )
{

	if( ISR_PROGMEM_FUNC_PTR != NULL )
	{
		/* Call the desired function if it has been assigned to the ISR */
		ISR_PROGMEM_FUNC_PTR();

	}
	else
	{
		/* Nothing to do*/
	}

}


