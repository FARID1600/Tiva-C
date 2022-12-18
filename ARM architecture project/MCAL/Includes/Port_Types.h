/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Types.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Abdelrahman Mohamed Farid
 ******************************************************************************/

#ifndef PORT_TYPES_H
#define PORT_TYPES_H

#include "Port_Cfg.h"
#include "Std_Types.h"

/*******************************************************************************
*                       Module Data Types and hash defines                     *
*******************************************************************************/

/* The 0xF switches alon the 6 LSB to enable the required  port clock */
#define PORT_CONTROL_REG_PMCx_POSITIVE_MASK  0x0000000F
/* Description: Used to reflect a single shift by 4 shifts (1 hexa shift) for the previous #define */
#define SHIFT_PMCx_LEFT                      (4U)
/* Description: Used to remain in the Port_Init while loop, till the configured number of ports are all done */
#define NO_PINS                              (0U)

/* Description: Types to use within the configuration structure */
typedef uint8           Port_PinType;

/* Description: Port PIN Level value 0 or 1 */
typedef enum
{
    PORT_PIN_LEVEL_LOW, PORT_PIN_LEVEL_HIGH
}Port_PinLevelValue;

/* Description: Port pin direction */
typedef enum
{
    PORT_PIN_IN, PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold PIN internal resistor type */
typedef enum
{
    Port_OFF, PULL_UP, PULL_DOWN
}Port_InternalResistor;

/*******************************************************************************
*                            Structures and unions                             *
*******************************************************************************/

/* Description: Structure to configure each individual PIN:
*	    1. The PORT that the pin belongs to --> A, B, C, D, E or F.
*       2. The pin number within the chosen port.
*       3. The pin direction --> INPUT or OUTPUT
*       4. The initial value in case O/P.
*       5. The internal resistor in case I/P --> Disabled, Pull up or Pull down
*       6. The pin mode --> GPIO, ADC, PWM, ...etc.
*/
typedef struct 
{
    Port_PinType port_num; 
    Port_PinType pin_num; 
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    Port_PinLevelValue initial_value;
    Port_PinMode pin_mode;
}Port_ConfigPIN;

/* Description: Array of the configuration structure */
typedef struct
{
    Port_ConfigPIN     Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType;

#endif