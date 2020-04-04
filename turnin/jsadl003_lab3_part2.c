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
    DDRB = 0x00; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
   ; 
    unsigned char fuel;
    unsigned char fuelCheck;
    while (1) {
        fuelCheck = PINA;
        fuel = 0x00;
   	
   
	if(fuelCheck == 0x00){
      	    fuel = 0;
   	}
	else if(fuelCheck <= 0x02){
	    fuel = 0x20;  
	}
	else if(fuelCheck <= 4){
	    fuel = 0x30;
	}
	else if(fuelCheck <= 6){
	    fuel = 0x38;
	}
	else if(fuelCheck <= 9){
	    fuel = 0x3C;
	}
	else if(fuelCheck <= 12){
	    fuel = 0x3E;
	}
	else if(fuelCheck <= 15){
	    fuel = 0x3F;
	}
  
	if(fuelCheck <= 0x04){
	    fuel = (fuel | 0x40); 
	}
	else{
	    fuel = (fuel  & 0x3F); 
	}
	PORTC = fuel;   
    }
    return 1;
}
