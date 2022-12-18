/**************************************************************************************************************
 *
 *   Module --> General Purpose Timer
 *
 *   File name --> Gpt.h
 *
 *   Description --> Header file for TM4C123GH6PM Microcontroller - General Purpose Timer Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#ifndef GPT_H
#define GPT_H

#include "Std_Types.h"
#include "Gpt_Types.h"

/*******************************************   FUNCTIONS PROTOTYPES  *******************************************/

/************************************************************************************
* Service Name: Gpt_Init
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the hardware timer module.
************************************************************************************/
void Gpt_Init(
    const Gpt_Configs* ConfigPtr
);

/************************************************************************************
* Service Name: Gpt_GetTimeElapsed
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel - Numeric Identifier to the GPT Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType   -   Elapsed timer value (in number of ticks)
* Description: Return the time already elapsed
************************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(
    Gpt_ChannelType Channel
);

/************************************************************************************
* Service Name: Gpt_GetTimeRemaining
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel - Numeric Identifier to the GPT Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType   -   Remaining timer value (in number of ticks)
* Description: Returns the time remaining until the target time is reached.
************************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(
    Gpt_ChannelType Channel
);

/************************************************************************************
* Service Name: Gpt_StartTimer
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel      -    Numeric Identifier to the GPT Channel
                   Value        -    Target time in number of ticks
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Starts a timer channel.
************************************************************************************/
void Gpt_StartTimer(
    Gpt_ChannelType Channel,
    Gpt_ValueType Value
);

/************************************************************************************
* Service Name: Gpt_StopTimer
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel      -    Numeric Identifier to the GPT Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Stops a timer channel.
************************************************************************************/
void Gpt_StopTimer(
    Gpt_ChannelType Channel
);

/************************************************************************************
* Service Name: Gpt_EnableNotifications
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel      -    Numeric Identifier to the GPT Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Enables the interrupt notification for a channel (relevant in normal mode).
************************************************************************************/
void Gpt_EnableNotification(
    Gpt_ChannelType Channel
);

/************************************************************************************
* Service Name: Gpt_DisableNotifications
* Service ID[hex]: 0x08
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel      -    Numeric Identifier to the GPT Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Disables the interrupt notification for a channel (relevant in normal mode).
************************************************************************************/
void Gpt_DisableNotifaction(
    Gpt_ChannelType Channel
);

/*******************************************   THE CALL BACK FUNCTIONS   *******************************************/

// Timers 0 --> 5.
void Gpt_Timer0_Notification();
void Gpt_Timer1_Notification();
void Gpt_Timer2_Notification();
void Gpt_Timer3_Notification();
void Gpt_Timer4_Notification();
void Gpt_Timer5_Notification();
// Wide timers 0 --> 5.
void Gpt_WTimer0_Notification();
void Gpt_WTimer1_Notification();
void Gpt_WTimer2_Notification();
void Gpt_WTimer3_Notification();
void Gpt_WTimer4_Notification();
void Gpt_WTimer5_Notification();

extern const Gpt_Configs Gpt_Configurations;

#endif