/*
 * STC_program.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Mahmoud Amr
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_config.h"
#include "STK_private.h"
#include "STK_interface.h"




/*
 *  global value >>> call back function
 */

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/*
 *
 */
void SysTick_Handler(void){
//	MSTK_CallBack();
}




/* Apply Clock Choice
 * Disable Systick interrupt
 * Disable Systick
 */
void MSTK_VoidInit(void){

#if MSTK_CLK_SRC == MSTK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	MSTK -> CTRL = 0x00000004;
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	MSTK -> CTRL = 0;
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;

#endif

}

/*
 *
 */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks){

	if (Copy_u32Ticks <= 0x00FFFFFF){
	// reload value
	MSTK -> LOAD = Copy_u32Ticks;
	// Start count
	SET_BIT(MSTK -> CTRL , 0);

	while(GET_BIT(MSTK -> CTRL , 16) == 0);

	//stop timer
	CLR_BIT(MSTK -> CTRL , 0);

	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
	}
	else{

	}

}



/*
 *
 */
void MSTK_voidDelay_ms(u32 Copy_u32Time){


#if MSTK_CLK_SRC == MSTK_SRC_AHB

	Copy_u32Time = Copy_u32Time*8000 ;

	if (Copy_u32Time > 0x00FFFFFF){
		//return error;
		Copy_u32Time = 1 ;
	}

	// reload value
	MSTK -> LOAD = Copy_u32Time;
	// Start count
	SET_BIT(MSTK -> CTRL , 0);

	while(GET_BIT(MSTK -> CTRL , 16) == 0);

	//stop timer
	CLR_BIT(MSTK -> CTRL , 0);

	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;


#else
	Copy_u32Time = Copy_u32Time*1000 ;

	if (Copy_u32Time > 0x00FFFFFF){
		// return error
		Copy_u32Time = 1 ;
	}

	// reload value
	MSTK -> LOAD = Copy_u32Time;
	// Start count
	SET_BIT(MSTK -> CTRL , 0);

	while(GET_BIT(MSTK -> CTRL , 16) == 0);

	//stop timer
	CLR_BIT(MSTK -> CTRL , 0);

	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;


#endif

}


/*
 *************** Remember *******************
 * call back function
 * pointer to function
 * ----------
 * void func (void);
 *
 * void (*ptr) (void); == func();
 * ----------
 * *******************************************
 *
 * // enable of interrupt and systick
 */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void)){

	MSTK_CallBack = Copy_ptr;

	// reload value
	MSTK -> LOAD = Copy_u32Ticks;
	// Start count , enable Interrupt
	SET_BIT(MSTK -> CTRL ,1);
	SET_BIT(MSTK -> CTRL ,0);



	//stop timer
	CLR_BIT(MSTK -> CTRL , 0);

	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;

}

/*
 *
 */
void MSTK_voidSetIntervalPeriodc(u32 Copy_u32Ticks, void (*Copy_ptr) (void)){

}


/*
 *
 */
void MSTK_voidStopInterval(void){

}







