/*
 * GPIO.h
 *
 *  Created on: Apr 19, 2023
 *      Author: AL-NABAA
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"

typedef enum{
    GPIO_enuOK ,
    GPIO_Incorrect,
}GPIO_ErrorStatus;


#define GPIO_Speed GPIO_LowSpeed

#define GPIO_LowSpeed       0 // APB
#define GPIO_HighSpeed      1 // AHB

typedef enum {
    GPIO_PortA ,
    GPIO_PortB ,
    GPIO_PortC ,
    GPIO_PortD ,
    GPIO_PortE ,
    GPIO_PortF ,
}GPIO_Ports;


typedef enum{
    GPIO_nonAFSEL ,
    GPIO_okAFSEL ,
}GPIO_AFSEL;


typedef enum {
    GPIO_Current_2MA ,
    GPIO_Current_4MA ,
    GPIO_Current_8MA ,
}GPIO_Current;

typedef enum {
    GPIO_OpenDrain ,
    GPIO_PullUp ,
    GPIO_PullDown ,
}GPIO_Res;

typedef enum{
    GPIO_nonDEN ,
    GPIO_okDEN ,
}GPIO_Den;

typedef enum{
    GPIO_nonAMSEL ,
    GPIO_okAMSEL ,
}GPIO_AMSEl;

typedef enum {
    GPIO_Pin0,
    GPIO_Pin1,
    GPIO_Pin2,
    GPIO_Pin3,
    GPIO_Pin4,
    GPIO_Pin5,
    GPIO_Pin6,
    GPIO_Pin7,
}GPIO_Pins;

typedef enum{
    GPIO_u8_PortInput ,
    GPIO_u8_PortOutput = 255,
}GPIO_PortDir;

typedef enum {
    GPIO_u8_PinInput,
    GPIO_u8_PinOutput,
}GPIO_PinDir;

typedef enum {
    GPIO_u8_PinLow,
    GPIO_u8_PinHigh,
}GPIO_PinVal;

typedef struct{
    GPIO_Ports   Port;
    GPIO_AFSEL   AFSEL;
    GPIO_Res     Res;
    GPIO_Current Current;
    GPIO_Den     Den;
    GPIO_AMSEl   Amsel;
}GPIO_STRUCT;

void GPIO_InitPort(GPIO_STRUCT * Add_ptrPointerGPIO);

GPIO_ErrorStatus GPIO_SetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PortDir);
GPIO_ErrorStatus GPIO_SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortVal);
GPIO_ErrorStatus GPIO_SetPinDirection( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir );
GPIO_ErrorStatus GPIO_SetPinValue( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal);
u8 GPIO_GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);




#endif /* GPIO_H_ */
