#include <REGX52.H>

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms)
	{
		//_nop_();
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


void main()
{
		while(1)
		{
			if(P3_1 == 0)//检测按下
			{
				Delay(20);//软件消抖
				while(P3_1 == 0);//只要不松手，就一直在空循环里不出来
				Delay(20);//松手消抖
				
				P2_7 =~P2_7;//~为按位取反符号
			}
		
		}

}	