#include "GPIO.H"

void GPIO_INIT(uint8 c){
	
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

void GPIO_set_pin_direction(uint8 c, uint16 MASK, Pin_Direction d){
	
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
void GPIO_set_pull_direction(uint8 c, uint16 MASK, Pull_Direction d){
	
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
//void DEN(uint8 c, uint16 MASK){
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
uint16 GPIO_D_Read(uint8 c, uint16 MASK){
	switch(c){
		case'A':
			if(GPIO_PORTA_DATA_R & MASK) return 1;
			else return 0;
		case'B':
			if(GPIO_PORTB_DATA_R & MASK) return 1;
			else return 0;
		case'C':
			if(GPIO_PORTC_DATA_R & MASK) return 1;
			else return 0;
		case'D':
			if(GPIO_PORTD_DATA_R & MASK) return 1;
			else return 0;
		case'E':
			if(GPIO_PORTE_DATA_R & MASK) return 1;
			else return 0;
		case'F':
			if(GPIO_PORTF_DATA_R & MASK) return 1;
			else return 0;
		default: return 0;
	}
}
void GPIO_D_Write(uint8 c, uint16 MASK, Write_Value w){
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
void GPIO_toggle(uint8 c, uint16 MASK){
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
void GPIO_Interrupt_INIT(uint8 c){
	switch(c){
		case'A':
			GPIO_PORTA_IM_R=0xFF; //enable port interrupt
			GPIO_PORTA_IS_R=0; //set enable to detect edges
			GPIO_PORTA_ICR_R=0xFF; //clears values of RIS and MIS
			GPIO_PORTA_IBE_R=0; //disable both edges detection
			GPIO_PORTA_IEV_R=0xFF; // detect rising edge;
			NVIC_EN0_R |= (1 << 1);
	
	case'B':
			GPIO_PORTB_IM_R=0xFF; //enable port interrupt
			GPIO_PORTB_IS_R=0; //set enable to detect edges
			GPIO_PORTB_ICR_R=0xFF; //clears values of RIS and MIS
			GPIO_PORTB_IBE_R=0; //disable both edges detection
			GPIO_PORTB_IEV_R=0xFF; // detect rising edge;
			NVIC_EN0_R |= (1 << 2);
	
case'C':
			GPIO_PORTC_IM_R=0xFF; //enable port interrupt
			GPIO_PORTC_IS_R=0; //set enable to detect edges
			GPIO_PORTC_ICR_R=0xFF; //clears values of RIS and MIS
			GPIO_PORTC_IBE_R=0; //disable both edges detection
			GPIO_PORTC_IEV_R=0xFF; // detect rising edge;
			NVIC_EN0_R |= (1 << 3);
	
	case'D':
			GPIO_PORTD_IM_R=0xFF; //enable port interrupt
			GPIO_PORTD_IS_R=0; //set enable to detect edges
			GPIO_PORTD_ICR_R=0xFF; //clears values of RIS and MIS
			GPIO_PORTD_IBE_R=0; //disable both edges detection
			GPIO_PORTD_IEV_R=0xFF; // detect rising edge;
			NVIC_EN0_R |= (1 << 4);
	
	case'E':
			GPIO_PORTE_IM_R=0xFF; //enable port interrupt
			GPIO_PORTE_IS_R=0; //set enable to detect edges
			GPIO_PORTE_ICR_R=0xFF; //clears values of RIS and MIS
			GPIO_PORTE_IBE_R=0; //disable both edges detection
			GPIO_PORTE_IEV_R=0xFF; // detect rising edge;
			NVIC_EN0_R |= (1 << 5);
	
	case'F':
			GPIO_PORTF_IM_R=0xFF; //enable port interrupt
			GPIO_PORTF_IS_R=0; //set enable to detect edges
			GPIO_PORTF_ICR_R=0xFF; //clears values of RIS and MIS
			GPIO_PORTF_IBE_R=0; //disable both edges detection
			GPIO_PORTF_IEV_R=0x00; // detect FALLING edge;
			NVIC_EN0_R |= (1 << 30);
	}
}

void DIO_Set_Pin(uint8 port_index,int pin_index)
{
	switch(pin_index)
	{
		case 0 : GPIO_D_Write(port_index,0x01,HIGH);
		case 1 : GPIO_D_Write(port_index,0x02,HIGH);
		case 2 : GPIO_D_Write(port_index,0x04,HIGH);
		case 3 : GPIO_D_Write(port_index,0x08,HIGH);
		case 4 : GPIO_D_Write(port_index,0x10,HIGH);
		case 5 : GPIO_D_Write(port_index,0x20,HIGH);
		case 6 : GPIO_D_Write(port_index,0x40,HIGH);
		case 7 : GPIO_D_Write(port_index,0x80,HIGH);
			
	}
	
}

void DIO_Clear_Pin(uint8 port_index,int pin_index)
{
	switch(pin_index)
	{
		case 0 : GPIO_D_Write(port_index,0x01,LOW);
		case 1 : GPIO_D_Write(port_index,0x02,LOW);
		case 2 : GPIO_D_Write(port_index,0x04,LOW);
		case 3 : GPIO_D_Write(port_index,0x08,LOW);
		case 4 : GPIO_D_Write(port_index,0x10,LOW);
		case 5 : GPIO_D_Write(port_index,0x20,LOW);
		case 6 : GPIO_D_Write(port_index,0x40,LOW);
		case 7 : GPIO_D_Write(port_index,0x80,LOW);
			
	}
	
}

