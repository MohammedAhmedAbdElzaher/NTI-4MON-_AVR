/*
 * keypad_interfaces.h
 *
 * Created: 10/22/2023 9:38:58 AM
 *  Author: zaher
 */ 


#ifndef KEYPAD_INTERFACES_H_
#define KEYPAD_INTERFACES_H_

#include "../../LIB/bit math.h"
#include "../../LIB/type.h"
#include "../Keypad/config.h"
void KeyPad_INT(void);
u8  KeyPad_READ(void);


#endif /* KEYPAD_INTERFACES_H_ */