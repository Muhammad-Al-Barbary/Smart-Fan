/*
 * GPIO.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Muhammad Al-Barbary
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "StdTypes.h"

//bits and ports
#define PortsNum 4
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define PinsNum 8
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

//typedef
typedef enum  { Input,Output }PinDirection;
typedef enum  { PortIn,PortOut=0xFF }PortDirection;

//functions prototypes
void SetPin (uint8 Pin, uint8 Port, PinDirection Direction);
void WritePin (uint8 Pin, uint8 Port, uint8 Value);
uint8 ReadPin(uint8 Pin, uint8 Port);

void SetPort (uint8 Port, PortDirection Direction);
void WritePort (uint8 Port, uint8 Value);
uint8 ReadPort(uint8 Port);



#endif /* GPIO_H_ */
