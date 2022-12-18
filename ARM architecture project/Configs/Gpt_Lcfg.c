/**************************************************************************************************************
 *
 *   Module --> General Purpose Timer
 *
 *   File name --> Gpt_Lcfg.c
 *
 *   Description --> Post-build configurations file for TM4C123GH6PM Microcontroller - General Purpose Timer Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#include "Std_Types.h"
#include "Gpt.h"


 /* PB structure used with Gpt_Init API */
const Gpt_Configs Gpt_Configurations =
{
	GPT_TIMER0,		GPT_63KHZ, 31250		    ,GPT_PERIODIC_MODE,	Gpt_Timer0_Notification,
	GPT_TIMER1,		GPT_125KHZ,	65535		,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_TIMER2,		GPT_250KHZ,	65535		,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_TIMER3,		GPT_1MHZ,	65535		,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_TIMER4,		GPT_4MHZ,	0	        ,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_TIMER5,		GPT_16MHZ,	0	        ,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_WTIMER0,	    GPT_31KHZ,	2147483647	,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_WTIMER1,  	GPT_16KHZ,	2147483647	,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_WTIMER2,	    GPT_8KHZ,	2147483647	,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_WTIMER3,	    GPT_2MHZ,	2147483647	,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_WTIMER4,	    GPT_8MHZ,	0	        ,GPT_PERIODIC_MODE,	NULL_PTR,
	GPT_WTIMER5,	    GPT_16MHZ,	0	        ,GPT_PERIODIC_MODE,	NULL_PTR
};