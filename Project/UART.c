#include "UART.h"

/*
* This function initialized UART0 and UART1 module with the upcoming configrations :
*
* 115200 baud rate
* Data length of 8 bits
* One stop bit
* Parity Enable (Odd)
* FIFOs enabled
* Enable interrupts
*
*/

void UART_Init(uint8 UARTnumber){
	
	switch(UARTnumber)
	{
			case 0:
					// Enable the UART module using the RCGCUART register.
					SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
					
					// Enable the clock to the appropriate GPIO module via the RCGCGPIO register.
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
					
					// Disable the UART by clearing the UARTEN bit in the UARTCTL register
					UART0_CTL_R &= ~UART_CTL_UARTEN;
					
					// Add calculated baud-rate divisor (BRD) value for 16 MHz.
					UART0_IBRD_R = 8680;    
					UART0_FBRD_R = 36;
					
					// Write the desired serial parameters to the UARTLCRH register (Word length is 8-bit, FIFO enabled, Odd parity used).
					UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN | UART_LCRH_PEN);
					
					// Enable the UART by setting the UARTEN bit in the UARTCTL register.
					UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
					
					// Set the GPIO AFSEL bits for the appropriate pins A0 A1.
					GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
					
					// Configure PORTA_PCTL register to select the alternative function (UART0).
					GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
					
					// Enable PORTA Digital mode.
					GPIO_PORTA_DEN_R |= GPIO_PA10_M;
					
					break;
					
			case 1:
					// Enable the UART module using the RCGCUART register.
					SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
					
					// Enable the clock to the appropriate GPIO module via the RCGCGPIO register.
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
					
					// Disable the UART by clearing the UARTEN bit in the UARTCTL register
					UART1_CTL_R &= ~UART_CTL_UARTEN;
					
					// Add calculated baud-rate divisor (BRD) value for 16 MHz.
					UART1_IBRD_R = 8680;    
					UART1_FBRD_R = 36;
					
					// Write the desired serial parameters to the UARTLCRH register (Word length is 8-bit, FIFO enabled, Odd parity used).
					UART1_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN | UART_LCRH_PEN);
					
					// Enable the UART by setting the UARTEN bit in the UARTCTL register.
					UART1_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
					
					// Set the GPIO AFSEL bits for the appropriate pins B0 B1.
					GPIO_PORTA_AFSEL_R |= GPIO_PB10_M;
								
					// Configure PORTB_PCTL register to select the alternative function (UART1).
					GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PB1_U1TX | GPIO_PCTL_PB0_U1RX);
								
					// Enable PORTB Digital mode.
					GPIO_PORTB_DEN_R |= GPIO_PB10_M;
					
					break;
		}
}


uint8 UART_Available(uint8 UART_number)
{
	volatile unsigned long *UART_flag;
	switch (UART_number)
	{
	case 0:
		UART_flag = &UART0_FR_R;
		break;
	case 1:
		UART_flag = &UART1_FR_R;
		break;
	case 2:
		UART_flag = &UART2_FR_R;
		break;
	case 3:
		UART_flag = &UART3_FR_R;
		break;
	case 4:
		UART_flag = &UART4_FR_R;
		break;
	case 5:
		UART_flag = &UART5_FR_R;
		break;
	case 6:
		UART_flag = &UART6_FR_R;
		break;
	case 7:
		UART_flag = &UART7_FR_R;
		break;

	default:
		UART_flag = &UART0_FR_R;
		break;
	}

	// check RXFE bit
	return !(*UART_flag & (1 << 4));
}


uint8 UART_Read(uint8 UART_number)
{
	volatile unsigned long *UART_data;
	switch (UART_number)
	{
	case 0:
		UART_data = &UART0_DR_R;
		break;
	case 1:
		UART_data = &UART1_DR_R;
		break;
	case 2:
		UART_data = &UART2_DR_R;
		break;
	case 3:
		UART_data = &UART3_DR_R;
		break;
	case 4:
		UART_data = &UART4_DR_R;
		break;
	case 5:
		UART_data = &UART5_DR_R;
		break;
	case 6:
		UART_data = &UART6_DR_R;
		break;
	case 7:
		UART_data = &UART0_DR_R;
		break;

	default:
		UART_data = &UART0_DR_R;
		break;
	}
	while (!UART_Available(UART_number))
		;

	//return least 8 significant bits of data
	return (uint8)((*UART_data) & 0xFF);
}


void UART_Write(uint8 UART_number, uint8 data)
{
	volatile unsigned long *UART_data;
	volatile unsigned long *UART_flag;

	switch (UART_number)
	{
	case 0:
		UART_data = &UART0_DR_R;
		UART_flag = &UART0_FR_R;
		break;
	case 1:
		UART_data = &UART1_DR_R;
		UART_flag = &UART1_FR_R;
		break;
	case 2:
		UART_data = &UART2_DR_R;
		UART_flag = &UART2_FR_R;
		break;
	case 3:
		UART_data = &UART3_DR_R;
		UART_flag = &UART3_FR_R;
		break;
	case 4:
		UART_data = &UART4_DR_R;
		UART_flag = &UART4_FR_R;
		break;
	case 5:
		UART_data = &UART5_DR_R;
		UART_flag = &UART5_FR_R;
		break;
	case 6:
		UART_data = &UART6_DR_R;
		UART_flag = &UART6_FR_R;
		break;
	case 7:
		UART_data = &UART0_DR_R;
		UART_flag = &UART7_FR_R;
		break;

	default:
		UART_data = &UART0_DR_R;
		UART_flag = &UART0_FR_R;
		break;
	}

	while ((*UART_flag) & (1 << 5))
		;
	*UART_data = data;
}

