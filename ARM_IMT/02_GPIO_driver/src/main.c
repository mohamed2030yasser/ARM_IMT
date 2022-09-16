
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"

// FORBIDDEN PINS 		[A13 A14 A15] : [B2 B3 B4]

#define ARM_DELAY_M4(m)		do{unsigned int i=m*4500; while(i--){asm("nop");}} while(0)

int main(void)
{

	MRCC_vInit();
	MRCC_vEnClock(RCC_AHB1, RCC_EN_GPIOA);

	for (int i = 0; i < 7; i++)
	{
				MGPIO_Config_t led_pin_cfg = {
				.Port 		= GPIO_PORTA,
				.Pin 		= i,
				.Mode 		= GPIO_MODE_GPOUT,
				.OutSpeed 	= GPIO_LOW_SPEED,
				.OutType 	= GPIO_PUSHPULL,
				.InputPull  = GPIO_NO_PULL,
		};

		GPIO_vInit(&led_pin_cfg);
	}


	while(1)
	{
		for (int i = 0; i < 7; i++) {
				GPIO_vSetPinValue(GPIO_PORTA, i, GET_BIT(0b0010010,i));

			}

		ARM_DELAY_M4(1000);

		for (int i = 0; i < 7; i++) {
				GPIO_vSetPinValue(GPIO_PORTA, i, GET_BIT(0b0110000,i));

			}
		ARM_DELAY_M4(1000);
	}
}
