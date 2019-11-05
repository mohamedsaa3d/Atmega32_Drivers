
/*------------ Main Application Algorithm -------------*/

#include "util/delay.h"

#include "..\Libraries\BIT_MATH.h"
#include "..\Libraries\STD_TYPES.h"

/*---------------- Including HAL Layer ----------------*/
#include "..\HAL\LCD\LCD_interface.h"

/*-------------- Including MCAL Layer -----------------*/

#include "..\MCAL\DIO\DIO.h"
#include "..\MCAL\ADC\ADC.h"

//#include "../MCAL/INTERRUPT/interrupt.h"

#define F_CPU 8000000UL

int main(void)
{
	u8 TEMP_HYSTERISIS  = 1;
	u8 ADC_VALUE       = 0;
	u8 TEMP_VALUE      = 0;

	ADC_u8Initialization();
	/*  ADC  : 0 ---> 1024     ,     TEMP : 0 ---> 100 */

	while(1)
	{
		ADC_u8ReadPin(  ADC0  ,  &ADC_VALUE  );

		TEMP_VALUE = (u8)(  ((u32)ADC_VALUE * 100) / 1024UL  );

		if (  (ADC_VALUE >= (30-TEMP_HYSTERISIS)) ||  (ADC_VALUE <= (50+TEMP_HYSTERISIS))  )
		{
			/* Temp : 30 TO 50 */
			/*    Action 1     */
		}
		if (  (ADC_VALUE >= (70-TEMP_HYSTERISIS)) ||  (ADC_VALUE <= (80+TEMP_HYSTERISIS))  )
		{
			/* Temp : 70 TO 80 */
			/*    Action 2     */
		}
	}


	return 0;
}
