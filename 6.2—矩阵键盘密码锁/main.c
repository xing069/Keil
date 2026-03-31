#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;
unsigned int RightPassword = 1027;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
			KeyNum = MatrixKey();
			if(KeyNum !=0)
			{
					if(KeyNum <= 10)//如果S1~S10按键按下，输入密码
					{
						if(Count<4)//输入次数<4
						{
								Password*=10;//密码左移一位
								Password+=KeyNum % 10;//获得一位密码；输入10的时候输出0，输入1~9的时候仍一一对应	
								Count++;//计次
						}
						LCD_ShowNum(2,1,Password,4);
					}
					if(KeyNum == 11)
					{
						if(Password == RightPassword)
						{
								LCD_ShowString(1,14,"Yes");
								Password = 0;//密码清零
								Count = 0;	 //计次清零
								LCD_ShowNum(2,1,Password,4);//更新显示 
						}
						else
						{
								LCD_ShowString(1,14,"NO ");
								Password = 0;//密码清零
								Count = 0;	 //计次清零
								LCD_ShowNum(2,1,Password,4);//更新显示
						}	
					}
			}
			if(KeyNum == 12)
			{
					Password = 0;//密码清零
					Count = 0;	 //计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示
			}
	}
}