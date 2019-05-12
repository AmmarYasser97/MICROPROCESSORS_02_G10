#ifndef __TEMP_H__
#define __TEMP_H__

#include "typedefs.h"
#include "tm4c123gh6pm.h"
#include "ADC.h"

//Prototypes
void Temp_Init(uint8 channel, uint16 mode);
uint8 Temp_Read(void);

#endif // __TEMP_H__
