
/*
 * RCC_INTERFACE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB  	0
#define RCC_APB1 	1
#define	RCC_APB2 	2



void RCC_voidInitSysClock(void);

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId );

void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId );

u16 ReadAnalog(void);


#endif /* RCC_INTERFACE_H_ */
