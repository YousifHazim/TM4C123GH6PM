#include "GPIO.h"
#include "SYSTICK.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

int main(void)
{

    if(NVIC_ST_CTRL_R & 0x10000){ // counterFlage = 1

        // do something

    }

	return 0;
}
