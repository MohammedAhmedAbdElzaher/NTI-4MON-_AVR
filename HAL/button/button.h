/*
 * button.h
 *
 * Created: 10/21/2023 1:17:35 AM
 *  Author: zaher
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO/interface.h"
#include "../../MCAL/DIO/Privet .h"
#include "../button/BUTTON_config.h"




// initialize

 void BUTTON_init(u8 buttonPort, u8 buttonPin);

// button read

 void BUTTON_read(u8 buttonPort, u8 buttonPin, u8 *value);

void button_test(void);


#endif /* BUTTON_H_ */