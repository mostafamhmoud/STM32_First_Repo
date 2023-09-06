#ifndef KEPAD_INTERFACE_H
#define KEPAD_INTERFACE_H


#define ROW1     PINA4
#define ROW2     PINA5
#define ROW3     PINA6
#define ROW4     PINA7

#define COL1     PINB0 
#define COL2     PINB1
#define COL3     PINB10
#define COL4     PINB11


#define PORT_COL  PORTB 
#define PORT_ROW  PORTA 


#define KEYPAD_PIN_SPEED        MAX_PIN_2_MHZ
#define KEYPAD_PIN_OUT_TYPE     OUTPUT_PUSH_PULL
#define KEYPAD_PIN_IN_TYPE      INPUT_FLOATING

#define NUM_COL     4 
#define NUM_ROW     4

#define KEYPAD_NO_KEYS         0xff

#define KEYPAD_ARR_VAL        {{1,2,3,4} , {5,6,7,8} , {9,10,11,12} , {13,14,15,16}}

void keypad_pins_init(void);
void keypad_clk_init(void);

uint8_t keypad_get_pressed_key(void);


#endif // !KEPAD_INTERFACE_H

