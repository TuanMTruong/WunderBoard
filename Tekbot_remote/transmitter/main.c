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


// byte format [M1|M2|F|B|D0|D1|D2|D3]
// M1, M2 for which motor
// F = forward
// B = Backward
// D[0,4] = speed data
uint8_t motor1_state = 0;
uint8_t motor2_state = 0;

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

	//check if tilt data is within Dead zone
	if ( (y_data < (Y_NOR + DEAD_ZONE)) && (x_data < (X_NOR + DEAD_ZONE))){
		max_speed = 0;	//stops all motor
		motor1_state = MOTOR1 | max_speed;	//set motor 1 stop
		motor2_state = MOTOR2 | max_speed;	//set motor 2 stop
		return 0;
	}

	//Check if tilt is forward or backward
	if (y_data >= (Y_NOR+DEAD_ZONE) ){
		//set all motor to spin forward
		max_speed = (y_data - Y_NOR) | FORWARD;
	}
	else {
		//set all motor to spin backward
		max_speed = ((Y_NOR - y_data) | BACKWARD);
	}

	//check if tilt is left or right
	if (x_data >= (X_NOR + DEAD_ZONE)){
		motor2_state = max_speed - (x_data - X_NOR);
		motor1_state = max_speed;
	}
	else {
		motor1_state = max_speed - (X_NOR - x_data);
		motor2_state = max_speed;
	}
	return 1;

}


/******************************************************************/
// Send motor data 
/******************************************************************/
uint8_t usart_sendmotor(void){
	usart_sendbyte(motor1_state);
	_delay_ms(1);
	usart_sendbyte(motor2_state);
	_delay_ms(1);
	return(1);
}
/******************************************************************/
//let the main party begin!!!!!!
/******************************************************************/
int main(void){
	ddr_setup();		//set up pins
	usart_setup(BAUD);	//set up USART with defined Baudrate

	uint8_t adc_data_xaxis = 0;	//hold x tilt data
	uint8_t adc_data_yaxis = 0;	//hold y tilt data
	
	uint8_t motor1_prev = 0;	//hold previous m1 state
	uint8_t motor2_prev = 0;	//hold previous m2 state

	while(1){
		_delay_ms(1);				//just wait
		adc_data_xaxis = adc_read(X_AXIS);	//read x tilt
		adc_data_yaxis = adc_read(Y_AXIS);	//read y tilt
		calc_speed(adc_data_xaxis, adc_data_yaxis);	//calc motor
		if ( (motor1_state != motor1_prev) || (motor2_state != motor2_prev) ){
			usart_sendmotor();		//if new data send motor data
		}
		motor1_prev = motor1_state;		//save previous m1 state
		motor2_prev = motor2_state;		//save previous m2 state
	}

}
