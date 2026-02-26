#include "D:\Learning Doc\PIC Learning\Header\GPIO\gpio.h"

#ifndef timer_H
#define timer_H

#define TMR0 ((volatile unsigned char *) 0x01)
#define INTCON ((volatile unsigned char *) 0x0B)
#define PIR1 ((volatile unsigned char *) 0x0C)
#define PIR2 ((volatile unsigned char *) 0x0D)
#define TMR1L ((volatile unsigned char *) 0x0E)
#define TMR1H ((volatile unsigned char *) 0x0F)
#define T1CON ((volatile unsigned char *) 0x10)
#define TMR2 ((volatile unsigned char *) 0x11)
#define T2CON ((volatile unsigned char *) 0x12)
#define PIE1 ((volatile unsigned char *) 0x8C)
#define PIE2 ((volatile unsigned char *) 0x8D)
#define OPTION_REG ((volatile unsigned char *) 0x81)


void delay(uint16_t a);// delay in ms


#endif 