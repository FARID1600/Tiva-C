/**************************************************************************************************************
 *
 *   Module --> Interrupts\exceptions controller
 *
 *   File name --> IntCtrl_Lcfg.c
 *
 *   Description --> Post-build configurations for TM4C123GH6PM Microcontroller - Interrupt Controller Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/
#include "IntCtrl.h"

const IntCtrl_Configs IntCtrl_Configurations =
{
    GPIO_PORTA,			ON, GROUP_PRI0,
    GPIO_PORTB,			ON, GROUP_PRI1,
    GPIO_PORTC,			ON, GROUP_PRI2,
    GPIO_PORTD,			ON, GROUP_PRI0,
    GPIO_PORTE,			ON, GROUP_PRI1,
    UART0,				ON, GROUP_PRI2,
    UART1,				ON, GROUP_PRI0,
    SSI0,				ON, GROUP_PRI1,
    I2C0,				ON, GROUP_PRI2,
    PWM0_Fault,			ON, GROUP_PRI0,
    PWM0_GENERATOR0,	ON, GROUP_PRI1,
    PWM0_GENERATOR1,	ON, GROUP_PRI2,
    PWM0_GENERATOR2,	ON, GROUP_PRI0,
    QEI0,				ON, GROUP_PRI1,
    ADC0_SEQUENCE0,		ON, GROUP_PRI2,
    ADC0_SEQUENCE1,		ON, GROUP_PRI0,
    ADC0_SEQUENCE2,		ON, GROUP_PRI1,
    ADC0_SEQUENCE3,		ON, GROUP_PRI2,
    WDT0_1,				ON, GROUP_PRI0,
    TIMER0A_16_32,		ON, GROUP_PRI1,
    TIMER0B_16_32,		ON, GROUP_PRI2,
    TIMER1A_16_32,		ON, GROUP_PRI0,
    TIMER1B_16_32,		ON, GROUP_PRI1,
    TIMER2A_16_32,		ON, GROUP_PRI2,
    TIMER2B_16_32,		ON, GROUP_PRI0,
    ANALOG_COMPARATOR0,	ON, GROUP_PRI1,
    ANALOG_COMPARATOR1,	ON, GROUP_PRI2,
    SYSTEM_CONTROL,		ON, GROUP_PRI0,
    FLAS_EEPROM_CTRL,	ON, GROUP_PRI1,
    GPIO_PORTF,			ON, GROUP_PRI2,
    UART2,				ON, GROUP_PRI0,
    SSI1,				ON, GROUP_PRI1,
    TIMER3A_16_32,		ON, GROUP_PRI2,
    TIMER3B_16_32,		ON, GROUP_PRI0,
    I2C1,				ON, GROUP_PRI1,
    QEI1,				ON, GROUP_PRI2,
    CAN0,				ON, GROUP_PRI0,
    CAN1,				ON, GROUP_PRI1,
    HIBERNATION_MODULE, ON, GROUP_PRI2, 
    USB,				ON, GROUP_PRI0, 
    PWM_GENERATOR3,		ON, GROUP_PRI1, 
    uDMA_SOFTWARE,		ON, GROUP_PRI2, 
    uDMA_ERROR,			ON, GROUP_PRI0, 
    ADC1_SEQUENCE0,		ON, GROUP_PRI1, 
    ADC1_SEQUENCE1,		ON, GROUP_PRI2, 
    ADC1_SEQUENCE2,		ON, GROUP_PRI0, 
    ADC1_SEQUENCE3,		ON, GROUP_PRI1, 
    SSI2,				ON, GROUP_PRI2, 
    SSI3,				ON, GROUP_PRI0, 
    UART3,				ON, GROUP_PRI1, 
    UART4,				ON, GROUP_PRI2, 
    UART5,				ON, GROUP_PRI0, 
    UART6,				ON, GROUP_PRI1, 
    UART7,				ON, GROUP_PRI2, 
    I2C2,				ON, GROUP_PRI0, 
    I2C3,				ON, GROUP_PRI1, 
    TIMER4A_16_32,		ON, GROUP_PRI2, 
    TIMER4B_16_32,		ON, GROUP_PRI0, 
    TIMER5A_16_32,		ON, GROUP_PRI1, 
    TIMER5B_16_32,		ON, GROUP_PRI2, 
    TIMER0A_32_64,		ON, GROUP_PRI0, 
    TIMER0B_32_64,		ON, GROUP_PRI1, 
    TIMER1A_32_64,		ON, GROUP_PRI2, 
    TIMER1B_32_64,		ON, GROUP_PRI0, 
    TIMER2A_32_64,		ON, GROUP_PRI1, 
    TIMER2B_32_64,		ON, GROUP_PRI2, 
    TIMER3A_32_64,		ON, GROUP_PRI0, 
    TIMER3B_32_64,		ON, GROUP_PRI1, 
    TIMER4A_32_64,		ON, GROUP_PRI2, 
    TIMER4B_32_64,		ON, GROUP_PRI0, 
    TIMER5A_32_64,		ON, GROUP_PRI1, 
    TIMER5B_32_64,		ON, GROUP_PRI2, 
    SYSTEM_EXCEPTION,	ON, GROUP_PRI0, 
    PWM1_GENERATOR0,	ON, GROUP_PRI1, 
    PWM1_GENERATOR1,	ON, GROUP_PRI2, 
    PWM1_GENERATOR2,	ON, GROUP_PRI0, 
    PWM1_GENERATOR3,	ON, GROUP_PRI1, 
    PWM1_FAULT,			ON, GROUP_PRI2
};