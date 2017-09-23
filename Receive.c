#include<reg51.h>
#define ldata P1
sbit rs = P3^2;
sbit rw = P3^3;
sbit e = P3^4;
sbit ldr = P2^0;
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void lcdcmd(unsigned char value)
{
	ldata=value;
	rs=0;
	rw=0;
	e=1;
	msdelay(1);
	e=0;
	return;
}
void lcddata(unsigned char disp)
{
	ldata=disp;
	rs=1;
	rw=0;
	e=1;
	msdelay(1);
	e=0;
	return;
}
void lcdini()
{
	lcdcmd(0x38);
	msdelay(10);
	lcdcmd(0x0F);
	msdelay(10);
	lcdcmd(0x8F);
	msdelay(10);
	lcdcmd(0x04);
}
void display()
{
	if(ldr == 1)
	{
		lcddata('1');
	}
	else if(ldr == 0)
	{
		lcddata('0');
	}
}
void main()
{
	P1=0x00;
	lcdini();
	while(1)
	{
		while(ldr == 0)
		{
			msdelay(220);
			display();
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(120);
			display();
			lcdcmd(0x04);
			msdelay(220);
			msdelay(1000);
			lcdcmd(0x8F);
		}
	}
}
