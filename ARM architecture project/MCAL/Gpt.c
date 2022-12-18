/**************************************************************************************************************
 *
 *   Module --> General Purpose Timer
 *
 *   File name --> Gpt.c
 *
 *   Description --> Source file for TM4C123GH6PM Microcontroller - General Purpose Timer Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#include "Gpt.h"
#include "Gpt_Regs.h"
#include "Common_Macros.h"

// Array of pointers to functions that contains the call back function to each timer.
STATIC void (*Gpt_CallBackPtr[GPT_NUM_TIMERS])(void) = { NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR,
                                                         NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR };
// Global pointer to the timer structure.
STATIC const Gpt_ConfigType* Gpt_ptrToStruct = NULL_PTR;

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
)
{
		uint8 timerId;
		Gpt_ptrToStruct = ConfigPtr->timersConfigs;
		for(timerId = 0; timerId < GPT_NUM_TIMERS; timerId++)
		{
				// Skip the timers with an un-defined call-back function.
				if(Gpt_ptrToStruct[timerId].Gpt_Notification == NULL_PTR)
				{
					continue;
				}
				// Configure the call back function to each timer.
				Gpt_CallBackPtr[Gpt_ptrToStruct[timerId].Gpt_ChannelID] = Gpt_ptrToStruct[timerId].Gpt_Notification;
				// Enable the clock for this timer. %6 so if Gpt_ChannelID > 6 (wide timer0->5) write 0->5 IDs in the wide RCGC register.
				SET_BIT(RCGC(Gpt_ptrToStruct[timerId].Gpt_ChannelID), Gpt_ptrToStruct[timerId].Gpt_ChannelID % 6);
				// For a (16/32)/(32/64)-bit timer, this value selects the 16/32-bit timer configuration.
				GPTMCFG(Gpt_ptrToStruct[timerId].Gpt_ChannelID) &= ~(0x7);            // Clear the bits we need to write in.
				GPTMCFG(Gpt_ptrToStruct[timerId].Gpt_ChannelID) |= 0x4;
				// Keep the timer disabled until this bit is set --> CLEAR_BIT(GPTMCTL(Gpt_ptrToStruct[timerId].Gpt_ChannelID), GPTMCTL_TAEN_MASK);
				// Timer A begins counting as soon as it is enabled.
				CLEAR_BIT(GPTMTAMR(Gpt_ptrToStruct[timerId].Gpt_ChannelID), GPTMTAMR_TAWOT_MASK);
				// Configure the timer to count up.
				SET_BIT(GPTMTAMR(Gpt_ptrToStruct[timerId].Gpt_ChannelID), GPTMTAMR_TACDIR_MASK);
				// Configure the timer mode (periodic or one shot).
				GPTMTAMR(Gpt_ptrToStruct[timerId].Gpt_ChannelID) &= ~(0x3);           // Clear the bits we need to write in.
				GPTMTAMR(Gpt_ptrToStruct[timerId].Gpt_ChannelID) |= Gpt_ptrToStruct[timerId].Gpt_ChannelMode;
				// Timer A freezes counting while the processor is halted by the debugger.
				SET_BIT(GPTMCTL(Gpt_ptrToStruct[timerId].Gpt_ChannelID), GPTMCTL_TASTALL_MASK);
				// Configure the pre-scaler.
				GPTMTAPR(Gpt_ptrToStruct[timerId].Gpt_ChannelID) &= ~(0xFFFF);    // Clear the bits we need to write in.
				GPTMTAPR(Gpt_ptrToStruct[timerId].Gpt_ChannelID) |= ( 1 << (Gpt_ptrToStruct[timerId].Gpt_Frequency) ) - 1;
		}
}

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
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
		// Return the register that contains the number of ticks.
		return GPTMTAR(Channel);
}

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
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    // Return the match value - the counted ticks.
    return( GPTMTAILR(Channel) - GPTMTAV(Channel)  ); 
}

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
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
		// Clear the corresponding bit in MIS and RIS registers.
		SET_BIT(GPTMICR(Channel), GPTMICR_TATOCINT_MASK);				// This line is not necessary.
		// Check if the given number of ticks value doesn't exceed the max defined in the post-build structure.
		if(Value < Gpt_ptrToStruct[Channel].Gpt_ChannelTickValueMax)
		{		
				// When timer is counting up, this register sets the upper bound for the timeout event.
				GPTMTAILR(Channel) = Value;
		}
		else
		{
				// Replace Value by the ticks value in the post-build configurations.
				GPTMTAILR(Channel) = Gpt_ptrToStruct[Channel].Gpt_ChannelTickValueMax;
		}
		// Start the counter.
		SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_MASK);
}

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
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
		/*Stop the counter*/
		CLEAR_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_MASK);
}

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
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    // An interrupt is generated when the match value in the GPTMTAMATCHR.
    //SET_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_MASK);
    /*Enable Match interrupt*/
    SET_BIT(GPTMIMR(Channel), GPTMIMR_TATOIM_MASK);
}

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
void Gpt_DisableNotifaction(Gpt_ChannelType Channel)
{
	  /*Disable Match interrupt*/
    CLEAR_BIT(GPTMIMR(Channel), GPTMIMR_TATOIM_MASK);
}

/*********************************  HANDLERS OF THE 12 TIMERS  *********************************/

// Timer0 handler function --> 16 bits.
void TIMER0A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_TIMER0] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_TIMER0])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_TIMER0), GPTMICR_TATOCINT_MASK);
	}
}
// Timer1 handler function --> 16 bits.
void TIMER1A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_TIMER1] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_TIMER1])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_TIMER1), GPTMICR_TATOCINT_MASK);
	}
}
// Timer2 handler function --> 16 bits.
void TIMER2A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_TIMER2] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_TIMER2])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_TIMER2), GPTMICR_TATOCINT_MASK);
	}
}
// Timer3 handler function --> 16 bits.
void TIMER3A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_TIMER3] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_TIMER3])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_TIMER3), GPTMICR_TATOCINT_MASK);
	}
}
// Timer4 handler function --> 16 bits.
void TIMER4A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_TIMER4] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_TIMER4])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_TIMER4), GPTMICR_TATOCINT_MASK);
	}
}
// Timer5 handler function --> 16 bits.
void TIMER5A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_TIMER5] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_TIMER5])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_TIMER5), GPTMICR_TATOCINT_MASK);
	}
}

// Wide timer0 handler function --> 32 bits.
void WTIMER0A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_WTIMER0] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_WTIMER0])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_WTIMER0), GPTMICR_TATOCINT_MASK);
	}
}
// Wide timer1 handler function --> 32 bits.
void WTIMER1A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_WTIMER1] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_WTIMER1])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_WTIMER1), GPTMICR_TATOCINT_MASK);
	}
}
// Wide timer2 handler function --> 32 bits.
void WTIMER2A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_WTIMER2] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_WTIMER2])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_WTIMER2), GPTMICR_TATOCINT_MASK);
	}
}
// Wide timer3 handler function --> 32 bits.
void WTIMER3A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_WTIMER3] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_WTIMER3])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_WTIMER3), GPTMICR_TATOCINT_MASK);
	}
}
// Wide timer4 handler function --> 32 bits.
void WTIMER4A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_WTIMER4] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_WTIMER4])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_WTIMER4), GPTMICR_TATOCINT_MASK);
	}
}
// Wide timer5 handler function --> 32 bits.
void WTIMER5A_Handler(void)
{
	if( Gpt_CallBackPtr[GPT_WTIMER5] != NULL_PTR )
	{
			(*Gpt_CallBackPtr[GPT_WTIMER5])();
			// Clear the corresponding bit in MMIS and MRIS registers.
			SET_BIT(GPTMICR(GPT_WTIMER5), GPTMICR_TATOCINT_MASK);
	}
}