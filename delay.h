#include<LPC21XX.H>
void delays(unsigned int );
void delayms(unsigned int );

void delays(unsigned int n)
{
	T0PR=15000000-1;
	T0TCR=0X01;
	while(T0TC<n);
	T0TCR=0X03;
	T0TCR=0X00;
}
void delayms(unsigned int n)
{
	T0PR=15000-1;
	T0TCR=0X01;
	while(T0TC<n);
	T0TCR=0X03;
	T0TCR=0X00;
}
