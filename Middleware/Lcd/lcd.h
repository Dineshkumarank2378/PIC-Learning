#include "D:\Learning Doc\PIC Learning\Header\GPIO\gpio.h"
#include"D:\Learning Doc\PIC Learning\Header\Timer\timer.h"

#ifndef lcd_H
#define lcd_H



void lcd_init();
void lcd_config(volatile unsigned char*a,volatile unsigned char *b, uint8_t e,uint8_t rs );
void lcd_cmd(uint8_t a);
void lcd_data(uint8_t b);
void lcd_out(char * c);
void lcd_enable();

   
    #endif 