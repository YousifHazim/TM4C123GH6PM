#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"

int main(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Enable the GPIO Port

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}; // Check if the peripheral is enable

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3); // Set the direction as output

    SysTickPeriodSet(0xFFFFFF); // Set reload value

    SysTickEnable(); // Systick Enable

    while(1)
    {

        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3); // Turn On Led
        while (SysTickValueGet()<0xFFFFF0);

        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0); // Turn Off Led
        while (SysTickValueGet()<0xFFFFF0);
    }
}
