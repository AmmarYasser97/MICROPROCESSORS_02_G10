
#include "tm4c123gh6pm.h"
#include "typedefs.h"

void sys_tic_init( int counts_required );
void sys_tic_enable(void);
void sys_tic_disable(void);
void sys_tic_delay_ns(uint32 n);
void sys_tic_delay_ms(uint32 n);
