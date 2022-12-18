 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Types.h
 *
 * Description: Types header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Abdelrahman Farid
 ******************************************************************************/

#ifndef DIO_TYPES_H
#define DIO_TYPES_H

#include "Std_Types.h"
#include "Dio_Cfg.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

typedef struct
{
/* Member contains the ID of the Port that this channel belongs to */
Dio_PortType Port_Num;
/* Member contains the ID of the Channel*/
Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;

/* Data Structure required for initializing the Dio Driver */
typedef struct Dio_ConfigType
{
  Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;

#endif