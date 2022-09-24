
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/NVIC/NVIC_init.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/EXTI/EXTI_prv.h"

void EXTI0_IRQHandler (void)
{
	GPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
	SET_BIT(EXTI->PR, 0);
}

int main(void)
{
	MRCC_vInit();
	MRCC_vEnClock(RCC_AHB1, RCC_EN_GPIOA);

	MRCC_vEnClock(RCC_APB2, RCC_EN_EXTI);


	MGPIO_Config_t led_pin_cfg = {
	.Port 		= GPIO_PORTA,
	.Pin 		= 1,
	.Mode 		= GPIO_MODE_GPOUT,
	.OutSpeed 	= GPIO_LOW_SPEED,
	.OutType 	= GPIO_PUSHPULL,
	.InputPull  = GPIO_NO_PULL,
	};

	GPIO_vInit(&led_pin_cfg);

	/*MGPIO_Config_t Button_pin_cfg = {
	.Port 		= GPIO_PORTA,
	.Pin 		= 0,
	.Mode 		= GPIO_MODE_INPUT,
	.OutSpeed 	= GPIO_LOW_SPEED,
	.OutType 	= GPIO_PUSHPULL,
	.InputPull  = GPIO_PULL_UP,
	};

	GPIO_vInit(&Button_pin_cfg);*/
	GPIO_vSetPinMod(GPIO_PORTA, 0, GPIO_MODE_INPUT);
	GPIO_vSetPinInputPull(GPIO_PORTA, 0, GPIO_PULL_UP);

	EXTI_vEnable_Line(1, 0);
	NVIC_vEnable_Pri(EXTI0);

	//EXTI_vSoftwareTrigger(0);

	while(1)
	{

		//GPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
		while(GPIO_u8GetPINValue(GPIO_PORTA, GPIO_PIN0))
		{
			GPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
		}

	}
}
