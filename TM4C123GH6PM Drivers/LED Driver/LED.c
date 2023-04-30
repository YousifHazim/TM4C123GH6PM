#include "LED.h"
#include "GPIO.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

void GPIO_setLedValue (unsigned char ledColor,unsigned char ledState) {
    switch (ledColor) {

       case GPIO_RED_LED:

           switch (ledState){
               case GPIO_LED_OFF: CLR_BIT(GPIO_PORTF_DATA_R,1); break;
			   case GPIO_LED_ON: SET_BIT(GPIO_PORTF_DATA_R,1); break;
			   default: break;
               }
               break;

     case GPIO_BLUE_LED: switch(ledState)

			{case GPIO_LED_OFF: CLR_BIT(GPIO_PORTF_DATA_R,2); break; 
				case GPIO_LED_ON: SET_BIT(GPIO_PORTF_DATA_R,2); break;
				default: break;
       } break;

			case GPIO_GREEN_LED: switch(ledState)

			{case GPIO_LED_OFF: CLR_BIT(GPIO_PORTF_DATA_R,3); break; 
			case GPIO_LED_ON: SET_BIT(GPIO_PORTF_DATA_R,3); break; 
			default: break;
		} break;

default: break;
	}
}
