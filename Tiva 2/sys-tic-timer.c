#include "sys-tic-timer.h"
#define GPIO_PF1_M					0x02U		// Pin 1 is connected to red
#define GPIO_PF4_M					0x10U		// Pin 4 is connected to switch
#define GPIO_PF3_M					0x08U		// Pin 3 is connected to green
#define GPIO_PF2_M					0x04U		// Pin 2 is connected to blue
void sys_tic_init( int counts_required)
{
	//intilally make all values in timer to equal 0
	NVIC_ST_CTRL_R = 0 ;
	// to clear any previous value
	NVIC_ST_CURRENT_R = 0 ;
	
}

void sys_tic_enable()
{
	NVIC_ST_CTRL_R = 5 ;
	
}

void sys_tic_disable()
{
	NVIC_ST_CURRENT_R = 0 ;
	NVIC_ST_CTRL_R = 0 ;
}

void sys_tic_delay_ms(uint32 n)
{
	
			uint32 i ;
			for (i=0;i< n ; i++)
			{
				sys_tic_delay_ns(1000000) ;
			}
}

void sys_tic_delay_ns(uint32 n)
{
	int required = (n/62.5);
	sys_tic_enable();
	NVIC_ST_RELOAD_R = required  ;
	while( !(NVIC_ST_CTRL_R & 0x000010000)) {}

	
}

