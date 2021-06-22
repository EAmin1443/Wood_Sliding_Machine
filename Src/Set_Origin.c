#include <Set_Origin.h>
#include "Display_7seg.h"
#include "Write_Read_Flash.h"
#include "main.h"


void set_origin(void)
{
	extern signed int IT_counter_angle;
	extern signed int IT_counter_hight;
	//static int counter_loop=0;
	
	while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)==0)
{
	
	while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0)
	{
			IT_counter_hight=0;
			write_data(IT_counter_hight, IT_counter_angle);
			display_number(IT_counter_hight, IT_counter_angle);
	}
	
	while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)==0)
	{
			IT_counter_angle=0;
			write_data(IT_counter_hight, IT_counter_angle);
			display_number(IT_counter_hight , IT_counter_angle);
	}
}
}

