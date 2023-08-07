#include <stdint.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"

int main()
{
    /* init keypad & led */
    initKeypad();
    initLED();


    while (1)
    {
        /* get char fron keypad */
        char key = KeyPad_Read();

        if (key != '\0') // if key is pressed
        {

            switch (key)
            {
                case '1':
                    turnOnLED(1); // turn on RED
                    break;
                case '2':
                    turnOnLED(2); // turn on blue
                    break;
                case '3':
                    turnOnLED(3); // turn on green
                    break;
                default:
                    turnOffLEDS();
                    break;
            }
        }
    }

    return 0;
}

