
#include "SYSTICK.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

void SYSTICK_Init(void){

    CLR_REG(NVIC_ST_CTRL_R); // disable SYSTICK Timer
    NVIC_ST_RELOAD_R = oneMS;  // set reload to maximum reload value
    CLR_REG(NVIC_ST_CURRENT_R); // Clear Counter
    SET_BIT(NVIC_ST_CTRL_R , ClockSourse_Enable); // enable SYSTICK Timer

}

void SYSTICK_delay(u32 counts){

    CLR_REG(NVIC_ST_CTRL_R); // disable SYSTICK Timer
    NVIC_ST_RELOAD_R = counts;  // set reload to maximum reload value
    CLR_REG(NVIC_ST_CURRENT_R); // Clear Counter
    SET_BIT(NVIC_ST_CTRL_R , ClockSourse_Enable); // enable SYSTICK Timer

    while(NVIC_ST_CTRL_R & 0x10000 == 0); // counterFlage

}

void SYSTICK_doubleDelay(int doubleDelay , u32 counts){

    int i;

    for( i = 0 ; i < doubleDelay ; i++){

        void SYSTICK_delay(u32 counts); // if doubleDelay = 10 then it will be 10 MS

    }
}
