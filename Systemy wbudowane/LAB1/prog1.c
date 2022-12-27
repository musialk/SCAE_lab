#include <REGX52.H>

void Delay(void);

void main (void)

{
   while(1)
   {
      P2 = 0xFE;
		Delay ();
      P2 = 0xFD;
		Delay ();
      P2 = 0xFB;
		Delay ();
      P2 = 0xF7;
		Delay ();
      P2 = 0xEF;
		Delay ();		 
      P2 = 0xDF;
		Delay ();
      P2 = 0xBF;
		Delay ();
		 P2 = 0x7F;
		Delay ();
		 		
   }
}

void Delay(void)
{
   int j;
   int i;
   for(i=0;i<100;i++)
   {
      for(j=0;j<100;j++){}
   }
}