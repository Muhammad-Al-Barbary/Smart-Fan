/*
 * PWM.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Muhammad Al-Barbary
 */

#ifndef PWM_H_
#define PWM_H_

#include "StdTypes.h"
#include <avr/io.h>


//definitions
#define PWM_Value TCNT0
#define PWM_DutyCycle OCR0
#define PWM_MaxValue 255
#define PWM_Port PortB
#define PWM_Pin  Pin3

//functions
void PWM0_Start(uint8 DutyCycle);


#endif /* PWM_H_ */
