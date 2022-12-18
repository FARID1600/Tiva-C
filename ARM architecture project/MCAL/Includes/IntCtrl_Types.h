/**************************************************************************************************************
 *
 *   Module --> Interrupts\exceptions controller
 *
 *   File name --> IntCtrl_Types.h
 *
 *   Description --> Types header file for TM4C123GH6PM Microcontroller - Interrupt Controller Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/*******************************************   MODULE DATA TYPES  *******************************************/

#define NUM_OF_IRQ       78
#define IntCtrl_APINT_VECTKEY_MAGIC_NUM     0x05FA
#define IRQS_PER_REGISTER             32
#define IRQS_IN_PRI_REG               4
#define START_RESERVED_BITS_IN_PRI_REG      5
#define IRQ_SWITCH_OFFSET_IN_PRI_REG        8
#if(3 == GROUP_PRIORITY_FIELD)
#define SUB_GROUP_PRIORITY_FIELD 0
#elif(2 == GROUP_PRIORITY_FIELD)
#define SUB_GROUP_PRIORITY_FIELD 1
#elif(1 == GROUP_PRIORITY_FIELD)
#define SUB_GROUP_PRIORITY_FIELD 2
#elif(0 == GROUP_PRIORITY_FIELD)
#define SUB_GROUP_PRIORITY_FIELD 3
#endif

typedef enum
{
	IntCtrl_Group3_Sub0 = 0x4,
	IntCtrl_Group2_Sub1,
	IntCtrl_Group1_Sub2,
	IntCtrl_Group0_Sub3
}Priority_field_assign;
/*
 * Description: Hold the interrupt numbers of all the interrupts to generate a software
 * interrupt by writing its number in the INTID section of SWTRIG register.
 */
typedef enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM0_Fault,
    PWM0_GENERATOR0,
    PWM0_GENERATOR1,
    PWM0_GENERATOR2,
    QEI0,
    ADC0_SEQUENCE0,
    ADC0_SEQUENCE1,
    ADC0_SEQUENCE2,
    ADC0_SEQUENCE3,
    WDT0_1,
    TIMER0A_16_32,
    TIMER0B_16_32,
    TIMER1A_16_32,
    TIMER1B_16_32,
    TIMER2A_16_32,
    TIMER2B_16_32,
    ANALOG_COMPARATOR0,
    ANALOG_COMPARATOR1,
    SYSTEM_CONTROL = 28,
    FLAS_EEPROM_CTRL,
    GPIO_PORTF,
    UART2 = 33,
    SSI1,
    TIMER3A_16_32,
    TIMER3B_16_32,
    I2C1,
    QEI1,
    CAN0,
    CAN1,
    HIBERNATION_MODULE = 43,
    USB,
    PWM_GENERATOR3,
    uDMA_SOFTWARE,
    uDMA_ERROR,
    ADC1_SEQUENCE0,
    ADC1_SEQUENCE1,
    ADC1_SEQUENCE2,
    ADC1_SEQUENCE3,
    SSI2 = 57,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    I2C2 = 68,
    I2C3,
    TIMER4A_16_32,
    TIMER4B_16_32,
    TIMER5A_16_32 = 92,
    TIMER5B_16_32,
    TIMER0A_32_64,
    TIMER0B_32_64,
    TIMER1A_32_64,
    TIMER1B_32_64,
    TIMER2A_32_64,
    TIMER2B_32_64,
    TIMER3A_32_64,
    TIMER3B_32_64,
    TIMER4A_32_64,
    TIMER4B_32_64,
    TIMER5A_32_64,
    TIMER5B_32_64,
    SYSTEM_EXCEPTION,
    PWM1_GENERATOR0 = 134,
    PWM1_GENERATOR1,
    PWM1_GENERATOR2,
    PWM1_GENERATOR3,
    PWM1_FAULT
} IntCtrl_InterruptType;
/*
 * Description: Hold the group priority of each interrupt.
 */
#if( (GROUP_PRIORITY_FIELD > 0 ) &&  (GROUP_PRIORITY_FIELD <= 3 ) )
typedef enum
{
    GROUP_PRI0,
    GROUP_PRI1,
    #if( (GROUP_PRIORITY_FIELD == 2) || (GROUP_PRIORITY_FIELD == 3) )
    GROUP_PRI2,
    GROUP_PRI3,
    #endif
    #if(GROUP_PRIORITY_FIELD == 3)
    GROUP_PRI4,
    GROUP_PRI5,
    GROUP_PRI6,
    GROUP_PRI7
    #endif
} IntCtrl_GroupPriority;
#endif
/*
 * Description: Hold the sub-group priority of each interrupt.
 */
#if( (SUB_GROUP_PRIORITY_FIELD > 0 ) &&  (SUB_GROUP_PRIORITY_FIELD <= 3 ) )
typedef enum
{
    SUB_GROUP_PRI0,
    SUB_GROUP_PRI1,
    #if( (SUB_GROUP_PRIORITY_FIELD == 2) || (SUB_GROUP_PRIORITY_FIELD == 3) )
    SUB_GROUP_PRI2,
    SUB_GROUP_PRI3,
    #endif
    #if(SUB_GROUP_PRIORITY_FIELD == 3)
    SUB_GROUP_PRI4,
    SUB_GROUP_PRI5,
    SUB_GROUP_PRI6,
    SUB_GROUP_PRI7
    #endif
} IntCtrl_SubGroupPriority;
#endif
/*
 * Description: Choose whether the selected interrupt is on or off.
 */
typedef enum
{
    OFF,
    ON
} IntCtrl_InterruptState;

/*
 * Description: It holds data for an intterupt that the user needs to configure.
 */
typedef struct
{
    IntCtrl_InterruptType InterruptType;
    IntCtrl_InterruptState state;
    IntCtrl_GroupPriority GroupPriority;
    //IntCtrl_SubGroupPriority SubgroupPriority;
}IntCtrl_InterruptConfig;
/*
 * Description: It holds an array (its size is the number of interrupts to be configured)
 * and each cell in the array is a structure of an interrupt configurations.
 */
typedef struct
{
    IntCtrl_InterruptConfig InterruptsConfig[NUM_OF_IRQ];
}IntCtrl_Configs;

#endif