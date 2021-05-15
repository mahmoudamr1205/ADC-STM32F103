
/*
 * NVIC_INTERFACE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_




/*
 * function to ENable NVIC status
 * 	hint: go to lib to know the name of peripheral
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);

/*
 * function to disable NVIC status
 * 	hint: go to lib to know the name of peripheral
 */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

void MNVIC_voidInitPriority(void);
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#define MNVIC_GROUP_4_SUB_0			0X05FA0300		// 4 bit for group priority - 0 bit for sub priority  in IPR
#define MNVIC_GROUP_3_SUB_1			0X05FA0400		// 3 bit for group priority - 1 bit for sub priority  in IPR
#define MNVIC_GROUP_2_SUB_2			0X05FA0500		// 2 bit for group priority - 2 bit for sub priority  in IPR
#define MNVIC_GROUP_1_SUB_3			0X05FA0600		// 1 bit for group priority - 3 bit for sub priority
#define MNVIC_GROUP_0_SUB_4			0X05FA0700		// 0 bit for group priority - 4 bit for sub priority

#define EXTI0			6
#define EXTI1			7

#endif /* NVIC_INTERFACE_H_ */
