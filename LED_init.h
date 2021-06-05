#include   "tm4c123gh6pm.h"



void setupLED(){
    SYSCTL_RCGC2_R    |= 0x20;
    while((SYSCTL_RCGC2_R & 0x20) == 0){}
    GPIO_PORTF_LOCK_R   = 0x4C4F434B;
    GPIO_PORTF_CR_R     |= 0x02;

    GPIO_PORTF_AMSEL_R  &= ~0x02;
    GPIO_PORTF_PCTL_R   &= ~0x02;
    GPIO_PORTF_AFSEL_R  &= ~0x02;
    GPIO_PORTF_DEN_R    |= 0x02;
    GPIO_PORTF_DIR_R    |= 0x02;
    GPIO_PORTF_DATA_R &= ~0x02;
}

void turnOnLED(){
    GPIO_PORTF_DATA_R |= 0x02;
}