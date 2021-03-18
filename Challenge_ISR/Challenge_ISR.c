/*
 * Challenge_ISR.c
 *
 *  Created on: Mar 18, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<avr/interrupt.h>

unsigned char g_num = 0;

ISR(INT2_vect){

	if((PORTC & 0x0F) == 9){
		g_num = (g_num & 0xF0);
		PORTC = (PORTC & 0xF0) | (g_num & 0x0F);
	}
	else{
		g_num++;
		PORTC = (PORTC & 0xF0) | (g_num & 0x0F);
	}
}

void INT2_Init(void){
	DDRB &= (~(1<<PB2));		//	Configure PIN PB2 as input
	MCUCR |= (1<<ISC2);			// Trigger INT2 with rising edge
	GICR |= (1<<INT2);			// Enable external interrupt PIN INT2
	SREG |= (1<<7);
}

int main(void){

	DDRC = 0x0F;				// Configure first 4 pins of PORTC as output
	PORTC = 0x00;				// Initialize first 4 pins of PORTC with 0


	INT2_Init();

	while(1){

	}
}
