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
void KEYBAD_TEST(void);
void KEYBAD_LCD_TEST(void);
void KEYBAD_calc_TEST(void);
void KEYBAD_NAME_SW_TEST(void);




int main(void)
{
    /* Replace with your application code */
	
	
	
	
	KEYBAD_NAME_SW_TEST();



	
	
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
	LED_init(Green_Led_port,Green_Led_pin);
	LED_init(Yellow_Led_port,Yellow_Led_pin);
	LED_init(Red_Led_port,Red_Led_pin);

	BUTTON_init(BUTTON_PORT,BUTTON_1_PIN);
	BUTTON_init(BUTTON_PORT,BUTTON_2_PIN);
	BUTTON_init(BUTTON_PORT,BUTTON_3_PIN);
	u8 b_S_1=0,b_S_2=0,b_S_3=0;
	LED_on(Blue_Led_port,Blue_Led_pin);
	while(1)
	{
		BUTTON_read(BUTTON_PORT,BUTTON_1_PIN,&b_S_1);
		_delay_ms(50);
		BUTTON_read(BUTTON_PORT,BUTTON_2_PIN,&b_S_2);
		_delay_ms(50);
		BUTTON_read(BUTTON_PORT,BUTTON_3_PIN,&b_S_3);
		_delay_ms(50);
		
		LED_on(Blue_Led_port,Blue_Led_pin);
		if (b_S_1 == 0)
		{
			LED_off(Blue_Led_port,Blue_Led_pin);
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
			LED_on(Green_Led_port,Green_Led_pin);
		} if (b_S_2 == 0){
			LED_off(Blue_Led_port,Blue_Led_pin);
			LED_on(Yellow_Led_port,Yellow_Led_pin);
			LED_off(Red_Led_port,Red_Led_pin);
			LED_off(Green_Led_port,Green_Led_pin);
		} if (b_S_3 == 0)
		{
			LED_off(Blue_Led_port,Blue_Led_pin);
			LED_off(Yellow_Led_port,Yellow_Led_pin);
			LED_on(Red_Led_port,Red_Led_pin);
			LED_off(Green_Led_port,Green_Led_pin);
		}
		else {
			LED_on(Blue_Led_port,Blue_Led_pin);
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
void KEYBAD_TEST(void)
{
	LCD_voidInt ();
	KeyPad_INT();
	LCD_voidSendString("start///////");
	u8 v=0;
	while(1)
	{
	 v=KeyPad_READ();
	 
	if(v>0)
	{
		LCD_voidDisplayNumber(v);
		v=0;
	}
	//_delay_ms(1000);
	}
}
void KEYBAD_LCD_TEST (void)
{
	
	KeyPad_INT();
	u8 v=5;
	
	while(1)
	{
		v=KeyPad_READ();
		
		BCD_SEG_vidWriteNumber(v);
		//_delay_ms(1000);
	}
}
void KEYBAD_calc_TEST(void)
{
	LCD_voidInt ();
	KeyPad_INT();
	LCD_voidGoToPosition(0,5);
	LCD_voidSendString("CALC");
	u8 v=0,NUM_t1=0,x=0,NUM_t2=0,y=1,op=0;
	u8 ANS=0;
	while(1)
	{
		v=KeyPad_READ();
		if (x==0 && v<=9)
		{
			NUM_t1=v;
			x=1;
		}if (x==1 && v<=9)
		{
			NUM_t2=v;
			x=0;
		}
		
		
		if(v=='/'||v=='x'||v=='+'||v=='-')
		{
			LCD_voidSendData(v);
			op=v;
			
		}
		else if (v =='=')
		{
			LCD_voidSendData(v);
			LCD_voidDisplayNumber(ANS);
			ANS=0;
			
			

	}else if (v =='c')
	{
		
		LCD_voidClearDisplay();
		LCD_voidGoToPosition(0,5);
		LCD_voidSendString("CALC");
		LCD_voidGoToPosition(1,6);
		

	}else if (v != 15)
		{
			LCD_voidDisplayNumber(v);
		}
		switch (op)
		{
			
			case '+':
			ANS=NUM_t1 + NUM_t2;
			op=0;
			break;
			
			case '-':
			ANS=NUM_t1 - NUM_t2;
			op=0;
			break;
			
			case 'x':
			ANS=NUM_t1 * NUM_t2;
			op=0;
			break;
			
			case '/':
			ANS=NUM_t1 / NUM_t2;
			op=0;
			break;
			
			default:
			
			break;
		}
		
		
		
	}
}
void KEYBAD_NAME_SW_TEST(void)
{
	u8 v=0;
	
	LCD_voidInt ();
	KeyPad_INT();
	
	while(1)
	{
		v=KeyPad_READ();
		if (v != 15 )
		{
			switch (v)
			{
				case 1:
				LCD_voidGoToPosition(0,0);
				LCD_voidSendString("Mohammed");
				break;
				
				case 4:
				LCD_voidGoToPosition(1,0);
				LCD_voidSendString("Ahmed");
				break;
				
				case 7:
				LCD_voidGoToPosition(2,0);
				LCD_voidSendString("Abd Elzaher");
				break;
				
				case 'c':
				LCD_voidClearDisplay();
				break;
				default:
				break;
				
				
			}
		}
	}
}


