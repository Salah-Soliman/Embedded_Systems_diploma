/*
 * Stm32_F103C6_GPIO_Driver.h
 *
 *  Created on: May 23, 2024
 *      Author: Salah Soliman
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "Stm32f103x6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint16_t GPIO_PinNumber ;	//specifies the GPOI Pins to be configured.
								//this parameter must be set based on @ref GPIO_Pins-Define

	uint8_t GPIO_Mode;			//specifies the operating mode for the selected pins.
								//this parameter values are based on @ref GPIO_Mode-Define

	uint8_t GPIO_Output_Speed ; // Specifies the speed for the selected pins
								// This Parameter values are based on @ref GPIO_Speed_define

}GPIO_PinConfig_t;




//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_Pins-Define

#define GPIO_Pin_0				((uint16_t)0x0001) //Pin 0  Selected
#define GPIO_Pin_1				((uint16_t)0x0002) //Pin 1 Selected
#define GPIO_Pin_2				((uint16_t)0x0004) //Pin 2 Selected
#define GPIO_Pin_3				((uint16_t)0x0008) //Pin 3 Selected
#define GPIO_Pin_4				((uint16_t)0x0010) //Pin 4 Selected
#define GPIO_Pin_5				((uint16_t)0x0020) //Pin 5 Selected
#define GPIO_Pin_6				((uint16_t)0x0040) //Pin 6 Selected
#define GPIO_Pin_7				((uint16_t)0x0080) //Pin 7 Selected
#define GPIO_Pin_8				((uint16_t)0x0100) //Pin 8 Selected
#define GPIO_Pin_9				((uint16_t)0x0200) //Pin 9 Selected
#define GPIO_Pin_10				((uint16_t)0x0400) //Pin 10 Selected
#define GPIO_Pin_11				((uint16_t)0x0800) //Pin 11 Selected
#define GPIO_Pin_12				((uint16_t)0x1000) //Pin 12 Selected
#define GPIO_Pin_13				((uint16_t)0x2000) //Pin 13 Selected
#define GPIO_Pin_14				((uint16_t)0x4000) //Pin 14 Selected
#define GPIO_Pin_15				((uint16_t)0x8000) //Pin 15 Selected
#define GPIO_Pin_All			((uint16_t)0xFFFF) //All Pins Selected

#define GPIO_PIN_MASK			0x0000FFFFU //PIN mask for assert test


//@ref GPIO_Pin_state

#define GPIO_Pin_Set	1
#define GPIO_Pin_Reset	0

//@ref GPIO_Return_Lock
#define GPIO_Return_Lock_Enabled	1
#define GPIO_Return_Lock_Error		0

//@ref GPIO_Mode-Define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with Pull-up
//3: Input with Pull-down
//4: General Purpose output Push-pull
//5: General Purpose output Open-drain
//6: ALternative function output Push-pull
//7: Alternative function output Open-drain
//8: Alternative function Input

#define GPIO_Mode_Analog							0X00000000U  //Analog mode
#define GPIO_Mode_Input_FLO							0X00000001U  //Floating input
#define GPIO_Mode_Input_PU							0X00000002U  //Input with Pull-up
#define GPIO_Mode_Input_PD							0X00000003U  //Input with Pull-down
#define GPIO_Mode_Output_PP							0X00000004U  //General Purpose output Push-pull
#define GPIO_Mode_Output_OD							0X00000005U  //General Purpose output Open-drain
#define GPIO_Mode_Output_AF_PP						0X00000006U  //Alternative function output Push-pull
#define GPIO_Mode_Output_AF_OD						0X00000007U  //Alternative function output Open-drain
#define GPIO_Mode_AF_Input							0X00000008U  //Alternative function Input


//@ref GPIO_Speed_define
//0: Output mode , max speed 10 MHz .
//1: Output mode , max speed 2 MHz .
//3: Output mode , max speed 50 MHz .

#define GPIO_Speed_10M			0x00000001U  //Output mode , max speed 10 MHz .
#define GPIO_Speed_2M			0x00000002U  //Output mode , max speed 2 MHz .
#define GPIO_Speed_50M			0x00000003U  //Output mode , max speed 50 MHz .


// ==============================================
// APIs Supported by "MCAL GPIO DRIVER"
//===============================================

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber , uint8_t PinValue);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx , uint16_t PortValue);
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber);

void MCAL_GPIO_Init_Port_Range(GPIO_TypeDef *GPIOx , GPIO_PinConfig_t *PinConfig, uint8_t PinCount);




#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
