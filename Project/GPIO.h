#ifndef __GPOI_H__
#define	__GPOI_H__

#include "tm4c123gh6pm.h"


#define PIN0 0x0000_0001
#define PIN1 0x0000_0010
#define PIN2 0x0000_0100
#define PIN3 0x0000_1000
#define PIN4 0x0001_0000
#define PIN5 0x0010_0000
#define PIN6 0x0100_0000
#define PIN7 0x1000_0000

typedef enum{IN=0,OUT=1}Pin_Direction;
typedef enum{DOWN=0,UP=1}Pull_Direction;
typedef enum{LOW=0,HIGH=1}Write_Value;

// USE UPPER CASE CHARACTERS A,B,C,D,E,F

void GPIO_INIT(char c);
void set_pin_direction(char c, unsigned int MASK, Pin_Direction d);
void set_pull_direction(char c, unsigned int MASK, Pull_Direction d);
//void DEN(char c, unsigned int MASK);
unsigned int D_Read(char c, unsigned int MASK);
void D_Write(char c, unsigned int MASK, Write_Value w);
void toggle(char c, unsigned int MASK);



#endif