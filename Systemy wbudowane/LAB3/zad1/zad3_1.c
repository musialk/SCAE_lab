#include <REGX52.H>
#define Zapal P0_0=0
#define Zgas P0_0=1

unsigned char bdata Key;
sbit Key_3=Key^3;
sbit Key_2=Key^2;
sbit Key_1=Key^1;

void wait(void)
{
	unsigned char data i,j;
	for (i=0; i<200; i++)
		for (j=0; j<100; j++)
	{
		;
	}
}

void work(void)
{
	unsigned char data i;
	for (i=1; i>0; i--)
	{
		Zapal;
		wait();
		Zgas;
		wait();
	}
}

void main(void)
{
	unsigned char code Koder[]={0xEF,0xDF,0xBF,0x7F};
	unsigned char data index=0;
	bit Ready=1;

  while(1)
	{
		P2=Koder[index];
		Key=P2;
		if ((Key_3&Key_2&Key_1)==0)
		{
			if (Ready==1)
			{
				if (Key==0xE7)
				work();
				if (Key==0xEB)
				work();
				if (Key==0xED)
				work();
				if (Key==0xD7)
				work();
				if (Key==0xDB)
				work();
				if (Key==0xDD)
				work();
				if (Key==0xB7)
				work();
				if (Key==0xBB)
				work();
				if (Key==0xBD)
				work();
				if (Key==0x77)
				work();
				if (Key==0x7D)
				work();
				if (Key==0x7B)
				work();
			}
			
			Ready=0;
		}
		else
		{
			if (index<0x03)
			{
				index++;
			}
			else
			{
				index=0x00;
			}
			Ready=1;
		}
	}
}