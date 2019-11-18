#ifndef __LCD__
#define __LCD__


void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_start();
void LCD_reset();
void write_lcd(unsigned char* data, short length);
#endif
