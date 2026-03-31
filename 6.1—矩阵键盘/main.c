#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey");
	while(1)
	{
			KeyNum = MatrixKey();//按键按下后，对KeyNum赋值对应键码；不按下时，一直为0
			if(KeyNum !=0)//按键按下后，KeyNum被赋值不为0，进入if内的显示任务；
										//若未按下按键，KeyNum则未被赋值，KeyNum=0,无法进入if显示任务
			{
				LCD_ShowNum(2,1,KeyNum,2);//执行显示任务
			}
	}
}