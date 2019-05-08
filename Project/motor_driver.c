#include "motor_driver.h"
#define IN_NUM  4


int IN[IN_NUM];


// if (n equals 512) this will lead to full rotation



void motor_init(int port_index , uint8_t mask)
{
	int index = 0;
	int i;
	
	//most of those will be commented
	sys_tic_init(50);
	
	//initializes port
	Port_Init(port_index);
	
	//set the pins we are going to use as an output in the selected port
	Port_SetPinDirection(port_index,mask,PORT_PIN_OUT);
	
	//we will put the elements in the array from right to right, and then we will call them from the array later on
		for (i=0;i<8;i++)
	{
		if ( 1 & (mask>>i) )
		{
			IN[index]= i;
			index++;
		}
		
	}
		
}

void move_step(int dir)
{
	int j;

	IN[0]=0;
	IN[1]=1;
	IN[2]=2;
	IN[3]=3;
	
	if(dir)
	{
		for (j=0; j<IN_NUM;j++)
		{
			sys_tic_delay_ms(2);
			//if			(j==0)		{DIO_WritePort(8,0x01,STD_HIGH);DIO_WritePort(8,0x02,STD_HIGH);DIO_WritePort(8,0x04,STD_LOW);DIO_WritePort(8,0x08,STD_LOW);}
			//else if	(j==1)		{DIO_WritePort(8,0x01,STD_LOW);DIO_WritePort(8,0x02,STD_HIGH);DIO_WritePort(8,0x04,STD_HIGH);DIO_WritePort(8,0x08,STD_LOW);}
			//else if	(j==2)		{DIO_WritePort(8,0x01,STD_LOW);DIO_WritePort(8,0x02,STD_LOW);DIO_WritePort(8,0x04,STD_HIGH);DIO_WritePort(8,0x08,STD_HIGH);}
			//else if (j==3)		{DIO_WritePort(8,0x01,STD_HIGH);DIO_WritePort(8,0x02,STD_LOW);DIO_WritePort(8,0x04,STD_LOW);DIO_WritePort(8,0x08,STD_HIGH);}
			
			if			(j==0)		{DIO_Set_Pin(8,IN[0]);DIO_Set_Pin(8,IN[1]);DIO_Clear_Pin(8,IN[2]);DIO_Clear_Pin(8,IN[3]);}
			else if	(j==1)		{DIO_Clear_Pin(8,IN[0]);DIO_Set_Pin(8,IN[1]);DIO_Set_Pin(8,IN[2]);DIO_Clear_Pin(8,IN[3]);}
			else if	(j==2)		{DIO_Clear_Pin(8,IN[0]);DIO_Clear_Pin(8,IN[1]);DIO_Set_Pin(8,IN[2]);DIO_Set_Pin(8,IN[3]);}
			else if (j==3)		{DIO_Set_Pin(8,IN[0]);DIO_Clear_Pin(8,IN[1]);DIO_Clear_Pin(8,IN[2]);DIO_Set_Pin(8,IN[3]);}
		}
		sys_tic_delay_ms(2);
		DIO_WritePort(8,0xFF,STD_LOW);
		
	}
	else
	{
		for (j=IN_NUM-1; j>=0 ;j--)
		{
			sys_tic_delay_ms(2);
			//if			(j==0)		{DIO_WritePort(8,0x01,STD_HIGH);DIO_WritePort(8,0x02,STD_LOW);DIO_WritePort(8,0x04,STD_LOW);DIO_WritePort(8,0x08,STD_LOW);}
			//else if	(j==1)		{DIO_WritePort(8,0x01,STD_LOW);DIO_WritePort(8,0x02,STD_HIGH);DIO_WritePort(8,0x04,STD_LOW);DIO_WritePort(8,0x08,STD_LOW);}
			//else if	(j==2)		{DIO_WritePort(8,0x01,STD_LOW);DIO_WritePort(8,0x02,STD_LOW);DIO_WritePort(8,0x04,STD_HIGH);DIO_WritePort(8,0x08,STD_LOW);}
			//else if (j==3)		{DIO_WritePort(8,0x01,STD_LOW);DIO_WritePort(8,0x02,STD_LOW);DIO_WritePort(8,0x04,STD_LOW);DIO_WritePort(8,0x08,STD_HIGH);}
			
			if			(j==0)		{DIO_Set_Pin(8,IN[0]);DIO_Set_Pin(8,IN[1]);DIO_Clear_Pin(8,IN[2]);DIO_Clear_Pin(8,IN[3]);}
			else if	(j==1)		{DIO_Clear_Pin(8,IN[0]);DIO_Set_Pin(8,IN[1]);DIO_Set_Pin(8,IN[2]);DIO_Clear_Pin(8,IN[3]);}
			else if	(j==2)		{DIO_Clear_Pin(8,IN[0]);DIO_Clear_Pin(8,IN[1]);DIO_Set_Pin(8,IN[2]);DIO_Set_Pin(8,IN[3]);}
			else if (j==3)		{DIO_Set_Pin(8,IN[0]);DIO_Clear_Pin(8,IN[1]);DIO_Clear_Pin(8,IN[2]);DIO_Set_Pin(8,IN[3]);}
		}
		sys_tic_delay_ms(2);
		DIO_WritePort(8,0xFF,STD_LOW);
	}
	
	
	
	
}

void move_n_s(int n, int dir)
{
	int i;
	for (i=0;i<n;i++)
	{
		move_step(dir);
	}
	
}

void move_30_deg(int dir)
{
	if (dir)
	{
		move_n_s(44,1);
	}
	else
	{
		move_n_s(44,0);
	}
	
	
	
}
	















