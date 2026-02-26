#include "D:\Learning Doc\PIC Learning\Header\GPIO\gpio.h"

#ifndef lcd_H
#define lcd_H


static  volatile unsigned char *lcd_dport  ;
static  volatile unsigned char * lcd_cport;
static uint8_t  lcd_en;
static uint8_t lcd_rs;



 void lcd_init(volatile unsigned char*a,volatile unsigned char *b, uint8_t e,uint8_t rs );
void lcd_cmd(uint8_t a);
void lcd_data(char b);
void  lcd_out(char * c);

   
    #endif 