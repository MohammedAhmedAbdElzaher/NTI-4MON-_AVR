/*
 * BCD_SEG.c
 *
 * Created: 10/21/2023 6:46:17 AM
 *  Author: zaher
 */ 

#include "../../LIB/bit math.h"
#include "../../LIB/type.h"
#include "../../MCAL/DIO/interface.h"
#include "../../MCAL/DIO/Privet .h"
#include "../BCD_SEG/BCD_SEG.h"
void BCD_SEG_vidinit(u8 com_type)
{
	switch(com_type)
	{
		case COM1:
		DIO_vidset_Pin_Direction(PORT_A,pin3,OUT);
		DIO_vidset_Pin_Direction(PORT_A,pin2,IN);
		DIO_vidset_Pin_Direction(PORT_B,pin5,IN);
		DIO_vidset_Pin_Direction(PORT_B,pin6,IN);


		
		break;
		case COM2:
		DIO_vidset_Pin_Direction(PORT_A,pin3,IN);
		DIO_vidset_Pin_Direction(PORT_A,pin2,OUT);
		DIO_vidset_Pin_Direction(PORT_B,pin5,IN);
		DIO_vidset_Pin_Direction(PORT_B,pin6,IN);
		 
		break;

		case COM3: 
		DIO_vidset_Pin_Direction(PORT_A,pin3,IN);
		DIO_vidset_Pin_Direction(PORT_A,pin2,IN);
		DIO_vidset_Pin_Direction(PORT_B,pin5,OUT);
		DIO_vidset_Pin_Direction(PORT_B,pin6,IN);
	
		break;

		case COM4: 
		DIO_vidset_Pin_Direction(PORT_A,pin3,IN);
		DIO_vidset_Pin_Direction(PORT_A,pin2,IN);
		DIO_vidset_Pin_Direction(PORT_B,pin5,IN);
		DIO_vidset_Pin_Direction(PORT_B,pin6,OUT);
		
		break;
	}
	DIO_vidset_Pin_Direction(BCD_PORT,BCD_PIN0,OUT);
	DIO_vidset_Pin_Direction(BCD_PORT,BCD_PIN1,OUT);
	DIO_vidset_Pin_Direction(BCD_PORT,BCD_PIN2,OUT);
	DIO_vidset_Pin_Direction(BCD_PORT,BCD_PIN4,OUT);
}
void BCD_SEG_vidWriteNumber(u8 Copy_u8Number)
{
	DIO_vidset_Pin_Value(BCD_PORT,BCD_PIN0,GET_BIT(Copy_u8Number,0));
	DIO_vidset_Pin_Value(BCD_PORT,BCD_PIN1,GET_BIT(Copy_u8Number,1));
	DIO_vidset_Pin_Value(BCD_PORT,BCD_PIN2,GET_BIT(Copy_u8Number,2));
	DIO_vidset_Pin_Value(BCD_PORT,BCD_PIN4,GET_BIT(Copy_u8Number,3));
}