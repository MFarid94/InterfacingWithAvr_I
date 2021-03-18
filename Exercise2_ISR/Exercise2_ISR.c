/*
 * Exercise2_ISR.c
 * Created on: Mar 18, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

ISR(INT1_vect){
	for(int i = 0; i<5 ;i++){
		PORTC = 0xFF;
		_delay_ms(500);
		PORTC = 0x00;
		_delay_ms(500);
	}
}

void INT1_Init(void){
	DDRD &= (~(1<<PD3));					// Configure PIN PD3 as input pin
	PORTD |= (1<<PD3);						// Activate internal pull up
	MCUCR |= (1<<ISC10) | (1<<ISC11);		// Trigger INT1 with rising edge
	GICR |= (1<<INT1);						// Enable external interrupt pin INT1
	SREG |= (1<<7);							// Enable I-bit
}

int main(void){
	INT1_Init();

	DDRC = 0xFF;							// Configure PORTC as Output
	PORTC = 0x00;							// Initialize PORTC to 0

	while(1){
		for(int i = 0; i < 8 ; ){
			PORTC |= (1<<i);
			_delay_ms(500);
			PORTC &= (~(1<<i));
			i++;
			if(i == 8){
				i = 0;
			}
		}
	}
}
