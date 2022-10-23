#ifndef SysTick_H_
#define  SysTick_H_

#include "../../LIBRARIES/1-STD_TYPES/STD_TYPES.h"
#include "../../LIBRARIES/2-BIT_MATH/BIT_MATH.h"
#include "../../LIBRARIES/Registers_dif/tm4c123gh6pm.h"



void SYSTICK_init(void);

void SYSTICK_delay_m(u32 delayNms , void (*callback)(void));

#endif