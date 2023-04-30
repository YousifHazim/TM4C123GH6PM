
#include "SWITCH.h"
#include "GPIO.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

unsigned char GPIO_getSwitchesValue(unsigned char sw){

switch (sw){

    case GPIO_SW1 :return GET_BIT(GPIO_PORTF_DATA_R,4); break;

    case GPIO_SW2 :return GET_BIT(GPIO_PORTF_DATA_R,0); break;

    default : return 0;

   }

}
