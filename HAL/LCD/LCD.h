/*
 * LCD.h
 *
 * Created: 10/21/2023 11:01:45 AM
 *  Author: zaher
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../LIB/bit math.h"
#include "../../LIB/type.h"


#define LCD_DATA_PORT   PORT_B

void LCD_voidInt(void);
void LCD_voidsendcommand(u8 copy_u8cmd);
void LCD_voidSendData(u8 copy_u8data);
void LCD_voidClearDisplay(void);
void LCD_voidSendString(u8 *Ptr_u8PtrString);
void LCD_voidGoToPosition(u8 Copy_u8RowNum,u8 Copy_u8ColNum);
void LCD_voidDisplayNumber(s32 Copy_s32Number);
void LCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum);





#endif /* LCD_H_ */