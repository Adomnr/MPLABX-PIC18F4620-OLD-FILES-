/* 

*/ 
#include <stdio.h> 
#include <stdlib.h> 
#include "Exp7.h"

void init_XLCD(void); //Initialize LCD display 
void DelayFor18TCY( void ); //18 cycles delay 
void DelayPORXLCD (void); // Delay of 15ms 
void DelayXLCD (void); // Delay of 5ms 
void main(void) 
{ 
    OSCCON = 0x76;// Configure to use 8MHz internal oscillator 
    init_XLCD(); //Call the display function 
    SetDDRamAddr(0x01);
    putrsXLCD ("Ubaid-ur-Rehman"); //DiInitialize LCD splay "LCD display" 
    SetDDRamAddr(0x41); //shift cursor to beginning of second line 
    putrsXLCD("19-EE-10"); //Display "StudentCompanion" 
    while(1) 
    { 
    } 
} 
void init_XLCD(void) //Initialize LCD display 
{ 
    OpenXLCD(FOUR_BIT&LINES_5X7); //configure LCD in 4-bit Data Interface mode 
    //and 5x7 characters, multiple line display 
    while(BusyXLCD()); //Check if the LCD controller is not busy 
    //before writing some commands? 
    WriteCmdXLCD(0x06); // move cursor right, don?t shift display 
    WriteCmdXLCD(0x18); //turn display on without cursor 
} 
void DelayFor18TCY( void ) //18 cycles delay 
{
    Delay10TCYx(20); 
} 
void DelayPORXLCD (void) // Delay of 15ms 
{
    Delay1KTCYx(30); 
} 
void DelayXLCD (void) // Delay of 5ms 
{
    Delay1KTCYx(10); 
}