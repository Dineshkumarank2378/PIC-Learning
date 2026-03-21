/*
 * File:   ultrasonic.c
 * Author: Dinesh Kumaran K
 *
 * Created on 12 March, 2026, 8:59 PM
 */


#include"Ultrasonic.h"

static uint8_t ul_echo ;
static uint8_t ul_trig ;
static volatile unsigned char * ul_port ;

void ultrasonic_init(volatile unsigned char * port,uint8_t a,uint8_t b)
{
    ul_echo=a;
    ul_trig=b;
    ul_port=port;
}
uint16_t ultra_distance()
{
    T1CON_BITS->TMR1_PRESCALER=TMR1_PRESCALER_8;
    
    T1CON_BITS->TMR1CS=0;
      T1CON_BITS->T1OSCEN = 0; 
    TMR1L=0X00;
    TMR1H=0X00;
 //while(1){
     *ul_port|=(1<<ul_trig);
  // delay_us();

   
    *ul_port&=~(1<<ul_trig);
 
    while(1)
    {
       if((*ul_port&(1<<ul_echo)))
       {
            T1CON_BITS->TMR1ON=1;
            
            break;
       }
    }
    
   while(1)
   {
       if((*ul_port&(1<<ul_echo))==0)
       {
            T1CON_BITS->TMR1ON=0;
           
            
            break;
       }
   }
   uint16_t time=0X0000;
          time= (((TMR1H)<<8)|time);
          time=time|(TMR1L);
                  
   
          uint16_t distance =(((time*1.6)*0.0343))/2;
          return distance;
    
}
