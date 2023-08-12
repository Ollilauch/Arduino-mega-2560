default:
	avr-gcc $(file).c -mmcu=atmega2560 -Os -o $(file).out
	avr-objcopy -j .text -j .data -O ihex $(file).out $(file).hex
	sudo avrdude -patmega2560 -cwiring -P/dev/ttyACM0 -D -Uflash:w:$(file).hex:i

#rgb:
#	avr-gcc rgb_led.c -mmcu=atmega2560 -Os -o rgb_led.out
#	avr-objcopy -j .text -j .data -O ihex rgb_led.out rgb_led.hex
#	sudo avrdude -patmega2560 -cwiring -P/dev/ttyACM0 -D -Uflash:w:rgb_led.hex:i
#
#button:
#	avr-gcc button_led.c -mmcu=atmega2560 -Os -o button_led.out
#	avr-objcopy -j .text -j .data -O ihex button_led.out button_led.hex
#	sudo avrdude -patmega2560 -cwiring -P/dev/ttyACM0 -D -Uflash:w:button_led.hex:i

# DEPRECATED
	#avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c -o blink_led.o blink_led.c
	#avr-gcc -o blink_led.bin blink_led.o
	#avr-objcopy -O ihex -R .eeprom blink_led.bin blink_led.hex
	#sudo avrdude -F -V -c arduino -p ATMEGA2560 -P /dev/ttyACM0 -b 115200 -U flash:w:blink_led.hex
