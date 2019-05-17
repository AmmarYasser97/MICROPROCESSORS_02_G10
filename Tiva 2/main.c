#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "UART.h"
#include "Timer.h"
#include "Temp_Sensor.h"
#include "Potentiometer.h"
#include "LCD.h"


void EnableInterrupts(void);
void TIMER0A_Handler(void);
void system_init(void);
void GPIOF_Handler(void);

int main (void) 
{
	uint8 Data_Recieved;
	uint8 test;
	
	//inits the system,ports,and modules
	system_init();
	
	for(;;)
	{
		Data_Recieved = UART_Read(7);
		test = Data_Recieved;
		//if (Data_Recieved > 20 && Data_Recieved < 40)
		//{
		//	GPIO_toggle('F', 0x02);
		//}
		
		UART_Write(0, '0' + test/100);
		test %= 100;
			
		UART_Write(0, '0' + test/10);
		test %= 10;
			
		UART_Write(0, '0' + test);
		UART_Write(0, ' ');
		
		LCD_sendInt(Data_Recieved);
	}
	
}

void TIMER0A_Handler(void)
{
	uint16 pot;
	uint8 pot2;
	
	//GPIO_toggle('F', PIN1);
	
	pot = Pot_Read();
	pot2 = (pot/4095.0)*100;
	
	pot2 |= PIN7;
	
	UART_Write(7, pot2);
	
	TIMER0_ICR_R |= 0x00000001;
}

void GPIOF_Handler(void)
{
	//GPIO_toggle('F', PIN1);

	if(GPIO_PORTF_RIS_R &PIN0)
	{
		UART_Write(7,0x00);
	}
	else if(GPIO_PORTF_RIS_R &PIN4)
	{
		UART_Write(7,0x40);
	}
	GPIO_PORTF_ICR_R=0xFF; //clears values of RIS and MIS
}

void system_init(void)
{
	EnableInterrupts();
	GPIO_INIT('E');
	//Timer_init();
	sys_tic_init(50);
	UART_Init(7);
	UART_Init(0);
	//No of ticks for one secound => 16 milion
	Periodic_Timer_Init(20000);
	//Port enables
	GPIO_INIT('F');
	GPIO_Interrupt_INIT('F');
	GPIO_set_pin_direction('F', PIN1, OUT);
	GPIO_set_pin_direction('F', PIN2, OUT);
	GPIO_set_pin_direction('F', PIN3, OUT);
	GPIO_set_pin_direction('F',PIN0,IN);
	GPIO_set_pin_direction('F',PIN4,IN);
	GPIO_set_pull_direction('F',PIN0,UP);
	GPIO_set_pull_direction('F',PIN4,UP);
	
	//LCD Ports Initilization
	GPIO_INIT('B');
	GPIO_INIT('D');
	GPIO_set_pin_direction('B', PIN0, OUT);
	GPIO_set_pin_direction('B', PIN1, OUT);
	GPIO_set_pin_direction('B', PIN2, OUT);
	GPIO_set_pin_direction('B', PIN3, OUT);
	GPIO_set_pin_direction('B', PIN4, OUT);
	GPIO_set_pin_direction('B', PIN5, OUT);
	GPIO_set_pin_direction('B', PIN6, OUT);
	GPIO_set_pin_direction('B', PIN7, OUT);
	
	GPIO_set_pull_direction('B', 0xFF, UP);
	
	GPIO_set_pin_direction('E', PIN2, OUT);
	GPIO_set_pin_direction('E', PIN3, OUT);
	GPIO_set_pin_direction('E', PIN4, OUT);
	
	//Direction
	//GPIO_set_pin_direction('F', 0x0F, OUT);
	//Write
	//GPIO_D_Write('F',PIN1,HIGH);
	Pot_Init(AIN8, ADC_EMUX_EM3_PROCESSOR);
	LCD_init();
	LCD_clearScreen();	
}
