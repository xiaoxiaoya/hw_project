
//gpb5-8 ~ led1-4

void delay_ms(volatile unsigned long ms)
{
	while(ms--);
}

int  main(void){
	
	int val;
	unsigned long* gpbcon = (unsigned long *)0x56000010;
	unsigned long* GPBDAT = (unsigned long *)0x56000014;
	
	*gpbcon &= ~((3<<10)|(3<<12)|(3<<14)|(3<<16));
	*gpbcon |=  ((1<<10)|(1<<12)|(1<<14)|(1<<16));
	//*GPBDAT = 0;
	while(1){
		for(val=5;val <9; val++){
			*GPBDAT = 0x7FF;
			*GPBDAT =~(1<<val);
			delay_ms(10000);
		}
		val = 5;
	}
	return 0;
}
