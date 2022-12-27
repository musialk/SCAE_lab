#include <REGX52.H>
#define Zapal P0_0=0
#define Zgas P0_0=1

//int poz[]={0xE7,0xED,0xDB,0xB7,0xBD,0x7B,0xEB,0xDD,0xBB,0x77,0x7D};

unsigned char bdata Key;
sbit Key_4=Key^4;
sbit Key_5=Key^5;
sbit Key_6=Key^6;
sbit Key_7=Key^7;

void wait(void)
{
	unsigned char data i,j;
	for (i=0; i<100; i++)
		for (j=0; j<100; j++)
	{;}
}

void work1(void)
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

void work2(void)
{
	unsigned char data i;
	for (i=2; i>0; i--)
	{
		Zapal;
		wait();
		Zgas;
		wait();
	}
}

void work12(void)
{
	unsigned char data i;
	for (i=12; i>0; i--)
	{
		Zapal;
		wait();
		Zgas;
		wait();
	}
}

void main(void)
{
	unsigned char code Koder[]={0xFD,0xFB,0xF7,0xFD};
	unsigned char data index=0;
	bit Ready=1;

 while(1)
	{
		P2=Koder[index];
		Key=P2;
		if ((Key_4&Key_5&Key_6&Key_7)==0)
		{
			if (Ready==1)
			{
				switch(Key)
			{
				case 0xE7:
				{
					work1();
					break;
				}
				case 0xEB:
				{
					work12();
					break;
				}
				case 0xED:
				{
					work1();
					break;
				}
				case 0xD7:
				{
					work1();
					break;
				}
				case 0xDB:
				{
					work2();
					break;
				}
				case 0xDD:
				{
					work1();
					break;
				}
				case 0xB7:
				{
					work1();
					break;
				}
				case 0xBB:
				{
					work1();
					break;
				}
				case 0xBD:
				{
					work2();
					break;
				}
				case 0x77:
				{
					work1();
					break;
				}
				case 0x7B:
				{
					work2();
					break;
				}
				case 0x7D:
				{
					work2();
					break;
				}
			}
			Ready=0;
		}
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