
#include "s3c2440_soc.h"

void delay(volatile int d)
{
	while (d--);
}

int main(void)
{
	int val = 0;  /* val: 0b0000, 0b1111 */
	int tmp;

	/* GPBCON/5/6/7/8 */
	GPBCON &= ~((3<<(2*5)) | (3<<(2*6)) | (3<<(2*7)) | (3<<(2*8)));
	GPBCON |=  ((1<<(2*5)) | (1<<(2*6)) | (1<<(2*7)) | (1<<(2*8)));

	/* light led */
	while (1)
	{
		tmp = ~val;
		if(val ==0)
		{
			//GPBDAT 
			GPBDAT |= 0x7FF;
			GPBDAT &= ~(1<<5);
		}
		else if(val ==1)
		{
			GPBDAT |= 0x7FF;
			GPBDAT &= ~(1<<6);
			//GPBDAT |=  (1<<6);
		}
		else if(val ==2)
		{
			GPBDAT |= 0x7FF;
			GPBDAT &= ~(1<<7);
			//GPBDAT |=  (1<<7);
		}
		else if(val ==3)
		{
			GPBDAT |= 0x7FF;
			GPBDAT &= ~(1<<8);
			//GPBDAT |=  (1<<9);
		}
		
		//tmp &= 15;
		//GPBDAT &= ~(15<<5);
		//GPBDAT |= (tmp<<5);
		delay(100000);
		val++;
		if (val == 4)
			val =0;		
	}

	return 0;
}



