#include "Temp_Sensor.h"

//This Driver was created by returning to this pages in the datasheet of the internal temparture sensor
//812,

/*
VTSENS = 2.7 - ((TEMP + 55) / 75)

The temperature sensor reading can be sampled in a sample sequence by setting the TSn bit in
the ADCSSCTLn register. The temperature reading from the temperature sensor can also be given
as a function of the ADC value. The following formula calculates temperature (TEMP in ℃) based
on the ADC reading (ADCCODE, given as an unsigned decimal number from 0 to 4095) and the
maximum ADC voltage range (VREFP - VREFN):

TEMP = 147.5 - ((75 * (VREFP - VREFN) × ADCCODE) / 4096)
*/

uint8 Temp_Read(uint8 pin, uint16 mode)
{
    ADC0_Init(pin);
    ADC0_SS3_Init(pin, mode, ENABLE);
    return (147.5 - ((75 * 3.3 * ADC0_SS3_Read()) / 4096));
}