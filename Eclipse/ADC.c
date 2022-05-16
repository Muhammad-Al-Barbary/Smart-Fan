/*
 * ADC.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Muhammad Al-Barbary
 */

#include "avr/io.h" /* To use the ADC Registers */
#include "ADC.h"
#include "CommonMacros.h" /* To use the macros like SET_BIT */
#include "GPIO.h"

//functions
void ADC_Init(const ADC_ConfigType* ConfigPtr)
{
	ADMUX = (ConfigPtr->RefVolt<<6);
	ADCSRA = (1<<ADEN)|(ConfigPtr->Prescaler);
}

uint16 ADC_ReadChannel(uint8 Channel)
{
	Channel &= 0x07; // Input channel number must be from 0 --> 7
	ADMUX &= 0xE0; // Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel
	ADMUX = ADMUX | Channel;
	SetBit(ADCSRA,ADSC); // Start conversion write '1' to ADSC
	while(IsBitClear(ADCSRA,ADIF)); //Wait for conversion to complete
	SetPin(Pin7,PortB,Output);

	SetBit(ADCSRA,ADIF); // Clear ADIF


	return ADC; /* Read the digital value from the data register */
}



