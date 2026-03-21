#include "D:\Learning Doc\PIC Learning\Header\GPIO\gpio.h"

#ifndef timer_H
#define timer_H

#define TMR0   (*((volatile unsigned char *) 0x01))
#define INTCON (*((volatile unsigned char *) 0x0B))
#define PIR1   (*((volatile unsigned char *) 0x0C))
#define PIR2   (*((volatile unsigned char *) 0x0D))
#define TMR1L  (*((volatile unsigned char *) 0x0E))
#define TMR1H  (*((volatile unsigned char *) 0x0F))
#define T1CON  (*((volatile unsigned char *) 0x10))
#define TMR2   (*((volatile unsigned char *) 0x11))
#define T2CON  (*((volatile unsigned char *) 0x12))
#define PIE1   (*((volatile unsigned char *) 0x8C))
#define PIE2   (*((volatile unsigned char *) 0x8D))
#define OPTION_REG (*((volatile unsigned char *) 0x81))

#define CCP1CON (*((volatile unsigned char *) 0x17))
#define CCP2CON (*((volatile unsigned char *) 0x1D))
#define CCPR1L   (*((volatile unsigned char *) 0x15))
#define CCPR1H   (*((volatile unsigned char *) 0x16))
#define CCPR2L   (*((volatile unsigned char *) 0x1B))
#define CCPR2H   (*((volatile unsigned char *) 0x1C))


#define TMR0_PRESCALER_2     0
#define TMR0_PRESCALER_4     1
#define TMR0_PRESCALER_8     2
#define TMR0_PRESCALER_16    3
#define TMR0_PRESCALER_32    4
#define TMR0_PRESCALER_64    5
#define TMR0_PRESCALER_128   6
#define TMR0_PRESCALER_256   7

#define TMR1_START 1
#define TMR1_STOP 0

#define CCP_RISING_EDGE 4
#define CCP_FALLING_EDGE 4
#define CCP_4TH_RISING_EDGE 4
#define CCP_16TH_RISING_EDGE 4



#define TMR1_PRESCALER_1   0
#define TMR1_PRESCALER_2   1
#define TMR1_PRESCALER_4   2
#define TMR1_PRESCALER_8   3


#define TMR2_ON 1
#define TMR2_OFF 0

#define TMR2_POSTSCALER_1 1 
#define TMR2_POSTSCALER_2 2
#define TMR2_POSTSCALER_3 3
#define TMR2_POSTSCALER_4 4
#define TMR2_POSTSCALER_5 5
#define TMR2_POSTSCALER_6 6
#define TMR2_POSTSCALER_7 7
#define TMR2_POSTSCALER_8 8
#define TMR2_POSTSCALER_9 9
#define TMR2_POSTSCALER_10 10
#define TMR2_POSTSCALER_11 11
#define TMR2_POSTSCALER_12 12
#define TMR2_POSTSCALER_13 13
#define TMR2_POSTSCALER_14 14
#define TMR2_POSTSCALER_15 15
#define TMR2_POSTSCALER_16 16

#define TMR2_PRESCALER_1 0
#define TMR2_PRESCALER_4 1
#define TMR2_PRESCALER_16 2



typedef struct
{
    uint8_t RBIF:1;     // bit0
    uint8_t INTF:1;     // bit1
    uint8_t TMR0IF:1;   // bit2
    uint8_t RBIE:1;     // bit3
    uint8_t INTE:1;     // bit4
    uint8_t TMR0IE:1;   // bit5
    uint8_t PEIE:1;     // bit6
    uint8_t GIE:1;      // bit7
} INTCON_REG_D;

#define INTCON_BITS ((volatile INTCON_REG_D *)0x0B)

typedef struct
{
    uint8_t TRM0_PRESCALER:3;      // bit0
    uint8_t T0SE:1;     // bit4
    uint8_t T0CS:1;     // bit5
    uint8_t INTEDG:1;   // bit6
    uint8_t RBPU:1;     // bit7
} OPTION_REG_D;

#define OPTION_REG_BITS ((volatile OPTION_REG_D *)0x81)

typedef struct
{
    uint8_t TMR1IE:1;   // bit0
    uint8_t TMR2IE:1;   // bit1
    uint8_t CCP1IE:1;   // bit2
    uint8_t SSPIE:1;    // bit3
    uint8_t TXIE:1;     // bit4
    uint8_t RCIE:1;     // bit5
    uint8_t ADIE:1;     // bit6
    uint8_t PSPIE:1;    // bit7
} PIE1_REG_D;

#define PIE1_BITS ((volatile PIE1_REG_D *)0x8C)

typedef struct
{
    uint8_t CCP2IE:1;   // bit0
    uint8_t :1;         // bit1
    uint8_t :1;         // bit2
    uint8_t BCLIE:1;    // bit3
    uint8_t EEIE:1;     // bit4
    uint8_t :1;         // bit5
    uint8_t CMIE:1;     // bit6
    uint8_t :1;         // bit7
} PIE2_REG_D;

#define PIE2_BITS ((volatile PIE2_REG_D *)0x8D)

typedef struct
{
    uint8_t TMR2_PRESCALER:2;    
    uint8_t TMR2ON:1;   
    uint8_t TMR2_POSTSCALER:4; 
    uint8_t :1;         
} T2CON_REG_D;

#define T2CON_BITS ((volatile T2CON_REG_D *)0x12)

typedef struct
{
    uint8_t TMR1ON:1;   
    uint8_t TMR1CS:1;   
    uint8_t T1SYNC:1;   
    uint8_t T1OSCEN:1;  
    uint8_t TMR1_PRESCALER:2;  
    uint8_t :1;         
    uint8_t :1;         
} T1CON_REG_D;

#define T1CON_BITS ((volatile T1CON_REG_D *)0x10)

typedef struct
{
    uint8_t CCP2IF:1;   // bit0
    uint8_t :1;         // bit1
    uint8_t :1;         // bit2
    uint8_t BCLIF:1;    // bit3
    uint8_t EEIF:1;     // bit4
    uint8_t :1;         // bit5
    uint8_t CMIF:1;     // bit6
    uint8_t :1;         // bit7
} PIR2_REG_D;

#define PIR2_BITS ((volatile PIR2_REG_D *)0x0D)

typedef struct
{
    uint8_t TMR1IF:1;   // bit0
    uint8_t TMR2IF:1;   // bit1
    uint8_t CCP1IF:1;   // bit2
    uint8_t SSPIF:1;    // bit3
    uint8_t TXIF:1;     // bit4
    uint8_t RCIF:1;     // bit5
    uint8_t ADIF:1;     // bit6
    uint8_t PSPIF:1;    // bit7
} PIR1_REG_D;

#define PIR1_BITS ((volatile PIR1_REG_D *)0x0C)

typedef struct
{
    uint8_t CCP1_MODE:4;
    uint8_t DC1B1:1;
    uint8_t DC1B0:1;
    uint8_t :2;
}CCP1CON_REG_D;

#define  CCP1CON_BITS ((volatile CCP1CON_REG_D *)0x17)

typedef struct
{
    uint8_t CCP2_MODE:4;
    uint8_t DC2B1:1;
    uint8_t DC2B0:1;
    uint8_t :2;
}CCP2CON_REG_D;

#define  CCP2CON_BITS ((volatile CCP2CON_REG_D *)0x1D)


///////////////////timer1/////////////////////
void delay_ms(uint16_t a);// delay in ms

void delay_us();

void timer0_enableinterrupt();

void timer0_disableinterrupt();

void timer0_external_clock();

void timer0_internal_clock();

void timer1_prescaler(uint8_t a);

////////////////////////////////////TIMER1//////////////////////////////

void timer1_enableinterrupt();

void timer1_disableinterrupt();

void timer1_internal_clock();

void timer1_external_clock();

void timer1_prescaler(uint8_t a);
 ////////////timer2/////////////////

void timer2_on();

void timer2_off();

void timer2_enableinterrupt();

void timer2_disableinterrupt();

void timer2_prescaler(uint8_t a);

void timer2_postscaler(uint8_t a);

////////////////////CAPTURE////////////////////

void capture1_mode(uint8_t a);

void capture2_mode(uint8_t a);

uint16_t capture1_read();

uint16_t capture2_read();


#endif 