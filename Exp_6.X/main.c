/*
 * File:   main.c
 * Author: Ubaid Rehman
 *
 * Created on December 19, 2021, 1:30 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Exp_6h.h" 
#define SW1 PORTCbits.RC0


void main(void) {
    TRISB = 0x00;	//Set PortB to all outputs
    TRISA = 0x00;
    TRISCbits.RC0 = 0x01;	//Set PortC.0 as input
    OSCCON = 0X76;	//SET fOR INTERNAL OSCCILATOR
    while(1){
        if (!SW1)	//Check if switch SW1 is closed
        {
            PORTB = 0x7F;
            PORTA = 0x06;
        }
        else
        {
            PORTB = 0x00;
            PORTA = 0x00;
        }
    }
}
