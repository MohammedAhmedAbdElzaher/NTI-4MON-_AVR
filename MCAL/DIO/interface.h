/*
 * interface.h
 *
 * Created: 10/20/2023 10:53:24 AM
 *  Author: zaher
 */ 


#ifndef interface_h_
#define interface_h_
#include "../../LIB/type.h"

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




void DIO_vidset_Port_Direction (u8 copy_u8portID,u8 copy_u8PortDir);
void DIO_vidset_Port_Value (u8 copy_u8portID,u8 copy_u8Portvalue);
void DIO_vidset_Pin_Direction (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pindir);
void DIO_vidset_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8Pinvalue);
void DIO_vidGET_Pin_Value (u8 copy_u8pinID,u8 copy_u8Pinvalue,u8 *value);
void DIO_vidTogel_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID);








#endif