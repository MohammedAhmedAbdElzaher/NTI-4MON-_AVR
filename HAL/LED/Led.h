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
#include "../LED/Ied_config.h"

// internal driver typedefs


void LED_init(u8 ledPort, u8 ledPin);

void LED_on(u8 ledPort, u8 ledPin);

void LED_off (u8 ledPort, u8 ledPin);

void LED_toggle(u8 ledPort, u8 ledPin);

void LED_test(void);





#endif /* LED_H_ */