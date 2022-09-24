/*
 * EXTI_prg.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Diefco
 */




#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include"EXTI_cfg.h"
#include"EXTI_int.h"
#include"EXTI_prv.h"


void EXTI_vInit(void)
{
	EXTI->IMR = 0 ;

	EXTI->IMR |=	(EXTI_line_0_enable << 0)	|
					(EXTI_line_1_enable << 1)	|
					(EXTI_line_2_enable << 2)	|
					(EXTI_line_3_enable << 3)	;

	EXTI->RTSR |= (1 << 0);


	// clear all flags
	EXTI->PR =0xffffffff;

}

//-------------------------------------------------

void EXTI_vEnable_Line(u8 A_u8_trigger ,u8 A_u8_Line_number)
{
	SET_BIT((EXTI->IMR),A_u8_Line_number);

	if(A_u8_trigger == EXTI_rising)
	{
		SET_BIT((EXTI->RTSR),A_u8_Line_number);
		CLR_BIT((EXTI->FTSR),A_u8_Line_number);
	}else if(A_u8_trigger == EXTI_fallling)
	{
		EXTI->FTSR |= (1 << A_u8_Line_number);
		CLR_BIT((EXTI->RTSR),A_u8_Line_number);
	}else
	{
		EXTI->RTSR |= (1 << A_u8_Line_number);
		EXTI->FTSR |= (1 << A_u8_Line_number);
	}

}

//-------------------------------------------------

void EXTI_vDisable_Line(u8 A_u8_Line_number)
{
	CLR_BIT((EXTI->IMR),A_u8_Line_number);
}

//-------------------------------------------------

void EXTI_vSoftwareTrigger(u8 A_u8_Line_number)
{
	SET_BIT((EXTI->SWIER),A_u8_Line_number);
}

//-------------------------------------------------

void EXTI_vSetTrigger(u8 A_u8_trigger ,u8 A_u8_Line_number)
{
	if(A_u8_trigger == EXTI_rising)
		{
			EXTI->RTSR |= (1 << A_u8_Line_number);
			CLR_BIT((EXTI->FTSR),A_u8_Line_number);
		}else if(A_u8_trigger == EXTI_fallling)
		{
			EXTI->FTSR |= (1 << A_u8_Line_number);
			CLR_BIT((EXTI->RTSR),A_u8_Line_number);
		}else
		{
			EXTI->RTSR |= (1 << A_u8_Line_number);
			EXTI->FTSR |= (1 << A_u8_Line_number);
		}
}



