#pragma once

#include <stdint.h>

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "Err_Types.h"







void keypad_clk_init(void)
{
	ST_RCC_Config_t keypad_clk =
	{
		.Sys_Clk_Select = HSI_system_clock_select,
		.PLL_clk_src = Half_HSI,
		.PLL_Factor = PLL_input_clock_x2,
		.AHP_Pres = AHP_SYSCLK_devided_by_8,
		.APB1_Pres = APB1_HCLK_not_divided,
		.APB2_Pres = APB2_HCLK_not_divided
	};

	RCC_Config(&keypad_clk);

	RCC_Enable_Peripheral(IOPAEN);
	RCC_Enable_Peripheral(IOPBEN);
}

void keypad_pins_init(void)
{
	ST_Pin_Config col1_pin =
	{
		.Port_X = PORT_COL ,
		.Pin_Num = COL1 ,
		.mode = KEYPAD_PIN_IN_TYPE,
		.speed = KEYPAD_PIN_SPEED
	}; 
	ST_Pin_Config col2_pin =
	{
		.Port_X = PORT_COL ,
		.Pin_Num = COL2 ,
		.mode = KEYPAD_PIN_IN_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};
	ST_Pin_Config col3_pin =
	{
		.Port_X = PORT_COL ,
		.Pin_Num = COL3 ,
		.mode = KEYPAD_PIN_IN_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};
	ST_Pin_Config col4_pin =
	{
		.Port_X = PORT_COL ,
		.Pin_Num = COL4 ,
		.mode = KEYPAD_PIN_IN_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};




	ST_Pin_Config row1_pin =
	{
		.Port_X = PORT_ROW ,
		.Pin_Num = ROW1 ,
		.mode = KEYPAD_PIN_OUT_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};
	ST_Pin_Config row2_pin =
	{
		.Port_X = PORT_ROW ,
		.Pin_Num = ROW2 ,
		.mode = KEYPAD_PIN_OUT_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};
	ST_Pin_Config row3_pin =
	{
		.Port_X = PORT_ROW ,
		.Pin_Num = ROW3 ,
		.mode = KEYPAD_PIN_OUT_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};
	ST_Pin_Config row4_pin =
	{
		.Port_X = PORT_ROW ,
		.Pin_Num = ROW4 ,
		.mode = KEYPAD_PIN_OUT_TYPE,
		.speed = KEYPAD_PIN_SPEED
	};

	GPIO_u8PIN_init(&col1_pin);
	GPIO_u8PIN_init(&col2_pin);
	GPIO_u8PIN_init(&col3_pin);
	GPIO_u8PIN_init(&col4_pin);
	GPIO_u8PIN_init(&row1_pin);
	GPIO_u8PIN_init(&row2_pin);
	GPIO_u8PIN_init(&row3_pin);
	GPIO_u8PIN_init(&row4_pin);
}

uint8_t keypad_get_pressed_key(void)
{
	uint8_t local_pressed_key; 

	uint8_t local_row_id; 
	uint8_t local_col_id;
	uint8_t local_pin_state = KEYPAD_NO_KEYS; 
	uint8_t local_col_arr[NUM_COL] = { COL1 , COL2 , COL3 , COL4 };
	uint8_t local_row_arr[NUM_ROW] = { ROW1 , ROW2 , ROW3 , ROW4 };

	uint8_t local_keypad_arr_val[NUM_ROW][NUM_COL] = KEYPAD_ARR_VAL;


	for (local_row_id = 0; local_row_id < NUM_ROW; local_row_id++)
	{
		GPIO_u8Set_Pin_Value(PORT_ROW, local_row_arr[local_row_id], PIN_LOW);

		for (local_col_id = 0; local_col_id < NUM_COL; local_col_id++)
		{
			GPIO_u8Read_Pin_Value(PORT_COL, local_col_arr[local_col_id], local_pin_state);
			
			if (local_pin_state == PIN_LOW)
			{
				local_pressed_key = local_keypad_arr_val[local_row_id][local_col_id];

				while (local_pin_state == PIN_LOW)
				{
					GPIO_u8Read_Pin_Value(PORT_COL, local_col_arr[local_col_id], local_pin_state);
				}

				return local_pressed_key;
			}
		}
	}
}