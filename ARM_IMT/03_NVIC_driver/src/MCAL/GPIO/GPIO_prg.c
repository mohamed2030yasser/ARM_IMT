/*
 * GPIO_prg.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Diefco
 */




#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GPIO_cfg.h"
#include "GPIO_int.h"
#include "GPIO_prv.h"



void GPIO_vSetPinMod(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8Mode)
{
	switch(A_u8Port_Id)
	{
	case GPIO_PORTA:
		GPIOA->MODER &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOA->MODER |= (A_u8Mode<<(A_u8Pin_Num*2));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOB->MODER |= (A_u8Mode<<(A_u8Pin_Num*2));
		break;
	case GPIO_PORTC:
		GPIOC->MODER &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOC->MODER |= (A_u8Mode<<(A_u8Pin_Num*2));
		break;
	}

}
void GPIO_vSetPinOutType(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8OutType)
{
	if(A_u8OutType == GPIO_OPENDRAIN)
	{
		switch(A_u8Port_Id)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->OTYPER,A_u8Pin_Num);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->OTYPER,A_u8Pin_Num);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->OTYPER,A_u8Pin_Num);
			break;
		}
	}else if(A_u8Port_Id == GPIO_PUSHPULL)
	{
		switch(A_u8Port_Id)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER,A_u8Pin_Num);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,A_u8Pin_Num);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,A_u8Pin_Num);
			break;
		}
	}
}
void GPIO_vSetPinOutSpeed(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8OutSpeed)
{
	switch(A_u8Port_Id)
	{
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOA->OSPEEDR |= (A_u8OutSpeed<<(A_u8Pin_Num*2));
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOB->OSPEEDR |= (A_u8OutSpeed<<(A_u8Pin_Num*2));
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOC->OSPEEDR |= (A_u8OutSpeed<<(A_u8Pin_Num*2));
		break;
	}
}
void GPIO_vSetPinInputPull(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8PullType)
{
	switch(A_u8Port_Id)
	{
	case GPIO_PORTA:
		GPIOA->PUPDR &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOA->PUPDR |= (A_u8PullType<<(A_u8Pin_Num*2));
		break;
	case GPIO_PORTB:
		GPIOB->PUPDR &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOB->PUPDR |= (A_u8PullType<<(A_u8Pin_Num*2));
		break;
	case GPIO_PORTC:
		GPIOC->PUPDR &= ~(0b11<<(A_u8Pin_Num*2));
		GPIOC->PUPDR |= (A_u8PullType<<(A_u8Pin_Num*2));
		break;
	}
}
u8	 GPIO_u8GetPINValue(u8 A_u8Port_Id,u8 A_u8Pin_Num)
{
	u8 PinValue=0;
	switch(A_u8Port_Id)
	{
	case GPIO_PORTA:
		PinValue = GET_BIT(GPIOA->IDR, A_u8Pin_Num);
		break;
	case GPIO_PORTB:
		PinValue = GET_BIT(GPIOB->IDR, A_u8Pin_Num);
		break;
	case GPIO_PORTC:
		PinValue = GET_BIT(GPIOC->IDR, A_u8Pin_Num);
		break;
	}
}
void GPIO_vSetPinValue(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8Value)
{
	if(A_u8Value == GPIO_HIGH)
	{
		switch(A_u8Port_Id)
		{
		case GPIO_PORTA:
			SET_BIT((GPIOA->ODR), A_u8Pin_Num);
			break;
		case GPIO_PORTB:
			SET_BIT((GPIOB->ODR), A_u8Pin_Num);
			break;
		case GPIO_PORTC:
			SET_BIT((GPIOC->ODR), A_u8Pin_Num);
			break;
		}
	}else if(A_u8Value == GPIO_LOW)
	{
		switch(A_u8Port_Id)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->ODR, A_u8Pin_Num);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->ODR, A_u8Pin_Num);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->ODR, A_u8Pin_Num);
			break;
		}
	}
}

void GPIO_vSetPortValue(u8 A_u8Port_Id,u16 A_u8Value_hex)
{
	switch(A_u8Port_Id)
	{
	case GPIO_PORTA:
		(GPIOA->ODR) = A_u8Value_hex;
		break;
	case GPIO_PORTB:
		(GPIOB->ODR) = A_u8Value_hex;
		break;
	case GPIO_PORTC:
		(GPIOC->ODR) = A_u8Value_hex;
		break;
	}
}

void GPIO_vSetPinValue_Fast(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8Value)
{
	if(A_u8Value == GPIO_BSRR_SET )
	{
		switch(A_u8Port_Id)
		{
		case GPIO_PORTA:
			(GPIOA->BSRR) |= (GPIO_BSRR_SET << A_u8Pin_Num);
			break;
		case GPIO_PORTB:
			(GPIOB->BSRR) |= (GPIO_BSRR_SET << A_u8Pin_Num);
			break;
		case GPIO_PORTC:
			(GPIOC->BSRR) |= (GPIO_BSRR_SET << A_u8Pin_Num);
			break;
		}
	}else if(A_u8Value == GPIO_BSRR_RESET)
	{
		switch(A_u8Port_Id)
		{
		case GPIO_PORTA:
			(GPIOA->BSRR) |= (1 << A_u8Pin_Num+16);
			break;
		case GPIO_PORTB:
			(GPIOB->BSRR) |= (1 << A_u8Pin_Num+16);
			break;
		case GPIO_PORTC:
			(GPIOC->BSRR) |= (1 << A_u8Pin_Num+16);
			break;
		}
	}
}
void GPIO_vSet_AF(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8AF)
{

}

void GPIO_vInit(MGPIO_Config_t* A_xPortConfig)
{
	GPIO_vSetPinMod(A_xPortConfig->Port, A_xPortConfig->Pin, A_xPortConfig->Mode);
	GPIO_vSetPinOutType(A_xPortConfig->Port, A_xPortConfig->Pin, A_xPortConfig->OutType);
	GPIO_vSetPinOutSpeed(A_xPortConfig->Port, A_xPortConfig->Pin, A_xPortConfig->OutSpeed);
	GPIO_vSetPinInputPull(A_xPortConfig->Port, A_xPortConfig->Pin, A_xPortConfig->InputPull);
	GPIO_vSet_AF(A_xPortConfig->Port, A_xPortConfig->Pin, A_xPortConfig->AltFun);
}




