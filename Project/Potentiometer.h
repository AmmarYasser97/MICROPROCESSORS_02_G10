#ifndef __POT_H__
#define __POT_H__

#include "typedefs.h"
#include "tm4c123gh6pm.h"
#include "ADC.h"

//Prototypes
void Pot_Init(uint8 channel, uint16 mode);
uint16 Pot_Read(void);

#endif // __POT_H__
