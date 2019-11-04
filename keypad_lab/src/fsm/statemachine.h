#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#define INCREMENT  0b10
#define DECREMENT  0b01
#define RESET      0b11
#define SW1 (1U<<4)
#define SW2 (1U<<0)

void run();
void update();

#endif
