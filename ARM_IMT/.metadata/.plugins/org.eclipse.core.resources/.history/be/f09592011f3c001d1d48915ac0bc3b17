/*
 * EXTI_prv.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Diefco
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define enable 		1
#define disable 	0

#define EXTI_rising		1
#define EXTI_fallling   2
#define EXTI_onChange	3


#define EXTI_BASE_ADDR		0x40013C00

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_MemMap_t;

#define EXTI 		((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDR))



#endif /* MCAL_EXTI_EXTI_PRV_H_ */
