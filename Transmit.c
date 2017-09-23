#include<reg51.h>
sbit C4 = P1^0;     // Connecting keypad to Port 1
sbit C3 = P1^1;
sbit C2 = P1^2;
sbit C1 = P1^3;
sbit R4 = P1^4;
sbit R3 = P1^5;
sbit R2 = P1^6;
sbit R1 = P1^7;

sbit bit0 = P2^0;
sbit bit1 = P2^1;
sbit bit2 = P2^2;
sbit bit3 = P2^3;
sbit bit4 = P2^4;
sbit bit5 = P2^5;
sbit bit6 = P2^6;
sbit bit7 = P2^7;

sbit led = P3^1;

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void send()
	{
		//	P3=0x00;
			led=0;
			msdelay(400);
			led=bit0;
			msdelay(250);
			led=bit1;
			msdelay(250);
			led=bit2;
			msdelay(250);
			led=bit3;
			msdelay(250);
			led=bit4;
			msdelay(250);
			led=bit5;
			msdelay(250);
			led=bit6;
			msdelay(250);
			led=bit7;
			msdelay(400);
			led=1;
	}


void row_finder1() //Function for finding the row for column 1
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
	if(R1==0)
	{
		P2=0x01;
		send();
	}
	if(R2==0)
	{
		P2=0x04;
		send();
	}
	if(R3==0)
	{
		P2=0x07;
		send();
	}
	if(R4==0)
	{
		P2=0x00;
		send();
	}
}
void row_finder2() //Function for finding the row for column 2
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
	if(R1==0)
	{
		P2=0x02;
		send();
	}
	if(R2==0)
	{
		P2=0x05;
		send();
	}
	if(R3==0)
	{
		P2=0x08;
		send();
	}
	if(R4==0)
	{
		P2=0x00;
		send();
	}
}
void row_finder3() //Function for finding the row for column 3
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
	if(R1==0)
	{
		P2=0x03;
		send();
	}
	if(R2==0)
	{
		P2=0x06;
		send();
	}
	if(R3==0)
	{
		P2=0x09;
		send();
	}
	if(R4==0)
	{
		P2=0x00;
		send();
	}
}
void row_finder4() //Function for finding the row for column 4
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
	if(R1==0)
	{
		P2=0x0A;
		send();
	}
	if(R2==0)
	{
		P2=0x0B;
		send();
	}
	if(R3==0)
	{
		P2=0x0C;
		send();
	}
	if(R4==0)
	{
		P2=0x0D;
		send();
	}
}
	
void main()
{
    while(1)
    {    
        //msdelay(30); 
        C1=C2=C3=C4=1;
          R1=R2=R3=R4=0;
          if(C1==0)
					{
						row_finder1();
					}
          else if(C2==0)
          { 
						row_finder2();
					}
           else if(C3==0)
					 {
						row_finder3();
					 }
					else if(C4==0)
					{
						row_finder4();
					}
    }
}
