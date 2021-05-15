
/*
 * RCC_program.c
 *
 * Created: 15 Aguest 2020 
 * Author: Mahmoud AMR
 * Version: V01
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_interface.h"



 

void RCC_voidInitSysClock(void){
	
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL  //Enable HSE Without bypass
		RCC_CR 	 = 0x00010000 ;
		RCC_CFGR = 0x00000001 ; 		  // System clock switch 
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC	  //Enable HSE With bypass
		RCC_CR   = 0x00050000 ;
		RCC_CFGR = 0x00000001 ; 		  // System clock switch 
	#elif RCC_CLOCK_TYPE == RCC_HSI		
		RCC_CR   = 0x00000081 ;			  //Enable HSI +Trimming =0
		RCC_CFGR = 0x00000000 ; 		  // System clock switch 
		
		/**************** Assigment ********************************/
	#elif RCC_CLOCK_TYPE == RCC_PLL
		
		
		//RCC_CFGR =(RCC_PLL_MUL_VAL << 18);	//PORT |= (1<<bit)
		
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		
		//RCC_CR   = RCC_PLL_INPUT ; 
		//	RCC_CFGR = 0x00000002 ; 		 	 // System clock switch 
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		
	
		#endif
		
		
		
	#else
		#error("wrnog clock type")
	#endif
	
	
	
	
	
}


void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId ){
	
	if (Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{	
			case RCC_AHB  : SET_BIT(RCC_AHBENR,  Copy_u8PerId); break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR, Copy_u8PerId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR, Copy_u8PerId); break;
			//default : /*Return Error*/						break;
			
		}	
	}	
	else
	{
		/* Return Error*/
	}	 
}


void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId ){
	
	if (Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{	
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,  Copy_u8PerId); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR, Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR, Copy_u8PerId); break;
			//default : /*Return Error*/    				    break;
			
		}	
	}	
	else
	{
		/* Return Error*/
	}
	 
}

