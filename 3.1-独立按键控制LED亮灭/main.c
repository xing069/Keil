#include <REGX52.H>

int main()
{
	//P2=0xFE;
	//P2_0 = 0;
	while(1)
		{
				if(P3_1 == 0 && P3_0 == 0 )//按下为0，可以利用逻辑与，同时按下时亮
				{
					P2_0 = 0;//亮
				}
				else
				{
					P2_0 = 1;//灭
				}	
		}	
}