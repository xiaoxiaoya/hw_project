
/*
 *@function:通过c函数来实现电灯
 *LED1~4:GPB5~8
 *GPBCON :0x56000010
 *nand :0
 *nor :0x40000000
 */

.text
.global  _start
_start:

	/*set sp*/
	ldr sp, =4096  /*nand*/


	/*调用main*/
	bl main
halt:
	b halt
	
		