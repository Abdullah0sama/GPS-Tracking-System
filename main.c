#include "LCD_init.h"
#include "LED_init.h"
#include  "7-segment_init.h"
#include "Switch.h"
#include "TrackDistance.h"
#include "uart4_init"

void SystemInit(){}

void setup(){
  setupLED();
  setupSwitch();

}
int main(){
  UART_Init():	
  setup();
  delay_milli(500);
  LCD_init();
  delay_milli(500);
  LCD_Cmd(0x80);	
  delay_milli(500);
	
  trackDistance();
  	
  //sevenSegment_init();
  //delay();
 // delay_sm();
 //display(555); 	
}	
	
	
