/*
* File: XC8.c
* Author: Ubaid Rehman
*
* Created on December 1, 2021, 5:33 PM
*/
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "newxc8_header1.h"

void main(void) { 
    TRISBbits.RB3 = 0;
    TRISBbits.RB4 = 0;
    OSCCON = 0x76;
    while (1) 
    {
        LATBbits.LATB3= ~LATBbits.LATB3;
        for (int countDelay=0; countDelay <200; countDelay ++)
            __delay_ms(50);
        LATBbits.LATB4= ~LATBbits.LATB4;
        for (int countDelay=0; countDelay <200; countDelay ++)
            __delay_ms(50);
     }
     return;
}
