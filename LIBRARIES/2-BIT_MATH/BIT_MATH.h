/*
 * BIT_MATH.h
 *
 * Created: 10/09/2022 6:58:02 am
 *  Author: moham
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR , BITNO)		VAR |= (1<<BITNO)
#define CLR_BIT(VAR , BITNO)		VAR &=~(1<<BITNO)
#define GET_BIT(VAR , BITNO)		((VAR>>BITNO) & 1)
#define TOG_BIT(VAR , BITNO)		VAR ^= (1<<BITNO)


#endif /* BIT_MATH_H_ */