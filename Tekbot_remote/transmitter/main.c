/******************************************************************/
// Author: Tuan
// Data: 12/20/13
// Brief:
// The transmitter will read in ADC value from accelerometer and 
// base on the orientation it will drive the Tekbots a certain 
// direction. 
/******************************************************************/
// Hardware spec:
// Buttons	A0-A3
// Slide switch	A4-A7
// SD card	B0-B3
// Audio In	B5
// RED Enable	B6
// GREEN Enable	B7
// LED rows	C0-C7
// LED column	E0-E2
// usart RX	D2
// usart TX	D3
// Accel_X	F5
// Accel_Y	F6
// Accel_Z	F7 (if installed)

/******************************************************************/

//includes
#include<avr/io.h>
#include<avr/interrupt.h>
#include"usart.h"

//macros
#define RED_EN 		6
#define GREEN_EN	7
#define USART_RX	2
#define USART_TX	3
#define X_AXIS		5
#define Y_AXIS		6
#define BAUD		9600

/******************************************************************/
// Set up all the inputs and out for the data direction 
// 1 = output , 0 = input
/******************************************************************/
void ddr_setup(void){
	DDRA = 0x00;				//set all buttons and switches to input
	DDRB = (1<<RED_EN)|(1<<GREEN_EN);	//enable the Green and Red LEDs
	DDRC = 0xFF;				//Set LEDs rows to output
	DDRD = (1<<USART_TX);			//USART TX % RX set
	DDRE = 0x07;				//set LEDs column to output
	DDRF = 0x00;				//all ADC to input
}


/******************************************************************/
// Reads the ADC channel given and returns a value based on ADC
// voltage
/******************************************************************/
uint8_t char read_adc(uint8_t channel){
	uint8_t char test;
	ADMUX = 0x60 | channel; 		// Set the channel to the one we want
	ADCSRA = 0b11000110; 			// Start a new sample.
	while ((ADCSRA & 0b00010000) == 0 ); 	// Wait for a Valid Sample
	ADCSRA |= 0b00010000; 			// Tell ADC you have the sample you want.
	ADCSRA |= 0b01000000; 			// Start a new sample.
	while ((ADCSRA & 0b00010000) == 0 ); 	// Wait for a Valid Sample
	ADCSRA |= 0b00010000; 			// Tell ADC you have the sample you want.
	
	test = ADCH; 
	ADCSRA = 0x00; 				// Disable the ADC

	return (test);
}

/******************************************************************/
//let the main party begin!!!!!!
/******************************************************************/
int main(void){
	ddr_setup();		//set up pins
	usart_setup(BAUD);	//set up USART with defined Baudrate
	
	while(1){

	}

}
