#include"gpio.h"

/*NOTE:PortA has only 6 pins
 *     PORTA 4th cant be high
       PortE has only 3 pins
 * usage of PORTB PORTC PORTD IS ADVISABLE*/
  

void  config_pin(volatile unsigned char * a,uint8_t bit,uint8_t c)
{
    if(c==0)
    { a=a+(0X80);
    *a&=~(1<<bit);}
    else if(c==1)
    {
         a=a+(0X80);
         *a|=1<<(bit);
    }
}

void sethigh(volatile unsigned char *a,uint8_t bit)
{
    *a|=(1<<(bit));
}

void setlow(volatile unsigned char *a,uint8_t bit)
{
   *a&=~(1<<(bit));
}

void setporthigh(volatile unsigned char *port)
{
    *port=0XFF;
}
void setportlow(volatile unsigned char *port)
{
    *port=0X00;
}

void config_port(volatile unsigned char *port,uint8_t c)
{
    if(c==0)
    {
        *(port+(0X80))=0X00;
    }
    else if(c==1)
    {
         *(port+(0X80))=0XFF;
    } 
}

void setvalue(volatile unsigned char * a,uint8_t value)
{
    *a=value;
}

void toggleport(volatile unsigned char *port)
{
    *port=~(*port);
}

void ledchaser(volatile unsigned char* a) 
{
    for( unsigned char i=0;i<8;i++)
    {*a=(char)(1<<i);
//    delay(1000);
}
}

void ledblink(volatile unsigned char* a)
{
    *a=~(*a);
  //  delay(10);
    *a=~(*a);
  //  delay(10);
    
}


//void delay (int a)
//{
//    while(a!=0)
//    {
//        for(uint16_t i=0;i<10;i++);
//        a--;
//    }
//}