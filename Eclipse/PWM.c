/*
 * PWM.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Muhammad Al-Barbary
 */


#include <util/delay.h>
#include "GPIO.h"
#include  "PWM.h"
#include <avr/io.h>

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */
void PWM0_Start(uint8 DutyCycle)
{
	PWM_Value = 0; // Set Timer Initial Value to 0

	PWM_DutyCycle  = (DutyCycle*PWM_MaxValue)/100; // Set Compare Value

	SetPin(PWM_Pin,PWM_Port,Output); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

