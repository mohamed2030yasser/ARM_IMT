


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../RCC/RCC_cfg.h"
#include "../RCC/RCC_int.h"
#include "../RCC/RCC_prv.h"

#include "NVIC_cfg.h"
#include "NVIC_prv.h"
#include "NVIC_init.h"


void NVIC_vEnable_Pri(u8 Pri_Id)
{
	NVIC->ISER[Pri_Id/32] = (1 << (Pri_Id % 32));
}

void NVIC_vDisable_Pri(u8 Pri_Id)
{
	NVIC->ICER[Pri_Id/32] = (1 << (Pri_Id % 32));
}

void NVIC_vSet_pending_Pri(u8 Pri_Id)
{
	NVIC->ISPR[Pri_Id/32] = (1 << (Pri_Id % 32));
}

void NVIC_vClear_pending_Pri(u8 Pri_Id)
{
	NVIC->ICPR[Pri_Id/32] = (1 << (Pri_Id % 32));
}

u8 NVIC_U8GetActive(u8 Pri_Id)
{
	u8 data = GET_BIT(NVIC->IABR[Pri_Id/32], (Pri_Id % 32));
	return data;
}
