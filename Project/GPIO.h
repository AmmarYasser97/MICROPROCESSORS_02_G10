#ifndef __GPOI_H__
#define	__GPOI_H__

#include "tm4c123gh6pm.h"
#include "typedefs.h"

#define PIN0 0x01
#define PIN1 0x02
#define PIN2 0x04
#define PIN3 0x08
#define PIN4 0x10
#define PIN5 0x20
#define PIN6 0x40
#define PIN7 0x80

typedef enum{IN=0,OUT=1}Pin_Direction;
typedef enum{DOWN=0,UP=1}Pull_Direction;
typedef enum{LOW=0,HIGH=1}Write_Value;

// USE UPPER CASE CHARACTERS A,B,C,D,E,F

void GPIO_INIT(uint8 c);
void GPIO_set_pin_direction(uint8 c, uint16 MASK, Pin_Direction d);
void GPIO_set_pull_direction(uint8 c, uint16 MASK, Pull_Direction d);
//void DEN(uint8 c, uint16 MASK);
uint16 GPIO_D_Read(uint8 c, uint16 MASK);
void GPIO_D_Write(uint8 c, uint16 MASK, Write_Value w);
void GPIO_toggle(uint8 c, uint16 MASK);
void GPIO_Interrupt_INIT(uint8 c);


#endif