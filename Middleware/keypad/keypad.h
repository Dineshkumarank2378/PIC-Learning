#include"gpio.h"
#include"sevseg.h"

//1st 4 bits of the port are output remaining are input

#ifndef keypad_H
#define kepad_H

uint8_t keypad(volatile unsigned char *port);//returns the pressed value

uint16_t keypadcal(unsigned volatile char *port);// returns the calculated value

#endif