#include "timer0.h"

void timer0_oneshot_init(){
    SYSCTL_RCGCTIMER_R|=0x01;  //enabling the sys clock for timer 0

    TIMER0_CTL_R=0x0;          //disabling timer
    TIMER0_CFG_R= 0x0;         //32-bit configuration
    TIMER0_TAMR_R=0x01;       //one shot mode 
}

/*
delay in sec
mode: 1-> one-shot 2->periodic
*/

void timer0_set(int delay, int mode){
    timer0_oneshot_init();
    TIMER0_TAILR_R=16000*delay-1; //loadimg the delay value
    TIMER0_CTL_R|=mode;                //enabling timer0

}

void timer0_reset(){
   TIMER0_ICR_R = 0x1;      //clear the timeout flag for timerA
}

int timeout(){
    if(TIMER0_RIS_R & 1){
        return 1;
    }
    return 0;
}

void delay(int time){
    timer0_set(time,1); //set timer0 A to one ssec in one-shot mode
    while(!timeout());
    timer0_reset();
}
