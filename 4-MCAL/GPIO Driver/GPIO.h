#ifndef GPIO_H_
#define GPIO_H_

#include "../../LIBRARIES/1-STD_TYPES/STD_TYPES.h"

/**************     MACROS      *************/
#define INPUT   0
#define OUTPUT  1
#define LOW     0
#define HIGH    1

/*** Ports Definitions ***/
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3
#define PORTE   4
#define PORTF   5

/*** Output currernt on the pin ***/
#define _2mA    0
#define _4mA    1
#define _8mA    2

/***  Pin internal attach  ***/
#define PULLUP      0
#define PULLDOWN    1


/**************     Typedefs      *************/

typedef enum GPIO_ERROR_EN 
{
    GPIO_OK,
    WRONG_PIN,
    WRONG_PORT,
    WRONG_DIRECTION,

} GPIO_ERROR_EN;

/*
typedef enum GPIO_ALT_SEL 
{
    GPIO,
    U0Rx, U0Tx, U1Rx, U1Tx, TCK_SWCLK, TMS_SWDIO, TDI, TDO_SWO, U4Rx, U4Tx, U3Rx, U3Tx, SSI3Clk, SSI3Fss, SSI3Rx, SSI3Tx, U6Rx, U6Tx, U2Rx, U2Tx, U7Rx, U7Tx, U5Rx, U5Tx, U1RTS, U1CTS,
    SSI0Clk, SSI0Fss, SSI0Rx, SSI0Tx, SSI2Clk, SSI2Fss, SSI2Rx, SSI2Tx, U1Rx, U1Tx, SSI1Clk, SSI1Fss, SSI1Rx, SSI1Tx, SSI1Rx, SSI1Tx, SSI1Clk, SSI1Fss, 
    I2C1SCL, I2C1SDA, I2C0SCL, I2C0SDA, I2C3SCL, 

} GPIO_ALT_SEL;
*/

typedef struct GPIO_PIN_ST
{
    u8 pin ;
    u8 port ;
    u8 direction ;
    u8 alt_func ;

} GPIO_PIN_ST;


/**************     Functions      *************/

GPIO_ERROR_EN GPIO_pin_init(GPIO_PIN_ST* pin);
GPIO_ERROR_EN GPIO_port_init( u8 port);

GPIO_ERROR_EN GPIO_pin_write(GPIO_PIN_ST* pin , u8 value);
GPIO_ERROR_EN GPIO_pin_toggle(GPIO_PIN_ST* pin);
GPIO_ERROR_EN GPIO_pin_read(GPIO_PIN_ST* pin , u8* result);




#endif