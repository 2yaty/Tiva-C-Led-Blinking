#include "SysTick.h"

void static (*SYSTICK_callback)(void);

u32 volatile counter  = 0;

void SYSTICK_init(void){

    /**
     * Enable NVIC 
     * give the timer priority
     * 
     * */

    /**
     * "STCTRL"
     * setting the bit 2 "CLK_SRC" to use the system timer.
     * setting the bit 1 "INTEN" to activate the interrupt.
     * clearing the bit 0 "ENABLE" so that I can Enable it when I start the timer.
     * */
    NVIC_ST_CTRL_R = 6;


    /**
     * "STRELOAD"
     * while I'm using the default 16M System timer there is a tick every (1/16)uS so to get to delay every 1mS I need (1m / (1/16)u) = 16000 tick.
     * so the timer will fire interrupt every 1mS.
     * */

    NVIC_ST_RELOAD_R = 16000;

}

void SYSTICK_delay_m(u32 delayNms , void (*callback)(void)) {


    counter = delayNms;

    SYSTICK_callback = callback;

    SET_BIT(NVIC_ST_CTRL_R , 0); //START TIMER

}


void Systick_Handler(void) {

	if (counter --  == 0) {
        CLR_BIT(NVIC_ST_CTRL_R , 0);
        SYSTICK_callback();
	}

}

