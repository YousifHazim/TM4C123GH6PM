/***************************/
/*  Author  : Yousif Hazim */
/*  Date    : 5 AUG 2023  */
/***************************/

#include <stdlib.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "BIT_UTILIES.h"

        /* LED in PORTF Functions */
void initLED()
{
    // Enable clock for Port F
    SYSCTL_RCGCGPIO_R |= (1 << 5);
    SYSCTL_GPIOHBCTL_R |= (1 << 5);

    // Set LED pins as outputs (Port F)
    GPIO_PORTF_AHB_DIR_R |= (1 << 1) | (1 << 2) | (1 << 3);
    GPIO_PORTF_AHB_DEN_R |= (1 << 1) | (1 << 2) | (1 << 3);
}

void turnOnLED(uint8_t led)
{
    // Turn on the specified LED (Port F)
    GPIO_PORTF_AHB_DATA_R |= (1 << led);
}

void turnOffLED(uint8_t led)
{
    // Turn off the specified LED (Port F)
    GPIO_PORTF_AHB_DATA_R &= ~(1 << led);
}

void turnOffLEDS(void)
{
    // Turn off the specified LED (Port F)
    GPIO_PORTF_AHB_DATA_R &= ~(0xE);
}

        /*  UART Functions */

char readChar(void)
{
    char c;
    while((UART0_FR_R & (1<<4)) != 0);
    c = UART0_DR_R;
    return c;
}

void printChar(char c)
{
    while((UART0_FR_R & (1<<5)) != 0);
    UART0_DR_R = c;
}

void printString(char *s)
{
    while (*s != NULL)
    {
        printChar(*(s++));
    }
}

int main(void)
{

    /*
     *          Confugure UART0 in PORT A
     *              Using PIN 0 and 1
    */

    /* Enable UART Module using the RCGCUART register */

    SET_BIT(SYSCTL_RCGCUART_R,0);

    /* Enable the clock to the appropriate GPIO Port A via the RCGCGPIO register */

    SET_BIT(SYSCTL_RCGCGPIO_R,0);

    /* Set the GPIO Port A AFSEL For Pin 0 and 1 */

    GPIO_PORTA_AFSEL_R |= 0x3;

    /* Configure the PMCn fields in the GPIOA PCTL register to assign the UART signals */

    GPIO_PORTA_PCTL_R |= 0x11;

    /* Enable DEN in GPIOA Pins 0 & 1 */

    GPIO_PORTA_DEN_R |= 0x3;

    /* Disable the UART */

    CLR_REG(UART0_CTL_R);

    /*
     * Find The Baud-Rate Divisor
     * BRD = 16,000,000 / (16 * 9600) = 104.1666
     * UARTFBRD = integer(0.1666 * 64 + 0.5) = 11
     */

    /* Set IBRD & FBRD registers */

    UART0_IBRD_R = 104;

    UART0_FBRD_R = 11;

    /* 8-bit data , no parity , 1-stop bit */

    UART0_LCRH_R = (0x3 << 5);

    /* Using System clock (based on clock source and divisor factor) */

    CLR_REG(UART0_CC_R);

    /* Enable the UART & RX & TX */

    UART0_CTL_R = (1<<0) | (1<<8) | (1<<9);

    initLED();

    while(1)
    {

        printString("Char R for Red Light , G for Green Light and B for Blue Light \n\r");

        char c;
        c = readChar();

        switch(c)
        {

        case 'r' :
            turnOnLED(1);
            break;

        case 'b' :
            turnOnLED(2);
            break;

        case 'g' :
            turnOnLED(3);
            break;

        default :
            turnOffLEDS();
        }
    }

}
