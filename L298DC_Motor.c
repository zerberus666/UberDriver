/*
 * L298DC_Motor.c
 *
 *  Created on: 15 θώνÿ 2015 γ.
 *      Author: Z
 */
#include "L298DC_Motor.h"
//#include  <inttypes.h>
void chSpeedChA (uint8_t speed) {

	OCR0A = speed;

}

void chSpeedChB (uint8_t speed) {

	OCR0B = speed;

}

int chDirChA (uint8_t dir) {
	switch (dir) {
		case 1: PORTB |= (1 << IN1_L298);
				PORTB &= ~(1 << IN2_L298);
				return 0;
				break;
		case 2: PORTB &= ~(1 << IN1_L298);
				PORTB |= (1 << IN2_L298);
				return 0;
				break;
		case 3: PORTB |= (1 << IN1_L298);
				PORTB |= (1 << IN2_L298);
				return 0;
				break;
		default: return 1;
			break;

	}


}

int chDirChB (uint8_t dir) {
	switch (dir) {
			case 1: PORTB |= (1 << IN3_L298);
					PORTB &= ~(1 << IN4_L298);
					return 0;
					break;
			case 2: PORTB &= ~(1 << IN3_L298);
					PORTB |= (1 << IN4_L298);
					return 0;
					break;
			case 3: PORTB |= (1 << IN3_L298);
					PORTB |= (1 << IN4_L298);
					return 0;
					break;
			default: return 1;
				break;

		}
}

void initL298DCMotor (void) {
	DDRD |= (1 << PD5);
	DDRB |= ((1 << PB2) | (1 << IN1_L298) | (1 << IN2_L298) | (1 << IN3_L298) | (1 << IN4_L298));


	TCCR0A |= (1 << COM0A1);
	TCCR0A &= ~(1 << COM0A0);
	TCCR0A |= (1 << COM0B1);
	TCCR0A &= ~(1 << COM0B0);
	TCCR0A |= ((1 << WGM00) | (1 << WGM01));
	TCCR0B &= ~(1 << WGM02);
	TCCR0B &= ~(1 << CS01);
	TCCR0B |= ((1 << CS00) | (1 << CS02));
	OCR0A = 0;
	OCR0B = 0;
}

