#include <stdint.h>

#include "../../../Common/Bit_Operations.h"
#include "../../../MCAL/GPIO/inc/GPIO_interface.h"
#include "../../../Common/Error_type.h"
#include "../../../MCAL/RCC/inc/RCC_interface.h"
#include "../../../MCAL/SYSTICK/inc/SysTick_interface.h"

 


#define RS PINA11
#define EN PINA8

#define D4  PINB15
#define D5  PINB14
#define D6  PINB13
#define D7  PINB12

#define LCD_DATA_PORT  PORTB
#define LCD_CTR_PORT   PORTA

#define LCD_PIN_SPEED     MAX_PIN_2_MHZ
#define LCD_PIN_OUT_TYPE  OUTPUT_PUSH_PULL

#define LCD_4_BIT_DATA_MASK 0x0FFF
 
uint8_t lcd_clk_init(void)
{
	ST_RCC_Config_t lcd_clk =
	{
		.Sys_Clk_Select = HSI_system_clock_select,
		.PLL_clk_src = Half_HSI,
		.PLL_Factor = PLL_input_clock_x2,
		.AHP_Pres = AHP_SYSCLK_devided_by_8,
		.APB1_Pres = APB1_HCLK_not_divided,
		.APB2_Pres = APB2_HCLK_not_divided
	};

	RCC_Config(&lcd_clk);

	RCC_Enable_Peripheral(IOPAEN);
	RCC_Enable_Peripheral(IOPBEN);
}

uint8_t lcd_pins_init(void)
{
	ST_Pin_Config rs_pin =
	{
		.Port_X = PORTA ,
		.Pin_Num = RS ,
		.mode = LCD_PIN_OUT_TYPE,
		.speed = LCD_PIN_SPEED
	};

	ST_Pin_Config en_pin =
	{
		.Port_X = PORTA ,
		.Pin_Num = EN ,
		.mode = LCD_PIN_OUT_TYPE,
		.speed = LCD_PIN_SPEED
	};
	ST_Pin_Config d4_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = D4 ,
		.mode = LCD_PIN_OUT_TYPE,
		.speed = LCD_PIN_SPEED
	};
	ST_Pin_Config d5_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = D5 ,
		.mode = LCD_PIN_OUT_TYPE,
		.speed = LCD_PIN_SPEED
	};
	ST_Pin_Config d6_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = D6 ,
		.mode = LCD_PIN_OUT_TYPE,
		.speed = LCD_PIN_SPEED
	};
	ST_Pin_Config d7_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = D7 ,
		.mode = LCD_PIN_OUT_TYPE,
		.speed = LCD_PIN_SPEED
	};

	GPIO_u8PIN_init(&rs_pin);
	GPIO_u8PIN_init(&en_pin);

	GPIO_u8PIN_init(&d4_pin);
	GPIO_u8PIN_init(&d5_pin);
	GPIO_u8PIN_init(&d6_pin);
	GPIO_u8PIN_init(&d7_pin);
}
uint8_t lcd_command(uint8_t cmd)
{


	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, RS, PIN_LOW);  /* write command */

	/*  write MSB */
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D4, (cmd >> 4) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D5, (cmd >> 5) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D6, (cmd >> 6) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D7, (cmd >> 7) & 1);

	/* Enable pulse */
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_HIGH);
	SysTick_Delay_us(20);
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_LOW);

	/* Delay 2ms */
	SysTick_Delay_us(200);

	/*  write LSB */
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D4, (cmd >> 0) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D5, (cmd >> 1) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D6, (cmd >> 2) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D7, (cmd >> 3) & 1);

	/* Enable pulse */
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_HIGH);
	SysTick_Delay_us(20);
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_LOW);

	SysTick_Delay_ms(2);

}

uint8_t lcd_data(uint8_t data)
{
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, RS, PIN_HIGH);  /* write data */
	/*  write MSB */
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D4, (data >> 4) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D5, (data >> 5) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D6, (data >> 6) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D7, (data >> 7) & 1);

	/* Enable pulse */
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_HIGH);
	SysTick_Delay_us(20);
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_LOW);

	SysTick_Delay_us(200);


	/*  write LSB */
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D4, (data >> 0) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D5, (data >> 1) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D6, (data >> 2) & 1);
	GPIO_u8Set_Pin_Value(LCD_DATA_PORT, D7, (data >> 3) & 1);
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_HIGH);
	/* Enable pulse */
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_HIGH);
	SysTick_Delay_us(20);
	GPIO_u8Set_Pin_Value(LCD_CTR_PORT, EN, PIN_LOW);

	SysTick_Delay_ms(2);
}

uint8_t lcd_init()
{
	SysTick_Delay_ms(20);

	lcd_command(0x33);
	lcd_command(0x32);    /* Send for 4 bit initialization of LCD  */
	lcd_command(0x28);    /* 2 line, 5*7 matrix in 4-bit mode */
	lcd_command(0x0c);    /* Display on cursor off */
	lcd_command(0x06);    /* Increment cursor (shift cursor to right) */
	lcd_command(0x01);    /* Clear display screen */

}

uint8_t lcd_print_char(uint8_t ch);
uint8_t lcd_print_string(const uint8_t* str)
{
	uint8_t i = 0;

	while (str[i] != '\0')
	{
		lcd_data(str[i]);
		i++;

		SysTick_Delay_ms(100);
		/*Delay 100ms */
	}
}

