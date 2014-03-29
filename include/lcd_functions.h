//lib for a HD44780 compatible LCD-Display

#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H

/*****************************************************************/
/****************Custom configurations part***********************/

////clock frequency
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

////pin allocation

#define LCD_PORT PORTD
#define LCD_DDR DDRD

#define LCD_SHIFT_CLOCK PD0
#define LCD_SHIFT_DATA PD1
#define LCD_SHIFT_STR PD2
#define LCD_SHIFT_OE PD3
#define LCD_RS PD4
#define LCD_RW PD5
#define LCD_E PD6
#define LCD_BUSY_FLAG PD7

/*************************END OF CUSTOM PART*********************/
/****************************************************************/

/****************************************************************/
/********************LCD Commands********************************/

//clear screen
#define LCD_CLEAR_SCREEN 		0x01

//Cursor Home
#define LCD_HOME			0x02

//Entry Mode
#define LCD_SET_ENTRY			0x04

#define LCD_ENTRY_DECREASE		0x00
#define LCD_ENTRY_INCREASE		0x02
#define LCD_ENTRY_NOSHIFT		0x00
#define LCD_ENTRY_SHIFT			0x01

//Display On/Off
#define LCD_SET_DISPLAY			0x08

#define LCD_DISPLAY_OFF			0x00
#define LCD_DISPLAY_ON			0x04
#define LCD_CURSOR_OFF			0x00
#define LCD_CURSOR_ON			0x02
#define LCD_BLINK_OFF			0x00
#define LCD_BLINK_ON				0x01

//Shift
#define LCD_SET_SHIFT			0x10

#define LCD_CURSOR_MOVE			0x00
#define LCD_DISPLAY_SHIFT		0x08
#define LCD_LEFT_SHIFT			0x00
#define LCD_RIGHT_SHIFT			0x04

//Set Functions
#define LCD_SET_FUNCTION		0x20

#define LCD_FUNCTION_4BIT		0x00
#define LCD_FUNCTION_8BIT		0x10
#define LCD_FUNCTION_1LINE		0x00
#define LCD_FUNCTION_2LINE		0x08
#define LCD_FUNCTION_5x7		0x00
#define LCD_FUNCTION_5x10		0x04

/**************************END OF LCD COMMANDS*************************************/
/**********************************************************************************/

//Line Address
#define LCD_SET_ADDR				0x80

#define LCD_ADDR_LINE1			0x00
#define LCD_ADDR_LINE2			0x40

/***********************************************************************************/
/*******************************PROTOTYPES******************************************/

void lcd_init(void);
void lcd_clear(void);
void lcd_home(void);
void lcd_setCursor(uint8_t col, uint8_t row);
void lcd_sendTo(uint8_t data);
void lcd_sendChar(uint8_t chara);
void lcd_sendString(const char *string);
void lcd_sendCommand(uint8_t command);
void lcd_enable(void);
void lcd_marquee(const char *string);

#endif
