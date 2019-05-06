#ifndef __UART_H__
#define	__UART_H__

#include "typedefs.h"
#include "tm4c123gh6pm.h"

#define GPIO_PA10_M 0x03
#define GPIO_PB10_M 0x03

void UART0_Init(uint8 UARTnumber);

uint8 UART0_Read(void);

void UART0_Write(uint8 data);

uint8 UART0_Available(void);

#endif // __UART_H__
