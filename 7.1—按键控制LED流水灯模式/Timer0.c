#include <REGX52.H>

void Timer0_Init()
{
	//TMOD = 0x01;//0000 0001 T0定时器工作模式1  但也会影响T1定时器
	TMOD &=0xF0; //把TMOD的低四位清零，高四位保持不变
	TMOD |= 0x01;//把TMOD的最低位置一，高四位保持不变
	TF0 = 0;
	TR0 = 1;
	TH0 = 64535/256;
	TL0 = 64535%256;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}
