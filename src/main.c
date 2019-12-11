#include "settings.h"
#include "macros.h"
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = DDRD | (1 << PD0);
    DDRD = DDRD | (1 << PD1);
    DDRD = DDRD | (1 << PD2);
    DDRD = DDRD | (1 << PD3);
    DDRD = DDRD | (1 << PD4);
    DDRD = DDRD | (1 << PD5); //Nastaví PD5 jako výstup
    DDRD = DDRD | (1 << PD6);
    DDRB = DDRB & ~(1 << PB7); 
    PORTB = PORTB | (1 << PB7); //PIN7 je vstup s rezistorem

    while (1) {
        if (!(PINB & (1 << PB7))) //Změna nastane při puštění tlačítka
        {
        switch(rand()%7) //vybere náhodně z 6ti případů
        {
            case 0: //případ 0
                PORTD = 0b01110111;
                break;
            case 1:
                PORTD = 0b00111110;
                break;
            case 2:
                PORTD = 0b00110110;
                break;
            case 3:
                PORTD = 0b00101010;
                break;
            case 4:
                PORTD = 0b00100010;
                break;
            case 5:
                PORTD = 0b00001000;
                break;
        }
        }
    }

    return 0;
}                               /* main */
