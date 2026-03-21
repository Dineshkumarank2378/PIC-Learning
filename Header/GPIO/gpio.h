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


typedef struct
{
    uint8_t RA0:1;
    uint8_t RA1:1;
    uint8_t RA2:1;
    uint8_t RA3:1;
    uint8_t RA4:1;
    uint8_t RA5:1;
    uint8_t :1;
    uint8_t :1;
}PORTA_REG_D;

#define PORTA_BITS ((volatile PORTA_REG_D *)0X05)

typedef struct
{
    uint8_t TA0:1;
    uint8_t TA1:1;
    uint8_t TA2:1;
    uint8_t TA3:1;
    uint8_t TA4:1;
    uint8_t TA5:1;
    uint8_t :1;
    uint8_t :1;
}TRISA_REG_D;

#define TRISA_BITS ((volatile TRISA_REG_D *)0X85)

typedef struct
{
    uint8_t RB0:1;
    uint8_t RB1:1;
    uint8_t RB2:1;
    uint8_t RB3:1;
    uint8_t RB4:1;
    uint8_t RB5:1;
    uint8_t RB6:1;
    uint8_t RB7:1;
}PORTB_REG_D;

#define PORTB_BITS ((volatile PORTB_REG_D *)0X06)

typedef struct
{
    uint8_t TB0:1;
    uint8_t TB1:1;
    uint8_t TB2:1;
    uint8_t TB3:1;
    uint8_t TB4:1;
    uint8_t TB5:1;
    uint8_t TB6:1;
    uint8_t TB7:1;
}TRISB_REG_D;

#define TRISB_BITS ((volatile TRISB_REG_D *)0X86)

typedef struct
{
    uint8_t RC0:1;
    uint8_t RC1:1;
    uint8_t RC2:1;
    uint8_t RC3:1;
    uint8_t RC4:1;
    uint8_t RC5:1;
    uint8_t RC6:1;
    uint8_t RC7:1;
}PORTC_REG_D;

#define PORTC_BITS ((volatile PORTC_REG_D *)0X07)

typedef struct
{
    uint8_t TC0:1;
    uint8_t TC1:1;
    uint8_t TC2:1;
    uint8_t TC3:1;
    uint8_t TC4:1;
    uint8_t TC5:1;
    uint8_t TC6:1;
    uint8_t TC7:1;
}TRISC_REG_D;

#define TRISC_BITS ((volatile TRISC_REG_D *)0X87)

typedef struct
{
    uint8_t RD0:1;
    uint8_t RD1:1;
    uint8_t RD2:1;
    uint8_t RD3:1;
    uint8_t RD4:1;
    uint8_t RD5:1;
    uint8_t RD6:1;
    uint8_t RD7:1;
}PORTD_REG_D;

#define PORTD_BITS ((volatile PORTD_REG_D *)0X08)

typedef struct
{
    uint8_t TD0:1;
    uint8_t TD1:1;
    uint8_t TD2:1;
    uint8_t TD3:1;
    uint8_t TD4:1;
    uint8_t TD5:1;
    uint8_t TD6:1;
    uint8_t TD7:1;
}TRISD_REG_D;

#define TRISD_BITS ((volatile TRISD_REG_D *)0X88)

typedef struct
{
    uint8_t RE0:1;
    uint8_t RE1:1;
    uint8_t RE2:1;
    uint8_t :1;
    uint8_t :1;
    uint8_t :1;
    uint8_t :1;
    uint8_t :1;
}PORTE_REG_D;

#define PORTE_BITS ((volatile PORTE_REG_D *)0X09)

typedef struct
{
    uint8_t TRE0:1;
    uint8_t TRE1:1;
    uint8_t TRE2:1;
    uint8_t :1;
    uint8_t :1;
    uint8_t :1;
    uint8_t :1;
    uint8_t :1;
}TRISE_REG_D;

#define TRISE_BITS ((volatile TRISE_REG_D *)0X89)

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