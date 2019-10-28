#ifndef __TIMER0_H__ 
#define __TIMER0_H__

#include "tm4c123gh6pm.h"

void timer0_set(int delay, int mode);
void timer0_reset();
int timeout();
void timer0_oneshot_init();
void delay(int delay);
#endif
