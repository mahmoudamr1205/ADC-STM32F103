
/*
 * GPIO_program.c
 *
 * Created: 15 Aguest 2020 
 * Author: Mahmoud AMR
 * Version: V01
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"



/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
void MGPIO_VoidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE){

	switch(copy_u8PORT){

		case GPIOA:		//Port A
			if(copy_u8PIN <= 7){

				GPIOA_CRL &= ~( (0b1111)<< (copy_u8PIN * 4));		// Rest pin to write
				GPIOA_CRL |=  ( (copy_u8MODE)<< (copy_u8PIN * 4));	// write value

			}else if(copy_u8PIN <= 15){
				copy_u8PIN = copy_u8PIN - 8 ;
				GPIOA_CRH &= ~( (0b1111)<< (copy_u8PIN * 4));
				GPIOA_CRH |=  ( (copy_u8MODE)<< (copy_u8PIN * 4));
			}
			break;
		case GPIOB:			//Port B
			if(copy_u8PIN <= 7){

				GPIOB_CRL &= ~( (0b1111)<< (copy_u8PIN * 4));
				GPIOB_CRL |=  ( (copy_u8MODE)<< (copy_u8PIN * 4));

			}else if(copy_u8PIN <= 15){
				copy_u8PIN = copy_u8PIN - 8 ;
				GPIOB_CRH &= ~( (0b1111)<< (copy_u8PIN * 4));
				GPIOB_CRH |=  ( (copy_u8MODE)<< (copy_u8PIN * 4));
			}
			break;
		case GPIOC:		//Port C
			if(copy_u8PIN <= 7){

				GPIOC_CRL &= ~( (0b1111)<< (copy_u8PIN * 4));
				GPIOC_CRL |=  ( (copy_u8MODE)<< (copy_u8PIN * 4));

			}else if(copy_u8PIN <= 15){
				copy_u8PIN = copy_u8PIN - 8 ;
				GPIOC_CRH &= ~( (0b1111)<< (copy_u8PIN * 4));
				GPIOC_CRH |=  ( (copy_u8MODE)<< (copy_u8PIN * 4));
			}

			break;
			default : /*Retuen Eror*/						   break;


	} //switch





}//  MGPIO_VoidSetPinDirection


/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
void MGPIO_VoidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE){

	switch(copy_u8PORT){

		case GPIOA:		//Port A

			if(copy_u8VALUE == HIGH)
			{
				SET_BIT(GPIOA_ODR, copy_u8PIN );
			}else if(copy_u8VALUE == LOW){
				CLR_BIT(GPIOA_ODR, copy_u8PIN );
			}
			break;

		case GPIOB:			//Port B
			if(copy_u8VALUE == HIGH)
			{
				SET_BIT(GPIOB_ODR, copy_u8PIN );
			}else if(copy_u8VALUE == LOW){
				CLR_BIT(GPIOB_ODR, copy_u8PIN );
			}
			break;
		case GPIOC:		//Port C
			if(copy_u8VALUE == HIGH)
			{
				SET_BIT(GPIOC_ODR, copy_u8PIN );
			}else if(copy_u8VALUE == LOW){
				CLR_BIT(GPIOC_ODR, copy_u8PIN );
			}
			break;
			default : /*Retuen Eror*/				   break;

	} //switch

}

/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
u8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN){

	u8 Local_u8Result = 0 ;
	switch(copy_u8PORT){

		case GPIOA:	Local_u8Result = GET_BIT(GPIOA_IDR, copy_u8PIN ); break;

		case GPIOB:	Local_u8Result = GET_BIT(GPIOB_IDR, copy_u8PIN ); break;

		case GPIOC:	Local_u8Result = GET_BIT(GPIOC_IDR, copy_u8PIN ); break;

		default : /*Retuen Eror*/				   break;

	} //switch

	return Local_u8Result ;
}








/* PORT: GPIOA -GPIOB - GPIOC
 * PIN:  PIN0 - PIN1 - PIN2 ..... PIN15
 * Value: LOW  - HIGH
 * MODE: INPUT - OUTPUT					*/
void MGPIO_VoidTOGGLE_PIN(u8 copy_u8PORT, u8 copy_u8PIN){

	switch(copy_u8PORT){

		case GPIOA:		TOG_BIT(GPIOA_ODR, copy_u8PIN );	 break;
		case GPIOB:		TOG_BIT(GPIOB_ODR, copy_u8PIN );	 break;
		case GPIOC:		TOG_BIT(GPIOC_ODR, copy_u8PIN );	 break;
			default : /*Retuen Eror*/				  		 break;

	} //switch

}

