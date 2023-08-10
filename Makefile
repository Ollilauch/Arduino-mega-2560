default:
	#avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c -o blink_led.o blink_led.c
	#avr-gcc -o blink_led.bin blink_led.o
	#avr-objcopy -O ihex -R .eeprom blink_led.bin blink_led.hex
	#sudo avrdude -F -V -c arduino -p ATMEGA2560 -P /dev/ttyACM0 -b 115200 -U flash:w:blink_led.hex
	avr-gcc blink_led.c -mmcu=atmega2560 -Os
	avr-objcopy -j .text -j .data -O ihex a.out a.hex
	sudo avrdude -patmega2560 -cwiring -P/dev/ttyACM0 -D -Uflash:w:a.hex:i
