
#include "s3c2440_soc.h"

void delay(volatile int d)
{
	while (d--);
}

int main(void)
{
	int val;
	
	/* GPBCON/5/6/7/8 */
	GPBCON &= ~((3<<(2*5)) | (3<<(2*6)) | (3<<(2*7)) | (3<<(2*8)));
	GPBCON |=  ((1<<(2*5)) | (1<<(2*6)) | (1<<(2*7)) | (1<<(2*8)));

	/* 按键配置为输入引脚:
	 * GPG0(K1),GPG3(K2),GPG5(K3),GPG6(K4)
	 */	
	GPGCON &= ~((3<<0) | (3<<6) | (3<<10) | (3<<12)) ;  

	/* 死循环 */
	while (1)
	{
		val = GPGDAT;
		GPBDAT |= 0x7FF;
		if (val & (1<<0)) /*K1 --> GPG0 */
		{
			
			GPBDAT |= (1<<5);
		}
		else
		{
			
			GPBDAT &= ~(1<<5);
		}

		if (val & (1<<3)) /* K2 --> GPG3 */
		{
			
			GPBDAT |= (1<<6);
		}
		else
		{
			
			GPBDAT &= ~(1<<6);
		}

		if (val & (1<<5)) /* K3 --> GPG5 */
		{
			GPBDAT |= (1<<7);
		}
		else
		{
			GPBDAT &= ~(1<<7);
		}
		if (val & (1<<6)) /* K4 --> GPG6 */
		{
			GPBDAT |= (1<<8);
		}
		else
		{
			GPBDAT &= ~(1<<8);
		}

		
	}

	return 0;
}



