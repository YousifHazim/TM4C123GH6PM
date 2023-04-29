#include "GPIO.h"
#include "STD_TYPES.h"
#include "BIT_UTILIES.h"
#include "TM4C123.h"



void GPIO_InitPort(GPIO_STRUCT * Add_ptrPointerGPIO){


    /* GPIO APB Mode */
    if(GPIO_Speed == GPIO_LowSpeed){

               /* GPIO Port Select */
               switch(Add_ptrPointerGPIO -> Port){
                   case GPIO_PortA : {
                       SET_BIT(SYSCTL_RCGCGPIO_R,0);
                       while(GET_BIT(SYSCTL_PRGPIO_R,0) == 0);

                       GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                       SET_REG(GPIO_PORTA_CR_R); // Allow Changes

                       /* GPIO AFSEL Mode */
                       switch(Add_ptrPointerGPIO -> AFSEL){
                       case GPIO_nonAFSEL : CLR_REG(GPIO_PORTA_AFSEL_R);break;
                       case GPIO_okAFSEL : SET_REG(GPIO_PORTA_AFSEL_R);break;
                       }

                       /* GPIO Current Mode */
                       switch(Add_ptrPointerGPIO -> Current){
                       case GPIO_Current_2MA :SET_REG(GPIO_PORTA_DR2R_R);CLR_REG(GPIO_PORTA_DR4R_R);CLR_REG(GPIO_PORTA_DR8R_R);break;
                       case GPIO_Current_4MA :SET_REG(GPIO_PORTA_DR4R_R);CLR_REG(GPIO_PORTA_DR2R_R);CLR_REG(GPIO_PORTA_DR8R_R);break;
                       case GPIO_Current_8MA :SET_REG(GPIO_PORTA_DR8R_R);CLR_REG(GPIO_PORTA_DR4R_R);CLR_REG(GPIO_PORTA_DR2R_R);break;
                       }

                       /* GPIO Resistance Mode */
                       switch(Add_ptrPointerGPIO -> Res){
                       case GPIO_OpenDrain : SET_REG(GPIO_PORTA_ODR_R);CLR_REG(GPIO_PORTA_PUR_R);CLR_REG(GPIO_PORTA_PDR_R);break;
                       case GPIO_PullUp : SET_REG(GPIO_PORTA_PUR_R);CLR_REG(GPIO_PORTA_ODR_R);CLR_REG(GPIO_PORTA_PDR_R);break;
                       case GPIO_PullDown : SET_REG(GPIO_PORTA_PDR_R);CLR_REG(GPIO_PORTA_PUR_R);CLR_REG(GPIO_PORTA_ODR_R);break;
                       }

                       /* GPIO Digital Enable */
                       switch(Add_ptrPointerGPIO -> Den){
                       case GPIO_nonDEN : CLR_REG(GPIO_PORTA_DEN_R);break;
                       case GPIO_okDEN : SET_REG(GPIO_PORTA_DEN_R);break;
                       }

                       /* GPIO Analog mode select */
                       switch(Add_ptrPointerGPIO -> Amsel){
                       case GPIO_nonAMSEL : CLR_REG(GPIO_PORTA_AMSEL_R);break;
                       case GPIO_okAMSEL : SET_REG(GPIO_PORTA_AMSEL_R);break;
                       }

                   }

                   case GPIO_PortB : {
                       SET_BIT(SYSCTL_RCGCGPIO_R,1);
                       while(GET_BIT(SYSCTL_PRGPIO_R,1) == 0);

                       GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                       SET_REG(GPIO_PORTB_CR_R); // Allow Changes

                       /* GPIO AFSEL Mode */
                       switch(Add_ptrPointerGPIO -> AFSEL){
                       case GPIO_nonAFSEL : CLR_REG(GPIO_PORTB_AFSEL_R);break;
                       case GPIO_okAFSEL : SET_REG(GPIO_PORTB_AFSEL_R);break;
                       }

                       /* GPIO Current Mode */
                       switch(Add_ptrPointerGPIO -> Current){
                       case GPIO_Current_2MA :SET_REG(GPIO_PORTB_DR2R_R);CLR_REG(GPIO_PORTB_DR4R_R);CLR_REG(GPIO_PORTB_DR8R_R);break;
                       case GPIO_Current_4MA :SET_REG(GPIO_PORTB_DR4R_R);CLR_REG(GPIO_PORTB_DR2R_R);CLR_REG(GPIO_PORTB_DR8R_R);break;
                       case GPIO_Current_8MA :SET_REG(GPIO_PORTB_DR8R_R);CLR_REG(GPIO_PORTB_DR4R_R);CLR_REG(GPIO_PORTB_DR2R_R);break;
                       }

                       /* GPIO Resistance Mode */
                       switch(Add_ptrPointerGPIO -> Res){
                       case GPIO_OpenDrain : SET_REG(GPIO_PORTB_ODR_R);CLR_REG(GPIO_PORTB_PUR_R);CLR_REG(GPIO_PORTB_PDR_R);break;
                       case GPIO_PullUp : SET_REG(GPIO_PORTB_PUR_R);CLR_REG(GPIO_PORTB_ODR_R);CLR_REG(GPIO_PORTB_PDR_R);break;
                       case GPIO_PullDown : SET_REG(GPIO_PORTB_PDR_R);CLR_REG(GPIO_PORTB_PUR_R);CLR_REG(GPIO_PORTB_ODR_R);break;
                       }

                       /* GPIO Digital Enable */
                       switch(Add_ptrPointerGPIO -> Den){
                       case GPIO_nonDEN : CLR_REG(GPIO_PORTB_DEN_R);break;
                       case GPIO_okDEN : SET_REG(GPIO_PORTB_DEN_R);break;
                       }

                       /* GPIO Analog mode select */
                       switch(Add_ptrPointerGPIO -> Amsel){
                       case GPIO_nonAMSEL : CLR_REG(GPIO_PORTB_AMSEL_R);break;
                       case GPIO_okAMSEL : SET_REG(GPIO_PORTB_AMSEL_R);break;
                       }
                   }

                   case GPIO_PortC : {
                       SET_BIT(SYSCTL_RCGCGPIO_R,2);
                       while(GET_BIT(SYSCTL_PRGPIO_R,2) == 0);

                       GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                       SET_REG(GPIO_PORTC_CR_R); // Allow Changes

                       /* GPIO AFSEL Mode */
                       switch(Add_ptrPointerGPIO -> AFSEL){
                       case GPIO_nonAFSEL : CLR_REG(GPIO_PORTC_AFSEL_R);break;
                       case GPIO_okAFSEL : SET_REG(GPIO_PORTC_AFSEL_R);break;
                       }

                       /* GPIO Current Mode */
                       switch(Add_ptrPointerGPIO -> Current){
                       case GPIO_Current_2MA :SET_REG(GPIO_PORTC_DR2R_R);CLR_REG(GPIO_PORTC_DR4R_R);CLR_REG(GPIO_PORTC_DR8R_R);break;
                       case GPIO_Current_4MA :SET_REG(GPIO_PORTC_DR4R_R);CLR_REG(GPIO_PORTC_DR2R_R);CLR_REG(GPIO_PORTC_DR8R_R);break;
                       case GPIO_Current_8MA :SET_REG(GPIO_PORTC_DR8R_R);CLR_REG(GPIO_PORTC_DR4R_R);CLR_REG(GPIO_PORTC_DR2R_R);break;
                       }

                       /* GPIO Resistance Mode */
                       switch(Add_ptrPointerGPIO -> Res){
                       case GPIO_OpenDrain : SET_REG(GPIO_PORTC_ODR_R);CLR_REG(GPIO_PORTC_PUR_R);CLR_REG(GPIO_PORTC_PDR_R);break;
                       case GPIO_PullUp : SET_REG(GPIO_PORTC_PUR_R);CLR_REG(GPIO_PORTC_ODR_R);CLR_REG(GPIO_PORTC_PDR_R);break;
                       case GPIO_PullDown : SET_REG(GPIO_PORTC_PDR_R);CLR_REG(GPIO_PORTC_PUR_R);CLR_REG(GPIO_PORTC_ODR_R);break;
                       }

                       /* GPIO Digital Enable */
                       switch(Add_ptrPointerGPIO -> Den){
                       case GPIO_nonDEN : CLR_REG(GPIO_PORTC_DEN_R);break;
                       case GPIO_okDEN : SET_REG(GPIO_PORTC_DEN_R);break;
                       }

                       /* GPIO Analog mode select */
                       switch(Add_ptrPointerGPIO -> Amsel){
                       case GPIO_nonAMSEL : CLR_REG(GPIO_PORTC_AMSEL_R);break;
                       case GPIO_okAMSEL : SET_REG(GPIO_PORTC_AMSEL_R);break;
                       }
                   }

                   case GPIO_PortD : {
                       SET_BIT(SYSCTL_RCGCGPIO_R,3);
                       while(GET_BIT(SYSCTL_PRGPIO_R,3) == 0);

                       GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                       SET_REG(GPIO_PORTD_CR_R); // Allow Changes

                       /* GPIO AFSEL Mode */
                       switch(Add_ptrPointerGPIO -> AFSEL){
                       case GPIO_nonAFSEL : CLR_REG(GPIO_PORTD_AFSEL_R);break;
                       case GPIO_okAFSEL : SET_REG(GPIO_PORTD_AFSEL_R);break;
                       }

                       /* GPIO Current Mode */
                       switch(Add_ptrPointerGPIO -> Current){
                       case GPIO_Current_2MA :SET_REG(GPIO_PORTD_DR2R_R);CLR_REG(GPIO_PORTD_DR4R_R);CLR_REG(GPIO_PORTD_DR8R_R);break;
                       case GPIO_Current_4MA :SET_REG(GPIO_PORTD_DR4R_R);CLR_REG(GPIO_PORTD_DR2R_R);CLR_REG(GPIO_PORTD_DR8R_R);break;
                       case GPIO_Current_8MA :SET_REG(GPIO_PORTD_DR8R_R);CLR_REG(GPIO_PORTD_DR4R_R);CLR_REG(GPIO_PORTD_DR2R_R);break;
                       }

                       /* GPIO Resistance Mode */
                       switch(Add_ptrPointerGPIO -> Res){
                       case GPIO_OpenDrain : SET_REG(GPIO_PORTD_ODR_R);CLR_REG(GPIO_PORTD_PUR_R);CLR_REG(GPIO_PORTD_PDR_R);break;
                       case GPIO_PullUp : SET_REG(GPIO_PORTD_PUR_R);CLR_REG(GPIO_PORTD_ODR_R);CLR_REG(GPIO_PORTD_PDR_R);break;
                       case GPIO_PullDown : SET_REG(GPIO_PORTD_PDR_R);CLR_REG(GPIO_PORTD_PUR_R);CLR_REG(GPIO_PORTD_ODR_R);break;
                       }

                       /* GPIO Digital Enable */
                       switch(Add_ptrPointerGPIO -> Den){
                       case GPIO_nonDEN : CLR_REG(GPIO_PORTD_DEN_R);break;
                       case GPIO_okDEN : SET_REG(GPIO_PORTD_DEN_R);break;
                       }


                       /* GPIO Analog mode select */
                       switch(Add_ptrPointerGPIO -> Amsel){
                       case GPIO_nonAMSEL : CLR_REG(GPIO_PORTD_AMSEL_R);break;
                       case GPIO_okAMSEL : SET_REG(GPIO_PORTD_AMSEL_R);break;
                       }
                   }

                   case GPIO_PortE : {
                       SET_BIT(SYSCTL_RCGCGPIO_R,4);
                       while(GET_BIT(SYSCTL_PRGPIO_R,4) == 0);

                       GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                       SET_REG(GPIO_PORTE_CR_R);

                       /* GPIO AFSEL Mode */
                       switch(Add_ptrPointerGPIO -> AFSEL){
                       case GPIO_nonAFSEL : CLR_REG(GPIO_PORTE_AFSEL_R);break;
                       case GPIO_okAFSEL : SET_REG(GPIO_PORTE_AFSEL_R);break;
                       }

                       /* GPIO Current Mode */
                       switch(Add_ptrPointerGPIO -> Current){
                       case GPIO_Current_2MA :SET_REG(GPIO_PORTE_DR2R_R);CLR_REG(GPIO_PORTE_DR4R_R);CLR_REG(GPIO_PORTE_DR8R_R);break;
                       case GPIO_Current_4MA :SET_REG(GPIO_PORTE_DR4R_R);CLR_REG(GPIO_PORTE_DR2R_R);CLR_REG(GPIO_PORTE_DR8R_R);break;
                       case GPIO_Current_8MA :SET_REG(GPIO_PORTE_DR8R_R);CLR_REG(GPIO_PORTE_DR4R_R);CLR_REG(GPIO_PORTE_DR2R_R);break;
                       }

                       /* GPIO Resistance Mode */
                       switch(Add_ptrPointerGPIO -> Res){
                       case GPIO_OpenDrain : SET_REG(GPIO_PORTE_ODR_R);CLR_REG(GPIO_PORTE_PUR_R);CLR_REG(GPIO_PORTE_PDR_R);break;
                       case GPIO_PullUp : SET_REG(GPIO_PORTE_PUR_R);CLR_REG(GPIO_PORTE_ODR_R);CLR_REG(GPIO_PORTE_PDR_R);break;
                       case GPIO_PullDown : SET_REG(GPIO_PORTE_PDR_R);CLR_REG(GPIO_PORTE_PUR_R);CLR_REG(GPIO_PORTE_ODR_R);break;
                       }

                       /* GPIO Digital Enable */
                       switch(Add_ptrPointerGPIO -> Den){
                       case GPIO_nonDEN : CLR_REG(GPIO_PORTE_DEN_R);break;
                       case GPIO_okDEN : SET_REG(GPIO_PORTE_DEN_R);break;
                       }


                       /* GPIO Analog mode select */
                       switch(Add_ptrPointerGPIO -> Amsel){
                       case GPIO_nonAMSEL : CLR_REG(GPIO_PORTE_AMSEL_R);break;
                       case GPIO_okAMSEL : SET_REG(GPIO_PORTE_AMSEL_R);break;
                       }
                   }

                   case GPIO_PortF : {
                       SET_BIT(SYSCTL_RCGCGPIO_R,5);
                       while(GET_BIT(SYSCTL_PRGPIO_R,5) == 0);

                       GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                       SET_REG(GPIO_PORTF_CR_R);

                       /* GPIO AFSEL Mode */
                       switch(Add_ptrPointerGPIO -> AFSEL){
                       case GPIO_nonAFSEL : CLR_REG(GPIO_PORTF_AFSEL_R);break;
                       case GPIO_okAFSEL : SET_REG(GPIO_PORTF_AFSEL_R);break;
                       }

                       /* GPIO Current Mode */
                       switch(Add_ptrPointerGPIO -> Current){
                       case GPIO_Current_2MA :SET_REG(GPIO_PORTF_DR2R_R);CLR_REG(GPIO_PORTF_DR4R_R);CLR_REG(GPIO_PORTF_DR8R_R);break;
                       case GPIO_Current_4MA :SET_REG(GPIO_PORTF_DR4R_R);CLR_REG(GPIO_PORTF_DR2R_R);CLR_REG(GPIO_PORTF_DR8R_R);break;
                       case GPIO_Current_8MA :SET_REG(GPIO_PORTF_DR8R_R);CLR_REG(GPIO_PORTF_DR4R_R);CLR_REG(GPIO_PORTF_DR2R_R);break;
                       }

                       /* GPIO Resistance Mode */
                       switch(Add_ptrPointerGPIO -> Res){
                       case GPIO_OpenDrain : SET_REG(GPIO_PORTF_ODR_R);CLR_REG(GPIO_PORTF_PUR_R);CLR_REG(GPIO_PORTF_PDR_R);break;
                       case GPIO_PullUp : SET_REG(GPIO_PORTF_PUR_R);CLR_REG(GPIO_PORTF_ODR_R);CLR_REG(GPIO_PORTF_PDR_R);break;
                       case GPIO_PullDown : SET_REG(GPIO_PORTF_PDR_R);CLR_REG(GPIO_PORTF_PUR_R);CLR_REG(GPIO_PORTF_ODR_R);break;
                       }

                       /* GPIO Digital Enable */
                       switch(Add_ptrPointerGPIO -> Den){
                       case GPIO_nonDEN : CLR_REG(GPIO_PORTF_DEN_R);break;
                       case GPIO_okDEN : SET_REG(GPIO_PORTF_DEN_R);break;
                       }


                       /* GPIO Analog mode select */
                       switch(Add_ptrPointerGPIO -> Amsel){
                       case GPIO_nonAMSEL : CLR_REG(GPIO_PORTF_AMSEL_R);break;
                       case GPIO_okAMSEL : SET_REG(GPIO_PORTF_AMSEL_R);break;
                       }
               }
           }
        }

            /* GPIO AHB Mode */
            else {

                       /* GPIO Port Select */
                      switch(Add_ptrPointerGPIO -> Port){
                          case GPIO_PortA : {
                              SET_BIT(SYSCTL_RCGCGPIO_R,0);
                              while(GET_BIT(SYSCTL_PRGPIO_R,0) == 0);

                              GPIO_PORTA_AHB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                              SET_REG(GPIO_PORTA_AHB_CR_R);

                              /* GPIO AFSEL Mode */
                              switch(Add_ptrPointerGPIO -> AFSEL){
                              case GPIO_nonAFSEL : CLR_REG(GPIO_PORTA_AHB_AFSEL_R);break;
                              case GPIO_okAFSEL : SET_REG(GPIO_PORTA_AHB_AFSEL_R);break;
                              }

                              /* GPIO Current Mode */
                              switch(Add_ptrPointerGPIO -> Current){
                              case GPIO_Current_2MA :SET_REG(GPIO_PORTA_AHB_DR2R_R);CLR_REG(GPIO_PORTA_AHB_DR4R_R);CLR_REG(GPIO_PORTA_AHB_DR8R_R);break;
                              case GPIO_Current_4MA :SET_REG(GPIO_PORTA_AHB_DR4R_R);CLR_REG(GPIO_PORTA_AHB_DR2R_R);CLR_REG(GPIO_PORTA_AHB_DR8R_R);break;
                              case GPIO_Current_8MA :SET_REG(GPIO_PORTA_AHB_DR8R_R);CLR_REG(GPIO_PORTA_AHB_DR4R_R);CLR_REG(GPIO_PORTA_AHB_DR2R_R);break;
                              }

                              /* GPIO Resistance Mode */
                              switch(Add_ptrPointerGPIO -> Res){
                              case GPIO_OpenDrain : SET_REG(GPIO_PORTA_AHB_ODR_R);CLR_REG(GPIO_PORTA_AHB_PUR_R);CLR_REG(GPIO_PORTA_AHB_PDR_R);break;
                              case GPIO_PullUp : SET_REG(GPIO_PORTA_AHB_PUR_R);CLR_REG(GPIO_PORTA_AHB_ODR_R);CLR_REG(GPIO_PORTA_AHB_PDR_R);break;
                              case GPIO_PullDown : SET_REG(GPIO_PORTA_AHB_PDR_R);CLR_REG(GPIO_PORTA_AHB_PUR_R);CLR_REG(GPIO_PORTA_AHB_ODR_R);break;
                              }

                              /* GPIO Digital Enable */
                              switch(Add_ptrPointerGPIO -> Den){
                              case GPIO_nonDEN : CLR_REG(GPIO_PORTA_AHB_DEN_R);break;
                              case GPIO_okDEN : SET_REG(GPIO_PORTA_AHB_DEN_R);break;
                              }

                              /* GPIO Analog mode select */
                              switch(Add_ptrPointerGPIO -> Amsel){
                              case GPIO_nonAMSEL : CLR_REG(GPIO_PORTA_AHB_AMSEL_R);break;
                              case GPIO_okAMSEL : SET_REG(GPIO_PORTA_AHB_AMSEL_R);break;
                              }

                          }

                          case GPIO_PortB : {
                              SET_BIT(SYSCTL_RCGCGPIO_R,1);
                              while(GET_BIT(SYSCTL_PRGPIO_R,1) == 0);

                              GPIO_PORTB_AHB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                              SET_REG(GPIO_PORTB_AHB_CR_R);

                              /* GPIO AFSEL Mode */
                              switch(Add_ptrPointerGPIO -> AFSEL){
                              case GPIO_nonAFSEL : CLR_REG(GPIO_PORTB_AHB_AFSEL_R);break;
                              case GPIO_okAFSEL : SET_REG(GPIO_PORTB_AHB_AFSEL_R);break;
                              }

                              /* GPIO Current Mode */
                              switch(Add_ptrPointerGPIO -> Current){
                              case GPIO_Current_2MA :SET_REG(GPIO_PORTB_AHB_DR2R_R);CLR_REG(GPIO_PORTB_AHB_DR4R_R);CLR_REG(GPIO_PORTB_AHB_DR8R_R);break;
                              case GPIO_Current_4MA :SET_REG(GPIO_PORTB_AHB_DR4R_R);CLR_REG(GPIO_PORTB_AHB_DR2R_R);CLR_REG(GPIO_PORTB_AHB_DR8R_R);break;
                              case GPIO_Current_8MA :SET_REG(GPIO_PORTB_AHB_DR8R_R);CLR_REG(GPIO_PORTB_AHB_DR4R_R);CLR_REG(GPIO_PORTB_AHB_DR2R_R);break;
                              }

                              /* GPIO Resistance Mode */
                              switch(Add_ptrPointerGPIO -> Res){
                              case GPIO_OpenDrain : SET_REG(GPIO_PORTB_AHB_ODR_R);CLR_REG(GPIO_PORTB_AHB_PUR_R);CLR_REG(GPIO_PORTB_AHB_PDR_R);break;
                              case GPIO_PullUp : SET_REG(GPIO_PORTB_AHB_PUR_R);CLR_REG(GPIO_PORTB_AHB_ODR_R);CLR_REG(GPIO_PORTB_AHB_PDR_R);break;
                              case GPIO_PullDown : SET_REG(GPIO_PORTB_AHB_PDR_R);CLR_REG(GPIO_PORTB_AHB_PUR_R);CLR_REG(GPIO_PORTB_AHB_ODR_R);break;
                              }

                              /* GPIO Digital Enable */
                              switch(Add_ptrPointerGPIO -> Den){
                              case GPIO_nonDEN : CLR_REG(GPIO_PORTB_AHB_DEN_R);break;
                              case GPIO_okDEN : SET_REG(GPIO_PORTB_AHB_DEN_R);break;
                              }

                              /* GPIO Analog mode select */
                              switch(Add_ptrPointerGPIO -> Amsel){
                              case GPIO_nonAMSEL : CLR_REG(GPIO_PORTB_AHB_AMSEL_R);break;
                              case GPIO_okAMSEL : SET_REG(GPIO_PORTB_AHB_AMSEL_R);break;
                              }
                          }

                          case GPIO_PortC : {
                              SET_BIT(SYSCTL_RCGCGPIO_R,2);
                              while(GET_BIT(SYSCTL_PRGPIO_R,2) == 0);

                              GPIO_PORTC_AHB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                              SET_REG(GPIO_PORTC_AHB_CR_R);

                              /* GPIO AFSEL Mode */
                              switch(Add_ptrPointerGPIO -> AFSEL){
                              case GPIO_nonAFSEL : CLR_REG(GPIO_PORTC_AHB_AFSEL_R);break;
                              case GPIO_okAFSEL : SET_REG(GPIO_PORTC_AHB_AFSEL_R);break;
                              }

                              /* GPIO Current Mode */
                              switch(Add_ptrPointerGPIO -> Current){
                              case GPIO_Current_2MA :SET_REG(GPIO_PORTC_AHB_DR2R_R);CLR_REG(GPIO_PORTC_AHB_DR4R_R);CLR_REG(GPIO_PORTC_AHB_DR8R_R);break;
                              case GPIO_Current_4MA :SET_REG(GPIO_PORTC_AHB_DR4R_R);CLR_REG(GPIO_PORTC_AHB_DR2R_R);CLR_REG(GPIO_PORTC_AHB_DR8R_R);break;
                              case GPIO_Current_8MA :SET_REG(GPIO_PORTC_AHB_DR8R_R);CLR_REG(GPIO_PORTC_AHB_DR4R_R);CLR_REG(GPIO_PORTC_AHB_DR2R_R);break;
                              }

                              /* GPIO Resistance Mode */
                              switch(Add_ptrPointerGPIO -> Res){
                              case GPIO_OpenDrain : SET_REG(GPIO_PORTC_AHB_ODR_R);CLR_REG(GPIO_PORTC_AHB_PUR_R);CLR_REG(GPIO_PORTC_AHB_PDR_R);break;
                              case GPIO_PullUp : SET_REG(GPIO_PORTC_AHB_PUR_R);CLR_REG(GPIO_PORTC_AHB_ODR_R);CLR_REG(GPIO_PORTC_AHB_PDR_R);break;
                              case GPIO_PullDown : SET_REG(GPIO_PORTC_AHB_PDR_R);CLR_REG(GPIO_PORTC_AHB_PUR_R);CLR_REG(GPIO_PORTC_AHB_ODR_R);break;
                              }

                              /* GPIO Digital Enable */
                              switch(Add_ptrPointerGPIO -> Den){
                              case GPIO_nonDEN : CLR_REG(GPIO_PORTC_AHB_DEN_R);break;
                              case GPIO_okDEN : SET_REG(GPIO_PORTC_AHB_DEN_R);break;
                              }

                              /* GPIO Analog mode select */
                              switch(Add_ptrPointerGPIO -> Amsel){
                              case GPIO_nonAMSEL : CLR_REG(GPIO_PORTC_AHB_AMSEL_R);break;
                              case GPIO_okAMSEL : SET_REG(GPIO_PORTC_AHB_AMSEL_R);break;
                              }
                          }

                          case GPIO_PortD : {
                              SET_BIT(SYSCTL_RCGCGPIO_R,3);
                              while(GET_BIT(SYSCTL_PRGPIO_R,3) == 0);

                              GPIO_PORTD_AHB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                              SET_REG(GPIO_PORTD_AHB_CR_R);

                              /* GPIO AFSEL Mode */
                              switch(Add_ptrPointerGPIO -> AFSEL){
                              case GPIO_nonAFSEL : CLR_REG(GPIO_PORTD_AHB_AFSEL_R);break;
                              case GPIO_okAFSEL : SET_REG(GPIO_PORTD_AHB_AFSEL_R);break;
                              }

                              /* GPIO Current Mode */
                              switch(Add_ptrPointerGPIO -> Current){
                              case GPIO_Current_2MA :SET_REG(GPIO_PORTD_AHB_DR2R_R);CLR_REG(GPIO_PORTD_AHB_DR4R_R);CLR_REG(GPIO_PORTD_AHB_DR8R_R);break;
                              case GPIO_Current_4MA :SET_REG(GPIO_PORTD_AHB_DR4R_R);CLR_REG(GPIO_PORTD_AHB_DR2R_R);CLR_REG(GPIO_PORTD_AHB_DR8R_R);break;
                              case GPIO_Current_8MA :SET_REG(GPIO_PORTD_AHB_DR8R_R);CLR_REG(GPIO_PORTD_AHB_DR4R_R);CLR_REG(GPIO_PORTD_AHB_DR2R_R);break;
                              }

                              /* GPIO Resistance Mode */
                              switch(Add_ptrPointerGPIO -> Res){
                              case GPIO_OpenDrain : SET_REG(GPIO_PORTD_AHB_ODR_R);CLR_REG(GPIO_PORTD_AHB_PUR_R);CLR_REG(GPIO_PORTD_AHB_PDR_R);break;
                              case GPIO_PullUp : SET_REG(GPIO_PORTD_AHB_PUR_R);CLR_REG(GPIO_PORTD_AHB_ODR_R);CLR_REG(GPIO_PORTD_AHB_PDR_R);break;
                              case GPIO_PullDown : SET_REG(GPIO_PORTD_AHB_PDR_R);CLR_REG(GPIO_PORTD_AHB_PUR_R);CLR_REG(GPIO_PORTD_AHB_ODR_R);break;
                              }

                              /* GPIO Digital Enable */
                              switch(Add_ptrPointerGPIO -> Den){
                              case GPIO_nonDEN : CLR_REG(GPIO_PORTD_AHB_DEN_R);break;
                              case GPIO_okDEN : SET_REG(GPIO_PORTD_AHB_DEN_R);break;
                              }


                              /* GPIO Analog mode select */
                              switch(Add_ptrPointerGPIO -> Amsel){
                              case GPIO_nonAMSEL : CLR_REG(GPIO_PORTD_AHB_AMSEL_R);break;
                              case GPIO_okAMSEL : SET_REG(GPIO_PORTD_AHB_AMSEL_R);break;
                              }
                          }

                          case GPIO_PortE : {
                              SET_BIT(SYSCTL_RCGCGPIO_R,4);
                              while(GET_BIT(SYSCTL_PRGPIO_R,4) == 0);

                              GPIO_PORTE_AHB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                              SET_REG(GPIO_PORTE_AHB_CR_R);

                              /* GPIO AFSEL Mode */
                              switch(Add_ptrPointerGPIO -> AFSEL){
                              case GPIO_nonAFSEL : CLR_REG(GPIO_PORTE_AHB_AFSEL_R);break;
                              case GPIO_okAFSEL : SET_REG(GPIO_PORTE_AHB_AFSEL_R);break;
                              }

                              /* GPIO Current Mode */
                              switch(Add_ptrPointerGPIO -> Current){
                              case GPIO_Current_2MA :SET_REG(GPIO_PORTE_AHB_DR2R_R);CLR_REG(GPIO_PORTE_AHB_DR4R_R);CLR_REG(GPIO_PORTE_AHB_DR8R_R);break;
                              case GPIO_Current_4MA :SET_REG(GPIO_PORTE_AHB_DR4R_R);CLR_REG(GPIO_PORTE_AHB_DR2R_R);CLR_REG(GPIO_PORTE_AHB_DR8R_R);break;
                              case GPIO_Current_8MA :SET_REG(GPIO_PORTE_AHB_DR8R_R);CLR_REG(GPIO_PORTE_AHB_DR4R_R);CLR_REG(GPIO_PORTE_AHB_DR2R_R);break;
                              }

                              /* GPIO Resistance Mode */
                              switch(Add_ptrPointerGPIO -> Res){
                              case GPIO_OpenDrain : SET_REG(GPIO_PORTE_AHB_ODR_R);CLR_REG(GPIO_PORTE_AHB_PUR_R);CLR_REG(GPIO_PORTE_AHB_PDR_R);break;
                              case GPIO_PullUp : SET_REG(GPIO_PORTE_AHB_PUR_R);CLR_REG(GPIO_PORTE_AHB_ODR_R);CLR_REG(GPIO_PORTE_AHB_PDR_R);break;
                              case GPIO_PullDown : SET_REG(GPIO_PORTE_AHB_PDR_R);CLR_REG(GPIO_PORTE_AHB_PUR_R);CLR_REG(GPIO_PORTE_AHB_ODR_R);break;
                              }

                              /* GPIO Digital Enable */
                              switch(Add_ptrPointerGPIO -> Den){
                              case GPIO_nonDEN : CLR_REG(GPIO_PORTE_AHB_DEN_R);break;
                              case GPIO_okDEN : SET_REG(GPIO_PORTE_AHB_DEN_R);break;
                              }


                              /* GPIO Analog mode select */
                              switch(Add_ptrPointerGPIO -> Amsel){
                              case GPIO_nonAMSEL : CLR_REG(GPIO_PORTE_AHB_AMSEL_R);break;
                              case GPIO_okAMSEL : SET_REG(GPIO_PORTE_AHB_AMSEL_R);break;
                              }
                          }

                          case GPIO_PortF : {
                              SET_BIT(SYSCTL_RCGCGPIO_R,5);
                              while(GET_BIT(SYSCTL_PRGPIO_R,5) == 0);

                              GPIO_PORTF_AHB_LOCK_R = GPIO_LOCK_KEY; // UnLock Register
                              SET_REG(GPIO_PORTF_AHB_CR_R);

                              /* GPIO AFSEL Mode */
                              switch(Add_ptrPointerGPIO -> AFSEL){
                              case GPIO_nonAFSEL : CLR_REG(GPIO_PORTF_AHB_AFSEL_R);break;
                              case GPIO_okAFSEL : SET_REG(GPIO_PORTF_AHB_AFSEL_R);break;
                              }

                              /* GPIO Current Mode */
                              switch(Add_ptrPointerGPIO -> Current){
                              case GPIO_Current_2MA :SET_REG(GPIO_PORTF_AHB_DR2R_R);CLR_REG(GPIO_PORTF_AHB_DR4R_R);CLR_REG(GPIO_PORTF_AHB_DR8R_R);break;
                              case GPIO_Current_4MA :SET_REG(GPIO_PORTF_AHB_DR4R_R);CLR_REG(GPIO_PORTF_AHB_DR2R_R);CLR_REG(GPIO_PORTF_AHB_DR8R_R);break;
                              case GPIO_Current_8MA :SET_REG(GPIO_PORTF_AHB_DR8R_R);CLR_REG(GPIO_PORTF_AHB_DR4R_R);CLR_REG(GPIO_PORTF_AHB_DR2R_R);break;
                              }

                              /* GPIO Resistance Mode */
                              switch(Add_ptrPointerGPIO -> Res){
                              case GPIO_OpenDrain : SET_REG(GPIO_PORTF_AHB_ODR_R);CLR_REG(GPIO_PORTF_AHB_PUR_R);CLR_REG(GPIO_PORTF_AHB_PDR_R);break;
                              case GPIO_PullUp : SET_REG(GPIO_PORTF_AHB_PUR_R);CLR_REG(GPIO_PORTF_AHB_ODR_R);CLR_REG(GPIO_PORTF_AHB_PDR_R);break;
                              case GPIO_PullDown : SET_REG(GPIO_PORTF_AHB_PDR_R);CLR_REG(GPIO_PORTF_AHB_PUR_R);CLR_REG(GPIO_PORTF_AHB_ODR_R);break;
                              }

                              /* GPIO Digital Enable */
                              switch(Add_ptrPointerGPIO -> Den){
                              case GPIO_nonDEN : CLR_REG(GPIO_PORTF_AHB_DEN_R);break;
                              case GPIO_okDEN : SET_REG(GPIO_PORTF_AHB_DEN_R);break;
                              }


                              /* GPIO Analog mode select */
                              switch(Add_ptrPointerGPIO -> Amsel){
                              case GPIO_nonAMSEL : CLR_REG(GPIO_PORTF_AHB_AMSEL_R);break;
                              case GPIO_okAMSEL : SET_REG(GPIO_PORTF_AHB_AMSEL_R);break;
                              }
                          }
                      }

            }
        }





GPIO_ErrorStatus GPIO_SetPortDirection(u8 Copy_u8PortId , u8 Copy_u8PortDir){

    GPIO_ErrorStatus LOC_enuErrorStatus = GPIO_enuOK;

        if(Copy_u8PortId <= GPIO_PortF){



            /* GPIO APB Mode */
            if(GPIO_Speed == GPIO_LowSpeed){
                        switch(Copy_u8PortId){

                        case GPIO_PortA : GPIO_PORTA_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortB : GPIO_PORTB_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortC : GPIO_PORTC_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortD : GPIO_PORTD_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortE : GPIO_PORTE_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortF : GPIO_PORTF_DIR_R = Copy_u8PortDir;break;
                        default : /* Wrong ID */ break;

                      }

                }

            else {

                    switch(Copy_u8PortId){
                        case GPIO_PortA : GPIO_PORTA_AHB_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortB : GPIO_PORTB_AHB_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortC : GPIO_PORTC_AHB_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortD : GPIO_PORTD_AHB_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortE : GPIO_PORTE_AHB_DIR_R = Copy_u8PortDir;break;
                        case GPIO_PortF : GPIO_PORTF_AHB_DIR_R = Copy_u8PortDir;break;
                        default : /* Wrong ID */ break;
                    }


            }
        } else

            LOC_enuErrorStatus = GPIO_Incorrect;

        return LOC_enuErrorStatus;
}


GPIO_ErrorStatus GPIO_SetPortValue(u8 Copy_u8PortId , u8 Copy_u8PortVal){

    GPIO_ErrorStatus LOC_enuErrorStatus = GPIO_enuOK;

        if(Copy_u8PortId <= GPIO_PortF){



            /* GPIO APB Mode */
            if(GPIO_Speed == GPIO_LowSpeed){
                        switch(Copy_u8PortId){

                        case GPIO_PortA : GPIO_PORTA_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortB : GPIO_PORTB_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortC : GPIO_PORTC_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortD : GPIO_PORTD_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortE : GPIO_PORTE_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortF : GPIO_PORTF_DATA_R = Copy_u8PortVal;break;
                        default : /* Wrong ID */ break;

                      }

                }

            else {

                    switch(Copy_u8PortId){
                        case GPIO_PortA : GPIO_PORTA_AHB_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortB : GPIO_PORTA_AHB_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortC : GPIO_PORTA_AHB_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortD : GPIO_PORTA_AHB_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortE : GPIO_PORTA_AHB_DATA_R = Copy_u8PortVal;break;
                        case GPIO_PortF : GPIO_PORTA_AHB_DATA_R = Copy_u8PortVal;break;
                        default : /* Wrong ID */ break;
                    }

                }

        } else

            LOC_enuErrorStatus = GPIO_Incorrect;

        return LOC_enuErrorStatus;
}


GPIO_ErrorStatus GPIO_SetPinDirection( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDir ){

    GPIO_ErrorStatus LOC_enuErrorStatus = GPIO_enuOK;

    if((Copy_u8PortId <= GPIO_PortF) && (Copy_u8PinId <= GPIO_Pin7)){ // check the port & pin is available



        /* GPIO APB Mode */
        if(GPIO_Speed == GPIO_LowSpeed){

        if(Copy_u8PinDir == GPIO_u8_PinOutput){ // if the pin is output = 1

            switch(Copy_u8PortId){

                case GPIO_PortA : SET_BIT(GPIO_PORTA_DIR_R,Copy_u8PinId);break;
                case GPIO_PortB : SET_BIT(GPIO_PORTB_DIR_R,Copy_u8PinId);break;
                case GPIO_PortC : SET_BIT(GPIO_PORTC_DIR_R,Copy_u8PinId);break;
                case GPIO_PortD : SET_BIT(GPIO_PORTD_DIR_R,Copy_u8PinId);break;
                case GPIO_PortE : SET_BIT(GPIO_PORTE_DIR_R,Copy_u8PinId);break;
                case GPIO_PortF : SET_BIT(GPIO_PORTF_DIR_R,Copy_u8PinId);break;
                default : /* Wrong ID */ ;break;

            }
        }

        else if(Copy_u8PinDir == GPIO_u8_PinInput){ // if the pin is input = 0

            switch(Copy_u8PortId){

            case GPIO_PortA : CLR_BIT(GPIO_PORTA_DIR_R,Copy_u8PinId);break;
            case GPIO_PortB : CLR_BIT(GPIO_PORTB_DIR_R,Copy_u8PinId);break;
            case GPIO_PortC : CLR_BIT(GPIO_PORTC_DIR_R,Copy_u8PinId);break;
            case GPIO_PortD : CLR_BIT(GPIO_PORTD_DIR_R,Copy_u8PinId);break;
            case GPIO_PortE : CLR_BIT(GPIO_PORTE_DIR_R,Copy_u8PinId);break;
            case GPIO_PortF : CLR_BIT(GPIO_PORTF_DIR_R,Copy_u8PinId);break;
            default : /* Wrong ID */ ;break;

            }
        }
        else
                LOC_enuErrorStatus = GPIO_Incorrect;


        }
        else {

            if(GPIO_u8_PinOutput){ // if the pin is output = 1

                 switch(Copy_u8PortId){

                     case GPIO_PortA : SET_BIT(GPIO_PORTA_DIR_R,Copy_u8PinId);break;
                     case GPIO_PortB : SET_BIT(GPIO_PORTB_DIR_R,Copy_u8PinId);break;
                     case GPIO_PortC : SET_BIT(GPIO_PORTC_DIR_R,Copy_u8PinId);break;
                     case GPIO_PortD : SET_BIT(GPIO_PORTD_DIR_R,Copy_u8PinId);break;
                     case GPIO_PortE : SET_BIT(GPIO_PORTE_DIR_R,Copy_u8PinId);break;
                     case GPIO_PortF : SET_BIT(GPIO_PORTF_DIR_R,Copy_u8PinId);break;
                     default : /* Wrong ID */ ;break;

                 }
             }

             else if(GPIO_u8_PinInput){ // if the pin is input = 0

                 switch(Copy_u8PortId){

                 case GPIO_PortA : CLR_BIT(GPIO_PORTA_DIR_R,Copy_u8PinId);break;
                 case GPIO_PortB : CLR_BIT(GPIO_PORTB_DIR_R,Copy_u8PinId);break;
                 case GPIO_PortC : CLR_BIT(GPIO_PORTC_DIR_R,Copy_u8PinId);break;
                 case GPIO_PortD : CLR_BIT(GPIO_PORTD_DIR_R,Copy_u8PinId);break;
                 case GPIO_PortE : CLR_BIT(GPIO_PORTE_DIR_R,Copy_u8PinId);break;
                 case GPIO_PortF : CLR_BIT(GPIO_PORTF_DIR_R,Copy_u8PinId);break;
                 default : /* Wrong ID */ ;break;

                 }
             }
             else
                     LOC_enuErrorStatus = GPIO_Incorrect;


        }

    }

    else

        LOC_enuErrorStatus = GPIO_Incorrect;


    return LOC_enuErrorStatus;
}

GPIO_ErrorStatus GPIO_SetPinValue( u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal){

    GPIO_ErrorStatus LOC_enuErrorStatus = GPIO_enuOK;

    if((Copy_u8PortId <= GPIO_PortF) && (Copy_u8PinId <= GPIO_Pin7)){ // check the port & pin is available


        /* GPIO APB Mode */
        if(GPIO_Speed == GPIO_LowSpeed){

        if(Copy_u8PinVal == GPIO_u8_PinHigh){ // if the pin is on

            switch(Copy_u8PortId){

                case GPIO_PortA : SET_BIT(GPIO_PORTA_DATA_R,Copy_u8PinId);break;
                case GPIO_PortB : SET_BIT(GPIO_PORTB_DATA_R,Copy_u8PinId);break;
                case GPIO_PortC : SET_BIT(GPIO_PORTC_DATA_R,Copy_u8PinId);break;
                case GPIO_PortD : SET_BIT(GPIO_PORTD_DATA_R,Copy_u8PinId);break;
                case GPIO_PortE : SET_BIT(GPIO_PORTE_DATA_R,Copy_u8PinId);break;
                case GPIO_PortF : SET_BIT(GPIO_PORTF_DATA_R,Copy_u8PinId);break;
                default : /* Wrong ID */ ;break;

            }
        }

        else if(Copy_u8PinVal == GPIO_u8_PinLow){ // if the pin is off

            switch(Copy_u8PortId){

            case GPIO_PortA : CLR_BIT(GPIO_PORTA_DATA_R,Copy_u8PinId);break;
            case GPIO_PortB : CLR_BIT(GPIO_PORTB_DATA_R,Copy_u8PinId);break;
            case GPIO_PortC : CLR_BIT(GPIO_PORTC_DATA_R,Copy_u8PinId);break;
            case GPIO_PortD : CLR_BIT(GPIO_PORTD_DATA_R,Copy_u8PinId);break;
            case GPIO_PortE : CLR_BIT(GPIO_PORTE_DATA_R,Copy_u8PinId);break;
            case GPIO_PortF : CLR_BIT(GPIO_PORTF_DATA_R,Copy_u8PinId);break;
            default : /* Wrong ID */ ;break;

            }
        }
        else
            {
                LOC_enuErrorStatus = GPIO_Incorrect;
            }

        }

        else {

             if(Copy_u8PinVal == GPIO_u8_PinHigh){ // if the pin is on

                 switch(Copy_u8PortId){

                     case GPIO_PortA : SET_BIT(GPIO_PORTA_AHB_DATA_R,Copy_u8PinId);break;
                     case GPIO_PortB : SET_BIT(GPIO_PORTB_AHB_DATA_R,Copy_u8PinId);break;
                     case GPIO_PortC : SET_BIT(GPIO_PORTC_AHB_DATA_R,Copy_u8PinId);break;
                     case GPIO_PortD : SET_BIT(GPIO_PORTD_AHB_DATA_R,Copy_u8PinId);break;
                     case GPIO_PortE : SET_BIT(GPIO_PORTE_AHB_DATA_R,Copy_u8PinId);break;
                     case GPIO_PortF : SET_BIT(GPIO_PORTF_AHB_DATA_R,Copy_u8PinId);break;
                     default : /* Wrong ID */ ;break;

                 }
             }

             else if(Copy_u8PinVal == GPIO_u8_PinLow){ // if the pin is off

                 switch(Copy_u8PortId){

                 case GPIO_PortA : CLR_BIT(GPIO_PORTA_AHB_DATA_R,Copy_u8PinId);break;
                 case GPIO_PortB : CLR_BIT(GPIO_PORTB_AHB_DATA_R,Copy_u8PinId);break;
                 case GPIO_PortC : CLR_BIT(GPIO_PORTC_AHB_DATA_R,Copy_u8PinId);break;
                 case GPIO_PortD : CLR_BIT(GPIO_PORTD_AHB_DATA_R,Copy_u8PinId);break;
                 case GPIO_PortE : CLR_BIT(GPIO_PORTE_AHB_DATA_R,Copy_u8PinId);break;
                 case GPIO_PortF : CLR_BIT(GPIO_PORTF_AHB_DATA_R,Copy_u8PinId);break;
                 default : /* Wrong ID */ ;break;

                 }
             }
             else
                 {
                     LOC_enuErrorStatus = GPIO_Incorrect;
                 }


             }
        }

    else
    {
        LOC_enuErrorStatus = GPIO_Incorrect;
    }

    return LOC_enuErrorStatus;
}


