/*
 * Led.h
 *
 * Created: 10/20/2023 9:32:39 PM
 *  Author: zaher
 */ 


#ifndef LED_H_
#define LED_H_




#include "../../MCAL/DIO/interface.h"
#include "../../MCAL/DIO/Privet .h"
#include "../../LIB/bit math.h"



// Three LEDs for cars
#define Green_Led_port PORT_A
#define Green_Led_pin  pin4
#define Yellow_Led_port PORT_A
#define Yellow_Led_pin  pin6
#define Red_Led_port PORT_B
#define Red_Led_pin  pin7
#define Blue_Led_port PORT_A
#define Blue_Led_pin  pin5

// internal driver typedefs


void LED_init(u8 ledPort, u8 ledPin);

void LED_on(u8 ledPort, u8 ledPin);

void LED_off (u8 ledPort, u8 ledPin);

void LED_toggle(u8 ledPort, u8 ledPin);

void LED_test(void);





#endif /* LED_H_ */