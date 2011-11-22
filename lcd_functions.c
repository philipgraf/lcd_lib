/**************************************************************************
 *      
 * File: lcd_functions.c
 *       
 * Author: Philip Graf
 * Created: Nov 21 2011 21:15:25
 * Last Changes: Nov 22 2011 01:17:57
 * Description: all necessary function to interacted with the LCD-Display
 *            
 *************************************************************************/

#include <avr/io.h>
#include "lcd_functions.h"
#include <util/delay.h>

void lcd_init(){

	_delay_ms(20);
	
	//set output pins
	uint8_t pins = (1<<LCD_SHIFT_CLOCK) |
				  		(1<<LCD_SHIFT_DATA)  |
				  		(1<<LCD_SHIFT_STR)   |
				  		(1<<LCD_SHIFT_OE)    |
				  		(1<<LCD_RS)          |
				  		(1<<LCD_RW)          |
				  		(1<<LCD_E);

	LCD_DDR |= pins;

	//set all to zero
	LCD_PORT &= ~pins;

	lcd_sendTo( LCD_SET_FUNCTION | LCD_FUNCTION_8BIT);

	lcd_sendCommand( LCD_SET_FUNCTION | LCD_FUNCTION_8BIT | LCD_FUNCTION_2LINE | LCD_FUNCTION_5x7 );
	lcd_sendCommand( LCD_SET_DISPLAY | LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF );
	lcd_sendCommand( LCD_SET_ENTRY | LCD_ENTRY_INCREASE | LCD_ENTRY_NOSHIFT );
	lcd_sendCommand( LCD_CLEAR_SCREEN );

	_delay_ms(20);
}

void lcd_enable(){
	LCD_PORT |= (1<< LCD_E);
	_delay_us(20);
	LCD_PORT &= ~(1<< LCD_E);
}

void lcd_sendTo(uint8_t data){
	uint8_t i;
	LCD_PORT |= (1<< LCD_SHIFT_STR);
	LCD_PORT &= ~(1<<LCD_SHIFT_OE);
	for(i=7;i>=0;i--){
		LCD_PORT &= ~(1<<LCD_SHIFT_CLOCK);
		if(data & (1<<i)){
			LCD_PORT |= (1<< LCD_SHIFT_DATA);
		}else{
			LCD_PORT &= ~(1<< LCD_SHIFT_DATA);
		}
		LCD_PORT |= (1<< LCD_SHIFT_CLOCK);
	}
	LCD_PORT &= ~(1<< LCD_SHIFT_STR);
	LCD_PORT |= (1<< LCD_SHIFT_OE);
	lcd_enable();
}

void lcd_sendChar(uint8_t chara){
	LCD_PORT |= (1<< LCD_RS);
	LCD_PORT &= ~(1<< LCD_RW);

	lcd_sendTo( chara );

	_delay_us(45);
}

void lcd_sendCommand(uint8_t command){
	LCD_PORT &= ~(1<< LCD_RS);
	LCD_PORT &= ~(1<< LCD_RW);

	lcd_sendTo( command );

	_delay_us(45);
}

lcd_clear(){
	lcd_sendCommand(LCD_CLEAR_SCREEN);
	_delay_ms(2);
}

lcd_home(){
	lcd_sendCommand(LCD_HOME);
	_delay_ms(2);
}

void lcd_setCursor(uint8_t col, uint8_t row){
	uint8_t command;

	switch(row){
		case 1:
			command = LCD_SET_ADDR + LCD_ADDR_LINE1 + col;
			break;
		case 2:
			command = LCD_SET_ADDR + LCD_ADDR_LINE2 + col;
			break;
		default:
			return;
	}
	lcd_sendCommand(command);
}

void lcd_sendString(const char *string){
	while( *string != '\0')
		lcd_sendChar(*string++);
}

