.text
.global _start
_start:
	ldr sp,=0x40000000+4096
	bl main
halt:
	b halt