#include "IntCtrl.h"
#include "Gpt.h"
#include "Led.h"
#include "Port.h"
#include "Dio.h"

STATIC volatile uint8 Gpt_ticksCounter = 0;

// The call back function.
void Gpt_Timer0_Notification()
{
    Gpt_ticksCounter++;
		// Turn on the LED after 2 overflows, and off after another 2.
    if( (Gpt_ticksCounter % 2) == 0 )
    {
        LED_toggle();
    }
		else
		{
				// Do nothing.
		}
}

int main(void)
{
		// Initialize the interrupts.
    IntCtrl_Init(&IntCtrl_Configurations);
    // Initialize Port Driver.
    Port_Init(&Port_Configurations);
    // Initialize Dio Driver.
    Dio_Init(&Dio_Configurations);
    // Initialize the Timers.
    Gpt_Init(&Gpt_Configurations);
    // Enable timer interrupts.
    Gpt_EnableNotification(GPT_TIMER0);
     /*
	   * Start the timer interrupts. The 2nd argument is the number of ticks before overflow.
		 * Time before interrupt = (1/configured_frequency)*number_of_ticks.
		 * NB: If the given argument > max value (configured in init), the argument is replaced by the max value.
	   */
    Gpt_StartTimer(GPT_TIMER0, 62500);
		/* Infinite loop. */
    for(;;);
}
