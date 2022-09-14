/*
 * GPIO_int.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Diefco
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_

#define GPIO_MODE_INPUT		00
#define GPIO_MODE_GPOUT		01
#define GPIO_MODE_ALTFUN	10
#define GPIO_MODE_ANAOUT	11

#define GPIO_PORTA		0
#define GPIO_PORTB		1
#define GPIO_PORTC		2

#define GPIO_OPENDRAIN	0
#define GPIO_PUSHPULL	1

#define GPIO_LOW_SPEED			00
#define GPIO_MEDIUM_SPEED		01
#define GPIO_HIGH_SPEED			10
#define GPIO_VERY_HIGH_SPEED	11

#define GPIO_NO_PULL			00
#define GPIO_PULL_UP			01
#define GPIO_PULL_DOWN			10

#define GPIO_HIGH		1
#define GPIO_LOW		0



void GPIO_vSetPinMod(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8Mode);
void GPIO_vSetPinOutType(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8OutType);
void GPIO_vSetPinOutSpeed(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8OutSpeed);
void GPIO_vSetPinInputPull(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8PullType);
u8	 GPIO_u8GetPINValue(u8 A_u8Port_Id,u8 A_u8Pin_Num);
void GPIO_vSetPinValue(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8Value);
void GPIO_vSetPortValue(u8 A_u8Port_Id,u16 A_u8Value);
void GPIO_vSetPinValue_Fast(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8Value);
void GPIO_vSet_AF(u8 A_u8Port_Id,u8 A_u8Pin_Num,u8 A_u8AF);
#endif /* MCAL_GPIO_GPIO_INT_H_ */