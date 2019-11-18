#include "sysinit.h"
#include "src/timer/timer0.h"

void sys_init(){

    //ENABLING CLOCK AND DELAY
    SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R5| SYSCTL_RCGCGPIO_R4);
    delaym(300);

    //PORT F CONFIG
    GPIO_PORTF_LOCK_R |=  GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= 1;
    GPIO_PORTF_DEN_R |= 0x11;
    GPIO_PORTF_PUR_R |= (SW1 | SW2);
    GPIO_PORTF_DIR_R &= ~0x11;
    GPIO_PORTF_DIR_R |= 0b10;
    GPIO_PORTF_DATA_R  |= 0x2;

    //PORT B CONFIG
    GPIO_PORTB_DEN_R |= 0xff;
    GPIO_PORTB_DIR_R |= 0xff;

    //PORT E CONFIG
     GPIO_PORTB_DEN_R |= 0xe;
     GPIO_PORTB_DIR_R |= 0xe;

}

void sys_start(){
    
}
