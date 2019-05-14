#ifndef LCD_H
#define LCD_H
//ENABLE E2, RW E3 , RS E4, DATA B0-7

#include "typedefs.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "timer_delay.h"
#include "sys-tic-timer.h"


#define RS 0
#define RW 1
#define E 2

#define CONTROL GPIO_PORTB_DATA_BITS_R
#define DATA GPIO_PORTB_DATA_R


/* List Of Command Codes */
#define Clear_display 0x01
#define Return_Home	  0x02
#define Display_off   0x08
#define Display_on    0x0C
#define CURSOR_Shift_Right	 0x14
#define CURSOR_Shift_left	 0x10
#define Display_shift_left    0x18
#define Display_shift_Right	  0x1C
#define Data_Set 0x38
#define DDRAM_CONST 0x80



void LCD_sendCommand(uint8 command);
void LCD_sendInt(uint16 number);
void LCD_init(void);
void LCD_clearScreen(void);
#endif
