#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#define NADA       0b00
#define COUNT  0b10
#define ABORT  0b01
#define RESET      0b11
#define SW1 (1U<<4)
#define SW2 (1U<<0)


int capture_switch();
void run();
void update();

#endif
