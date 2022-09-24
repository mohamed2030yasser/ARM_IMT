/*
 * EXTI_int.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Diefco
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
};


void EXTI_vInit(void);

void EXTI_vEnable_Line(u8 A_u8_trigger ,u8 A_u8_Line_number);
void EXTI_vDisable_Line(u8 A_u8_Line_number);

void EXTI_vSoftwareTrigger(u8 A_u8_Line_number);

void EXTI_vSetTrigger(u8 A_u8_trigger ,u8 A_u8_Line_number);


#endif /* MCAL_EXTI_EXTI_INT_H_ */
