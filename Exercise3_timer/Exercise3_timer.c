/*
 * Exercise3_timer.c
 *
 *  Created on: Mar 18, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<avr/interrupt.h>


void timer0_CTC_square_wave_init(void){
	TCNT0 = 0;
	DDRB |= (1<<PB3);
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
	OCR0 = 250;

}

int main(void){
	timer0_CTC_square_wave_init();
	while(1){

	}
}
