/*
 * Exercise5_timer.c
 *
 *  Created on: Mar 19, 2021
 *      Author: mfari
 */

#include<avr/io.h>
#include<util/delay.h>

void Timer0_PWM_Init(unsigned char set_duty_cycle){
	TCNT0 = 0;
	DDRB |= (1<<PB3);
	OCR0 = set_duty_cycle;
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (CS01);
}

int main(void){
	unsigned char duty;
		while(1)
		{
			for(duty = 0 ; duty < 255 ; duty++)
			{
				/*increase the LED light intensity*/
				Timer0_PWM_Init(duty);
				_delay_ms(10);
			}
			_delay_ms(100);
			for(duty = 255 ; duty > 0 ; duty--)
			{
				/*decrease the LED light intensity*/
				Timer0_PWM_Init(duty);
				_delay_ms(10);
			}
		}

}
