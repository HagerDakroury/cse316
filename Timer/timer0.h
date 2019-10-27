#ifndef __TIMER0_H__ 
#define __TIMER0_H__

void timer0_set(int delay, int mode);
void timer0_reset();
int timeout();
void timer0_oneshot_init();

#endif