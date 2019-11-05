#include "../../../Libraries/BIT_MATH.h"
#include "../../../Libraries/STD_TYPES.h"
#include "wdt_int.h"


u8 WatchDogTimer_u8Initialization(void)
{
	u8 ErrorFlag=0;

	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);


	return ErrorFlag;
}

u8 WatchDogTimer_u8Enable(void)
{
	u8 ErrorFlag=0;

	SET_BIT(WDTCR,3);
	//SET_BIT(WDTCR,4);

	//WDTCR |= (1<<4) | (1<<3) ;


	return ErrorFlag;
}
