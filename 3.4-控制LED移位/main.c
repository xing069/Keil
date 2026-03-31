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

void mian()
{
	unsigned char LEDnum = 0;
	P2=~0x01;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			LEDnum++;
			if(LEDnum>=8)
			{
				LEDnum = 0;
			}
			P2 =~(0x01<<LEDnum);
			
		}
		if(P3_0 == 0)
			{
				Delay(20);
				while(P3_0 == 0);
				Delay(20);

				if(LEDnum==0)
				{
					LEDnum = 7;
				}
				else
				{
					LEDnum--;
				}
				
				P2 =~(0x01<<LEDnum);
				
			}
	}
	//0000 0001   <<0
	//0000 0010		<<1
	//0000 0100		<<2
	//0000 1000		<<3
	//0001 0000		<<4
	
	//0000 1000		<<3
	//0000 0100		<<2
}