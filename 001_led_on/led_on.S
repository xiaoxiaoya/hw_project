

/*
 * ����LED1: GPB5
 *CPBCON:0x56000010
 */

.text
.global _start

_start:

/* 设置GPB5为输出引脚
 * CPBCON：0x56000010
 */
	ldr r1, =0x56000010
	//ldr r0, =0x400	/* mov r0, #0x100 */
	ldr r0, =0x15400	/* mov r0, #0x100 */
	str r0, [r1]


/* 设置GPB5为低电平 
 * GPBDAT：0x56000014
 */
	ldr r1, =0x56000014
	ldr r0, =0	/* mov r0, #0 */
	str r0, [r1]

	/* 死循环 */
halt:
	b halt

