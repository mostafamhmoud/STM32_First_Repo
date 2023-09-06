#ifndef RCC_GPIO_H
#define RCC_GPIO_H





typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG
}EN_Port_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15

}EN_Pin_t;


typedef enum
{
	ANALOG  = 0b0000,
	INPUT_FLOATING  = 0b0100,
	INPUT_PULL_UP_DOWN  = 0b1000,

	OUTPUT_PUSH_PULL = 0b0001,
	OUTPUT_OPEN_DRAIN = 0b0101,
	AF_PUSH_PULL = 0b1001,
	AF_OPEN_DRAIN = 0b1101

}EN_Pin_Mode;

typedef enum
{
	ANALOG_PORT = 0x00000000,
	INPUT_FLOATING_PORT = 0x44444444,
	INPUT_PULL_UP_DOWN_PORT = 0x88888888,

	OUTPUT_PUSH_PULL_PORT = 0x11111111,
	OUTPUT_OPEN_DRAIN_PORT = 0x55555555,
	AF_PUSH_PULL_PORT = 0x99999999,
	AF_OPEN_DRAIN_PORT = 0xDDDDDDDD

}EN_Port_Mode;

typedef enum
{
	MAX_PIN_10_MHZ = 1 ,
	MAX_PIN_2_MHZ ,
	MAX_PIN_50_MHZ
}EN_Output_Pin_Speed_t;

typedef enum
{
	MAX_PORT_10_mHZ =  0x11111111,
	MAX_PORT_2_MHZ  =  0x22222222,
	MAX_PORT_50_MHZ =  0x33333333
}EN_Output_Port_Speed_t;


typedef struct
{
	EN_Port_t Port_X;
	EN_Pin_t Pin_Num;
	EN_Pin_Mode mode;
	EN_Output_Pin_Speed_t speed;
	
}ST_Pin_Config;

typedef struct
{
	EN_Port_t Port_X;
	EN_Port_Mode mode;
	EN_Output_Port_Speed_t speed;

}ST_Port_Config;

typedef enum
{
	PIN_LOW,
	PIN_HIGH

}EN_Pin_Value_t;

uint8_t GPIO_u8PIN_init(const ST_Pin_Config* pin_config);

uint8_t GPIO_u8PORT_init(const ST_Port_Config* pin_config);

uint8_t GPIO_u8Set_PORT_Value(EN_Port_t port, uint32_t value);

uint8_t GPIO_u8Get_PORT_Value(EN_Port_t port, uint32_t* value);

uint8_t GPIO_u8Set_Pin_Value(EN_Port_t port, EN_Pin_t pin, EN_Pin_Value_t Pin_Value);

uint8_t GPIO_u8Toggle_Pin_Value(EN_Port_t port, EN_Pin_t pin);

uint8_t GPIO_u8Read_Pin_Value(EN_Port_t port, EN_Pin_t pin, EN_Pin_Value_t* Pin_Value);  // save value in pointer passed to function

uint8_t GPIO_Set_Alt_Function(EN_Port_t port, uint16_t pin_no, uint16_t alt_fun_value);




#define PINA0         0
#define PINA1         1
#define PINA2         2
#define PINA3         3
#define PINA4         4
#define PINA5         5
#define PINA6         6
#define PINA7         7
#define PINA8         8
#define PINA9         9
#define PINA10        10
#define PINA11        11
#define PINA12        12
#define PINA13        13
#define PINA14        14
#define PINA15        15

#define PINB0         0
#define PINB1         1
#define PINB2         2
#define PINB3         3
#define PINB4         4
#define PINB5         5
#define PINB6         6
#define PINB7         7
#define PINB8         8
#define PINB9         9
#define PINB10        10
#define PINB11        11
#define PINB12        12
#define PINB13        13
#define PINB14        14
#define PINB15        15

#define PINC0         0
#define PINC1         1
#define PINC2         2
#define PINC3         3
#define PINC4         4
#define PINC5         5
#define PINC6         6
#define PINC7         7
#define PINC8         8
#define PINC9         9
#define PINC10        10
#define PINC11        11
#define PINC12        12
#define PINC13        13
#define PINC14        14
#define PINC15        15

#define PIND0         0
#define PIND1         1
#define PIND2         2
#define PIND3         3
#define PIND4         4
#define PIND5         5
#define PIND6         6
#define PIND7         7
#define PIND8         8
#define PIND9         9
#define PIND10        10
#define PIND11        11
#define PIND12        12
#define PIND13        13
#define PIND14        14
#define PIND15        15

#define PINE0         0
#define PINE1         1
#define PINE2         2
#define PINE3         3
#define PINE4         4
#define PINE5         5
#define PINE6         6
#define PINE7         7
#define PINE8         8
#define PINE9         9
#define PINE10        10
#define PINE11        11
#define PINE12        12
#define PINE13        13
#define PINE14        14
#define PINE15        15

#define PINF0         0
#define PINF1         1
#define PINF2         2
#define PINF3         3
#define PINF4         4
#define PINF5         5
#define PINF6         6
#define PINF7         7
#define PINF8         8
#define PINF9         9
#define PINF10        10
#define PINF11        11
#define PINF12        12
#define PINF13        13
#define PINF14        14
#define PINF15        15

#define PING0         0
#define PING1         1
#define PING2         2
#define PING3         3
#define PING4         4
#define PING5         5
#define PING6         6
#define PING7         7
#define PING8         8
#define PING9         9
#define PING10        10
#define PING11        11
#define PING12        12
#define PING13        13
#define PING14        14
#define PING15        15


#endif
