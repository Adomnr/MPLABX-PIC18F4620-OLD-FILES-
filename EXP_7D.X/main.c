#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <p18f4550.h>
#include "delays.h" 
#include "config.h"
#include "xlcd.h"

void init_XLCD(void); //Initialize LCD display
void DelayFor18TCY( void ); //18 cycles delay
void DelayPORXLCD (void); // Delay of 15ms
void DelayXLCD (void); // Delay of 5ms

void main(void)
{
 init_XLCD(); //Call the Initialize LCD display function
 putrsXLCD("Bilal Hayder"); //Display "Hello World"
 SetDDRamAddr(0x40); //shift cursor to beginning of second line
 putrsXLCD("19-EE-22"); //Display "LCD display"
 while(1)
 {
 }
 }
void init_XLCD(void) //Initialize LCD display
{ OpenXLCD(FOUR_BIT&LINES_5X7); //configure LCD in 4-bit Data Interface mode
 //and 5x7 characters, multiple line display
 while(BusyXLCD()); //Check if the LCD controller is not busy
 //before writing some commands?
 WriteCmdXLCD(0x06); // move cursor right, don?t shift display
 WriteCmdXLCD(0x0C); //turn display on without cursor

 }
void DelayFor18TCY( void ) //18 cycles delay
{
 Nop( ); Nop( ); Nop( ); Nop( ); // 18 cycle delay
 Nop( ); Nop( ); Nop( ); Nop( );
 Nop( ); Nop( ); Nop( ); Nop( );
 Nop( ); Nop( );
 return;
}

void DelayPORXLCD (void) // Delay of 15ms
{
 Delay1KTCYx(30);
}

void DelayXLCD (void) // Delay of 5ms
{
 Delay1KTCYx(10);
}