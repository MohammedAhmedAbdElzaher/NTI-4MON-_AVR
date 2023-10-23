/*
 * Prog.c
 *
 * Created: 10/22/2023 9:36:11 AM
 *  Author: zaher
 */ 
#include "../Keypad/keypad_interfaces.h"
#include "avr/delay.h"
// key
void KeyPad_INT(void)
{
	for(int i=0;i<4;i++)
	{
		DIO_vidset_Pin_Direction(Keypad_ROW_PORT,keyPad_ROW_PIN[i],OUT);
	}
	for(int i=0;i<4;i++)
	{
		DIO_vidset_Pin_Direction(Keypad_COL_PORT,keyPad_COL_PIN[i],IN);
	}
	for(int i=0;i<4;i++)
	{
		DIO_vidset_Pin_Value(Keypad_ROW_PORT,keyPad_ROW_PIN[i],HIGH);
	}
	for(int i=0;i<4;i++)
	{
		DIO_vidset_Pin_Value(Keypad_COL_PORT,keyPad_COL_PIN[i],HIGH);
	}
}
u8  KeyPad_READ(void)
{ u8 dip_value_col = 1;
	u8 data_out[4][4]=ARR_DATA;
	u8 Value=15;
	for(u8 i=0;i<=3;i++)
	{
		DIO_vidset_Pin_Value(Keypad_ROW_PORT,keyPad_ROW_PIN[i],LOW);
		for(u8 j=0;j<=3;j++)
		{
			DIO_vidGET_Pin_Value(Keypad_COL_PORT,keyPad_COL_PIN[j],&dip_value_col);
			//_delay_ms(40);
			if(dip_value_col==0)
			{
				Value=data_out[i][j];
				while(dip_value_col==0)
				{
					DIO_vidGET_Pin_Value(Keypad_COL_PORT,keyPad_COL_PIN[j],&dip_value_col);
				}
			}
			
		}
		DIO_vidset_Pin_Value(Keypad_ROW_PORT,keyPad_ROW_PIN[i],HIGH);
	}
	if (Value != 15)
	{
	return Value;
	}
}