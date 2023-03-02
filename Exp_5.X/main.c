/*
 * File:   main.c
 * Author: Ubaid Rehman
 *
 * Created on December 15, 2021, 2:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Exp_5.h"
void main(void)
{
 TRISBbits.RB0 = 0;
 TRISBbits.RB1 = 0;
 TRISCbits.RC2 = 0;
 TRISCbits.RC1 = 0;
 TRISCbits.RC0 = 1;
 OSCCON = 0x76; 
 while (1)
 {
    if(PORTCbits.RC0 == 0) //check if the switch is closed
    {
        for(int c=0;c<=20;c++)__delay_ms(5); //wait for 100ms
        if(PORTCbits.RC0 == 0) //check if the switch is still closed
        {
            LATBbits.LATB0 = 1;
            LATBbits.LATB1 = 1; 
            LATCbits.LATC1 = 1;
            LATCbits.LATC2 = 1;
           
        }
    }
    else{
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 0;
        LATCbits.LATC1 = 0;
        LATCbits.LATC2 = 0;
    }
 }
 return;
}