/***************************/
/*  Author  : Yousif Hazim */
/*  Date    : 16 AUG 2023  */
/***************************/

#include <stdlib.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "BIT_UTILIES.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "uartstdio.h"

void initUART(void)
{

    // Set the system clock to 50MHz
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable UART0 and GPIOA
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Configure GPIO Pins for UART mode
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Initialize UART
    UARTStdioConfig(0, 115200, SysCtlClockGet());
}

int main(void){

    initUART();

    while (1)
    {
        UARTprintf("Print On Console \n\r");
    }
    return 0;
}
