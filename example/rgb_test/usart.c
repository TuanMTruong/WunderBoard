/*
 * usart.c
 *
 * Created: 12/2/2013 2:04:21 PM
 *  Author: Tuan
 */ 
//includes
#include<avr/io.h>
#include "usart.h"


//global variables
volatile uint8_t dataring[buffersize];
volatile uint8_t ringcounter= 0;

/****************************************************************/
// USART 8 bit, 1SB, No Parity
// buad = 57600
/****************************************************************/
void Setup_USART(){
	//set up DDR for USART, 1 = output, 0 = input
	DDRD |= (1<<TX_PIN);
	DDRD &= ~(1<<RX_PIN);
	//By default USART is asynchronous, parity is disable, and 1 stop bit
	//UCSR1A = (1<<U2X1);
	UCSR1B = (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1);
	//Setting USART data frame to 8bit
	UCSR1C = (3<<UCSZ10);

	//set baud rate to 57.6K
	UBRR1 = 16;
	return;
}

/****************************************************************/
// send one byte and no more
/****************************************************************/
void send_byte_usart(uint8_t data){
    while ( !( UCSR1A & (1<<UDRE1)) ){} //almos ready
    UDR1 = data;                        //ready
}

/****************************************************************/
// send lots of bytes
/****************************************************************/
void send_string_usart(uint8_t *str, uint8_t len){
    uint8_t i = 0;              //counter
    for(i=0; i<len; i++){
        send_byte_usart(*str);  //send one byte at a time in array
        str++;                  //next index
    }
}

/****************************************************************/
//functions that access data buffer
/****************************************************************/

//push data to push
void PushData(uint8_t data){
	if(ringcounter >= buffersize){ //check if at end of buffer
		ringcounter = 0;
	}
	dataring[ringcounter] = data;   //add new data
	ringcounter++;                  //next spot
}

//pop the last data
uint8_t PopData(){
	return dataring[ringcounter];   //return data
}

//read data of an index
uint8_t ReadData(uint8_t location){
	return dataring[location];      //return located data
}

//currenlt location of index in buffer
uint8_t get_buff_location(){
	return ringcounter;             //where am I?
}

//set new location of buffer
void set_buff_location(uint8_t location){
	ringcounter = location;         //I an here
	return;
}

