/*
 * config.h
 *
 * Created: 10/22/2023 9:36:32 AM
 *  Author: zaher
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_
#include "../../LIB/type.h"
#include "../../MCAL/DIO/config.h"

#include "../../MCAL/DIO/interface.h"
#include "../../MCAL/DIO/config.h"

// driver macros
#define PORT_A (0x01)

#define PORT_B (0x02)

#define PORT_C (0x03)

#define PORT_D (0x04)

#define  PORT_OUT (0xff)

#define  PORT_IN (0x00)

//direction def
#define IN 0

#define OUT 1

//value def
#define LOW 0

#define HIGH 1

// pin def
#define pin0 (0x00)
#define pin1 (0x01)
#define pin2 (0x02)
#define pin3 (0x03)
#define pin4 (0x04)
#define pin5 (0x05)
#define pin6 (0x06)
#define pin7 (0x07)

// keyPad port dif
#define Keypad_ROW_PORT PORT_C
#define Keypad_COL_PORT PORT_D
#define  Keypad_PORT_ROW_COL {PORT_C,PORT_D};

// keyPad pin dif
//row
#define Keypad_ROW_1_PIN pin5
#define Keypad_ROW_2_PIN pin4
#define Keypad_ROW_3_PIN pin3
#define Keypad_ROW_4_PIN pin2
u8 keyPad_ROW_PIN[4]={pin5,pin4,pin3,pin2};
//col
#define Keypad_COL_1_PIN pin7
#define Keypad_COL_2_PIN pin6
#define Keypad_COL_3_PIN pin5
#define Keypad_COL_4_PIN pin3
u8 keyPad_COL_PIN[4]={pin7,pin6,pin5,pin3};
	
// ARR_DATA


	#define ARR_DATA {{7,8,9,'x'},{4,5,6,'/'},{1,2,3,'+'},{'c',0,'=','-'}}





#endif /* CONFIG_H_ */