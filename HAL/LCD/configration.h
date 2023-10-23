/*
 * configration.h
 *
 * Created: 10/21/2023 11:48:19 AM
 *  Author: zaher
 */ 


#ifndef CONFIGRATION_H_
#define CONFIGRATION_H_
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
// LCD pin mode
#define LCD_MODE         	_4_BIT_MODE
// LCD DATA port &pin
#define LCD_DATA_PORT    	PORT_B

#define LCD_DATA_PIN_4   	pin0
#define LCD_DATA_PIN_5	 	pin1
#define LCD_DATA_PIN_6	 	pin2
#define LCD_DATA_PIN_7	 	pin4

// LCD control port and pin
#define LCD_CONTROL_PORT    PORT_A

#define LCD_RS_PIN       	pin3
#define LCD_EN_PIN       	pin2



#endif /* CONFIGRATION_H_ */