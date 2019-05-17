#ifndef pwmControl
#define	pwmControl

#include "typedefs.h"
#include "tm4c123gh6pm.h"


void PWMInit(uint8 PWM_PIN);
void PWMSetDutyCycle(uint8 DutyCycle);

#endif //pwmControl
