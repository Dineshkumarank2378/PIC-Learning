#include"keypad.h"

uint16_t keypadcal(unsigned volatile char *port)
{
    uint16_t a[3],temp=0,b=0,operator,i=0;
        while(1)
      {
        for(i=0;i<4;i++)
        {  
           *port =(char) (1 << i);
 
            if((*port)&0X10)
            {
                if(i==3)//division
                { operator='/';
                    a[0]=b;
                    a[1]='/';
                     b=0;
                }
                else
                {temp= i+7;
                 b=(b*10)+temp;
                } delay(100);
            }
            if((*port)&0X20)
            {
                 if(i==3)
                {operator='*';
                    a[0]=b;
                    a[1]='*';
                     b=0;
                     
                 }
                 else
                 {temp= i+4;//multiplication
                b=(b*10)+temp;} delay(100);
               
            }
            if((*port)&0X40)
            {
                 if(i==3)//subraction
                {
                    a[0]=b;
                    a[1]='-';
                     b=0;
                    
                 }
                 else
                 { temp= i+1; 
                
                 b=(b*10)+temp;} 
                 delay(100);
            }
            if((*port)&0X80)
            {
               if(i==0)//reset
               {a[0]=0;
               a[1]=0;
               
                 b=0;
               operator=0;
               }
                if(i==1)//zero
                { temp=0;
                delay(100);
                   b=(b*10)+temp;}
               if(i==2)//result
               { if(a[1]=='+')
                  {return (uint16_t)(a[0]+b);}                
                 if(a[1]=='-')
                  {return (uint16_t)(a[0]-b);}
                 if(a[1]=='*')
                  {return (uint16_t)(a[0]*b);}
                if(a[1]=='/')
                 { return (uint16_t)(a[0]/b);}
               }
               if(i==3)//addition
               {operator='+';
                    a[0]=b;
                    a[1]='+';
                     b=0;
               } delay(100);
            }
            
        }
    }
}


 

uint8_t keypad(volatile unsigned char *port)// 3*3, First 4 bit output next four bit 
    {
         while(1)
      {
        for(uint8_t i=0;i<4;i++)
        {
            //__delay_ms(1000);
            
           *port =( char) (1 << i);
 
            if((*port)&0X10)
            {

                return i+7;
            }
            if((*port)&0X20)
            {

               return i+4;
            }
            if((*port)&0X40)
            {

                return i+1;
            }
            if((*port)&0X80)
            {

                if(i==1)
                {
                return 0;}

            }
            
        }
    }
         } 