#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H
#include "../../LIBRARIES/1-STD_TYPES/STD_TYPES.h"



/*Function declarations*/
void NVIC_SetInterrupt  (u8 InterruptID);
void NVIC_ClearInterrupt(u8 InterruptID);
void NVIC_SetPending    (u8 InterruptID);
void NVIC_ClearPending  (u8 InterruptID);
void NVIC_SetPriority   (u8 InterruptID, u8 InterruptPriority);

/*Interrupt IDs*/
typedef enum NVIC_INT_ID {
    NVIC_GPIO_PORTA = 16,
    NVIC_GPIO_PORTB,
    NVIC_GPIO_PORTC,
    NVIC_GPIO_PORTD,
    NVIC_GPIO_PORTE,
    NVIC_GPIO_PORTF = 46 
}NVIC_INT_ID;

/*
typedef enum NVIC_PERIOD{

    NVIC_PRI0_R, 
    NVIC_PRI1_R, 
    NVIC_PRI2_R, 
    NVIC_PRI3_R, 
    NVIC_PRI4_R, 
    NVIC_PRI5_R, 
    NVIC_PRI6_R, 
    NVIC_PRI7_R, 
    NVIC_PRI8_R, 
    NVIC_PRI9_R, 
    NVIC_PRI10_R,
    NVIC_PRI11_R,
    NVIC_PRI12_R,
    NVIC_PRI13_R,
    NVIC_PRI14_R,
    NVIC_PRI15_R,
    NVIC_PRI16_R,
    NVIC_PRI17_R,
    NVIC_PRI18_R,
    NVIC_PRI19_R,
    NVIC_PRI20_R,
    NVIC_PRI21_R,
    NVIC_PRI22_R,
    NVIC_PRI23_R,
    NVIC_PRI24_R,
    NVIC_PRI25_R,
    NVIC_PRI26_R,
    NVIC_PRI27_R,
    NVIC_PRI28_R,
    NVIC_PRI29_R,
    NVIC_PRI30_R,
    NVIC_PRI31_R,
    NVIC_PRI32_R,
    NVIC_PRI33_R,
    NVIC_PRI34_R
}NVIC_PERIOD;
*/
#endif