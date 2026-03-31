#include <REGX52.H>

unsigned char LEDTable[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
void LED(unsigned char Location,Number)
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
}

void main()
{
	//LED5-->Y4
	//P2_4 = 1;
	//P2_3 = 0;
	//P2_2 = 0;
	//P0 = 0x7D;
	LED(2,8);
	
	while(1)
	{
	
	}
}