/**************************************************************************************************************
 *
 *   Module --> Interrupts\exceptions controller
 *
 *   File name --> IntCtrl.h
 *
 *   Description --> Header file for TM4C123GH6PM Microcontroller - Interrupt Controller Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#ifndef INTCTRL_H
#define INTCTRL_H

#include "IntCtrl_Types.h"



/*******************************************   FUNCTIONS PROTOTYPES  *******************************************/

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
);

extern const IntCtrl_Configs IntCtrl_Configurations;

#endif