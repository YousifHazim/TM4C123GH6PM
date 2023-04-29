

/**
 * main.c
 */

#include "GPIO.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

int main(void)
{

    GPIO_STRUCT gpio = {
        .Port = GPIO_PortA ,
        .AFSEL = GPIO_nonAFSEL,
        .Res = GPIO_PullUp,
        .Current = GPIO_Current_2MA,
        .Den  = GPIO_okDEN,
        .Amsel = GPIO_nonAMSEL
    };

    GPIO_InitPort(&gpio);

     GPIO_SetPortDirection(GPIO_PortA , GPIO_u8_PortOutput);
     GPIO_SetPinDirection( GPIO_PortA , GPIO_Pin7 , GPIO_u8_PinOutput );
     GPIO_SetPinValue( GPIO_PortA , GPIO_Pin7 , GPIO_u8_PinHigh);



	return 0;
}
