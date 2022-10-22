#include "GPIO_test.h"
#include "GPIO.h"


void GPIO_test(void){

    GPIO_PIN_ST led1 = {0 , PORTF , OUTPUT , 0};

    GPIO_PIN_ST led2 = {1 , PORTF, OUTPUT , 0};
    
    GPIO_port_init(PORTF);


    GPIO_pin_init(&led1);
    GPIO_pin_init(&led2);


    GPIO_pin_write(&led1 , HIGH);

    GPIO_pin_write(&led2 , 0);


}
