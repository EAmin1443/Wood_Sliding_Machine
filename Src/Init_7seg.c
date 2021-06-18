#include <Init_7seg.h>
#include "main.h"

void display_init(void)
{
	static uint8_t spiTxBuf_init[2];
	#define Data spiTxBuf_init[0]
	#define Address spiTxBuf_init[1]
	extern SPI_HandleTypeDef hspi1;


		
	//******Display_Test_All digits(on)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x1; //Turn on all 8 digits
	Address=0xF;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	// Delay_function_with_a_for
	static int iii;
	for (iii=0;iii<1000000;iii++);
		
	//******Display_Test(off)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x0; // Turn off all 8 digits
	Address=0xF;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Display_Light_intensity******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x2; //intensity_Level
	Address=0xA; 
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
				
	//******Display_Normal_Mode(Shutdown/Normal)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x1; // 0:shutdown mode; 1:normal mode;
	Address=0xC;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Active_Display_Digits******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x7; //Active all 8 digits
	Address=0xB;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Active_Decode mode (or manual mode)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0xFF; // Active_Decode mode all 8 digits
	Address=0x09;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
//*** --------------------------Init primary value of height-----------------------------***//	
	

	//**************************Write of digit(1)**************************//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x00; 
	Address=0x1;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
		//**************************Write of digit(2)************************************//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x00 | 0x80;
	Address=0x2;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Write of digit(3)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x00; 
	Address=0x3;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Write of digit(4)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0xA; 
	Address=0x4;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
//*** --------------------------Init primary value of angle-----------------------------***//	

	
	//******Write of digit(5)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0xA; 
	Address=0x5;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Write of digit(6)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x00; 
	Address=0x6;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Write of digit(7)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x00 | 0x80; 
	Address=0x7;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
	
	//******Write of digit(8)******//
//1.Bring slave low
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
//2.Transmit register + data
	Data=0x00; 
	Address=0x8;
	HAL_SPI_Transmit(&hspi1, spiTxBuf_init, 1, 50);
//3.Bring slave select high
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);
}
