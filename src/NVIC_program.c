
/*
 * NVIC_program.c
 *
 * Created: 15 Aguest 2020 
 * Author: Mahmoud AMR
 * Version: V01
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_config.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"


void MNVIC_voidInitPriority(void){

	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;

}


/*
 * function to enable NVIC status
 * 	hint: go to lib to know the name of peripheral
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber){		// u8  0 to 255


	if( Copy_u8IntNumber <= 31 ){

		NVIC_ISER0 = ( 1 << Copy_u8IntNumber );

	}else if( Copy_u8IntNumber <= 59 ){

		// Copy_u8IntNumber -=32 ;
		NVIC_ISER1 = ( 1 << ( Copy_u8IntNumber-32));

	}else{

		// return error
	}


}



/*
 * function to disable NVIC status
 * 	hint: go to lib to know the name of peripheral
 */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber){		// u8  0 to 255  not under 0


	if( Copy_u8IntNumber <= 31 ){

		NVIC_ICER0 = ( 1 << Copy_u8IntNumber );

	}else if( Copy_u8IntNumber <= 59 ){

		// Copy_u8IntNumber -=32 ;
		NVIC_ICER1 = ( 1 << ( Copy_u8IntNumber-32));

	}else{

		// return error
	}


}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber){		// u8  0 to 255  not under 0


	if( Copy_u8IntNumber <= 31 ){

		NVIC_ISPR0 = ( 1 << Copy_u8IntNumber );

	}else if( Copy_u8IntNumber <= 59 ){

		// Copy_u8IntNumber -=32 ;
		NVIC_ISPR1 = ( 1 << ( Copy_u8IntNumber-32));

	}else{

		// return error
	}


}



void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber){		// u8  0 to 255  not under 0


	if( Copy_u8IntNumber <= 31 ){

		NVIC_ICPR0 = ( 1 << Copy_u8IntNumber );

	}else if( Copy_u8IntNumber <= 59 ){

		// Copy_u8IntNumber -=32 ;
		NVIC_ICPR1 = ( 1 << ( Copy_u8IntNumber-32));

	}else{

		// return error
	}


}




u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber){		// u8  0 to 255  not under 0

	u8 Local_u8Result = 0 ;

	if( Copy_u8IntNumber <= 31 ){

		Local_u8Result =GET_BIT( NVIC_IABR0 , Copy_u8IntNumber );

	}else if( Copy_u8IntNumber <= 59 ){

		// Copy_u8IntNumber -=32 ;
		Local_u8Result =GET_BIT( NVIC_IABR1 , (Copy_u8IntNumber - 32) );

	}else{

		// return error
	}

	return Local_u8Result;

}




void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority){

	u8 Local_Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ((MNVIC_GROUP_SUB_DISTRIBUTION -  0X05FA0300)/0x100)  ;
	// core peripheral


	//External peripheral

	if( Copy_s8InterruptID >= 0 ){

		NVIC_IPR[Copy_s8InterruptID] = (Local_Priority<<4) ;

	}




}








