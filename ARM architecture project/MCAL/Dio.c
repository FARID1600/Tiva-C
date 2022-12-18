 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"
#include "Dio_Port_Reg.h"

STATIC const Dio_ConfigChannel * Dio_PortChannels = NULL_PTR;

/************************************************************************************
* Service Name: Dio_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/

void Dio_Init(
	const Dio_ConfigType * ConfigPtr
)
{
	// Point to the DIO structures that contain data.
	Dio_PortChannels = ConfigPtr->Channels; 
}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(
	Dio_ChannelType ChannelId, Dio_LevelType Level
)
{					
	volatile uint32 * Port_Ptr = NULL_PTR;
	// Point to the required port register according to the ID.
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
	case PORTA_ID:   Port_Ptr = &GPIO_PORTA_DATA_REG;
			  break;
	case PORTB_ID:   Port_Ptr = &GPIO_PORTB_DATA_REG;
			  break;
	case PORTC_ID:   Port_Ptr = &GPIO_PORTC_DATA_REG;
			  break;
	case PORTD_ID:   Port_Ptr = &GPIO_PORTD_DATA_REG;
			  break;
	case PORTE_ID:   Port_Ptr = &GPIO_PORTE_DATA_REG;
			  break;
	case PORTF_ID:   Port_Ptr = &GPIO_PORTF_DATA_REG;
			  break;
	}
	if(Level == STD_HIGH)
	{
		// Write logic high.
		SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
	}
	else if(Level == STD_LOW)
	{
		// Write logic low.
		CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
	}
	else
	{
		// Do nothing
	}

}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;
	// Point to the required port register according to the ID.
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
		case PORTA_ID:    Port_Ptr = &GPIO_PORTA_DATA_REG;
			   break;
		case PORTB_ID:    Port_Ptr = &GPIO_PORTB_DATA_REG;
			   break;
		case PORTC_ID:    Port_Ptr = &GPIO_PORTC_DATA_REG;
			   break;
		case PORTD_ID:    Port_Ptr = &GPIO_PORTD_DATA_REG;
			   break;
		case PORTE_ID:    Port_Ptr = &GPIO_PORTE_DATA_REG;
			   break;
		case PORTF_ID:    Port_Ptr = &GPIO_PORTF_DATA_REG;
			   break;
	}
	// Read the required channel.
	if(BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num))
	{
		output = STD_HIGH;
	}
	else
	{
		output = STD_LOW;
	}
	return output;
}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = NULL_PTR;
	Dio_LevelType output = STD_LOW;
	// Point to the required port register according to the ID.
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
		case PORTA_ID:    Port_Ptr = &GPIO_PORTA_DATA_REG;
			   	   break;
		case PORTB_ID:    Port_Ptr = &GPIO_PORTB_DATA_REG;
			   	   break;
		case PORTC_ID:    Port_Ptr = &GPIO_PORTC_DATA_REG;
			   	   break;
		case PORTD_ID:    Port_Ptr = &GPIO_PORTD_DATA_REG;
			   	   break;
		case PORTE_ID:    Port_Ptr = &GPIO_PORTE_DATA_REG;
			   	   break;
		case PORTF_ID:    Port_Ptr = &GPIO_PORTF_DATA_REG;
			   	   break;
	}
	/* Read the required channel and write the required level */
	if(BIT_IS_SET(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num))
	{
		CLEAR_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		output = STD_LOW;
	}
	else
	{
		SET_BIT(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		output = STD_HIGH;
	}
		return output;
}

/************************************************************************************
* Service Name: Dio_ReadPort
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO Port.
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	// casting because the return type Dio_PortLevelType is unit8.
	return ( (uint8)( GPIO_DATA_REG_OFFSET(PortId) ) );
}


/************************************************************************************
* Service Name: Dio_WritePort
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a Port.
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	GPIO_DATA_REG_OFFSET(PortId) = Level;
}