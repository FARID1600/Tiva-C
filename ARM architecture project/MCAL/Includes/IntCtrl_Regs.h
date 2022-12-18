/**************************************************************************************************************
 *
 *   Module --> Interrupts\exceptions controller
 *
 *   File name --> IntCtrl_Regs.h
 *
 *   Description --> Registers assignment for TM4C123GH6PM Microcontroller - Interrupt Controller Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#ifndef INTCTRL_REGS_H
#define INTCTRL_REGS_H

#include "Compiler.h"
#include "Platform_Types.h"

// NVIC registers base Address.
#define CORTEXM4_PERIPHERALS_BASE_ADRESS    0xE000E000

/*******************************************   NVIC Registers Map --> page 134   *******************************************/

#define EN(select_one)               ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X100 + 4 * select_one) )
#define DIS(select_one)              ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X180 + 4 * select_one) )
#define PEND(select_one)             ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X200 + 4 * select_one) )
#define UNPEND(select_one)           ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X280 + 4 * select_one) )
#define ACTIVE(select_one)           ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X300 + 4 * select_one) )
#define PRI(select_one)              ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X400 + 4 * select_one) )
#define SWTRIG                       ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XF00) )

/*******************************************   SCB Registers Map --> page 136   ********************************************/

#define ACTLR                       ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0X008) )
#define CPUID                       ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD00) )
#define INTCTRL                     ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD04) )
#define VTABLE                      ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD08) )
#define APINT                       ( *(volatile IntCtrl_ApintTag*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD0C) )
#define SYSCTRL                     ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD10) )
#define CFGCTRL                     ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD14) )
#define SYSPRI(select_one)          ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD14 + 4 * select_one) )
#define SYSHNDCTRL                  ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD24) )
#define FAULTSTAT                   ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD28) )
#define HFAULTSTAT                  ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD2C) )
#define MMADDR                      ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD34) )
#define FAULTADDR                   ( *(volatile uint32*)(CORTEXM4_PERIPHERALS_BASE_ADRESS + 0XD38) )

/*********************************************   APINT register addresses   **********************************************/

typedef struct
{
    uint32 VECTRESET  : 1;      // This bit must be written as a 0, otherwise behavior is unpredictable (reserved to debug).
    uint32 VECTCLRACT : 1;      // This bit must be written as a 0, otherwise behavior is unpredictable (reserved to debug).
    uint32 SYSRESREQ  : 1;      // write 1 --> resets the core and all on-chip peripherals except the Debug interface.
    uint32            : 5;
    uint32 PRIGROUP   : 3;      // Determines group and sub-group priorities --> xxx = 0x0-0x4, xxy = 0x5, xyy = 0x6, yyy = 0x7.
    uint32            : 4;
    uint32 ENDIANESS  : 1;      // It's always 0 as Tiva-C uses little-endian.
    uint32 VECTKEY    : 16;     // Don't forget to write the magic key value to access the register --> 0xFA05.
}IntCtrl_ApintRegs;

typedef union
{
    uint32 register_access;
    IntCtrl_ApintRegs slice_access;
}IntCtrl_ApintTag;


/***************************************************************************************************************************/
#endif