#include "GPIO.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

int main(void)

{
	
	GPIO_initPortF();
	
	
	SET_BIT(GPIO_PORTF_DATA_R,1); // LED 1 in PORT F ON
	SET_BIT(GPIO_PORTF_DATA_R,2); // LED 2 in PORT F ON
	
	return 0;
}
