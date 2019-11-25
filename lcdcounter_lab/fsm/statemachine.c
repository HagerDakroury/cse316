#include "statemachine.h"
#include "src/lcd/lcd.h"
#include "src/tm4c123gh6pm.h"
#include "src/timer/timer0.h"

 char* count[10]={{"0"},{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"}};
int counter = 0;

int capture_input(){
    unsigned int sw1 = (GPIO_PORTF_DATA_R & SW1)? 0:1;
    unsigned  int sw2 = (GPIO_PORTF_DATA_R & SW2)? 0:1;
    return sw1 << 1 | sw2;
}

void update(){
    if (counter == 10)
        counter = 0;
    if (counter == -1)
        counter = 9;

}

void run(){
    LCD_start();
        while(1){
            systick_delay(1);
            update();
            LCD_start();

            write_lcd(count[counter],1);
            counter--;

    }
}
