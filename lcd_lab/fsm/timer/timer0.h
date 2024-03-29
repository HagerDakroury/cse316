#ifndef __TIMER0_H__ 
#define __TIMER0_H__

#include "src/tm4c123gh6pm.h"

void timer0_set(int delay, int mode);
void timer0_reset();
int timeout();
void timer0_oneshot_init();
void delaym(int delay);
void delayu(int delay);

#endif
