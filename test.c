/**************************************************************************
 *      
 * File: test.c
 *       
 * Author: Philip Graf
 * Created: Nov 22 2011 00:10:30
 * Last Changes: Nov 25 2011 19:31:44
 * Description: Test for my own LCD-Routines
 *            
 *************************************************************************/

#include <avr/io.h>
#include "include/lcd_functions.h"
#include <util/delay.h>

int main(void){
	
	lcd_init();
while(1){

			lcd_setCursor(20,1);
		lcd_sendString("Hello again");
	}
	return 0;
}
