#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

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
