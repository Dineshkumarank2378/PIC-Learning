#include"timer.h"

void delay(uint16_t a)// a in ms
{ 
    *OPTION_REG&=~(1<<5);
    *OPTION_REG&=~(1<<3);    
    *OPTION_REG&=~(1<<1);    
    *OPTION_REG&=~(1<<0);    
    *OPTION_REG|=(1<<2);
    
    *TMR0=0x64;
    while(a>0)
    {
       
        if(*INTCON&(1<<2))
        {
            *INTCON&=~(1<<2);  
            a--;
           *TMR0=0x64;
         
                    
        }
    
    }}
