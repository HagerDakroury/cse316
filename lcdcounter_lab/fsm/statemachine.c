#include "statemachine.h"
#include "src/lcd/lcd.h"
#include "src/tm4c123gh6pm.h"
#include "src/timer/timer0.h"
#include "src/keypad/keypad.h"

char count[10]={'0','1','2','3','4','5','6','7','8','9'};
int counter=0;
//1->counting 0->receiving input
int counting=0;

int capture_switch(){
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
    int digits[4]={0,0,0,0};
   // int digitCount=0;
    int seconds;
    int minutes;
    int temp;
    int input;
    while(1){
        input = capture_switch();
        switch (input) {

        //START COUNTING
           case COUNT:
                counting=1;
                break;
        //STOP COUNTING
            case ABORT:
                counting=0;
                break;
        }

        if(counting==1){
            counting=2;
            seconds=digits[3]+digits[2]*10;
            minutes=digits[1]+digits[0]*10;
            LCD_start();
            LCD_data(count[digits[0]]);
            LCD_data(count[digits[1]]);
            LCD_data(':');
            LCD_data(count[digits[2]]);
            LCD_data(count[digits[3]]);

            //display the count value
            //display the 4 digits
            //display the resolution thing
        }
        else if (counting==2){
             if(seconds==59){
                 seconds=0;
                 minutes++;
             }
             else{
                 seconds++;
             }
             LCD_start();
             LCD_data(count[(minutes/10)%10]);
             LCD_data(count[minutes%10]);
             LCD_data(':');
             LCD_data(count[(seconds/10)%10]);
             LCD_data(count[seconds%10]);

             digits[3]=seconds%10;
             temp=seconds/10;
             digits[2]=temp%10;

             digits[1]=minutes%10;
             temp=minutes/10;
             digits[0]=temp%10;

             delaym(1000);

                     }



            //display the count value
            //display the 4 digits
            //display the resolution thing



        else{

            /*digits[digitCount]=capture_input();
                        digitCount++;*/

        }
}






    }

