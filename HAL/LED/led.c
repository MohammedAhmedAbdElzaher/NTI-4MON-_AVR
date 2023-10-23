/*
 * led.c
 *
 * Created: 10/20/2023 9:41:31 PM
 *  Author: zaher
 */ 
#include "../LED/Led.h"

//the led on function is used to choose led  pin direction using dio
void LED_init(u8 ledPort, u8 ledPin)
{
	 DIO_vidset_Pin_Direction (ledPort ,ledPin,OUT);
}
	

/*
the led on function is used to turn on led  pin location using dio
*/
 void LED_on(u8 ledPort, u8 ledPin)
{
	DIO_vidset_Pin_Value (ledPort,ledPin,HIGH);
	
}

/*
the led off function is used to turn on led  pin location using dio
*/
void LED_off (u8 ledPort, u8 ledPin)
{
	DIO_vidset_Pin_Value (ledPort,ledPin, LOW);
	
}
/*
the led toggle function is used to toggle led  pin location using dio
*/

void LED_toggle(u8 ledPort, u8 ledPin)
{
	DIO_vidTogel_Pin_Value (ledPort,ledPin);
	
}
