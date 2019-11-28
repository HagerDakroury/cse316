#include "statemachine.h"
#include "src/lcd/lcd.h"
#include "src/tm4c123gh6pm.h"
#include "src/timer/timer0.h"
#include "src/keypad/keypad.h"

char count[10]={'0','1','2','3','4','5','6','7','8','9'};

//0->receiving input 1->initial display
// 2->actively counting 3->idle  4->counting done
int counting=0;

int capture_switch(){
    unsigned int sw1 = (GPIO_PORTF_DATA_R & SW1)? 0:1;
    unsigned  int sw2 = (GPIO_PORTF_DATA_R & SW2)? 0:1;
    return sw1 << 1 | sw2;
}


void run(){
    LCD_start();
    int digits[4]={0,0,0,0};
    int digitCount=0;
    int seconds;
    int milliseconds=0;
    int input=0;
    while(1){
        input = capture_switch();

        //polling on the switch value
        switch (input) {

        //START COUNTING
           case COUNT:
                counting=1;
                break;
        //STOP COUNTING and reset
            case ABORT:
                counting=0;
                digitCount=0;
                LCD_start();
                break;
        }

        //prepare the timer value+display initial msg
        //next state is the actual counting
        if(counting==1){

            counting=2;
            seconds=digits[0]+digits[1]*10+digits[2]*100+digits[3]*1000;
            LCD_start();
            LCD_data(count[digits[3]]);
            LCD_data(count[digits[2]]);
            LCD_data(count[digits[1]]);
            LCD_data(count[digits[0]]);
            LCD_data('.');
            LCD_data(count[milliseconds]);
            LCD_data('0');
            delaym(100);

        }

        //counting state
        //counts until it reaches 0 or the abort switch is pressed
        else if (counting==2){
            //counter is done
             if(seconds==0 && milliseconds==0){
                 counting=4;

             }

             if(milliseconds==0){
                 milliseconds=9;
                 seconds--;
             }
             milliseconds--;


             //the counter display, refreshes every .1 second
             LCD_start();
             LCD_data(count[(seconds/1000)%10]);
             LCD_data(count[(seconds/100)%10]);
             LCD_data(count[(seconds/10)%10]);
             LCD_data(count[seconds%10]);
             LCD_data('.');
             LCD_data(count[milliseconds]);
             LCD_data('0');

             delaym(100);

           }


        //accept up to 4 digits from the keypad
        //initial state of the program
        else if(counting==0){


            if(digitCount==3)
                counting=3;

           input=capture_input();
           delaym(100);

            //accept only the numbers-> no letters
            if(input<10){

                digits[3-digitCount]=input;

                LCD_data(count[digits[3-digitCount]]);
                digitCount++;
            }


        }

        //final state
        //when the counter reaches 0 the end msg is displayed and the RED LED blinks for 3 sec
        else if(counting==4){
            char end[7]={'T','H','E',' ','E','N','D'};
            LCD_start();
            int i=0;
            for(i=0;i<7;i++){
                LCD_data(end[i]);
                delaym(1);
                    }

            for(i=0;i<5;i++){
                GPIO_PORTF_DATA_R  |= 0x2;
                delaym(1000);
                GPIO_PORTF_DATA_R  &=~0x2;
                delaym(1000);
        }
            counting=3;


        }



        }
}








