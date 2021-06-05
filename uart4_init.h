#include "tm4c123gh6pm.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void UART_Init(void){
SYSCTL_RCGCUART_R |=0x0004; //enable uart4 and Port D
SYSCTL_RCGCGPIO_R |=0x0008;
UART2_CTL_R &=~0x0001; //diable uart uartctl

UART2_IBRD_R = 0x0208; //or 104 
UART2_FBRD_R = 0x35 ;   //baudrate
UART2_LCRH_R = 0x0070;      
UART2_CTL_R |= 0x0001;  //enable uartctl

GPIO_PORTD_AFSEL_R |= 0xC0;
GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R &0x00FFFFFF)+0x11000000 ;
GPIO_PORTD_DEN_R |= 0xC0;     
GPIO_PORTD_AMSEL_R &=~ 0XC0;       

}

long long UART1_Read(void)
{
	while((UART1_FR_R & 0x0010) != 0);
	return (long long)(UART1_DR_R&0xFF);
}
