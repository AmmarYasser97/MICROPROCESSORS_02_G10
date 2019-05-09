#include "GPIO.H"

void GPIO_INIT(char c){
	
	switch(c){
		case'A':
			SYSCTL_RCGCGPIO_R |=0x01;
			GPIO_PORTA_LOCK_R =GPIO_LOCK_KEY;
			GPIO_PORTA_CR_R=0xFF;
			GPIO_PORTA_AFSEL_R =0;
			GPIO_PORTA_DEN_R=0xFF;
			GPIO_PORTA_AMSEL_R =0;
			GPIO_PORTA_PCTL_R =0;
			
			break;
		case 'B':
			SYSCTL_RCGCGPIO_R |=0x02;
			GPIO_PORTB_LOCK_R =GPIO_LOCK_KEY;
			GPIO_PORTB_CR_R=0xFF;
			GPIO_PORTB_DEN_R=0xFF;
			GPIO_PORTB_AFSEL_R =0;
			GPIO_PORTB_AMSEL_R =0;
			GPIO_PORTB_PCTL_R =0;
			
			break;
		case'C':
			SYSCTL_RCGCGPIO_R |=0x04;
			GPIO_PORTC_LOCK_R =GPIO_LOCK_KEY;
			GPIO_PORTC_CR_R=0xFF;
			GPIO_PORTC_DEN_R=0xFF;
			GPIO_PORTC_AFSEL_R =0;
			GPIO_PORTC_AMSEL_R =0;
			GPIO_PORTC_PCTL_R =0;
			
			break;
		case'D':
			SYSCTL_RCGCGPIO_R |=0x08;
			GPIO_PORTD_LOCK_R =GPIO_LOCK_KEY;
			GPIO_PORTD_CR_R=0xFF;
			GPIO_PORTD_DEN_R=0xFF;
			GPIO_PORTD_AFSEL_R =0;
			GPIO_PORTD_AMSEL_R =0;
			GPIO_PORTD_PCTL_R =0;
			
			break;
		case'E':
			SYSCTL_RCGCGPIO_R |=0x10;
			GPIO_PORTE_LOCK_R =GPIO_LOCK_KEY;
			GPIO_PORTE_CR_R=0xFF;
			GPIO_PORTE_DEN_R=0xFF;
			GPIO_PORTE_AFSEL_R =0;
			GPIO_PORTE_AMSEL_R =0;
			GPIO_PORTE_PCTL_R =0;
			
			break;
		case'F':
			SYSCTL_RCGCGPIO_R |=0x20;
			GPIO_PORTF_LOCK_R =GPIO_LOCK_KEY;
			GPIO_PORTF_CR_R=0xFF;
			GPIO_PORTF_DEN_R=0xFF;
			GPIO_PORTF_AFSEL_R =0;
			GPIO_PORTF_AMSEL_R =0;
			GPIO_PORTF_PCTL_R =0;
			
			break;
	}
	
}

void set_pin_direction(char c, unsigned int MASK, Pin_Direction d){
	
	switch(c){
		case'A':
			if(d) GPIO_PORTA_DIR_R|=MASK;
			else GPIO_PORTA_DIR_R&= ~MASK;
			break;
		case'B':
			if(d) GPIO_PORTB_DIR_R|=MASK;
			else GPIO_PORTB_DIR_R&= ~MASK;
			break;
		case'C':
			if(d) GPIO_PORTC_DIR_R|=MASK;
			else GPIO_PORTC_DIR_R&= ~MASK;
			break;
		case'D':
			if(d) GPIO_PORTD_DIR_R|=MASK;
			else GPIO_PORTD_DIR_R&= ~MASK;
			break;
		case'E':
			if(d) GPIO_PORTE_DIR_R|=MASK;
			else GPIO_PORTE_DIR_R&= ~MASK;
			break;
		case'F':
			if(d) GPIO_PORTF_DIR_R|=MASK;
			else GPIO_PORTF_DIR_R&= ~MASK;
			break;
	
	}
}
void set_pull_direction(char c, unsigned int MASK, Pull_Direction d){
	
		switch(c){
		case'A':
			if(d) GPIO_PORTA_PUR_R|=MASK;
			else GPIO_PORTA_PDR_R|=MASK;
			break;
		case'B':
			if(d) GPIO_PORTB_PUR_R|=MASK;
			else GPIO_PORTB_PDR_R|=MASK;
			break;
		case'C':
			if(d) GPIO_PORTC_PUR_R|=MASK;
			else GPIO_PORTC_PDR_R|=MASK;
			break;
		case'D':
			if(d) GPIO_PORTD_PUR_R|=MASK;
			else GPIO_PORTD_PDR_R|=MASK;
			break;
		case'E':
			if(d) GPIO_PORTE_PUR_R|=MASK;
			else GPIO_PORTE_PDR_R|=MASK;
			break;
		case'F':
			if(d) GPIO_PORTF_PUR_R|=MASK;
			else GPIO_PORTF_PDR_R|=MASK;
			break;
	
	}
}
//void DEN(char c, unsigned int MASK){
//	switch(c){
//		case'A':
//			GPIO_PORTA_DEN_R|=MASK;
//			break;
//		case'B':
//			GPIO_PORTB_DEN_R|=MASK;
//			break;
//		case'C':
//			GPIO_PORTC_DEN_R|=MASK;
//			break;
//		case'D':
//			GPIO_PORTD_DEN_R|=MASK;
//			break;
//		case'E':
//			GPIO_PORTE_DEN_R|=MASK;
//			break;
//		case'F':
//			GPIO_PORTF_DEN_R|=MASK;
//			break;
//	}
//}
unsigned int D_Read(char c, unsigned int MASK){
	switch(c){
		case'A':
			if(GPIO_PORTA_DATA_R & MASK) return 1;
			else return 0;
			break;
		case'B':
			if(GPIO_PORTB_DATA_R & MASK) return 1;
			else return 0;
			break;
		case'C':
			if(GPIO_PORTC_DATA_R & MASK) return 1;
			else return 0;
			break;
		case'D':
			if(GPIO_PORTD_DATA_R & MASK) return 1;
			else return 0;
			break;
		case'E':
			if(GPIO_PORTE_DATA_R & MASK) return 1;
			else return 0;
			break;
		case'F':
			if(GPIO_PORTF_DATA_R & MASK) return 1;
			else return 0;
			break;
		default: return 0;
	}
}
void D_Write(char c, unsigned int MASK, Write_Value w){
		switch(c){
		case'A':
			if(w) GPIO_PORTA_DATA_R|=MASK;
			else GPIO_PORTA_DATA_R&=~ MASK;
			break;
		case'B':
			if(w) GPIO_PORTB_DATA_R|=MASK;
			else GPIO_PORTB_DATA_R&=~ MASK;
			break;
		case'C':
			if(w) GPIO_PORTC_DATA_R|=MASK;
			else GPIO_PORTC_DATA_R&=~ MASK;
			break;
		case'D':
			if(w) GPIO_PORTD_DATA_R|=MASK;
			else GPIO_PORTD_DATA_R&=~ MASK;
			break;
		case'E':
			if(w) GPIO_PORTE_DATA_R|=MASK;
			else GPIO_PORTE_DATA_R&=~ MASK;
			break;
		case'F':
			if(w) GPIO_PORTF_DATA_R|=MASK;
			else GPIO_PORTF_DATA_R&=~ MASK;
			break;
	}
}
void toggle(char c, unsigned int MASK){
	switch(c){
		case 'A':
			GPIO_PORTA_DATA_R ^=MASK;
			break;
		case 'B':
			GPIO_PORTB_DATA_R ^=MASK;
			break;
		case 'C':
			GPIO_PORTC_DATA_R ^=MASK;
			break;
		case 'D':
			GPIO_PORTD_DATA_R ^=MASK;
			break;
		case 'E':
			GPIO_PORTE_DATA_R ^=MASK;
			break;
		case 'F':
			GPIO_PORTF_DATA_R ^=MASK;
			break;
	}
}

