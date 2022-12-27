#include <REGX52.H>

unsigned char xdata left _at_ 0xFE00;
unsigned char xdata right _at_ 0xFD00;
unsigned char code koder[] = {0x3F, 0x06};

void main(void)
	{
	unsigned char data index=0;
	while(1)
		{
		left = koder[index];
		right = koder[index];
		if(P3_2 == 0)
		 {
		 if(index==1)(index=0);
			else (index=1);
			while(P3_2==0)
			{
				left = koder[index];
				right = koder[index];
			}
		  }
		}
	}
