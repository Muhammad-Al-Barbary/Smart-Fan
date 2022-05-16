/*
 * ADC.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Muhammad Al-Barbary
 */


#ifndef ADC_H_
#define ADC_H_

#include "StdTypes.h"

//definitions
#define ADC_MaxValue    1023
#define ADC_Volt     2.56

//typedef
typedef enum  { AREF,AVCC,Internal=3}ADC_ReferenceVoltage;
typedef enum  {DF2,DF4=2,DF8,DF16,DF32,DF64,DF128}ADC_Prescaler;
typedef struct{
ADC_ReferenceVoltage RefVolt;
ADC_Prescaler Prescaler;
}ADC_ConfigType;

//functions
void ADC_Init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_ReadChannel(uint8 Channel);

#endif /* ADC_H_ */
