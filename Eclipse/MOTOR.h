/*
 * MOTOR.h
 *
 *  Created on: Oct 17, 2021
 *      Author: Muhammad Al-Barbary
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "StdTypes.h"

//definitions
#define MotorPinA Pin0
#define MotorPinB Pin1
#define MotorPort PortB

typedef enum {Stop,CW,ACW}MOTOR_State;


//functions

/*Function responsible for setting
  the direction of the motor pins
  Motor is initially stopped*/
void MOTOR_Init(void);

/*Function responsible for choosing
  the direction of rotation of motor
  and choosing its speed of rotation*/
void MOTOR_Rotate(MOTOR_State state,uint8 speed);


#endif /* MOTOR_H_ */
