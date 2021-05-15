/*
 * LCD2004_private.h
 *
 *  Created on: May 8, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_LCD2004_PRIVATE_H_
#define INCLUDE_LCD2004_PRIVATE_H_





#define function_set_8BIT				0b00111000	//0x38
#define function_set_4BIT				0b00101000	//0x38
#define display_on_cursor_on_B_on  	  	0b00001111	//0x0f		blink on
#define display_on_cursor_off_B_off  	0b00001100	//0x0f
#define display_on_cursor_on_B_off  	0b00001110
#define display_off_ 					0b00001011	//0x0f		blink on
#define display_clear					0b00000001	//0x01
#define entery_mode 					0b00000110	//	0x06		shift off + increases
#define return_home						0b00000010  //




#endif /* INCLUDE_LCD2004_PRIVATE_H_ */
