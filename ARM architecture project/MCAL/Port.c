 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"
/* Pointer to point to the configuration parameters */
STATIC const Port_ConfigPIN * Port_PinPtr = NULL_PTR;

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
)
{    
    /* pointer to the required Port Registers base address */
    volatile uint32 * PortGpio_Ptr = NULL_PTR;
    /* Delay variable for the clock */
    volatile uint32 delay = STD_LOW;
    /* Number of configured pins to loop */
    uint8 Pin = PORT_CONFIGURED_PINS;
    /* Point to the first structure within the array of structures */
    Port_PinPtr =  ConfigPtr->Pins;
    /* Loop till all the configured number of pins configures successfully */
    while(Pin > NO_PINS)
    {
        Pin--;
        /* point to the required Port Registers base address */
        switch(STRUCT_PORT_NUM)
        {
            case  PORTA_ID: PortGpio_Ptr = (volatile uint32 *)PORT_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                    break;
            case  PORTB_ID: PortGpio_Ptr = (volatile uint32 *)PORT_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                    break;
            case  PORTC_ID: PortGpio_Ptr = (volatile uint32 *)PORT_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                    break;
            case  PORTD_ID: PortGpio_Ptr = (volatile uint32 *)PORT_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                    break;
            case  PORTE_ID: PortGpio_Ptr = (volatile uint32 *)PORT_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                    break;
            case  PORTF_ID: PortGpio_Ptr = (volatile uint32 *)PORT_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                    break;
        }
        /* Enable clock for PORT and allow time for clock to start*/
        SYSCTL_REGCGC2_REG |= (PORT_PIN_LEVEL_HIGH<<STRUCT_PORT_NUM);
        delay = SYSCTL_REGCGC2_REG;
        /* Configure all the used pins */
        /* Unlock or do nothing for the special registers that need unlocking */
        if( ((PORTD_ID == STRUCT_PORT_NUM) && (PIN_7 == STRUCT_PIN_NUM)) || ((PORTF_ID == STRUCT_PORT_NUM) && (PIN_0 == STRUCT_PIN_NUM)) ) /* PD7 or PF0 */
        {
            /* Unlock the GPIOCR register */  
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B; 
            /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET),
                    STRUCT_PIN_NUM);
        }
        else if( (PORTC_ID == STRUCT_PORT_NUM) && (STRUCT_PIN_NUM <= PIN_3) ) /* Protect JTAG pins: PC0 --> PC3 */
        {
            continue;
        }
        else
        {
            /* Do Nothing ... No need to unlock the commit register for the rest of pins */
        }
        
        if(PORT_PIN_MODE_ADC == STRUCT_PIN_MODE)
        {
            /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALTERNATE_REG_OFFSET),
                    STRUCT_PIN_NUM);
            /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_REG_OFFSET),
                        STRUCT_PIN_NUM);
            /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_REG_OFFSET),
                    STRUCT_PIN_NUM);
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CONTROL_REG_OFFSET) &= ~(PORT_CONTROL_REG_PMCx_POSITIVE_MASK << (STRUCT_PIN_NUM * SHIFT_PMCx_LEFT));
        }
        else if(PORT_PIN_MODE_DIO == STRUCT_PIN_MODE)
        {
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_REG_OFFSET),
                        STRUCT_PIN_NUM);
            /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALTERNATE_REG_OFFSET),
                        STRUCT_PIN_NUM);
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_REG_OFFSET),
                    STRUCT_PIN_NUM); 
            /* Clear the PMCx bits for this pin */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CONTROL_REG_OFFSET) &= ~(PORT_CONTROL_REG_PMCx_POSITIVE_MASK << (STRUCT_PIN_NUM * SHIFT_PMCx_LEFT));
        }
        else
        {
            /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALTERNATE_REG_OFFSET),
                    STRUCT_PIN_NUM);
            /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_REG_OFFSET),
                        STRUCT_PIN_NUM);
            /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_REG_OFFSET),
                    STRUCT_PIN_NUM); 
            /* Clear the PMCx bits for this pins, then add (by oring) the number defined in the pin mode enum within the structure */
            /* This is a user dependent code, he must add the mode within the enum in the correctr order, based on what port and pin he is using */
            /* Again, the code depends on the user, it is the user responsibility to fill the enum correctly (or by using a GUI) */
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CONTROL_REG_OFFSET) = ( (*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CONTROL_REG_OFFSET)) & (~(PORT_CONTROL_REG_PMCx_POSITIVE_MASK << (STRUCT_PIN_NUM * SHIFT_PMCx_LEFT)) ) ) || (~( STRUCT_PIN_MODE << (STRUCT_PIN_NUM * SHIFT_PMCx_LEFT) ));
        }
        
        if(PORT_PIN_OUT == STRUCT_PIN_DIRECTION)
        {   
            /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIRECTION_REG_OFFSET),
                    STRUCT_PIN_NUM);                
            
            if(PORT_PIN_LEVEL_HIGH == STRUCT_PIN_INITIAL_VALUE)
            {   /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET),
                        STRUCT_PIN_NUM);          
            }
            else if(PORT_PIN_LEVEL_LOW == STRUCT_PIN_INITIAL_VALUE)
            {   /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET),
                            STRUCT_PIN_NUM);        
            }
            else
            {
            /* Do nothing */
            }
        }
        else if(PORT_PIN_IN == STRUCT_PIN_DIRECTION)
        {  
                /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIRECTION_REG_OFFSET),
                        STRUCT_PIN_NUM);             
            
            if(PULL_UP == STRUCT_PIN_RESISTOR)
            {   
                /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULLUP_REG_OFFSET),
                        STRUCT_PIN_NUM);       
            }
            else if(PULL_UP == STRUCT_PIN_RESISTOR)
            {   
                /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULLDOWN_REG_OFFSET),
                        STRUCT_PIN_NUM);     
            }
            else if(Port_OFF == STRUCT_PIN_RESISTOR)
            {   
                /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULLUP_REG_OFFSET),
                            STRUCT_PIN_NUM);     
                /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULLDOWN_REG_OFFSET),
                            STRUCT_PIN_NUM);   
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }             
    }
}