/*
 * LCD.c
 *
 * Created: 10/21/2023 11:34:22 AM
 *  Author: zaher
 */ 
#include "../../LIB/type.h"
#include "../../LIB/bit math.h"
#include "LCD.h"
#include "avr/delay.h"
#include "configration.h"
#include "../../MCAL/DIO/interface.h"

void LCD_voidInt(void)
{
	DIO_vidset_Pin_Direction(LCD_CONTROL_PORT,LCD_EN_PIN,OUT);
	DIO_vidset_Pin_Direction(LCD_CONTROL_PORT,LCD_RS_PIN,OUT);
	
	DIO_vidset_Pin_Direction(LCD_DATA_PORT,LCD_DATA_PIN_4,OUT);
	DIO_vidset_Pin_Direction(LCD_DATA_PORT,LCD_DATA_PIN_5,OUT);
	DIO_vidset_Pin_Direction(LCD_DATA_PORT,LCD_DATA_PIN_6,OUT);
	DIO_vidset_Pin_Direction(LCD_DATA_PORT,LCD_DATA_PIN_7,OUT);
	_delay_ms(100);
	LCD_voidsendcommand(0x33);		   /*select 4-bit Mode*/
	LCD_voidsendcommand(0x32);
	LCD_voidsendcommand(0x28);
	
	LCD_voidsendcommand(0x0c);		   
	LCD_voidsendcommand(0x02);
	LCD_voidsendcommand(0x01);
		LCD_voidsendcommand(0x06);

	
	
}
void LCD_voidsendcommand(u8 copy_u8cmd)
{DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(copy_u8cmd,4));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(copy_u8cmd,5));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(copy_u8cmd,6));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(copy_u8cmd,7));

	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH); //EN
	_delay_ms(2);
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(copy_u8cmd,0));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(copy_u8cmd,1));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(copy_u8cmd,2));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(copy_u8cmd,3));
	
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH); //EN
	_delay_ms(2);
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
	
}
void LCD_voidSendData(u8 copy_u8data)
{DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(copy_u8data,4));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(copy_u8data,5));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(copy_u8data,6));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(copy_u8data,7));

	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH); //EN
	_delay_ms(2);
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(copy_u8data,0));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(copy_u8data,1));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(copy_u8data,2));
	DIO_vidset_Pin_Value(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(copy_u8data,3));
	
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH); //EN
	_delay_ms(2);
	DIO_vidset_Pin_Value(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
}
void LCD_voidClearDisplay(void)
{
	LCD_voidsendcommand (0x01);
}
void LCD_voidSendString(u8 *Ptr_u8PtrString)
{
	while(*Ptr_u8PtrString != 0)
	{
		LCD_voidSendData(*Ptr_u8PtrString);
		Ptr_u8PtrString++;
	}
}
void LCD_voidGoToPosition(u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	u8 arr[4] ={0x80,0xC0,0x94,0xD4};
	LCD_voidsendcommand(arr[Copy_u8RowNum] + Copy_u8ColNum);
}
void LCD_voidDisplayNumber(s32 Copy_s32Number)
{
	if(Copy_s32Number == 0)
	{
		LCD_voidSendData('0');
	}
	else if(Copy_s32Number > 0  )
	{
		s8 i=0;
		u8 Copy_u8Remander = 0;
		u8 arr[10] = {0};
		while(Copy_s32Number != 0)
		{
			Copy_u8Remander = Copy_s32Number % 10;
			arr[i] = Copy_u8Remander;
			i++;
			Copy_s32Number /= 10;
		}
		i--;
		while(i >= 0)
		{
			LCD_voidSendData(arr[i] + 48);
			i--;
		}
		
	}
}
void LCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_voidGoToPosition( Copy_u8RowNum, Copy_u8ColNum);
	LCD_voidSendData(CGRam_index);
	u8 Local_u8address;
	u8 Local_u8Index;
	if (CGRam_index < 8)
	{
		Local_u8address= CGRam_index * 8;
		Local_u8address=SET_BIT(Local_u8address,6);
		LCD_voidsendcommand(Local_u8address);
		for(Local_u8Index = 0;Local_u8Index < 8;Local_u8Index++)
		{
			LCD_voidSendData(Ptr_u8PtrChar[Local_u8Index]);
		}
	}
	LCD_voidsendcommand(0x02);
}

