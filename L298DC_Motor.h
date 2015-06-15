/*
 * L298DC_Motor.h
 *
 *  Created on: 15 θώνÿ 2015 γ.
 *      Author: Z
 *      Only for ATTiny2313
 */

#ifndef L298DC_MOTOR_H_
#define L298DC_MOTOR_H_
#include <avr/io.h>
#include <avr/iotn2313.h>
#include <inttypes.h>

#define IN1_L298 PB0
#define IN2_L298 PB1
#define IN3_L298 PB6
#define IN4_L298 PB7



void chSpeedChA (uint8_t speed);
void chSpeedChB (uint8_t speed);
int chDirChA (uint8_t dir);
int chDirChB (uint8_t dir);
void initL298DCMotor (void);


#endif /* L298DC_MOTOR_H_ */
