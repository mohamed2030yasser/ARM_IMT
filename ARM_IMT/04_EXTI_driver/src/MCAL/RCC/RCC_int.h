/*
 * RCC_int.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Diefco
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

#define RCC_AHB1		0
#define RCC_AHB2		1
#define RCC_APB1		2
#define RCC_APB2		3


#define RCC_EN_GPIOA	0
#define RCC_EN_GPIOB	1
#define RCC_EN_GPIOC	2
#define RCC_EN_GPIOD	3
#define RCC_EN_GPIOE	4
#define RCC_EN_GPIOH	7

#define RCC_EN_EXTI		14


void MRCC_vInit(void) ;
void MRCC_vEnClock(/*??????*/);
void MRCC_vDisClock(/*??????*/);


#endif /* MCAL_RCC_RCC_INT_H_ */