#include "LedController.h"

void LedInit(void)
{
	//Enable PWM Module 1 during Run mode
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	//Enable Port F (give it clock and power it up)
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
	//Configured the Run-Mode clock to use the PWM divider
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
	//Set the divider to divide by 64 aka setting the PWM CLOCK to 1.25 MHz
	SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64;
	
	//Clear the Control (also disable PWM Block)
	PWM1_3_CTL_R = 0x00000000;
	//High at reload and low at CMP
	PWM1_3_GENA_R = 0x0000008C;
  //1KHz	
	PWM1_3_LOAD_R = 1250 - 1; 
	//Currenty compare is just 1 tick difference between reload so its always low
	PWM1_3_CMPA_R = 1248;
	//PWM Block Enable
	PWM1_3_CTL_R = PWM_0_CTL_ENABLE;
	
	//Enables alternative peripheral (so not GPIO)
	GPIO_PORTF_AFSEL_R |= PWM_PIN;
	//Set control 
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R & 0xFFFFF0FF) | (GPIO_PCTL_PF2_M1PWM6);
	//Set pin output
	GPIO_PORTF_DIR_R |= PWM_PIN;
	//Set pin as digital
	GPIO_PORTF_DEN_R |= PWM_PIN;
	
	PWM1_ENABLE_R = PWM_ENABLE_PWM6EN;
}

void LedSetDutyCycle(uint8 DutyCycle)
{
	if(DutyCycle == 100)
	{
		PWM1_3_CMPA_R = 1;
	}
	else if(DutyCycle == 0)
	{
		PWM1_3_CMPA_R = 1248;
	}
	else
	{
		PWM1_3_CMPA_R = (uint16)(1250 * (1 - (DutyCycle / 100.0)) - 1);
	}
}