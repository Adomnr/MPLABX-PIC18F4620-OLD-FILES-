/*
 * File:   main.c
 * Author: Ubaid Rehman
 *
 * Created on December 15, 2021, 1:49 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Exp_4h.h"
void main(void) { 
    TRISB = 0;
    TRISC = 0;
    OSCCON = 0x76; 
    while(1)
    {
        LATBbits.LATB0=~LATBbits.LATB0;
        LATBbits.LATB1=~LATBbits.LATB1;
        LATBbits.LATB2=~LATBbits.LATB2;
        LATCbits.LATC0=~LATCbits.LATC0;
        LATCbits.LATC1=~LATCbits.LATC1;
     for (int countDelay=0; countDelay <20; countDelay ++)__delay_ms(50); 
        LATBbits.LATB0=~LATBbits.LATB0;
        LATBbits.LATB1=~LATBbits.LATB1;
        LATBbits.LATB2=~LATBbits.LATB2;
        LATCbits.LATC0=~LATCbits.LATC0;
        LATCbits.LATC1=~LATCbits.LATC1;
     for (int countDelay=0; countDelay <40; countDelay ++)__delay_ms(50); 
     }
return;
}