
#include"lcd.h" 
 


static  volatile unsigned char *lcd_dport  ;
static  volatile unsigned char * lcd_cport;
static uint8_t  lcd_en;
static uint8_t lcd_rs;



 void lcd_config(volatile unsigned char*a,volatile unsigned char *b, uint8_t e,uint8_t rs )
    {
     delay_ms(20);
        lcd_dport=a;
        lcd_cport=b;
        lcd_en=e;
        lcd_rs=rs;
    }
 
 void lcd_init()
{
    *lcd_cport&=~(1<<lcd_rs);  
      delay_ms(20);   
	lcd_cmd(0x38);
	
	lcd_cmd(0x0c);
	
	lcd_cmd(0x06);
    
    lcd_cmd(0x01);

    lcd_cmd(0x80);      
    delay_ms(3);
	
}
void lcd_cmd(uint8_t a) // for command
    {
        *lcd_cport&=~(1<<lcd_rs);
        *lcd_dport=a;
         lcd_enable();   
        
    }
    
void lcd_data(uint8_t b) // For data Transfer
    {
        *lcd_cport|=(1<<lcd_rs);
         *lcd_dport=b;
         lcd_enable();
    }
     
void  lcd_out(char * c) // data to be transfered
    {      
        for(uint16_t i=0;c[i]!='\0';i++)
        {
            lcd_data(c[i]);
        }
    }
    
void lcd_enable()
  {
     
    *lcd_cport &= ~(1<<lcd_en);
    delay_ms(1);
    *lcd_cport |= (1<<lcd_en);
    delay_ms(1);
    *lcd_cport &= ~(1<<lcd_en);
    delay_ms(2);      
  }