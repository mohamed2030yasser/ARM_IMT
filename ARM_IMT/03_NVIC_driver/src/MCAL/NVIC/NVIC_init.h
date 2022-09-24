/*
 * NVIC_init.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Diefco
 */

#ifndef MCAL_NVIC_NVIC_INIT_H_
#define MCAL_NVIC_NVIC_INIT_H_

#define GROUP_16_SUB_NON	0b000
#define GROUP_8_SUB_2		0b100
#define GROUP_4_SUB_4		0b101
#define GROUP_2_SUB_8		0b110
#define GROUP_NON_SUB_16	0b111

//-------------------------------------
#define Memory_management_fault 	-6
#define Bus_fault 					-5
#define Usage_fault					-4
////////////////////////////////--------
#define SVCall 						-3
////////////////////////////////--------
#define PendSV						-2
#define SysTick						-1
//-------------------------------------

#define WWDG 		 0
#define EXTI16 		 1
#define EXTI21 		 2
#define EXTI22 		 3
#define FLASH 		 4
#define RCC 		 5
#define ETI0 		 6
#define EXTI1 		 7
#define EXTI2 		 8
#define EXTI3 		 9
#define EXTI4 		 10
#define DMA1_STREAM0 11
#define DMA1_STREAM1 12
#define DMA1_STREAM2 13
#define DMA1_STREAM3 14
#define DMA1_STREAM4 15
#define DMA1_STREAM5 16
#define DMA1_STREAM6 17
#define ADC 		 18
#define EXTI9        23
#define TIM1_BRK_TIM9 24
#define TIM1_UP_TIM10 25
#define TIM1_TRG_COM_TIM11 26
#define TIM1_CC 	 27
#define TIM2 		 28
#define TIM3  		 29
#define TIM4 		 30
#define I2C1_EV 	 31
#define I2C1_ER 	 32
#define I2C2_EV 	 33
#define I2C2_ER 	 34
#define SPI1 	     35
#define SPI2 		 36
#define USART1 		 37
#define USART2 		 38
#define EXTI15_10 	 30
#define EXTI17 	     41
#define EXTI18 		 42
#define DMA1_STREAM7 47
#define SDIO  		 49
#define TIM5 		 50
#define SPI3 		 51
#define DMA2_STREAM0 56
#define DMA2_STREAM1 57
#define DMA2_STREAM2 58
#define DMA2_STREAM3 59
#define DMA2_STREAM4 60
#define OTG_FS 		 67
#define DMA2_STREAM5 68
#define DMA2_STREAM6 69
#define DMA2_STREAM7 70
#define USART6 		 71
#define I2C3_EV 	 72
#define I2C3_ER 	 73
#define FPU 		 81
#define SPI4 		 84

void NVIC_vEnable_Pri(u8 Pri_Id);
void NVIC_vDisable_Pri(u8 Pri_Id);
void NVIC_vSet_pending_Pri(u8 Pri_Id);
void NVIC_vClear_pending_Pri(u8 Pri_Id);
u8 NVIC_U8GetActive(u8 Pri_Id);
void NVIC_vSetPriorityConfig(u8 copy_priority_option);
void NVIC_vSetPriority(s8 Copy_u8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);





#endif /* MCAL_NVIC_NVIC_INIT_H_ */
