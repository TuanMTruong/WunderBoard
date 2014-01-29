/******************************************************************/
// Author: Tuan
// Date: 12/28/13
// Brief:
// The reciever will prcoess the incoming data and drive each motor.
// Every time the reciever gets a usart interrupt it will check
// which motor the data is for, the direction of said motor, and 
// the speed. 
//
// update: because the wunderboard is 3.3V and the motro driver is
// 5V, the wunderboard is having trouble using a pwm to flip the 
// direction pin at a fast speed. This is could be solved by adding
// a transistor that the wunderboard would control for the pwm.
// But with limited time and resources this code has ditched the
// pwm meathod and gone with simple forward, backward, right and 
// left option with no speed control.
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
#include<util/delay.h>
#include"usart.h"

//macros
#define RED_EN 		6
#define GREEN_EN	7
#define USART_RX	2
#define USART_TX	3
#define MOTOR1		0x80
#define MOTOR2		0x40
#define FORWARD		0x20
#define BACKWARD	0x10
#define RIGHT		0x22
#define LEFT		0x33
#define STOP		0x3A
#define BAUD		9600

#define MOTOR_PORT	PORTD
#define M1_EN_PIN	4
#define M2_EN_PIN	6
#define M1_DIR_PIN	5
#define M2_DIR_PIN	7
#define M1_ENABLE()	MOTOR_PORT &= ~(1<<M1_EN_PIN)
#define M1_DISABLE()	MOTOR_PORT |= (1<<M1_EN_PIN)
#define M2_ENABLE()	MOTOR_PORT &= ~(1<<M2_EN_PIN)
#define M2_DISABLE()	MOTOR_PORT |= (1<<M2_EN_PIN)	


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
	DDRB = (1<<RED_EN)|(1<<GREEN_EN)|(1<<5);	//enable the Green and Red LEDs
	DDRC = 0xFF;				//Set LEDs rows to output
	DDRD = (1<<USART_TX);			//USART TX % RX set
	DDRE = 0x07;				//set LEDs column to output
	DDRF = 0x00;				//all ADC to input
}



/******************************************************************/
// using pwm on 8 bit timer 1 and 2 to control motors
// set up timers for pwm mode
/******************************************************************/
void pwm_setup(void){
	
	TCCR1A = (0<<WGM10);
	TCCR1B = (1<<WGM12) | (4<<CS10);
	TCNT1 = 0;
	OCR1A = 1000;
	OCR1B = 1000;
	TIMSK1 = (1<<OCIE1A) | (1<<OCIE1B);
	return;
}


/******************************************************************/
// change motor speed
// takes a single motor data and change the direction and speed 
/******************************************************************/
uint8_t motor_speed(uint8_t motor_data){
	uint8_t motor = motor_data & 0xC0;
	uint8_t dir = motor_data & 0x30;
	uint8_t speed = motor_data & 0x0F;

	if ((motor != MOTOR1) && (motor != MOTOR2)){
		return 0;
	}

	if(motor == MOTOR1){
		if (speed == 0){
			M1_DISABLE();
		}
		M1_ENABLE();

		//TODO check direction and speed

	}
	else {
		if (speed == 0){
			M2_DISABLE();
		}
		M2_DISABLE();
		//TODO check direction and speed
	}

	return (1);
}

/******************************************************************/
// Interrupt to catch incoming usart data
// if data matches motor headers then store data
/******************************************************************/
ISR(USART1_RX_vect){
	uint8_t temp = 0;
	temp = UDR1;

	if ( (temp | MOTOR1) == MOTOR1){
		motor1_state = temp;
	}
	else if ( (temp|MOTOR2) == MOTOR2){
		motor2_state = temp;
	}

}


/******************************************************************/
// Interrupt for PWM timer to flip a pin
// used OCR1A and OCR1B to create a pwm for the direction pins
/******************************************************************/

ISR(TIMER1_COMPA_vect){
	if (OCR1A == 1000){
		MOTOR_PORT |= (1<<M1_DIR_PIN);
		OCR1A = 2000;
	} else {
		MOTOR_PORT &= ~(1<<M1_DIR_PIN);
		OCR1A = 1000;
	}
}

ISR(TIMER1_COMPB_vect){
	if (OCR1B == 1000){
		MOTOR_PORT |= (1<<M2_DIR_PIN);
		OCR1B = 2000;
	} else {
		MOTOR_PORT &= ~(1<<M2_DIR_PIN);
		OCR1B = 1000;
	}
}


/******************************************************************/
// clear all LEDs
/******************************************************************/
void clearArray(void){
	PORTC = 0x00;
	PORTB |= (1<<RED_EN)|(1<<GREEN_EN);
	PORTB &= ~((1<<RED_EN)|(1<<GREEN_EN));
}


void mtr_cmd(uint8_t cmd){
	if (cmd == STOP){
		M1_DISABLE();
		M2_DISABLE();
	}
	else if (cmd == FORWARD){
		M1_ENABLE();
		M2_ENABLE();
		MOTOR_PORT &= ~((1<<M1_EN_PIN)|(1<<M2_DIR_PIN));
	}
	else if (cmd == BACKWARD){
		M1_ENABLE();
		M2_ENABLE();
		MOTOR_PORT |= ((1<<M1_EN_PIN)|(1<<M2_DIR_PIN));
	}
	else if (cmd == RIGHT){
		M1_ENABLE();
		M2_ENABLE();
		MOTOR_PORT |= (1<<M2_DIR_PIN);
		MOTOR_PORT &= ~(1<<M1_DIR_PIN);
	}
	else if (cmd == LEFT){
		M1_ENABLE();
		M2_ENABLE();
		MOTOR_PORT |= (1<<M1_DIR_PIN);
		MOTOR_PORT &= ~(1<<M2_DIR_PIN);
	}
	

}
/******************************************************************/
//let the main party begin!!!!!!
/******************************************************************/
int main(void){
	ddr_setup();
	usart_setup(BAUD);
	//pwm_setup();
	clearArray();
	PORTB = (1<<RED_EN);
	PORTC = 0xff;
	
	uint8_t states = FORWARD;
	PORTD = 0xff;
	while(1);
	/*
	//sei();
	while(1){
		switch(states){
		//states = usart_readbyte();
		states = FORWARD;
			case FORWARD:
				PORTE = 2;
				mtr_cmd(FORWARD);
				break;
			case BACKWARD:
				mtr_cmd(BACKWARD);
				break;
			case RIGHT:
				mtr_cmd(RIGHT);
				break;
			case LEFT:
				mtr_cmd(LEFT);
				break;
			default:
				mtr_cmd(STOP);
				break;

		}

	}
	*/
}
