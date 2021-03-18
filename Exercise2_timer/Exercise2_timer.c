/*
 * Exercise1_timer_comp.c
 *
 *  Created on: Mar 18, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char g_Tick = 0;

ISR(TIMER0_COMP_vect){

	g_Tick++;
	if(g_Tick == 2){
		PORTC ^= (1<<PC0);
		g_Tick = 0;
	}
}

void timer0_init_compare_mode(void){
	OCR0 = 250; 				// each 250 clk = 250 ms an interrupt is raised
	/* Configure the timer control register
		 * 1. Non PWM mode FOC0=1
		 * 2. compare Mode WGM01=1 & WGM00=0
		 * 3. Normal Mode COM00=0 & COM01=0
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<CS00) | (1<<CS02);
	TIMSK |= (1<<OCIE0);								// Enable TIMER0 compare Interrupt
	SREG |= (1<<7);										// Enable I-bit
}

int main(void){
	DDRC |= (1<<PC0);
	PORTC &= (~(1<<PC0));

	timer0_init_compare_mode();

	while(1){

	}
}
