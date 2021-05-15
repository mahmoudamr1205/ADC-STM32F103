/*
 * LCD2004_program.C
 *
 *  Created on: MAY 6, 2021
 *      Author: Mahmoud Amr
 */

#include <stdio.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD2004_config.h"
#include "LCD2004_private.h"
#include "LCD2004_interface.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "ALARM_interface.h"





	/*
	Function Name        : LCD_8BIT_INIT
	Function Returns     : void
	Function Arguments   :
	Function Description : initialization  lcd in 8 bit mode


	*/
void HLCD_VoidInit(void){

		MSTK_voidDelay_ms(2000);

	#ifdef four_bits_mode
		MGPIO_VoidSetPinDirection(LCD_PORT , EN , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VoidSetPinDirection(LCD_PORT , RS , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VoidSetPinDirection(LCD_PORT , D4 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VoidSetPinDirection(LCD_PORT , D5 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VoidSetPinDirection(LCD_PORT , D6 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VoidSetPinDirection(LCD_PORT , D7 , OUTPUT_SPEED_2MHZ_PP);

		HLCD_send_command(0x02);
		MSTK_voidDelay_ms(2);
		HLCD_send_command(function_set_4BIT);
		MSTK_voidDelay_ms(10);


	#endif

		#ifdef eight_bits_mode



		#endif

		HLCD_send_command(display_on_cursor_on_B_off);
		MSTK_voidDelay_ms(10);
		HLCD_send_command(display_clear);
		MSTK_voidDelay_ms(10);
		HLCD_send_command(entery_mode);
		MSTK_voidDelay_ms(100);

	}


static void send_falling_edge(void){

	MGPIO_VoidSetPinValue(LCD_PORT, EN, HIGH);
	MSTK_voidDelay_ms(2);
	MGPIO_VoidSetPinValue(LCD_PORT, EN, LOW);

}




/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
void HLCD_send_command(u8 command){

#ifdef four_bits_mode

	//			> command :76543210
	MGPIO_VoidSetPinValue(LCD_PORT, D4, GET_BIT(command,4));
	MGPIO_VoidSetPinValue(LCD_PORT, D5, GET_BIT(command,5));
	MGPIO_VoidSetPinValue(LCD_PORT, D6, GET_BIT(command,6));
	MGPIO_VoidSetPinValue(LCD_PORT, D7, GET_BIT(command,7));

	MGPIO_VoidSetPinValue(LCD_PORT, RS, LOW);
	send_falling_edge();


	//			> Command <<4


	MGPIO_VoidSetPinValue(LCD_PORT, D4, GET_BIT(command,0));
	MGPIO_VoidSetPinValue(LCD_PORT, D5, GET_BIT(command,1));
	MGPIO_VoidSetPinValue(LCD_PORT, D6, GET_BIT(command,2));
	MGPIO_VoidSetPinValue(LCD_PORT, D7, GET_BIT(command,3));

	MGPIO_VoidSetPinValue(LCD_PORT, RS, LOW);
	send_falling_edge();



#endif


#ifdef eight_bits_mode
/*
	DIO_write_pin(portcontrol,RS,0);
	DIO_write_pin(portcontrol,RW,0);
	DIO_write_port_val(portdata,command);
	send_falling_edge();
*/
#endif



}



/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
// LCD_send_vhar(x+48); --> 0 = ASCcode  48 'in numbers'
void HLCD_send_char(u8 Data){

#ifdef four_bits_mode

	//			> command :76543210
	MGPIO_VoidSetPinValue(LCD_PORT, D4, GET_BIT(Data,4));
	MGPIO_VoidSetPinValue(LCD_PORT, D5, GET_BIT(Data,5));
	MGPIO_VoidSetPinValue(LCD_PORT, D6, GET_BIT(Data,6));
	MGPIO_VoidSetPinValue(LCD_PORT, D7, GET_BIT(Data,7));

	MGPIO_VoidSetPinValue(LCD_PORT, RS, HIGH);
	send_falling_edge();

	//			> Command <<4

	MGPIO_VoidSetPinValue(LCD_PORT, D4, GET_BIT(Data,0));
	MGPIO_VoidSetPinValue(LCD_PORT, D5, GET_BIT(Data,1));
	MGPIO_VoidSetPinValue(LCD_PORT, D6, GET_BIT(Data,2));
	MGPIO_VoidSetPinValue(LCD_PORT, D7, GET_BIT(Data,3));

	MGPIO_VoidSetPinValue(LCD_PORT, RS, HIGH);
	send_falling_edge();


#endif

#ifdef eight_bits_mode

	/*if(count == 16){
		LCD_movecursor(2,1);
	}else if (count==32)
	{
		LCD_clear();
		LCD_movecursor(1,1);
		count = 0;
	}


		unsigned int address = 0x80;

		if(row == 1){
			address = 0x80;
		}else if (row == 2)
		{
			address = 0xc0;
		}
		LCD_send_command(address+=(coloumn-1));

	*/


	#endif



}









/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/
void HLCD_send_string(u8* string_){


u16 count = 0;
	while((*string_) >  0){

		HLCD_send_char(*string_);
		string_++;
		count++;
		if(count == 20){
			HLCD_movecursor(2,1);
		}else if (count==40)
		{
			HLCD_movecursor(3,1);
		}else if (count==60)
		{
			HLCD_movecursor(4,1);

		}else if (count==81)
		{
			HLCD_clear();
			HLCD_movecursor(1,1);
			count = 0;
		}
	}



}


/*
Function Name        :
Function Returns     : void
Function Arguments   :
Function Description : i


*/


void HLCD_movecursor(char row,char coloumn){


#ifdef four_bits_mode

		u16 address = 0x00;

		if(row == 1){
			address = 0x80;
		}else if (row == 2)
		{
			address = 0xc0;
		}else if (row == 3)
		{
			address = 0x94;
		}else if (row == 4)
		{
			address = 0xd4;
		}

		HLCD_send_command(address+=(coloumn-1));

#endif
#ifdef eight_bits_mode


#endif

}

void HLCD_clear(){

#ifdef four_bits_mode

	HLCD_send_command(display_clear);

#endif

		#ifdef eight_bits_mode

		#endif




}




    /*char temp[1];

	for (int i = 0; i < digit ; i++)
	{
		char[i]= data
	}

	temp[0] = 1023 % 10;
	temp[1] = (1023 % 100) / 10;
	temp[2] = (1023 % 1000) / 100;
	temp[3] = (1023 % 10000) / 1000;*/




void HLCD_send_number(int num){

	/*  unsigned int has values: 0 to 65535
		int has values: -32768 to +32767
	*/

	u8 str[7];
	sprintf(str, "%d", num);
	HLCD_send_string(str);






}



void HLCD_send_realnumber(float64 num){


		u8 str[16];
		u8 *tmpsign =(num <0)? "-" : "";
		u8 tmpval =(num <0)? -num : num;
		int tmpint_1 = tmpval;		//Get the integer (678)
		float32 tmpfrac = tmpval - tmpint_1 ; //Get fraction (0.0123)
		int tmpint_2 = tmpfrac * 1000;  //turn into integer (123)
		//print as parts, note that you need 0-padding for fractional bit.
		sprintf(str, "%s%d.%04d", tmpsign, tmpint_1, tmpint_2);
		HLCD_send_string(str);

}




void HLCD_voidStart_Page(u8* ptr){

	MSTK_voidDelay_ms(100);
	HLCD_movecursor(1,1);
	HLCD_send_string(ptr);
	//delay for view
	MSTK_voidDelay_ms(1000);

	//  LCD ALARM START Machine
	HALARM_ON();
	MSTK_voidDelay_ms(35);
	HALARM_OFF();
	MSTK_voidDelay_ms(80);
	HALARM_ON();
	MSTK_voidDelay_ms(35);
	HALARM_OFF();
	MSTK_voidDelay_ms(100);
	HALARM_ON();

	// ALARM END

	HLCD_clear();
	MSTK_voidDelay_ms(100);
	HALARM_OFF();
}












