#ifndef __TIMER_H__
#define	__TIMER_H__

#include "tm4c123gh6pm.h"
#include "typedefs.h"

#define TIMER_LOAD_VAL 0x00F42400 // 16,000,000 in decimal = microcontroller's clock freq. therefore equivalent to one second

void Periodic_Timer_Init(uint32 TimerNo);

#endif
