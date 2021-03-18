/*
 * Exercise2_ISR.c
 * Created on: Mar 18, 2021
 * Author: Muhammad Farid
 */

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

unsigned char g_Interrupt_Flag = 0;

ISR(INT1_vect){
	g_Interrupt_Flag = 1;
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

	unsigned char Loop_idx;
	while(1){
		if(g_Interrupt_Flag == 0){

					_delay_ms(500);
					PORTC = (PORTC<<1);
					if(PORTC == 0x00){
						PORTC = 0x01;
					}
		}
		else if(g_Interrupt_Flag == 1){
			for(Loop_idx = 0; Loop_idx < 5 ; Loop_idx++){
					PORTC = 0xFF;
					_delay_ms(500);
					PORTC = 0x00;
					_delay_ms(500);
				}
		}
	}
}
