/*
 * Privet_.h
 *
 * Created: 10/20/2023 11:59:10 AM
 *  Author: zaher
 */ 

#ifndef Privet_H_
#define Privet_H_
#include "../../LIB/type.h"

#define DDR_A *((volatile u8*)0x3A)
#define PORTA_REG *((volatile u8*)0x3B)
#define PIN_A  *((volatile u8*)0x39)

#define DDR_B *((volatile u8*)0x37)
#define PORTB_REG *((volatile u8*)0x38)
#define PIN_B  *((volatile u8*)0x36)

#define DDR_C *((volatile u8*)0x34)
#define PORTC_REG *((volatile u8*)0x35)
#define PIN_C  *((volatile u8*)0x33)

#define DDR_D *((volatile u8*)0x31)
#define PORTD_REG *((volatile u8*)0x32)
#define PIN_D  *((volatile u8*)0x30)

#endif /* Privet_.h */