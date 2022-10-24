#include "NVIC.h"
#include "../../LIBRARIES/1-STD_TYPES/STD_TYPES.h"
#include "../../LIBRARIES/Registers_dif/tm4c123gh6pm.h"

void NVIC_SetInterrupt  (u8 InterruptID){

    /*Global interrupt enable*/
	__enable_irq();

    u8 registerNumber = (InterruptID - 16) / 32;
	u8 bitNumber = (InterruptID - 16) % 32;

	switch (registerNumber) {
	case 0:
		SET_BIT(NVIC_EN0_R, bitNumber);
		break;

	case 1:
		SET_BIT(NVIC_EN1_R, bitNumber);
		break;

	case 2:
		SET_BIT(NVIC_EN2_R, bitNumber);
		break;

	case 3:
		SET_BIT(NVIC_EN3_R, bitNumber);
		break;


    /**
     * Future Work 
     * add more Interrupt Registers 
     */

	default:
		return ;

	}

}
void NVIC_ClearInterrupt(u8 InterruptID){

    u8 registerNumber = (InterruptID - 16) / 32;
	u8 bitNumber = (InterruptID - 16) % 32;

	switch (registerNumber) {
	case 0:
		SET_BIT(NVIC_DIS0_R, bitNumber);
		break;

	case 1:
		SET_BIT(NVIC_DIS1_R, bitNumber);
		break;

	case 2:
		SET_BIT(NVIC_DIS2_R, bitNumber);
		break;

	case 3:
		SET_BIT(NVIC_DIS3_R, bitNumber);
		break;


    /**
     * Future Work 
     * add more Interrupt Registers 
     */

	default:
		return ;

	}

}
void NVIC_SetPending    (u8 InterruptID){

    u8 registerNumber = (InterruptID - 16) / 32;
	u8 bitNumber = (InterruptID - 16) % 32;

	switch (registerNumber) {
	case 0:
		SET_BIT(NVIC_PEND0_R, bitNumber);
		break;

	case 1:
		SET_BIT(NVIC_PEND1_R, bitNumber);
		break;

	case 2:
		SET_BIT(NVIC_PEND2_R, bitNumber);
		break;

	case 3:
		SET_BIT(NVIC_PEND3_R, bitNumber);
		break;


    /**
     * Future Work 
     * add more Interrupt Registers 
     */

	default:
		return ;

	}
}
void NVIC_ClearPending  (u8 InterruptID){
    u8 registerNumber = (InterruptID - 16) / 32;
	u8 bitNumber = (InterruptID - 16) % 32;

	switch (registerNumber) {
	case 0:
		SET_BIT(NVIC_EN0_R, bitNumber);
		break;

	case 1:
		SET_BIT(NVIC_EN1_R, bitNumber);
		break;

	case 2:
		SET_BIT(NVIC_EN2_R, bitNumber);
		break;

	case 3:
		SET_BIT(NVIC_EN3_R, bitNumber);
		break;


    /**
     * Future Work 
     * add more Interrupt Registers 
     */

	default:
		return ;

	}
}
/*
* future work

void NVIC_SetPriority   (u8 InterruptID, u8 InterruptPriority){
    
    u8 registerNumber = (InterruptID - 16) / 4;
	u8 bitNumber = (InterruptID - 16) % 4;
	
}

*/