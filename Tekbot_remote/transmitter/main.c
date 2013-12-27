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
#include<util/delay.h>

//macros
#define RED_EN 		6
#define GREEN_EN	7
#define USART_RX	2
#define USART_TX	3
#define X_AXIS		6
#define X_MIN		0x67
#define X_NOR		0x83
#define X_MAX		0x9D
#define Y_AXIS		5
#define Y_MIN		0x85
#define Y_NOR		0x6A
#define Y_MAX		0x9F
#define DEAD_ZONE	5
#define BAUD		9600

#define MOTOR1		0x80
#define MOTOR2		0x40
#define FORWARD		0x20
#define BACKWARD	0x10

uint8_t send_buffer[4];
uint8_t motro1_speed = 0;
uint8_t motor2_speed = 0;
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
// X_AXIS: Normal 0x83(131), Min = 0x67(103), MAX = 0x9d(157)
// Y_AXIS: Normal 0x85(133), Min = 0x6A(106), MAX = 0x9F(159)
/******************************************************************/
uint8_t adc_read(uint8_t channel){
	uint8_t test;
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
// This function takes in the x and y axis data and fill the 
// motor 1 and motor 2 data byte with the motor selection and the 
// speed at which that motor should spin at.
// Y data will be the max speed 
// x data will be motor proportion
/******************************************************************/
uint8_t calc_speed(uint8_t x_data, uint8_t y_data){
	uint8_t max_speed = 0;
	if (y_data > (Y_NOR+DEAD_ZONE) ){
		max_speed = y_data - Y_NOR;
	}
	else if (y_data < (Y_NOR - DEAD_ZONE)){
		max_speed = Y_NOR - y_data;
	}
	else {
		max_speed = 0;
	}

	
}
/******************************************************************/
//let the main party begin!!!!!!
/******************************************************************/
int main(void){
	ddr_setup();		//set up pins
	usart_setup(BAUD);	//set up USART with defined Baudrate
	
	uint8_t adc_data_xaxis = 0;
	uint8_t adc_data_yaxis = 0;

	while(1){
		_delay_ms(1);
		adc_data_xaxis = adc_read(X_AXIS);
//		usart_sendbyte(temp);
//		usart_sendarray("HELLO", 5);		
		usart_sendbyte(MOTOR1 | (i));

	}

}
