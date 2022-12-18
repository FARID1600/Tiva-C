 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: PORT_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - PORT Driver Registers
 *
 * Author: Abdelrahman Mohamed Farid
 ******************************************************************************/

#ifndef PORT_REGS_H
#define PORT_REGS_H

#include "Std_Types.h"

/* Define the base addresses */
#define PORT_PORTA_BASE_ADDRESS           0x40004000
#define PORT_PORTB_BASE_ADDRESS           0x40005000
#define PORT_PORTC_BASE_ADDRESS           0x40006000
#define PORT_PORTD_BASE_ADDRESS           0x40007000
#define PORT_PORTE_BASE_ADDRESS           0x40024000
#define PORT_PORTF_BASE_ADDRESS           0x40025000

/* Define the offsets */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIRECTION_REG_OFFSET         0x400
#define PORT_ALTERNATE_REG_OFFSET         0x420
#define PORT_PULLUP_REG_OFFSET            0x510
#define PORT_PULLDOWN_REG_OFFSET          0x514
#define PORT_DIGITAL_REG_OFFSET           0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_REG_OFFSET            0x528
#define PORT_CONTROL_REG_OFFSET           0x52C

/* Clock register address */
#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE108))

#endif /* PORT_REGS_H */
