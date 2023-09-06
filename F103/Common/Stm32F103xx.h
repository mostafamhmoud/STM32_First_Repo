#ifndef STM32F103xx_H
#define STM32F103xx_H



#define SET_BIT(register_x , bit_x) (register_x |= (1<<bit_x))
#define CLEAR_BIT(register_x , bit_x) (register_x &= ~(1<<bit_x))
#define TOGGLE_BIT(register_x , bit_x) (register_x ^= (1<<bit_x))
#define READ_BIT(register_x , bit_x) ((register_x & (1<<bit_x)) >> bit_x)


/***************************         CORE Peripherals Base Address        ***************/

#define SYSTICK_BASE_ADDRESS               0xE000E010



/***************************         Various memories Base Address        ***************/

#define FLASH_BASE_ADDRESS           0x08000000UL
#define SRAM_BASE_ADDRESS            0x20000000UL
#define ROM_BASE_ADDRESS             0x1FFF0000UL


/***************************         AHB1 Peripheral Base Address        ***************/

#define RCC_BASE_ADRESS               0x40021000


/***************************         APB1 Peripheral Base Address         ***************/




/***************************         APB2 Peripheral Base Address         ***************/


#define GPIOA_BASE_ADRESS             0x40010800
#define GPIOB_BASE_ADRESS             0x40010C00
#define GPIOC_BASE_ADRESS             0x40011000
#define GPIOD_BASE_ADRESS             0x40011400
#define GPIOE_BASE_ADRESS             0x40011800
#define GPIOF_BASE_ADRESS             0x40011C00
#define GPIOG_BASE_ADRESS             0x40012000




/***************************         NVIC Peripheral Registers Base Address         ***************/

#define  NVIC_ISER_BASE_ADDRESS      0xE000E100
#define  NVIC_ICER_BASE_ADDRESS      0xE000E180
#define  NVIC_ISPR_BASE_ADDRESS      0xE000E200
#define  NVIC_ICPR_BASE_ADDRESS      0xE000E280
#define  NVIC_IABR_BASE_ADDRESS      0xE000E300
#define  NVIC_IPR_BASE_ADDRESS       0xE000E400



/***************************         GPIO & AFIO Register Definition Structure   ***************/


/* * * * * * * * * * * * * * *
 *  GPIO Registers Structure  *
 * * * * * * * * * * * * * * */
typedef struct
{
	volatile uint32_t CR[2];                  /*GPIO PORT Mode Register*/
	volatile uint32_t IDR;               /*GPIO PORT Input Data Register*/
	volatile uint32_t ODR;                  /*GPIO PORT Output Data Register*/
	volatile uint32_t BSRR;                    /*GPIO PORT Bit Set/Reset Register*/
	volatile uint32_t BRR;                    /*GPIO PORT Bit Reset Register*/
	volatile uint32_t LCKR;                   /*GPIO PORT Lock Register*/

}ST_GPIO_RegDef_t;


/* * * * * * * * * * * * * * *
 *  AFIO Registers Structure  *
 * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t EVCR;                  /*Event control register*/
	volatile uint32_t MAPR;                 /*AF remap and debug I/O configuration register*/
	volatile uint32_t EXTICR1;               /*External interrupt configuration register 1*/
	volatile uint32_t EXTICR2;                  /*External interrupt configuration register 2*/
	volatile uint32_t EXTICR3;                    /*External interrupt configuration register 3*/
	volatile uint32_t AFIO_EXTICR4;                    /*External interrupt configuration register 4 */
	volatile uint32_t MAPR2;                   /*AF remap and debug I/O configuration register2*/
};

/***************************         RCC Register Definition Structure   ***************/

/* * * * * * * * * * * * * * *
 *  RCC Registers Structure  *
 * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}ST_RCC_RegDef_t;


/***************************         SYSTICK Register Definition Structure   ***************/

/* * * * * * * * * * * * * * *
 *  SYSTICK Registers Structure  *
 * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t CTRL ;
	volatile uint32_t LOAD ;
	volatile uint32_t VAL ;
	volatile uint32_t CALIB;
}ST_SysTick_RegDef_t;


/***************************         GPIO Peripheral Definitions   ***************/

#define GPIOA             ((ST_GPIO_RegDef_t*)GPIOA_BASE_ADRESS)
#define GPIOB             ((ST_GPIO_RegDef_t*)GPIOB_BASE_ADRESS)
#define GPIOC             ((ST_GPIO_RegDef_t*)GPIOC_BASE_ADRESS)
#define GPIOD             ((ST_GPIO_RegDef_t*)GPIOD_BASE_ADRESS)
#define GPIOE             ((ST_GPIO_RegDef_t*)GPIOE_BASE_ADRESS)
#define GPIOF             ((ST_GPIO_RegDef_t*)GPIOF_BASE_ADRESS)
#define GPIOG             ((ST_GPIO_RegDef_t*)GPIOG_BASE_ADRESS)


/***************************         RCC Peripheral Definitions   ***************/

#define RCC            ((ST_RCC_RegDef_t*)RCC_BASE_ADRESS)


/***************************         SYSTICK Peripheral Definitions   ***************/

#define SYSTICK              ((ST_SysTick_RegDef_t*)SYSTICK_BASE_ADDRESS)



/***************************         NVIC Peripheral Definitions   ***************/

#define  NVIC_ISER      ((uint32_t*)NVIC_ISER_BASE_ADDRESS)
#define  NVIC_ICER      ((uint32_t*)NVIC_ICER_BASE_ADDRESS)
#define  NVIC_ISPR      ((uint32_t*)NVIC_ISPR_BASE_ADDRESS)
#define  NVIC_ICPR      ((uint32_t*)NVIC_ICPR_BASE_ADDRESS)
#define  NVIC_IABR      ((uint32_t*)NVIC_IABR_BASE_ADDRESS)
#define  NVIC_IPR       ((uint32_t*)NVIC_IPR_BASE_ADDRESS)

#define  NVIC_STIR           ((uint32_t*)0xE000EF00)


#endif

