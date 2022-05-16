/*
 * MOTOR.c
 *
 *  Created on: Oct 17, 2021
 *      Author: Muhammad Al-Barbary
 */

#include "GPIO.h"
#include "MOTOR.h"
#include "PWM.h"


void MOTOR_Rotate(MOTOR_State state,uint8 speed){
	WritePin(MotorPinA,MotorPort,state& 0b01);
	WritePin(MotorPinB,MotorPort,state& 0b10);
	PWM0_Start(speed);
}

void MOTOR_Init(void){
	SetPin(MotorPinA,MotorPort,Output);
	SetPin(MotorPinB,MotorPort,Output);
	MOTOR_State state={Stop};
	WritePin(MotorPinA,MotorPort,state& 0b01);
	WritePin(MotorPinB,MotorPort,state& 0b10);
}


