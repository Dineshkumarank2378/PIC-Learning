#include "sevseg.h"

char sevseg(int a)
{
     unsigned char A[10]={0xBF,0X86,0XDB,0XCF,0XE6,0XED,0XFD,0X87,0XFF,0XEF};
     return A[a];
}

void counter_sevseg(volatile unsigned char *a)
{
    for(volatile char i=0;i<10;i++)
    {
        *a=sevseg(i);
         delay(1000);
        
    }
}

void counter_2sevseg(volatile unsigned char *port,volatile unsigned char *eport, uint8_t a, uint8_t b)
{
    for(uint8_t i=0;i<10;i++)
    {
        for(uint8_t j=0;j<10;j++)
        { 
            for(uint16_t k=0;k<100;k++)
            {
                 sethigh(eport,a);
            sethigh(eport,b);
            *port=sevseg(i);
            setlow(eport,a);
           delay(1);
            sethigh(eport,a);
            sethigh(eport,b);
            *port=sevseg(j);
             setlow(eport,b);
             delay(1);
            }
            
            
        }
    }
}

void display_2sevseg(volatile unsigned char *port,volatile unsigned char *eport, uint8_t a, uint8_t b,uint8_t c)
{
    uint8_t ones=c%10;
    uint8_t tens =c/10;
    for(uint8_t i=0;i<250;i++)
    {
        sethigh(eport,a);
        sethigh(eport,b);
        *port=sevseg(ones);
        setlow(eport,b);
        delay(1);
         sethigh(eport,a);
        sethigh(eport,b);
        *port=sevseg(tens);
        setlow(eport,a);
        delay(1);     
    }
}