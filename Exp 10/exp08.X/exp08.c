/* 
 * File:   exp08.c
 * Author: Muhammad Bilal Khan
 *
 * Created on July 11, 2021, 12:57 PM
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "exp08.h" //Include the Header File
void main(void) {
TRISBbits.RB0=0; //Set PORTB Bit 0 as Output pin.
TRISCbits.RC0=1; //Set PORTC Bit 1 as input pin.
OSCCON=0x76; //Configure OSCON Register to use
 //internal oscillator. Please check datasheetPage 109 of 139
 while (1)
 {
 if (PORTCbits.RC0==0)
 {
 LATBbits.LATB0= 1;
  for (int countDelay=0; countDelay <40; countDelay ++)__delay_ms(50); 
 }
 else {
 LATBbits.LATB0= 0;
  for (int countDelay=0; countDelay <40; countDelay ++)__delay_ms(50); 
 }
 }
}

