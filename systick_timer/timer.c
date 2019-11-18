#include "timer.h"
#include "tm4c123gh6pm.h"

void systick_init(){
    NVIC_ST_CTRL_R = 0x5;
    NVIC_ST_RELOAD_R |= 0xffffff;
}

void systick_delay(int seconds) {
    for(int i = 0; i<seconds; i++){
        systick_init();
        while(!NVIC_ST_CTRL_R & 0x10000);
    }
}