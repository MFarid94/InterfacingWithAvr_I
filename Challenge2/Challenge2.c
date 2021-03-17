/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control 7-segment using Two push button
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<util/delay.h>

int main(void){
	unsigned char num = 0;
	DDRD |= 0x0F;
	PORTD &= 0xF0;

	DDRA &= (~(1<<PA0)) & (~(1<<PA1));

	while(1){
		if(PINA & (1<<PA0)){
			_delay_ms(30);
			if(PINA & (1<<PA0)){
				if( (PORTD & 0x0F) == 9){
					PORTD = (PORTD & 0xF0) | (num & 0x0F);
				}
				else{
					num++;
					PORTD = (PORTD & 0xF0) | (num & 0x0F);
				}
				while(PINA & (1<<PA0)){};
			}
		}
		else if(PINA & (1<<PA1)){
			_delay_ms(30);
			if(PINA & (1<<PA1)){
				if( (PORTD & 0x0F) == 0){
					PORTD = (PORTD & 0xF0) | (num & 0x0F);
				}
				else{
					num--;
					PORTD = (PORTD & 0xF0) | (num & 0x0F);
				}
				while(PINA & (1<<PA1)){};
			}
		}
	}
}
