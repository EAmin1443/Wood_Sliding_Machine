#include <Height_Angle_Motor.h>
#include "main.h"

void height_increasing(void)
{
extern signed int IT_counter_hight;
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9)==0 && IT_counter_hight<700)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
		}
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
}

void height_decreasing(void)
{
extern signed int IT_counter_hight;
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0 && IT_counter_hight>-100)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
		}
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
}

void angle_increasing(void)
{
extern signed int IT_counter_angle;
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0 && IT_counter_angle<474)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
		}
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
}

void angle_decreasing(void)
{
extern signed int IT_counter_angle;
		while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)==0 && IT_counter_angle>-100)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		}
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
}


