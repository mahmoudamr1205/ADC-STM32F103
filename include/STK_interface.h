/*
 * STK_interface.h
 *
 *  Created on: Feb 6, 2021
 *      Author: Mahmoud Amr
 */

#ifndef INCLUDE_STK_INTERFACE_H_
#define INCLUDE_STK_INTERFACE_H_



/* Apply Clock Choice
 * Disable Systick interrupt
 * Disable Systick
 */
void MSTK_VoidInit(void);

/*
 *
 */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

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
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void));


/*
 *
 */
void MSTK_voidSetIntervalPeriodc(u32 Copy_u32Ticks, void (*Copy_ptr) (void));


/*
 *
 */
void MSTK_voidStopInterval(void);

/*
 *
 */
void MSTK_voidDelay_ms(u32 Copy_u32Ticks);



#endif /* INCLUDE_STK_INTERFACE_H_ */
