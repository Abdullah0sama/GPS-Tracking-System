#include <stdint.h>
#include <string.h>
#include <stdlib.h>

struct position{
    double lat;
    double lon;
};
typedef struct position pos;

char UART2_Read(void)
{
	while((UART2_FR_R & 0x0010) != 0);
	return (UART2_DR_R&0xFF);
}
pos readThis()
{	
	pos currentPos;
	char x[11];
	char y[200];
	char z[12];
	char m[3];
	double q;
	double v;
        int i=0;
	int t=0;
	for(i=0;i<500;i++)
	{
		while(i<6)
		{
		  y[i] = UART2_Read();
	          i++;
	        }
		y[i] = UART2_Read();
		if(y[i]==',' && y[i-1]=='L' && y[i-2]=='L' && y[i-3]=='G' && y[i-4]=='P' && y[i-5]=='G' && y[i-6]=='$')
		{
			for(t=0;t<500;t++)
			{
				if(t>=0 && t<=9)
				{
				  x[t] = UART2_Read();
				  x[10]='\0';
				}
				else if(t>=10 && t<=12)
				{
				  m[t-10]= UART2_Read();
				}
				else if(t>=13 && t<=23)
				{
			          z[t-13]= UART2_Read();
				  z[12]='\0';
				}
				else
				{
				  break;
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
