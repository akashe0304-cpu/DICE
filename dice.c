#include<lpc21xx.h>
#include"lcdheader.h"
#define sw1 1<<12
#define sw2 1<<13
void TIMER(void);
void LCD_DISPLAY(int);
int arr[6],i=0;
unsigned char pattern[6][8] = {
 {0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00}, 
 {0x18,0x18,0x00,0x00,0x00,0x00,0x03,0x03},  
 {0x18,0x18,0x00,0x06,0x06,0x00,0x03,0x03}, 
 {0x1B,0x1B,0x00,0x00,0x00,0x00,0x1B,0x1B},  
 {0x1B,0x1B,0x00,0x04,0x04,0x00,0x1B,0x1B},  
 {0x1B,0x1B,0x00,0x1B,0x1B,0x00,0x1B,0x1B}   
};
int main()
{
	int j,l,k;
	LCD_INIT();
	LCD_COMMAND(0X85);
	LCD_STR("START");
	LCD_COMMAND(0XC5);
	LCD_STR("GAME");
	for(l=0;l<6;l++)
			{
				LCD_COMMAND(0X40+(l*8));
				for(k=0;k<8;k++)
				LCD_DATA(pattern[l][k]);
			}
	while(1)
	{
		if((IOPIN0&sw1)==0)
		{
			LCD_INIT();
			LCD_COMMAND(0X80);
			LCD_STR("PLAYER-1:");
			TIMER();
		}
		if((IOPIN0&sw2)==0)
		{
			LCD_INIT();
			for(j=0;j<6;j++){
			LCD_COMMAND(0X80);
			LCD_STR("UNDO:");
			LCD_DATA(arr[j]+48);
			delayms(500);}
			LCD_COMMAND(0X01);
			LCD_COMMAND(0X85);
			LCD_STR("RESET");
			
		}		
	}
	
}
void TIMER(void)
{
	int a;
	T0PR=6-1;
	T0TCR=0X01;
	while((IOPIN0&sw1)==0);
	a=(T0TC%6)+1;
	T0TCR=0X03;
	T0TCR=0X00;
	LCD_DATA((a)+48);
	LCD_DISPLAY(a);
	arr[i]=a;
	i++;
	if(i==6)
		i=0;
}
void LCD_DISPLAY(int n)
{
	LCD_COMMAND(0XC5);
	LCD_DATA(n-1);
}
