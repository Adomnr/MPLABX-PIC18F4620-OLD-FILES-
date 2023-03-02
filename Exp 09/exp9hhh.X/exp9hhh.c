/* 
 * File:   exp9hhh.c
 * Author: Muhammad Bilal Khan
 *
 * Created on July 12, 2021, 12:06 AM
 */
#include <xc.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "exp9hhh.h" 
/* 
* 
*/ 
//#define set_port_kbd PORTB // Change if port is different 
#define row1port LATCbits.LATC0 
#define row2port LATCbits.LATC1 
#define row3port LATCbits.LATC2 
#define row4port LATCbits.LATC3 
#define col1port PORTCbits.RC7
#define col2port PORTCbits.RC5 
#define col3port PORTCbits.RC6 
//#define col4port PORTBbits.RB7 //if a 4x4 keypad is used 
unsigned char const Seven_Segment_MAP[10] = 
{0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; 
char const keyPadMatrix[] = 
{ 
'1','2','3', 
'4','5','6', 
'7','8','9', 
'*','0','#', 
0xFF 
}; 
char key,old_key; 
//void init_IO(void); 
void kbd_init(); 
int kbd_getc(); 
void display_7seg(char c); 
void main(void) { 
char keypress,keyboard='0'; 
kbd_init(); 
while(1){ 
keypress = kbd_getc(); 
if(keypress!=0xFF){ 
keyboard=keypress; 
} 
display_7seg(keyboard); 
} 
}
void kbd_init(){ 
PORTC = 0x00;
LATC = 0x00; 
TRISC = 0xF0; //Use PORTC for Keypad 
INTCON2bits.NOT_RBPU = 1; // Pull-ups disabled 
TRISA = 0x00; //Use PORTA to display 
}
int kbd_getc(){ 
// This routine returns the first key found to be pressed during the scan. 
char key = 0, row; 
for( row = 0b00000001; row < 0b00010000; row <<= 1 ) 
{ 
{ // turn on row output 
row1port = (row & 0x0001)>>0; 
row2port = (row & 0x0002)>>1; 
row3port = (row & 0x0004)>>2; 
row4port = (row & 0x0008)>>3; 
__delay_ms(1); 
} 
// read colums - break when key press detected 
if( col1port )break; key++; 
if( col2port )break; key++;
if( col3port )break; key++; 
//if( col4port )break; key++; 
} 
row1port = 0; 
row2port = 0; 
row3port = 0; 
row4port = 0; 
if (key!=old_key){ 
old_key=key; 
return keyPadMatrix[ key ]; 
} 
else 
return keyPadMatrix[ 0x0C ]; 
}
void display_7seg(char c) {
LATA = 0x00; 
if((c>'9')||(c<'0')) 
if (c=='*') LATA=0x77; //Display 'A' 
else if (c=='#') LATA=0x76; //Display 'H' 
else LATA = (0x00); 
else 
LATA = (Seven_Segment_MAP[c-'0']); 
}

