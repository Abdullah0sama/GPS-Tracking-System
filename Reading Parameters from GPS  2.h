
char UART2_Read(void)
{
	while((UART1_FR_R & 0x0010) != 0);
	return (UART1_DR_R&0xFF);
}
double readThis2()
{	
	char *y;
	char c;
	char *x;
  int i=0;
	int t=0;
	for(i=0;i<500;i++)
	{
		c = UART2_Read();
		x[i] = c;
		if(x[i]==',' && x[i-1]=='A' && x[i-2]=='G' && x[i-3]=='G' && x[i-4]=='P' && x[i-5]=='G' && x[i-6]=='$')
		{
			for(t=0;t<26;t++)
			{
				c = UART2_Read();
				if(t==23 || t==24 || t==25){y[t-23]=c;}
			}
			break;
		}
	}
	return (double)((y[0]*100)+(y[1]*10)+(y[2]));
}
