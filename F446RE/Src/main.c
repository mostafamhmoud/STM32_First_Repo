/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "../MCAL/RCC/inc/RCC_interface.h"
#include "../MCAL/GPIO/inc/GPIO_interface.h"
#include "../MCAL/NVIC/inc/NVIC_interface.h"
#include "../MCAL/EXTI/inc/EXTI_interface.h"
#include "../MCAL/SYSCFG/inc/SYSCFG_interface.h"


/*
int main(void)
{

	NVIC_EnableIRQ(DMA1_Stream0_IRQn);

	ST_RCC_Config_t rcc_user_specs =
	{
		.Sys_Clk_Select = HSI_system_clock_select,
		.PLL_clk_src = HSI,
		.PLLM_Pres = 50 ,
		.PLLN_Factor = 200 ,
		.PLLP_Pres = PLLP_devided_by_2,
		.AHP_Pres = AHB_SYSCLK_devided_by_4,
		.APB1_Pres = APB1_HCLK_not_divided,
		.APB2_Pres = APB2_HCLK_not_divided
	};

	RCC_Config(&rcc_user_specs);

	RCC_Enable_Peripheral(GPIOAEN);

	ST_Pin_Config led_pin =
	{
			.Port_X = PORTA ,
			.mode = OUTPUT ,
			.Pin_Num = PIN5 ,
			.speed = LOW ,
			.Output_Type = PUSH_PULL ,
			.PullType = NO_PULL
	};

	GPIO_u8PIN_init(&led_pin);
	GPIO_u8Set_Pin_Value(PORTA , PIN5 , PIN_HIGH) ;

	for(;;);
}

void DMA1_Stream0_IRQHandler(void)
{
	int x = 50;
}

*/


void EXTI0_func(void);
int main()
{
	ST_RCC_Config_t rcc_user_specs =
	{
		.Sys_Clk_Select = HSI_system_clock_select,
		.PLL_clk_src = HSI,
		.PLLM_Pres = 50 ,
		.PLLN_Factor = 200 ,
		.PLLP_Pres = PLLP_devided_by_2,
		.AHP_Pres = AHB_SYSCLK_devided_by_4,
		.APB1_Pres = APB1_HCLK_not_divided,
		.APB2_Pres = APB2_HCLK_not_divided
	};

	RCC_Config(&rcc_user_specs);

	RCC_Enable_Peripheral(GPIOCEN);
	RCC_Enable_Peripheral(GPIOAEN);


	ST_Pin_Config butt_pin =
	{
			.Port_X = PORTC ,
			.mode = INPUT ,
			.Pin_Num = PIN13 ,
			.speed = LOW ,
			.PullType = PULL_UP
	};

	ST_Pin_Config led_pin =
	{
			.Port_X = PORTA ,
			.mode = OUTPUT ,
			.Pin_Num = PIN5 ,
			.Output_Type = PUSH_PULL,
			.speed = LOW ,
			.PullType = NO_PULL
	};

	GPIO_u8PIN_init(&butt_pin);
	GPIO_u8PIN_init(&led_pin);

	ST_EXTI_Config_t pin_int =
	{
		.line_num = EXTI_LINE0,
		.edge_detect = FALLING_TRIG,
		.init_state = ENABLE,
		.CallBackFun = EXTI0_func,
	};

	EXTI_init(&pin_int);

	SYSCFG_Set_Line(PC, LINE0);


}


void EXTI0_func(void)
{
	GPIO_u8Set_Pin_Value(PORTA, PIN5, PIN_HIGH);
}
