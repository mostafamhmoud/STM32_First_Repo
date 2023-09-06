
#include <stdint.h>
#include "../../../Common/Bit_Operations.h"
#include "../../../MCAL/GPIO/inc/GPIO_interface.h"
#include "../../../Common/Error_type.h"
#include "../../../MCAL/RCC/inc/RCC_interface.h"


#define COM1  PINB8
#define COM2  PINB9
#define COM3  PINB3

#define A   PINA11
#define B   PINA8
#define C   PINB15
#define D   PINB14
#define E   PINB13
#define F   PINB12
#define G   PINA12
#define DOT PINA15

#define COM_PORT PORTB

#define SEVEN_SEG_PIN_OUT_TYPE  OUTPUT_PUSH_PULL
#define SEVEN_SEG_PIN_SPEED MAX_PIN_2_MHZ


uint8_t seven_seg_clk_init(void)
{
	ST_RCC_Config_t seven_seg_clk =
	{
		.Sys_Clk_Select = HSI_system_clock_select,
		.PLL_clk_src = Half_HSI,
		.PLL_Factor = PLL_input_clock_x2,
		.AHP_Pres = AHP_SYSCLK_devided_by_8,
		.APB1_Pres = APB1_HCLK_not_divided,
		.APB2_Pres = APB2_HCLK_not_divided
	};

	RCC_Config(&seven_seg_clk);

	RCC_Enable_Peripheral(IOPAEN);
	RCC_Enable_Peripheral(IOPBEN);
}

uint8_t seven_seg_pins_init(void)
{
	ST_Pin_Config A_pin =
	{
		.Port_X = PORTA ,
		.Pin_Num = A ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};

	ST_Pin_Config B_pin =
	{
		.Port_X = PORTA ,
		.Pin_Num = B ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config C_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = C ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config D_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = D ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config E_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = E ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config F_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = F ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config G_pin =
	{
		.Port_X = PORTA ,
		.Pin_Num = G ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config DOT_pin =
	{
		.Port_X = PORTA ,
		.Pin_Num = DOT ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config COM1_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = COM1 ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config COM2_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = COM2 ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};
	ST_Pin_Config COM3_pin =
	{
		.Port_X = PORTB ,
		.Pin_Num = COM3 ,
		.mode = SEVEN_SEG_PIN_OUT_TYPE,
		.speed = SEVEN_SEG_PIN_SPEED,
	};

	GPIO_u8PIN_init(&A_pin);
	GPIO_u8PIN_init(&B_pin);
	GPIO_u8PIN_init(&C_pin);
	GPIO_u8PIN_init(&D_pin);
	GPIO_u8PIN_init(&E_pin);
	GPIO_u8PIN_init(&F_pin);
	GPIO_u8PIN_init(&G_pin);
	GPIO_u8PIN_init(&DOT_pin);
	GPIO_u8PIN_init(&COM1_pin);
	GPIO_u8PIN_init(&COM2_pin);
	GPIO_u8PIN_init(&COM3_pin);
}

uint8_t seven_seg_write(uint16_t num);
uint8_t seven_seg_write_digit1(uint8_t num)
{
	GPIO_u8Set_Pin_Value(COM_PORT, COM1, PIN_HIGH);
	GPIO_u8Set_Pin_Value(COM_PORT, COM2, PIN_HIGH);
	GPIO_u8Set_Pin_Value(COM_PORT, COM3, PIN_HIGH);

	if (num <= 9)
	{
		switch (num)
		{
		case 0:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_LOW);
			break;
		case 1:
			GPIO_u8Set_Pin_Value(PORTB, A, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_LOW);
			break;
		case 2:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		case 3:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		case 4:
			GPIO_u8Set_Pin_Value(PORTB, A, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		case 5:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, B, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		case 6:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, B, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		case 7:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_LOW);
			break;
		case 8:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		case 9:
			GPIO_u8Set_Pin_Value(PORTA, A, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, B, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, C, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTB, D, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, E, PIN_LOW);
			GPIO_u8Set_Pin_Value(PORTB, F, PIN_HIGH);
			GPIO_u8Set_Pin_Value(PORTA, G, PIN_HIGH);
			break;
		}
	}
}
uint8_t seven_seg_write_digit2(uint8_t num);
uint8_t seven_seg_write_digit3(uint8_t num);
