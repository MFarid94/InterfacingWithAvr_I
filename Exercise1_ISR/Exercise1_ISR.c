/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control 7-segment using Two push button
 * Created on: Mar 18, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<avr/interrupt.h>

ISR(INT0_vect){
	PORTC ^= (1<<PC0);		// Toggle LED with each interrupt request
}

void INT0_Init(void){
	DDRD &= (~(1<<PD2));					// configure PIN PD2 as input
	MCUCR |= (1<<ISC00) | (1<<ISC01);		// Trigger INT0 with raising edge
	GICR |= (1<<INT0);                      // Enable external interrupt pin INT0
	SREG |= (1<<7);							// Enable I-bit
}

int main(void){
		INT0_Init();

		DDRC |= (1<<PC0);		// configure PIN PC0 as output
		PORTC |= (1<<PC0);		// Initialize PIN PC0 to 1 , LED OFF

		while(1){

		}
}
