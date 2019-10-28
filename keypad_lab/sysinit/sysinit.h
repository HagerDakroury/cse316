#ifndef __SYSINIT__
#define __SYSINIT__



#define R0 (1U<<0)
#define R1 (1U<<1)
#define R2 (1U<<2)
#define R3 (1U<<3)

#define C0 (1U<<0)
#define C1 (1U<<1)
#define C2 (1U<<2)
#define C3 (1U<<3)

void sys_init();
void sys_start();

#endif
