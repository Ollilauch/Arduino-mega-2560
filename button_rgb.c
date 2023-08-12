/*
*   Make RGB LED light up when button is Pressed
*/

#include <avr/io.h>
#include <util/delay.h>

// BUTTON = PIN 9
#define BUTTON PH6

// RED = PIN 6
#define RED PH3
// GREEN = PIN 5
#define GREEN PE3
// BLUE = PIN 4
#define BLUE PG5

int main(void){
    
    // set BUTTON to an input
    DDRH &= ~(1 << BUTTON);
    // enable pullup to input (= default value is HIGH unless pulled LOW by i.e pressing)
    PORTH |=  (1 << BUTTON);

    // set LED to an output
    DDRH |= (1 << RED);
    DDRE |= (1 << GREEN);
    DDRG |= (1 << BLUE);

    PORTH |= (1 << RED);

    while(1){
        if(!(PINH & (1 << BUTTON))){
           
            // if RGB LED is RED turn RED to LOW and GREEN to HIGH
            // wait 10000 ms for debounce of button
            if(PINH & (1 << RED)){
                PORTH &= ~(1 << RED);
                PORTE |= (1 << GREEN);
                _delay_ms(10000);
            }

            // if RGB LED is GREEN turn GREEN to LOW and BLUE to HIGH
            // wait 10000 ms for debounce of button
            else if (PINE & (1 << GREEN)){
                PORTE &= ~(1 << GREEN);
                PORTG |= (1 << BLUE);
                _delay_ms(10000);
            }

            // if RGB LED is BLUE turn BLUE to LOW and RED to HIGH
            // wait 10000 ms for debounce of button
            else if(PING & (1 << BLUE)){
                PORTG &= ~(1 << BLUE);
                PORTH |= (1 << RED);
                _delay_ms(10000);
            }

        }
    }


}
