#include<stdint.h>
#ifndef gpio_H
#define gpio_H


#define high 1
#define low 0
#define input 1
#define output 0


#define PORTA ((volatile unsigned char*) 0x05)
#define TRISA ((volatile unsigned char*) 0x85)
#define PORTB ((volatile unsigned char*) 0x06)
#define TRISB ((volatile unsigned char*) 0x86)
#define PORTC ((volatile unsigned char*) 0x07)
#define TRISC ((volatile unsigned char*) 0x87)
#define PORTD ((volatile unsigned char*) 0x08)
#define TRISD ((volatile unsigned char*) 0x88)
#define PORTE ((volatile unsigned char*) 0x09)
#define TRISE ((volatile unsigned char*) 0x89)
#define ADCON1 ((volatile unsigned char*) 0x9F)



// configure the pin 
void  config_pin(volatile unsigned char * a,uint8_t bit,uint8_t c);

//set value to pin
void  sethigh(volatile unsigned char * a,uint8_t bit);
void  setlow(volatile unsigned char * a,uint8_t bit);


//configure the port
void config_port(volatile unsigned char *port,uint8_t c);

// set value to port
void setporthigh(volatile unsigned char *port);
void setportlow(volatile unsigned char *port);


// set the value
void setvalue(volatile unsigned char * a,uint8_t value);



void ledchaser(volatile unsigned char* a);// Run led chaser on specified port
void ledblink(volatile unsigned char* a);// blink the  specified port
void toggleport(volatile unsigned char *port);// toggle the specified port
//void delay (int a);// delay for given second

#endif