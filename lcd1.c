#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void lcdcmd(unsigned char);//this function is used for passing the commands
void lcddat(unsigned char);//this function is used for passing the characters
void delay();
void main()
{
	P2=0x00;//output deceleration
	while(1)
	{
		lcdcmd(0x38);//decleratin 5X7 matrix
		delay();
		lcdcmd(0x01);//clear the lcd display
		delay();
		lcdcmd(0x10);//curser blinking
		delay();
		lcdcmd(0x0c);//display on
		delay();
		lcdcmd(0x81);//force the cursur first line first position
		delay();
		lcddat('V');
		delay();
		lcddat('Y');
		delay();
		lcddat('A');
		delay();
		lcddat('N');
		delay();
		lcddat('K');
		delay();
		lcddat('A');
		delay();
		lcddat('T');
		delay();
		lcddat('E');
		delay();
		lcddat('S');
		delay();
		lcddat('H');
		delay();
		lcddat('<');
		delay();
		lcddat('<');
		delay();
		lcddat('<');
		delay();
		
	}
}
void lcdcmd(unsigned char val)
{
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char val)
{
	P2=val;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void delay()
{
	unsigned int i;
	for(i=0;i<12000;i++);
}