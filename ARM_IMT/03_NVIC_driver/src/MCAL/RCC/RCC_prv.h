/*
 * RCC_prv.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Diefco
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_

/* RCC clock control register (RCC_CR) */
#define HSION	0	//Internal high-speed clock enable
#define HSEON	16	//External high-speed clock enable
#define HSEBYP	18	//HSE clock bypass
#define CSSON	19	//Clock security system enable
#define PLLON	24	// phase locked loop
/* >>>>>>>>>>>>>			end		   */


/* clock configuration register (RCC_CFGR) */
#define SW0		0
#define SW1		1
/* >>>>>>>>>>>>>			end		   */

/* PLL configuration register (RCC_PLLCFGR) */
// F(PLL) = ( F[input] * [N] ) / ( [P] * [M] )

#define PLLM0		0		//M [2≤ PLLM ≤ 63]
#define PLLM1		1
#define PLLM2		2
#define PLLM3		3
#define PLLM4		4
#define PLLM5		5

#define PLLN0		6		//N [192 ≤ PLLN ≤ 432]
#define PLLN1		7
#define PLLN2		8
#define PLLN3		9
#define PLLN4		10
#define PLLN5		11
#define PLLN6		12
#define PLLN7		13
#define PLLN8		14

#define PLLP0		16		//p  2,4,6,8
#define PLLP1		17

#define PLLSRC		22		// HSI or HSE
/* >>>>>>>>>>>>>			end		   */


#define RCC_BASE_ADDR		0x40023800

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved_1;
	u32 Reserved_2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved_3;
	u32 Reserved_4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved_5;
	u32 Reserved_6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved_7;
	u32 Reserved_8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 Reserved_9;
	u32 Reserved_10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 Reserved_11;
	u32 Reserved_12;
	u32 BDCR;
	u32 CSR;
	u32 Reserved_13;
	u32 Reserved_14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 DCKCFGR;
}RCC_MemMap_t;

#define RCC		((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))

#endif /* MCAL_RCC_RCC_PRV_H_ */
