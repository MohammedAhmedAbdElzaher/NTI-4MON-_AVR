/*
 * BUTTON_config.h
 *
 * Created: 10/23/2023 4:35:46 AM
 *  Author: zaher
 */ 


#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_



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
// button port&pin
#define BUTTON_PORT PORT_D
#define BUTTON_1_PIN  pin7
#define BUTTON_2_PIN  pin6
#define BUTTON_3_PIN  pin5

#endif /* BUTTON_CONFIG_H_ */