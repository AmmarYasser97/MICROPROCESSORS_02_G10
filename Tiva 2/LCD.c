#include "LCD.h"


		/* init Settings */
#define CURSOR  1		/* 1 to Enable , 0 to Disable */
#define Blink	0		/* 1 to Enable , 0 to Disable */
#define _5x10_Dot	 0	/* 1 to Enable , 0 for 5 x 8 Dot */
#define Two_lines	 1	/* 1 to Enable , 0 for 1 Line */
#define LCD_CRTL_MASK     0x07  // 00 0111

		#if ( _5x10_Dot && Two_lines )
			#if Two_lines
				#pragma GCC error "You cannot Have Two Lines LCD with 5 * 10"
			#endif
		#endif

//LCD initialization
void LCD_init(void)
{
		sys_tic_delay_ms(1);
		//delay_ms(1);
		//Port_SetPinDirection(PORT_E, LCD_CRTL_MASK, PORT_PIN_OUT);
		//Port_SetPinDirection(PORT_D, 0xFF, PORT_PIN_OUT);
		LCD_sendCommand(0x30);
		sys_tic_delay_ms(5);
		LCD_sendCommand(0x30);
		sys_tic_delay_ms(1);
		LCD_sendCommand(0x08);
		LCD_sendCommand(0x01);
		LCD_sendCommand(0x06);
		LCD_sendCommand(0x0E);

}


// function to convert number to char array
char* itoa(int value, char* result, int base) {
		// check that the base if valid
		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}


void LCD_sendInt(uint16 number){
	uint8 n;
	uint8 i=0;
	char c[3];
	if(number/100 >0) n=3;
	else if(number/10 >0) n=2;
	else n=1;
	
	itoa(number,c,10);
	LCD_clearScreen();
	for( i=0; i<n; i++)
	{
		GPIO_PORTB_DATA_R= c[i]; //send numbers character by character
		GPIO_D_Write('D',PIN1,HIGH); // set RS
		GPIO_D_Write('D',PIN2,HIGH); // set ENABLE
		GPIO_D_Write('D',PIN3,LOW); //clr rw aka write mode
		//delay_ms(1);
		sys_tic_delay_ms(1);
		GPIO_D_Write('D',PIN2,LOW); // clr ENABLE
	}
}

//Sends a command to the LCD
//uint8 command: Command to be sent
void LCD_sendCommand(uint8 command)
{
	//void DIO_WritePort(uint8 port_index, uint8 pins_mask, Dio_LevelType pins_level);
	//DIO_WritePort(PORT_E, MASK_0, STD_LOW);
	GPIO_D_Write('D',PIN1,LOW); //CLR RS
	GPIO_D_Write('D',PIN3,LOW); // CLR RW
	//delay_ms(1);
	DATA = command;
	sys_tic_delay_ms(1);
	GPIO_D_Write('D',PIN2, HIGH); //SET ENABLE
	//delay_ms(1);
	//sys_tic_delay_ms(200);
	//DATA = command;
	sys_tic_delay_ms(1);
	GPIO_D_Write('D',PIN2,LOW); //CLR ENABLE
	//delay_ms(1);
	sys_tic_delay_ms(1);	
}

void LCD_clearScreen()
{
	LCD_sendCommand(Clear_display);
}
