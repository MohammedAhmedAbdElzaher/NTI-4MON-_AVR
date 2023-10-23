/*
 * Dio.c
 *
 * Created: 10/20/2023 10:53:07 AM
 *  Author: zaher
 */ 
#ifndef Prog_H_
#define Prog_H_
#include "../DIO/Privet .h"
#include "interface.h"
#include "../../LIB/type.h"
#include "../../LIB/bit math.h"

// choose the direction of the port out or in
void DIO_vidset_Port_Direction (u8 copy_u8portID,u8 copy_u8PortDir)
{
			switch(copy_u8portID) {

				case PORT_A:
				DDR_A = copy_u8PortDir;
				break;
				case PORT_B:
				DDR_B = copy_u8PortDir;
				break;
				case PORT_C:
				DDR_C = copy_u8PortDir;
				break;
				case PORT_D:
				DDR_D = copy_u8PortDir;
				break;
				default:
				break;
			}
				

				
}

// choose the value of the port 0 or 1
void DIO_vidset_Port_Value (u8 copy_u8portID,u8 copy_u8Portvalue)
{
		switch(copy_u8portID) {

			case PORT_A:
			PORTA_REG = copy_u8Portvalue;
			break;
			case PORT_B:
			PORTB_REG = copy_u8Portvalue;
			break;
			case PORT_C:
			PORTC_REG = copy_u8Portvalue;
			break;
			case PORT_D:
			PORTD_REG = copy_u8Portvalue;
			break;
			default:
			break;
		}
}

// choose the direction of the pin out or in
void DIO_vidset_Pin_Direction (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pindir)
{
	if(copy_u8pindir == OUT && copy_u8pinID <= pin7)
	{
		switch(copy_u8portID)
		{
			case PORT_A:
			SET_BIT(DDR_A,copy_u8pinID);
			break;
			
			case PORT_B:
			SET_BIT(DDR_B,copy_u8pinID);
			break;
			
			case PORT_C:
			SET_BIT(DDR_C,copy_u8pinID);
			break;
			
			case PORT_D:
			SET_BIT(DDR_D,copy_u8pinID);
			break;
			default:
			break;
			
			
		}
		
	}
	else if(copy_u8pindir == IN && copy_u8pinID <= pin7)
	{
		switch(copy_u8portID)
		{
			case PORT_A:
			CLEAR_BIT(DDR_A,copy_u8pinID);
			break;
			
			case PORT_B:
			CLEAR_BIT(DDR_B,copy_u8pinID);
			break;
			
			case PORT_C:
			CLEAR_BIT(DDR_C,copy_u8pinID);
			break;
			
			case PORT_D:
			CLEAR_BIT(DDR_D,copy_u8pinID);
			break;
			default:
			break;
	
}
	}
}

// choose the value of the pin 0 or 1
void DIO_vidset_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8Pinvalue)
{
	
	if(copy_u8Pinvalue > 0x00 && copy_u8pinID <= pin7)
	{
		switch(copy_u8portID)
		{
			case PORT_A:
			SET_BIT(PORTA_REG,copy_u8pinID);
			break;
			
			case PORT_B:
			SET_BIT(PORTB_REG,copy_u8pinID);
			break;
			
			case PORT_C:
			SET_BIT(PORTC_REG,copy_u8pinID);
			break;
			
			case PORT_D:
			SET_BIT(PORTD_REG,copy_u8pinID);
			break;
			default:
			break;
			
			
		}
		
		
	}
	
	 if(copy_u8Pinvalue == 0x00 && copy_u8pinID <= pin7)
	{
		switch(copy_u8portID)
		{
			case PORT_A:
			CLEAR_BIT(PORTA_REG,copy_u8pinID);
			break;
			
			case PORT_B:
			CLEAR_BIT(PORTB_REG,copy_u8pinID);
			break;
			
			case PORT_C:
			CLEAR_BIT(PORTC_REG,copy_u8pinID);
			break;
			
			case PORT_D:
			CLEAR_BIT(PORTD_REG,copy_u8pinID);
			break;
			default:
			break;
			
			
		}
		
		
	}
	
}
	
	// read the value of the pin 0 or 1
void DIO_vidGET_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID,u8 *value)
{
	
	if( copy_u8pinID <= pin7)
	{
		switch(copy_u8portID)
		{
			case PORT_A:
			*value=GET_BIT(PIN_A,copy_u8pinID);
			break;
			
			case PORT_B:
			*value=GET_BIT(PIN_B,copy_u8pinID);
			break;
			
			case PORT_C:
			*value=GET_BIT(PIN_C,copy_u8pinID);
			break;
			
			case PORT_D:
			*value=GET_BIT(PIN_D,copy_u8pinID);
			break;
			default:
			break;
			
			
		}
		
	}
}

// togel the value of the pin 0 or 1
void DIO_vidTogel_Pin_Value (u8 copy_u8portID,u8 copy_u8pinID)
{
	if( copy_u8pinID <=pin7)
	{
		switch(copy_u8portID)
		{
			case PORT_A:
			TOGG_BIT(PORTA_REG,copy_u8pinID);
			break;
			
			case PORT_B:
			TOGG_BIT(PORTB_REG,copy_u8pinID);
			break;
			
			case PORT_C:
			TOGG_BIT(PORTC_REG,copy_u8pinID);
			break;
			
			case PORT_D:
			TOGG_BIT(PORTD_REG,copy_u8pinID);
			break;
			default:
			break;
			
			
		}
		
	}
}



#endif