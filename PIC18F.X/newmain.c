/*
* File: XC8.c
* Author: Ubaid Rehman
*
* Created on December 1, 2021, 5:33 PM
*/
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "newxc8_header.h"

void main(void) { 
    DDRBbits.RB0 = 0;
    DDRBbits.RB1 = 0;
    OSCCON = 0x76;
    while (1)
    {
        LATBbits.LATB0= ~LATBbits.LATB0;

        for (int countDelay=0; countDelay <20; countDelay ++)__delay_ms(50);
        LATBbits.LATB1= ~LATBbits.LATB1;
        for (int countDelay=0; countDelay <20; countDelay ++)__delay_ms(50);
     }
     return;
}
