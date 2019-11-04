#include "sysinit.h"
#include "tm4c123gh6pm.h"
#include "src/timer/timer0.h"

void sys_init(){

    //ENABLING CLOCK AND DELAY
    SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R2 | SYSCTL_RCGCGPIO_R4);
    delay(300);

 /*   //PORT F CONFIG
    GPIO_PORTF_LOCK_R |=  GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= 1;
    GPIO_PORTF_DEN_R |= 0x11;
    GPIO_PORTF_PUR_R |= (SW1 | SW2);
    GPIO_PORTF_DIR_R &= ~0x11;
    GPIO_PORTF_DIR_R |= 0b10;
    GPIO_PORTF_DATA_R  |= 0x2;
    */

    //PORT B CONFIG
    GPIO_PORTB_DEN_R |= 0xff;
    GPIO_PORTB_DIR_R |= 0xff;

    //PORT E CONFIG as KEYPAD input pins
    GPIO_PORTE_DEN_R |= 0xf;
    GPIO_PORTE_DIR_R &= ~0xf;
    GPIO_PORTE_PUR_R |= (C0|C1|C2|C3);

   //PORT C CONFIG as KEPAD output pins
    GPIO_PORTC_DEN_R |= 0xf0;
    GPIO_PORTC_DIR_R |= 0xf0;


}

