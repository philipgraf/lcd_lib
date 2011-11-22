/**************************************************************************
 *      
 * File: test.c
 *       
 * Author: Philip Graf
 * Created: Nov 22 2011 00:10:30
 * Last Changes: Nov 22 2011 01:11:46
 * Description: Test for my own LCD-Routines
 *            
 *************************************************************************/

#include <avr/io.h>
#include "lcd_functions.h"

int main(){
	
	lcd_init();
	
	lcd_sendString("Test 2 ");

	lcd_clear();


	while(1){
			
	}

	return 0;
}
