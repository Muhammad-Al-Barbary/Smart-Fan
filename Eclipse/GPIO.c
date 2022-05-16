/*
 * GPIO.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Muhammad Al-Barbary
 */
#include "GPIO.h"
#include "CommonMacros.h"
#include "avr/io.h"
#include <util/delay.h>


void SetPin(uint8 Pin, uint8 Port, PinDirection Direction){
	if( (Pin >= PinsNum) || (Port >= PortsNum) )
		{
			/* Do Nothing */
		}

	else {
			switch (Port){
			case PortA :
				if (Direction==Input)
					ClearBit(DDRA,Pin);
				else
					SetBit(DDRA,Pin);
				break;

			case PortB :
				if (Direction==Input)
					ClearBit(DDRB,Pin);
				else
					SetBit(DDRB,Pin);
				break;

			case PortC :
				if (Direction==Input)
					ClearBit(DDRC,Pin);
				else
					SetBit(DDRC,Pin);
				break;

			case PortD :
				if (Direction==Input)
					ClearBit(DDRD,Pin);
				else
					SetBit(DDRD,Pin);
				break;

			}


	}

}



void WritePin(uint8 Pin, uint8 Port, uint8 Value){
	if( (Pin >= PinsNum) || (Port >= PortsNum) )
		{
			/* Do Nothing */
		}

	else {
			switch (Port){
			case PortA :
				if (Value==Low)
					ClearBit(PORTA,Pin);
				else
					SetBit(PORTA,Pin);
				break;

			case PortB :
				if (Value==Low)
					ClearBit(PORTB,Pin);
				else
					SetBit(PORTB,Pin);
				break;


			case PortC :
				if (Value==Low)
					ClearBit(PORTC,Pin);
				else
					SetBit(PORTC,Pin);
				break;


			case PortD :
				if (Value==Low)
					ClearBit(PORTD,Pin);
				else
					SetBit(PORTD,Pin);
				break;

			}


	}

}


uint8 ReadPin(uint8 Pin, uint8 Port){
	if( (Pin >= PinsNum) || (Port >= PortsNum) )
		{
			return Low;
		}

	else {
			switch (Port){
			case PortA :
				if ( IsBitSet(PINA,Pin) )
					return High;
				else
					return Low;
				break;

			case PortB :
				if ( IsBitSet(PINB,Pin) )
					return High;
				else
					return Low;
				break;

			case PortC :
				if ( IsBitSet(PINC,Pin) )
					return High;
				else
					return Low;
				break;


			case PortD :
				if ( IsBitSet(PIND,Pin) )
					return High;
				else
					return Low;
				break;

			default:
				return Low;
				break;
			}


	}

}



void SetPort (uint8 Port, PortDirection Direction){
	switch (Port) {
	case PortA:
		DDRA=Direction;
		break;
	case PortB:
		DDRB=Direction;
		break;
	case PortC:
		DDRC=Direction;
		break;
	case PortD:
		DDRD=Direction;
		break;
	default:
		break;

	}

}



void WritePort (uint8 Port, uint8 Value){
	switch (Port) {
	case PortA:
		PORTA=Value;
		break;
	case PortB:
		PORTB=Value;
		break;
	case PortC:
		PORTC=Value;
		break;
	case PortD:
		PORTD=Value;
		break;
	default:
		break;

	}

}


uint8 ReadPort (uint8 Port){
	switch (Port) {
	case PortA:
		return PINA;
		break;
	case PortB:
		return PINB;
		break;
	case PortC:
		return PINC;
		break;
	case PortD:
		return PIND;
		break;
	default:
		return Low;
		break;

	}

}
