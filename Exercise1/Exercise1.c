/*
 * Exercise1.c
 * Description: Embedded C code using ATmega16 uC to control a led using a push buttton
 * Created on: Mar 16, 2021
 * Author: Muhammad Farid
 */

#include<avr\io.h>

int main(void){
	DDRA &= (~(1<<3));			/* Pin 3 at Port A configured as input */
	DDRC |= (1<<5);				/* Pin 5 at Port C configured as output */
	PORTC &= (~(1<<5));			/* Pin 5 at Port C initialized to 0 */

	while(1){
		if( PINA & (1<<3) ){	/* check if push button at Port A Pin 3 is pressed */
			PORTC |= (1<<5);	/* Set Pin 5 at Port C , LED ON */
		}
		else{
			PORTC &= (~(1<<5));				/* Clear Pin 5 at Port C , LED OFF */
		}
	}
}
