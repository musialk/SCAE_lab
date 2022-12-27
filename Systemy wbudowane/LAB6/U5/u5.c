#include <REGX52.H>

#define max 0xFF
#define min 0x00
#define nex (max/3)
#define speed1 (nex*1)
#define speed2 (nex*2)
#define speed3 (nex*3)
#define speed0 min

volatile unsigned char data kod;
volatile unsigned char data wpis;
volatile unsigned char data Licznik = 0x00;
volatile unsigned char data Silnik = 0x00;
unsigned char bdata stan = 0x00;
bit wybor = 1;

sbit En1 = P2^3;
sbit En2 = P2^4;
sbit stan_0 = stan^0;
sbit stan_1 = stan^1;

void set(unsigned char predkosc)
	{
		if(predkosc=='0') {Silnik=speed0;}
			if(predkosc=='1') {Silnik=speed1;}
			if(predkosc=='2') {Silnik=speed2;}
			if(predkosc=='3') {Silnik=speed3;}
	}
	
void pwm (void) interrupt 5
	{
		TF2 = 0;
		EXF2 = 0;
		if ((Licznik <= Silnik) & (wpis == 0))
		{
			P2 |= 0x18;
			wpis = 1;
		}
		if ((Licznik > Silnik) & (wpis == 1))
		{
			P2 &= 0xE7;
			wpis = 0;
		}
	if (Licznik == max) { Licznik = 0;}
	Licznik++;
}

void Init(void)
	{
		P2 = 0x00;
		kod = '0';
		ET2 = 1;
		T2CON = 0x00;
		TH2 = 0XFF;
		TL2 = 0XFF;
		RCAP2L = 0X0F0;
		RCAP2H = 0XFF;
		TR2 = 1;
		kod = 0;
		set (kod);
		EA = 1;
	}
	
void main(void)
	{
		Init();
		while(1)
		{
			stan_0 = out3;
			stan_1 = out4;
			wybor = P3_3;
			if(wybor==0)
			{
				while(P3_3==0) {;}
					if(stan==0) {kod = '0'; set (kod);}
					if(stan==1) {kod = '1'; set (kod);}
					if(stan==2) {kod = '2'; set (kod);}
					if(stan==3) {kod = '3'; set (kod);}
					P2 &= 0xBD;
					P2 |= 0x24;
			}
		}
	}