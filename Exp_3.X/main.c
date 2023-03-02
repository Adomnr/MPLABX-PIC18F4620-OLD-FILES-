/*
* File: XC8.c
* Author: Ubaid Rehman
*
* Created on December 1, 2021, 5:33 PM
*/
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "exp_3_h.h"

void main(void) { 
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    OSCCON = 0x76;
    while (1)
    {
        LATBbits.LATB0= ~LATBbits.LATB0;
        for (int countDelay=0; countDelay <20; countDelay ++)__delay_ms(5);
        LATBbits.LATB1= ~LATBbits.LATB1;
        for (int countDelay=0; countDelay <20; countDelay ++)__delay_ms(5);
     }
     return;
}
