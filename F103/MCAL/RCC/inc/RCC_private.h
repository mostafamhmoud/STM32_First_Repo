#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define IS_PLLMULTIPLICATION_FACTOR_CORRECT(x)  ((x >=2) && (x <= 16))


#define IS_AHB_PRESCALER_CORRECT(x)  (((x >= 8) && (x <= 15)) || (x == 0))
#define IS_APB1_PRESCALER_CORRECT(x) (((x >= 4) && (x <= 7)) || (x == 0))
#define IS_APB2_PRESCALER_CORRECT(x) (((x >= 4) && (x <= 7)) || (x == 0))


#define CLOCK_SWITCH_MASK                 0b11
#define PLL_MULTIPLICATION_FACTOR_MASK    0xFFC3FFFF
#define AHP_PRESCALER_MASK                0xFFFFFF0F
#define APB1_PRESCALER_MASK               0xFFFFF8FF
#define APB2_PRESCALER_MASK               0xFFFFC7FF

#define PERIPHERAL_IN_RCC_AHBENR(peripheral_idx) (peripheral_idx < 32)
#define PERIPHERAL_IN_RCC_APB2ENR(peripheral_idx) (peripheral_idx >= 32 && peripheral_idx < 64)
#define PERIPHERAL_IN_RCC_APB1ENR(peripheral_idx) (peripheral_idx >= 64 && peripheral_idx < 96)




#endif // !RCC_PRIVATE_H

