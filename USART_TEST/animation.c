#include <avr/io.h>
#include "wunderproject.h"


void SetupAnimation(){

    face_animation[0][0] = 0b00111100;
    face_animation[0][1] = 0b01111110;
    face_animation[0][2] = 0b11011011;
    face_animation[0][3] = 0b10111111;
    face_animation[0][4] = 0b10111111;
    face_animation[0][5] = 0b11011011;
    face_animation[0][6] = 0b01111110;
    face_animation[0][7] = 0b00111100;
    
    face_animation[1][0] = 0b00111100;
    face_animation[1][1] = 0b01111110;
    face_animation[1][2] = 0b11011011;
    face_animation[1][3] = 0b10111111;
    face_animation[1][4] = 0b10111111;
    face_animation[1][5] = 0b11011011;
    face_animation[1][6] = 0b01111110;
    face_animation[1][7] = 0b00111100;
    
    face_animation[2][0] = 0b00111100;
    face_animation[2][1] = 0b01111110;
    face_animation[2][2] = 0b11011011;
    face_animation[2][3] = 0b10111111;
    face_animation[2][4] = 0b10111111;
    face_animation[2][5] = 0b11011011;
    face_animation[2][6] = 0b01111110;
    face_animation[2][7] = 0b00111100;
    
    /****************************************************/
    animation[0][0][0] = 0b00000000;
    animation[0][0][1] = 0b00000000;
    animation[0][0][2] = 0b00000000;
    animation[0][0][3] = 0b00000000;
    animation[0][0][4] = 0b00000000;
    animation[0][0][5] = 0b00000000;
    animation[0][0][6] = 0b00000000;
    animation[0][0][7] = 0b00000000;
    
    animation[0][1][0] = 0b00000000;
    animation[0][1][1] = 0b00000000;
    animation[0][1][2] = 0b00000000;
    animation[0][1][3] = 0b00000000;
    animation[0][1][4] = 0b00000000;
    animation[0][1][5] = 0b00000000;
    animation[0][1][6] = 0b00000000;
    animation[0][1][7] = 0b00000000;
    
    animation[0][2][0] = 0b00000000;
    animation[0][2][1] = 0b00000000;
    animation[0][2][2] = 0b00000000;
    animation[0][2][3] = 0b00000000;
    animation[0][2][4] = 0b00000000;
    animation[0][2][5] = 0b00000000;
    animation[0][2][6] = 0b00000000;
    animation[0][2][7] = 0b00000000;
    
    /****************************************************/
    animation[1][0][0] = 0b00000000;
    animation[1][0][1] = 0b00000000;
    animation[1][0][2] = 0b00000000;
    animation[1][0][3] = 0b00000000;
    animation[1][0][4] = 0b00000000;
    animation[1][0][5] = 0b00000000;
    animation[1][0][6] = 0b00000000;
    animation[1][0][7] = 0b00000000;
    
    animation[1][1][0] = 0b10000000;
    animation[1][1][1] = 0b10000000;
    animation[1][1][2] = 0b10000000;
    animation[1][1][3] = 0b10000000;
    animation[1][1][4] = 0b10000000;
    animation[1][1][5] = 0b10000000;
    animation[1][1][6] = 0b10000000;
    animation[1][1][7] = 0b10000000;
    
    animation[1][2][0] = 0b00000000;
    animation[1][2][1] = 0b00000000;
    animation[1][2][2] = 0b00000000;
    animation[1][2][3] = 0b00000000;
    animation[1][2][4] = 0b00000000;
    animation[1][2][5] = 0b00000000;
    animation[1][2][6] = 0b00000000;
    animation[1][2][7] = 0b00000000;
    
    /****************************************************/
    animation[2][0][0] = 0b00000000;
    animation[2][0][1] = 0b00000000;
    animation[2][0][2] = 0b00000000;
    animation[2][0][3] = 0b00000000;
    animation[2][0][4] = 0b00000000;
    animation[2][0][5] = 0b00000000;
    animation[2][0][6] = 0b00000000;
    animation[2][0][7] = 0b00000000;
    
    animation[2][1][0] = 0b10000000;
    animation[2][1][1] = 0b10000000;
    animation[2][1][2] = 0b10000000;
    animation[2][1][3] = 0b10000000;
    animation[2][1][4] = 0b10000000;
    animation[2][1][5] = 0b10000000;
    animation[2][1][6] = 0b10000000;
    animation[2][1][7] = 0b10000000;
    
    animation[2][2][0] = 0b00000000;
    animation[2][2][1] = 0b00000000;
    animation[2][2][2] = 0b01000000;
    animation[2][2][3] = 0b01000000;
    animation[2][2][4] = 0b01000000;
    animation[2][2][5] = 0b01000000;
    animation[2][2][6] = 0b00000000;
    animation[2][2][7] = 0b00000000;
    
    /****************************************************/
    animation[3][0][0] = 0b00000000;
    animation[3][0][1] = 0b00000000;
    animation[3][0][2] = 0b00000000;
    animation[3][0][3] = 0b00000000;
    animation[3][0][4] = 0b00000000;
    animation[3][0][5] = 0b00000000;
    animation[3][0][6] = 0b00000000;
    animation[3][0][7] = 0b00000000;
    
    animation[3][1][0] = 0b10000000;
    animation[3][1][1] = 0b10000000;
    animation[3][1][2] = 0b10000000;
    animation[3][1][3] = 0b10000000;
    animation[3][1][4] = 0b10000000;
    animation[3][1][5] = 0b10000000;
    animation[3][1][6] = 0b10000000;
    animation[3][1][7] = 0b10000000;
    
    animation[3][2][0] = 0b00000000;
    animation[3][2][1] = 0b00000000;
    animation[3][2][2] = 0b01100000;
    animation[3][2][3] = 0b01100000;
    animation[3][2][4] = 0b01100000;
    animation[3][2][5] = 0b01100000;
    animation[3][2][6] = 0b00000000;
    animation[3][2][7] = 0b00000000;
    
    /****************************************************/
    animation[4][0][0] = 0b00000000;
    animation[4][0][1] = 0b00000000;
    animation[4][0][2] = 0b00000000;
    animation[4][0][3] = 0b00000000;
    animation[4][0][4] = 0b00000000;
    animation[4][0][5] = 0b00000000;
    animation[4][0][6] = 0b00000000;
    animation[4][0][7] = 0b00000000;
    
    animation[4][1][0] = 0b10000000;
    animation[4][1][1] = 0b10000000;
    animation[4][1][2] = 0b10000000;
    animation[4][1][3] = 0b10000000;
    animation[4][1][4] = 0b10000000;
    animation[4][1][5] = 0b10000000;
    animation[4][1][6] = 0b10000000;
    animation[4][1][7] = 0b10000000;
    
    animation[4][2][0] = 0b00000000;
    animation[4][2][1] = 0b00000000;
    animation[4][2][2] = 0b01110000;
    animation[4][2][3] = 0b01110000;
    animation[4][2][4] = 0b01110000;
    animation[4][2][5] = 0b01110000;
    animation[4][2][6] = 0b00000000;
    animation[4][2][7] = 0b00000000;
    
    /****************************************************/
    animation[5][0][0] = 0b00000000;
    animation[5][0][1] = 0b00000000;
    animation[5][0][2] = 0b00000000;
    animation[5][0][3] = 0b00000000;
    animation[5][0][4] = 0b00000000;
    animation[5][0][5] = 0b00000000;
    animation[5][0][6] = 0b00000000;
    animation[5][0][7] = 0b00000000;
    
    animation[5][1][0] = 0b10000000;
    animation[5][1][1] = 0b10000000;
    animation[5][1][2] = 0b10000000;
    animation[5][1][3] = 0b10000000;
    animation[5][1][4] = 0b10000000;
    animation[5][1][5] = 0b10000000;
    animation[5][1][6] = 0b10000000;
    animation[5][1][7] = 0b10000000;
    
    animation[5][2][0] = 0b00000000;
    animation[5][2][1] = 0b00000000;
    animation[5][2][2] = 0b01110000;
    animation[5][2][3] = 0b01111100;
    animation[5][2][4] = 0b01111100;
    animation[5][2][5] = 0b01110000;
    animation[5][2][6] = 0b00000000;
    animation[5][2][7] = 0b00000000;
    
    /****************************************************/
    animation[6][0][0] = 0b00000000;
    animation[6][0][1] = 0b00001000;
    animation[6][0][2] = 0b00000100;
    animation[6][0][3] = 0b00000010;
    animation[6][0][4] = 0b00000010;
    animation[6][0][5] = 0b00000100;
    animation[6][0][6] = 0b00001000;
    animation[6][0][7] = 0b00000000;
    
    animation[6][1][0] = 0b10000000;
    animation[6][1][1] = 0b10000000;
    animation[6][1][2] = 0b10000000;
    animation[6][1][3] = 0b10000000;
    animation[6][1][4] = 0b10000000;
    animation[6][1][5] = 0b10000000;
    animation[6][1][6] = 0b10000000;
    animation[6][1][7] = 0b10000000;
    
    animation[6][2][0] = 0b00000000;
    animation[6][2][1] = 0b00001000;
    animation[6][2][2] = 0b01111100;
    animation[6][2][3] = 0b01111110;
    animation[6][2][4] = 0b01111110;
    animation[6][2][5] = 0b01111100;
    animation[6][2][6] = 0b00001000;
    animation[6][2][7] = 0b00000000;
    
    /****************************************************/
    animation[7][0][0] = 0b00000000;
    animation[7][0][1] = 0b00001000;
    animation[7][0][2] = 0b00000111;
    animation[7][0][3] = 0b00010010;
    animation[7][0][4] = 0b01100010;
    animation[7][0][5] = 0b00000100;
    animation[7][0][6] = 0b00001000;
    animation[7][0][7] = 0b00000000;
    
    animation[7][1][0] = 0b10000000;
    animation[7][1][1] = 0b10000000;
    animation[7][1][2] = 0b10000000;
    animation[7][1][3] = 0b10000000;
    animation[7][1][4] = 0b10000000;
    animation[7][1][5] = 0b10000000;
    animation[7][1][6] = 0b10000000;
    animation[7][1][7] = 0b10000000;
    
    animation[7][2][0] = 0b00000000;
    animation[7][2][1] = 0b00001000;
    animation[7][2][2] = 0b01111100;
    animation[7][2][3] = 0b01101110;
    animation[7][2][4] = 0b00011110;
    animation[7][2][5] = 0b01111100;
    animation[7][2][6] = 0b00001000;
    animation[7][2][7] = 0b00000000;
    
    /****************************************************/
    animation[8][0][0] = 0b00000000;
    animation[8][0][1] = 0b00000000;
    animation[8][0][2] = 0b00000000;
    animation[8][0][3] = 0b00000000;
    animation[8][0][4] = 0b00000000;
    animation[8][0][5] = 0b00000000;
    animation[8][0][6] = 0b00000000;
    animation[8][0][7] = 0b00000000;
    
    animation[8][1][0] = 0b10000000;
    animation[8][1][1] = 0b10000000;
    animation[8][1][2] = 0b10000000;
    animation[8][1][3] = 0b10000000;
    animation[8][1][4] = 0b10000000;
    animation[8][1][5] = 0b10000000;
    animation[8][1][6] = 0b10000000;
    animation[8][1][7] = 0b10000000;
    
    animation[8][2][0] = 0b00000000;
    animation[8][2][1] = 0b00000000;
    animation[8][2][2] = 0b01010110;
    animation[8][2][3] = 0b00111110;
    animation[8][2][4] = 0b01010110;
    animation[8][2][5] = 0b00000000;
    animation[8][2][6] = 0b00000000;
    animation[8][2][7] = 0b00000000;
    
    /****************************************************/
    animation[9][0][0] = 0b00000000;
    animation[9][0][1] = 0b00001110;
    animation[9][0][2] = 0b00000000;
    animation[9][0][3] = 0b00000000;
    animation[9][0][4] = 0b00000000;
    animation[9][0][5] = 0b00000000;
    animation[9][0][6] = 0b00001110;
    animation[9][0][7] = 0b00000000;
    
    animation[9][1][0] = 0b00000000;
    animation[9][1][1] = 0b00000000;
    animation[9][1][2] = 0b00000000;
    animation[9][1][3] = 0b00000000;
    animation[9][1][4] = 0b00000000;
    animation[9][1][5] = 0b00000000;
    animation[9][1][6] = 0b00000000;
    animation[9][1][7] = 0b00000000;
    
    animation[9][2][0] = 0b00000000;
    animation[9][2][1] = 0b00000000;
    animation[9][2][2] = 0b00000000;
    animation[9][2][3] = 0b00000000;
    animation[9][2][4] = 0b00000000;
    animation[9][2][5] = 0b00000000;
    animation[9][2][6] = 0b00000000;
    animation[9][2][7] = 0b00000000;
    
    /****************************************************/
    animation[10][0][0] = 0b00000000;
    animation[10][0][1] = 0b00001110;
    animation[10][0][2] = 0b00000000;
    animation[10][0][3] = 0b00000000;
    animation[10][0][4] = 0b00000000;
    animation[10][0][5] = 0b00000000;
    animation[10][0][6] = 0b00001110;
    animation[10][0][7] = 0b00000000;
    
    animation[10][1][0] = 0b00100000;
    animation[10][1][1] = 0b01000000;
    animation[10][1][2] = 0b10000000;
    animation[10][1][3] = 0b10000000;
    animation[10][1][4] = 0b10000000;
    animation[10][1][5] = 0b10000000;
    animation[10][1][6] = 0b01000000;
    animation[10][1][7] = 0b00100000;
    
    animation[10][2][0] = 0b00000000;
    animation[10][2][1] = 0b00000000;
    animation[10][2][2] = 0b00000000;
    animation[10][2][3] = 0b00000000;
    animation[10][2][4] = 0b00000000;
    animation[10][2][5] = 0b00000000;
    animation[10][2][6] = 0b00000000;
    animation[10][2][7] = 0b00000000;
    
    
    return;


}
