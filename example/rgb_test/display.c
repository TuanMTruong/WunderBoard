/**************************************/
/* Author: Tuan Truong
*/
/**************************************/


//includes
#include<avr/io.h>
#include<util/delay.h>
#include"spi.h"
#include"display.h"



void init_display(void){
	//set up spi
	setup_SPI(MSB_FIRST | MASTER_MODE | MODE_0 | SPI_4DIV);

	//clear display
	PORTB = 1;
	int i = 0;
	for(i =0; i<8; i++){
		
	send_SPI_byte(0x00);
	send_SPI_byte(0x00);
	send_SPI_byte(0x00);
	latch_display();
	}



}

void latch_display(void){

	PORTB |= (1<<LATCH_PIN);
	_delay_ms(1);
	PORTB &= ~(1<<LATCH_PIN);
	return;

}

void line_display(uint8_t red, uint8_t green, uint8_t blue, uint8_t line){
	PORTE = line;
	send_SPI_byte(red);
	send_SPI_byte(green);
	send_SPI_byte(blue);
	latch_display();


}

void array_display(char *array[8]){

	return;

}

void fill_display(uint8_t red, uint8_t green, uint8_t blue){
	int i = 0;
	
	for(i=0; i<8;i++){
		line_display(red,green,blue,i);
		_delay_ms(1);
	}
	return;

}
