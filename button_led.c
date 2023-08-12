/*
*   Make LED light up when button is Pressed
*/

#include <avr/io.h>
#include <util/delay.h>

// BUTTON = PIN 9
#define BUTTON PH6
// RED LED = PIN 2
#define LED    PE4

int main(void){
    
    // set BUTTON to an input
    DDRH &= ~(1 << BUTTON);
    // enable pullup to input (= default value is HIGH unless pulled LOW by i.e pressing)
    PORTH |=  (1 << BUTTON);

    // set LED to an output
    DDRE |= (1 << LED);

    while(1){
        if(!(PINH & (1 << BUTTON))){
            PORTE |= (1 << LED);
            _delay_ms(10000);
        }
        PORTE &= ~(1 << LED);
    }


}
