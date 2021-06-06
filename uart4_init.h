#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void UART_Init(void){
SYSCTL_RCGCUART_R |=0x0004; //enable uart2 and Port D
SYSCTL_RCGCGPIO_R |=0x0008;
UART2_CTL_R &=~0x0001; //diable uart uartctl

UART2_IBRD_R = 0x0104; //change it from 204 to 104 default or 204 
UART2_FBRD_R = 0x11 ;   //as we changed value of ibrd from 204 to 104 to change fbrd  baudrate
UART2_LCRH_R = 0x0070;      
UART2_CTL_R |= 0x0001;  //enable uartctl

GPIO_PORTD_AFSEL_R |= 0xC0;
GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R &0x00FFFFFF)+0x11000000 ;
GPIO_PORTD_DEN_R |= 0xC0;     
GPIO_PORTD_AMSEL_R &=~ 0XC0;       

}

 uint8_t UART2_Read(void)
{
	while((UART2_FR_R & 0x0010) != 0);
	return (uint8_t)(UART2_DR_R&0xFF);
}
