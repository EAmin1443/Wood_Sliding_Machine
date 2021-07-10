#include <Interrupt_Callback.h>
#include "main.h"
#include "Display_7seg.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	extern signed int IT_counter_angle;
	extern signed int IT_counter_hight;
	extern int saving_index;
	extern int saving_flage;
	 char angle_plus_key;
	 char angle_minus_key;
	 char angle_minus_index;
	 char angle_plus_index;
	 char height_plus_key;
	 char height_minus_key;
	 char height_plus_index;
	 char height_minus_index;

	if(GPIO_Pin == GPIO_PIN_1)
	{
		height_plus_key=HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
		height_minus_key=HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);

		if(height_plus_key==0)
		{
		height_minus_index=0;
		IT_counter_hight++;
		height_plus_index++;
		}
		if(height_minus_key==0)
		{
		height_plus_index=0;
		IT_counter_hight--;
		height_minus_index++;
		}
		if ((height_minus_key==1) && (height_plus_key==1))
		{
		if (height_plus_index!=0)
		IT_counter_hight++;
		if (height_minus_index!=0)
		IT_counter_hight--;
		}
	 } 

	if(GPIO_Pin == GPIO_PIN_3)
 {
		angle_minus_key=HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
		angle_plus_key=HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);
					
		if(angle_plus_key==0)
		{
		angle_minus_index=0;
		IT_counter_angle++;
		angle_plus_index++;
		}
		
		if(angle_minus_key==0)
		{
		angle_plus_index=0;
		IT_counter_angle--;
		angle_minus_index++;
		}
						
		if ((angle_minus_key==1)&&(angle_plus_key==1))
		{
		if (angle_plus_index!=0)
		IT_counter_angle++;
		if (angle_minus_index!=0)
		IT_counter_angle--;
		}
  } 
display_number(IT_counter_hight , IT_counter_angle);	
saving_index=0;
saving_flage=0;	
}

