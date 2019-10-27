#include "sevensegment.h"
#include "../Timer/timer0.h"
#include "tm4c123gh6pm.h"

#define SW1 (1U<<4)
#define SW2 (1U<<0)


void init(){
    SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R5|SYSCTL_RCGCGPIO_R0);
    GPIO_PORTF_LOCK_R |=  GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= 1;
    GPIO_PORTF_DEN_R |= 0x11;  // enabling PORT F FIRST 5 PINS 
    GPIO_PORTF_PUR_R |= (SW1 | SW2);
    GPIO_PORTF_DIR_R &= ~0x11;

    GPIO_PORTA_DEN_R |=0Xff;
    GPIO_PORTA_DIR_R |=0xff;
}

//TODO change the port
void dataconfig(int number){
    GPIO_PORTA_DATA_R=0x0;
    GPIO_PORTA_DATA_R=numbers[number];
    
}

/*void main(){
    int counter=0;

    while(1){
        if(!(GPIO_PORTF_DATA_R & SW1)){
            counter++;
        }
        else if(!(GPIO_PORTF_DATA_R & SW2)){
            counter--;
        }
        else if (!((GPIO_PORTF_DATA_R & SW2) | (GPIO_PORTF_DATA_R & SW2)) ){
            counter=0;
        }

        switch (counter){
            case 0:
            dataconfig(0);
                break;
            case 1:
            dataconfig(1);
                break;
            case 2:
            dataconfig(2);
                break;
            case 3:
            dataconfig(3);
                break;
            case 4:
            dataconfig(4);
                break;
            case 5:
            dataconfig(5);
                break;
            case 6:
            dataconfig(6);
                break;
            case 7:
            dataconfig(7);
                break;
            case 8:
            dataconfig(8);
                break;
            case 9:
            dataconfig(9);
                break;
            case 10:
            dataconfig(10);
                break;
            case 11:
            dataconfig(11);
                break;
            case 12:
            dataconfig(12);
                break;
            case 13:
            dataconfig(13);
                break;
            case 14:
            dataconfig(14);
                break;
            case 15:
            dataconfig(15);
                break;
        }
        timer0_set(1,1); //set timer0 A to one sec in one-shot mode
        while(!timeout());
        timer0_reset();
    }

}
*/



//the smart thing to do
void main(){

    int counter=0;
    while(1){
        
        if(!(GPIO_PORTF_DATA_R&sw1)){
            counter++;
            if(counter==16)
                counter=0;
            dataconfig(counter);
            
        timer0_set(1,1); //set timer0 A to one sec in one-shot mode
        while(!timeout());
        timer0_reset();
            
        }

        else if(!(GPIO_PORTF_DATA_R&sw2)){
          counter--;
          if(counter==-1)
                counter=15;
          dataconfig(counter);
          
        timer0_set(1,1); //set timer0 A to one sec in one-shot mode
        while(!timeout());
        timer0_reset();
   
        }

        else if (!((GPIO_PORTF_DATA_R & SW2) | (GPIO_PORTF_DATA_R & SW2)) ){
            counter=0;
            dataconfig(counter);
            
        timer0_set(1,1); //set timer0 A to one sec in one-shot mode
        while(!timeout());
        timer0_reset();
        }

    }
}



