/*******************************************************************/
/* Author: Tuan Truong
 * Data: 11/14/13
 * Test audio module on Wunderboard by using TIMER1 to PWM OCR1A on
 * PORTB PIN5
 */

/*******************************************************************/

//Define CPU clock for delay cycle
#define F_CPU 1000000UL

//includes
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

//Set up PWM for toggling Audio pin
void Set_upPWM(){
	//Enable OCR1A and set PWM mode
	TCCR1A = (1<<COM1A0) | (3<<WGM10);
	TCCR1B = (1<<WGM13) | (2<<CS10);
	//Enable Interrupt for TIMER1
	TIMSK1 = (1<<OCIE1A);    
	//Set PORTB to output
	DDRB = 0xff;
	return;
}

//change the frequency of audio
//changes the output compare that the counter has to count to
void Set_frequency(uint16_t freq){
	OCR1A = freq;
	return;
}

//Interrupt to reset counter
ISR (TIMER1_COMPA_vect){
	//reset counter
	TCNT1 = 0;
	//Indicate interrupt fired correctly
	PORTC^=0xff;
}

//Catch all interrupt 
ISR (BADISR_vect){
	//forever loop displaying alternating LEDs
	PORTC = 0xAA;
	while(1){
		PORTC^=0xff;
		_delay_ms(200);
	}
}


//main code
int main(){
	//Set LEDs to output
	DDRC = 0xff;
	//Turn on all LEDs
	PORTC = 0xff;
	//Set up PWM
	Set_upPWM();
	//reset counter
	TCNT1 = 0;
	//enable global interrupt
	sei();

	//Set starting frequency 
	Set_frequency(600);

	while(1){
		//Wait 500 milliseconds then change frequency.
		_delay_ms(500);
		Set_frequency(550);

		_delay_ms(500);
		Set_frequency(500);

		_delay_ms(500);
		Set_frequency(450);

		_delay_ms(500);
		Set_frequency(400);

		_delay_ms(500);
		Set_frequency(350);

		_delay_ms(500);
		Set_frequency(300);

		_delay_ms(500);
		Set_frequency(250);

		_delay_ms(500);
		Set_frequency(200);

		_delay_ms(500);
		Set_frequency(150);

		_delay_ms(500);
		Set_frequency(100);



	}

}
