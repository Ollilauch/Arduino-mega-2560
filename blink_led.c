#include <avr/io.h>
#include <util/delay.h>

// Arudino MEGA 2560 
// CHIP: ATmega2560
// BuiltIn LED Pin: 13 (PB7)

int main(void) {
    
    // set PORTB7 (Pin 13) as an output
    //DDRB = DDRB | (1 << DDB7);
    
    // set Pin 11 (PB5) as an output
    DDRB |= (1 << PB5);

    while(1) {
        // set PORTB7 as HIGH (bit 1) and light
        //PORTB = PORTB | (1 << PORTB7);

        // set Pin 11 (PB5) as HIGH
        PORTB |= (1 << PB5);

        //wait
        _delay_ms(8000);

        //PORTB = PORTB & ~(1 << PORTB7);
        
        //set Pin 11 (PB5) as LOW
        PORTB &= ~(1 << PB5);

        //wait
        _delay_ms(8000);
    }

}
