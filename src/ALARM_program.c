/*
 * ALARM_program.c
 *
 *  Created on: May 8, 2021
 *      Author: Mahmoud Amr
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ALARM_interface.h"
#include "ALARM_config.h"
#include "ALARM_private.h"

#include "GPIO_interface.h"



void HALARM_VoidInit(void){

	MGPIO_VoidSetPinDirection(ALARM_PORT , ALARM_PIN_1 , OUTPUT_SPEED_2MHZ_PP);

}
void HALARM_OFF(void){


	MGPIO_VoidSetPinValue(ALARM_PORT, ALARM_PIN_1, LOW);


}


void HALARM_ON(void){

	MGPIO_VoidSetPinValue(ALARM_PORT, ALARM_PIN_1, HIGH);


}
