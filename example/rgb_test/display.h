/*
 * display.h
 *
 * Created: 3/9/2015
 *  Author: Tuan
 */ 


#define LATCH_PIN	7
void init_display(void);
void latch_display(void);
void line_display(uint8_t red, uint8_t green, uint8_t blue, uint8_t line);
void fill_display(uint8_t red, uint8_t green, uint8_t blue);
void array_display(char *array[8]);
