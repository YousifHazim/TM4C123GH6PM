#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"

void SysTickIntHandler(void);
int main(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Enable the GPIO for Port F

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // check if the peripheral is enable

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3); // Direction as output (PF3)

    SysTickPeriodSet(SysCtlClockGet()); // // Set reload value 1 sec

    SysTickIntRegister(SysTickIntHandler); // Define ISR for the Systick

    SysTickIntEnable(); // Systick Interrupt Enable

    IntMasterEnable(); // Enable Interrupt to the Processor

    SysTickEnable(); // Systick Enable

    while(1)
    {

    // Processor enters Sleep Mode to save Power instead of Looping
    // Once Interrupt happens, Processor goes directly into Run mode

      SysCtlSleep();

    }
}
void SysTickIntHandler(void)
{
    /*
     * The static keyword means that the variable
     * will retain its value between function calls,
     * so it can be used to store state information across interrupts.
     */

        static char PIN_3=0;

        PIN_3 ^=GPIO_PIN_3; // Toggle from 0 to 1

        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, PIN_3); // Toggle the green led
}
