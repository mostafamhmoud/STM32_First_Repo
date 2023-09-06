
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


uint8_t lcd_init();
uint8_t lcd_command(uint8_t cmd);
uint8_t lcd_data(uint8_t data);
uint8_t lcd_print_char(uint8_t ch);
uint8_t lcd_print_string(const uint8_t* str);

uint8_t lcd_pins_init(void);

uint8_t lcd_clk_init(void);

#endif
