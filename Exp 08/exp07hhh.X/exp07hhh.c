/* 
 * File:   exp07hhh.c
 * Author: Muhammad Bilal Khan
 *
 * Created on July 9, 2021, 11:46 PM
 */

#include <xc.h>
#include "exp07hhh.h"
#include <stdio.h>
#include <stdlib.h>
#include <delays.h>
void init_ADC1(void); //Initialize ADC
void init_XLCD(void); //Initialize LCD display
void DelayFor18TCY( void ); //18 cycles delay
void DelayPORXLCD (void); // Delay of 15ms
void DelayXLCD (void); // Delay of 5ms
//**************Declare Global Variables******************
unsigned int ADCResult=0;
float voltage;
unsigned char Buffer[20];
void main(void)
{
 OSCCON=0x76; //Configure to use 8MHz internal oscillator.
 init_XLCD(); //Call the Initialize LCD display function
 init_ADC1(); //Call the Initialize ADC function
 putrsXLCD("ADC"); //Display "Hello World"
 SetDDRamAddr(0x40); //shift cursor to beginning of second line
 putrsXLCD("LCD display"); //Display "LCD display"
 for (int x=0; x<=20;x++) __delay_ms(50); // 1 second delay
 WriteCmdXLCD(0x01); //Clear Screen
 while(1)
 {
ADCResult =0;
 //---sample and convert----
ConvertADC(); //Start conversion
while(BusyADC()); //Wait here until conversion is finished
ADCResult =ReadADC(); //Read the converted data
voltage=ADCResult*(5.0)/1024;//convert the converted data into voltage
 //we divide by 1024 because its a 10-bit converted data
 putrsXLCD("Voltage= "); //Display "Voltage" on the screen
 sprintf(Buffer, "%.3g", voltage ); // Convert voltage to string
 putsXLCD(Buffer); //Display the Voltage on the screen
 putrsXLCD(" "); // Clear after comma
 WriteCmdXLCD(0x02); //Home position on LCD
 }
}
void init_XLCD(void) //Initialize LCD display
{
OpenXLCD(FOUR_BIT&LINES_5X7); //configure LCD in 4-bit Data Interface mode
 //and 5x7 characters, multiple line display
while(BusyXLCD()); //Check if the LCD controller is not busy
 //before writing some commands?
WriteCmdXLCD(0x06); // move cursor right, don?t shift display
WriteCmdXLCD(0x0C); //turn display on without cursor
}
void init_ADC1(void) //Initialize ADC
{
 /**** ADC configured for:
 * FOSC/2 as conversion clock
 * Result is right justified
 * Acquisition time of 2 AD
 * Channel 1 for sampling
 * ADC interrupt off
 * ADC reference voltage from VDD & VSS
*/
 OpenADC(ADC_FOSC_2 & ADC_RIGHT_JUST & ADC_2_TAD,
 ADC_CH0 & ADC_INT_OFF & ADC_REF_VDD_VSS,
 ADC_1ANA);
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

