// przerwania1
//

#include <REGX52.H>

sbit LEDZielona = P2^0; // mrugaj od przerwania od licznika
sbit LEDZolta = P2^7; // mrugaj od przycisku
sbit SW = P3^2;

void timer0_isr() interrupt 1
{
TH0 = 0XCA; //zaladuj od nowa wybrana TH0
TL0 = 0X00;
LEDZielona =!LEDZielona; // Zmien stan diody zielonej
}

void main()
{
   TMOD = 0x01; //Timer0 mode 1
   TH0 = 0XFF; //Zaladuj wybrana wartosc TH0
   TL0 = 0X00;
   TR0 = 1; //turn ON Timer zero
   ET0 = 1; //Enable Timer0 Interrupt
   EA = 1; //Enable Global Interrupt bit
   SW = 1; //SW ma pracowac jako wejscie
        while(1)
          {
       LEDZolta= SW; //Stan przycisku na diodzie zoltej
    }
}