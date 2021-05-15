
/*
 * EXTI_INTERFACE
 *
 * Created: 9/20/2019 2:04:42 PM
 * Author: Mahmoud Amr
 * Version: V01
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



void MEXTI_voidInit();

void MEXTI_voidEnableEXTI(u8 copy_u8Line);
void MEXTI_voidDisableEXTI(u8 copy_u8Line);

void MEXTI_voidSWTriggerEXTI(u8 copy_u8Line);




#endif /* EXTI_INTERFACE_H_ */
