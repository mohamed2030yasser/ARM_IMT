/*
 * NVIC_prv.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Diefco
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_

#define NVIC_BASE_ADDR	0xE000E100

typedef struct
{
	u32 ISER[8];
	u32 Reserved0[24];
	u32 ICER[8];
	u32 Reserved1[24];
	u32 ISPR[8];
	u32 Reserved2[24];
	u32 ICPR[8];
	u32 Reserved3[24];
	u32 IABR[8];
	u32 Reserved4[24];
	u32 Reserved5[32];
	u8 IPR[128];

	u32 STIR[32];

}NVIC_MemMap;

#define	NVIC	((volatile NVIC_MemMap*)NVIC_BASE_ADDR)


#endif /* MCAL_NVIC_NVIC_PRV_H_ */
