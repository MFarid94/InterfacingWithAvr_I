/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control 7-segment using a push button
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<util/delay.h>

int main(void){
	unsigned char num = 0;
	DDRC |= 0x0F;
	PORTC &= 0xF0;

	DDRD &= (~(1<<PD4));

	while(1){
		if(PIND & (1<<PD4)){
			_delay_ms(30);
			if(PIND & (1<<PD4)){
				if( (PORTC & 0x0F) == 9){
					num = (num & 0xF0);
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
				else{
					num++;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
				while(PIND & (1<<PD4)){};
			}
		}
	}
}
