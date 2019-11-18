#include "src/sysinit/sysinit.h"
#include "src/timer/timer0.h"
#include "lcd.h"


void write_lcd(unsigned char* data, short length){
    int i;
    for(i = 0; i<length;i++){
        LCD_data(data[i]);
        delaym(1);
    }
    }






void LCD_start(){
    delaym(20); /* initialization sequence */// Wait >15 ms after power is applied

    LCD_command(0x30);
    // command 0x30 = Wake up

    delaym(5);
    // must wait 5ms, busy flag not available

    LCD_command(0x30);
    // command 0x30 = Wake up #2

    delayu(100);
    // must wait 100us, busy flag not available

    LCD_command(0x30);
    // command 0x30 = Wake up #3

    delayu(100);
    // must wait 100us, busy flag not available

    // Prepare LCD Operation and Function

    LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */

    LCD_command(0x06); /* move cursor right */

    LCD_command(0x01); /* clear screen, move cursor to home */

    LCD_command(0x0F); /* turn on display, cursor blinking */



}

void LCD_reset(){

    LCD_command(0x1);
    // display clear DL 1 N 0 F 0
    LCD_command(0b00110000);
    //FUNCTION SET


    LCD_command(0x8);
    // display on\off b 0 c 0 d 0
    LCD_command(0x6);
    // entry mode set LD 1 S 0
}
void LCD_command(unsigned char command)

{

LCD_CTRL_DATA = 0;
/* RS = 0, R/W = 0 */

LCD_DATA_DATA = command;

LCD_CTRL_DATA = EN;
/* pulse E */

delayu(1);
/* Enable pulse Width */

LCD_CTRL_DATA = 0;

if (command < 4)

delaym(2);
/* command 1 and 2 needs up to 1.64ms */

else

delayu(40); /* all others 40 us */

}

void LCD_data(unsigned char data)

{

LCD_CTRL_DATA = RS; /* RS = 1, R/W = 0 */

LCD_DATA_DATA = data;

LCD_CTRL_DATA = EN | RS; /* pulse E */

delayu(1);

LCD_CTRL_DATA = 0;

delayu(40);
}


