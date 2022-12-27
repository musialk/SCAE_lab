#include <REGX52.H>

void Delay(void);
void Delay1(void);

void main (void)

{
   while(1)
   {
      P2 = 0x3F;
		Delay ();		 
      P2 = 0xCF;
		Delay1 ();
      P2 = 0xF3;
		Delay ();		
      P2 = 0xFC;
		Delay1 ();

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

void Delay1(void)
{
	int i;
	int j;
   for(i=0;i<200;i++)
   {
      for(j=0;j<200;j++){}
	 }
}