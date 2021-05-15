
/*
 * EXTI_program.c
 *
 * Created: 15 Aguest 2020 
 * Author: Mahmoud AMR
 * Version: V01
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"





void MEXTI_voidInit(){

	#if EXTI_MODE == RISING

	 	 SET_BIT(EXTI -> RTSR , EXTI_LINE);

	#elif EXTI_MODE == FALLING

		SET_BIT(EXTI -> FTSR , EXTI_LINE);

	#elif EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#endif

		/* Disable interrupt */
		CLR_BIT(EXTI -> IMR , EXTI_LINE);
}

void MEXTI_voidEnableEXTI(u8 copy_u8Line){

	SET_BIT(EXTI -> IMR , copy_u8Line);


}
void MEXTI_voidDisableEXTI(u8 copy_u8Line){


	CLR_BIT(EXTI -> IMR , copy_u8Line);

}

void MEXTI_voidSWTriggerEXTI(u8 copy_u8Line){

	SET_BIT(EXTI -> SWIER , copy_u8Line);
}

/*
 * To change mode  in run time
 * */
void MEXTI_voidSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode ){

	switch(copy_u8Mode){

	case RISING  	: SET_BIT(EXTI -> RTSR , copy_u8Line); break;
	case FALLING 	: SET_BIT(EXTI -> FTSR , copy_u8Line); break;
	case  ON_CHANGE	:
				SET_BIT(EXTI -> RTSR , copy_u8Line);
				SET_BIT(EXTI -> FTSR , copy_u8Line);
					break;


	}
}
