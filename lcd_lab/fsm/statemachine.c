#include "statemachine.h"
#include "tm4c123gh6pm.h"
#include "../sevensegment/sevensegment.h"
#include "../timer/timer0.h"

int counter = 0;

int capture_input(){
    unsigned int sw1 = (GPIO_PORTF_DATA_R & SW1)? 0:1;
    unsigned  int sw2 = (GPIO_PORTF_DATA_R & SW2)? 0:1;
    return sw1 << 1 | sw2;
}

void update(){
    if (counter == 16)
        counter = 0;
    if (counter == -1)
        counter = 15;

    GPIO_PORTB_DATA_R = numbers[counter];
}

void run(){
    int input;
    while(1){
        input = capture_input();
        switch (input) {
           case INCREMENT:
                counter++;
                update();
                delay(500);
                break;
            case DECREMENT:
                counter--;
                update();
                delay(500);
                break;
            case RESET:
                counter = 10;
                update();
                delay(500);
                break;
        }
    }
}
