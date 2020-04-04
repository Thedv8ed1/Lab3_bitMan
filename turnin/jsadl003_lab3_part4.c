/*	Author: jsadl003
 *  Partner(s) Name: Jason Sadler
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
  DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
   ; 
    unsigned char hi;
    unsigned char low;
    while (1) {
	hi = PINA&0xF0;
	low = PINA&0x0F;
	PORTB = (hi>>4);
	PORTC = (low<<4);
    }
    return 1;
}
