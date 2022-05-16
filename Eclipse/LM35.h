/*
 * LM35.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Muhammad Al-Barbary
 */

#ifndef LM35_H_
#define LM35_H_

#include "StdTypes.h"

//definitions
#define LM35_Channel 2
#define LM35_MaxVolt 1.5
#define LM35_MaxTemp 150

//functions
uint8 LM35_GetTemp();

#endif /* LM35_H_ */
