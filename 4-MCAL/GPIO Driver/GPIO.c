#include "GPIO_PRIVATE.h"
#include "GPIO.h"
#include "../../LIBRARIES/Registers_dif/tm4c123gh6pm.h"
#include "../../LIBRARIES/2-BIT_MATH/BIT_MATH.h"

GPIO_ERROR_EN GPIO_pin_init(GPIO_PIN_ST* PIN){


    if (PIN->pin > 7 )
    {
        return WRONG_PIN;
    }
    else if (PIN->port == PORTE && PIN->pin > 6)
    {
        return WRONG_PIN;
    }
    else if (PIN->port == PORTF && PIN->pin > 5)
    {
        return WRONG_PIN;
    }
    
    
    
    switch ( PIN->port)
    {
    case PORTA:
        if(PIN->direction){ SET_BIT(GPIO_PORTA_DIR_R, PIN->pin); } 
        else { CLR_BIT(GPIO_PORTA_DIR_R, PIN->pin); }

        if (PIN->alt_func == 0)
        { SET_BIT(GPIO_PORTA_AFSEL_R , PIN->pin); } 

        SET_BIT(GPIO_PORTA_DEN_R , PIN->pin);   

        /**
         * Future Work:
         *      Enabling the option for the analog 
         *      adding a way to choose the alternate function
         */
        
        break;

    case PORTB:
        if(PIN->direction){ SET_BIT(GPIO_PORTB_DIR_R, PIN->pin); } 
        else { CLR_BIT(GPIO_PORTB_DIR_R, PIN->pin); }

        if (PIN->alt_func == 0)
        { SET_BIT(GPIO_PORTB_AFSEL_R , PIN->pin); } 

        SET_BIT(GPIO_PORTB_DEN_R , PIN->pin);   
        break;

    case PORTC:
        if(PIN->direction){ SET_BIT(GPIO_PORTC_DIR_R, PIN->pin); } 
        else { CLR_BIT(GPIO_PORTC_DIR_R, PIN->pin); }

        if (PIN->alt_func == 0)
        { SET_BIT(GPIO_PORTC_AFSEL_R , PIN->pin); } 

        SET_BIT(GPIO_PORTC_DEN_R , PIN->pin); 
        break;

    case PORTD:
        if(PIN->direction){ SET_BIT(GPIO_PORTD_DIR_R, PIN->pin); } 
        else { CLR_BIT(GPIO_PORTD_DIR_R, PIN->pin); }

        if (PIN->alt_func == 0)
        { SET_BIT(GPIO_PORTD_AFSEL_R , PIN->pin); } 

        SET_BIT(GPIO_PORTD_DEN_R , PIN->pin); 
        break;

    case PORTE:
        if(PIN->direction){ SET_BIT(GPIO_PORTE_DIR_R, PIN->pin); } 
        else { CLR_BIT(GPIO_PORTE_DIR_R, PIN->pin); }

        if (PIN->alt_func == 0)
        { SET_BIT(GPIO_PORTE_AFSEL_R , PIN->pin); } 

        SET_BIT(GPIO_PORTE_DEN_R , PIN->pin); 
        break;
    

    case PORTF:
        if(PIN->direction){ SET_BIT(GPIO_PORTF_DIR_R, PIN->pin); } 
        else { CLR_BIT(GPIO_PORTF_DIR_R, PIN->pin); }

        if (PIN->alt_func == 0)
        { SET_BIT(GPIO_PORTF_AFSEL_R , PIN->pin); } 

        SET_BIT(GPIO_PORTF_DEN_R , PIN->pin); 
        break;

    default:
        return WRONG_PORT;
    }

    return GPIO_OK;
    
    
}
GPIO_ERROR_EN GPIO_port_init( u8 port){

    if (port > 5  )
    {
        return WRONG_PORT;
    }
    
    SET_BIT(SYSCTL_RCGCGPIO_R , port);

			return GPIO_OK;
}

GPIO_ERROR_EN GPIO_pin_write(GPIO_PIN_ST* PIN , u8 value){

    switch (PIN->port)
    {
    case PORTA:
        if(value > 0) SET_BIT(GPIO_PORTA_DATA_R , PIN->pin); else CLR_BIT(GPIO_PORTA_DATA_R , PIN->pin);
        break;

    case PORTB:
        if(value > 0) SET_BIT(GPIO_PORTB_DATA_R , PIN->pin); else CLR_BIT(GPIO_PORTB_DATA_R , PIN->pin);
        break;
    
    case PORTC:
        if(value > 0) SET_BIT(GPIO_PORTC_DATA_R , PIN->pin); else CLR_BIT(GPIO_PORTC_DATA_R , PIN->pin);
        break;

    case PORTD:
        if(value > 0) SET_BIT(GPIO_PORTD_DATA_R , PIN->pin); else CLR_BIT(GPIO_PORTD_DATA_R , PIN->pin);
        break;

    case PORTE:
        if(value > 0) SET_BIT(GPIO_PORTE_DATA_R , PIN->pin); else CLR_BIT(GPIO_PORTE_DATA_R , PIN->pin);
        break;

    case PORTF:
        if(value > 0) SET_BIT(GPIO_PORTF_DATA_R , PIN->pin); else CLR_BIT(GPIO_PORTF_DATA_R , PIN->pin);
        break;

    default:
        return WRONG_PORT;
        
    }

    return GPIO_OK;

}
GPIO_ERROR_EN GPIO_pin_toggle(GPIO_PIN_ST* PIN){

    switch (PIN->port)
    {
    case PORTA:
        TOG_BIT(GPIO_PORTA_DATA_R , PIN->pin );
        break;
    
    case PORTB:
        TOG_BIT(GPIO_PORTB_DATA_R , PIN->pin );
        break;

    case PORTC:
        TOG_BIT(GPIO_PORTC_DATA_R , PIN->pin );
        break;

    case PORTD:
        TOG_BIT(GPIO_PORTD_DATA_R , PIN->pin );
        break;

    case PORTE:
        TOG_BIT(GPIO_PORTE_DATA_R , PIN->pin );
        break;

    case PORTF:
        TOG_BIT(GPIO_PORTF_DATA_R , PIN->pin );
        break;

    default:
        return WRONG_PORT;
      
    }

    return GPIO_OK;
}
GPIO_ERROR_EN GPIO_pin_read(GPIO_PIN_ST* PIN , u8* result){

    switch (PIN->port)
    {
    case PORTA:
        *result = GET_BIT(GPIO_PORTA_DATA_R , PIN->pin);
        break;
    
    case PORTB:
        *result = GET_BIT(GPIO_PORTB_DATA_R , PIN->pin);
        break;

    case PORTC:
        *result = GET_BIT(GPIO_PORTC_DATA_R , PIN->pin);
        break;

    case PORTD:
        *result = GET_BIT(GPIO_PORTD_DATA_R , PIN->pin);
        break;

    case PORTE:
        *result = GET_BIT(GPIO_PORTE_DATA_R , PIN->pin);
        break;

    case PORTF:
        *result = GET_BIT(GPIO_PORTF_DATA_R , PIN->pin);
        break;

    default:
        return WRONG_PORT;
       
    }

    return GPIO_OK;
}
