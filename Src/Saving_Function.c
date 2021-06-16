#include <Saving_Function.h>
#include "Write_Read_Flash.h"
#include "main.h"

void Saving_Routin(void)
{
	extern signed int IT_counter_angle;
	extern signed int IT_counter_hight;
	extern int saving_index;
	extern int saving_loop;
	extern int saving_flage;
	
	if (saving_flage==0)
	{
	saving_index++;
	if (saving_index>=saving_loop)
	{
	write_data(IT_counter_hight, IT_counter_angle);
	saving_index=0;
	saving_flage=1;
	}
	}
}

