#include "LCD_init.h"
#include "LED_init.h"
#include  "7-segment_init.h"
void SystemInit(){}

int main(){
  //sevenSegment_init();
  //delay();
 // delay_sm();
 //display(555); 
	setupLED();
	turnOnLED();
        delay_milli(500);
        LCD_init();
        delay_milli(500);

for(;;)
  {
     delay_milli(500);

     LCD_Cmd(0x80);

     delay_milli(500);
     Lcd_String("GPS TRACKING");

     delay_milli(500);

    LCD_Cmd(0x02);
    delay_milli(100);
    LCD_Cmd(0xC0);
    delay_milli(100);


    Lcd_String("Distance=___");

  }
	
}	
	
	
