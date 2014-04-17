

//Define F_CPU
#define F_CPU 1000000UL

//Lenght of Marguee text
#define STRING_SIZE 31

//Physical SPI pins
#define MISO	3
#define MOSI	2
#define SCLK	1
#define LATCH	7


#define BUFFER_SIZE 100
#define TRUE 1
#define FALSE 0


/*******************************************/
/* Global share variables                  */
/*******************************************/

extern unsigned char LEDarray[3][STRING_SIZE];
extern unsigned char animation[11][3][8];
extern unsigned char face_animation[3][8];
extern unsigned char CharacterArray[26][5];


/*******************************************/
/* Function prototypes                     */
/*******************************************/
void Initialize();
void SetupSPI();
void SendByteSPI(uint8_t data);
void SendRGBSPI(uint8_t RED, uint8_t GREEN, uint8_t BLUE);
void flipLatch();
unsigned char read_adc(uint8_t channel);
void SetupUSART();
unsigned char ReadByteUSART();
void SendByteUSART(char data);
void SendStringUSART(char *str);
void SetupMarqueeLEDarray();
void SetupCharacterArray();
void SetupAnimation();

