/*
 * project.c
 *
 * Created: 10/20/2023 10:45:18 AM
 * Author : zaher
 */ 



#include "MCAL/DIO/Privet .h"
#include "../project/MCAL/DIO/interface.h"
#include "../project/HAL/LED/Led.h"
#include "../project/HAL/button/button.h"
#include "../project/HAL/LCD/LCD.h"
#include "../project/HAL/BCD_SEG/BCD_SEG.h"
#include "avr/delay.h"

void LEAD_TEST(void);
void button_test(void);
void SEG_TEST(void);
void SEG_TEST_BIN_AND_DIS(void);
void SEG_TEST_traffic(void);
void SEG_TEST_2counter(void);
void LCD_TEST(void);
void LCD_TEST_sin(void);
int main(void)
{
    /* Replace with your application code */
	
	
	
	
	SEG_TEST_BIN_AND_DIS();



	
	
}
void LEAD_TEST(void)
{
	
	LED_init(Green_Led_port,Green_Led_pin);
	LED_init(Yellow_Led_port,Yellow_Led_pin);
	LED_init(Red_Led_port,Red_Led_pin);
	LED_init(Blue_Led_port,Blue_Led_pin);
	
	
	while (1)
	{
		for(int x = 0 ;x<25000;x++)
		{
			LED_on(Yellow_Led_port,Yellow_Led_pin);
			LED_off(Blue_Led_port,Blue_Led_pin);
			LED_off(Green_Led_port,Green_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
		}
		for(int x = 0 ;x<25000;x++)
		{
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			LED_on(Blue_Led_port,Blue_Led_pin);
			LED_off(Green_Led_port,Green_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
		}
		
		
		for(int x = 0 ;x<25000;x++)
		{
			
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			LED_off(Blue_Led_port,Blue_Led_pin);
			LED_on(Green_Led_port,Green_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
		}
		for(int x = 0 ;x<25000;x++)
		{
			
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			LED_off(Blue_Led_port,Blue_Led_pin);
			LED_off(Green_Led_port,Green_Led_pin);
			LED_on(Red_Led_port,Red_Led_pin);
		}
		
	}
}
void button_test(void)
{
	
	LED_init(Blue_Led_port,Blue_Led_pin);
	BUTTON_init(PORT_D,pin7);
	u8 b_S;
	LED_on(Blue_Led_port,Blue_Led_pin);
	while(1)
	{
		BUTTON_read(PORT_D,pin7,&b_S);
		
		if (b_S > 0)
		{
				LED_off(Blue_Led_port,Blue_Led_pin);
			LED_on(Green_Led_port,Green_Led_pin);
		}else {
			LED_off(Green_Led_port,Green_Led_pin);
		}
	}
}
//task 3
void SEG_TEST_2counter(void)
{  
	while(1)
	{
		for(int y=0;y<10;y++)
		{
			for(int x=0;x<10;x++)
			{ for (int n=0;n<40;n++)
				{
					BCD_SEG_vidinit(COM1);
					BCD_SEG_vidWriteNumber(x);
					_delay_ms(50);
					BCD_SEG_vidinit(COM2);
					BCD_SEG_vidWriteNumber(y);
					_delay_ms(50);
					BCD_SEG_vidinit(COM3);
					BCD_SEG_vidWriteNumber(9-x);
					_delay_ms(50);
					BCD_SEG_vidinit(COM4);
					BCD_SEG_vidWriteNumber(9-y);
					_delay_ms(50);
				}
				
			}
		}
		
		
	}
}
//task 2
void SEG_TEST_traffic(void)
{
	LED_init(Green_Led_port,Green_Led_pin);
	LED_init(Yellow_Led_port,Yellow_Led_pin);
	LED_init(Red_Led_port,Red_Led_pin);
	LED_init(Blue_Led_port,Blue_Led_pin);
	while (1)
	{
		for (int x=0 ; x<=2 ; x++ )
		{
			switch(x)
			{
			case 0:
			LED_on(Yellow_Led_port,Yellow_Led_pin);
			LED_off(Green_Led_port,Green_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
			for(int i= 0 ;i<10;i++)
			{
				BCD_SEG_vidinit(COM1);
				BCD_SEG_vidWriteNumber(i);
				_delay_ms(4000);
			}
			break;
			
			case 1:
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			LED_on(Green_Led_port,Green_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
			for(int i= 0 ;i<10;i++)
			{
				BCD_SEG_vidinit(COM1);
				BCD_SEG_vidWriteNumber(i);
				_delay_ms(4000);
			}
			break;
			
			case 2:
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			
			LED_off(Green_Led_port,Green_Led_pin);
			LED_on(Red_Led_port,Red_Led_pin);
			for(int i= 0 ;i<10;i++)
			{
				BCD_SEG_vidinit(COM1);
				BCD_SEG_vidWriteNumber(i);
				_delay_ms(4000);
			}
			break;
			
			default:
			break;
			}
		}
		
		
	}
}
//task 1
void SEG_TEST_BIN_AND_DIS(void)
{
	while (1)
	{
		LED_init(Green_Led_port,Green_Led_pin);
		LED_init(Yellow_Led_port,Yellow_Led_pin);
		LED_init(Red_Led_port,Red_Led_pin);
		LED_init(Blue_Led_port,Blue_Led_pin);
		for(int i= 0 ;i<10;i++)
		{
			BCD_SEG_vidinit(COM1);
			BCD_SEG_vidWriteNumber(i);
			DIO_vidset_Pin_Value(Yellow_Led_port,Yellow_Led_pin,GET_BIT(i,3));
			DIO_vidset_Pin_Value(Blue_Led_port,Blue_Led_pin,GET_BIT(i,2));
			DIO_vidset_Pin_Value(Green_Led_port,Green_Led_pin,GET_BIT(i,1));
			DIO_vidset_Pin_Value(Red_Led_port,Red_Led_pin,GET_BIT(i,0));
			_delay_ms(6000);
		}
	}
	
}
//task 4
void LCD_TEST_sin(void)
{
	LCD_voidInt ();
	while(1)
	
	{int n=0,m=2;
		for(int x=0;x<20;x++)
		{
			if(n<4)
			{
				
				LCD_voidGoToPosition(n,x);
				LCD_voidSendData('A');
				_delay_ms(2000);
				
				n++;
			}
			else if(m >= 0)
			{
				
				LCD_voidGoToPosition(m,x);
				LCD_voidSendData('A');
				_delay_ms(2000);
				
				m--;
			}
			else
			{
				
				LCD_voidGoToPosition(1,x);
				LCD_voidSendData('A');
				_delay_ms(2000);
				
				m=2;
				n=2;
			}
			
			LCD_voidClearDisplay();
			_delay_ms(2000);
			
		}
	
	
}
}
void LCD_TEST(void)
{
	LCD_voidInt ();
	 	LCD_voidSendString("symk");
	 	LCD_voidGoToPosition(1,0);
	 	LCD_voidSendString("symk1");
	 	LCD_voidGoToPosition(2,0);
	 	LCD_voidSendString("symk2");
	 	LCD_voidGoToPosition(3,0);
	 	LCD_voidSendString("symk3");
}
