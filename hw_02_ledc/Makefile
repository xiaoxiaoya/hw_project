all:
	arm-linux-gcc -c -o led_c.o led_c.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led_c.o -o led_c.elf
	arm-linux-objcopy -O binary -S led_c.elf led_c.bin
	arm-linux-objdump -D led_c.elf >led_c.dis
clean:
	rm *.o *.elf *.bin *.dis