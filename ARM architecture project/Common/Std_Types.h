 /******************************************************************************
 *
 * Module: Common - Platform
 *
 * File Name: Std_Types.h
 *
 * Description: General type definitions
 *
 * Author: Abdelrahman Farid
 *
 *******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

/*
 *  Describes the standard Return Type Definitions/
 */
typedef uint8  Std_ReturnType;

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */

#define ZERO            0 /*Define 0 as ZERO (AR Rules)*/

#define ONE_PLACE       1

/* Define IDs to the ports */
#define PORTA_ID        0
#define PORTB_ID        1
#define PORTC_ID        2
#define PORTD_ID        3
#define PORTE_ID        4
#define PORTF_ID        5

/* Define IDs to the pins */
#define PIN_0           0
#define PIN_1           1
#define PIN_2           2
#define PIN_3           3
#define PIN_4           4
#define PIN_5           5
#define PIN_6           6
#define PIN_7           7

#endif /* STD_TYPES_H */
