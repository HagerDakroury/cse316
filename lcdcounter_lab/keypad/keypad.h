#ifndef __KEYPAD_H__
#define __KEYPAD_H__


#define C0 (1U<<0)
#define C1 (1U<<1)
#define C2 (1U<<2)
#define C3 (1U<<3)

int capture_input();
int get_row();


#endif
