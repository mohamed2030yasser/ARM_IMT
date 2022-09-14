
#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"


int main(void)
{
	MRCC_vInit();
	MRCC_vEnClock(RCC_AHB1, RCC_EN_GPIOA);

	GPIO_vSetPinMod( GPIO_PORTA, 0, GPIO_MODE_GPOUT);
	GPIO_vSetPinOutSpeed(GPIO_PORTA, 0, GPIO_LOW_SPEED);
	GPIO_vSetPinOutType(GPIO_PORTA, 0, GPIO_PUSHPULL);
	GPIO_vSetPinValue(GPIO_PORTA, 0, GPIO_HIGH);
	while(1)
	{

	}
}
