
#include <stdint.h>
#include "../../../Common/Bit_Operations.h"
#include "../../../MCAL/GPIO/inc/GPIO_interface.h"
#include "../../../Common/Error_type.h"
#include "../inc/led_interface.h"
#include "../../../MCAL/RCC/inc/RCC_interface.h"



uint8_t led_pin_init_clk(EN_Port_t port, EN_Pin_t pin)
{
	ST_RCC_Config_t led_pin =
	{
		.Sys_Clk_Select = HSI_system_clock_select,
		.PLL_clk_src = Half_HSI,
		.PLL_Factor = PLL_input_clock_x2,
		.AHP_Pres = AHP_SYSCLK_not_devided,
		.APB1_Pres = APB1_HCLK_not_divided,
		.APB2_Pres = APB2_HCLK_not_divided
	};


	RCC_Config(&led_pin);

	RCC_Enable_Peripheral(port+IOPAEN); /* IOP offset in APB2 BUS ( ENUM ) IOPAEN = 34*/
}

uint8_t led_pin_init(EN_Port_t port, EN_Pin_t pin)
{
	ST_Pin_Config led_pin =
	{
		.Port_X = port ,
		.Pin_Num = pin ,
		.mode = OUTPUT_PUSH_PULL,
		.speed = MAX_PIN_2_MHZ
	};

	GPIO_u8PIN_init(&led_pin);
}

uint8_t led_On(EN_Port_t port, EN_Pin_t pin)
{
	uint8_t Local_u8_Error_State = OK;

	if (port <= PORTG && pin <= PIN15)
	{
		Local_u8_Error_State = GPIO_u8Set_Pin_Value(port, pin, PIN_HIGH);
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t led_Off(EN_Port_t port, EN_Pin_t pin)
{
	uint8_t Local_u8_Error_State = OK;

	if (port <= PORTG && pin <= PIN15)
	{
		Local_u8_Error_State = GPIO_u8Set_Pin_Value(port, pin, PIN_LOW);
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}
