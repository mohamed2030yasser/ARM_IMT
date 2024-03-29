/*
 * RCC_prg.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Diefco
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "RCC_prv.h"
#include "RCC_cfg.h"
#include "RCC_int.h"

/* 1- [ en HSX , choose BYP , select HSX ] >> Initialize
 * 2- [ select bus ]
 */

void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */
	/*2- HSE_BYP */
	CLR_BIT(RCC->CR,HSEBYP);

	/*3- Select Clock Switch  (HSE/HSI/PLL)
		----------[System clock switch]------
		00: HSI oscillator selected as system clock
		01: HSE oscillator selected as system clock
		10: PLL selected as system clock
		11: not allowed                  */
	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

	/*4- Bus prescaler */
	/*5- PLL config  */
	/*6- EN selected Clk (HSE/HSI/PLL) ON */
#if RCC_HSE_EN==E
	SET_BIT(RCC->CR,HSEON);
#endif
}

void MRCC_vEnClock(u32 Au32_Bus_Id , u32 Au32_PerId )
{
	switch(Au32_Bus_Id)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,Au32_PerId);
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,Au32_PerId);
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,Au32_PerId);
		break;
	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR,Au32_PerId);
		break;
	default:
		// ERROR : >>>>>>>>>>>
		break;
	}
}

void MRCC_vDisClock(u32 Au32_Bus_Id , u32 Au32_PerId)
{
	switch(Au32_Bus_Id)
		{
		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,Au32_PerId);
			break;
		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,Au32_PerId);
			break;
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,Au32_PerId);
			break;
		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,Au32_PerId);
			break;
		default:
			// ERROR : >>>>>>>>>>>
			break;
		}
}

