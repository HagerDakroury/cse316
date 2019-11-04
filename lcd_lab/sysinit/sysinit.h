#ifndef __SYSINIT__
#define __SYSINIT__

#include "tm4c123gh6pm.h"
#define SW1 (1U<<4)
#define SW2 (1U<<0)

#define LCD_DATA_DATA GPIO_PORTB_DATA_R
#define LCD_CTRL_DATA GPIO_PORTE_DATA_R
#define EN (1U<<2)
#define RS (1U<<0)
#define RW (1U <<1)

void sys_init();
void sys_start();

#endif
