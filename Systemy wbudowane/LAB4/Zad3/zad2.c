#include <REGX52.H>

unsigned char code Tab[] = {0xEF, 0xDF, 0xBF, 0x7F};
unsigned char data ind; 																			//zmienia sie w zakresie od 0 do 3

extern void Setup(void); 																			//powiadomienie programu o funkcji

void main(void)
  {
		Setup();
		while(1)
			{
				P2 = Tab[ind];
				if(ind<0x03){ind++;}else{ind=0;}
			}
	}
	
void Send(unsigned char Value)
	{
		TI=0; 																						       	// bit powiazany z portem szeregowym
			SBUF=Value;
			while(TI==0){;}
		TI=0;
	}
	
void ISR_Key(void) interrupt 0 																	//zrodla przerwan 
	{
		unsigned char data Znak;
		
		EX0=0; 																											//WYLACZONY Z OBSLUGI
			Znak=P2;
				if(Znak==0xE7)
					{
						Send('1');
					}				
					if(Znak==0xEB)
					{
						Send('2');
					}
					if(Znak==0xED)
					{
						Send('3');
					}
					if(Znak==0xD7)
					{
						Send('4');
					}
					if(Znak==0xDB)
					{
						Send('5');
					}
					if(Znak==0xDD)
					{
						Send('6');
					}
					if(Znak==0xB7)
					{
						Send('7');
					}
					if(Znak==0xBB)
					{
						Send('8');
					}
					if(Znak==0xBD)
					{
						Send('9');
					}
					if(Znak==0x77)
					{
						Send('*');
					}
					if(Znak==0x7B)
					{
						Send('0');
					}
					if(Znak==0x7D)
					{
						Send('#');
					}
				while(P3_2==0x00){;}
			IE0=0;
		EX0=1;
	}
	
void Setup(void)
	{
		ind = 0;
		SCON=0x40; 																//ustawienie portu szeregowego na 8bitach
		RCAP2L=TL2=0xEE; 													//ustawienie timer 2, dolaczenie do portu szeregowego i konfiguracja, timer jest  16-bitowy
		RCAP2H=TH2=0xFF; 
		TCLK=1; 																	//wlaczony nadajnik portu szeregowego
		TR2=1; 																		//timer jest uruchomiony
		IT0 = 1; 																	//Obsluga zbocza opadajacego, kazde wcisniecie przycisku powoduje zapalenie niebieskiego kwadracika
		EX0 = 1; 																	//wlacza przerwanie od IT0
		EA = 1; 																	// Na koncu - wlacza wszystkie obslugi przerwan
	}