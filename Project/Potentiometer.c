#include "Potentiometer.h"

uint16 Pot_Read(uint8 pin, uint16 mode)
{
    ADC0_Init(pin);
    ADC0_SS3_Init(pin, mode, DISABLE);
    return ADC0_SS3_Read();
}