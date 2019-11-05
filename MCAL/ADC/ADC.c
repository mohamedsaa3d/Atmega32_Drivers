#include "ADC.h"



u8 ADC_u8Initialization(void)
{
	u8 ErrorFlag=0;

	SET_BIT( ADCSRA , 7 ); /* Enable ADC */

	CLR_BIT( ADCSRA , 0 ); /* ADC Prescaler */
	CLR_BIT( ADCSRA , 1 ); /* ADC Prescaler */
	CLR_BIT( ADCSRA , 2 ); /* ADC Prescaler */

	SET_BIT( ADMUX , 5 ); /* ADC Left Adjust Select  */

	SET_BIT( ADMUX , 6 ); /* ADC Reference Selection : AVCC */
	CLR_BIT( ADMUX , 7 ); /* ADC Reference Selection       */


	return ErrorFlag;
}

u8 ADC_u8ReadPin(u8 PinNO , u8* value)
{
	u8 ErrorFlag=0;

	switch(PinNO)
	{
		case 0:
			CLR_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 1:
			SET_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 2:
			CLR_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 3:
			SET_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 4:
			CLR_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 5:
			SET_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 6:
			CLR_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
			break;
		case 7:
			SET_BIT( ADMUX , 0 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 1 ); /* ADC Channel Select  */
			SET_BIT( ADMUX , 2 ); /* ADC Channel Select  */

			CLR_BIT( ADMUX , 3 ); /* ADC Channel Select  */
			CLR_BIT( ADMUX , 4 ); /* ADC Channel Select  */
				break;
	}



	SET_BIT( ADCSRA , 6 ); /* Start Conversion */

	while( !GET_BIT(ADCSRA,4) ); /* Wait till the conversion is finished */

	SET_BIT(ADCSRA,4); /* CLearing the interrupt flag */

	*value = ADCH; /* Return the value */

	return ErrorFlag;
}
