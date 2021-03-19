/*
 * Exercise4_timer.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<util/delay.h>

void Timer0_PWM_Init(unsigned char set_duty_cycle){
	TCNT0 = 0;
	OCR0 = set_duty_cycle;
	DDRB |= (1<<PB3);
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}


int main(void){
	Timer0_PWM_Init(128);
	_delay_ms(5000);
	Timer0_PWM_Init(64);

	while(1){

	}
}
