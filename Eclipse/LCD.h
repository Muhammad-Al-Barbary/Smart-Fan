/*
 * LCD.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Muhammad Al-Barbary
 */

#ifndef LCD_H_
#define LCD_H_

#include "StdTypes.h"

//definitions

// Pins
#define LCD_RSPort                    PortD
#define LCD_RSPin                     Pin0

#define LCD_RWPort                    PortD
#define LCD_RWPin                     Pin1

#define LCD_EPort                     PortD
#define LCD_EPin                      Pin2

#define LCD_DataPort                  PortC

// Commands
#define LCD_Clear                      0x01
#define LCD_Home                       0x02
#define LCD_EightBits                  0x38
#define LCD_FourBits                   0x28
#define LCD_CursorOff                  0x0C
#define LCD_CursorOn                   0x0E
#define LCD_SetCursor                  0x80



//Functions Prototypes

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_Init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_SendCommand(uint8 command);



/*
 * Description :
 * Display the required character on the screen
 */
void LCD_DisplayCharacter(uint8 data);



/*
 * Description :
 * Display the required string on the screen
 */
void LCD_DisplayString(const char *Str);



/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_MoveCursor(uint8 row,uint8 col);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_IntToStr(uint32 data);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_DisplayStringRowColumn(uint8 row,uint8 col,const char *Str);




/*
 * Description :
 * Send the clear screen command
 */
void LCD_ClearScreen(void);

#endif /* LCD_H_ */
