/*
 * traffic_light.c
 *
 * Created: 1/31/2018 12:42:04 PM
 *  Author: ADITYA
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define delay 1000
void count()
{
	DDRA=DDRB=0XFF;
	unsigned char seg[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
	
	for (signed char i=2;i>=0;i--)
	for (signed char j=9;j>=0;j--)
	{
		PORTA=seg[i];
		PORTB=seg[j];
		_delay_ms(delay);
		if(i==0 && j==5)
		return;
	}
}

void count5()
{
	DDRA=DDRB=0XFF;
	unsigned char seg[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
	for (signed char i=4;i>0;i--)
	{
		PORTB=seg[i];
		_delay_ms(delay);
	}
}

int main(void)
{
	DDRA=DDRB=DDRC=DDRD=0xff;
	
	
    while(1)
    {	
		PORTC=0b01010110;
		PORTD=0x00;
		count();
		PORTC=0b01010000;
		PORTD=0x03;
		count5();
		PORTC=0b01011001;
		PORTD=0x00;
		count();
		PORTC=0b01000001;
		PORTD=0x06;
		count5();
		PORTC=0b01100101;
		PORTD=0x00;
		count();
		PORTC=0b00000101;
		PORTD=0x0c;
		count5();
		PORTC=0b10010101;
		PORTD=0x00;
		count();
		PORTC=0b00010100;
		PORTD=0x09;
		count5();
    }
}