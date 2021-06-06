#include <stdint.h>
#include "tm4c123gh6pm.h"
#include <string.h>

void delay_milli(int n);
void delay_micro(int n);
void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_init(void);
void Lcd_String(unsigned char* data);
void display_LCD(int y);

#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80


void LCD_init(void){
 //PORT(A7,A6,A5),PORTB clock
            delay_milli(20);
            SYSCTL_RCGCGPIO_R |= 0x01;
            SYSCTL_RCGCGPIO_R |= 0x02;
   while((SYSCTL_RCGCGPIO_R & 0x03) == 0)
            GPIO_PORTA_AFSEL_R = 0x00;
            GPIO_PORTA_AMSEL_R = 0x00;
            GPIO_PORTA_PCTL_R = 0x00;
            GPIO_PORTA_DIR_R |=0xE0; //PORTA controls RS,E and R/W
            GPIO_PORTA_DEN_R |=0xE0;

            GPIO_PORTB_AMSEL_R = 0x00;
            GPIO_PORTB_AFSEL_R = 0x00;
            GPIO_PORTA_PCTL_R = 0x00;
            GPIO_PORTB_DIR_R =0xFF; //PORTB D0-D7
            GPIO_PORTB_DEN_R =0xFF; //PORTB D0-D7

            delay_milli(50);
            LCD_Cmd(0x30); //8-bits,2 display lines, 5x7 font
            delay_milli(20);
            LCD_Cmd(0x30);
            delay_micro(140);
            LCD_Cmd(0x30);
            delay_milli(30);

            delay_milli(30);
            LCD_Cmd(0x38);
            delay_micro(60);
            LCD_Cmd(0x0F);
            delay_micro(50);
            LCD_Cmd(0x06);
            delay_milli(10);
            LCD_Cmd(0x01);
            delay_micro(50);
            delay_milli(30);
   }
void LCD_Cmd(unsigned char command) {
        GPIO_PORTA_DATA_R = 0x00; //RS =0, E=0, RW=0
        GPIO_PORTB_DATA_R =command;
        delay_micro(5);
        GPIO_PORTA_DATA_R =0x80; //E=1 to secure command
        delay_micro(5);
        GPIO_PORTA_DATA_R =0x00;
        if(command <4)           // Command 1,2,3 need more delay than other commands
            delay_milli(5);
        else
            delay_micro(50);
    }
	void LCD_Data(unsigned char data) {

     GPIO_PORTB_DATA_R =data;
     GPIO_PORTA_DATA_R =0x20; //RS=1, E=0,RW=0
	 
     delay_milli(50);
     delay_milli(50);

     GPIO_PORTA_DATA_R = 0x80 | 0x20;
     delay_micro(50);
     GPIO_PORTA_DATA_R  &= ~ 0x80;
     delay_micro(50);

    }
	
void Lcd_String(unsigned char* data)
{
	int i;
	for (i = 0; data[i] != 0; i++)
	{
		Lcd_Data(data[i]);
	}
}
 void display_LCD(int y){
         int ones = y%10;
         int tens = (y%100 - ones)/10;
         int hundreads = (y/100);
       unsigned char sad [3];
             sad[0] = hundreads + '0';
             sad[1] = tens + '0';
             sad[2] = ones + '0';
             Lcd_String(sad);
 }
// For Delay
void delay_milli(int n){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<3180;j++)
{}
}
}

void delay_micro(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3;j++)
{}
}
