#include "config.h"
#include "xlcd.h"
#define TMR2PRESCALE 4
long F; //frequency
char Duty_Cycle[] = " 00.0 %"; //set duty cycle
int C;
unsigned int set_duty;
long adc_calc; //to calculate ADC value
int Max_Duty_cycle()
{
  return(_XTAL_FREQ/(F*TMR2PRESCALE)); // Max frequency 
}

void PWM_init(long freq)
{
  PR2 = (_XTAL_FREQ/(freq*4*TMR2PRESCALE)) - 1;
  F = freq;
}

void duty_Cycle(unsigned int duty)
{
    duty = ((float)duty/100) * 1023; //percentage;
  if(duty<1024)
  {
    duty = ((float)duty/1023)*Max_Duty_cycle();
    CCP1CONbits.DC1B0 = duty & 0x02;
    CCP1CONbits.DC1B1 = duty & 0x01;
    CCPR1L = duty>>0x02;
  }
  }
void PWM_start()
{
  CCP1CONbits.CCP1M3 = 1;
  CCP1CONbits.CCP1M2 = 1;
  #if TMR2PRESCALAR == 1
  #elif TMR2PRESCALAR == 4 
  #elif TMR2PRESCALAR == 16   
  #endif
  
  T2CONbits.TMR2ON = 1;
  TRISC2 = 0;
} 

PWM_stop()
{
  CCP1CONbits.CCP1M3 = 0;
  CCP1CONbits.CCP1M2 = 0;
}

void ADC_Init()
{
TRISA = 0xff; //*set as input port*/ 
ANSELA = 0xff; //Set PORT A 0th bit  as a analog input
ADCON1 = 0b11110000; //Right Justify, FRC Clock , All pins as Analog Input and setting Reference Voltages 
ADCON0 = 0b00000001; //Turn ON ADC and Clock Selection
ADRESH = 0; //*Flush ADC output Register*/
ADRESL = 0;
}
unsigned int ADC_Read(unsigned char channel)
{

 ADCON0 |= channel<< 1; //Setting the required Bits
  __delay_ms(2); //Acquisition time to charge hold capacitor
  GO_nDONE = 1; //Initializes A/D Conversion
  while(GO_nDONE); //Wait for A/D Conversion to complete
  return ((ADRESH<< 8)+ADRESL); //Returns Result
}

void main()
{
  TRISC = 0x00; //PORTC as output to monitor data on Oscilloscope
  TRISA = 0xFF; //PORTA as input for Analog Data
  TRISD = 0x00; // PORT D as output for LCD
  Init_LCD(); // start LCD function
  ADC_Init(); //* initialize 10-bit ADC*/  
  PWM_init(5000);
  PWM_start();//start PWM //set CCP1 on
   while(1)
    {
    C = ADC_Read(0); //Reading Analog Channel 0
    adc_calc = (long)C * 255;
    adc_calc = adc_calc / 1023;
    adc_calc = (adc_calc * 100)/255; //convert into percentage     
    Duty_Cycle[0]  = adc_calc/100 + 48;               // Set Duty_Cycle 100th Digit on LCD
    Duty_Cycle[1]  = (adc_calc / 10) % 10  + 48;      // Set Duty_Cycle 10th Digit on LCD
    Duty_Cycle[2]  =  adc_calc % 10  + 48;            // Set Duty_Cycle 0th Digit on LCD
    Lcd_Set_Cursor(0xC0);
    Lcd_Write_String("Duty:");
    Lcd_Write_String(Duty_Cycle); //Display Duty Cycle on LCD
    Lcd_Set_Cursor(0xC0);
    set_duty = C/4; // Set 
    __delay_ms(50);
    duty_Cycle(set_duty);  // Set Duty Cycle 
    }
    return;
}
