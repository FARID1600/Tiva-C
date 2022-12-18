 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

//El shifted by tab dy el 7agat el gbtaha mn el manual
//El comments bta3ty btb2a //kalam w ta7taha //Fadya w t7tohom space
//

#ifndef DIO_CFG_H
#define DIO_CFG_H

// Number of the configured Dio Channels.
#define DIO_CONFIGURED_CHANNLES             (2U)

// Channel Index in the array of structures in Dio_PBcfg.c.
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_LED2_CHANNEL_ID_INDEX        (uint8)0x01
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x02
#define DioConf_SW2_CHANNEL_ID_INDEX         (uint8)0x03

// Dio_(Channel/Port)Type is a typedef defined in Dio.h
//

// DIO Configured Port ID's (0->5 = A->F).
#define DioConf_LED1_PORT_NUM                (Dio_PortType)5
#define DioConf_LED2_PORT_NUM                (Dio_PortType)5
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)5
#define DioConf_SW2_PORT_NUM                 (Dio_PortType)5

// DIO Configured Channel ID's (pin number).
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)1
#define DioConf_LED2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)4
#define DioConf_SW2_CHANNEL_NUM              (Dio_ChannelType)0 

#endif /* DIO_CFG_H */
