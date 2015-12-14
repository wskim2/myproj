NAME = blink

 CFLAGS = -g -Wall -Og -std=c99 -ffreestanding
 LDFLAGS = -nostdlib

 all: $(NAME).bin
  
 %.bin: %.elf
     arm-none-eabi-objcopy $< -O binary $@

 %.elf: %.o
     arm-none-eabi-gcc $(LDFLAGS) $< -o $@

 %.o: %.c
     arm-none-eabi-gcc $(CFLAGS) -c $< -o $@
 
 %.list: %.o
     arm-none-eabi-objdump -d $< > $@

 install: $(NAME).bin
     rpi-install.py $<

 clean:
     rm -f *.o *.elf *.bin *.list