/*
 * LCD.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Muhammad Al-Barbary
 */

#include "GPIO.h"
#include "CommonMacros.h"
#include "LCD.h"
#include <util/delay.h>
#include "StdTypes.h"
#include <stdlib.h>

void LCD_Init(void){
	SetPin(LCD_RSPin,LCD_RSPort,Output);
	SetPin(LCD_RWPin,LCD_RWPort,Output);
	SetPin(LCD_EPin,LCD_EPort,Output);
	SetPort(LCD_DataPort,PortOut);
	LCD_SendCommand(LCD_EightBits);
	LCD_SendCommand(LCD_CursorOff);
	LCD_SendCommand(LCD_Clear);
}

void LCD_SendCommand(uint8 command){
	WritePin(LCD_RWPin,LCD_RWPort,Low);
	WritePin(LCD_RSPin,LCD_RSPort,Low);
	_delay_ms(1);
	WritePin(LCD_EPin,LCD_EPort,High);
	_delay_ms(1);
	WritePort(LCD_DataPort,command);
	_delay_ms(1);
	WritePin(LCD_EPin,LCD_EPort,Low);
	_delay_ms(1);
}

void LCD_DisplayCharacter(uint8 data){
	WritePin(LCD_RWPin,LCD_RWPort,Low);
	WritePin(LCD_RSPin,LCD_RSPort,High);
	_delay_ms(1);
	WritePin(LCD_EPin,LCD_EPort,High);
	_delay_ms(1);
	WritePort(LCD_DataPort,data);
	_delay_ms(1);
	WritePin(LCD_EPin,LCD_EPort,Low);
	_delay_ms(1);
}

void LCD_DisplayString(const char *Str){
	uint8 i=0;
	while( Str[i]!= '\0'){
		LCD_DisplayCharacter(Str[i]);
		i++;
	}
}

void LCD_MoveCursor(uint8 row,uint8 col){
	uint8 LCD_address;
	switch(row)
		{
			case 0:
				LCD_address=col;
					break;
			case 1:
				LCD_address=col+0x40;
					break;
			case 2:
				LCD_address=col+0x10;
					break;
			case 3:
				LCD_address=col+0x50;
					break;
		}
	LCD_SendCommand(LCD_address | LCD_SetCursor);
}

void LCD_DisplayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_MoveCursor(row,col);
	LCD_DisplayString(Str);
}

void LCD_IntToStr(uint32 data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_DisplayString(buff); /* Display the string */
}

void LCD_ClearScreen(void){
	LCD_SendCommand(LCD_Clear);
}
