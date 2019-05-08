
//testing only includes
#include "sys-tic-timer.h"


//Initialize the motor
void motor_init(int port_index , uint8_t mask);

//Make one step
void move_step(int dir);

//move n steps with dir
void move_n_s(int n , int dir);

void move_30_deg(int dir);