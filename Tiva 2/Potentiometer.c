#include "Potentiometer.h"

void Pot_Init(uint8 channel, uint16 mode)
{
    ADC0_Init(channel);
    ADC0_SS3_Init(channel, mode, DISABLE);
}
uint16 Pot_Read(void)
{
    return ADC0_SS3_Read();
}