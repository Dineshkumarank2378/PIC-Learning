
#include"lcd.h" 
 
 void lcd_init(volatile unsigned char*a,volatile unsigned char *b, uint8_t e,uint8_t rs )//  for initialize the lcd
    {
        for(uint8_t i=0;i<20;i++);
        lcd_dport=a;
        lcd_cport=b;
        lcd_en=e;
        lcd_rs=rs;
    }
    void lcd_cmd(uint8_t a) // for command
    {
        *lcd_cport&=(1<<lcd_rs);
        *lcd_dport=a;
        *lcd_cport&=~(1<<lcd_en);
        for(uint8_t t=0;t<10;t++)
        *lcd_cport|=(1<<lcd_en);    
        
    }
    
    void lcd_data(char b) // For data Transfer
    {
        *lcd_cport|=(1<<lcd_rs);
         *lcd_dport=b;
        *lcd_cport&=~(1<<lcd_en);
        for(uint8_t t=0;t<15;t++)
        *lcd_cport|=(1<<lcd_en);
    }
     
  void  lcd_out(char * c) // data to be transfered
    {      
        for(uint16_t i=0;c[i]!='\0';i++)
        {
            lcd_data(c[i]);
        }
    }
    