#include "statemachine.h"
#include "src/lcd/lcd.h"
#include "src/tm4c123gh6pm.h"
#include "src/timer/timer0.h"
#include "../lcd/lcd.h"

int counter = 0;

int capture_input(){
    unsigned int sw1 = (GPIO_PORTF_DATA_R & SW1)? 0:1;
    unsigned  int sw2 = (GPIO_PORTF_DATA_R & SW2)? 0:1;
    return sw1 << 1 | sw2;
}

void update(){
    if (counter == 2)
        counter = 0;
    if (counter == -1)
        counter = 1;

}

void write(int counter){
    if(counter)
        write_lcd("Ziyad",5);
    else
        write_lcd("Hager",5);

}

void run(){

    LCD_start();
    while(1){

        int input = capture_input();
        switch (input) {
           case INCREMENT:
                counter++;
                update();
                LCD_start();
                write(counter);
                delaym(500);
                break;
            case DECREMENT:
                counter--;
                update();
                LCD_start();
                write(counter);
                delaym(500);
                break;
            case RESET:
                counter = 1;
                update();
                LCD_start();
                write(counter);
                delaym(500);
                break;
        }
    }
}
