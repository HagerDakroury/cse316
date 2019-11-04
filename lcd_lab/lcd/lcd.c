#include "sysinit/sysinit.h"
#include "timer/timer0.h"
void LCD_command(unsigned char command)

{

LCD_CTRL_DATA = 0;
/* RS = 0, R/W = 0 */

LCD_DATA_DATA = command;

LCD_CTRL_DATA = EN;
/* pulse E */

delayUs(1);
/* Enable pulse Width */

LCD_CTRL_DATA = 0;

if (command < 4)

delayMs(2);
/* command 1 and 2 needs up to 1.64ms */

else

delayUs(40); /* all others 40 us */

}

void LCD_data(unsigned char data)

{

LCD_CTRL_DATA = RS; /* RS = 1, R/W = 0 */

LCD_DATA_DATA = data;

LCD_CTRL_DATA = EN | RS; /* pulse E */

delayUs(1);

LCD_CTRL_DATA = 0;

delayUs(40);
}


