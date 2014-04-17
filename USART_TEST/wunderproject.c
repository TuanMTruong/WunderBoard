
//Includes
#include <avr/io.h>
#include "wunderproject.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


//Global variables
unsigned char LEDarray[3][STRING_SIZE];
unsigned char animation[11][3][8];
unsigned char face_animation[3][8];
unsigned char CharacterArray[26][5];



//Initialize PORT data direction register
void Initialize(){
	//1 = output, 0 = input
	DDRA = 0x00;
	//set spi pins to output, refer to #defines for the pin numbers
	DDRB = (1<<MISO) | (1<<MOSI) | (1<<SCLK) | (1<<LATCH);;
	DDRC = 0xff;
	DDRD = 0x08;
	DDRE = 0x07;
	DDRF = 0x00;
	return;
}

/**********************************************************/
/* SPI functions                                          */
/**********************************************************/
//Enable SPI in master mode
void SetupSPI(){
	SPCR = (1<<SPE) | (1<<DORD) | (1<<MSTR);
	return;
}

//Send a byte via SPI
void SendByteSPI(uint8_t data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF))){}
	return;
}

//Send 3 bytes for RGB and flip latch to show color
void SendRGBSPI(uint8_t RED, uint8_t GREEN, uint8_t BLUE){
	SendByteSPI(RED);
	SendByteSPI(GREEN);
	SendByteSPI(BLUE);
	flipLatch();
	return;
}

//flip LED latch to load spi data to color
void flipLatch(){
	PORTB |= (1<<LATCH);
	_delay_us(10);
	PORTB &= ~(1<<LATCH);
	_delay_us(10);
	return;
}


/**********************************************************/
/* ADC functions                                          */
/**********************************************************/
//read ADC channel
//channel 5 - Y axis
//channel 6 - X axis
//channel 7 - Z axis
unsigned char read_adc(uint8_t channel){
	unsigned char test;

	ADMUX = 0x60 | channel;         // Set the channel to the one we want
	ADCSRA = 0b11000110;            // Start a new sample.
	while ((ADCSRA & 0x10) == 0 ); 	// Wait for a Valid Sample
	ADCSRA |= 0b00010000;           // Tell ADC you have the sample you want.
	ADCSRA |= 0b01000000;           // Start a new sample.
	while ((ADCSRA & 0x10) == 0 ); 	// Wait for a Valid Sample
	ADCSRA |= 0b00010000;           // Tell ADC you have the sample you want.

	test = ADCH;
	ADCSRA = 0x00;                  // Disable the ADC

	return (test);
}


/**********************************************************/
/* USART functions                                        */
/**********************************************************/
//Enable USART BD = 9600, 8bit, no parity, 1SB
void SetupUSART(){
	UCSR1A = (1<<U2X1);                 //Enable double speed
	UCSR1B = (1<<RXEN1) | (1<<TXEN1);   //Enable RX & TX
	UCSR1C = (3<<UCSZ10);               //8 bit, no parity, 1 SB
	UBRR1 = 12;                         //9600
	return;
}

//read USART buffer and return the data
unsigned char ReadByteUSART(){
	while(! (UCSR1A & (1<<RXC1))){}     //wait for data
	return UDR1;                        //return data
}

//takes a pointer of a string and read in USART byte, terminate at new line
void ReadStringUSART(char *str){
	while(*str){
		*str = ReadByteUSART();
		if(*str == '\n'){
			return;
		}
		str++;
	}

	return;
}

//Send byte via USART
void SendByteUSART(char data){
	while(!(UCSR1A & (1<<UDRE1))){}     //wait for register to be ready
	UDR1 = data;                        //load data to tx buffer
}

//Send a string of ascii
void SendStringUSART(char *str){
	while(*str){                //continue till string is empty
		SendByteUSART(*str);    //Send byte
		str++;                  //move to next byte
	}
	return;
}

void SetupUSART_RECV_INTR(){
	UCSR1B |= (1<<RXCIE1);
	return;
}


