/*
 * NVIC_prv.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Diefco
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_

#define NVIC_BASE_ADDR	0xE000E100
#define SCB_BASE_ADDR	0xE000ED00

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

typedef struct
{
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCSR;
	u32 CFSR;
	u32 HFSR;
	u32 Reserved;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;

}SCB_MemMap;

#define	NVIC	((volatile NVIC_MemMap*)NVIC_BASE_ADDR)
#define	SCB	((volatile SCB_MemMap*)SCB_BASE_ADDR)


#endif /* MCAL_NVIC_NVIC_PRV_H_ */
