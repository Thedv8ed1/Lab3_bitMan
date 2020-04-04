/*	Author: jsadl003
 *  Partner(s) Name: Jason Sadler
 *	Lab Section: 021
 *	Assignment: Lab #  Exercise #
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
    DDRB = 0x00; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char cnt; 
    unsigned char i;
    while (1) {
        cnt = 0;
	i = 0;
	for(i = 0; i < 8; i++){
	    if(((PINA>>i)&0x01)){
	        cnt = cnt + 1;
	    }

	    if(((PINB>>i)&0x01)){
                cnt = cnt + 1;
            }
	    
	}
	PORTC = cnt;
    }
    return 1;
}
