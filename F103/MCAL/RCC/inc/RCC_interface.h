
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


 /********************************
  * APB2 peripheral reset register Pins *
  ********************************/
enum
{
	AFIORST,
	IOPARST = 2,
	IOPBRST,
	IOPCRST,
	IOPDRST,
	IOPERST,
	IOPFRST,
	IOPGRST,
	ADC1RST,
	ADC2RST,
	TIM1RST,
	SPI1RST,
	TIM8RST,
	USART1RST,
	ADC3RST,
	TIM9RST = 19,
	TIM10RST,
	TIM11RST
};

/********************************
 * APB1 peripheral reset register Pins *
 ********************************/
enum
{
	TIM2RST,
	TIM3RST,
	TIM4RST,
	TIM5RST,
	TIM6RST,
	TIM7RST,
	TIM12RST,
	TIM13RST,
	TIM14RST,
	WWDGRST = 11,
	SPI2RST = 14,
	SPI3RST,
	USART2RST = 17,
	USART3RST,
	UART4RST,
	UART5RST,
	I2C1RST,
	I2C2RST,
	USBRST,
	CANRST = 25,
	BKPRST = 27,
	PWRRST,
	DACRST
};

/********************************
 * AHB peripheral clock enable register *
 ********************************/
enum
{
	DMA1EN,
	DMA2EN,
	SRAMEN,
	FLITFEN = 4,
	CRCEN = 6,
	FSMCEN = 8,
	SDIOEN = 10,

};

/********************************
 * APB2 peripheral clock enable register *
 ********************************/
enum
{
	AFIOEN = 32,
	IOPAEN = 34,
	IOPBEN,
	IOPCEN,
	IOPDEN,
	IOPEEN,
	IOPFEN,
	IOPGEN,
	ADC1EN,
	ADC2EN,
	TIM1EN,
	SPI1EN,
	USART1EN = 46
};
/********************************
 * APB1 peripheral clock enable register *
 ********************************/
enum
{
	TIM2EN = 64,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	TIM6EN,
	TIM7EN,
	TIM12EN,
	TIM13EN,
	TIM14EN,
	WWDGEN = 75,
	SPI2EN = 78,
	SPI3EN,
	USART2EN = 81,
	USART3EN,
	UART4EN,
	UART5EN,
	I2C1EN,
	I2C2EN,
	USBEN,
	CANEN = 89,
	BKPEN = 91,
	PWREN,
	DACEN,
};


/********************************
 * Clock Control registers Pins *
 ********************************/

enum
{
	HSION,
	HSIRDY,
	HSITRIM0 = 3,
	HSITRIM1,
	HSITRIM2,
	HSITRIM3,
	HSITRIM4,
	HSICAL0,
	HSICAL1,
	HSICAL2,
	HSICAL3,
	HSICAL4,
	HSICAL5,
	HSICAL6,
	HSICAL7,
	HSEON,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON = 24,
	PLLRDY
};

/********************************
 * Clock Configuration registers Pins *
 ********************************/
enum
{
	SW0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE10,
	PPRE11,
	PPRE12,
	PPRE20,
	PPRE21,
	PPRE22,
	ADCPRE0,
	ADCPRE1,
	PLLSRC,
	PLLXTPRE,
	PLLMUL0,
	PLLMUL1,
	PLLMUL2,
	PLLMUL3,
	USBPRE,
	MCO0 = 24,
	MCO1,
	MCO2,
};

/********************************
 * Clock interrupt register Pins *
 ********************************/

enum
{
	LSIRDYF,
	LSERDYF,
	HSIRDYF,
	HSERDYF,
	PLLRDYF,
	CSSF = 7,
	LSIRDYIE,
	LSERDYIE,
	HSIRDYIE,
	HSERDYIE,
	PLLRDYIE,
	LSIRDYC = 16,
	LSERDYC,
	HSIRDYC,
	HSERDYC,
	PLLRDYC,
	CSSC = 23
};

/********************************
 * Backup domain control register *
 ********************************/
enum
{
	LSEON,
	LSERDY,
	LSEBYP,
	RTCSEL0 = 8,
	RTCSEL1,
	RTCEN = 15,
	BDRST,
};

/* * * * * * * * * * * * * * *
 *   MCO Prescaler Factor    *
 * * * * * * * * * * * * * * */

enum
{
	MCO_No_clock,
	MCO_System_clock = 4,
	MCO_HSI_clock,
	MCO_HSE_clock,
	MCO_PLL_clock_devided_by_2
};

/* * * * * * * * * * * * * * *
 *   PLL multiplication factor    *
 * * * * * * * * * * * * * * */
typedef enum
{
	PLL_input_clock_x2,
	PLL_input_clock_x3,
	PLL_input_clock_x4,
	PLL_input_clock_x5,
	PLL_input_clock_x6,
	PLL_input_clock_x7,
	PLL_input_clock_x8,
	PLL_input_clock_x9,
	PLL_input_clock_x10,
	PLL_input_clock_x11,
	PLL_input_clock_x12,
	PLL_input_clock_x13,
	PLL_input_clock_x14,
	PLL_input_clock_x15,
	PLL_input_clock_x16,
}EN_PLLMUL_Factor_t;

/* * * * * * * * * * * * * * *
 *   ADC prescaler    *
 * * * * * * * * * * * * * * */
enum
{
	ADC_PCLK2_divided_by_2,
	ADC_PCLK2_divided_by_4,
	ADC_PCLK2_divided_by_6,
	ADC_PCLK2_divided_by_8
};

/* * * * * * * * * * * * * * *
 *   APB2 high-speed prescaler    *
 * * * * * * * * * * * * * * */
typedef enum
{
	APB2_HCLK_not_divided,
	APB2_HCLK_divided_by_2 = 4,
	APB2_HCLK_divided_by_4,
	APB2_HCLK_divided_by_8,
	APB2_HCLK_divided_by_16,
}EN_APB2_HClk_Prescaler_t;

/* * * * * * * * * * * * * * *
 *   APB1 low-speed prescaler    *
 * * * * * * * * * * * * * * */
typedef enum
{
	APB1_HCLK_not_divided,
	APB1_HCLK_divided_by_2 = 4,
	APB1_HCLK_divided_by_4,
	APB1_HCLK_divided_by_8,
	APB1_HCLK_divided_by_16,
}EN_APB1_HClk_Prescaler_t;

/* * * * * * * * * * * * * * *
 *   AHP prescaler  *
 * * * * * * * * * * * * * * */
typedef enum
{
	AHP_SYSCLK_not_devided,
	AHP_SYSCLK_devided_by_2 = 8,
	AHP_SYSCLK_devided_by_4,
	AHP_SYSCLK_devided_by_8,
	AHP_SYSCLK_devided_by_16,
	AHP_SYSCLK_devided_by_64,
	AHP_SYSCLK_devided_by_128,
	AHP_SYSCLK_devided_by_256,
	AHP_SYSCLK_devided_by_512
}EN_AHP_SysClk_Prescaler_t;

/* * * * * * * * * * * * * * *
 *   system clock source *
 * * * * * * * * * * * * * * */
typedef enum
{
	HSI_system_clock_select,
	HSE_system_clock_select,
	PLL_system_clock_select
}EN_SysClk_Type_t;

/* * * * * * * * * * * *
 *   PLL CLK Source    *
 * * * * * * * * * * * */
typedef enum
{
	HSE,
	Half_HSE,
	Half_HSI
}EN_PLL_Clk_Source_t;

typedef struct
{
	EN_SysClk_Type_t Sys_Clk_Select;
	EN_AHP_SysClk_Prescaler_t AHP_Pres;
	EN_APB1_HClk_Prescaler_t APB1_Pres;
	EN_APB2_HClk_Prescaler_t APB2_Pres;
	EN_PLL_Clk_Source_t PLL_clk_src;
	EN_PLLMUL_Factor_t PLL_Factor;

}ST_RCC_Config_t;





uint8_t RCC_Enable_HSI(void);
uint8_t RCC_Enable_HSE(void);
uint8_t RCC_Enable_PLL(EN_PLL_Clk_Source_t clk_src , EN_PLLMUL_Factor_t mul_factor);

uint8_t RCC_Enable_LSI(void);
uint8_t RCC_Enable_LSE(void);

uint8_t RCC_MCO_CLK(uint8_t MCO_CLK_source);

uint8_t AHP_Prescaler(EN_AHP_SysClk_Prescaler_t AHP_prescaler_value);
uint8_t APB1_Prescaler(EN_APB1_HClk_Prescaler_t APB1_prescaler_value);
uint8_t APB2_Prescaler(EN_APB2_HClk_Prescaler_t APB2_prescaler_value);

uint8_t ADC_Prescaler(uint8_t ADC_prescaler_value);
uint8_t USB_Prescaler(uint8_t USB_prescaler_value);

uint8_t RCC_Enable_Peripheral(uint8_t peripheral_idx);
uint8_t RCC_Disable_Peripheral(uint8_t peripheral_idx);

uint8_t RCC_Config(ST_RCC_Config_t* st_rcc_config);


#endif

