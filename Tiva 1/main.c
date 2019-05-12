#include "tm4c123gh6pm.h"
#include "UART.h"
#include "GPIO.h"
#include "Temp_Sensor.h"
#include "Timer.h"

void TIMER0A_Handler(void);

int main (void) 
{
	
	UART_Init(0);
	GPIO_INIT('F');
	set_pin_direction('F', 0x11, IN);
	set_pin_direction('F', 0x0E, OUT);
	set_pull_direction('F', 0x11, DOWN);
	
	D_Write('F', 0x0E, LOW);
	
	Temp_Init(AIN0, ADC_EMUX_EM3_PROCESSOR);

	
	Periodic_Timer_Init(0x00F42400);
	for(;;)
	{
		
	}
}

void TIMER0A_Handler(void)
{
	uint8 temp = Temp_Read();

	TIMER0_ICR_R |= 0x00000001;
	toggle('F', 0x02);
	

	UART_Write(0, '0' + temp/10);
	UART_Write(0, '0' + temp%10);
	UART_Write(0, ' ');
	UART_Write(0, 'C');

	
	
	
}
