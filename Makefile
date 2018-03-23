PROJECT = lab4
lab4:
	avr-as -mmcu=atmega328p -o $(PROJECT)a.o $(PROJECT).asm
	avr-gcc -mmcu=atmega328p -c -o $(PROJECT)c.o $(PROJECT).c
	avr-ld -o $(PROJECT).elf $(PROJECT)a.o $(PROJECT)c.o 
	avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature $(PROJECT).elf $(PROJECT).hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$(PROJECT).hex
clean:
	rm -f *.hex *.o *.elf
