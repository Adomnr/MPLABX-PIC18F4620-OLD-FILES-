#include <stdio.h>
#include <stdlib.h>
#include "config.c" // File with Configuration bits
bit flag;            //Declare the Flag bit
//Interrupt Subroutine
 void interrupt CheckSwitchPressed()
   { //check if the interrupt is caused by the pin RB0
     if(INTCONbits.INT0F == 1) //Checks Receive Interrupt Flag bit
      {//Do your interrupt code, flash RB5 5 times
         for (int flash_count = 0;flash_count <10; flash_count++) {
         LATBbits.LATB5 = 1;
          for (int count=0; count<40; count++) __delay_ms(25); //Generate 1000ms delay
         LATBbits.LATB5 = 0;
         for (int count=0; count<40; count++) __delay_ms(25); //Generate 1000ms delay
       }
      INTCONbits.INT0F = 0;  // Clear Interrupt Flag
      } }
//Flashing routine (10 X) to call when there is an interrupt
 void FlashingRouting() {
     for (int flash_count = 0;flash_count<=10; flash_count++) {
  LATBbits.LATB5 = ~ LATBbits.LATB5;
  for (int count=0; count<20; count++) __delay_ms(15); //Generate 300ms delay
       }
     LATBbits.LATB5 = 0;
}
void main(void) {
    TRISB = 0x0F;         //Set PORTC as Output
  //  TRISBbits.RB0=1;   //Set PORTB Bit 0 as Input pin.
   // OSCCON=0x76;       //Configure OSCON Register to use
                       //internal oscillator (8MHz). Please check datasheet
    INTCONbits.INT0E = 1;    //enable Interrupt 0 (RB0 as interrupt)
    INTCON2bits.INTEDG0 = 0; //cause interrupt at falling edge
    INTCONbits.INT0F = 0;    //clear interrupt flag
     ei();     // This is like flipping the master switch to enable interrupt

     flag   = 0;      // Flag Variable initialization
    while (1)
    {
      LATBbits.LATB4 = 1;   //Switch ON B4
      for (int count=0; count<20; count++) __delay_ms(50); //Generate 1 sec delay
      LATBbits.LATB4 = 0;  //Switch OFF B4
      for (int count=0; count<20; count++) __delay_ms(50); //Generate 1 sec delay
    }
}