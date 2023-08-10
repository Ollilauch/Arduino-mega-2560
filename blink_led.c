#include <avr/io.h>
#include <util/delay.h>

// Arudino MEGA 2560 
// CHIP: ATmega2560
// BuiltIn LED Pin: 13 (PB7)

int main(void) {
    
    // set PORTB7 as an output
    DDRB = DDRB | (1 << DDB7);

    while(1) {
        // set PORTB7
        PORTB = PORTB | (1 << PORTB7);
        _delay_ms(8000);

        PORTB = PORTB & ~(1 << PORTB7);

        _delay_ms(8000);
    }

}
