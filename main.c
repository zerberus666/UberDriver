/*
 * main.c
 *
 *  Created on: 14 θώνÿ 2015 γ.
 *      Author: Miksher
 */

#include <avr/io.h>
#include <avr/iotn2313.h>
#include <inttypes.h>
#include <util/delay.h>
#include "L298DC_Motor.h"

#define F_CPU 16000000H
void setup (void);


int main (void) {
	setup();
	int count = 0;
	chSpeedChB(0xAF);
	chDirChA (2);
	chDirChB (1);
	while (1) {
		for (count = 0; count < 250; count++){
			chSpeedChA(count);
			_delay_ms(2);
		}
		for (count = 255; count > 1; count--){
			chSpeedChA(count);
			_delay_ms(2);
		}
	}
	return 0;

}

void setup (void){
initL298DCMotor();
}




