
#include "led_on.h"

int main(void)
{

	/*1.设置led引脚为输出引脚*/
	GPBCON = 0x400;

	/*2.设置led引脚输出低电平*/
	GPBDAT =0;
	return 0; 
}
