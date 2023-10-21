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


#define BUTTON_PORT PORT_D
#define BUTTON_PIN  pin7
//button stat
#define button_stat_HIGH 1
#define button_stat_LOW  0



// initialize

 void BUTTON_init(u8 buttonPort, u8 buttonPin);

// button read

 void BUTTON_read(u8 buttonPort, u8 buttonPin, u8 *value);

void button_test(void);


#endif /* BUTTON_H_ */