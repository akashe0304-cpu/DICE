#include<LPC21XX.H>
#include"delay.h"
#define lcd 0xff<<0
#define RS 1<<8
#define E 1<<9
void LCD_INIT(void);
void LCD_COMMAND(unsigned int);
void LCD_DATA(unsigned int);
void LCD_STR(char*);


void LCD_INIT(void)
{
	IODIR0=lcd|RS|E;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X02);
	LCD_COMMAND(0X0C);
	LCD_COMMAND(0X38);
}
 void LCD_COMMAND(unsigned int cmd)
 {
	 IOCLR0=lcd;
	 IOSET0=cmd;
	 IOCLR0=RS;
	 IOSET0=E;
	 delayms(2);
	 IOCLR0=E;
 }
 void LCD_DATA(unsigned int data)
 {
	 IOCLR0=lcd;
	 IOSET0=data;
	 IOSET0=RS;
	 IOSET0=E;
	 delayms(2);
	 IOCLR0=E;
 }
 void LCD_STR(char*p)
 {
	 while(*p)
	 {
		 LCD_DATA(*p++);
	 }
 }
