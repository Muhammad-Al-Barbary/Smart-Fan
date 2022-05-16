/*
 * CommonMacros.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Muhammad Al-Barbary
 */

#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_

// Set a certain bit in any register
#define SetBit(REG,BIT) (REG|=(1<<BIT))

// Clear a certain bit in any register
#define ClearBit(REG,BIT) (REG&=(~(1<<BIT)))

// Toggle a certain bit in any register
#define ToggleBit(REG,BIT) (REG^=(1<<BIT))

// Rotate right the register value with specific number of rotates
#define ShiftRight(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

// Rotate left the register value with specific number of rotates
#define ShiftLeft(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

// Check if a specific bit is set in any register and return true if yes
#define IsBitSet(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define IsBitClear(REG,BIT) ( !(REG & (1<<BIT)) )


#endif /* COMMONMACROS_H_ */
