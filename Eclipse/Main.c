/*
 ===================================================================================================
 Filename        : Main.c
 Author      : Muhammad Al-Barbary
 Description : Automatic temperature-controlled fan with an LCD display
 Date        : 17/10/2021
 ===================================================================================================
 */

#include "LM35.h"
#include "StdTypes.h"
#include "MOTOR.h"
#include "LCD.h"
#include "GPIO.h"
#include "ADC.h"
#include <util/delay.h>

int main (){
	uint8 Temp; /*variable to carry the temperature value the sensor measures*/
	uint8 state; /*fan state is on (1) or off (1)*/
	MOTOR_Init(); /* initialize the motor*/
	LCD_Init(); /* initialize the LCD*/
	ADC_ConfigType ADC_Config = {Internal,DF8}; /*choose adc voltage and prescaler*/
	ADC_Init(&ADC_Config); /* initialize the adc*/
	_delay_ms(300); /*delay for the circuit to be ready to work*/
	while(1){

		Temp=LM35_GetTemp(); /*measure the temperature value*/
		/* the following block controls the fan speed depending on the temperature*/
		if (Temp<30){
			MOTOR_Rotate(Stop,0); /*If the temperature is less than 30C turn off the fan*/
			state=0;
		}

		else if (Temp>=30 && Temp<60){ /*If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed*/
			MOTOR_Rotate(CW,25);
			state=1;
		}

		else if (Temp>=60 && Temp<90){/*If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed*/
				MOTOR_Rotate(CW,50);
				state=1;
		}

		else if (Temp>=90 && Temp<120){ /*If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed*/
				MOTOR_Rotate(CW,75);
				state=1;
		}
		else{
			MOTOR_Rotate(CW,100);/*If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed*/
			state=1;
		}


		/*the following block displays data on LCD*/
		switch(state){
		case 0:	LCD_DisplayStringRowColumn(0,3,"Fan is OFF"); /* Display the fan state on first row*/
				break;
		case 1: LCD_DisplayStringRowColumn(0,3,"Fan is ON ");
				break;
		}
		LCD_DisplayStringRowColumn(1,3,"Temp = "); /*Display the temperature on second row*/
		LCD_IntToStr(Temp);

		/* two if conditions to clear the extra digits on LCD in case the
		   number of digits of temperature decreased
		   (example: temperature was 100 then decreased to 99)*/
		if(Temp<10)
							LCD_DisplayStringRowColumn(1,11," ");
		if(Temp<100)
			LCD_DisplayStringRowColumn(1,12," ");

		LCD_DisplayString("C");
	}
}
