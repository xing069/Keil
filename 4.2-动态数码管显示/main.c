#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms)
	{
	
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} 
		while (--i);
		xms--;
	}
	
}

unsigned char NiXIETable[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
void NiXie(unsigned char Location,Number)
{
	switch(Location)
	{
		case 1:P2_4 = 1;P2_3 = 1; P2_2 = 1;break;//LED8×î×ó
		case 2:P2_4 = 1;P2_3 = 1; P2_2 = 0;break;//LED7
		case 3:P2_4 = 1;P2_3 = 0; P2_2 = 1;break;//LED6
		case 4:P2_4 = 1;P2_3 = 0; P2_2 = 0;break;//LED5
		case 5:P2_4 = 0;P2_3 = 1; P2_2 = 1;break;//LED4
		case 6:P2_4 = 0;P2_3 = 1; P2_2 = 0;break;//LED3
		case 7:P2_4 = 0;P2_3 = 0; P2_2 = 1;break;//LED2
		case 8:P2_4 = 0;P2_3 = 0; P2_2 = 0;break;//LED1×îÓÒ
	}
	P0 = LEDTable[Number];
	Delay(1);
	P0 = 0x00;
}

void main()
{
	
	
	while(1)
	{
		LED(1,1);
		//Delay(200);
		LED(2,1);
		//Delay(200);
		LED(3,4);
		//Delay(200);
		LED(4,5);
		//Delay(200);
		LED(5,1);
		//Delay(200);
		LED(6,4);
		//Delay(200);
		//LED(7,4);
		//Delay(200);
		//LED(8,1);
		//Delay(200);
	}

}