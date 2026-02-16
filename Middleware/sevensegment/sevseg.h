#include"gpio.h"

#ifndef sevseg_H
#define sevseg_H

char sevseg(int a);//returns the binary value for 7 segment

void counter_sevseg(volatile unsigned char *a);//single digit counter

void counter_2sevseg(volatile unsigned char *port,volatile unsigned char *eport, uint8_t a, uint8_t b);//double digit counter on single port

void display_2sevseg(volatile unsigned char *port,volatile unsigned char *eport, uint8_t a, uint8_t b,uint8_t c);//display the double digit value on single port

#endif