#include <avr/io.h>
#include "wunderproject.h"

void SetupMarqueeLEDarray(){
	LEDarray[0][0] = 0b00000000;
	LEDarray[0][1] = 0b11111111;
	LEDarray[0][2] = 0b00011000;
	LEDarray[0][3] = 0b00011000;
	LEDarray[0][4] = 0b00011000;
	LEDarray[0][5] = 0b11111111;
	LEDarray[0][6] = 0b00000000;
	LEDarray[0][7] = 0b00000000;
	LEDarray[0][8] = 0b00000000;
	LEDarray[0][9] = 0b00000000;
	LEDarray[0][10]= 0b00000000;
	LEDarray[0][11]= 0b00000000;
	LEDarray[0][12]= 0b00000000;
	LEDarray[0][13]= 0b00000000;
	LEDarray[0][14]= 0b00000000;
	LEDarray[0][15]= 0b00000000;
	LEDarray[0][16]= 0b00000000;
	LEDarray[0][17]= 0b00000000;
	LEDarray[0][18]= 0b00000000;
	LEDarray[0][19]= 0b11111111;
	LEDarray[0][20]= 0b11111111;
	LEDarray[0][21]= 0b11000000;
	LEDarray[0][22]= 0b11000000;
	LEDarray[0][23]= 0b11000000;
	LEDarray[0][24]= 0b00000000;
	LEDarray[0][25]= 0b11111111;
	LEDarray[0][26]= 0b10000001;
	LEDarray[0][27]= 0b10000001;
	LEDarray[0][28]= 0b10000001;
	LEDarray[0][29]= 0b11111111;
	LEDarray[0][30]= 0b00000000;

	LEDarray[1][0] = 0b00000000;
	LEDarray[1][1] = 0b00000000;
	LEDarray[1][2] = 0b00000000;
	LEDarray[1][3] = 0b00000000;
	LEDarray[1][4] = 0b00000000;
	LEDarray[1][5] = 0b00000000;
	LEDarray[1][6] = 0b00000000;
	LEDarray[1][7] = 0b11111111;
	LEDarray[1][8] = 0b10011001;
	LEDarray[1][9] = 0b10011001;
	LEDarray[1][10]= 0b10011001;
	LEDarray[1][11]= 0b10011001;
	LEDarray[1][12]= 0b00000000;
	LEDarray[1][13]= 0b00000000;
	LEDarray[1][14]= 0b00000000;
	LEDarray[1][15]= 0b00000000;
	LEDarray[1][16]= 0b00000000;
	LEDarray[1][17]= 0b00000000;
	LEDarray[1][18]= 0b00000000;
	LEDarray[1][19]= 0b11111111;
	LEDarray[1][20]= 0b11111111;
	LEDarray[1][21]= 0b11000000;
	LEDarray[1][22]= 0b11000000;
	LEDarray[1][23]= 0b11000000;
	LEDarray[1][24]= 0b00000000;
	LEDarray[1][25]= 0b00000000;
	LEDarray[1][26]= 0b00000000;
	LEDarray[1][27]= 0b00000000;
	LEDarray[1][28]= 0b00000000;
	LEDarray[1][29]= 0b00000000;
	LEDarray[1][30]= 0b00000000;

	LEDarray[2][0] = 0b00000000;
	LEDarray[2][1] = 0b00000000;
	LEDarray[2][2] = 0b00000000;
	LEDarray[2][3] = 0b00000000;
	LEDarray[2][4] = 0b00000000;
	LEDarray[2][5] = 0b00000000;
	LEDarray[2][6] = 0b00000000;
	LEDarray[2][7] = 0b00000000;
	LEDarray[2][8] = 0b00000000;
	LEDarray[2][9] = 0b00000000;
	LEDarray[2][10]= 0b00000000;
	LEDarray[2][11]= 0b00000000;
	LEDarray[2][12]= 0b00000000;
	LEDarray[2][13]= 0b11111111;
	LEDarray[2][14]= 0b11111111;
	LEDarray[2][15]= 0b11000000;
	LEDarray[2][16]= 0b11000000;
	LEDarray[2][17]= 0b11000000;
	LEDarray[2][18]= 0b00000000;
	LEDarray[2][19]= 0b00000000;
	LEDarray[2][20]= 0b00000000;
	LEDarray[2][21]= 0b00000000;
	LEDarray[2][22]= 0b00000000;
	LEDarray[2][23]= 0b00000000;
	LEDarray[2][24]= 0b00000000;
	LEDarray[2][25]= 0b11111111;
	LEDarray[2][26]= 0b10000001;
	LEDarray[2][27]= 0b10000001;
	LEDarray[2][28]= 0b10000001;
	LEDarray[2][29]= 0b11111111;
	LEDarray[2][30]= 0b00000000;

}



void SetupCharacterArray(){

	CharacterArray[0][0] = 0b11111100;
	CharacterArray[0][1] = 0b00010010;
	CharacterArray[0][2] = 0b00010001;
	CharacterArray[0][3] = 0b00010010;
	CharacterArray[0][4] = 0b11111100;

	CharacterArray[1][0] = 0b11111111;
	CharacterArray[1][1] = 0b10010001;
	CharacterArray[1][2] = 0b10010001;
	CharacterArray[1][3] = 0b10010001;
	CharacterArray[1][4] = 0b01100110;

	CharacterArray[2][0] = 0b01111110;
	CharacterArray[2][1] = 0b10000001;
	CharacterArray[2][2] = 0b10000001;
	CharacterArray[2][3] = 0b10000001;
	CharacterArray[2][4] = 0b01000010;

	CharacterArray[3][0] = 0b11111111;
	CharacterArray[3][1] = 0b10000001;
	CharacterArray[3][2] = 0b10000001;
	CharacterArray[3][3] = 0b01000010;
	CharacterArray[3][4] = 0b00111100;

	CharacterArray[4][0] = 0b11111111;
	CharacterArray[4][1] = 0b11111111;
	CharacterArray[4][2] = 0b10011001;
	CharacterArray[4][3] = 0b10011001;
	CharacterArray[4][4] = 0b10011001;

	CharacterArray[5][0] = 0b11111111;
	CharacterArray[5][1] = 0b11111111;
	CharacterArray[5][2] = 0b00001001;
	CharacterArray[5][3] = 0b00001001;
	CharacterArray[5][4] = 0b00001001;

	CharacterArray[6][0] = 0b01111110;
	CharacterArray[6][1] = 0b10000001;
	CharacterArray[6][2] = 0b10010001;
	CharacterArray[6][3] = 0b10010001;
	CharacterArray[6][4] = 0b11110010;

	CharacterArray[7][0] = 0b11111111;
	CharacterArray[7][1] = 0b00011000;
	CharacterArray[7][2] = 0b00011000;
	CharacterArray[7][3] = 0b00011000;
	CharacterArray[7][4] = 0b11111111;

	CharacterArray[8][0] = 0b10000001;
	CharacterArray[8][1] = 0b10000001;
	CharacterArray[8][2] = 0b11111111;
	CharacterArray[8][3] = 0b10000001;
	CharacterArray[8][4] = 0b10000001;

	CharacterArray[9][0] = 0b01000000;
	CharacterArray[9][1] = 0b10000000;
	CharacterArray[9][2] = 0b10000001;
	CharacterArray[9][3] = 0b01111111;
	CharacterArray[9][4] = 0b00000001;

	CharacterArray[10][0] = 0b11111111;
	CharacterArray[10][1] = 0b00011000;
	CharacterArray[10][2] = 0b00100100;
	CharacterArray[10][3] = 0b01000010;
	CharacterArray[10][4] = 0b10000001;

	CharacterArray[11][0] = 0b11111111;
	CharacterArray[11][1] = 0b11111111;
	CharacterArray[11][2] = 0b10000000;
	CharacterArray[11][3] = 0b10000000;
	CharacterArray[11][4] = 0b10000000;

	CharacterArray[12][0] = 0b11111111;
	CharacterArray[12][1] = 0b00000010;
	CharacterArray[12][2] = 0b00011100;
	CharacterArray[12][3] = 0b00000010;
	CharacterArray[12][4] = 0b11111111;

	CharacterArray[13][0] = 0b11111111;
	CharacterArray[13][1] = 0b00000110;
	CharacterArray[13][2] = 0b00011000;
	CharacterArray[13][3] = 0b01100000;
	CharacterArray[13][4] = 0b11111111;

	CharacterArray[14][0] = 0b01111110;
	CharacterArray[14][1] = 0b10000001;
	CharacterArray[14][2] = 0b10000001;
	CharacterArray[14][3] = 0b10000001;
	CharacterArray[14][4] = 0b01111110;

	CharacterArray[15][0] = 0b11111111;
	CharacterArray[15][1] = 0b00010001;
	CharacterArray[15][2] = 0b00010001;
	CharacterArray[15][3] = 0b00010001;
	CharacterArray[15][4] = 0b00001110;

	CharacterArray[16][0] = 0b01111110;
	CharacterArray[16][1] = 0b10000001;
	CharacterArray[16][2] = 0b10000001;
	CharacterArray[16][3] = 0b01000001;
	CharacterArray[16][4] = 0b10111110;

	CharacterArray[17][0] = 0b11111111;
	CharacterArray[17][1] = 0b00010001;
	CharacterArray[17][2] = 0b00110001;
	CharacterArray[17][3] = 0b01010001;
	CharacterArray[17][4] = 0b10001100;

	CharacterArray[18][0] = 0b01001100;
	CharacterArray[18][1] = 0b10010010;
	CharacterArray[18][2] = 0b10010010;
	CharacterArray[18][3] = 0b10010010;
	CharacterArray[18][4] = 0b01100100;

	CharacterArray[19][0] = 0b00000001;
	CharacterArray[19][1] = 0b00000001;
	CharacterArray[19][2] = 0b11111111;
	CharacterArray[19][3] = 0b00000001;
	CharacterArray[19][4] = 0b00000001;

	CharacterArray[20][0] = 0b01111111;
	CharacterArray[20][1] = 0b10000000;
	CharacterArray[20][2] = 0b10000000;
	CharacterArray[20][3] = 0b10000000;
	CharacterArray[20][4] = 0b01111111;

	CharacterArray[21][0] = 0b00111111;
	CharacterArray[21][1] = 0b01000000;
	CharacterArray[21][2] = 0b10000000;
	CharacterArray[21][3] = 0b01000000;
	CharacterArray[21][4] = 0b00111111;

	CharacterArray[22][0] = 0b01111111;
	CharacterArray[22][1] = 0b10000000;
	CharacterArray[22][2] = 0b01110000;
	CharacterArray[22][3] = 0b10000000;
	CharacterArray[22][4] = 0b01111111;

	CharacterArray[23][0] = 0b11000111;
	CharacterArray[23][1] = 0b00101000;
	CharacterArray[23][2] = 0b00010000;
	CharacterArray[23][3] = 0b00101000;
	CharacterArray[23][4] = 0b11000111;

	CharacterArray[24][0] = 0b00001111;
	CharacterArray[24][1] = 0b00010000;
	CharacterArray[24][2] = 0b11100000;
	CharacterArray[24][3] = 0b00010000;
	CharacterArray[24][4] = 0b00001111;

	CharacterArray[24][0] = 0b11000010;
	CharacterArray[24][1] = 0b10100010;
	CharacterArray[24][2] = 0b10010010;
	CharacterArray[24][3] = 0b10001010;
	CharacterArray[24][4] = 0b10000110;


}
