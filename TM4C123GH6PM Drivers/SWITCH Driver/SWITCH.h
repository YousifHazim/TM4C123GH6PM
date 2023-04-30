
#ifndef SWITCH_H_
#define SWITCH_H_

#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

#define GPIO_SW1 0
#define GPIO_SW2 1

unsigned char GPIO_getSwitchesValue(unsigned char sw);

#endif /* SWITCH_H_ */
