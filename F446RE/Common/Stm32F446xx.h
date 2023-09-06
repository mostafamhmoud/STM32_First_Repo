#ifndef STM32F446xx_H
#define STM32F446xx_H

#include "stdint.h"


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

#define GPIOA_BASE_ADRESS             0x40020000U
#define GPIOB_BASE_ADRESS             0x40020400U
#define GPIOC_BASE_ADRESS             0x40020800U
#define GPIOD_BASE_ADRESS             0x40020C00U
#define GPIOE_BASE_ADRESS             0x40021000U
#define GPIOF_BASE_ADRESS             0x40021400U
#define GPIOG_BASE_ADRESS             0x40021800U
#define GPIOH_BASE_ADRESS             0x40021C00U

#define RCC_BASE_ADRESS               0x40023800U

/***************************         AHB2 Peripheral Base Address        ***************/






/***************************         AHB3 Peripheral Base Address         ***************/




/***************************         APB1 Peripheral Base Address         ***************/




/***************************         APB2 Peripheral Base Address         ***************/




/***************************         NVIC Peripheral Registers Base Address         ***************/

#define  NVIC_ISER_BASE_ADDRESS      0xE000E100 
#define  NVIC_ICER_BASE_ADDRESS      0xE000E180 
#define  NVIC_ISPR_BASE_ADDRESS      0xE000E200 
#define  NVIC_ICPR_BASE_ADDRESS      0xE000E280 
#define  NVIC_IABR_BASE_ADDRESS      0xE000E300 
#define  NVIC_IPR_BASE_ADDRESS       0xE000E400 



/***************************         EXTI Peripheral Registers Base Address         ***************/

#define  EXTI_BASE_ADDRESS      0x40013C00 



/***************************         SYSCFG Peripheral Registers Base Address         ***************/

#define  SYSCFG_BASE_ADDRESS      0x40013800 



/***************************         SCB Peripheral Registers Base Address         ***************/

#define SCB_BASE_ADDRESS            0xE000E008



/***************************         GPIO Register Definition Structure   ***************/

typedef struct
{
	volatile uint32_t MODER;                  /*GPIO PORT Mode Register*/
	volatile uint32_t OTYPER;                 /*GPIO PORT Output Type Register*/
	volatile uint32_t OSPEEDER;               /*GPIO PORT Output Speed Register*/
	volatile uint32_t PUPDR;                  /*GPIO PORT Pull Up/Down Register*/
	volatile uint32_t IDR;                    /*GPIO PORT Input Data Register*/
	volatile uint32_t ODR;                    /*GPIO PORT Output Data Register*/
	volatile uint32_t BSRR;                   /*GPIO PORT Bit Set/Reset Register*/
	volatile uint32_t LCKR;                   /*GPIO PORT Lock Register*/
	volatile uint32_t AFR[2];                 /*GPIO PORT Alternate Function Register*/

}ST_GPIO_RegDef_t;

/***************************         RCC Register Definition Structure   ***************/

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	uint32_t RESERVED1;

	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	uint32_t RESERVED2;
	uint32_t RESERVED3;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	uint32_t RESERVED4;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	uint32_t RESERVED5;
	uint32_t RESERVED6;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	uint32_t RESERVED7;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	uint32_t RESERVED8;
	uint32_t RESERVED9;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	uint32_t RESERVED10;
	uint32_t RESERVED11;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
	volatile uint32_t CKGATENR;
	volatile uint32_t DCKCFGR2;

}ST_RCC_RegDef_t;




/***************************         SYSTICK Register Definition Structure   ***************/

/* * * * * * * * * * * * * * *
 *  SYSTICK Registers Structure  *
 * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}ST_SysTick_RegDef_t;



/***************************         SCB Register Definition Structure   ***************/

  /* * * * * * * * * * * * * * *
   *  SCB Registers Structure  *
   * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t ACTLR;
	volatile uint32_t space[830];
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCSR;
	volatile uint32_t CFSR;
}ST_SCB_RegDef_t;


/***************************         EXTI Register Definition Structure   ***************/

  /* * * * * * * * * * * * * * *
   *  EXTI Registers Structure  *
   * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}ST_EXTI_RegDef_t;


/***************************         SYSCFG Register Definition Structure   ***************/

  /* * * * * * * * * * * * * * *
   *  SYSCFG Registers Structure  *
   * * * * * * * * * * * * * * */

typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
    uint32_t RESERVED1[2];
	volatile uint32_t CMPCR;
	uint32_t RESERVED2[2];
	volatile uint32_t CFGR;

}ST_SYSCFG_RegDef_t;



/***************************         GPIO Peripheral Definitions   ***************/

#define GPIOA             ((ST_GPIO_RegDef_t*)GPIOA_BASE_ADRESS)
#define GPIOB             ((ST_GPIO_RegDef_t*)GPIOB_BASE_ADRESS)
#define GPIOC             ((ST_GPIO_RegDef_t*)GPIOC_BASE_ADRESS)
#define GPIOD             ((ST_GPIO_RegDef_t*)GPIOD_BASE_ADRESS)
#define GPIOE             ((ST_GPIO_RegDef_t*)GPIOE_BASE_ADRESS)
#define GPIOF             ((ST_GPIO_RegDef_t*)GPIOF_BASE_ADRESS)
#define GPIOG             ((ST_GPIO_RegDef_t*)GPIOG_BASE_ADRESS)
#define GPIOH             ((ST_GPIO_RegDef_t*)GPIOH_BASE_ADRESS)


/***************************         RCC Peripheral Definitions   ***************/

#define RCC            ((ST_RCC_RegDef_t*)RCC_BASE_ADRESS)



/***************************         NVIC Peripheral Definitions   ***************/

  /* every  register has 8 copies { ISER[0] TO ISER[7] and so on for the remaining registers except for IPR 60
  ** from IPR[0] to IPR[59]   each IRQ have 8 bits in the register so each register has configs for 4 IRQ */

#define  NVIC_ISER      ((uint32_t*)NVIC_ISER_BASE_ADDRESS)  
#define  NVIC_ICER      ((uint32_t*)NVIC_ICER_BASE_ADDRESS)
#define  NVIC_ISPR      ((uint32_t*)NVIC_ISPR_BASE_ADDRESS)
#define  NVIC_ICPR      ((uint32_t*)NVIC_ICPR_BASE_ADDRESS)
#define  NVIC_IABR      ((uint32_t*)NVIC_IABR_BASE_ADDRESS)
#define  NVIC_IPR       ((uint8_t*)NVIC_IPR_BASE_ADDRESS)    // because each IRQ priority have 1 byte  

#define  NVIC_STIR           ((uint32_t*)0xE000EF00)



/***************************         SYSTICK Peripheral Definitions   ***************/


#define SCB       ((ST_SCB_RegDef_t*)SCB_BASE_ADDRESS)


/***************************         EXTI Peripheral Definitions   ***************/


#define EXTI       ((ST_EXTI_RegDef_t*)EXTI_BASE_ADDRESS)


/***************************         EXTI Peripheral Definitions   ***************/


#define SYSCFG       ((ST_SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)


/***************************         SYSTICK Peripheral Definitions   ***************/

#define SYSTICK              ((ST_SysTick_RegDef_t*)SYSTICK_BASE_ADDRESS)

#endif

