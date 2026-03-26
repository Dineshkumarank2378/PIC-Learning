

#include "D:\Learning Doc\PIC Learning\Header\GPIO\gpio.h"
#include"D:\Learning Doc\PIC Learning\Header\Timer\timer.h"

#ifndef ultrasonic_H
#define ultrasonic_H
 
void ultrasonic_init(volatile unsigned char * port,uint8_t a,uint8_t b);

uint16_t ultra_distance();


#endif