#include <stdint.h>

#include "../../../Common/Bit_Operations.h"
#include "../../../Common/Error_type.h"
#include "../../../Common/Stm32F103xx.h"
#include "../inc/RCC_private.h"
#include "../inc/RCC_interface.h"



uint8_t RCC_Enable_HSI(void)
{
	uint8_t Local_u8_Error_State = OK;
	uint16_t wait = 0;
	SET_BIT(RCC->CR, HSION);
	while ((RCC->CR & (1 << HSIRDY)) == 0)
	{
		if (wait >= 500)
		{
			Local_u8_Error_State = TIMEOUT_ERR;
			break;
		}
		wait++;
	}
	SET_BIT(RCC->CIR, HSIRDYC); /* clear flag */

	RCC->CFGR &= ~(CLOCK_SWITCH_MASK << SW0);
	RCC->CFGR |= (HSI_system_clock_select << SW0);

	return Local_u8_Error_State;

}
uint8_t RCC_Enable_HSE(void)
{
	uint8_t Local_u8_Error_State = OK;
	uint16_t wait = 0;
	SET_BIT(RCC->CR, HSEON);
	while ((RCC->CR & (1 << HSERDY)) == 0)
	{
		if (wait >= 500)
		{
			Local_u8_Error_State = TIMEOUT_ERR;
			break;
		}
		wait++;
	}
	SET_BIT(RCC->CIR, HSERDYC); /* clear flag */

	RCC->CFGR &= ~(CLOCK_SWITCH_MASK << SW0);
	RCC->CFGR |= (HSE_system_clock_select << SW0);

	return Local_u8_Error_State;
}
uint8_t RCC_Enable_PLL(EN_PLL_Clk_Source_t clk_src , EN_PLLMUL_Factor_t mul_factor)
{
	uint8_t Local_u8_Error_State = OK;
	uint16_t wait = 0;
	SET_BIT(RCC->CR, PLLON);
	while ((RCC->CR & (1 << PLLRDY)) == 0)
	{
		if (wait >= 500)
		{
			Local_u8_Error_State = TIMEOUT_ERR;
			break;
		}
		wait++;
	}

	switch (clk_src)
	{
	case Half_HSI:
		CLEAR_BIT(RCC->CFGR, PLLSRC);
		break;

	case Half_HSE:
		SET_BIT(RCC->CFGR, PLLXTPRE);  // devide HSE/2
		SET_BIT(RCC->CFGR, PLLSRC);    // select HSE as PLL Source
		break;

	case HSE:
		SET_BIT(RCC->CFGR, PLLSRC);    // select HSE as PLL Source
		break;

	default:
		Local_u8_Error_State = PLL_CLK_SRC_ERR;
		break;
	}
	SET_BIT(RCC->CIR, PLLRDYC); // CLEAR FLAG

	if (IS_PLLMULTIPLICATION_FACTOR_CORRECT(mul_factor))
	{
		RCC->CFGR = (RCC->CFGR & (PLL_MULTIPLICATION_FACTOR_MASK)) | (mul_factor << PLLMUL0);
	}
	else
	{
		Local_u8_Error_State = PLL_MULTIPLICATION_FACTOR_ERR;
	}

	return Local_u8_Error_State;
}

uint8_t RCC_Enable_LSI(void);
uint8_t RCC_Enable_LSE(void);

uint8_t RCC_MCO_CLK(uint8_t MCO_CLK_source);

uint8_t AHP_Prescaler(EN_AHP_SysClk_Prescaler_t AHP_prescaler_value)
{
	uint8_t Local_u8_Error_State = OK;
	if (IS_AHB_PRESCALER_CORRECT(AHP_prescaler_value))
	{
		RCC->CFGR = (RCC->CFGR & (AHP_PRESCALER_MASK)) | (AHP_prescaler_value << HPRE0);
	}
	else
	{
		Local_u8_Error_State = AHB_PRESCALER_ERR;
	}
	return Local_u8_Error_State;
}
uint8_t APB1_Prescaler(EN_APB1_HClk_Prescaler_t APB1_prescaler_value)
{
	uint8_t Local_u8_Error_State = OK;
	if (IS_APB1_PRESCALER_CORRECT(APB1_prescaler_value))
	{
		RCC->CFGR = (RCC->CFGR & (APB1_PRESCALER_MASK)) | (APB1_prescaler_value << PPRE10);
	}
	else
	{
		Local_u8_Error_State = APB1_PRESCALER_ERR;
	}
	return Local_u8_Error_State;
}
uint8_t APB2_Prescaler(EN_APB2_HClk_Prescaler_t APB2_prescaler_value)
{
	uint8_t Local_u8_Error_State = OK;
	if (IS_APB2_PRESCALER_CORRECT(APB2_prescaler_value))
	{
		RCC->CFGR = (RCC->CFGR & (APB2_PRESCALER_MASK)) | (APB2_prescaler_value << PPRE20);
	}
	else
	{
		Local_u8_Error_State = APB2_PRESCALER_ERR;
	}
	return Local_u8_Error_State;

}

uint8_t ADC_Prescaler(uint8_t ADC_prescaler_value);
uint8_t USB_Prescaler(uint8_t USB_prescaler_value);

uint8_t RCC_Enable_Peripheral(uint8_t peripheral_idx)
{
	uint8_t Local_u8_Error_State = OK;
	if (PERIPHERAL_IN_RCC_AHBENR(peripheral_idx))
	{
		SET_BIT(RCC->AHBENR, peripheral_idx);
	}
	else if (PERIPHERAL_IN_RCC_APB2ENR(peripheral_idx))
	{
		peripheral_idx = peripheral_idx - 32;
		SET_BIT(RCC->APB2ENR, peripheral_idx);
	}
	else if (PERIPHERAL_IN_RCC_APB1ENR(peripheral_idx))
	{
		peripheral_idx = peripheral_idx - 64;
		SET_BIT(RCC->APB1ENR, peripheral_idx);
	}
	else
	{
		Local_u8_Error_State = PERIPHERAL_NOT_FOUND_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t RCC_Disable_Peripheral(uint8_t peripheral_idx)
{
	uint8_t Local_u8_Error_State = OK;
	if (PERIPHERAL_IN_RCC_AHBENR(peripheral_idx))
	{
		CLEAR_BIT(RCC->AHBENR, peripheral_idx);
	}
	else if (PERIPHERAL_IN_RCC_APB2ENR(peripheral_idx))
	{
		peripheral_idx = peripheral_idx - 32;
		CLEAR_BIT(RCC->APB2ENR, peripheral_idx);
	}
	else if (PERIPHERAL_IN_RCC_APB1ENR(peripheral_idx))
	{
		peripheral_idx = peripheral_idx - 64;
		CLEAR_BIT(RCC->APB1ENR, peripheral_idx);
	}
	else
	{
		Local_u8_Error_State = PERIPHERAL_NOT_FOUND_ERR;
	}
	return Local_u8_Error_State;
}

uint8_t RCC_Config(ST_RCC_Config_t* st_rcc_config)
{
	uint8_t Local_u8_Error_State = OK;

	if (st_rcc_config->Sys_Clk_Select == HSI_system_clock_select)
	{
		Local_u8_Error_State = RCC_Enable_HSI();
	}
	else if (st_rcc_config->Sys_Clk_Select == HSE_system_clock_select)
	{
		Local_u8_Error_State = RCC_Enable_HSE();
	}
	else if (st_rcc_config->Sys_Clk_Select == PLL_system_clock_select)
	{
		Local_u8_Error_State = RCC_Enable_PLL(st_rcc_config->PLL_clk_src , st_rcc_config->PLL_Factor);
	}
	else
	{
		Local_u8_Error_State = CLK_SRC_ERR;
	}

	Local_u8_Error_State = AHP_Prescaler(st_rcc_config->AHP_Pres);
	Local_u8_Error_State = APB1_Prescaler(st_rcc_config->APB1_Pres);
	Local_u8_Error_State = APB2_Prescaler(st_rcc_config->APB2_Pres);

	return Local_u8_Error_State;
}
