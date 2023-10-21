/*
 * BCD_SEG.h
 *
 * Created: 10/21/2023 6:36:15 AM
 *  Author: zaher
 */ 


#ifndef BCD_SEG_H_
#define BCD_SEG_H_

typedef enum
{
	COM1,
	COM2,
	COM3,
	COM4
}COM_TYPE_t;

#define BCD_PORT    (PORT_B)
/*Select BCD PINS ON Faris pcb kit
 * */
#define BCD_PIN0    (pin0)
#define BCD_PIN1    (pin1)
#define BCD_PIN2    (pin2)
#define BCD_PIN4    (pin4)

void BCD_SEG_vidinit(u8 com_type);
void BCD_SEG_vidWriteNumber(u8 Copy_u8Number);




#endif /* BCD_SEG_H_ */