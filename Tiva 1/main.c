#include "GPIO.h"
#include "UART.h"
#include "Timer.h"
#include "Temp_Sensor.h"
#include "motor_driver.h"
#include "PWMController.h"

void EnableInterrupts(void);
void TIMER0A_Handler(void);
void system_init(void);

int main (void) 
{
	uint8 Data_Recieved;
	uint8 mode;
	uint8 pwm;
	
	//inits the system,ports,and modules
	system_init();
	
	for(;;)
	{
		Data_Recieved = UART_Read(7);
		mode = Data_Recieved & 0x80; //first bit
		
		if (!mode) //0 -> Motor
		{
			if (Data_Recieved & (0x40)) //second bit
			{
				//LEFT
				move_30_deg(1, 0xF0, 'A');
			}
			else 
			{
				//RIGHT
				move_30_deg(0, 0xF0, 'A');				
			}
		}
		else //1 -> LED
		{
			pwm = Data_Recieved & 0x7F; //Least significant 7 bits
			
			//UART_Write(0, '0' + pwm/100);
			//pwm %= 100;
			
			//UART_Write(0, '0' + pwm/10);
			//pwm %= 10;
			
			//UART_Write(0, '0' + pwm);
			//UART_Write(0, ' ');
			
			PWMSetDutyCycle(pwm);
		}
	}
	
}

void TIMER0A_Handler(void)
{
	uint8 temp; 
	temp = Temp_Read();
	UART_Write(7, temp);
	
	TIMER0_ICR_R |= 0x00000001;
}

void system_init(void)
{
	//motor init

	motor_init('A', 0xF0); //A4 to A7 
	EnableInterrupts();
	UART_Init(7);
	UART_Init(0);
	//No of ticks for one secound => 16 milion
	Periodic_Timer_Init(0x00F42400);
	//enables the temperature module
	Temp_Init(AIN0, ADC_EMUX_EM3_PROCESSOR);
	//Port enables
	PWMInit(0x04);
}
