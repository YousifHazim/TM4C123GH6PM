#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#define LED_RED     (1U << 1)   // Port F Pin 1

void configureTimer(void);
void configureGPIO(void);

int main(void) {
    configureTimer();
    configureGPIO();

    while(1) {
           // Toggle the LED state
    }
}

void Timer0A_Handler(void)
{
    // Your interrupt handler code here
    GPIO_PORTF_DATA_R ^= LED_RED;
    // Clear the interrupt flag
    TIMER0_ICR_R |= 0x01;
}

void configureTimer(void) {
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;    // Enable clock for Timer 0
        TIMER0_CTL_R &= ~TIMER_CTL_TAEN;              // Disable Timer 0A during setup
        TIMER0_CFG_R = TIMER_CFG_32_BIT_TIMER;        // Set timer to 32-bit mode
        TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD;       // Configure Timer 0A as periodic mode

        // Set desired frequency
        TIMER0_TAILR_R = 16000000 - 1;                // 16,000,000 cycles per second / 16000000 = 1Hz

        TIMER0_IMR_R |= 0x01; // Enable Timer 0A timeout interrupt

        NVIC_PRI4_R = (NVIC_PRI4_R & 0xFFFF00FF) | 0x00008000; // Set the interrupt priority (adjust as needed)

        NVIC_EN0_R |= 1 << 19; // Enable interrupt 19 (corresponding to Timer 0A) in NVIC

        TIMER0_CTL_R |= 0x01; // Enable Timer 0
}

void configureGPIO(void) {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;       // Enable clock for Port F
    GPIO_PORTF_DIR_R |= LED_RED;                   // Set Pin 1 as output
    GPIO_PORTF_DEN_R |= LED_RED;                   // Enable digital function for Pin 1
}

