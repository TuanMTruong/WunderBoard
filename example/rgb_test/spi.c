/*
 * spi.c
 *
 * Created: 12/2/2013 2:05:47 PM
 *  Author: Tuan
 */ 
//includes
#include<avr/io.h>
#include "spi.h"

/****************************************************************/
//enable SPI
//give spi settings
//returns set spi settings
/****************************************************************/
uint8_t setup_SPI(uint8_t settings){
	//set up DDR for SPI, 1 = output, 0 = input
	DDRB |= (1<< SS_PIN) | (1<< SCLK_PIN) | (1<< MOSI_PIN);
	DDRB &= ~(1<<MISO_PIN);
	//Set up SPI control register
	SPCR = settings | (1<<SPE);
	//SPSR |= 1<<SPI2X;

	return (uint8_t)SPCR;
}

/****************************************************************/
//Send byte via SPI
//return data in SPDR (data that the spi read)
/****************************************************************/
uint8_t send_SPI_byte(uint8_t data){
	SPDR = data;    //Send data
	while(!(SPSR & (1<<SPIF))); //wait for sending completion
	return SPDR;
}

