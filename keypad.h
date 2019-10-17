 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "macros.h"
#include "registers.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 3
#define N_row 2

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT REG_PORTC
#define KEYPAD_PORT_IN  REG_PINC
#define KEYPAD_PORT_DIR REG_DDRC
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
uint8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
