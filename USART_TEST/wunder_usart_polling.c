/********************************************************************/
/* Author: Tuan Truong                                              */
/* This code reads data from USART by polling then store the data   */
/* in a buffer that is to be went out when receiving is done.       */
/* Refer to wunderproject.c and wunderproject.h for sub functions   */
/* and animatio/text variables are in animation.c and character.c   */
/********************************************************************/

#define F_CPU 1000000UL

#include<avr/io.h>
#include<wunderproject.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdio.h>
#include<stdlib.h>


//Global variables for ringbuffer
//The ring buffer is an array that the USART will use to store data until it is serviced
volatile char ringbuffer[BUFFER_SIZE];
volatile int ringcounter;
volatile int rev_complete;


//Clear the ring buffer 
void ClearRingBuffer(){
	int i = 0;
	for (i = 0; i < BUFFER_SIZE; i++){
		ringbuffer[i] = 0;
	}
	return;
}



int main(){
	Initialize();		//set up DDR
	SetupSPI();		//set up SPI for LED matrix
	SetupUSART();		//Setup USART for 9600. 8B 1SB no parity
	while(1){
        if ((UCSR1A & (1<<RXC1))) {
            //Flip lightings to show interrupt fired
            PORTC ^=0xff;
            
            //if at the end of the buffer restart at the front
            if (ringcounter == BUFFER_SIZE){
                ringcounter =0;
            }
            
            //Read byte into ringbuffer
            ringbuffer[ringcounter] = UDR1;
            //if byte is newline then set rev_complete flag
            if(ringbuffer[ringcounter] == '\n'){
                rev_complete = TRUE;
            }
            //next buffer slot
            ringcounter++;

        }
        
		//When receiving is completed print out string
		if(rev_complete == TRUE){
			rev_complete = FALSE;
			//reset reing buffer position
			ringcounter = 0;
			//send ring buffer out via USART
			SendStringUSART(ringbuffer);
			//clear ring buffer for new data
			ClearRingBuffer();
		}
	}
}
