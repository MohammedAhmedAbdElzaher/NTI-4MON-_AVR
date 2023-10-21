/*
 * buttonc.c
 *
 * Created: 10/21/2023 1:26:28 AM
 *  Author: zaher
 */ 
#include "../button/button.h"
/*
the button init function is used to initialize button port and pin location using dio
*/
 void BUTTON_init(u8 buttonPort, u8 buttonPin)
{
  DIO_vidset_Pin_Direction(buttonPort,buttonPin,IN);
	
}


/*
the button read function is used to read button port and pin location using dio
*/
void BUTTON_read(u8 buttonPort, u8 buttonPin, u8 *value)
{
	DIO_vidGET_Pin_Value (buttonPort,buttonPin,value);
}