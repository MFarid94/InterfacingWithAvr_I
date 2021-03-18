/*
 * Challenge1_timer.c
 *
 *  Created on: Mar 18, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<avr/interrupt.h>


unsigned char g_Tick = 0;
unsigned char g_Num = 0;

ISR(TIMER0_OVF_vect){
	g_Tick++;
	if(g_Tick == 122){
		g_Num++;
		g_Tick = 0;
	}
}

void timer0_init_normal_mode(void){
	TCNT0 = 0;			// initialize to 0
	/* Configure the timer control register
			 * 1. Non PWM mode FOC0=1
			 * 2. Normal Mode WGM01=0 & WGM00=0
			 * 3. Normal Mode COM00=0 & COM01=0
			 * 4. clock = F_CPU/256 CS00= CS01=0 CS02=1
			 */
	TCCR0 |= (1<<FOC0) | (1<<CS02);
	TIMSK |= (1<<TOIE0);			//Enable timer0 overflow interrupt
	SREG |= (1<<7);
}

int main(void){
	DDRC |= 0x0F;
	PORTC &= 0xF0;

	timer0_init_normal_mode();

	while(1){
		if((PORTC & 0x0F) == 10){
			g_Num = (g_Num & 0xF0);
			PORTC = (PORTC & 0xF0) | (g_Num & 0x0F);
		}
		else{
			PORTC = (PORTC & 0xF0) | (g_Num & 0x0F);
		}
	}
}
