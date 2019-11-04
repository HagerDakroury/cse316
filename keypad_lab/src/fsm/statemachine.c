#include "statemachine.h"
#include "tm4c123gh6pm.h"
#include "../sevensegment/sevensegment.h"
#include "../timer/timer0.h"
#include "src/keypad/keypad.h"

int counter = 0;


void update(){
    if (counter == 16)
        counter = 0;
    if (counter == -1)
        counter = 15;

    GPIO_PORTB_DATA_R = numbers[counter];
}

void run(){
    while(1){
        counter = capture_input();
        update();
        delay(400);

    }
}
