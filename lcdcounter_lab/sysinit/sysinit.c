#include "sysinit.h"
#include "src/timer/timer0.h"

void sys_init(){

    //ENABLING CLOCK AND DELAY
    SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R5| SYSCTL_RCGCGPIO_R0|SYSCTL_RCGCGPIO_R2 | SYSCTL_RCGCGPIO_R4);
    delaym(300);

    //PORT F CONFIG
    GPIO_PORTF_LOCK_R |=  GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= 1;
    GPIO_PORTF_DEN_R |= 0x11;
    GPIO_PORTF_PUR_R |= (SW1 | SW2);
    GPIO_PORTF_DIR_R &= ~0x11;
    GPIO_PORTF_DIR_R |= 0b10;
    GPIO_PORTF_DATA_R  |= 0x2;

    //PORT B CONFIG FOR LCD DATA
    GPIO_PORTB_DEN_R |= 0xff;
    GPIO_PORTB_DIR_R |= 0xff;

    //PORT A CONFIG FOR LCD CONTROL
     GPIO_PORTA_DEN_R |= 0x1C;
     GPIO_PORTA_DIR_R |= 0x1C;

     //PORT E CONFIG as KEYPAD input pins
     GPIO_PORTE_DEN_R |= 0xf;
     GPIO_PORTE_DIR_R &= ~0xf;
     GPIO_PORTE_PUR_R |= (C0|C1|C2|C3);

    //PORT C CONFIG as KEPAD output pins
     GPIO_PORTC_DEN_R |= 0xf0;
     GPIO_PORTC_DIR_R |= 0xf0;


}

void sys_start(){
    
}
