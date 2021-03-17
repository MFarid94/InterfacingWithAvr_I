/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control 8 leds
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<util/delay.h>

int main(void){
	unsigned char i;

	DDRC = 0xFF;
	PORTC = 0x00;

	while(1){
		for(i=0 ; i<8 ; ){
			PORTC |= (1<<i);
			_delay_ms(500);
			PORTC &= (~(1<<i));
			i++;
			if(i == 8){
				i = 0;
			}
		}
	}
}
