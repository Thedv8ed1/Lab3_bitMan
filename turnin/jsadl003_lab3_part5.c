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
    DDRB = 0xFE; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0xFF; PORTC = 0x00;
    DDRD = 0x00; PORTD = 0x00;
    /* Insert your solution below */
    unsigned short tmpB;
    unsigned short tmpD;
    unsigned int weight;
    unsigned char airbag;
    while (1) {
	tmpD=0;tmpB=0;
        tmpD = PIND;
	tmpB = PINB;
	weight = 0;
	airbag = 0;
	weight = ((tmpD<<1) + (tmpB&0x01));
	if(weight >= 0x46){
	    airbag = 0x02;
	}
	else if(weight > 0x05 && weight < 0x46){
	    airbag = 0x04;
	}
	else{
	    
	}
	PORTB = ((airbag));
    }
    return 1;
}
