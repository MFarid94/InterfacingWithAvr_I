/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control a led
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<util/delay.h>


int main(void){
	DDRD |= (1<<6);		/* Configure PIN 6 at PORTD as OUTPUT PIN */
	PORTD |= (1<<6);  /* Initialize PIN 6  at PORTD to 1, LED OFF*/

	while(1){
		PORTD &= (~(1<<6));

		_delay_ms(1000);

		PORTD |= (1<<6);

		_delay_ms(1000);
	}
}
