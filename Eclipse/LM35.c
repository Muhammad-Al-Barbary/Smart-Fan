/*
 * LM35.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Muhammad Al-Barbary
 */

#include "ADC.h"
#include "LM35.h"



uint8 LM35_GetTemp(){

	uint8 Temp = 0;
    uint16 ADC = ADC_ReadChannel(2);

	Temp=(uint8)(((uint32)ADC*LM35_MaxTemp*ADC_Volt)/(ADC_MaxValue*LM35_MaxVolt));

	return Temp;
}


