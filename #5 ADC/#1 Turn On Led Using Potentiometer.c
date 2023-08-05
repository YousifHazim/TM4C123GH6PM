/***************************/
/*  Author  : Yousif Hazim */
/*  Date    : 5 AUG 2023  */
/***************************/

#include <stdlib.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "BIT_UTILIES.h"

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


void main(void)
{
    /* Enable and provide a clock to ADC module 0 in Run mode */

    SET_BIT(SYSCTL_RCGCADC_R,0);

    /* Enable the clock to the appropriate GPIO modules */

    SET_BIT(SYSCTL_RCGCGPIO_R,4);

    /* Set the GPIO AFSEL bits for the ADC input pins */

    GPIO_PORTE_AFSEL_R |= 0x08;

    /* Configure the AINx signals to be analog inputs */

    GPIO_PORTE_DEN_R &= ~0x08;

    /* Disable the analog isolation circuit for all ADC input pins */

    GPIO_PORTE_AMSEL_R |= 0x08;

    /*
     * Sample Sequencer Configuration
    */

    /* Ensure that the sample sequencer is disabled */

    CLR_BIT(ADC0_ACTSS_R,3);

    /* Configure the trigger event for the sample sequencer */

    ADC0_EMUX_R &= ~(0xF << 12);

    /* configure the corresponding input source */

    ADC0_SSMUX3_R = 2;

    /* configure the sample control bits */

    ADC0_SSCTL3_R |= 6;

    /* Enable the sample sequencer logic */

    SET_BIT(ADC0_ACTSS_R,3);

    initLED();

    while(1)
    {
        // Start ADC conversion
       ADC0_PSSI_R = 0x08;

      // Wait for conversion to complete
       while (!(ADC0_RIS_R & 0x08)) {}


       uint32_t adcResult = ADC0_SSFIFO3_R & 0xFFF; // MASK

        if(adcResult>2048)
        {
            turnOnLED(1); // TURN ON RED
        }else
        {
            turnOffLED(1); // TURN OFF RED
        }
    }

}


