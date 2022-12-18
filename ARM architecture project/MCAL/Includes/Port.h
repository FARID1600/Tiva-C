 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Abdelrahman Mohamed Farid
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Common_Macros.h"
#include "Port_Types.h"

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr --> Pointer to post-build configuration data.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module:
*              1. Setup the pin direction.
*              2. Setup the internal resistor for I/P pin.
*              3. Setup initial value for O/P pin.
*              4. Setup pin mode.
************************************************************************************/
void Port_Init(
    const Port_ConfigType* ConfigPtr
);

/*******************************************************************************
 *                       Extern Variables                                    *
 *******************************************************************************/
extern const Port_ConfigType Port_Configurations;

/*******************************************************************************
 *                       Port Definitions                                      *
 *******************************************************************************/
/* Pin with port definisions */
#define PORT_PA0                        (0U)
#define PORT_PA1                        (1U)
#define PORT_PA2                        (2U)
#define PORT_PA3                        (3U)
#define PORT_PA4                        (4U)
#define PORT_PA5                        (5U)
#define PORT_PA6                        (6U)
#define PORT_PA7                        (7U)
#define PORT_PB0                        (8U)
#define PORT_PB1                        (9U)
#define PORT_PB2                        (10U)
#define PORT_PB3                        (11U)
#define PORT_PB4                        (12U)
#define PORT_PB5                        (13U)
#define PORT_PB6                        (14U)
#define PORT_PB7                        (15U)
#define PORT_PC0                        (16U)
#define PORT_PC1                        (17U)
#define PORT_PC2                        (18U)
#define PORT_PC3                        (19U)
#define PORT_PC4                        (20U)
#define PORT_PC5                        (21U)
#define PORT_PC6                        (22U)
#define PORT_PC7                        (23U)
#define PORT_PD0                        (24U)
#define PORT_PD1                        (25U)
#define PORT_PD2                        (26U)
#define PORT_PD3                        (27U)
#define PORT_PD4                        (28U)
#define PORT_PD5                        (29U)
#define PORT_PD6                        (30U)
#define PORT_PD7                        (31U)
#define PORT_PE0                        (32U)
#define PORT_PE1                        (33U)
#define PORT_PE2                        (34U)
#define PORT_PE3                        (35U)
#define PORT_PE4                        (36U)
#define PORT_PE5                        (37U)
#define PORT_PF0                        (38U)
#define PORT_PF1                        (39U)
#define PORT_PF2                        (40U)
#define PORT_PF3                        (41U)
#define PORT_PF4                        (42U)

/* Macros to get access to structure elements and stay human readable */
#define STRUCT_PORT_NUM                 Port_PinPtr[Pin].port_num
#define STRUCT_PIN_NUM                  Port_PinPtr[Pin].pin_num
#define STRUCT_PIN_MODE                 Port_PinPtr[Pin].pin_mode
#define STRUCT_PIN_DIRECTION            Port_PinPtr[Pin].direction
#define STRUCT_PIN_INITIAL_VALUE        Port_PinPtr[Pin].initial_value
#define STRUCT_PIN_RESISTOR             Port_PinPtr[Pin].resistor
#define STRUCT_CHANGE_PIN_MODE          Port_PinPtr[Pin].pin_mode_changeable
#define STRUCT_CHANGE_PIN_DIRECTION     Port_PinPtr[Pin].pin_direction_changeable



#endif
