#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include "UART.h"

void EnableInterrupts(void);

void GPIOF_Handler (void)
{
	if (GPIO_PORTF_RIS_R & (1 << 0))
	{
		GPIO_D_Write('F', 4, HIGH);
		UART_Write(1, 'R');
	}
	 else if (GPIO_PORTF_RIS_R & (1 << 4))
	 {
		GPIO_D_Write('F', 8, HIGH);
		UART_Write(1, 'L');
	 }
	GPIO_PORTF_ICR_R = 0xFF;
}

int main (void) 
{
	UART_Init(1);
	EnableInterrupts();
	GPIO_INIT('F');
	GPIO_set_pin_direction('F', 0x10, IN);
	GPIO_set_pin_direction('F', 0x0E, OUT); 
	GPIO_set_pull_direction('F', 0x10, UP);
	GPIO_D_Write('F', 0x02, HIGH);
	GPIO_Interrupt_INIT('F');
	for(;;)
	{
	}
}
