all:
	arm-linux-gcc -c -o led_on.o led_on.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o led_on.o -o led.elf
	arm-linux-objcopy -O binary -S led.elf led.bin
	arm-linux-objdump -D led.elf > led.dis
clean:
	rm *.bin *.o *.elf *.dis
	
		
	
