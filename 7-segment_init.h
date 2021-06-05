#include "tm4c123gh6pm.h"
#include "stdint.h"
unsigned char segments_code[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
sevenSegment_init();
delay();
delay_sm();
display_7segment(int num1, int num2, int num3);	
	
void sevenSegment_init(){
        SYSCTL_RCGC2_R    |= 0x02;
        while((SYSCTL_RCGC2_R & 0x02) == 0){}

        SYSCTL_RCGC2_R    |= 0x01;
        while((SYSCTL_RCGC2_R & 0x01) == 0){}



        GPIO_PORTB_CR_R     |=  0xFE;
        GPIO_PORTB_AMSEL_R  &= ~0xFE;
        GPIO_PORTB_PCTL_R   &= ~0xFE;
        GPIO_PORTB_AFSEL_R  &= ~0xFE;
        GPIO_PORTB_DEN_R    |= 0xFE; 
        GPIO_PORTB_DIR_R    |= 0xFE;
        GPIO_PORTB_DATA_R   |= 0xFE;

        GPIO_PORTA_CR_R     |=  0xE0;
        GPIO_PORTA_AMSEL_R  &= ~0xE0;
        GPIO_PORTA_PCTL_R   &= ~0xE0;
        GPIO_PORTA_AFSEL_R  &= ~0xE0;
        GPIO_PORTA_DEN_R    |=  0xE0; 
        GPIO_PORTA_DIR_R    |=  0xE0;
        GPIO_PORTA_DATA_R   &= ~0xE0;


    }
	void delay(){
        int x;
        for(x = 0; x < 10000; ++x){

        }
    }
    void delay_sm(){
        int x;
        for(x = 0; x < 300; ++x){}
    }
    void display_7segment(int num1, int num2, int num3){
        GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & ~0xE0) | 0x80;
        GPIO_PORTB_DATA_R = ~segments_code[num1];
        delay_sm();
        GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & ~0xE0) | 0x40;
        GPIO_PORTB_DATA_R = ~segments_code[num2];
        delay_sm();
        GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & ~0xE0) | 0x20;
        GPIO_PORTB_DATA_R = ~segments_code[num3];
        delay_sm();
    }
   void display(int y){
    int ones = y%10;
    int tens = (y%100 - ones)/10;
    int hundreads = (y/100);


    display_7segment(hundreads,tens,ones);
}
