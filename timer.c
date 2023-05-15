#include<reg51.h>
#define ON 1
#define OFF 0

sbit led=P2^0;

unsigned int i=0;

void delay();

void delay()
	{
		TMOD = 0x01;    // Timer0 mode1
		TH0 = 0xFC; 	 //initial value for 1ms
		TL0 = 0x66;
		TR0 = 1;      // timer start
		while(TF0==0);  // check overflow condition
		TR0 = 0;     // Stop Timer
		TF0 = 0;    // Clear flag
	}

void main()
	{
		while(1)
			{
				led = ON;
				for(i=0;i<1000;i++)
				{
					delay();
				}
				led = OFF;
				for(i=0;i<1000;i++)
				{
					delay();
				}
			}
	}
