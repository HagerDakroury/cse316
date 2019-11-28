#include "keypad.h"
#include "src/tm4c123gh6pm.h"
#include "src/timer/timer0.h"

const unsigned int keypad_map[4][4] = {
    { 1 , 2, 3 , 10},
    { 4 , 5, 6 , 11},
    { 7 , 8, 9 , 12},
    { 14, 0, 15, 13}
};

int row;
int col;

int capture_input(){
    for(;;){
        //Forcing Rows (output) to zeroes
        GPIO_PORTC_DATA_R &= ~0xf0;
        delaym(40);
        if ( (~(GPIO_PORTE_DATA_R & 0xf)) & C0 ){
            col = 0;
            row = get_row(col);
            delaym(40);
            return keypad_map[row][col];
        }  if ( (~(GPIO_PORTE_DATA_R & 0xf)) & C1 ){
            col = 1;
            row = get_row(col);
            delaym(40);
            return keypad_map[row][col];
        }  if ( (~(GPIO_PORTE_DATA_R & 0xf)) & C2 ){
            col = 2;
            row = get_row(col);
            return keypad_map[row][col];
        }  if ( (~(GPIO_PORTE_DATA_R & 0xf)) & C3 ){
            col = 3;
            row = get_row(col);
            delaym(40);

            return keypad_map[row][col];

        }
    }
}

int get_row(int col) {
    GPIO_PORTC_DATA_R &=  0x0f;
    GPIO_PORTC_DATA_R |=  0xe0;
    delaym(40);
    if ( (~(GPIO_PORTE_DATA_R & 0xf)) & (1 << col) ){
        return 0;
    }
    GPIO_PORTC_DATA_R &=  0x0f;
    GPIO_PORTC_DATA_R |=  0xd0;

    delaym(10);
    if ( (~(GPIO_PORTE_DATA_R & 0xf)) & (1 << col) ){
        return 1;
    }
    GPIO_PORTC_DATA_R &=  0x0f;
    GPIO_PORTC_DATA_R |=  0xb0;
    delaym(10);
    if ( (~(GPIO_PORTE_DATA_R & 0xf)) & (1 << col) ){
        return 2;
    }
    GPIO_PORTC_DATA_R &=  0x0f;
    GPIO_PORTC_DATA_R |=  0x70;
    delaym(10);

    if ( (~(GPIO_PORTE_DATA_R & 0xf)) & (1 << col) ){
        return 3;
    }
    return 0;
}
