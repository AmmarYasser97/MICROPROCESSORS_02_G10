
//testing only includes
#include "sys-tic-timer.h"
#include "GPIO.h"

//Initialize the motor
void motor_init(uint8 port_index , uint8 mask);

//Make one step
void move_step(uint8 dir, uint8 mask , uint8 port_in );

//move n steps with dir
void move_n_s(uint8 n , uint8 dir, uint8 mask, uint8 port_in);

//moves 30 degress
void move_30_deg(uint8 dir, uint8 mask , uint8 port_in);
