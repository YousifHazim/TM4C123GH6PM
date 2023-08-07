#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "BIT_UTILIES.h"


#define KEYPAD_ROWS     4
#define KEYPAD_COLUMNS  4

// Define the mapping of keys to their corresponding row and column pins
char keypadKeys[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', 'X'},
    {'&', '0', '=', '/'}
};

void initKeypad()
{
    // Enable clock for Port B and Port A
    SYSCTL_RCGCGPIO_R |= (1 << 2) | (1 << 4);
    SYSCTL_GPIOHBCTL_R |= (1 << 2) | (1 << 4);

    // Set keypad rows as outputs (Port B)
    GPIO_PORTE_AHB_DIR_R |= 0x0F;
    GPIO_PORTE_AHB_DEN_R |= 0x0F;

    // Set keypad columns as inputs with pull-up resistors (Port A)
    GPIO_PORTC_AHB_DIR_R &= ~0xF0;
    GPIO_PORTC_AHB_PUR_R |= 0xF0;
    GPIO_PORTC_AHB_DEN_R |= 0xF0;
}

unsigned char KeyPad_Read(void)
{
    uint8_t row, col;

    for (row = 0; row < KEYPAD_ROWS; ++row)
    {
        // Drive current row low
        GPIO_PORTE_AHB_DATA_R = (~(1 << row)) & 0x0F;

        // Read the columns
        for (col = 0; col < KEYPAD_COLUMNS; ++col)
        {
            if (!(GPIO_PORTC_AHB_DATA_R & (1 << (col + 4))))
            {
                // A button was pressed
                return keypadKeys[row][col];
            }
        }
    }

    // No button pressed
    return '\0';
}


void delay()
{
   int c;

   for (c = 1; c <= 1000000; c++);

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

int flag = 0;

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

    initKeypad();

    while(1)
    {

        if(flag == 0)
        {
            delay();
            printString("Enter The First Number : \n\r");
            flag++;


        }

        char num1;
        if(flag == 1){
            num1 =  KeyPad_Read();
            if (num1 != '\0') // if key is pressed
            {
                printString(&num1);
                delay();
                printString("\n\r");
                delay();
                flag++;
            }
        }

        if(flag == 2)
        {
            printString("Enter The Second Number : \n\r");
            flag++;
        }

        char num2;
        if(flag == 3){
            num2 =  KeyPad_Read();
            if (num2 != '\0') // if key is pressed
            {
               printString(&num2);
               delay();
                printString("\n\r");
               delay();
               flag++;
            }
        }

        if(flag == 4)
        {
            printString("Enter The Operation : \n\r");
            flag++;
        }

        char op;
        if(flag == 5){
            op =  KeyPad_Read();
            if (op != '\0') // if key is pressed
            {
               printString(&op);
               delay();
                printString("\n\r");
               delay();
               flag++;
            }
        }

        if(flag == 6)
        {
            printString("The Result : \n\r");

            switch(op)
            {
            case '+':
            {
            int res = 0;
            res =  num1+num2;
            res -= 48;
            printString(&res);
            printString("\n\r");
            flag++;
            }break;

            case'-':
            {
            int res = 0;
            res =  num1-num2;
            res -= 48;
            printString(&res);
            printString("\n\r");
            flag++;
            }break;

            }

        }


    }

}

