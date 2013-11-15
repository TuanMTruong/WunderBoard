//Testing audio out on the Wunderboard

#define F_CPU 1000000UL
//includes
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
//audio out is on PB5 OC1A
void Set_upPWM(){
	TCCR1A = (1<<COM1A0) | (3<<WGM10);
	TCCR1B = (1<<WGM13) | (2<<CS10);
	TIMSK1 = (1<<OCIE1A);    
	DDRB = 0xff;

}

ISR (TIMER1_COMPA_vect){
	
	TCNT1 = 0;
	PORTC^=0xff;

}

ISR (BADISR_vect){
	PORTC = 0xAA;
	while(1){
		PORTC^=0xff;
		_delay_ms(200);
	}
}




int main(){
	//DDRB = 0xff;
	DDRC = 0xff;
	PORTC = 0xff;
	Set_upPWM();
	TCNT1 = 0;
	sei();    
	OCR1A = 600;
	while(1){
	





	_delay_ms(500);
	OCR1A= 550;

	_delay_ms(500);
	OCR1A= 400;

	_delay_ms(500);
	OCR1A= 300;

	_delay_ms(500);
	OCR1A= 200;


	_delay_ms(500);
	OCR1A= 150;

	_delay_ms(500);
	OCR1A= 100;


	_delay_ms(500);
	OCR1A= 50;



	/**TCNT1 = 0;
		  OCR1A = 100;
		  _delay_ms(300);
		  TCNT1 = 0;
		  OCR1A = 200;
		  _delay_ms(300);
		  TCNT1 = 0;
		  OCR1A = 300;
		  _delay_ms(300);
		  TCNT1 = 0;
		  OCR1A = 400;
		  _delay_ms(300);
		  */
		/**PORTB ^= 0xff;
		  _delay_us(3);
		  PORTC = PORTB;
		  }

*/
	}

}
