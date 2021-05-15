	/*
 * LCD2004_interface.h
 *
 *  Created on: May 8, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_LCD2004_INTERFACE_H_
#define INCLUDE_LCD2004_INTERFACE_H_




static void send_falling_edge(void);

/*
Function Name        : LCD_8BIT_INIT
Function Returns     : void
Function Arguments   :
Function Description : initialization  LCD in 8 bit mode


*/
void HLCD_VoidInit(void);


/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
void HLCD_send_char(u8 Data);


/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
void HLCD_send_command(u8 command);


/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
void HLCD_send_string(u8* string_);


/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
void HLCD_send_number(int num);

void HLCD_send_realnumber(float64 num);

void HLCD_clear();
void HLCD_movecursor(char row,char coloumn);

void HLCD_voidStart_Page(u8* ptr);


#endif /* INCLUDE_LCD2004_INTERFACE_H_ */
