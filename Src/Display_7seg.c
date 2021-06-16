#include <Display_7seg.h>
#include "main.h"


void display_number( signed int left_number, signed int right_number)
{
	extern SPI_HandleTypeDef hspi1;
	uint8_t spiTxBuf[2];
	#define Data spiTxBuf[0]
	#define Address spiTxBuf[1]
	
	static char ones;
	static char tens;
	static char hundreds;
	static int digiting;
//	static char angle_minus_flage=0;
//	static char height_minus_flage=0;

	/* limiting_3_digits */
	if (right_number<0)
	{	
//		angle_minus_flage=1;
		right_number=(right_number*-1);
	}
	if (left_number<0)
	{
//		height_minus_flage=1;
		left_number=(left_number*-1);
	}
	if (right_number>=999)
	{	
//		angle_minus_flage=1;
		right_number=999;
	}
	if (left_number>=999)
	{
//		height_minus_flage=1;
		left_number=999;
	}
	right_number=right_number%1000;
	left_number=left_number%1000;
	
	
	/* display_angle */
	right_number=right_number/1.03; //callibration factor
	ones=right_number%10;
	digiting=right_number/10;
	tens=digiting%10;				
	hundreds=digiting/10;	
	
	/*Write digit(1)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
	Data=ones; 
	Address=0x1;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	/*Write digit(2)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
	Data=tens | 0x80;
	Address=0x2;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	/*Write digit(3)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
//	if (angle_minus_flage==1)
//		Data=0xA;
//	if (angle_minus_flage==0)
		Data=hundreds; 
	Address=0x3;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//*Write digit(4)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
	Data=0xA; 
	Address=0x4;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);		      
	
	/* display_height */
	ones=left_number%10;
	digiting=left_number/10;
	tens=digiting%10;
	hundreds=digiting/10;
	
	/*Write digit(5)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
	Data=0xA; 
	Address=0x5;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	/*Write digit(6)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
	Data=ones;
	Address=0x6;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	/*Write of digit(7)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
	Data=tens | 0x80; 
	Address=0x7;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	/*Write of digit(8)*/
	//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	//2.Transmit register + data
//	if (height_minus_flage==1)
//		Data=0xA;
//	if (height_minus_flage==0)
		Data=hundreds; 
	Address=0x8;
	HAL_SPI_Transmit(&hspi1, spiTxBuf, 1, 50);
	//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
		
}
