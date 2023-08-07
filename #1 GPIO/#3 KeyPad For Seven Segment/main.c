#include <stdint.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"

void seven_seg_display(uint8_t data) {
  // Seven-segment LED segment map
  const uint8_t seg_map[] = { 0x3F,  // 0
                              0x06,  // 1
                              0x5B,  // 2
                              0x4F,  // 3
                              0x66,  // 4
                              0x6D,  // 5
                              0x7D,  // 6
                              0x07,  // 7
                              0x7F,  // 8
                              0x6F,  // 9
                            };

  GPIO_PORTB_DATA_R = seg_map[data];  // Display the data on seven-segment LED
}

int main()
{

    // Set Port B as output for seven-segment LED
    SYSCTL_RCGCGPIO_R |= 0x02;  // Enable Port B clock
    GPIO_PORTB_DIR_R |= 0xFF;  // Set PB0 - PB7 as output
    GPIO_PORTB_DEN_R |= 0xFF;  // Enable digital function for PB0 - PB7

    /* init keypad & led */
    initKeypad();
    initLED();


    while (1)
    {
        /* get char fron keypad */
        char key = KeyPad_Read();

        uint8_t data;
        if (key != '\0') // if key is pressed
        {

            switch (key)
            {
            case '0':
            data = 0; break;
            case '1':
            data = 1; break;
            case '2':
            data = 2; break;
            case '3':
            data = 3; break;
            case '4':
            data = 4; break;
            case '5':
            data = 5; break;
            case '6':
            data = 6; break;
            case '7':
            data = 7; break;
            case '8':
            data = 8; break;
            case '9':
            data = 9; break;
            default:
            data = 0; break;
            }
        }

        seven_seg_display(data);

    }

    return 0;
}
