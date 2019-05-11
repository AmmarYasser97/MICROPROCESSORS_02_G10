#ifndef ledControl
#define	ledControl

#include "typedefs.h"
#include "tm4c123gh6pm.h"

#define PWM_PIN 0x04

void LedInit(void);
void LedSetDutyCycle(uint8 DutyCycle);

#endif //ledControl