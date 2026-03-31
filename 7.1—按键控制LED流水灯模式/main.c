#include <REGX52.H>
#include "Timer0.h"
//定时器初始化
//void Timer0_Init()
//{
//	//TMOD = 0x01;//0000 0001 T0定时器工作模式1  但也会影响T1定时器
//	TMOD &=0xF0; //把TMOD的低四位清零，高四位保持不变
//	TMOD |= 0x01;//把TMOD的最低位置一，高四位保持不变
//	TF0 = 0;
//	TR0 = 1;
//	TH0 = 64535/256;
//	TL0 = 64535%256;
//	ET0 = 1;
//	EA = 1;
//	PT0 = 0;
//}

int main()
{
	Timer0_Init();
	while(1)
	{
		
	}
}

//中断函数

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;//静态函数
	TH0 = 64535/256;
	TL0 = 64535%256;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count = 0;
		P2_0 = ~P2_0;
	}
}