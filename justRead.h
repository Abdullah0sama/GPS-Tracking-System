char UART1_Read(void)
{
    while((UART1_FR_R & 0x0010) != 0);
    return (UART1_DR_R&0xFF);
}
unsigned char* justRead(void)
{
    unsigned char *c;
    int i=0;
    for(i=0;i<5;i++)
    {
        c[i]=UART1_Read();
    }
    return c;
}
unsigned char* leaveSomeTakeSome(void)
{
 unsigned char* c;
 unsigned char* d;
 int i;
 for(i=0;i<10;i++)
  {
    d[i]=UART1_Read();
    if(i==7||i==8||i==9)
      {
        c[i]=UART1_Read();
      }
  }
 return c; 
}
