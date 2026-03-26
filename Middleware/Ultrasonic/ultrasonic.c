/*
 * File:   ultrasonic.c
 * Author: Dinesh Kumaran K
 *
 * Created on 12 March, 2026, 8:59 PM
 */

#include "Ultrasonic.h"

static uint8_t ul_echo;
static uint8_t ul_trig;
static volatile unsigned char *ul_port;

void ultrasonic_init(volatile unsigned char *port, uint8_t echo, uint8_t trig)
{
    ul_echo = echo;
    ul_trig = trig;
    ul_port = port;

    // Set directions using TRIS address = PORT address + 0x80
    *(ul_port + 0x80) |=  (1 << ul_echo);   // echo = input
    *(ul_port + 0x80) &= ~(1 << ul_trig);   // trig = output

    // Keep trigger low initially
    *ul_port &= ~(1 << ul_trig);
}

uint16_t ultra_distance(void)
{
    uint16_t time;

    T1CON_BITS->TMR1_PRESCALER = TMR1_PRESCALER_8;
    T1CON_BITS->TMR1CS = 0;        // internal clock
    T1CON_BITS->T1OSCEN = 0;
    T1CON_BITS->TMR1ON = 0;

    TMR1H = 0x00;
    TMR1L = 0x00;

    // Trigger pulse: 10 us
    *ul_port &= ~(1 << ul_trig);
    delay_us(2);
    *ul_port |= (1 << ul_trig);
    delay_us(10);
    *ul_port &= ~(1 << ul_trig);

    // Wait for echo HIGH
    
    while (1)
    {
        if(((*ul_port & (1 << ul_echo)) > 0))
        break;
    }
    T1CON_BITS->TMR1ON = 1;

    // Wait for echo LOW
    while (1)
    {
        if(((*ul_port & (1 << ul_echo)) == 0))
        
        break;
    }
    T1CON_BITS->TMR1ON = 0;
    

    

    time = ((uint16_t)TMR1H << 8) | TMR1L;

    // For 20MHz oscillator, Timer1 prescaler 8:
    // tick = 1.6 us
    // distance = time * 1.6 * 0.0343 / 2
    // distance = time * 0.0274
    return (uint16_t)((time * 274UL) / 10000);
}