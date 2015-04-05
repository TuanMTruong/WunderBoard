/*
 * spi.h
 *
 * Created: 12/2/2013 2:06:54 PM
 *  Author: Tuan
 */ 


#ifndef SPI_H_
#define SPI_H_


#define LEDPORT PORTD
#define LED	6
#define SS_PIN	0
#define SCLK_PIN 1
#define MOSI_PIN 2
#define MISO_PIN 3

#define LSB_FIRST	(1<<DORD)
#define MSB_FIRST	(0<<DORD)
#define MASTER_MODE	(1<<MSTR)
#define SLAVE_MODE	(0<<MSTR)
#define INTR_EN		(1<<SPIE)
#define SPI_2X		(1<<SPI2X)

#define MODE_0		(0<<CPOL)|(1<<CPHA)
#define MODE_1		(0<<CPOL)|(0<<CPHA)
#define MODE_2		(1<<CPOL)|(1<<CPHA)
#define MODE_3		(1<<CPOL)|(0<<CPHA)

#define SPI_4DIV	(0<<SPI2X)|(0<<SPR1)|(0<<SPR0)
#define SPI_16DIV	(0<<SPI2X)|(0<<SPR1)|(1<<SPR0)
#define SPI_64DIV	(0<<SPI2X)|(1<<SPR1)|(0<<SPR0)
#define SPI_128DIV	(0<<SPI2X)|(1<<SPR1)|(1<<SPR0)
#define SPI_2DIV	(1<<SPI2X)|(0<<SPR1)|(0<<SPR0)
#define SPI_8DIV	(1<<SPI2X)|(0<<SPR1)|(1<<SPR0)
#define SPI_32DIV	(1<<SPI2X)|(1<<SPR1)|(0<<SPR0)

uint8_t setup_SPI(uint8_t settings);
uint8_t send_SPI_byte(uint8_t data);


#endif /* SPI_H_ */
