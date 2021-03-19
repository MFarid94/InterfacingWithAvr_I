/*
 * Challenge2_timer.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char g_Tick = 0;

ISR(TIMER0_COMP_vect){
	g_Tick++;
	PORTC ^= (1<<PC0);
	if(g_Tick == 2){
		PORTC ^= (1<<PC1);
	}
	else if (g_Tick == 4){
		PORTC ^= (1<<PC1) ^ (1<<PC2);
		g_Tick = 0;
	}
}

void timer0_CTC_square_wave_init(void){
	OCR0 = 50;			// interrupt is generated every 50 us
	TCNT0 = 0;			// Initial timer value is 0
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS01);
	TIMSK |= (1<<OCIE0);
	SREG |= (1<<7);
}

int main(void){
	DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC2);
	PORTC &= (~(1<<PC0)) & (~(1<<PC1)) &(~(1<<PC2));

	timer0_CTC_square_wave_init();

	while(1){

	}
}
