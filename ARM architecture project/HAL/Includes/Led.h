/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "Std_Types.h"

#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW
// Configure the LED Port Number.
#define LED_PORT DioConf_LED1_PORT_NUM
// Configure the LED Pin Number.
#define LED_PIN_NUM DioConf_LED1_CHANNEL_NUM


/*
 * Description: Turn on the LED.
 */
void LED_setOn(void);

/*
 * Description: Turn off the LED.
 */
 void LED_setOff(void);

/*
 * Description: Toggle the LED.
 */
 void LED_toggle(void);

#endif
