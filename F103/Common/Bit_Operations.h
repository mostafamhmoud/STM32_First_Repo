#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#define SET_BIT(register_x , bit_x) (register_x |= (1<<bit_x))
#define CLEAR_BIT(register_x , bit_x) (register_x &= ~(1<<bit_x))
#define TOGGLE_BIT(register_x , bit_x) (register_x ^= (1<<bit_x))
#define READ_BIT(register_x , bit_x) ((register_x & (1<<bit_x)) >> bit_x)

#endif
