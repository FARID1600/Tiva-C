 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Abdelrahman Mohamed Farid
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_PINS                  (43U)
/* Number of accessable pins in Tiva-C */
#define PORT_NUMBER_OF_PORT_PINS              (8U)

/* Number of available modes in */
#define NUMBER_OF_PIN_MODES                   PORT_PIN_MODE_SPI
/* N.B.: PORT_PIN_MODE_SPI must be the last element in Port_PinMode the enum */

/* Description: Port pin mode from mode list for use with Port_Init() function. You have to configure the numbers depending on what pin you are using */
typedef enum
{
PORT_PIN_MODE_DIO, PORT_PIN_MODE_ADC, PORT_PIN_MODE_CAN, PORT_PIN_MODE_DIO_GPT, PORT_PIN_MODE_DIO_WDG, PORT_PIN_MODE_FLEXRAY, PORT_PIN_MODE_ICU, PORT_PIN_MODE_LIN, PORT_PIN_MODE_MEM, PORT_PIN_MODE_PWM, PORT_PIN_MODE_SPI
}Port_PinMode;

#endif /* PORT_CFG_H */
