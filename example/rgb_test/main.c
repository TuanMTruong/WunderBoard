/**************************************/
/* Author: Tuan Truong
 *
 * Brief: Flash red, green, blue. Testing displa
 */
/**************************************/
/* Hardware pins:
 *
 * A0-A7: Push buttons
 */

//includes
#include<avr/io.h>
#include<util/delay.h>
#include"spi.h"
#include"display.h"

#ifndef F_CPU
#define F_CPU 1000000U
#endif

#define LEDarray PORTC

//prototypes
void init(void);

//main
int main(void){

	init();
	init_display();
	int i = 0;

	LEDarray = 0x00;
	while(1){
		LEDarray++;
		fill_display(0,0, 0xff);
		//fill_display(0, 0xff, 0);
		//fill_display(0, 0, 0xff);

		i++;
	}

	return 0;
}


void init(void){
	DDRA = 0x00;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRE = 0xFF;


}

