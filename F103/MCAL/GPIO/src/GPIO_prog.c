#include <stdint.h>
#include "../../../Common/Stm32F103xx.h"
#include "../inc/GPIO_interface.h"
#include "../inc/GPIO_private.h"
#include "../../../Common/Error_type.h"



uint8_t GPIO_u8PIN_init(const ST_Pin_Config* pin_config)
{
	uint8_t Local_u8_Error_State = OK;
	uint8_t in_or_out = 0 ;
	ST_GPIO_RegDef_t* port_id = (ST_GPIO_RegDef_t*)((uint32_t)GPIOA + (pin_config->Port_X) * 0x400);
	if (pin_config != NULL)
	{
		if (pin_config->Port_X <= PORTG && pin_config->Pin_Num <= PIN15)
		{
			port_id->CR[pin_config->Pin_Num / 8] &= ~(PIN_MODE_MASK << (4 * (pin_config->Pin_Num % 8)));
			port_id->CR[pin_config->Pin_Num / 8] |= (pin_config->mode << (4 * (pin_config->Pin_Num % 8)));

			in_or_out = (port_id->CR[pin_config->Pin_Num / 8] & (0b11 << (4 * (pin_config->Pin_Num % 8)))) >> (4 * (pin_config->Pin_Num % 8));
			if (in_or_out != 0) /* this pin is output then detect speed */
			{
				port_id->CR[pin_config->Pin_Num / 8] &= ~(PIN_SPEED_MASK << (4 * (pin_config->Pin_Num % 8)));
				port_id->CR[pin_config->Pin_Num / 8] |= (pin_config->speed << (4 * (pin_config->Pin_Num % 8)));
			}
		}
		else
		{
			Local_u8_Error_State = PORTS_PINS_ERR;
		}
	}
	else
	{
		Local_u8_Error_State = NULL_PTR_ERR;
	}
	return Local_u8_Error_State ;
}

uint8_t GPIO_u8Set_Pin_Value(EN_Port_t Port_X, EN_Pin_t pin, EN_Pin_Value_t Pin_Value)
{
	uint8_t Local_u8_Error_State = OK;

	ST_GPIO_RegDef_t* port_id = (ST_GPIO_RegDef_t*)((uint32_t)GPIOA + Port_X * 0x400);

	if (Port_X <= PORTG && (pin <= 15)) // check if port and pin_number are Valid
	{
		(Pin_Value == PIN_HIGH) ? (port_id->BSRR = (1 << pin)) : (port_id->BSRR = (1 << (pin + 16)));
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t GPIO_u8Set_PORT_Value(EN_Port_t Port_X, uint32_t value)
{
	uint8_t Local_u8_Error_State = OK;

	ST_GPIO_RegDef_t* port_id = (ST_GPIO_RegDef_t*)((uint32_t)GPIOA + Port_X * 0x400);

	if (Port_X <= PORTG ) // check if port and pin_number are Valid
	{
		port_id->ODR = value;
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t GPIO_u8Get_PORT_Value(EN_Port_t Port_X, uint32_t* value)
{
	uint8_t Local_u8_Error_State = OK;

	ST_GPIO_RegDef_t* port_id = (ST_GPIO_RegDef_t*)((uint32_t)GPIOA + Port_X * 0x400);

	if (Port_X <= PORTG) // check if port and pin_number are Valid
	{
		*value = port_id->ODR;
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t GPIO_u8Toggle_Pin_Value(EN_Port_t Port_X, EN_Pin_t pin)
{
	uint8_t Local_u8_Error_State = OK;

	ST_GPIO_RegDef_t* port_id = (ST_GPIO_RegDef_t*)((uint32_t)GPIOA + Port_X * 0x400);

	if (Port_X <= PORTG && (pin <= 15)) // check if port and pin_number are Valid
	{
		TOGGLE_BIT(port_id->ODR, pin);
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t GPIO_u8Read_Pin_Value(EN_Port_t Port_X, EN_Pin_t pin, EN_Pin_Value_t* Pin_Value)
{
	uint8_t Local_u8_Error_State = OK;

	ST_GPIO_RegDef_t* port_id = (ST_GPIO_RegDef_t*)((uint32_t)GPIOA + Port_X * 0x400);

	if (Port_X <= PORTG && (pin <= 15)) // check if port and pin_number are Valid
	{
		*Pin_Value = READ_BIT(port_id->ODR, pin);
	}
	else
	{
		Local_u8_Error_State = PORTS_PINS_ERR;
	}
	return Local_u8_Error_State;
}


