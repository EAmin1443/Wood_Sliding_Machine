#include <Write_Read_Flash.h>
#include "main.h"


void write_data(int data_height, int data_angle)
{
	static char sector=11;
	extern uint32_t address_height;
	extern uint32_t address_angle;
	HAL_FLASH_Unlock();
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
  FLASH_Erase_Sector(sector, FLASH_VOLTAGE_RANGE_3);
		
	HAL_StatusTypeDef check = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address_height, data_height);
	check = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address_angle, data_angle);
	while(check!=HAL_OK);
	HAL_Delay(10);
	HAL_FLASH_Lock();
}

void read_data(void)
{
	extern signed int IT_counter_angle;
	extern signed int IT_counter_hight;
	extern uint32_t address_height;
	extern uint32_t address_angle;

	IT_counter_hight= *(uint16_t *)address_height; //Read 16bit
	IT_counter_angle= *(uint16_t *)address_angle; //Read 16bit	
	
	if (IT_counter_hight>0xFF00)
		IT_counter_hight=-((IT_counter_hight^0xFFFF)+1);
	if (IT_counter_angle>0xFF00)
		IT_counter_angle=-((IT_counter_angle^0xFFFF)+1);
}

