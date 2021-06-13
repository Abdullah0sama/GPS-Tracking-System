#include <stdint.h>
#include <string.h>
#include <stdlib.h>

struct position{
    double lat;
    double lon;
};

char UART2_Read(void)
{
	while((UART2_FR_R & 0x0010) != 0);
	return (UART2_DR_R&0xFF);
}
pos readThis()
{	
	pos currentPos;
	char x[10];
	char y[7];
	char z[11];
	char m[3];
	double q;
	double v;
        int i=0;
	int t=0;
	for(i=0;i<500;i++)
	{
		y[i] = UART2_Read();
		if(y[i]==',' && y[i-1]=='L' && y[i-2]=='L' && y[i-3]=='G' && y[i-4]=='P' && y[i-5]=='G' && y[i-6]=='$')
		{
			for(t=0;t<24;t++)
			{
				if(t==10 || t==11 || t==12)
				{
				  m[t-10]= UART2_Read();
				}
				else if(t==13 || t==14 || t==15||t==16 || t==17 || t==18||t==19 || t==20 || t==21||t==22 || t==23)
				{
			          z[i-13]= UART2_Read();
				}
				else
				{
				  x[i] = UART2_Read();
				}
			}
		   q=atof(x);
	           v=atof(z);
			   currentPos.lat = q;
			   currentPos.lon = v;
			break;
		}
	}
	return currentPos;
}
