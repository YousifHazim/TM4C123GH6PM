#include "inc/tm4c123gh6pm.h"
#include <stdint.h>

int main() {

    /* Configure SysTick */
  
    NVIC_ST_CTRL_R = 0;             // Disable SysTick during configuration
  
    NVIC_ST_RELOAD_R = 0x00FFFFFF;  // set reload to maximum reload value

    NVIC_ST_CURRENT_R = 0;          // Clear current value
  
    NVIC_ST_RELOAD_R = 16000000-1;  // Set reload value to generate 1 second delay
  
    NVIC_ST_CTRL_R = 5;             // Enable SysTick with system clock

    while (1) {

    while ((NVIC_ST_CTRL_R & 0x10000) == 0);         /* Reading COUNT FLAG will reset it back */

    }
  
    return 0;
}
