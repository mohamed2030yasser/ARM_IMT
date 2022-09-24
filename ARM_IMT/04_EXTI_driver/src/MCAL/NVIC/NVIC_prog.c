


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../RCC/RCC_cfg.h"
#include "../RCC/RCC_int.h"
#include "../RCC/RCC_prv.h"

#include "NVIC_cfg.h"
#include "NVIC_prv.h"
#include "NVIC_init.h"

static u32 globalStatic_u32_GropupConfig ;

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

void NVIC_vSetPriorityConfig(u8 copy_priority_option)
{
	globalStatic_u32_GropupConfig = 0xFA050000 | (copy_priority_option << 8);
	SCB->AIRCR = globalStatic_u32_GropupConfig;
}

void NVIC_vSetPriority(s8 Copy_u8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
    u8 local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((globalStatic_u32_GropupConfig - 0x05FA0300) / 256);
    // Core Peripheral
    if (Copy_u8INTID < 0)
    {
        if (Copy_u8INTID == Memory_management_fault || Copy_u8INTID == Bus_fault || Copy_u8INTID == Usage_fault)
        {
            Copy_u8INTID += 3;
            SCB->SHPR1 = (local_u8Priority) << ((8 * Copy_u8INTID) + 4);
        }
        else if (Copy_u8INTID == SVCall)
        {
            Copy_u8INTID += 7;
            SCB->SHPR2 = (local_u8Priority) << ((8 * Copy_u8INTID) + 4);
        }
        else if (Copy_u8INTID == PendSV || Copy_u8INTID == SysTick)
        {
            Copy_u8INTID += 8;
            SCB->SHPR3 = (local_u8Priority) << ((8 * Copy_u8INTID) + 4);
        }
    }
    // External Peripheral
    else if (Copy_u8INTID >= 0)
    {
        NVIC->IPR[Copy_u8INTID] = local_u8Priority << 4;
    }
}
