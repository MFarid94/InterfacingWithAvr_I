/*
 * Exercise1_timer.c
 *
 *  Created on: Mar 18, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char g_Tick = 0;

ISR(TIMER0_OVF_vect){
	/* With each interrupt set initial timer value to 6 in order to
	 * count precisely 250 ms = 0.25 s */
	TCNT0 = 6;
	g_Tick++;
	if(g_Tick == 2){
		PORTC ^= (1<<PC0);
		g_Tick = 0;
	}
}

void timer0_init_normal_mode(void){
	/* Configure the timer control register
		 * 1. Non PWM mode FOC0=1
		 * 2. Normal Mode WGM01=0 & WGM00=0
		 * 3. Normal Mode COM00=0 & COM01=0
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
	TCCR0 |= (1<<FOC0) | (1<<CS00) | (1<<CS02);
	TIMSK |= (1<<TOIE0);								// Enable TIMER0 overflow Interrupt
	SREG |= (1<<7);										// Enable I-bit
}

int main(void){
	DDRC |= (1<<PC0);
	PORTC &= (~(1<<PC0));

	timer0_init_normal_mode();

	while(1){

	}
}
