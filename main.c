#include "LCD_init.h"
#include "LED_init.h"
void SystemInit(){}

int main(){
    setupLED();
	turnOnLED();
    delay_milli(500);
    LCD_init();
    delay_milli(500);

    for(;;)
  {
    delay_milli(100);

    LCD_Cmd(0x80);

    delay_milli(500);
    LCD_Data('H');
    LCD_Data('E');
    LCD_Data('L');
    LCD_Data('L');
    LCD_Data('O');
    LCD_Data(' ');
    LCD_Data('W');
    LCD_Data('O');
    LCD_Data('R');
    LCD_Data('L');
    LCD_Data('D');

    delay_milli(100);
    delay_milli(500);	
  }
	
	
	
	