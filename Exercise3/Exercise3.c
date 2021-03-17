/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control two leds using two push buttons
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr\io.h>

int main(void){
	DDRB &= (~(1<<PB0));
	DDRB &= (~(1<<PB1));
	DDRC |= (1<<PC0);
	DDRC |= (1<<PC1);
	PORTC &= (~(1<<PC0));
	PORTC &= (~(1<<PC1));

	while(1){
		if(PINB&(1<<PB0)){
			PORTC |= (1<<PC0);
		}
		else{
			PORTC &= (~(1<<PC0));
		}

		if(PINB & (1<<PB1)){
			PORTC |= (1<<PC1);
		}
		else{
			PORTC &= (~(1<<PC1));
		}
	}
}
