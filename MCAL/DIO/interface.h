/*
 * interface.h
 *
 * Created: 10/20/2023 10:53:24 AM
 *  Author: zaher
 */ 


#ifndef INTERFACE_H_
#define INTERFACE_H_


#include "../../LIB/type.h"
#include "../DIO/config.h"

#include "../DIO/config.h"

void DIO_vidset_Port_Direction (u8 copy_u8portID,u8 copy_u8PortDir);
void DIO_vidset_Port_Value (u8 copy_u8portID,u8 copy_u8Portvalue);
void DIO_vidset_Pin_Direction (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pindir);
void DIO_vidset_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8Pinvalue);
void DIO_vidGET_Pin_Value (u8 copy_u8pinID,u8 copy_u8Pinvalue,u8 *value);
void DIO_vidTogel_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID);



#endif /* INTERFACE_H_ */