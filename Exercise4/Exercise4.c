/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control a led using a push button
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<util/delay.h>

int main(void){
	unsigned char flag = 0;

	DDRB &= (~(1<<PB0));
	PORTB |= (1<<PB0);

	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);

	while(1){
		if(!(PINB & (1<<PB0))){
			_delay_ms(30);
			if(!(PINB & (1<<PB0))){
				if(flag == 0){
					PORTC ^= (1<<PC0);
					flag = 1;
				}
			}
			else{
				flag = 0;
			}
		}
	}
}
