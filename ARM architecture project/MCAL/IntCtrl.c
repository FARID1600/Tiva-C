/**************************************************************************************************************
 *
 *   Module --> Interrupts\exceptions controller
 *
 *   File name --> IntCtrl.c
 *
 *   Description --> source file for TM4C123GH6PM Microcontroller - Interrupt Controller Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 ******************************************************************************/

#include "IntCtrl.h"
#include "IntCtrl_Regs.h"
#include "Compiler.h"
#include "Platform_Types.h"

STATIC const IntCtrl_InterruptConfig* IRQ_Ptr = NULL_PTR;
/*******************************************************************************
 *                                 Functions                                   *
 ******************************************************************************/
/*
 *  Service Name: IntCtrl_Init
 *  Sync/Async: Synchronous
 *  Reentrancy: Non Reentrant
 *  Parameters (in): None
 *  Parameters (inout): None
 *  Parameters (out): None
 *  Return value: None
 *  Description: Initialize NVIC/SCB module by parsing the configurations into
 *               NVIC/SCB registers.
 */
void IntCtrl_Init(
	const IntCtrl_Configs* ConfigPtr
)
{
		// Used to iterate on all the IRQs throw the for loop.
		uint8 counter;
    // Used to swipe threw registers with same name, but with diff. no. (EN is repeated EN0->EN4 for example).
    uint8 register_flag = NONE;
    uint8 PRI_reg_offset = NONE;
    uint8 PRIx_interrupt_location = NONE;
    // Let the global ptr points to the configuration structure with the ConfigPtr.
    IRQ_Ptr = ConfigPtr->InterruptsConfig;
    /* 
     * Steps description:
     * 1. Configure grouping\sub-grouping system in APINT register in SCB (xxx-yyy).
     * 2. Assign group\sub-group priorities in NVIC_PRIx and SCB_SYSPRIx registers.
     * 3. Enable\Disable interrupts based on use configs in NVIC_ENx and SCB_Sys(enabled by default) regs.
     */
    // Add the magic value to the APINt register to unlock it.
    APINT.slice_access.VECTKEY = IntCtrl_APINT_VECTKEY_MAGIC_NUM;
    // Choose 8 group priorities and 0 sub-priorities.
    APINT.slice_access.PRIGROUP = IntCtrl_Group3_Sub0;
    for(counter = NONE; counter < NUM_OF_IRQ; counter++)
    {
        // Increment EN register offset to assign each consecutive 32 interrupt numbers from 0->138 in EN(0->4) respectively.
        if( (IRQ_Ptr[counter]).InterruptType >= IRQS_PER_REGISTER )
        {
            register_flag = (IRQ_Ptr[counter]).InterruptType / IRQS_PER_REGISTER;
        }
        else
        {
            // Do nothing.
        }
        // to determine PRI(offset). We've 139 interrupts (0->138) and 139/4=35 PRI registers (0->34).
        PRI_reg_offset = (IRQ_Ptr[counter]).InterruptType / IRQS_IN_PRI_REG;
        // INTA or INTB or INTC or INTD.
        PRIx_interrupt_location = (IRQ_Ptr[counter]).InterruptType % IRQS_IN_PRI_REG;
        // Assign priorities throw PRI(offset) register.
        PRI(PRI_reg_offset) |= ( (IRQ_Ptr[counter]).GroupPriority << (START_RESERVED_BITS_IN_PRI_REG + IRQ_SWITCH_OFFSET_IN_PRI_REG * PRIx_interrupt_location) );
        // (ptr->InterruptsConfig[counter]) is the current interrupt structure.
        if( (IRQ_Ptr[counter]).state == ON )
        {
            // Enable the current interrupt. %32 so that the shifting is within register EN(offset) width.
            EN(register_flag) |= ( ONE_PLACE << ( ( (IRQ_Ptr[counter]).InterruptType ) % IRQS_PER_REGISTER )  );
        }
        else
        {
            // Disable the current interrupt.
            DIS(register_flag) |= ( ONE_PLACE << ( ( (IRQ_Ptr[counter]).InterruptType ) % IRQS_PER_REGISTER )  );
        }
    }
}