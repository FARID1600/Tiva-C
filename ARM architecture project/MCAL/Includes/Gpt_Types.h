/**************************************************************************************************************
 *
 *   Module --> General Purpose Timer
 *
 *   File name --> Gpt_Types.h
 *
 *   Description --> Types header file for TM4C123GH6PM Microcontroller - General Purpose Timer Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#include "Std_Types.h"
#include "Gpt_Cfg.h"

/*******************************************   MODULE DATA TYPES  *******************************************/

typedef uint32 Gpt_ValueType;
// Define a pointer to function named Gpt_CallBackFunc as a type.
typedef  void(*Gpt_CallBackFunc)(void);

/*
 * Description: Enum to hold the available modes.
 */
typedef enum
{
	GPT_ONE_SHOT = 1,
	GPT_PERIODIC_MODE
}Gpt_ModeType;

/*
 * Description: List all the module timers.
 */
typedef enum
{
	/* Normal timers */
	GPT_TIMER0,
	GPT_TIMER1,
	GPT_TIMER2,
	GPT_TIMER3,
	GPT_TIMER4,
	GPT_TIMER5,
	/* Wide timers */
	GPT_WTIMER0,
	GPT_WTIMER1,
	GPT_WTIMER2,
	GPT_WTIMER3,
	GPT_WTIMER4,
	GPT_WTIMER5
}Gpt_ChannelType;

/*
 * Description: Pre-scalers.
 */
typedef enum
{
	GPT_16MHZ,
	GPT_8MHZ,
	GPT_4MHZ,
	GPT_2MHZ,
	GPT_1MHZ,
	GPT_500KHZ,
	GPT_250KHZ,
	GPT_125KHZ,
	GPT_63KHZ,
    #if(WIDE_TIMERS == STD_ON) 
	GPT_31KHZ,
	GPT_16KHZ,
	GPT_8KHZ,
	GPT_4KHZ,
	GPT_2KHZ,
	GPT_1KHZ,
	GPT_488HZ,
	GPT_244HZ
    #endif
}Gpt_ChannelTickFrequency;

/*
 * Description: Hold any configurations data of the timers.
 * 1. Which timer?
 * 2. Frequency it works on.
 * 3. Max counter value.
 * 4. Periodic or one-shot?
 * 5. Call back function.
 */
typedef struct
{
	Gpt_ChannelType	Gpt_ChannelID;
	Gpt_ChannelTickFrequency Gpt_Frequency;
	Gpt_ValueType Gpt_ChannelTickValueMax;
	Gpt_ModeType Gpt_ChannelMode;
	Gpt_CallBackFunc Gpt_Notification;
}Gpt_ConfigType;

typedef struct
{
	Gpt_ConfigType timersConfigs[GPT_NUM_TIMERS];
}Gpt_Configs;

#endif