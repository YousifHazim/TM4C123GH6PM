#include "DIO.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

void GPIO_initPortA(){

SET_BIT(SYSCTL_RCGCGPIO_R,0); // BIT 0

while(GET_BIT(SYSCTL_PRGPIO_R,0)== 0);

GPIO_PORTA_LOCK_R= GPIO_LOCK_KEY;

GPIO_PORTA_CR_R |= 0xFF;

GPIO_PORTA_AMSEL_R &= 0x0; // Disable Analog

GPIO_PORTA_DIR_R |= 0x00; // PA Input

GPIO_PORTA_DEN_R |= 0xFF; // Enable digital

}

void GPIO_initPortB(){

SET_BIT(SYSCTL_RCGCGPIO_R,1); // BIT 1

while(GET_BIT(SYSCTL_PRGPIO_R,1)== 0);

GPIO_PORTB_LOCK_R= GPIO_LOCK_KEY;

GPIO_PORTB_CR_R |= 0xFF;

GPIO_PORTB_AMSEL_R &= 0x0; // Disable Analog

GPIO_PORTB_DIR_R |= 0xFF; // PB OutPut

GPIO_PORTB_DEN_R |= 0xFF; // Enable digital

}

void GPIO_initPortC(){

SET_BIT(SYSCTL_RCGCGPIO_R,2); // BIT 2

while(GET_BIT(SYSCTL_PRGPIO_R,2)== 0);

GPIO_PORTC_LOCK_R= GPIO_LOCK_KEY;

GPIO_PORTC_CR_R |= 0xFF;

GPIO_PORTC_AMSEL_R &= 0x0; // Disable Analog

GPIO_PORTC_DIR_R |= 0xFF; // PC OutPut

GPIO_PORTC_DEN_R |= 0xFF; // Enable digital

}

void GPIO_initPortD(){

SET_BIT(SYSCTL_RCGCGPIO_R,3); // BIT 3

while(GET_BIT(SYSCTL_PRGPIO_R,3)== 0);

GPIO_PORTD_LOCK_R= GPIO_LOCK_KEY;

GPIO_PORTD_CR_R |= 0xFF;

GPIO_PORTD_AMSEL_R &= 0x0; // Disable Analog

GPIO_PORTD_DIR_R |= 0xFF; // PD OutPut

GPIO_PORTD_DEN_R |= 0xFF; // Enable digital

}

void GPIO_initPortE(){

SET_BIT(SYSCTL_RCGCGPIO_R,4); // BIT 4

while(GET_BIT(SYSCTL_PRGPIO_R,4)== 0);

GPIO_PORTE_LOCK_R= GPIO_LOCK_KEY;

GPIO_PORTE_CR_R |= 0x3F;

GPIO_PORTE_AMSEL_R &= 0x0; // Disable Analog

GPIO_PORTE_DIR_R |= 0x3F; // PE OutPut

GPIO_PORTE_DEN_R |= 0xFF; // Enable digital

}

void GPIO_initPortF(){

SET_BIT(SYSCTL_RCGCGPIO_R,5); // BIT 5

while(GET_BIT(SYSCTL_PRGPIO_R,5)== 0);

GPIO_PORTF_LOCK_R= GPIO_LOCK_KEY;

GPIO_PORTF_PUR_R |= 0x11; // PullUp

GPIO_PORTF_CR_R |= 0x1F;

GPIO_PORTF_AMSEL_R &= 0x0; // Disable Analog

GPIO_PORTF_DIR_R |= 0x0E; // PF OutPut PF1 ~ PF3 & PF Input PF0 - PF4

GPIO_PORTF_DEN_R|=0x1F;

}

