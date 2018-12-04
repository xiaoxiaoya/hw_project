
.text
.global _start
_start:
    ldr r0,=0x56000050
    mov r1,#0x400
    str r1,[r0]

    ldr r0,=0x56000054
    mov r1,#0
    str r1,[r0]
halt:
    b halt