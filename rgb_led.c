#include <avr/io.h>
#include <util/delay.h>


// RED = PIN 6
#define RED PH3
// GREEN = PIN 5
#define GREEN PE3
// BLUE = PIN 4
#define BLUE PG5

int main(void){

    // set RED, GREEN, BLUE as an output
    DDRH |= (1 << RED);
    DDRE |= (1 << GREEN);
    DDRG |= (1 << BLUE);

    while(1) {

        // set RED light to HIGH (1)
        PORTH |= (1 << RED);
        
        //wait
        _delay_ms(25000);

        // set RED light to LOW (0)
        PORTH &= ~(1 << RED);

        // set GREEN light to HIGH (1)
        PORTE |= (1 << GREEN);

        //wait
        _delay_ms(25000);

        // set GREEN light to LOW (0)
        PORTE &= ~(1 << GREEN);

        // set BLUE light to HIGH (1)
        PORTG |= (1 << BLUE);

        //wait
        _delay_ms(25000);

        // set BLUE light to LOW (0)
        PORTG &= ~(1 << BLUE);

    }


    return 0;
}
