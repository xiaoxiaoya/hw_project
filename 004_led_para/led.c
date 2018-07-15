
void delay(volatile int d)
{
	while (d--);
}

int led_on(int which)
{
	unsigned int *pGPFCON = (unsigned int *)0x56000010;
	unsigned int *pGPFDAT = (unsigned int *)0x56000014;

	if (which == 4)
	{
		/* GPB5 */
		*pGPFCON = 0x400;
	}
	else if (which == 5)
	{
		/* GPB6 */
		*pGPFCON = 0x1000;
	}
	
	/* ����GPF4/5���0 */
	*pGPFDAT = 0;

	return 0;
}



