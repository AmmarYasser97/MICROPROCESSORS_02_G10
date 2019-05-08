#include "motor_driver.h"
#define IN_NUM  4


int IN[IN_NUM];



void motor_init(int port_index , uint8_t mask)
{
	int index = 0;
	int i;
	
	//most of those will be commented
	sys_tic_init();
	
	//initializes port
	Port_Init(port_index);
	
	//set the pins we are going to use as an output in the selected port
	Port_SetPinDirection(port_index,mask,PORT_PIN_OUT);
	
	//we will put the elements in the array from right to right, and then we will call them from the array later on
		for (i=0;i<8;i++)
	{
		if ( 1 && (mask>>i) )
		{
			IN[index]= i;
			index++;
		}
		
	}
		
}

void move_step(int dir)
{
	int j;
	//Clockwise
	//IN1,IN2,IN3,IN4
	
	//AntiClockwise
	//IN4,IN3,IN2,IN1
	
	if(dir)
	{
		for (j=0; j<IN_NUM;j++)
		{
			if			(j==0)		{IN[0]=1;IN[1]=0;IN[2]=0;IN[3]=0;}
			else if	(j==1)		{IN[0]=0;IN[1]=1;IN[2]=0;IN[3]=0;}
			else if	(j==2)		{IN[0]=0;IN[1]=0;IN[2]=1;IN[3]=0;}
			else if (j==3)		{IN[0]=0;IN[1]=0;IN[2]=0;IN[3]=1;}
		}
		
	}
	else
	{
		for (j=IN_NUM-1; j>=0 ;j++)
		{
			if			(j==0)		{IN[0]=1;IN[1]=0;IN[2]=0;IN[3]=0;}
			else if	(j==1)		{IN[0]=0;IN[1]=1;IN[2]=0;IN[3]=0;}
			else if	(j==2)		{IN[0]=0;IN[1]=0;IN[2]=1;IN[3]=0;}
			else if (j==3)		{IN[0]=0;IN[1]=0;IN[2]=0;IN[3]=1;}
		}
	}
	
	sys_tic_delay_ms(2);
	
	
}

void move_n_s(int n, int dir)
{
	int i;
	for (i=0;i<n;i++)
	{
		move_step(dir);
	}
	
}
	















