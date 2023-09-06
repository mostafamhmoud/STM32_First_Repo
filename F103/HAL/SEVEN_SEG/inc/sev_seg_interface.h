#ifndef SEV_SEG_INTERFACE_H
#define SEV_SEG_INTERFACE_H


uint8_t seven_seg_write(uint16_t num);
uint8_t seven_seg_write_digit1(uint8_t num);
uint8_t seven_seg_write_digit2(uint8_t num);
uint8_t seven_seg_write_digit3(uint8_t num);
uint8_t seven_seg_clk_init(void);
uint8_t seven_seg_pins_init(void);

#endif // !7_SEGEMNT_INTERFACE_H
