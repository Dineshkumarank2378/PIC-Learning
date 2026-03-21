#include"timer.h"

void delay_ms(uint16_t a)// a in ms
{ 
    OPTION_REG&=~(1<<5);
    OPTION_REG&=~(1<<3);    
    OPTION_REG&=~(1<<1);    
    OPTION_REG|=(1<<0);    
    OPTION_REG|=(1<<2);
    
    TMR0=0x64;
    while(a>0)
    {
       
        if(INTCON&(1<<2))
        {
            INTCON&=~(1<<2);  
            a--;
            TMR0=0x64;
         
                    
        }
    
    }
}

void delay_us()
{
    asm("nop");  
}


void timer0_enableinterrupt()
{
    INTCON|=(1<<5);
}
void timer0_disableinterrupt()
{
    INTCON&=~(1<<5);
}
void timer0_external_clock()
{
    OPTION_REG_BITS->T0CS=1;
}
void timer0_internal_clock()
{
    OPTION_REG_BITS->T0CS=0;
}

void timer0_prescaler(uint8_t a)
{
    OPTION_REG_BITS->TRM0_PRESCALER=a;
}
///////////////////////TIMER1///////////////////



void timer1_enableinterrupt()
{
    PIE1_BITS->TMR1IE=1;
}

void timer1_disableinterrupt()
{
    PIE1_BITS->TMR1IE=0;
}

void timer1_internal_clock()
{
    T1CON_BITS->TMR1CS=0;
}

void timer1_external_clock()
{
    T1CON_BITS->TMR1CS=1;
}

void timer1_prescaler(uint8_t a)
{
    T1CON_BITS->TMR1_PRESCALER=a;
}








//////////////timer2/////////////////

void timer2(uint8_t a)
{
    T2CON|=(1<<2);
}

void timer2_enableinterrupt()
{
    PIR1_BITS->TMR2IF=1;
}

void timer2_disableinterrupt()
{
    PIR1_BITS->TMR2IF=0;
}

void timer2_postscaler(uint8_t a)
{
    T2CON_BITS->TMR2_POSTSCALER=a;
}

void timer2_prescaler(uint8_t a)
{
    T2CON_BITS->TMR2_PRESCALER=a;
}
/////////////////////////////////////////////////////////CAPTURE///////////////////////////////////////////


void capture1_mode(uint8_t a)
{
    CCP1CON_BITS->CCP1_MODE=a;
}

uint16_t capture1_read()
{
    uint16_t a=((CCPR1H<<8)|CCPR1L);
    return a;
}

void capture2_mode(uint8_t a)
{
    CCP2CON_BITS->CCP2_MODE=a;
}

uint16_t capture2_read()
{
    uint16_t a=((CCPR2H<<8)|CCPR2L);
    return a;
}

