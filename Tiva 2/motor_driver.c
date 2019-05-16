#include "motor_driver.h"
#define IN_NUM  4


// the indexes of the pin that are to be written
uint8 IN_M[IN_NUM];


// if (n equals 512) this will lead to full rotation



void motor_init(uint8 port_index , uint8 mask)
{
	//uint8 index = 0;
	//uint8 i;

	
	//inits the timer
	sys_tic_init(50);
	
	//initializes port
	GPIO_INIT(port_index);
	
	//set the pins we are going to use as an output in the selected port
	GPIO_set_pin_direction(port_index,mask,OUT);
	
		
}

void move_step(uint8 dir ,  uint8 mask , uint8 port_in)
{
	//counters
	int j;
	int i=0;
	//counter of the IN Array that contains the pins that are masked
	uint8 index=0;
	
	
	// for loop to determine the pins
		for (i=0;i<8;i++)
	{
		if ( 1 & (mask>>i) )
		{
			IN_M[index]= i;
			index++;
		}
		
	}
	
	
	//IN1 IN2 IN3 IN4
	if(dir)
	{
		for (j=0; j<IN_NUM;j++)
		{
			sys_tic_delay_ms(2);

			
			
			if		(j==0)		{GPIO_D_Write(port_in,(1<<IN_M[0]),HIGH);	GPIO_D_Write(port_in,(1<<IN_M[1]),LOW);		GPIO_D_Write(port_in,(1<<IN_M[2]),LOW); 	GPIO_D_Write(port_in,(1<<IN_M[3]),LOW); }
			else if	(j==1)		{GPIO_D_Write(port_in,(1<<IN_M[0]),LOW);	GPIO_D_Write(port_in,(1<<IN_M[1]),HIGH);	GPIO_D_Write(port_in,(1<<IN_M[2]),LOW); 	GPIO_D_Write(port_in,(1<<IN_M[3]),LOW);	}
			else if	(j==2)		{GPIO_D_Write(port_in,(1<<IN_M[0]),LOW);	GPIO_D_Write(port_in,(1<<IN_M[1]),LOW);		GPIO_D_Write(port_in,(1<<IN_M[2]),HIGH);	GPIO_D_Write(port_in,(1<<IN_M[3]),LOW);	}
			else if (j==3)		{GPIO_D_Write(port_in,(1<<IN_M[0]),LOW);	GPIO_D_Write(port_in,(1<<IN_M[1]),LOW);		GPIO_D_Write(port_in,(1<<IN_M[3]),LOW); 	GPIO_D_Write(port_in,(1<<IN_M[3]),HIGH); }
		
		sys_tic_delay_ms(2);
		GPIO_D_Write(port_in,0xFF,LOW);
		}
	}
		//IN4 IN3 IN2 IN1
	else
	{
		for (j=IN_NUM-1; j>=0 ;j--)
		{
			sys_tic_delay_ms(2);
			
			if		(j==0)		{GPIO_D_Write(port_in,(1<<IN_M[0]),HIGH);	GPIO_D_Write(port_in,(1<<IN_M[1]),LOW);		GPIO_D_Write(port_in,(1<<IN_M[2]),LOW); 	GPIO_D_Write(port_in,(1<<IN_M[3]),LOW); }
			else if	(j==1)		{GPIO_D_Write(port_in,(1<<IN_M[0]),LOW);	GPIO_D_Write(port_in,(1<<IN_M[1]),HIGH);	GPIO_D_Write(port_in,(1<<IN_M[2]),LOW); 	GPIO_D_Write(port_in,(1<<IN_M[3]),LOW);	}
			else if	(j==2)		{GPIO_D_Write(port_in,(1<<IN_M[0]),LOW);	GPIO_D_Write(port_in,(1<<IN_M[1]),LOW);		GPIO_D_Write(port_in,(1<<IN_M[2]),HIGH);	GPIO_D_Write(port_in,(1<<IN_M[3]),LOW);	}
			else if (j==3)		{GPIO_D_Write(port_in,(1<<IN_M[0]),LOW);	GPIO_D_Write(port_in,(1<<IN_M[1]),LOW);		GPIO_D_Write(port_in,(1<<IN_M[3]),LOW); 	GPIO_D_Write(port_in,(1<<IN_M[3]),HIGH); }
		}
		sys_tic_delay_ms(2);
		GPIO_D_Write(port_in,0xFF,LOW);
	}
	
	
	
	
}

void move_n_s(uint8 n, uint8 dir , uint8 mask ,  uint8 port_in)
{
	int i;
	for (i=0;i<n;i++)
	{
		move_step(dir , mask , port_in);
	}
	
}

void move_30_deg(uint8 dir , uint8 mask , uint8 port_in)
{
	if (dir)
	{
		move_n_s(44,1,mask , port_in);
	}
	else
	{
		move_n_s(44,0,mask , port_in );
	}
	
	
	
}
	















